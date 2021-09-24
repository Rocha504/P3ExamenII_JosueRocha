#include <iostream>
#include <fstream>
#include<vector>
#include "Stack.cpp"
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

void evaluarOperacion(vector <string> operacion){
	
	string tipo=operacion[0];
	string operador;
	if(tipo=="I"){
		Stack<int>* pila = new Stack<int>();
		int aux1,aux2;
		for(int i=0;i<operacion.size();i++){
			string copia=operacion[i];
			char copia2=copia[0];
			if((int)copia2>=97){	
				pila->push(stoi(operacion[i]));
				//imprimir pila
			}
			else{
				operador=operacion[i];
				aux1=pila->top();
				pila->pop();
				aux2=pila->top();
				pila->pop();
				
			}
		}
	}
}

int menu(){
	int op;
	cout<<"1-Leer archivo"<<endl;
	cout<<"2-Salir"<<endl;
	cin>>op;
	return op;
}