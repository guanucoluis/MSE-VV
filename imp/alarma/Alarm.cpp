/****************************************************
    nombre de archivo: Alarm.cpp
    fecha: 19/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase principal del sistema alarma.
****************************************************/

#include "Arduino.h"
#include "Alarm.h"

#define DEBUG 

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
    while(sensorAnalogico.check(ref.get()) & sensorDigital.check()){
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
    if(sensorAnalogico.get()>ref.get())
      return true; //FIXME no se define la lógica del "true";
    else if (sensorDigital.get() == true)
      return true;
    else
      return false;      
}

void Alarm::disparar()
{
#ifdef DEBUG
  Serial.println("Metodo disparar()");
#endif
  while(pulsadorControl.presionado() == false){    
    sirenaOut.toggle();
    indicador.toggle();
    keepAlive.generarSenal();
  }
}            

int Alarm::detener()
{
  #ifdef DEBUG
    Serial.println("Metodo detener()");
  #endif
    while(pulsadorControl.pulsadorLiberado() == false)
      keepAlive.generarSenal();
    tiempoActual = pulsadorControl.tiempoDesdePulsado(millis());
    if(tiempoActual > 1000){
      if(tiempoActual < 5000)
	return 5; //FIXME los límites de tiempo superados
      else
	{
	  sirenaOut.off();
	  indicador.off();
	  return 1; //FIXME los límites de tiempo superados
	}      
    }
    else
      return 0;
}




