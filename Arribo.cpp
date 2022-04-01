#include "Arribo.h"

Arribo::Arribo(){}
Arribo::Arribo(DtFecha fecha, float carga, Barco * barco){
    this->fecha = fecha;
    this->carga = carga;
    this->barco = barco;
}
void Arribo::setFecha(DtFecha fecha){
    this->fecha = fecha;
}
void Arribo::setCarga(float carga){
    this->carga = carga;
}
void Arribo::setBarco(Barco * barco){
    this->barco = barco;
}
DtFecha Arribo::getFecha(){
    return this->fecha;
}
float Arribo::getCarga(){
    return this->carga;
}
Barco * Arribo::getBarco(){
    return this->barco;
}
Arribo::~Arribo(){}

DtBarco* Arribo::getDtBarco(){
  return this->barco->getDtBarco();
}

//    barco getBarco (){
//    return 
}