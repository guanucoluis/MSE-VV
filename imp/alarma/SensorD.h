/****************************************************
    nombre de archivo: SensorD.h
    fecha: 25/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase SensorD.
****************************************************/

#include "Arduino.h"
#include "Digital.h"

class SensorD : public Digital {
 private:
  boolean sensorDigital;
  int pinSensor;
  
 public:
   SensorD(void);
   boolean get(void);
   void setPin(int pin);
   boolean check(void);
};
