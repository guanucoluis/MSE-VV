/****************************************************
    nombre de archivo: Inputs.h
    fecha: 21/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase abstracta, base para las 
                 diferentes entradas
****************************************************/

#include "Arduino.h"

class Inputs {
 public:
  virtual int get(void) = 0;

};
