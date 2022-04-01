#include "DtBarcoPasajeros.h"

DtBarcoPasajeros::DtBarcoPasajeros(){}
DtBarcoPasajeros::DtBarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio):DtBarco(nombre, id){
    this->cantPasajeros = cantPasajeros;
    this->tamanio = tamanio;
}
void DtBarcoPasajeros::setCantPasajeros(int cantPasajeros){
    this->cantPasajeros = cantPasajeros;
}
void DtBarcoPasajeros::setTamanio(TipoTamanio tamanio){
    this->tamanio = tamanio;
}
int DtBarcoPasajeros::getCantPasajeros(){
    return this->cantPasajeros;
}
TipoTamanio DtBarcoPasajeros::getTamanio(){
    return this->tamanio;
}
DtBarcoPasajeros::~DtBarcoPasajeros(){}
ostream & operator << (ostream & salida, DtBarcoPasajeros & pasajero){
    cout << (DtBarco) pasajero << " Cant. Pasajeros: " << pasajero.cantPasajeros << " Tamanio: " << pasajero.tamanio << endl;
    return salida;
}

