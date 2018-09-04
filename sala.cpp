/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "sala.h"


Sala::Sala()
{

	for (char x = 'A'; x < fila; x++)
		for (int y = 1; y < columna; y++)
			asientos[x][y] = *(new Asiento());
}

Sala::~Sala() 
{

}

bool Sala::setPos(string cadena)
{
	char unFil = toupper(cadena.at(0));
	int unCol = stoi(cadena.substr(1, 1));

	if (asientos[unFil][unCol].getAsiento() == "RC" || asientos[unFil][unCol].getAsiento() == "OO")
		return false;
	else
	{
		asientos[unFil][unCol].setAsiento("XX");
		return true;
	}

}

void Sala::setPelicula(Pelicula* unPelicula)
{
	p = unPelicula;
}

Pelicula * Sala::getPelicula()
{
	return p;
}

Asiento Sala::getPos(string cadena)
{
	char unFil = toupper(cadena.at(0));
	int unCol = stoi(cadena.substr(1, 1));

	return asientos[unFil][unCol];
}

void Sala::toString() // imprime una sala de cine en donde, los asientos disponibles son rojos, los seleccionados en el momentos son grises y los que son confirmados en el momento son como azules
{

	for (char x = 'A'; x < fila; x++)
	{

		cout << endl;
		cout << "| |";
		for (int y = 1; y < columna; y++)
		{
			if (asientos[x][y].getAsiento() == " ")
			{

				if (y == columna - 1)
				{
					cambiaColor(GREEN);
					cout << x << y;
					cambiaColor(WHITE);
					cout << "| |";
				}
				else
					if (y == columna / 2)
					{
						cambiaColor(GREEN);
						cout << x << y;
						cambiaColor(WHITE);
						cout << "| |";
					}
					else
					{
						cambiaColor(GREEN);
						cout << x << y;
						cambiaColor(WHITE);
						cout << "|";
					}
			}
			else
			{
				if (asientos[x][y].getAsiento() == "XX")
				{
					if (y == columna - 1)
					{
						cambiaColor(DARKGRAY);
						cout << x << y;
						cambiaColor(WHITE);
						cout << "| |";
					}
					else
						if (y == columna / 2)
						{
							cambiaColor(DARKGRAY);
							cout << x << y;
							cambiaColor(WHITE);
							cout << "| |";
						}
						else
						{
							cambiaColor(DARKGRAY);
							cout << x << y;
							cambiaColor(WHITE);
							cout << "|";
						}
				}
				else
					if (asientos[x][y].getAsiento() == "RC")
					{
						if (y == columna - 1)
						{
							cambiaColor(DARKTEAL);
							cout << x << y;
							cambiaColor(WHITE);
							cout << "| |";
						}
						else
							if (y == columna / 2)
							{
								cambiaColor(DARKTEAL);
								cout << x << y;
								cambiaColor(WHITE);
								cout << "| |";
							}
							else
							{
								cambiaColor(DARKTEAL);
								cout << x << y;
								cambiaColor(WHITE);
								cout << "|";
							}
					}
					else
						if (asientos[x][y].getAsiento() == "OO")
						{
							if (y == columna - 1)
							{
								cambiaColor(RED);
								cout << x << y;
								cambiaColor(WHITE);
								cout << "| |";
							}
							else
								if (y == columna / 2)
								{
									cambiaColor(RED);
									cout << x << y;
									cambiaColor(WHITE);
									cout << "| |";
								}
								else
								{
									cambiaColor(RED);
									cout << x << y;
									cambiaColor(WHITE);
									cout << "|";
								}
						}
			}
		}
		cout << endl;

	}
	cout << endl;
	cout << endl;
	// me salio grande el metodo, pero no se compara a la alegria de cuando me funciono lol
}


void Sala::eliminaSeleccion()
{
	for (char x = 'A'; x < fila; x++)
		for (int y = 1; y < columna; y++)
			if (asientos[x][y].getAsiento() == "XX")
			{
				/*delete asientos[x][y];*/
				asientos[x][y] = *(new Asiento());
			}
}

void Sala::CompraMomentaneaAsientos() //convierte un asiento seleccionado por un recien comprado = RC
{
	for (char x = 'A'; x < fila; x++)
		for (int y = 1; y < columna; y++)
			if (asientos[x][y].getAsiento() == "XX")
				asientos[x][y].setAsiento("RC");
}
void Sala::CompraDefinitivaAsientos() // convierte un asiento recien comprado como ocupado
{
	for (char x = 'A'; x < fila; x++)
		for (int y = 1; y < columna; y++)
			if (asientos[x][y].getAsiento() == "RC")
				asientos[x][y].setAsiento("OO");
}

bool Sala::revisaMatriz(char unFil, int num)
{
	char unFila = toupper(unFil);
	int cont = 0;
	for (int y = 1; y < columna; y++)
	{
		if (asientos[unFila][y].getAsiento() == " ")
			cont++;
		else
			cont = 0;
	}
	if (cont >= num)
		return true;
	else
		return false;
}

int Sala::retornaPrimeraPos(char unFil)
{
	char unFila = toupper(unFil);
	int pos = 0;
	for (int y = 1; y < columna; y++)
		if (asientos[unFila][y].getAsiento() == " ")
		{
			pos = y;
			return pos;
		}
	return 0;
}

void Sala::seleccionaAsientos(char fil, int pos, int num)
{
	char unFila = toupper(fil);
	int cont = 0;
	do
	{
		asientos[unFila][pos].setAsiento("XX");
		cont++;
		pos++;
	} while (cont < num);
}

int Sala::cuentaAsientos() // cuenta cuantos asientos fueron comprados para referencia en los tiquetes
{
	int cont = 0;
	for (char x = 'A'; x < fila; x++)
		for (int y = 1; y < columna; y++)
			if (asientos[x][y].getAsiento() == "RC")
				cont++;
	return cont;
}

void Sala::cambiaColor(Color c) // tan simple y tan complejo
{
	HANDLE hCon;
	hCon = NULL;
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}

string Sala::imprimeAsientosComprados() // imprime los asientos comprados en el tiquete al finalizar
{
	stringstream s;

	for (char x = 'A'; x < fila; x++)
		for (int y = 0; y < columna; y++)
		{
			if (asientos[x][y].getAsiento() == "RC")
				s << x << y << " ";
		}
	return s.str();
}
