#ifndef BARCOPASAJEROS
#define BARCOPASAJEROS
#include "Barco.h"
#include "TipoTamanio.h"
#include "DtBarcoPasajeros.h"
class BarcoPasajeros:public Barco{
private:
  int cantPasajeros;
  TipoTamanio tamanio;
public:
  BarcoPasajeros();
  BarcoPasajeros(string, string, int, TipoTamanio);
  void setCantPasajeros(int);
  void setTamanio(TipoTamanio);
  int getCantPasajeros();
  TipoTamanio getTamanio();
  ~BarcoPasajeros();
  void arribar(float cargaDespacho);
  
  DtBarco* getDtBarco();
};

#endif