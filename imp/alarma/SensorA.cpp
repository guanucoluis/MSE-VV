/****************************************************
    nombre de archivo: SensorA.cpp
    fecha: 25/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase que lee el valor del sensor
                 analógico.
****************************************************/

#include "SensorA.h"

#define DEBUG

SensorA::SensorA(void){
  #ifdef DEBUG
    Serial.println("Objeto SensorA creado");
  #endif
  sensorAnalogico = 0;
}

int SensorA::get(void){
  sensorAnalogico = analogRead(pinSensor);
  return sensorAnalogico;
}

void SensorA::setPin(int pin){
  pinSensor = pin;
}

boolean SensorA::check(int refSensor){
  if(get()>=refSensor)
    return false;
  else
    return true;
}



