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

Alarm alarma;


// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600);
  #ifdef DEBUG
    Serial.println("Habilitado puerto serie para debug");
  #endif
  alarma.iniciar();
}

// the loop routine runs over and over again forever:
void loop() {

     if(alarma.armar() == false) //FIXME Revisar la lógica del true
        alarma.disparar();
     if(alarma.detener() == 5)
        alarma.iniciar();
}
	
