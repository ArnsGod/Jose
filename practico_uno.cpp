#include <iostream>
#include <cctype>
#include <cstdlib> // Para la función system en sistemas UNIX
#include <unistd.h> // Para la función usleep en sistemas UNIX
using namespace std;
// variables globales
int n1, n2; 
char opcion;
double res_num;
string palabra_uno, palabra_dos;

void IngresoFrace()
{
	cout << "Ingrese la primera frase: " << endl;
	cin >> palabra_uno;
	cout << "Ingrese la segunda frase: " << endl;
	cin >> palabra_dos;
}

void concatenar()
{
	cout << "La concatenacion es: " + palabra_uno + " " + palabra_dos << endl;
}

void SubMenu()
{
	cout << "----------SUBMENU--------------" << endl;
	cout << "1) -- Suma de 2 numeros" << endl;
	cout << "2) -- Division de 2 numeros" << endl;
	cout << "(m/M) -- Volver al menu principal" << endl;
	cin >> opcion;
}

void sumar()
{
	res_num = n1 + n2;
	cout << "La suma total es: " << res_num << endl;
}

void divi()
{
	if (n2 != 0)
	{
		res_num = static_cast<double>(n1) / static_cast<double>(n2);
		cout << "La respuesta de la division es: " << res_num << endl;
	}
	else
	{
		cout << "!!!No es posible dividir entre 0!!!" << endl;
	}
}

void IngresoValores()
{
	cout << "Ingrese el primer valor: ";
	cin >> n1;
	cout << "Ingrese el segundo valor: ";
	cin >> n2;
}

void MenuPrincipal()
{
	cout << "----------MENU--------------" << endl;
	cout << "(1) -- Operacion con Nùmeros" << endl;
	cout << "(2) -- Concatenar 2 cadenas" << endl;
	cout << "(s/S) -- Salir" << endl;
	cin >> opcion;
}

int main(int argc, char *argv[])
{
	do
	{
		MenuPrincipal();
		opcion = tolower(opcion);
		switch (opcion)
		{
		case '1':
			do
			{
				SubMenu();
				switch (opcion)
				{
				case '1':
					IngresoValores();
					sumar();
					break;
				case '2':
					IngresoValores();
					divi();
					break;
				case 'm':
					cout << "Volviendo al Menú Principal" << endl;
					break;
				default:
					cout << "NO ES UNA OPCION VALIDA" << endl;
				}
			}while(opcion != 'm');
			break;
		case '2':
			IngresoFrace();
			concatenar();
			break;
		case 's':
			cout << "Saliendo" << endl;
			break;
		default:
			cout << "NO ES UNA OPCION VALIDA" << endl;
		}
		
	} while (opcion != 's');
	return 0;
}
