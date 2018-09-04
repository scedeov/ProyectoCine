#ifndef CONTROL
#define CONTROL
//-------------------
/*	Version 1.0
27/09/16
Steven Cedeño V.
*/
//----------------------
#include "cartelera.h"
#include "grupoSalas.h"
#include "interfaz.h"
#include "pelicula.h"
#include "sala.h"
#include "tiquete.h"
#include "horario.h"
//---------------------
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h> //_getch para hacer una experiencia mas automatizada

using namespace std;

class Control
{
private:
	Interfaz	i;
	Cartelera*	c;
	Horario*	h;

public:
	Control();
	~Control();
	void Principal();
	void opcionAdmin();
	void opcionCartelera();
	void opcionBuscar();
	void opcionComprar();
	void porFilas();
	void pausa();
	void individualmente();
	void pass();
	void ingPelicula();
	void eliminaPelicula();
	Sala* recuperaSalaporCodigo(string);
};
#endif