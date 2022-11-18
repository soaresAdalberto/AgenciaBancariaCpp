#ifndef CONTA_H
#define CONTA_H

#include<iostream>

using namespace std;

//Classe mãe, onde tem os atributos em comum entre todas as classes:
class Conta
{
	private:
		string numAgencia;
		string numConta;
		string proprietario;
		char aux;
	
	public:
		Conta();
		Conta(string numAgencia, string numConta, string proprietario, float saldo);
		~Conta();
		
		string getNumAgencia();
		string getNumConta();
		string getProprietario();
		float getSaldo();
		
		void setNumAgencia(string numAgencia);
		void setNumConta(string numConta);
		void setProprietario(string proprietario);
		void setSaldo(float saldo);
		
		//Virtual é um método polifórmico:
		virtual bool sacar(float valor);
		bool depositar(float valor);
		virtual	void imprimirExtrato();
		
	//Pode ser acessado no escopo da classe filha:
	protected:
		float saldo;
};

#endif
