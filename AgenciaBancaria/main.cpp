#include <iostream>
#include <locale>

//Incluindo as classes que criei:
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "ContaInvestimento.h"

//----------------------------------------------------------------------------------//	

//Fun��o para introduzir o polimorfismo:
void poliCadastrarConta(Conta *conta)
{
	cout << "Entre com a ag�ncia da conta:" << endl;
	string numAgencia;
	getline(cin, numAgencia);
	cin.clear();
	fflush(stdin);
	conta->setNumAgencia(numAgencia);
	
	cout << "Entre com o n�mero da conta:" << endl;
	string numConta;
	getline(cin, numConta);
	cin.clear();
	fflush(stdin);
	conta->setNumConta(numConta);
	
	cout << "Entre com o propriet�rio da conta:" << endl;
	string proprietario;
	getline(cin, proprietario);
	conta->setProprietario(proprietario);
	cin.clear();
	fflush(stdin);
	
	cout << "Entre com o saldo da conta:" << endl;
	float saldo;
	cin >> saldo;
	cin.clear();
	fflush(stdin);
	conta->setSaldo(saldo);
	
	system("cls");
}

//----------------------------------------------------------------------------------//	

//Fun��o polim�rfica para utilizar o recurso especial de conta poupan�a: m�s anivers�rio.
void poliCadastrarContaPoupanca(ContaPoupanca *conta)
{
	poliCadastrarConta(conta);
	
	int op;
	
	MesAniversario mes;
	
	do {
		cout << "Entre com o m�s anivers�rio da conta:" << endl << endl;
		cout << "[1]  Janeiro" << endl;
		cout << "[2]  Fevereiro" << endl;
		cout << "[3]  Mar�o" << endl;
		cout << "[4]  Abril" << endl;
		cout << "[5]  Maio" << endl;
		cout << "[6]  Junho" << endl;
		cout << "[7]  Julho" << endl;
		cout << "[8]  Agosto" << endl;
		cout << "[9]  Setembro" << endl;
		cout << "[10] Outubro" << endl;
		cout << "[11] Novembro" << endl;
		cout << "[12] Dezembro" << endl;
		cin >> op;
		cin.clear();
		fflush(stdin);
				
		switch(op) {
			case 1:
				mes = JANEIRO;
				break;
			
			case 2:
				mes = FEVEREIRO;
				break;
			
			case 3:
				mes = MARCO;
				break;
			
			case 4:
				mes = ABRIL;
				break;
			
			case 5:
				mes = MAIO;
				break;
			
			case 6:
				mes = JUNHO;
				break;
			
			case 7:
				mes = JULHO;
				break;
			
			case 8:
				mes = AGOSTO;
				break;
			
			case 9:
				mes = SETEMBRO;
				break;
				
			case 10:
				mes = OUTUBRO;
				break;
				
			case 11:
				mes = NOVEMBRO;
				break;
				
			case 12:
				mes = DEZEMBRO;
				break;
				
			default:
				cout << "Esse m�s n�o existe!" << endl;
				break;
		}
		
	} while (op < 1 || op > 12);	
	
	conta->setMes(mes);
	
	system("cls");

}

//----------------------------------------------------------------------------------//	

//Fun��o polim�rfica para utilizar o recurso especial de conta corrente: limite.
void poliCadastrarContaCorrente(ContaCorrente * conta)
{
	poliCadastrarConta(conta);
	
	cout << "Entre com o limite da conta:" << endl;
	float limite;
	cin >> limite;
	cin.clear();
	fflush(stdin);
	conta->setLimite(limite);
	
	system("cls");
}

//----------------------------------------------------------------------------------//	

//Fun��o polim�rfica para utilizar os recursos especiais de conta investimento: tipoInvest e saldoInvestimento.
void poliCadastrarContaInvestimento(ContaInvestimento *conta)
{
	poliCadastrarContaCorrente(conta);
	
	int op;
	
	TipoInvest tipo;
	
	do {
	cout << "Entre com a op��o de investimento:" << endl << endl;
		cout << "[1]  CDB" << endl;
		cout << "[2]  Tesouro direto" << endl;
		cout << "[3]  Fundo de a��es" << endl;
		cout << "[4]  Fundo imobili�rio" << endl;
		cin >> op;
		
	switch(op) {
			case 1:
				tipo = CDB;
				break;
			
			case 2:
				tipo = TESOURO;
				break;
			
			case 3:
				tipo = ACAO;
				break;
			
			case 4:
				tipo = IMOBILIARIO;
				break;
			
			default:
				cout << "Op��o inv�lida." << endl;
				break;
			}
		
	} while (op < 1 || op > 4);
	conta->setTipoInvest(tipo);
	
	cout << "Entre com o saldo do investimento" << endl;
	float saldo;
	cin >> saldo;
	cin.clear();
	fflush(stdin);
	conta->setSaldoInvestimento(saldo);
	
	system("cls");
}

//----------------------------------------------------------------------------------//	

//Fun��o para cadastro de contas: apenas chamar as fun��es, lembrando que quantContas � refer�ncia para alterarmos o valor.
void cadastrarContas(Conta *listConta[100], int &quantContas) 
{
	//Contador:
	int op;
	
	//Menu:
	do {
	system("cls");
	
	cout << "		Cadastrar Contas		" << endl << endl;
	cout << "[1] Conta Poupan�a" << endl;
	cout << "[2] Conta Corrente" << endl;
	cout << "[3] Conta Investimento" << endl;
	cout << "[4] Sair" << endl << endl;
	cin >> op;
	cin.clear();
	fflush(stdin);
		
	switch(op) 
		{
			case 1: {
				ContaPoupanca *conta = new ContaPoupanca();
				poliCadastrarContaPoupanca(conta);
				listConta[quantContas] = conta;
				quantContas++;
				break;
			}
				
			case 2: {
				ContaCorrente *conta = new ContaCorrente();
				poliCadastrarContaCorrente(conta);
				listConta[quantContas] = conta;
				quantContas++;
				break;
			}				
			
			case 3: {
				ContaInvestimento *conta = new ContaInvestimento();
				poliCadastrarContaInvestimento(conta);
				listConta[quantContas] = conta;
				quantContas++;
				break;
			}
			
			case 4: {
				system("cls");
				break;
			}
			
			default: {
				system("cls");
				cout << "Op��o inv�lida, favor revalidar o menu!" << endl << endl << endl;
				break;
			}
			
		}
	
	} while (op != 4);
		
	cin.clear();
	fflush(stdin);
}

//----------------------------------------------------------------------------------//	

//Buscando as contas e retornando um ponteiro:
Conta* buscarConta(Conta *listConta[100], int quantContas) {
	
	Conta *conta = NULL;
	
	cout << "Entre com o n�mero da ag�ncia:" << endl;
	string numAgencia;
	getline(cin, numAgencia);
	cin.clear();
	fflush(stdin);
	
	cout << "Entre com o n�mero da conta:" << endl;
	string numConta;
	getline(cin, numConta);
	cin.clear();
	fflush(stdin);
	
	//Validando se a ag�ncia e conta digitadas est�o corretas:
	for (int i = 0; i < quantContas; i++) 
	{
		if ((listConta[i]->getNumAgencia() == numAgencia) && (listConta[i]->getNumConta() == numConta)) 
		{
			conta = listConta[i];
			break;
		} else {
			cout << "Conta inexistente!" << endl;
		}
	}
	
	return conta;
}

//----------------------------------------------------------------------------------//	

//Fazendo o dep�sito nas contas banc�rias: usando a fun��o de buscar conta.
void depositar(Conta *listConta[100], int quantContas)
{
	cout << "		Depositar em conta		" << endl << endl;
	Conta *conta = buscarConta(listConta, quantContas);
	
	float valor; 
	
	//Tendo uma conta preenchida:
	if (conta != NULL) {
		cout << "Entre com o valor a ser depositado:" << endl;
		cin >> valor;
		cin.clear();
		fflush(stdin);
	} else {
		cout << "Valor inv�lido!" << endl;
	}
		
	//Se retornar true e o dep�sito for feito...
	if(conta->depositar(valor)) {
		cout << "Deposito efetuado com sucesso!" << endl;
	} else {
		cout << "Valor inv�lido para dep�sito!" << endl;
	}		
}

//----------------------------------------------------------------------------------//	

//Fun��o para sacar o dinheiro
void sacar(Conta *listConta[100], int quantContas)
{
	cout << "		Sacar em conta		" << endl << endl;
	Conta *conta = buscarConta(listConta, quantContas);
	
	//Tendo uma conta preenchida:
	if (conta != NULL) {
		cout << "Entre com o valor a ser sacado:" << endl;
		float valor;
		cin >> valor;
		cin.clear();
		fflush(stdin);
		
		//Se retornar true e o dep�sito for feito...
		if(conta->sacar(valor)) {
			cout << "Saque efetuado com sucesso!" << endl;
		} else {
			cout << "Valor indispon�vel para saque!" << endl;
		}
	}
}

//Fun��o para ver o extrato da conta:
void extrato(Conta *listConta[100], int quantContas)
{
	cout << "		Sacar em conta		" << endl << endl;
	Conta *conta = buscarConta(listConta, quantContas);
	
	//Tendo uma conta preenchida:
	if (conta != NULL) {
		conta->imprimirExtrato();
	} else {
		cout << "N�o h� saldo para ser consultado." << endl;
	}
}

//----------------------------------------------------------------------------------//	

//Fun��o principal:
int main(int argc, char** argv) {
	
	//Caracteres unicode:	
	setlocale(LC_ALL, "");
	system("chcp 1252 > nul");

	//Inicializando meu contador de constas:
	int quantContas = 0;
		
	//Declarando meu vetor de ponteiro Conta:
	Conta *listConta[100];	
	
	//Contadores:
	int op;
	
	//Construindo o meu menu:
	do {
		cout << "		Terminal banc�rio		" << endl << endl;
		cout << "[1] Cadastrar contas" << endl;
		cout << "[2] Depositar valor" << endl;
		cout << "[3] Sacar valor" << endl;
		cout << "[4] Imprimir extrato banc�rio" << endl;
		cout << "[5] Sair" << endl << endl;
		
		cout << "Entre com a op��o: ";
		cin >> op;
		cin.clear();
		fflush(stdin);
		
		switch(op) 
		{
			case 1:
				cadastrarContas(listConta, quantContas);
				break;
			
			case 2: {
				if (quantContas > 0)
				{
					depositar(listConta, quantContas);
				} else {
					cout << "Favor cadastrar pelo menos uma conta para realizar essa opera��o!";
				}
				break;
			}
				
			case 3: {
				if (quantContas > 0) 
				{
					sacar(listConta, quantContas);
				} else {
					cout << "Favor cadastrar pelo menos uma conta para realizar essa opera��o!";
				}
				break;
			}
				
			case 4: {
				if (quantContas > 0) 
				{
					for (int i = 0; i < quantContas; i++) {
						listConta[i]->imprimirExtrato();
						cout << endl;
					}
				} else {
					cout << "Favor cadastrar pelo menos uma conta para realizar essa opera��o!";
				}
				break;
			}
				
			case 5:	
				system("cls");
				break;
			
			default: {
				system("cls");
				cout << "Op��o inv�lida, favor revalidar o menu!" << endl << endl << endl;
				
				cin.clear();
				fflush(stdin);
				break;
			}
		}
		
	} while (op != 5);
	
	//Mostrando todas as contas cadastradas pro usu�rio:
	char aux;
	
	cout << "Deseja ver o extrato de todas as contas cadastradas? S/N" << endl;
	cin >> aux;
	cin.clear();
	fflush(stdin);
	
	if (aux == 'S' || aux == 's') 
	{
	for (int i = 0; i < quantContas; i++) {
		listConta[i]->imprimirExtrato();
		cout << endl;
	}
	} else 
	{
		cout << endl << "Obrigado por utilizar os nossos servi�os!" << endl << endl;	
	}
	
	return 0;
}
