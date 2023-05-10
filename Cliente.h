#pragma once
#include <mysql.h>
#include "Persona.h"
#include <iostream>
#include "ConexcionBD.h"
#include <string>

using namespace std;
class Cliente : Persona{
private:string nit;
public:
	Cliente()
	{
	}
	Cliente(string nom, string ape, string dire, int tel, string fn, string n) : Persona(nom, ape, dire, tel, fn)
	{
		nit = n;
	}
	//set (modificar el atributo)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setDireccion(string dire) { direccion = dire; }
	void setTelefono(int tel) { telefono = tel; }
	void setApellidos(string ape) { apellidos = ape; }
	void setFechaN(string fn) { fecha_nacimiento = fn; }

	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFechaN() { return fecha_nacimiento; }
	//metodo
	void crear() {
		int q_estado;
		ConexcionBD cn = ConexcionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			
			string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES ('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "');";

			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;

			}
			else {
				cout << "xxx Error al Ingresar xxx" << endl;
			}
		} else {
			cout << "Error en la Conexión..." << endl;

		}
		cn.cerrar_conexion();

	}

	void leer() {
		int q_estado;
		ConexcionBD cn = ConexcionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from Clientes;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());
				cout << "--------------Clientes--------------"<<endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}

			}
			else {
				cout << "xxx Error al Consultar xxx" << endl;
			}
		}
		else {
			cout << "Error en la Conexión..." << endl;
		
		}
		cn.cerrar_conexion();

	}
		


	



};

