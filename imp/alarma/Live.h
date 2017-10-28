/****************************************************
    nombre de archivo: Live.h
    fecha: 28/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase Live.
****************************************************/

#include "Arduino.h"
#include "Indicadores.h"

class Live : public Indicadores {
 private:
  int pinLive;
  
 public:
   Live(void);
   void setPin(int);
   void generarSenal(void);
   void off(void);
};
