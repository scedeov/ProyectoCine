/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "grupoSalas.h"

Grupo_Salas::Grupo_Salas()
{
	cant = 0;
	for (int x = cant; x < tam; x++)
	{
		vector[x] = NULL;
	}

}

Grupo_Salas::~Grupo_Salas()
{
}

Sala* Grupo_Salas::getSala(int TipoSala)
{
	return vector[TipoSala];
}

void Grupo_Salas::setSala(int TipoSala, Sala* unSala)
{
	if (vector[TipoSala] == NULL)
		vector[TipoSala] = unSala;
}

