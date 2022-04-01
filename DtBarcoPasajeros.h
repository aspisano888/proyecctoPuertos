#ifndef DTBARCOPASAJEROS
#define DTBARCOPASAJEROS
#include "DtBarco.h"
#include "TipoTamanio.h"
class DtBarcoPasajeros:public DtBarco{
private:
  int cantPasajeros;
  TipoTamanio tamanio;
public:
  DtBarcoPasajeros();
  DtBarcoPasajeros(string, string, int, TipoTamanio);
  void setCantPasajeros(int);
  void setTamanio(TipoTamanio);
  int getCantPasajeros();
  TipoTamanio getTamanio();
  ~DtBarcoPasajeros();
  friend ostream & operator << (ostream &, DtBarcoPasajeros &);
};

#endif