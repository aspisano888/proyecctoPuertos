#include "DtPuerto.h"
#include "DtFecha.h"
DtPuerto::DtPuerto(){}
DtPuerto::DtPuerto(string id, string nombre, DtFecha fechaCreacion, int cantArribos){
    this->id = id;
    this->nombre = nombre;
    this->fechaCreacion = fechaCreacion;
    this->cantArribos = cantArribos;
}
void DtPuerto::setId(string id){
    this->id = id;
}
void DtPuerto::setNombre(string nombre){
    this->nombre = nombre;
}
void DtPuerto::setFechaCreacion(DtFecha fechaCreacion){
    this->fechaCreacion = fechaCreacion;
}
void DtPuerto::setCantArribos(int cantArribos){
    this->cantArribos = cantArribos;
}
string DtPuerto::getId(){
    return this->id;
}
string DtPuerto::getNombre(){
    return this->nombre;
}
DtFecha DtPuerto::getFechaCreacion(){
    return this->fechaCreacion;
}
int DtPuerto::getCantArribos(){
    return this->cantArribos;
}
DtPuerto::~DtPuerto(){}
ostream & operator << (ostream & salida, DtPuerto & puerto){
    cout << "Id: " << puerto.id << " Nombre: " << puerto.nombre << " Fecha: " << puerto.fechaCreacion << " Arribos: " << puerto.cantArribos << endl;
    return salida;
}

