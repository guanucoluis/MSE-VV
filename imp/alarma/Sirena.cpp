/****************************************************
    nombre de archivo: Sirena.cpp
    fecha: 27/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase que maneja la Sirena (salida)
****************************************************/

#include "Sirena.h"

#define DEBUG

Sirena::Sirena(void){
  #ifdef DEBUG
    Serial.println("Objeto Sirena creado");
  #endif
    pinSirena = 0;
}

void Sirena::setPin(int pin){
  pinSirena = pin;
  pinMode(pinSirena, OUTPUT); 
}

void Sirena::toggle(void){
  digitalWrite(pinSirena,HIGH);
  delay(300); //FIXME definir en alto nivel
  digitalWrite(pinSirena,LOW);
  delay(300); //FIXME definir en alto nivel
}

void Sirena::off(void){
  digitalWrite(pinSirena,LOW);
}

