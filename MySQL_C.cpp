// MySQL_C.cpp 

#include <iostream>
#include "Cliente.h"
using namespace std;



int main() {
	
	
		//cout << "Conexion Exitosa..." << endl;
		
	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;
	cout << "Ingrese nit:";
	getline(cin, nit);
	cout << "Ingrese nombres:";
	getline(cin, nombres);
	cout << "Ingrese apellidos:";
	getline(cin, apellidos);
	cout << "Ingrese direccion:";
	getline(cin, direccion);
	cout << "Ingrese telefono:";
		cin >> telefono;
		cin.ignore();
		cout << "Ingrese fecha nacimiento:";
		cin >> fecha_nacimiento;

	Cliente c = Cliente(nombres,apellidos,direccion,telefono,fecha_nacimiento,nit);
	c.crear();
	c.leer();
	system("Pause");
	return 0;
}
