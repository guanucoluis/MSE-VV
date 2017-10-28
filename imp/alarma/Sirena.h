/****************************************************
    nombre de archivo: Sirena.h
    fecha: 27/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase Sirena.
****************************************************/

#include "Arduino.h"
#include "Indicadores.h"
#include "DigitalToggle.h"

class Sirena : public Indicadores {
 private:
  int pinSirena;
  
 public:
   Sirena(void);
   void setPin(int);
   void toggle(void);   
};
