/****************************************************
    nombre de archivo: Indicadores.h
    fecha: 28/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase abstracta, base para las 
                 diferentes salidas
****************************************************/
#ifndef INDICADORES_H
#define INDICADORES_H

#include "Arduino.h"

class Indicadores {
 public:
  virtual void off(void) = 0;
};

#endif
