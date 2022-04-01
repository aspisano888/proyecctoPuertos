#ifndef BARCOPESQUERO
#define BARCOPESQUERO
#include "Barco.h"
#include "DtBarcoPesquero.h"

class BarcoPesquero : public Barco {
   private:
    int capacidad;
    int carga;

   public:
    BarcoPesquero();
    BarcoPesquero(string, string, int, int);
    void setCapacidad(int);
    void setCarga(int);
    int getCapacidad();
    int getCarga();
    ~BarcoPesquero();
    void arribar(float cargaDespacho);

    DtBarco* getDtBarco();
};

#endif
