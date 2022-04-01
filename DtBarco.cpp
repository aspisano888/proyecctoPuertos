#include "DtBarco.h"
#include <iostream>
using namespace std;

DtBarco::DtBarco(){}
DtBarco::DtBarco(string nombre, string id){
    this->nombre = nombre;
    this->id = id;
}
void DtBarco::setNombre(string nombre){
    this->nombre = nombre;
}
void DtBarco::setId(string id){
    this->id = id;
}
string DtBarco::getNombre(){
    return this->nombre ;
}
string DtBarco::getId(){
    return this->id;
}
DtBarco::~DtBarco(){}
ostream & operator << (ostream & salida, const DtBarco & barco){
    cout << "Nombre: " << barco.nombre << " Id: " << barco.id << endl;
    return salida;
}