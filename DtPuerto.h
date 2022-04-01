#ifndef DTPUERTO
#define DTPUERTO
#include "DtFecha.h"
#include <iostream>
using namespace std;

class DtPuerto{
private:
  string id;
  string nombre;
  DtFecha fechaCreacion;
  int cantArribos;
public:
  DtPuerto();
  DtPuerto(string, string, DtFecha, int);
  void setId(string);
  void setNombre(string);
  void setFechaCreacion(DtFecha);
  void setCantArribos(int);
  string getId();
  string getNombre();
  DtFecha getFechaCreacion();
  int getCantArribos();
  ~DtPuerto();
  friend ostream & operator << (ostream &, DtPuerto &);
};

#endif