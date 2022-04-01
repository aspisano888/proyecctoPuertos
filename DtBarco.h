#ifndef DTBARCO
#define DTBARCO
#include <iostream>
using namespace std;

class DtBarco{
private:
  string nombre;
  string id;
public:
  DtBarco();
  DtBarco(string, string);
  void setNombre(string nombre);
  void setId(string id);
  string getNombre();
  string getId();
  virtual ~DtBarco();
  friend ostream & operator << (ostream &, const DtBarco &);
};

#endif