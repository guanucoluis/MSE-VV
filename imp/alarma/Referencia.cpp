/****************************************************
    nombre de archivo: Referencia.cpp
    fecha: 22/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase que lee el valor de referencia
                 para el sensor analógico (umbral).                 
****************************************************/

#include "Referencia.h"

Referencia::Referencia(void){
  refAnalogica = 0;
}

int Referencia::get(void){
  refAnalogica = analogRead(pinRef);
  return refAnalogica;
}

void Referencia::setPin(int pin){
  pinRef = pin;
}


