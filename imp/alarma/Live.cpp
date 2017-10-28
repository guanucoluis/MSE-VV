/****************************************************
    nombre de archivo: Live.cpp
    fecha: 28/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase que maneja el keep-alive (salida)
****************************************************/

#include "Live.h"

#define DEBUG

Live::Live(void){
  #ifdef DEBUG
    Serial.println("Objeto Live creado");
  #endif
    pinLive = 0;
}

void Live::setPin(int pin){
  pinLive = pin;
  pinMode(pinLive, OUTPUT);
  digitalWrite(pinLive,LOW);
}

void Live::generarSenal(void){
  digitalWrite(pinLive,HIGH);
  delay(200); //FIXME Buscar requerimiento de este tiempo
  digitalWrite(pinLive,LOW);
}

void Live::off(void){ //FIXME Nunca se utiliza
  digitalWrite(pinLive,LOW);
}
