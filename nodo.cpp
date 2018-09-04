/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "nodo.h"

Nodo::Nodo(Pelicula *unPel, Nodo* unNext) 
{
	pel = unPel;
	next = unNext;
}

Nodo::~Nodo() 
{
	delete pel;
}

void Nodo::setPelicula(Pelicula *unPel) 
{ 
	pel = unPel; 
}

Pelicula* Nodo::getPelicula() 
{ 
	return pel; 
}

void Nodo::setNext(Nodo* unNext) 
{ 
	next = unNext; 
}

Nodo* Nodo::getNext() 
{ 
	return next; 
}

string Nodo::toStringNodo() 
{
	return pel->imprimenCart();
}