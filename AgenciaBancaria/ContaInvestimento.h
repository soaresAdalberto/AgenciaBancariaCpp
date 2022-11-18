#ifndef CONTAINVESTIMENTO_H
#define CONTAINVESTIMENTO_H

#include "ContaCorrente.h"
#include "TipoInvestimento.h"

//ContaInvestimento tendo herança multipla: duas classes mães.
class ContaInvestimento : public ContaCorrente, public TipoInvestimento
{
	public:
		ContaInvestimento();
		ContaInvestimento(string numAgencia, string numConta, string proprietario, float saldo, float limite, TipoInvest tipoInvest, float saldoInvestimento);
		~ContaInvestimento();
		
		void imprimirExtrato();
		
	protected:
};

#endif
