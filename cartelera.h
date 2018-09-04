#ifndef CARTELERA
#define CARTELERA

/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "nodo.h"
#include <sstream>
#include <time.h>

class Cartelera
{
private:
	Nodo* primero;
	Nodo* paux;

public:
	Cartelera();
	~Cartelera();
	bool insertarFinal(Pelicula*);
	bool eliminaporID(string);
	string toStringCart();
	bool cvacia();
	string generaID(string, int);
	bool buscaGenero(string);
	bool buscaNombre(string);
	bool buscaTipo(int);
	bool buscaDimension(int);
	bool buscaTipoSala(int);
	bool buscaPublico(int);
	string convierteMinuscula(string);
};

#endif
