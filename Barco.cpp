#include "Barco.h"
#include <iostream>
using namespace std;

Barco::Barco(){}
Barco::Barco(string nombre, string id){
    this->nombre = nombre;
    this->id = id;
}
void Barco::setNombre(string nombre){
    this->nombre = nombre;
}
void Barco::setId(string id){
    this->id = id;
}
string Barco::getNombre(){
    return this->nombre;
}
string Barco::getId(){
    return this->id;
}
ostream & operator << (ostream & salida, const Barco & barco){
    cout << "Nombre: " << barco.nombre << " Id: " << barco.id << endl;
    return salida;
}
Barco::~Barco(){}
