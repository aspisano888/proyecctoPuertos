#ifndef PUERTO
#define PUERTO
#define MAX_ARRIBOS 30
#include "DtFecha.h"
#include "DtArribo.h"
#include <iostream>
using namespace std;

class Puerto{
private:
  //ATRIBUTOS
  string id;
  string nombre;
  DtFecha fechaCreacion;
  //PSEUDOATRIBUTOS
  Arribo * arribo[MAX_ARRIBOS];
  int topeArribos;
public:
  Puerto();
  Puerto(string, string, DtFecha);
  void setId(string);
  void setNombre(string);
  void setFechaCreacion(DtFecha);
  string getId();
  string getNombre();
  DtFecha getFechaCreacion();
  Arribo ** obtenerArribos(int &);
  ~Puerto();
  int getTopeArribos ();
  void agregarArribo(Arribo* a);
  DtArribo** getDtArribo();
};

#endif
