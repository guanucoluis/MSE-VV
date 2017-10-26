/****************************************************
    nombre de archivo: Alarm.cpp
    fecha: 19/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Clase principal del sistema alarma.
****************************************************/

#include "Arduino.h"
#include "Alarm.h"

#define DEBUG 


Alarm::Alarm()
{
  #ifdef DEBUG
    Serial.println("Objeto Alarm creado");
  #endif
}

void Alarm::iniciar()
{
  #ifdef DEBUG
    Serial.println("Metodo iniciar()");
  #endif
}

void Alarm::armar()
{
    #ifdef DEBUG
    Serial.println("Metodo armar()");
  #endif
}

void Alarm::disparar()
{
  #ifdef DEBUG
    ref.setPin(A0);
    Serial.println("Metodo disparar()");
  #endif
}

void Alarm::detener()
{
  #ifdef DEBUG
    inRef = ref.get();
    Serial.println("Metodo detener()");
    Serial.print("Variable: ");
    Serial.println(inRef);
  #endif
}

void Alarm::keepalive()
{
}



