#include "DtBarcoPesquero.h"

DtBarcoPesquero::DtBarcoPesquero(){}
DtBarcoPesquero::DtBarcoPesquero(string nombre, string id, int capacidad, int carga):DtBarco(nombre, id){
    this->capacidad = capacidad;
    this->carga = carga;
}
void DtBarcoPesquero::setCapacidad(int){
    this->capacidad = capacidad;
}
void DtBarcoPesquero::setCarga(int){
    this->carga = carga;
}
int DtBarcoPesquero::getCapacidad(){
    return this->capacidad;
}
int DtBarcoPesquero::getCarga(){
    return this->carga;
}
DtBarcoPesquero::~DtBarcoPesquero(){}

ostream & operator << (ostream & salida, DtBarcoPesquero & pesca){
    cout << (DtBarco) pesca << " Capacidad: " << pesca.capacidad << " Carga: " << pesca.carga << endl;
    return salida;
}

