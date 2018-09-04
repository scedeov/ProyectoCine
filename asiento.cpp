/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "asiento.h"

Asiento::Asiento()
{
	asi = " ";
	//se crea un asiento
}

Asiento::~Asiento()
{
	//se elimina un asiento
}

string Asiento::getAsiento()
{
	return asi;
}

void Asiento::setAsiento(string unAsi)
{
	asi = unAsi;
}