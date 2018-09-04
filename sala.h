#ifndef SALA_H  
#define SALA_H

/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h> // libreria para el cambio de color

#include "asiento.h"
#include "pelicula.h"


using namespace std;

const char fila = 'G'; //n+1 puesto que los asientos inician en 1
const int columna = 11; //n+1 puesto que los asientos inician en 1
//-----------------
enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE }; // enumero los colores para mejor orden

class Sala
{
private:
	Asiento asientos[fila][columna];
	Pelicula* p;
public:
	Sala();
	~Sala();

	bool setPos(string);

	void setPelicula(Pelicula*);
	Pelicula* getPelicula();

	Asiento getPos(string);
	void toString();
	void eliminaSeleccion();
	void CompraMomentaneaAsientos();
	void CompraDefinitivaAsientos();
	bool revisaMatriz(char, int);
	int retornaPrimeraPos(char);
	void seleccionaAsientos(char, int, int);
	int cuentaAsientos();
	string imprimeAsientosComprados();
	void cambiaColor(Color);

};

#endif