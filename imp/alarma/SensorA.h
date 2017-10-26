/****************************************************
    nombre de archivo: SensorA.h
    fecha: 25/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase SensorA.                 
****************************************************/

#include "Arduino.h"
#include "Analogica.h"

class SensorA : public Analogica {
 private:
  int sensorAnalogico;
  int pinSensor;
  
 public:
   SensorA(void);
   int get(void);
   void setPin(int pin);
   boolean check(int refSensor);
};
