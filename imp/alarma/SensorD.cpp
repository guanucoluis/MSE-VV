/****************************************************
    nombre de archivo: SensorD.cpp
    fecha: 25/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase que lee el valor del sensor
                 digital.
****************************************************/

#include "SensorD.h"

#define DEBUG

SensorD::SensorD(void){
  #ifdef DEBUG
    Serial.println("Objeto SensorD creado");
  #endif
  sensorDigital = false;
}

boolean SensorD::get(void){
  sensorDigital = digitalRead(pinSensor);
  return sensorDigital;
}

void SensorD::setPin(int pin){
  pinSensor = pin;
  pinMode(pinSensor, INPUT); 
}

boolean SensorD::check(){
  if(get())
    return false;
  else
    return true;
}

