#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class ConexcionBD
{
private: MYSQL* conectar;
public:void abrir_conexion(){
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "HLJDanni", "db_empresa", 3306, NULL, 0);

}
	  MYSQL* getConectar() {
		  return conectar;
	  }
	  void cerrar_conexion() {
		  mysql_close(conectar);
	  }
	 
};

