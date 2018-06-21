#include <iostream>
#include <cstdlib>
#include "lista.h"
#include <string>
using namespace std;

//Função de dispersão a ser utilizada
int funcaoDisp(string str, int d){
	int sum =0;
	for(int i=0; str[i]!='\0'; i++){

		sum+=str[i];
	}
	return sum % d;
}


int main(){

	LinkedList<string> tabela[53];
	//primeiros nos somente informativo
	for(int i=0; i < 53; i++){

		tabela[i].PushBack("Posição >" +to_string(i+1)+  "<");
	}
	cout << endl;
	
	//tratar entradas
	string str;
	int ind=0;
	while(cin  >> str){
		ind = funcaoDisp(str,53);
		tabela[ind].PushBack(str);
	}
	

	std::cout << "==========================" << std::endl;
	//imprimir 
	for(int i=0; i < 53; i++){
		
		tabela[i].Print();
	}
	std::cout << "==========================" << std::endl;
	//imprimir repetidos
	for(int i=0; i < 53; i++){
		
		tabela[i].PrintRepetidos();
	}
}