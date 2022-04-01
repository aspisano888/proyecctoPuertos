#include "DtArribo.h"

DtArribo::DtArribo(){}
DtArribo::DtArribo(DtFecha fecha, float carga, DtBarco barco){
    this->fecha = fecha;
    this->carga = carga;
    this->barco = barco;
}
void DtArribo::setFecha(DtFecha fecha){
    this->fecha = fecha;
}
void DtArribo::setCarga(float carga){
    this->carga = carga;
}
void DtArribo::setDtBarco(DtBarco barco){
    this->barco = barco;
}
DtFecha DtArribo::getFecha(){
    return this->fecha;
}
float DtArribo::getCarga(){
    return this->carga;
}
DtBarco DtArribo::getDtBarco(){
    return this->barco;
}
DtArribo::~DtArribo(){}
ostream & operator << (ostream & salida, DtArribo & arribo){
    return salida;
}