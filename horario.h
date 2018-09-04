#ifndef HORARIO
#define HORARIO
/*	Version 1.0
27/09/16
Steven Cedeño V.
*/


#include "grupoSalas.h"

using namespace std;
const int dias = 7; 
const int funciones = 3; // la cantidad de funciones en un dia

class Horario //administra grupos de salas ( en este caso dos) 
{
private:
	Grupo_Salas*** h;

public:
	Horario();
	void setGrupoSalas(string, Grupo_Salas*);
	string imprimeHorario();
	string diahorario(int);
	string funhorario(int);
	Grupo_Salas* getGrupo(string);
	~Horario();

};


#endif

