#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

//Cada número se refere a um mês, recurso do enum:
enum MesAniversario{
	JANEIRO = 1,
	FEVEREIRO = 2,
	MARCO = 3,
	ABRIL = 4,
	MAIO = 5,
	JUNHO = 6,
	JULHO = 7,
	AGOSTO = 8,
	SETEMBRO = 9,
	OUTUBRO = 10,
	NOVEMBRO = 11,
	DEZEMBRO = 12
};

//----------------------------------------------------------------------------------//	

//Classe ContaPoupança com os atributos de sua mãe e os seus específicos:
class ContaPoupanca : public Conta
{
	private:
		MesAniversario mes;
		string getNomeMes();
		
	public:
		ContaPoupanca();
		ContaPoupanca(string numAgencia, string numConta, string proprietario, float saldo, MesAniversario mes);
		~ContaPoupanca();
		
		MesAniversario getMes();
		void setMes(MesAniversario mes);
		
		void imprimirExtrato();
		
	protected:
};

#endif
