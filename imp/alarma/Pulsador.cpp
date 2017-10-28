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
  pulsado = false;
  registroInicioTiempo = 0;
  tiempoTranscurrido = 0;
}

bool Pulsador::presionado(void){
  pulsado = pulsadorCore.isPressed();
  if(pulsado == true)
    registroInicioTiempo = millis();
  return pulsado;
}

unsigned long Pulsador::tiempoDesdePulsado(unsigned long tiempoActual){
  if(registroInicioTiempo > tiempoActual)
    tiempoTranscurrido = tiempoActual + (4294967294 - registroInicioTiempo);
  else
    tiempoTranscurrido = tiempoActual - registroInicioTiempo;

  return tiempoTranscurrido;
}

bool Pulsador::pulsadorLiberado(void){
  return pulsadorCore.stateChanged();
}

/* FIXME
void Pulsador::setPin(int pin){
  pinPulso = pin;
  pinMode(pinPulso, INPUT); 
}
*/

