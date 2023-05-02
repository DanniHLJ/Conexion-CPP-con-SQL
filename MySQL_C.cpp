// MySQL_C.cpp 
#include <mysql.h>
#include <iostream>
using namespace std;

int main() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "HLJDanni", "db_empresa", 3306, NULL, 0);
	cout << "Hellow World! Im Daniel,\nIm trying Visual Studio with SQL!"<<endl;
	if (conectar) {
		cout << "Conexion Exitosa..." << endl;

	}
	else {
		cout << "Error en la Conexion..." << endl;
	}
	system("Pause");
	return 0;
}
