#include "BarcoPesquero.h"

BarcoPesquero::BarcoPesquero() {}
BarcoPesquero::BarcoPesquero(string nombre, string id, int capacidad, int carga)
    : Barco(nombre, id) {
    this->capacidad = capacidad;
    this->carga = carga;
}
void BarcoPesquero::setCapacidad(int) {
    this->capacidad = capacidad;
}
void BarcoPesquero::setCarga(int) {
    this->carga = carga;
}
int BarcoPesquero::getCapacidad() {
    return this->capacidad;
}
int BarcoPesquero::getCarga() {
    return this->carga;
}
BarcoPesquero::~BarcoPesquero() {}
void BarcoPesquero::arribar(float cargaDespacho) {
    this->carga = this->carga - cargaDespacho;
}

DtBarco* BarcoPesquero::getDtBarco() {
    DtBarcoPesquero* dtbpe = new DtBarcoPesquero(this->getNombre(), this->getId(), this->capacidad, this->carga);
    return dtbpe;
}
