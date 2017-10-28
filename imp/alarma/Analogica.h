/****************************************************
    nombre de archivo: Analogica.h
    fecha: 21/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase abstracta, base para las 
                 diferentes entradas analógicas.
****************************************************/
#ifndef ANALOGICA_H
#define ANALOGICA_H

#include "Arduino.h"
#include "Inputs.h"

class Analogica : public Inputs {
 public:
  virtual int get(void) = 0;
};

#endif
