#ifndef ARRIBO
#define ARRIBO
#include "DtFecha.h"
#include "Barco.h"
#include <iostream>
using namespace std;

class Arribo{
private:
  DtFecha fecha;
  float carga;
  Barco * barco;
public:
  Arribo();
  Arribo(DtFecha, float, Barco *);
  void setFecha(DtFecha fecha);
  void setCarga(float carga);
  void setBarco(Barco * barco);
  DtFecha getFecha();
  float getCarga();
  Barco * getBarco();
  
  DtBarco* getDtBarco();
        
  
  ~Arribo();
};

#endif