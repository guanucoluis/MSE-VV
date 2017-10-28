/****************************************************
    nombre de archivo: Alarm.h
    fecha: 19/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase Alarm
****************************************************/

#include "Arduino.h"
#include "Referencia.h"
#include "SensorA.h"
#include "SensorD.h"
#include "Pulsador.h"
#include "Sirena.h"
#include "IndicadorLuminoso.h"
#include "Live.h"

class Alarm
{
  public:
    Alarm(void);
    void iniciar(void);
    boolean armar(void);
    void disparar(void);    
    int detener(void);    

 private:    
    Referencia ref;
    SensorA sensorAnalogico;
    SensorD sensorDigital;
    Pulsador pulsadorControl;
    Sirena sirenaOut;
    IndicadorLuminoso indicador;
    Live keepAlive;
    unsigned long tiempoActual;
    
};

