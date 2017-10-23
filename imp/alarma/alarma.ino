/*  
    nombre de archivo: alarma.ino
    fecha: 19/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion:  Codigo principal del desarrollo "alarma" escribo para 
                  plataforma arduinoUNO.
*/

#include "Alarm.h"

#define DEBUG

int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
  Serial.begin(9600);
  #ifdef DEBUG
    Serial.println("Habilitado puerto serie para debug");
  #endif
  
  Alarm alarma;
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
