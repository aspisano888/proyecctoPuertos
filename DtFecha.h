#ifndef DTFECHA
#define DTFECHA
#include <iostream>
using namespace std;

class DtFecha{
private:
  int dia;
  int mes;
  int anio;
public:
  DtFecha();
  DtFecha(int, int, int);
  void setDia(int dia);
  int getDia();
  void setMes(int mes);
  int getMes();
  void setAnio(int anio);
  int getAnio();
  ~DtFecha();
  friend ostream & operator << (ostream &, DtFecha &);
};

#endif