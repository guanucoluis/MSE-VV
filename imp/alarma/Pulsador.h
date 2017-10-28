/****************************************************
    nombre de archivo: Pulsador.h
    fecha: 25/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase Pulsador.
****************************************************/

#include "Arduino.h"
#include "Digital.h"
#include "Button.h"

class Pulsador : public Digital {
 private:
  bool pulsado;
  //  int pinPulso;
  Button pulsadorCore(13,PULLUP); //FIXME pasar por parametro el pin
  unsigned long registroTiempo;
  unsigned long tiempoTranscurrido;
  
 public:
   Pulsador(void);
   bool presionado(void);
   unsigned long tiempoDesdePulsado(unsigned long);
   bool pulsadorLiberado(void);
   //   void setPin(int pin);
};
