/****************************************************
    nombre de archivo: IndicadorLuminoso.cpp
    fecha: 27/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase que maneja la IndicadorLuminoso (salida)
****************************************************/

#include "IndicadorLuminoso.h"

#define DEBUG

IndicadorLuminoso::IndicadorLuminoso(void){
  #ifdef DEBUG
    Serial.println("Objeto IndicadorLuminoso creado");
  #endif
    pinIndicadorLuminoso = 0;
}

void IndicadorLuminoso::setPin(int pin){
  pinIndicadorLuminoso = pin;
  pinMode(pinIndicadorLuminoso, OUTPUT); 
}

void IndicadorLuminoso::toggle(void){
  digitalWrite(pinIndicadorLuminoso,HIGH);
  delay(300); //FIXME definir en alto nivel
  digitalWrite(pinIndicadorLuminoso,LOW);
  delay(300); //FIXME definir en alto nivel
}

void IndicadorLuminoso::off(void){
  digitalWrite(pinIndicadorLuminoso,LOW);
}
