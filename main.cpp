#include <iostream>
#include <fstream>
#include<vector>
#include "Stack.h"
#include <cstring>
#include<sstream>
using namespace std;
 

vector<string> tokenizer(string);
void evaluarOperacion(vector <string>);
int menu();
vector<vector<string>> leerArchivo(string);

int main(int argc, char** argv) {
	 
	int op;
	op=menu();
	while(op!=2){
		if(op==1){
			 
		}
	}
	return 0;
}

vector<vector<string>> leerArchivo(string nombreA){
	
	string linea;
	vector<vector<string>> operaciones;
	 
	ifstream archivo;
	string nombreArchivo;
	cout<<"Cual es el nombre de el archivo que desea leer?(Porfavor incluir la extencion .txt)"<<endl;
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);
	while(!archivo.eof()){
		getline(archivo,linea);
		operaciones.push_back(tokenizer(linea));
	}
	return operaciones;
}

vector<string> tokenizer(string linea){
	
	string aux;
	vector<string> operacion;
	stringstream check(linea);
	while(getline(check,aux, ',')){
    	operacion.push_back(aux);
	}
	return operacion;
	
}

void evaluarOperacion(vector <string>){
	
}

int menu(){
	int op;
	cout<<"1-Leer archivo"<<endl;
	cout<<"2-Salir"<<endl;
	cin>>op;
	return op;
}