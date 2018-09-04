#ifndef GRUPO_SALAS  // Clase que administra la objetos tipo Sala y se encarga de la cantidad de salas
#define GRUPO_SALAS
/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

const int tam = 2; //numero de salas


#include <iostream>
#include "sala.h"

class Grupo_Salas
{
private:
	Sala* vector[tam];
	int cant;
public:
	Grupo_Salas();
	~Grupo_Salas();
	Sala* getSala(int);
	void setSala(int, Sala*);
};
#endif
