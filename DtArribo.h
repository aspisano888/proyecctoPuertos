#ifndef DTARRIBO
#define DTARRIBO
#include "DtFecha.h"
#include "DtBarco.h"
#include <iostream>
using namespace std;

class DtArribo{
private:
  DtFecha fecha;
  float carga;
  DtBarco barco;
public:
  DtArribo();
  DtArribo(DtFecha, float, DtBarco);
  void setFecha(DtFecha fecha);
  void setCarga(float carga);
  void setDtBarco(DtBarco barco);
  DtFecha getFecha();
  float getCarga();
  DtBarco getDtBarco();       
  ~DtArribo();
  friend ostream & operator << (ostream &, DtArribo &);
};

#endif