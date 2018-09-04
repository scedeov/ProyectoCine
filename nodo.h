#ifndef NODO
#define NODO

/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "pelicula.h"

class Nodo
{
private:
	Pelicula *pel;
	Nodo* next;
public:
	Nodo(Pelicula*, Nodo*);
	~Nodo();
	void setPelicula(Pelicula*);
	Pelicula* getPelicula();
	void setNext(Nodo*);
	Nodo* getNext();
	string toStringNodo();
};

#endif