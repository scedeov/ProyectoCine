#ifndef PELICULA_H
#define PELICULA_H

/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


class Pelicula
{
private:
	string genero;
	string nombre;
	string sipnosis;
	string pais;
	string ID;
	int anno;
	int sala; //
	bool tipo; // true = doblada, false = subtitulada
	bool publico; // true = adultos, false = ninos
	bool dimension; // true = 3D, false = 2D


public:
	Pelicula();
	Pelicula(string, string, string, bool, bool, bool, int, string, int);
	~Pelicula();
	void setGen(string);
	void setID(string);
	void setNom(string);
	void setSip(string);
	void setAnno(int);
	void setPais(string);
	void setSala(int);
	void CambiaTipo(int);
	void CambiaPublico(int);
	void CambiaDimension(int);
	string getGen();
	string getNom();
	string getSip();
	int getAnno();
	string getID();
	int	getSala();
	string getPais();
	bool getTipo();
	bool getPublico();
	bool getDimension();
	string toString();
	string imprimenCart();
	string imprimehorario();
	int imprimeprecio();

};


#endif
