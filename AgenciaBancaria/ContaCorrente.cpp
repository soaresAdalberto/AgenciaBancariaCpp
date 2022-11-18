#include "ContaCorrente.h"

//Construtor e destrutor:
ContaCorrente::ContaCorrente()
{
}

ContaCorrente::~ContaCorrente()
{
}

//Construtor sobrecarregado de ContaCorrente chamando os SET do construtor sobrecarregado Conta:
ContaCorrente::ContaCorrente(string numAgencia, string numConta, string proprietario, float saldo, float limite) 
: Conta(numAgencia, numConta, proprietario, saldo)
{
	setLimite(limite);
}

//----------------------------------------------------------------------------------//	

//Método GET:
float ContaCorrente::getLimite(){
	return limite;
}

//----------------------------------------------------------------------------------//	

//Método SET:
void ContaCorrente::setLimite(float limite){
	this->limite = (limite >= 0) ? limite : 0;
}

//----------------------------------------------------------------------------------//	

//Método para saque em contas corrente: cheque especial.
bool ContaCorrente::sacar(float valor) {
	if((saldo + limite) >= valor && (valor > 0)){
		saldo -= valor;
		return true;
	} else {
		return false;
	}
}
	
//Imprimir as informações específicas da conta corrente:
void ContaCorrente::imprimirExtrato(){
	Conta::imprimirExtrato();
	cout << "Limite total: " << limite << endl;
	
	if (saldo >= 0) {
		cout << "Limite para uso: " << limite << endl;
	} else {
		cout << "Limite para uso: " << limite + saldo << endl;
	}
	
}
