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
			vector<vector<string>> operaciones=leerArchivo("Prueba.txt");
			for(int i=0;i<operaciones.size();i++){
				evaluarOperacion(operaciones[i]);
				cout<<"----------------------------------------"<<endl;
			}
			
		}
	}
	return 0;
}

vector<vector<string>> leerArchivo(string nombreA){
	
	string linea;
	vector<vector<string>> operaciones;
	ifstream archivo;
	archivo.open(nombreA.c_str(),ios::in);
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
	if(tipo=="I"){//Tipo int
		Stack<int>* pila = new Stack<int>();
		int aux1,aux2,resultado;
		for(int i=0;i<operacion.size();i++){
			string copia=operacion[i];
			char copia2=copia[0];
			if(isdigit(copia2)){	
				pila->push(stoi(operacion[i]));
				//imprimir pila
			}
			else{
				operador=operacion[i];
				aux1=pila->top();
				pila->pop();
				aux2=pila->top();
				pila->pop();
				if(operador=="+"){
					resultado=aux1+aux2;
					pila->push(resultado);
					pila->print();
				}
				else
					if(operador=="-"){
						resultado=aux1-aux2;
						pila->push(resultado);
						pila->print();
					}
				else
					if(operador=="/"){
						resultado=aux1/aux2;
						pila->push(resultado);
						pila->print();
					}
				else
					if(operador=="*"){
						resultado=aux1*aux2;
						pila->push(resultado);
						pila->print();
					}
			}
		}
	}
	else
		if(tipo=="F"){//Tipo Float
			Stack<float>* pila = new Stack<float>();
			float aux1,aux2,resultado;
			for(int i=0;i<operacion.size();i++){
				string copia=operacion[i];
				char copia2=copia[0];
				if(isdigit(copia2)){	
					pila->push(stoi(operacion[i]));
					pila->print();
				}
				else{
					operador=operacion[i];
					aux1=pila->top();
					pila->pop();
					aux2=pila->top();
					pila->pop();
					if(operador=="+"){
						resultado=aux1+aux2;
						pila->push(resultado);
						pila->print();
					}
					else
						if(operador=="-"){
							resultado=aux1-aux2;
							pila->push(resultado);
							pila->print();
						}
					else
						if(operador=="/"){
							resultado=aux1/aux2;
							pila->push(resultado);
							pila->print();
						}
					else
						if(operador=="*"){
							resultado=aux1*aux2;
							pila->push(resultado);
							pila->print();
						}
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