/****************************************************
    nombre de archivo: Alarm.h
    fecha: 19/10/2017
    creado por: lguanuco
    version: 1.0
    Descripcion: Declaración de la clase Alarm
****************************************************/

#include "Arduino.h"
#include "Referencia.h"

class Alarm
{
  public:
    Alarm(void);
    void iniciar(void);
    void armar(void);
    void disparar(void);    
    void detener(void);    
    void keepalive(void);
  private:
    Referencia ref;
    int inRef;
    
};

