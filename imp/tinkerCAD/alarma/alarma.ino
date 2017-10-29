/*  
    nombre de archivo: alarma.ino
    fecha: 19/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion:  Codigo principal del desarrollo "alarma" escribo para 
                  plataforma arduinoUNO.
*/

#define DEBUG

////////////////////////////////////////////////////////
// Clase abstracta, base para las diferentes entradas //
////////////////////////////////////////////////////////
class Inputs {};

////////////////////////////////////////////////////////////////////
// Clase abstracta, base para las diferentes entradas analógicas. //
////////////////////////////////////////////////////////////////////

class Analogica : public Inputs {
 public:
  virtual int get(void) = 0;
};

/////////////////////////////////////////////////////////////////////////////
// Clase que lee el valor de referencia para el sensor analógico (umbral). //
/////////////////////////////////////////////////////////////////////////////

class Referencia : public Analogica {
 private:
  int refAnalogica;
  int pinRef;
  
 public:
   Referencia(void);
    int get(void);
   void setPin(int pin); 
};

Referencia::Referencia(void){
  #ifdef DEBUG
    Serial.println("Objeto Referencia creado");
  #endif  
  refAnalogica = 0;
}

int Referencia::get(void){
  refAnalogica = analogRead(pinRef);
  return refAnalogica;
}

void Referencia::setPin(int pin){
  pinRef = pin;
}

//////////////////////////////////////////////////
// Clase que lee el valor del sensor analógico. //
//////////////////////////////////////////////////

class SensorA : public Analogica {
 private:
  int sensorAnalogico;
  int pinSensor;
  
 public:
   SensorA(void);
   int get(void);
   void setPin(int pin);
   boolean check(int refSensor);
};

SensorA::SensorA(void){
  #ifdef DEBUG
    Serial.println("Objeto SensorA creado");
  #endif
  sensorAnalogico = 0;
}

int SensorA::get(void){
  sensorAnalogico = analogRead(pinSensor);
  return sensorAnalogico;
}

void SensorA::setPin(int pin){
  pinSensor = pin;
}

boolean SensorA::check(int refSensor){
  if(get()>=refSensor)
    return false;
  else
    return true;
}


//////////////////////////////////////////////////////////////////
// Clase abstracta, base para las diferentes entradas digitales //
//////////////////////////////////////////////////////////////////

class Digital : public Inputs {};

////////////////////////////////////////////////
// Clase que lee el valor del sensor digital. //
////////////////////////////////////////////////

class SensorD : public Digital {
 private:
  boolean sensorDigital;
  int pinSensor;
  
 public:
   SensorD(void);
   boolean get(void);
   void setPin(int pin);
   boolean check(void);
};

SensorD::SensorD(void){
  #ifdef DEBUG
    Serial.println("Objeto SensorD creado");
  #endif
  sensorDigital = false;
}

boolean SensorD::get(void){
  sensorDigital = digitalRead(pinSensor);
  return sensorDigital;
}

void SensorD::setPin(int pin){
  pinSensor = pin;
  pinMode(pinSensor, INPUT_PULLUP); 
}

boolean SensorD::check(){
  if(get()==true)
    return false;
  else
    return true;
}



#define PULLUP HIGH
#define PULLDOWN LOW

#define CURRENT 0
#define PREVIOUS 1
#define CHANGED 2

/*
||
|| @file Button.h
|| @version 1.6
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Provide an easy way of making buttons
|| #
||
|| @license
|| | Copyright (c) 2009 Alexander Brevig. All rights reserved.
|| | This code is subject to AlphaLicence.txt
|| | alphabeta.alexanderbrevig.com/AlphaLicense.txt */

class Button{
  public:
    Button(uint8_t buttonPin, uint8_t buttonMode=PULLDOWN);
    void pullup();
    void pulldown();
    bool isPressed();
    bool wasPressed();
    bool stateChanged();
	bool uniquePress();
  private: 
    uint8_t pin;
    uint8_t mode;
    uint8_t state;
};

Button::Button(uint8_t buttonPin, uint8_t buttonMode){
	this->pin=buttonPin;
    pinMode(pin,INPUT);
	buttonMode==PULLDOWN ? pulldown() : pullup();
    state = 0;
    bitWrite(state,CURRENT,!mode);
}

/*
|| Set pin HIGH as default
*/
void Button::pullup(void){
	mode=PULLUP;
	digitalWrite(pin,HIGH);
}

/*
|| Set pin LOW as default
*/
void Button::pulldown(void){
	mode=PULLDOWN;
	//digitalWrite(pin,LOW);
}

/*
|| Return the bitWrite(state,CURRENT, of the switch
*/
bool Button::isPressed(void){
    bitWrite(state,PREVIOUS,bitRead(state,CURRENT));
    if (digitalRead(pin) == mode){
        bitWrite(state,CURRENT,false);
    } else {
        bitWrite(state,CURRENT,true);
    }
    if (bitRead(state,CURRENT) != bitRead(state,PREVIOUS)){
        bitWrite(state,CHANGED,true);
    }else{
        bitWrite(state,CHANGED,false);
    }
	return bitRead(state,CURRENT);
}

/*
|| Return true if the button has been pressed
*/
bool Button::wasPressed(void){
    if (bitRead(state,CURRENT)){
        return true;
    } else {
        return false;
    }
}

/*
|| Return true if state has been changed
*/
bool Button::stateChanged(void){
    return bitRead(state,CHANGED);
}

/*
|| Return true if the button is pressed, and was not pressed before
*/
bool Button::uniquePress(void){
    return (isPressed() && stateChanged());
}


/////////////////////////////////////////////
// Clase que lee el estado del pulsador.   //
/////////////////////////////////////////////

class Pulsador : public Digital {
 private:
  bool pulsado;
  //  int pinPulso;
  Button pulsadorCore = Button(12,PULLUP); //FIXME pasar por parametro el pin
  unsigned long registroInicioTiempo;
  unsigned long tiempoTranscurrido;
  
 public:
   Pulsador(void);
   bool presionado(void);
   unsigned long tiempoDesdePulsado(unsigned long);
   bool pulsadorLiberado(void);
   //   void setPin(int pin);
};

Pulsador::Pulsador(void){
  #ifdef DEBUG
    Serial.println("Objeto Pulsador creado");
  #endif
  pulsado = false;
  registroInicioTiempo = 0;
  tiempoTranscurrido = 0;
}

bool Pulsador::presionado(void){
  pulsado = pulsadorCore.isPressed();
  if(pulsado == true && pulsadorLiberado() == true)
    registroInicioTiempo = millis();
  return pulsado;
}

unsigned long Pulsador::tiempoDesdePulsado(unsigned long tiempoActual){
  if(registroInicioTiempo > tiempoActual)
    tiempoTranscurrido = tiempoActual + (4294967294 - registroInicioTiempo);
  else
    tiempoTranscurrido = tiempoActual - registroInicioTiempo;
  return tiempoTranscurrido;
}

bool Pulsador::pulsadorLiberado(void){
  return pulsadorCore.stateChanged();
}

////////////////////////////////////////////////////////
// Clase abstracta, base para las diferentes salidas. //
////////////////////////////////////////////////////////

class Indicadores {
 public:
  virtual void off(void) = 0;
};

/////////////////////////////////////////
// Clase que maneja la Sirena (salida) //
/////////////////////////////////////////

class Sirena : public Indicadores {
 private:
  int pinSirena;
  
 public:
   Sirena(void);
   void setPin(int);
   void toggle(void);
   void off(void);
};

Sirena::Sirena(void){
  #ifdef DEBUG
    Serial.println("Objeto Sirena creado");
  #endif
    pinSirena = 0;
}

void Sirena::setPin(int pin){
  pinSirena = pin;
  pinMode(pinSirena, OUTPUT); 
}

void Sirena::toggle(void){
  digitalWrite(pinSirena,HIGH);
  delay(200); //FIXME definir en alto nivel
  digitalWrite(pinSirena,LOW);
  delay(200); //FIXME definir en alto nivel
}

void Sirena::off(void){
  digitalWrite(pinSirena,LOW);
}

/////////////////////////////////////////////////////
// Clase que maneja la IndicadorLuminoso (salida). //
/////////////////////////////////////////////////////

class IndicadorLuminoso : public Indicadores {
 private:
  int pinIndicadorLuminoso;
  
 public:
   IndicadorLuminoso(void);
   void setPin(int);
   void toggle(void);
   void off(void);
};


IndicadorLuminoso::IndicadorLuminoso(void){
  #ifdef DEBUG
    Serial.println("Objeto IndicadorLuminoso creado");
  #endif
    pinIndicadorLuminoso = 0;
}

void IndicadorLuminoso::setPin(int pin){
  pinIndicadorLuminoso = pin;
  pinMode(pinIndicadorLuminoso, OUTPUT); 
}

void IndicadorLuminoso::toggle(void){
  digitalWrite(pinIndicadorLuminoso,HIGH);
  delay(200); //FIXME definir en alto nivel
  digitalWrite(pinIndicadorLuminoso,LOW);
  delay(200); //FIXME definir en alto nivel
}

void IndicadorLuminoso::off(void){
  digitalWrite(pinIndicadorLuminoso,LOW);
}

//////////////////////////////////////////////
// Clase que maneja el keep-alive (salida). //
//////////////////////////////////////////////

class Live : public Indicadores {
 private:
  int pinLive;
  
 public:
   Live(void);
   void setPin(int);
   void generarSenal(void);
   void off(void);
};

Live::Live(void){
  #ifdef DEBUG
    Serial.println("Objeto Live creado");
  #endif
    pinLive = 0;
}

void Live::setPin(int pin){
  pinLive = pin;
  pinMode(pinLive, OUTPUT);
  digitalWrite(pinLive,LOW);
}

void Live::generarSenal(void){
  digitalWrite(pinLive,HIGH);
  delay(200); //FIXME Buscar requerimiento de este tiempo
  digitalWrite(pinLive,LOW);
}

void Live::off(void){ //FIXME Nunca se utiliza
  digitalWrite(pinLive,LOW);
}


/////////////////////////////////////////
// Clase principal del sistema alarma. //
/////////////////////////////////////////

class Alarm
{
  public:
    Alarm(void);
    void iniciar(void);
    boolean armar(void);
    void disparar(void);    
    int detener(void);    
    void desarmar(void);

 private:    
    Referencia ref;
    SensorA sensorAnalogico;
    SensorD sensorDigital;
    Pulsador pulsadorControl;
    Sirena sirenaOut;
    IndicadorLuminoso indicador;
    Live keepAlive;
    unsigned long tiempoActual;
    
};

Alarm::Alarm()
{
  #ifdef DEBUG
    Serial.println("Objeto Alarm creado");
  #endif
    ref.setPin(A0); //FIXME hacerlo en alto nivel
    sensorAnalogico.setPin(A1); //FIXME hacerlo en alto nivel
    sensorDigital.setPin(4); //FIXME hacerlo en alto nivel
    sirenaOut.setPin(8); //FIXME hacerlo en alto nivel
    indicador.setPin(7); //FIXME hacerlo en alto nivle
    keepAlive.setPin(1); //FIXME hacerlo en alto nivle

    digitalWrite(0,LOW); //FIXME
    digitalWrite(2,LOW); //FIXME
    tiempoActual = 0;
}

void Alarm::iniciar()
{
  #ifdef DEBUG
    Serial.println("Metodo iniciar()");
  #endif
    digitalWrite(0,HIGH);
    while((sensorAnalogico.check(ref.get()) == false) || (sensorDigital.check() == false)){
      digitalWrite(2,HIGH);
      delay(200); //FIXME
      digitalWrite(2,LOW);
    }
    digitalWrite(2,HIGH);
}

boolean Alarm::armar()
{
  #ifdef DEBUG
    Serial.println("Metodo armar()");
  #endif
    keepAlive.generarSenal();
    if((sensorAnalogico.get()>ref.get()) || (sensorDigital.get() == true))
      return true; //FIXME no se define la lógica del "true"
    else
      return false;      
}

void Alarm::disparar()
{
#ifdef DEBUG
  Serial.println("Metodo disparar()");
#endif
    sirenaOut.toggle();
    indicador.toggle();
}

int Alarm::detener()
{
  #ifdef DEBUG
    Serial.println("Metodo detener()");
  #endif
  if(pulsadorControl.presionado() == true)
    return 10;
  else {
    if (pulsadorControl.pulsadorLiberado() == true){
      tiempoActual = pulsadorControl.tiempoDesdePulsado(millis());
      if(tiempoActual > 1000){
        if(tiempoActual > 5000)
          return 5; //FIXME los límites de tiempo superados
        else
	  return 1; //FIXME los límites de tiempo superado
      }
    }
    else
      return 0;
  } 
}

void Alarm::desarmar()
{
  sirenaOut.off();
  indicador.off();
}


//////////////////////////////////////////////////////////////////////

Alarm alarma;

// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600);
  #ifdef DEBUG
    Serial.println("Habilitado puerto serie para debug");
  #endif
  alarma.iniciar();
}

// the loop routine runs over and over again forever:
void loop() {

  if(alarma.armar() == true) //FIXME Revisar la lógica del true
    alarma.disparar();

  switch(alarma.detener()){
    case 0: //no se presiono el boton
      break;
    case 1: //paso entre 1 y 5 segundos
      alarma.desarmar();
      break;
    case 5: //paso mas de 5 segundos
      alarma.iniciar();
      break;
    case 10://se presiono el boton pero esta sin liberar
      break; 
    default:
      break;
  }
  
  delay(200); // FIXME maneja el tick del Loop()
  
}


