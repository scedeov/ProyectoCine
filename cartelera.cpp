/*	Version 1.0
27/09/16
Steven Cedeño V.
*/


#include "cartelera.h"

Cartelera::Cartelera()
{
	primero = NULL;
	paux = NULL;
}

Cartelera::~Cartelera()
{
	delete primero;
}


bool Cartelera::insertarFinal(Pelicula* p) //ingresa una pelicula al final de cada lista
{
	paux = primero;
	if (primero == NULL)
	{
		primero = new Nodo(p, NULL);
		return true;
	}
	else
	{
		while (paux->getNext() != NULL) 
		{
			paux = paux->getNext();

		}
		paux->setNext(new Nodo(p, NULL));
		return true;
	}
}

bool Cartelera::eliminaporID(string unID)
{
	Nodo* panterior = NULL;
	paux = primero;

	if (primero == NULL) 
	{ 
		return false; 
	}

	if (primero->getPelicula()->getID() == unID)
	{
		paux = paux->getNext();
		delete (primero);
		primero = paux;
		return true;
	}

	while (paux != NULL &&   paux->getPelicula()->getID() != unID)
	{
		panterior = paux;
		paux = paux->getNext();
	}

	if (paux == NULL) 
	{ 
		return false; 
	}

	else
	{
		panterior->setNext(paux->getNext());
		delete paux;
		return true;
	}
}

string Cartelera::toStringCart()
{
	stringstream s;
	paux = primero;

	if (paux == NULL)
	{
		s << "No hay peliculas enlistadas en este momento, por favor contacte al administrador. " << endl;
		s << endl << endl;
		return s.str();
	}
	else
	{
		while (paux != NULL)
		{
			s << paux->toStringNodo() << endl;
			paux = paux->getNext();
		}
		return s.str();
	}
}

bool Cartelera::cvacia()
{
	paux = primero;
	if (paux == NULL)
		return true;
	else
		return false;
}


string Cartelera::generaID(string posicionMatriz, int posicionGrupoSala) // este id es importante ya que permite ubicar la pelicula desde la matriz de horarios
{
	string codigo = posicionMatriz + to_string(posicionGrupoSala);
	return codigo;
}



bool Cartelera::buscaGenero(string gen)
{
	paux = primero;
	while (paux != NULL)
	{
		if (convierteMinuscula(paux->getPelicula()->getGen()) == convierteMinuscula(gen))
		{
			cout << paux->getPelicula()->toString();
			return true;
		}
		paux = paux->getNext();
	}
	return false;
}

bool Cartelera::buscaNombre(string unNom)
{
	paux = primero;
	while (paux != NULL)
	{
		if (convierteMinuscula(paux->getPelicula()->getNom()) == convierteMinuscula(unNom))
		{
			cout << paux->getPelicula()->toString();
			return true;
		}
		paux = paux->getNext();
	}
	return false;
}

bool Cartelera::buscaTipo(int unTipo)
{
	bool aux;

	if (unTipo == 1)
		aux = true;
	else
		aux = false;

	paux = primero;
	while (paux != NULL)
	{
		if (paux->getPelicula()->getTipo() == aux)
		{
			cout << paux->getPelicula()->toString();
			return true;
		}
		paux = paux->getNext();
	}
	return false;
}

bool Cartelera::buscaDimension(int di)
{

	bool aux;
	if (di == 1)
		aux = true;
	else
		aux = false;

	paux = primero;
	while (paux != NULL)
	{
		if (paux->getPelicula()->getDimension() == aux)
		{
			cout << paux->getPelicula()->toString();
			return true;
		}
		paux = paux->getNext();
	}
	return false;
}

bool Cartelera::buscaTipoSala(int sa)
{
	paux = primero;
	while (paux != NULL)
	{
		if (paux->getPelicula()->getSala() == sa)
		{
			cout << paux->getPelicula()->toString();
			return true;
		}
		paux = paux->getNext();
	}
	return false;
}

bool Cartelera::buscaPublico(int pu)
{
	bool aux;
	if (pu == 1)
		aux = true;
	else
		aux = false;

	paux = primero;
	while (paux != NULL)
	{
		if (paux->getPelicula()->getPublico() == aux)
		{
			cout << paux->getPelicula()->toString();
			return true;
		}
		paux = paux->getNext();
	}
	return false;
}

string Cartelera::convierteMinuscula(string unString)
{
	stringstream s;
	for (int x = 0; unString[x]; x++)
		s << tolower(unString[x]);
	return s.str();
}


