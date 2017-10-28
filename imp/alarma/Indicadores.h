/****************************************************
    nombre de archivo: Indicadores.h
    fecha: 28/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase abstracta, base para las 
                 diferentes salidas
****************************************************/

#include "Arduino.h"

class Indicadores {
 public:
  virtual void on(void) = 0;
  virtual void off(void) = 0;
};
