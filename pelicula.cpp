/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "pelicula.h"

Pelicula::Pelicula()
{
	nombre = "Sin definir";
	genero = "Sin definir";
	sipnosis = "Sin definir";
	ID = "";
	anno = 0;
	pais = "Sin definir";
	tipo = true; // true = doblada, false = subtitulada
	sala = 0; // 1 = VIP, 2 = Regular, etc //en caso de mas salas
	publico = true; // true = adultos, false = ninos
	dimension = true; // true = 3D, false = 2D
}

Pelicula::Pelicula(string unNom, string unGen, string unPais, bool untipo, bool unPub, bool unDim, int unAnno, string unID, int unSala)
{
	nombre = unNom;
	genero = unGen;
	pais = unPais;
	tipo = untipo;
	publico = unPub;
	dimension = unDim;
	anno = unAnno;
	ID = unID;
	sala = unSala;
}

Pelicula::~Pelicula() {}

void Pelicula::setGen(string unGen) { genero = unGen; }
void Pelicula::setID(string unID) { ID = unID; }
void Pelicula::setNom(string unNom) { nombre = unNom; }
void Pelicula::setAnno(int unAnno) { anno = unAnno; }
void Pelicula::setPais(string unPais) { pais = unPais; }
void Pelicula::setSip(string unSip) { sipnosis = unSip; }


//-------------------------------------
void Pelicula::CambiaTipo(int unTipo)
{
	if (unTipo == 1)
		tipo = true;
	else
		tipo = false;
}

void Pelicula::setSala(int unSala)
{
	sala = unSala;
}

void Pelicula::CambiaPublico(int unPublico)
{
	if (unPublico == 1)
		publico = true;
	else
		publico = false;
}

void Pelicula::CambiaDimension(int unDimension)
{
	if (unDimension == 1)
		dimension = true;
	else
		dimension = false;
}
//---------------------------------------------

string	Pelicula::getGen() { return genero; }
string	Pelicula::getNom() { return nombre; }
string	Pelicula::getPais() { return pais; }
string	Pelicula::getSip() { return sipnosis; }
bool	Pelicula::getTipo() { return tipo; }

bool	Pelicula::getPublico() { return publico; }
bool	Pelicula::getDimension() { return dimension; }
int		Pelicula::getAnno() { return anno; }
string	Pelicula::getID() { return ID; }
int		Pelicula::getSala() { return sala; }



string Pelicula::toString() // imprime mas datos de las peliculas a lahora de buscarlas
{
	stringstream s;

	s << endl << endl;
	s << "Pelicula: " << "\"" << nombre << "\"" << endl;
	s << "ID: " << ID << endl;
	s << "Horario: " << imprimehorario() << endl;
	s << "Genero: " << genero << endl;
	s << "Sipnosis: " << endl << sipnosis << endl;
	s << "Anno: " << anno << endl;
	s << "Pais: " << pais << endl;
	//--------------------------------
	s << "Tipo: ";
	if (tipo == true)
		s << "Doblada" << endl;
	else
		s << "Subtitulada" << endl;
	//--------------------------------
	s << "Sala: ";
	if (sala == 1)
		s << "VIP" << endl; //en caso de que seas mas salas hay que cambiar el else
	else
		s << "Regular" << endl;
	//--------------------------------

	s << "Precio: " << imprimeprecio() << "/ persona" << endl;

	s << "Publico: ";
	if (publico == true)
		s << "Adultos" << endl;
	else
		s << "Ninos" << endl;
	//--------------------------------
	s << "Dimension: ";
	if (dimension == true)
		s << "3D" << endl;
	else
		s << "2D" << endl;
	//--------------------------------
	s << endl << endl;
	return s.str();
}

string Pelicula::imprimenCart() //imprime los datos de las peliculas de forma facil de entender a la hora de comprar un tiquete
{
	stringstream cs;
	cs << endl << endl;
	cs << "Pelicula: " << "\"" << nombre << "\"" << '\t';
	cs << "-- ";
	cs << "ID: " << ID << '\t';
	cs << "Horario:" << imprimehorario() << '\t';
	cs << "-- ";
	cs << "Precio:" << imprimeprecio() << '\t';

	if (tipo == true)
		cs << "Doblada" << '\t';
	else
		cs << "Subtitulada" << '\t';

	cs << "-- ";
	if (publico == true)
		cs << "Adultos" << '\t';
	else
		cs << "Ninos" << '\t';

	cs << "-- ";
	if (sala == 1)
		cs << "VIP" << '\t';
	else
		cs << "Regular" << '\t';

	cs << "-- ";
	if (dimension == true)
		cs << "3D" << '\t';
	else
		cs << "2D" << '\t';
	//--------------------------------

	return cs.str();

}

string Pelicula::imprimehorario() //metodo que ayuda imprimenCart y toString para saber el horario
{
	stringstream horario;

	string id = getID();

	switch (id.at(1))
	{
	case '0': horario << "Lunes | "; break;
	case '1': horario << "Martes | "; break;
	case '2': horario << "Miercoles | "; break;
	case '3': horario << "Jueves | "; break;
	case '4': horario << "Viernes | "; break;
	case '5': horario << "Sabado | "; break;
	case '6': horario << "Domingo | "; break;
	}

	switch (id.at(0))
	{
	case '0': horario << "7:00am - 9:00am"; break;
	case '1': horario << "3:00pm - 5:30pm"; break;
	case '2': horario << "6:00pm - 8:30pm"; break;
	}


	return horario.str();

}

int Pelicula::imprimeprecio() // ayuda de igual manera a los otros imprime para saber el precio
{
	int precio = 0;
	if (getPublico() == true)
		precio += 5000; //Adultos
	else
		precio += 3000; //Ninos

	if (getSala() == 1)
		precio += 1500; //El precio del VIP es de 1500, regular no tiene costo adicional

	return precio;
}
