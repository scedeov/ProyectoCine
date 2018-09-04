/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "tiquete.h"

int Tiquete::precioTiquete(Pelicula* obj)
{
	int precio = 0;
	if (obj->getPublico() == true)
		precio += 5000; //Adultos
	else
		precio += 3000; //Ninos

	if (obj->getSala() == 1)
		precio += 1500; //El precio del VIP es de 1500, regular no tiene costo adicional

	return precio;
}

int Tiquete::precioTotal(Pelicula* p, Sala* s) //recibe el precio de uno, y una sala para saber cuantos tiquetes se compraron
{
	int ptotal = 0; int canTiq = s->cuentaAsientos();
	int unTiq = precioTiquete(p);
	ptotal = unTiq*canTiq;
	return ptotal;
}

int Tiquete::codigoTiquete() // un codigo a un tiquete, que quiza sea util para reclamos 
{
	srand((unsigned)time(0));
	int cod = rand() % 1000;
	return cod;
}

string Tiquete::imprimeTiquete(Pelicula*  p, Sala* unS)
{
	stringstream s1;

	s1 << " ************" << endl;
	s1 << "*" << " Tiquete # " << codigoTiquete() << endl;
	s1 << "*" << " Pelicula " << p->getNom() << endl;
	s1 << "*" << " Horario " << p->imprimehorario() << endl;
	s1 << "*" << " Asientos " << unS->imprimeAsientosComprados() << endl;
	s1 << "*" << " Total a Pagar: " << precioTotal(p, unS) << endl;
	s1 << " ************" << endl;
	s1 << endl << endl;
	return s1.str();
}


