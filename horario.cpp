/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "horario.h"

Horario::Horario()
{
	h = new Grupo_Salas**[funciones];
	for (int x = 0; x < funciones; x++)
	{
		h[x] = new Grupo_Salas*[dias];
	}

	for (int x = 0; x < funciones; x++)
	{
		for (int y = 0; y < dias; y++)
		{
			h[x][y] = new Grupo_Salas();
		}
	}
}

void Horario::setGrupoSalas(string pos, Grupo_Salas* ungrupo)
{
	int unfun = stoi(pos.substr(0, 1));
	int undia = stoi(pos.substr(1, 1));

	h[unfun][undia] = ungrupo;
}

string Horario::imprimeHorario()
{
	stringstream s;
	for (int x = 0; x < funciones; x++)
	{
		for (int y = 0; y < dias; y++)
		{
			if (y == 0)
			{
				s << funhorario(x) << diahorario(y) << x << y << "| ";
			}
			else
				s << diahorario(y) << x << y << "|";
		}
		s << endl;
	}
	return s.str();
}

Grupo_Salas * Horario::getGrupo(string pos)
{
	int unfun = stoi(pos.substr(0, 1));
	int undia = stoi(pos.substr(1, 1));

	return h[unfun][undia];
}

string Horario::funhorario(int fun) //a la hora de escojer un lugar en la matriz, en administrador, este metodo permite ver el horario
{
	stringstream horario;

	switch (fun)
	{
	case 0: horario << "7am - 9am "; break;
	case 1: horario << "3pm - 5pm "; break;
	case 2: horario << "7pm - 9pm "; break;
	}


	return horario.str();

}
string Horario::diahorario(int dia) //a la hora de escojer un lugar en la matriz, en administrador, este metodo permite ver el horario, era solo uno pero lo separe para que se viera mejor en consola
{
	stringstream horario;

	switch (dia)
	{
	case 0: horario << "L > "; break;
	case 1: horario << "K > "; break;
	case 2: horario << "M > "; break;
	case 3: horario << "J > "; break;
	case 4: horario << "V > "; break;
	case 5: horario << "S > "; break;
	case 6: horario << "D > "; break;
	}

	return horario.str();

}





Horario::~Horario()
{
	for (int x = 0; x < funciones; x++)
	{
		for (int y = 0; y < dias; y++)
		{
			delete h[x][y];
		}
	}

	for (int x = 0; x < funciones; x++)
	{
		delete[] h[x];
	}

	delete[] h;
}




