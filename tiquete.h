#ifndef TIQUETE
#define TIQUETE

/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include <iostream>
#include "pelicula.h"
#include "sala.h"
#include "time.h"

using namespace std;

class Tiquete
{
public:
	int precioTiquete(Pelicula*);
	int precioTotal(Pelicula*, Sala*);
	int codigoTiquete();
	string imprimeTiquete(Pelicula*, Sala*);

};

#endif
