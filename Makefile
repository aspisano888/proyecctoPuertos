main: Barco.o Arribo.o Puerto.o BarcoPasajeros.o BarcoPesquero.o DtBarcoPasajeros.o DtBarcoPesquero.o DtPuerto.o DtArribo.o DtBarco.o DtFecha.o main.o
	g++ Barco.o Arribo.o Puerto.o BarcoPasajeros.o BarcoPesquero.o DtBarcoPasajeros.o DtBarcoPesquero.o DtPuerto.o DtArribo.o DtBarco.o DtFecha.o main.o -o main

BarcoPasajeros.o: BarcoPasajeros.cpp

BarcoPesquero.o: BarcoPesquero.cpp

Barco.o: Barco.cpp

Arribo.o: Arribo.cpp

Puerto.o: Puerto.cpp

DtBarcoPasajeros.o: DtBarcoPasajeros.cpp

DtBarcoPesquero.o: DtBarcoPesquero.cpp

DtPuerto.o: DtPuerto.cpp

DtArribo.o: DtArribo.cpp

DtBarco.o: DtBarco.cpp

DtFecha.o: DtFecha.cpp

main.o: main.cpp

clean:
	rm -rf *.o main
	clear