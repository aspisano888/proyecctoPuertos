#include "BarcoPasajeros.h"

BarcoPasajeros::BarcoPasajeros() {}
BarcoPasajeros::BarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio)
    : Barco(nombre, id) {
    this->cantPasajeros = cantPasajeros;
    this->tamanio = tamanio;
}
void BarcoPasajeros::setCantPasajeros(int cantPasajeros) {
    this->cantPasajeros = cantPasajeros;
}
void BarcoPasajeros::setTamanio(TipoTamanio tamanio) {
    this->tamanio = tamanio;
}
int BarcoPasajeros::getCantPasajeros() {
    return this->cantPasajeros;
}
TipoTamanio BarcoPasajeros::getTamanio() {
    return this->tamanio;
}
void BarcoPasajeros::arribar(float cargaDespacho) {}

DtBarco* BarcoPasajeros::getDtBarco() {
    DtBarcoPasajeros* dtbpa = new DtBarcoPasajeros(this->getNombre(), this->getId(), this->cantPasajeros, this->tamanio);
    return dtbpa;
}
