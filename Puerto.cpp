#include "Puerto.h"
#include "Arribo.h"
#include "DtFecha.h"
Puerto::Puerto() {}
Puerto::Puerto(string id, string nombre, DtFecha fechaCreacion) {
    this->id = id;
    this->nombre = nombre;
    this->fechaCreacion = fechaCreacion;
    this->topeArribos = 0;
}
void Puerto::setId(string id) {-
    this->id = id;
}
void Puerto::setNombre(string nombre) {
    this->nombre = nombre;
}
void Puerto::setFechaCreacion(DtFecha fechaCreacion) {
    this->fechaCreacion = fechaCreacion;
}
string Puerto::getId() {
    return this->id;
}
string Puerto::getNombre() {
    return this->nombre;
}
DtFecha Puerto::getFechaCreacion() {
    return this->fechaCreacion;
}
/*Arribo ** Puerto::obtenerArribos(int & cantArribos){
    cantArribos = this->topeArribos;
    return this->arribo;
}*/
Puerto::~Puerto() {}

void Puerto::agregarArribo(Arribo* a) {
    this->arribo[this->topeArribos] = a;
    this->topeArribos++;
}

int Puerto::getTopeArribos() {
    return this->topeArribos;
}

DtArribo** Puerto::getDtArribo() {
    DtArribo** dtArribos = new DtArribo*[this->topeArribos];
    for (int i = 0; i < this->topeArribos; i++) {
        DtArribo* dta = new DtArribo(this->arribo[i]->getFecha(),
                                     this->arribo[i]->getCarga(),
                                     this->arribo[i]->getDtBarco());
        dtArribos[i] = dta;
    }
    return dtArribos;
}