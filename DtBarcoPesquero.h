#ifndef DTBARCOPESQUERO
#define DTBARCOPESQUERO
#include "DtBarco.h"

class DtBarcoPesquero:public DtBarco{
private:
  int capacidad;
  int carga;
public:
  DtBarcoPesquero();
  DtBarcoPesquero(string, string, int, int);
  void setCapacidad(int);
  void setCarga(int);
  int getCapacidad();
  int getCarga();
  ~DtBarcoPesquero();
  friend ostream & operator << (ostream &, DtBarcoPesquero &);
};

#endif

