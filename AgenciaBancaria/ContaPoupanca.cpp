#include "ContaPoupanca.h"

//Construtor e destrutor:
ContaPoupanca::ContaPoupanca()
{
}

ContaPoupanca::ContaPoupanca(string numAgencia, string numConta, string proprietario, float saldo, MesAniversario mes) 
: Conta(numAgencia, numConta, proprietario, saldo)
{
	setMes(mes);
}

ContaPoupanca::~ContaPoupanca()
{
}

//----------------------------------------------------------------------------------//	

//M�todos GET:
MesAniversario ContaPoupanca::getMes(){
	return mes;
}

//----------------------------------------------------------------------------------//	

//M�todos SET e regras de neg�cio:
void ContaPoupanca::setMes(MesAniversario mes){
	this->mes = mes;
}

string ContaPoupanca::getNomeMes(){
	string nomeMes = "";
	
	switch(mes){
		case 1:
			nomeMes = "Janeiro";
			break; 
		case 2:
			nomeMes = "Fevereiro";
			break; 
		case 3:
			nomeMes = "Mar�o";
			break; 
		case 4:
			nomeMes = "Abril";
			break; 
		case 5:
			nomeMes = "Maio";
			break; 
		case 6:
			nomeMes = "Junho";
			break; 
		case 7:
			nomeMes = "Julho";
			break; 
		case 8:
			nomeMes = "Agosto";
			break; 
		case 9:
			nomeMes = "Setembro";
			break; 
		case 10:
			nomeMes = "Outubro";
			break; 
		case 11:
			nomeMes = "Novembro";
			break; 
		case 12:
			nomeMes = "Dezembro";
			break;			
	}
	
	return nomeMes;
}

//----------------------------------------------------------------------------------//	

//Imprimir as informa��es de extrato da conta poupan�a:		
void ContaPoupanca::imprimirExtrato(){
	Conta::imprimirExtrato();
	cout << "M�s anivers�rio: " << getNomeMes() << endl;
}
