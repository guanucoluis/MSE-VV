/****************************************************
    nombre de archivo: IndicadorLuminoso.h
    fecha: 27/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase IndicadorLuminoso.
****************************************************/

#include "Arduino.h"
#include "Indicadores.h"
#include "DigitalToggle.h"

class IndicadorLuminoso : public Indicadores {
 private:
  int pinIndicadorLuminoso;
  
 public:
   IndicadorLuminoso(void);
   void setPin(int);
   void toggle(void);   
};
