#include "ContaInvestimento.h"

//Construtor e destrutor:
ContaInvestimento::ContaInvestimento()
{
}

ContaInvestimento::ContaInvestimento(string numAgencia, string numConta, string proprietario, float saldo, float limite, TipoInvest tipoInvest, float saldoInvestimento) 
: ContaCorrente(numAgencia, numConta, proprietario, saldo, limite), TipoInvestimento(tipoInvest, saldoInvestimento)
{
} 

ContaInvestimento::~ContaInvestimento()
{
}

//----------------------------------------------------------------------------------//

//M�todo para imprimir informa��es:
void ContaInvestimento::imprimirExtrato(){
	ContaCorrente::imprimirExtrato();
	cout << "Tipo Investimento: " << getNomeTipoInvest() << endl;
	cout << "Saldo Investimento: " << saldoInvestimento << endl;
}

/*
Note que essa classe n�o tem m�todos GET e SET, uma vez que ela � apenas uma conta comum
com as regras de neg�cio da suas classes m�es.
*/
