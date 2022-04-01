#ifndef BARCO
#define BARCO
#include <iostream>
#include<string>
#include "DtBarco.h"
using namespace std;

class Barco{
private:
  string nombre;
  string id;
public:
  Barco();
  Barco(string, string);
  void setNombre(string nombre);
  void setId(string id);
  string getNombre();
  string getId();
  ~Barco();
  
  virtual DtBarco* getDtBarco()=0;
  
  virtual void arribar(float cargaDespacho) = 0;
  friend ostream & operator << (ostream &, const Barco &);
};

#endif


