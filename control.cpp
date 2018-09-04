/*	Version 1.0
27/09/16
Steven Cedeño V.
*/

#include "control.h"

Control::Control()
{
	c = new Cartelera();
	h = new Horario();
}

Control::~Control()
{}

void Control::Principal()
{
	bool end = false;

	while (end == false)
	{
		char ans;
		i.MenuPrincipal();
		cout << "\tBienvenido.\n" << endl;
		cout << "\tPor favor, selecione una de las opciones -> ";

		ans = _getch();

		cout << ans << endl;

		while (ans < '1' || ans > '4')
		{
			cout << "\tOpcion incorrecta, ingrese una opcion valida ";
			ans = _getch();
			cout << ans << endl;
		}

		switch (ans)
		{
		case '1':
		{
			system("cls");
			i.MenuCartelera();
			opcionCartelera();
			system("cls");
		} break;

		case '2':
		{
			if (c->cvacia() == true)
			{
				cout << endl << endl;
				cout << "No hay peliculas enlistadas en cartelera, favor contacte al administrador. ";
				pausa();
				system("cls");
				Principal();
			}
			system("cls");
			i.MenuComprar();
			opcionComprar();
			system("cls");

		} break;

		case '3':
		{
			pass();
			system("cls");
			i.MenuAdministrador();
			opcionAdmin();
			system("pause");
			system("cls");

		} break;

		case '4':
		{
			delete c;
			delete h;
			end = true;

		} break;
		}
	}
}

void Control::opcionAdmin()
{
	char ans;
	cout << endl << endl;
	cout << "Opcion -> ";
	ans = _getch();
	cout << ans << endl;
	if (ans == '4') return;

	while (ans < 'a' || ans > 'b')
	{
		cout << "\tOpcion incorrecta, ingrese una opcion valida ";
		ans = _getch();
		if (ans == '4') return;
		cout << ans << endl;

	}

	switch (ans)
	{
	case 'a':
	{
		ingPelicula();
		cout << c->toStringCart();
	}break;

	case 'b':
	{
		cout << c->toStringCart();
		if (c->cvacia() == true)
		{
			break;
		}
		else
			eliminaPelicula();
	}break;
	}
}

void Control::pass()  // un metodo simple para restringir el uso a solo administradores, hubiese querido que aparecieran asteriscos en vez de numeros pero ni idea como hacerlo
{
	string pass = "1234";
	string ans;
	cout << endl << endl;
	cout << "Ingrese la contrasena --> ";
	cin >> ans;
	while (ans != pass)
	{
		cin.clear();
		cout << "Contrasena incorrecta, favor intente de nuevo -- >" << endl;
		cin >> ans;
	}
}

void Control::ingPelicula()
{
	char ansP;
	do
	{
		Grupo_Salas *grupo = new Grupo_Salas();

		Sala *sala = new Sala();

		Pelicula *p = new Pelicula();

		cout << endl;
		cout << "Ingrese el nombre de la Pelicula -->  "; cin.ignore();
		string nomb; getline(cin, nomb); p->setNom(nomb);
		cout << "Ingrese el genero --> ";
		string gen; cin >> gen; p->setGen(gen);
		cout << "Ingrese una breve sipnosis --> "; cin.ignore();
		string sip; getline(cin, sip); p->setSip(sip);
		cout << "Ingrese el anno --> ";
		int anno; cin >> anno;
		while (cin.fail() || (anno < 1950 || anno > 2016))
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Opcion incorrecta, ingrese una opcion valida. ";
			cin >> anno;
		}
		p->setAnno(anno);

		cout << "Ingrese el pais --> "; cin.ignore();
		string pais; getline(cin, pais); p->setPais(pais); cout << endl;
		//------------------
		cout << "La pelicula se encuentra Doblada <1> o Subtitulada <2> ? --> ";
		int ans;
		ans = _getch() - 48;
		cout << ans << endl;
		while (ans > 3 || ans <= 0)
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			ans = _getch() - 48;
			cout << ans << endl;
		}
		p->CambiaTipo(ans);
		//-------------------------
		cout << "La pelicula es para Adultos <1> o para Ninos <2> --> ";
		ans = _getch() - 48;
		cout << ans << endl;

		while (ans > 3 || ans <= 0)
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			ans = _getch() - 48;
			cout << ans << endl;
		}
		p->CambiaPublico(ans);
		//------------------------
		cout << "La pelicula sera en 3D <1> o 2D <2> -->";
		ans = _getch() - 48;
		cout << ans << endl;
		while (ans > 3 || ans <= 0)
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			ans = _getch() - 48;
			cout << ans << endl;
		}
		p->CambiaDimension(ans);
		//--------------------------------
		cout << "La pelicula sera reproducida en la Sala VIP <1> o Regular <2>  ? --> ";
		ans = _getch() - 48;
		cout << ans << endl;

		while (ans > 3 || ans <= 0) // cambiar el rango en caso de mas salas y agregarlas a la descripcion
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			ans = _getch() - 48;
			cout << ans << endl;
		}
		p->setSala(ans);
		//--------------------
		cout << h->imprimeHorario();
		cout << "En que horario desea incluir la pelicula, digite la posicion deseada ? (ej. '00') --> ";

		string ansh; cin >> ansh;
		char X = ansh.at(0);
		char Y = ansh.at(1);
		cout << ansh << endl;

		while ((X < '0' || X > '3') || (Y < '0' || Y > '7')) // cambiar el rango en caso de mas salas y agregarlas a la descripcion
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			cin.clear();
			cin >> ansh;
			char X = ansh.at(0);
			char Y = ansh.at(1);
			cout << ansh << endl;
		}
		p->setID(c->generaID(ansh, ans));
		sala->setPelicula(p);
		grupo->setSala(ans, sala);
		h->setGrupoSalas(ansh, grupo);

		//--------------------
		if (c->insertarFinal(p) == true)
		{
			cout << "La pelicula ha sido anadida correctamente" << endl;

			cout << endl << endl;
		}
		else
		{
			cout << "Ha ocurrido un problema ingresando la pelicula al sistema." << endl;
			cout << endl << endl;
		}
		//-------------------------------
		cout << "Presiona la letra <Y> si desea ingresar una nueva pelicula, de lo contrario, presione la tecla <N> ";
		ansP = _getch();
		while (toupper(ansP) != 'N'  && toupper(ansP) != 'Y')
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			ansP = _getch();
		}
		//---------------------------
		if (toupper(ansP) == 'N')
			break;


	} while (toupper(ansP) == 'Y');
}
void Control::eliminaPelicula() //necesito implementar un metodo que limpie la sala de la matriz de horarios para uso posterior ** importante, si este comentario sigue aqui al ser entregado fue que no me dio tiempo o se me olvido
{
	string bye;
	cout << "Ingrese el ID de la pelicula que desea eliminar: ";
	cin >> bye;
	if (c->eliminaporID(bye) == true)
		cout << "La pelicula ha sido eliminada satisfactoriamente. " << endl;
	else
		cout << "No ha sido posible eliminar la pelicula seleccionada porque no ha sido encontrada o porque ha ocurrido un problema en el sistema. " << endl;
}

void Control::opcionCartelera()
{
	char ans;
	cout << endl << endl;
	cout << "Opcion ->";
	ans = _getch();
	cout << ans << endl;
	if (ans == '4') return;

	while (ans <'a' || ans > 'c')
	{
		cout << "Opcion incorrecta, ingrese una opcion valida. ";
		ans = _getch();
		cout << ans << endl;
		if (ans == '4') return;
	}

	switch (ans)
	{
	case 'a':
	{
		cout << c->toStringCart();
		pausa();
		system("cls");

	} break;

	case 'b':
	{
		system("cls");
		i.MenuFiltro();
		opcionBuscar();
		pausa();
		system("cls");

	}break;
	}

}
void Control::opcionBuscar()
{
	char ans;
	cout << endl << endl;
	cout << "Opcion ->";
	ans = _getch();
	cout << ans << endl;
	if (ans == '4') return;

	while (ans <'a' || ans > 'g')
	{
		cout << "Opcion incorrecta, ingrese una opcion valida. ";
		ans = _getch();
		cout << ans << endl;
		if (ans == '4') return;
	}

	switch (ans)
	{
	case 'a':
	{
		string a;
		cout << "Ingrese el genero de la pelicula a buscar (ejemplo 'comedia') sin comillas) ->>"; cin >> a;
		if (c->buscaGenero(a) == false)
			cout << "Lo sentimos, no existen peliculas con ese criterio. " << endl;
	}break;
	case 'b':
	{
		string b;
		cout << "Ingrese el nombre de la pelicula a buscar (ejemplo 'Transformers') sin comillas) ->>"; cin >> b;
		if (c->buscaNombre(b) == false)
			cout << "Lo sentimos, no existen peliculas con ese criterio. " << endl;
	}break;
	case 'c':
	{
		int cx;
		cout << "Desea buscar peliculas dobladas <1> o subtituladas <2> ? ->> "; cx = _getch() - 48;
		if (c->buscaTipo(cx) == false)
			cout << "Lo sentimos, no existen peliculas con ese criterio. " << endl;
	} break;
	case 'd':
	{
		int d;
		cout << "Desea buscar peliculas en 3D <1> o 2D <2> ? ->> "; d = _getch() - 48;
		if (c->buscaDimension(d) == false)
			cout << "Lo sentimos, no existen peliculas con ese criterio. " << endl;
	}break;
	case 'e':
	{
		int e;
		cout << "Desea buscar peliculas en Sala VIP <1> o Sala Regular <2> ? ->> "; e = _getch() - 48;
		if (c->buscaTipoSala(e) == false)
			cout << "Lo sentimos, no existen peliculas con ese criterio. " << endl;
	}break;
	case 'f':
	{
		int f;
		cout << "Desea buscar peliculas calificadas para Adultos <1> o para Ninos <2> ? ->> "; f = _getch() - 48;
		if (c->buscaPublico(f) == false)
			cout << "Lo sentimos, no existen peliculas con ese criterio. " << endl;
	} break;
	}
}

void Control::opcionComprar()
{
	char ans;
	cout << endl << endl;
	cout << "Opcion ->>";
	ans = _getch();
	cout << ans << endl;
	if (ans == '4') return;
	while (ans <'a' || ans > 'b')
	{
		cout << "Opcion incorrecta, ingrese una opcion valida. ";
		ans = _getch();
		cout << ans << endl;
		if (ans == '4') return;
	}

	switch (ans)
	{
	case 'a':
		individualmente(); break;
	case 'b':
		porFilas(); break;
	}
}

void Control::individualmente() //permite comprar tiquetes por asiento individual
{
	Tiquete *t = new Tiquete();
	cout << c->toStringCart();


	string codigo;
	cout << "Favor ingrese el codigo de la pelicula de la que desea comprar tiquetes ->> "; cin >> codigo;

	Sala* s = recuperaSalaporCodigo(codigo);
	char ans;
	string cadena;

	do
	{
	back:
		system("cls");
		s->toString();

		cout << "Digite el asiento deseado ";
		cin >> cadena;
		cout << endl;

		char X = toupper(cadena.at(0));
		int Y = stoi(cadena.substr(1, 1));
		cout << X << Y << endl;

		while ((X < 'A' || X > 'F') || (Y < 1 || Y > 10))
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			cin.clear();
			cin >> cadena;
			char X = toupper(cadena.at(0));
			int Y = stoi(cadena.substr(1));
			cout << X << Y << endl;
		}

		while (s->setPos(cadena) == false)
		{
			cout << "Asiento Ocupado, favor ingrese otro asiento -> ";
			cin.clear();
			cin >> cadena;
			s->setPos(cadena);
			cout << cadena << endl;

		}


		system("cls");
		s->toString();
		cout << "Esta seguro de su eleccion? Si <Y> o NO <N> ";
		ans = _getch();
		cout << ans << endl;
		while (toupper(ans) != 'N' && toupper(ans) != 'Y')
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			ans = _getch();
			cout << ans << endl;
		}

		if (toupper(ans) == 'N')
		{
			s->eliminaSeleccion();
			goto back;
		}
		else
			if (toupper(ans) == 'Y')
			{
				system("cls");
				s->CompraMomentaneaAsientos();
				s->toString();
				cout << "Desea comprar mas asientos? Si <Y> o NO <N> ";
				ans = _getch();
				cout << ans << endl;
				while (toupper(ans) != 'N' && toupper(ans) != 'Y')
				{
					cout << "Opcion incorrecta, digite una opcion valida --> ";
					ans = _getch();
					cout << ans << endl;
				}
			}

	} while (toupper(ans) == 'Y');

	system("cls");

	cout << t->imprimeTiquete(s->getPelicula(), s);

	s->CompraDefinitivaAsientos();
	cout << endl << endl;

	s->toString();
	pausa();

}

void Control::porFilas() //permite comprar varios asientos a la vez por filas
{
	Tiquete *t = new Tiquete();
	cout << c->toStringCart();


	string codigo;
	cout << "Favor ingrese el codigo de la pelicula de la que desea comprar tiquetes ->> "; cin >> codigo;

	Sala* s = recuperaSalaporCodigo(codigo);

	char elec;

	do
	{
	back:
		system("cls");
		s->toString();

		cout << "Cuantos asientos desea comprar? ";
		int asientos;
		cin >> asientos;
		cout << asientos << endl;
		while (cin.fail() || (asientos < 1 || asientos > 10))
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Opcion incorrecta, ingrese una opcion valida. ";
			cin >> asientos;
		}

		cout << endl << endl;

		cout << "En que Fila? ";
		char fila;
		fila = _getch();
		fila = tolower(fila);
		cout << fila << endl;
		cout << endl << endl;
		while (fila < 'a' || fila > 'f')
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			fila = _getch();
			fila = tolower(fila);
			cout << fila << endl;
		}

		if (s->revisaMatriz(fila, asientos) == true)
			s->seleccionaAsientos(fila, s->retornaPrimeraPos(fila), asientos);
		else
		{
			cout << "Lo sentimos, no hay " << asientos << " asientos disponibles en la fila " << fila << endl;
			cin.get();
		}

		system("cls");
		s->toString();

		cout << "Esta seguro de su eleccion? Si <Y> o NO <N> ";
		elec = _getch();
		while (toupper(elec) != 'N' && toupper(elec) != 'Y')
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			elec = _getch();
		}

		if (toupper(elec) == 'N')
		{
			s->eliminaSeleccion();
			goto back;
		}
		else
			if (toupper(elec) == 'Y')
			{
				system("cls");
				s->CompraMomentaneaAsientos();
				s->toString();
			}

		cout << "Desea comprar mas asientos? Si <Y> o NO <N> ";
		elec = _getch();
		while (toupper(elec) != 'N' && toupper(elec) != 'Y')
		{
			cout << "Opcion incorrecta, digite una opcion valida --> ";
			elec = _getch();
		}
	} while (toupper(elec) == 'Y');

	system("cls");

	cout << t->imprimeTiquete(s->getPelicula(), s);

	s->CompraDefinitivaAsientos();
	cout << endl << endl;

	s->toString();

	pausa();
}

void Control::pausa() // para evitar el uso de system implemente esta pausa, ya que lei que no es buena idea usar comandos exclusivos de consola
{
	cout << '\n' << "Presione cualquier tecla para continuar ";
	_getch();
} 

Sala* Control::recuperaSalaporCodigo(string codigo) // me devuelve la sala que le pertenece a una pelicula agregada a la lista
{
	string posicionMatriz = codigo.substr(0, 2);
	int posicionGrupoSala = stoi(codigo.substr(2, 1));

	Sala* salarecuperada = h->getGrupo(posicionMatriz)->getSala(posicionGrupoSala);

	return salarecuperada;

}



