/****************************************************
    nombre de archivo: Referencia.h
    fecha: 21/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase Referencia.                 
****************************************************/

#include "Arduino.h"
#include "Analogica.h"

class Referencia : public Analogica {
 private:
  int refAnalogica;
  int pinRef;
  
 public:
   Referencia(void);
    int get(void);
   void setPin(int pin); 
};
