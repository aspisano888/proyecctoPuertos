#include "Arribo.h"
#include "Barco.h"
#include "BarcoPasajeros.h"
#include "BarcoPesquero.h"
#include "DtArribo.h"
#include "DtBarco.h"
#include "DtBarcoPasajeros.h"
#include "DtBarcoPesquero.h"
#include "DtFecha.h"
#include "DtPuerto.h"
#include "Puerto.h"
#include "TipoTamanio.h"
#define MAX_PUERTOS 30
#define MAX_BARCOS 50
#include <iostream>
using namespace std;

struct str_puerto {
    Puerto* puertos[MAX_PUERTOS];
    int topePuerto;
} colPuertos;

struct str_barco {
    Barco* barco[MAX_BARCOS];
    int topeBarco;
} colBarcos;

DtFecha* f = new DtFecha();
int dia, mes, anio;
string id, nombre;

void menuAgregarPuerto() {
    //pedir ID, nombre y fecha.
    cout << "Ingrese el ID del puerto: ";
    cin >> id;
    cout << "Ingrese nombre del puerto: ";
    cin >> nombre;
    cout << "Ingrese el dia de creacion: ";
    cin >> dia;
    cout << "Ingrese el mes de creacion: ";
    cin >> mes;
    cout << "Ingrese el anio de creacion: ";
    cin >> anio;

    try {
        *f = DtFecha(dia, mes, anio);
    } catch (invalid_argument& fechaMal) {
        cout << fechaMal.what() << endl;
    }
    //__________________________________________________________
}

void agregarPuerto(string id, string nombre, DtFecha fechaCreacion) {  // [A] Agregar puerto. S]i existe un puerto con el mismo identificador, levanta la excepción std::invalid_argument.
    bool existe = false;
    int i = 0;
    while ((i < colPuertos.topePuerto) && (!existe)) {
        if (id == colPuertos.puertos[i]->getId()) {
            existe = true;
        }
        i++;
    }
    if (existe) {
        throw invalid_argument("Error, existe un puerto con el mismo indentificador");
    } else {
        Puerto* p = new Puerto(id, nombre, fechaCreacion);
        colPuertos.puertos[colPuertos.topePuerto] = p;
        colPuertos.topePuerto++;
    }
}

void agregarBarco(DtBarco& barco) {  // [B] Agregar barco. Si existe un barco con el mismo identificador, levanta una excepción std::invalid_argument.
    bool existe = false;
    int i = 0;
    while ((i < colBarcos.topeBarco) && (!existe)) {
        if (barco.getId() == colBarcos.barco[i]->getId()) {
            existe = true;
        }
        i++;
    }
    if (existe) {
        throw invalid_argument("Error, existe un puerto con el mismo indentificador");
    } else {
        try {
            DtBarcoPasajeros& dtbpa = dynamic_cast<DtBarcoPasajeros&>(barco);
            BarcoPasajeros* barcoPasajeros = new BarcoPasajeros(dtbpa.getNombre(),
                                                                dtbpa.getId(),
                                                                dtbpa.getCantPasajeros(),
                                                                dtbpa.getTamanio());
            colBarcos.barco[colBarcos.topeBarco] = barcoPasajeros;
            colBarcos.topeBarco++;
        } catch (bad_cast) {
            try {
                DtBarcoPesquero& dtbpe = dynamic_cast<DtBarcoPesquero&>(barco);
                BarcoPesquero* barcoPesquero = new BarcoPesquero(dtbpe.getNombre(),
                                                                 dtbpe.getId(),
                                                                 dtbpe.getCapacidad(),
                                                                 dtbpe.getCarga());
                colBarcos.barco[colBarcos.topeBarco] = barcoPesquero;
                colBarcos.topeBarco++;
            } catch (bad_cast) {
            }
        }
    }
}

DtPuerto** listarPuertos(int& cantPuertos) {  // [C] Devuelve un arreglo con información de los puertos registrados.
    cantPuertos = colPuertos.topePuerto;
    DtPuerto** listado = new DtPuerto*[cantPuertos];
    for (int i = 0; i < colPuertos.topePuerto; i++) {
        DtPuerto* dtp = new DtPuerto(dtp->getId(),
                                     dtp->getNombre(),
                                     dtp->getFechaCreacion(),
                                     dtp->getCantArribos());
        listado[i] = dtp;
    }
    return listado;
}

void agregarArribo(string idPuerto, string idBarco, DtFecha fecha, float cargaDespacho) {  // [D] Agregar arribo al puerto (idPuerto) correspondiente al barco (IdBarco) en la fecha actual y con el valor de la carga que se despacha (cargaDespacho).
    // 1 busco el puerto
    int j=0;
    while(colPuertos.puertos[j]->getId()!=idPuerto)
    j++;
    // 2 busco barco
    int i = 0;
    while (colBarcos.barco[i]->getId() != idBarco)
    i++;
    // 3 creo el arribo y le asigno el barco
    Arribo* a = new Arribo(fecha,cargaDespacho,colBarcos.barco[i]); 
    // 4 agrego el arribo a la coleccion de arribos del puerto
    colPuertos.puertos[j]->agregarArribo(a); // desde puertos asigno el arribo
}



void menuArribosDePuertos();
DtArribo** arribosDePuertos(string puertos, int& topeArribos){
  int i=0;
  while(colPuertos.puertos[i]->getId()!=puertos)
    i++;
  topeArribos=colPuertos.puertos[i]->getTopeArribos();
  DtArribo** arribos = colPuertos.puertos[i]->getDtArribo();
  return arribos;
}










DtArribo** obtenerInfoArribosEnPuerto(string idPuerto, int& cantArribos) {  // Devuelve un arreglo con información de los arribos en el puerto (idPuerto). cantArribos es un parámetro de salida, devuelve la cantidad de arribos.
    return NULL;
}

void eliminarArribos(string idPuerto, DtFecha fecha) {  // Elimina los arribos en el puerto (idPuerto) en la fecha ingresada.
}

DtBarco** listarBarcos(int& cantBarcos) {  // Devuelve un arreglo con información de los barcos. cantBarcos es un parámetro de salida, devuelve la cantidad de barcos.
    cantBarcos = colBarcos.topeBarco;
    DtBarco** listado = new DtBarco*[cantBarcos];
    for (int i = 0; i < colBarcos.topeBarco; i++) {
        if (BarcoPasajeros* bpa = dynamic_cast<BarcoPasajeros*>(colBarcos.barco[i])) {
            DtBarcoPasajeros* dtbpa = new DtBarcoPasajeros(bpa->getNombre(),
                                                           bpa->getId(),
                                                           bpa->getCantPasajeros(),
                                                           bpa->getTamanio());
            listado[i] = dtbpa;
        } else if (BarcoPesquero* bpe = dynamic_cast<BarcoPesquero*>(colBarcos.barco[i])) {
            DtBarcoPesquero* dtbpe = new DtBarcoPesquero(bpe->getNombre(),
                                                         bpe->getId(),
                                                         bpe->getCapacidad(),
                                                         bpe->getCarga());
            listado[i] = dtbpe;
        }
    }
    return listado;
}

void menu();  // Menu

int main() {
    int opcion;
    colPuertos.topePuerto = 0;
    colBarcos.topeBarco = 0;
    DtBarcoPasajeros* r;
    DtBarco* b = new DtBarcoPasajeros("buquebus", "1234", 5, bote);
    menu();
    cin >> opcion;
    while (opcion != 8) {
        switch (opcion) {
            case 1:
                menuAgregarPuerto();
                agregarPuerto(id, nombre, *f);
                //agregarPuerto("2", "Rio de Janeiro", *f);
                cout << "Id: " << colPuertos.puertos[0]->getId() << " Nombre: " << colPuertos.puertos[0]->getNombre() << " Fecha: " << colPuertos.puertos[0]->getFechaCreacion().getDia() << "/" << colPuertos.puertos[0]->getFechaCreacion().getMes() << "/" << colPuertos.puertos[0]->getFechaCreacion().getAnio() << endl;
                //cout << "Id: " << colPuertos.puertos[1]->getId() << " Nombre: " << colPuertos.puertos[1]->getNombre() << " Fecha: " << colPuertos.puertos[1]->getFechaCreacion().getDia() << "/" << colPuertos.puertos[1]->getFechaCreacion().getMes() << "/" << colPuertos.puertos[1]->getFechaCreacion().getAnio() << endl;
                cout << "Pulse enter para continuar..." << endl;
                system("read X");
                break;
            case 2:

                agregarBarco(*b);
                r = dynamic_cast<DtBarcoPasajeros*>(colBarcos.barco[0]);
                cout << *r << endl;
                cout << "Pulse enter para continuar..." << endl;
                system("read X");
                break;
            case 3:
                // listarPuertos(int & cantPuertos);
                break;
            case 4:
                // agregarArribo(string idPuerto, string idBarco, DtFecha fecha, float cargaDespacho);
                break;
            case 5:
                // obtenerInfoArribosEnPuerto(string idPuerto, int & cantArribos);
                break;
            case 6:
                // eliminarArribos(string idPuerto, DtFecha fecha);
                break;
            case 7:
                // listarBarcos(int & cantBarcos);
                break;
            case 8:
                system("exit");
                cout << "SALIENDO..." << endl;
            default:
                cout << "OPCIÓN INCORRECTA" << endl;
        }
        menu();
        cin >> opcion;
    }
}

void menu() {
    system("clear");
    cout << "Bienvenido, elija la opcion:" << endl;
    cout << "   1. Agregar puerto" << endl;
    cout << "   2. Agregar barco" << endl;
    cout << "   3. Lista puertos" << endl;
    cout << "   4. Agregar arribo" << endl;
    cout << "   5. Informacion arribos" << endl;
    cout << "   6. Eliminar arribos" << endl;
    cout << "   7. Listar barcos" << endl;
    cout << "   8. Salir" << endl;
    cout << "Opcion: ";
}
