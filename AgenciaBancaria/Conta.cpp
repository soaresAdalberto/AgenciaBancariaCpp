#include "Conta.h"

//Construtores e destrutor: o segundo construtor polimorfista j� seta as vari�veis.
Conta::Conta()
{
}

Conta::Conta(string numAgencia, string numConta, string proprietario, float saldo) 
{
	setNumAgencia(numAgencia);
	setNumConta(numConta);
	setProprietario(proprietario);
	setSaldo(saldo);
}

Conta::~Conta()
{
}

//----------------------------------------------------------------------------------//	

//M�todos GET:
string Conta::getNumAgencia(){
	return numAgencia;
}

string Conta::getNumConta(){
	return numConta;
}

string Conta::getProprietario(){
	return proprietario;
}

float Conta::getSaldo(){
	return saldo;
}

//----------------------------------------------------------------------------------//	

//M�todos SET:
void Conta::setNumAgencia(string numAgencia){
	this->numAgencia = numAgencia;
}

void Conta::setNumConta(string numConta){
	this->numConta = numConta;
}

void Conta::setProprietario(string proprietario){
	this->proprietario = proprietario;
}

void Conta::setSaldo(float saldo){
	this->saldo = (saldo >= 0) ? saldo : 0;
}

bool Conta::sacar(float valor){
	if(saldo >= valor && valor > 0){
		saldo = saldo - valor;
		return true;
	}else{
		return false;
	}
}

bool Conta::depositar(float valor){
	
	if(valor > 0){
		saldo = saldo + valor;
		return true;
	}else{
		return false;
	}
}

//----------------------------------------------------------------------------------//	

//M�todo para imprimir o extrato das contas:
void Conta::imprimirExtrato(){
	
	cout << "Ag�ncia: " << numAgencia << endl;
	cout << "Conta: " << numConta << endl;
	cout << "Propriet�rio: " << proprietario << endl;
	cout << "Saldo: " << saldo << endl;
	
}
