// Efraín Girón Romero 15300102 5G1
#include "stdafx.h"
#include <iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo *sig, *ant;
}*inicio, *aux, *aux2, *nodo, *Encabezado;

void inicializar();
void imprime();
void limpia();
bool vacia();
bool buscar(int dato);
void insertar(int dato);
void eliminar(int dato);

int main()
{
	int R = 0;
	inicializar();
	do
	{
		int r;
		system("cls");
		cout << "                    Lista Circular Doblemente Enlazada                    " << endl;
		cout << "¿Que accion decea realizar?\nSeleccione el numero\n1: Ingresar dato\n2: Eliminar dato\n3: Mostrar todos los datos\n4: Eliminar todos los datos\n5: Salir" << endl;
		cin >> r;
		system("cls");
		switch (r)
		{
		case 1: //insertar()
			cout << "                    Lista Circular Doblemente Enlazada                    " << endl;
			cout << "Ingresa el numero a la lista" << endl;
			int x;
			cin >> x;
			insertar(x);
			system("cls");
			break;
		case 2: //eliminar()
			cout << "                    Lista Circular Doblemente Enlazada                    " << endl;
			cout << "Ingresa el numero que decea eliminar de la lista" << endl;
			int y;
			cin >> y;
			eliminar(y);
			system("cls");
			break;
		case 3: //imprime()
			cout << "                    Lista Circular Doblemente Enlazada                    " << endl;
			imprime();
			system("cls");
			break;
		case 4: //limpia()
			cout << "                    Lista Circular Doblemente Enlazada                    " << endl;
			limpia();
			system("cls");
			break;
		case 5: //Salir
			R = 1;
			break;
		}
	} while (R != 1);
	return 0;
}

void inicializar()
{
	Encabezado = new Nodo;
	Encabezado->dato = NULL;
	Encabezado->sig = Encabezado;
	Encabezado->ant = Encabezado;
}

bool vacia()
{
	if (Encabezado->sig == Encabezado)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

void insertar(int dato)
{
	nodo = new Nodo;
	nodo->dato = dato;
	nodo->sig = NULL;
	nodo->ant = NULL;
	if (vacia())
	{
		inicio = nodo;
		inicio->sig = Encabezado;
		inicio->ant = Encabezado;
		Encabezado->sig = inicio;
		Encabezado->ant = inicio;
	}
	else
	{
		if (buscar(dato))
		{
			cout << "El dato ya existe en la lista\nNo se pueden repetir los datos" << endl;
		}
		else
		{
			if (dato < inicio->dato)
			{
				Encabezado->sig = nodo;
				nodo->ant = Encabezado;
				nodo->sig = inicio;
				inicio->ant = nodo;
				inicio = nodo;
			}
			else
			{
				bool exit = true;
				aux = inicio;
				while (exit == true)
				{
					if (nodo->dato < aux->sig->dato || aux == Encabezado->ant)
					{
						nodo->sig = aux->sig;
						aux->sig->ant = nodo;
						aux->sig = nodo;
						nodo->ant = aux;
						exit = false;
					}
					else
					{
						aux = aux->sig;
					}
				}
			}
		}
	}
	system("Pause");
}

void eliminar(int dato)
{
	if (vacia())
	{
		cout << "La lista ya esta vacia" << endl;
	}
	else
	{
		if (!buscar(dato))
		{
			cout << "El elemento que decea eliminar no esta en la lista" << endl;
		}
		else
		{
			if (dato == inicio->dato)
			{
				if (inicio->sig == Encabezado && inicio->ant == Encabezado)
				{
					delete inicio;
					inicializar();
				}
				else
				{
					aux = inicio->sig;
					delete inicio;
					Encabezado->sig = aux;
					aux->ant = Encabezado;
					inicio = aux;
				}
			}
			else
			{
				bool exit = true;
				aux = inicio;
				while (exit == true)
				{
					if (aux->sig->dato == dato)
					{
						aux2 = aux->sig;
						aux->sig = aux2->sig;
						aux2->sig->ant = aux;
						delete aux2;
						exit = false;
					}
					else
					{
						aux = aux->sig;
					}
				}
			}
		}
	}
	system("Pause");
}

void imprime()
{
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		aux = inicio;
		do
		{
			cout << aux->dato << " - ";
			aux = aux->sig;
		} while (aux != Encabezado);
		cout << endl;
	}
	system("Pause");
}

void limpia()
{
	if (vacia())
	{
		cout << "La lista ya se encuentra vacia" << endl;
	}
	else
	{
		bool exit = true;
		aux = Encabezado;
		while (exit)
		{
			if (aux->sig == Encabezado)
			{
				exit = false;
			}
			else
			{

				inicio = aux->sig;
				aux->sig = inicio->sig;
				delete inicio;
			}
		}
	}
}

bool buscar(int dato)
{
	if (vacia())
	{
		return(false);
	}
	else
	{
		aux = inicio;
		do
		{
			if (aux->dato == dato)
			{
				return(true);
			}
			else
			{
				aux = aux->sig;
			}
		} while (aux != Encabezado);
		if (aux == Encabezado)
		{
			return(false);
		}
	}
}

