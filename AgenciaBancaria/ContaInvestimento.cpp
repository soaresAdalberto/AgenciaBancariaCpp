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

//Método para imprimir informações:
void ContaInvestimento::imprimirExtrato(){
	ContaCorrente::imprimirExtrato();
	cout << "Tipo Investimento: " << getNomeTipoInvest() << endl;
	cout << "Saldo Investimento: " << saldoInvestimento << endl;
}

/*
Note que essa classe não tem métodos GET e SET, uma vez que ela é apenas uma conta comum
com as regras de negócio da suas classes mães.
*/
