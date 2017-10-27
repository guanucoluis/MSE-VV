/****************************************************
    nombre de archivo: Pulsador.cpp
    fecha: 25/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase que lee el estado del pulsador
****************************************************/

#include "Pulsador.h"

#define DEBUG

Pulsador::Pulsador(void){
  #ifdef DEBUG
    Serial.println("Objeto Pulsador creado");
  #endif
  pulso = false;
}

boolean Pulsador::get(void){
  sensorDigital = digitalRead(pinPulso);
  return sensorDigital;
}

void Pulsador::setPin(int pin){
  pinPulso = pin;
  pinMode(pinPulso, INPUT); 
}
