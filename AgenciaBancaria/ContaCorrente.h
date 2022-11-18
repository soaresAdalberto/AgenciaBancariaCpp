#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

//Classe filha ContaCorrente, recebendo os atributos da sua mãe e específicações: 
class ContaCorrente : public Conta
{
	private:
		float limite;	
		float saldo_limite;
	
	public:
		ContaCorrente();
		ContaCorrente(string numAgencia, string numConta, string proprietario, float saldo, float limite);
		~ContaCorrente();
		
		float getLimite();
		void setLimite(float limite);
		
		void imprimirExtrato();
		bool sacar(float valor);
		
	protected:
};

#endif
