/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "interfaz.h"

void Interfaz::MenuPrincipal()
{

	cout << "**********CINE**********" << endl;
	cout << "|1|--- CARTELERA " << endl;
	cout << "|2|--- COMPRAR TIQUETES " << endl;
	cout << "|3|--- ADMIN" << endl;
	cout << "|4|--- SALIR" << endl;
	cout << "************************" << endl;
	cout << endl << endl;


}

void Interfaz::MenuCartelera()
{
	cout << "**********CINE**********" << endl;
	cout << "|1|--- CARTELERA " << endl;
	cout << "	(a) Ver toda la cartelera" << endl;
	cout << "	(b) Filtrar pelicula" << endl;
	cout << "|*|--- COMPRAR TIQUETES " << endl;
	cout << "|*|--- ADMIN" << endl;
	cout << "|4|--- SALIR" << endl;
	cout << "************************" << endl;
}

void Interfaz::MenuFiltro()
{
	cout << "**********CINE**********" << endl;
	cout << "|1|--- CARTELERA " << endl;
	cout << "	(*) Ver toda la cartelera" << endl;
	cout << "	(B) Filtrar pelicula" << endl;
	cout << "		--Buscar por: " << endl;
	cout << "			(a) Genero" << endl;
	cout << "			(b) Nombre" << endl;
	cout << "			(c) Tipo (Subtitulada o Doblada)" << endl;
	cout << "			(d) Dimension (3D o 2D)" << endl;
	cout << "			(e) Sala" << endl;
	cout << "			(f) Publico" << endl;
	cout << "|*|--- COMPRAR TIQUETES " << endl;
	cout << "|*|--- ADMIN" << endl;
	cout << "|4|--- SALIR" << endl;
	cout << "************************" << endl;
}

void Interfaz::MenuComprar()
{

	cout << "**********CINE**********" << endl;
	cout << "|*|--- CARTELERA " << endl;
	cout << "|2|--- COMPRAR TIQUETES " << endl;
	cout << "	--Comprar por: " << endl;
	cout << "	(a) Asientos" << endl;
	cout << "	(b) Filas" << endl;
	cout << "|*|---ADMIN" << endl;
	cout << "|4|--- SALIR" << endl;
	cout << "************************" << endl;

}

void Interfaz::MenuAdministrador()
{
	cout << "**********CINE**********" << endl;
	cout << "|*|--- CARTELERA " << endl;
	cout << "|*|--- COMPRAR TIQUETES " << endl;
	cout << "|3|--- ADMIN" << endl;
	cout << "	(a) Agregar peliculas" << endl;
	cout << "	(b) Eliminar peliculas" << endl;
	cout << "|4|--- SALIR" << endl;
	cout << "************************" << endl;
	cout << endl << endl;

}
