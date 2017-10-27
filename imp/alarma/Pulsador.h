/****************************************************
    nombre de archivo: Pulsador.h
    fecha: 25/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase Pulsador.
****************************************************/

#include "Arduino.h"
#include "Digital.h"

class Pulsador : public Digital {
 private:
  boolean pulso;
  int pinPulso;
  
 public:
   Pulsador(void);
   boolean get(void);
   void setPin(int pin);
   boolean check(void);
};
