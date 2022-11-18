#ifndef TIPOINVESTIMENTO_H
#define TIPOINVESTIMENTO_H

#include <iostream>
using namespace std;

//Enum para o tipo de investimento: de acordo com o numero seleciona o investimento escolhido:
enum TipoInvest{
	CDB = 1,	
	TESOURO = 2,
	ACAO = 3,
	IMOBILIARIO = 4
};

//----------------------------------------------------------------------------------//	

//Classe TipoInvestimento que será mãe para a classe ContaInvestimento juntamente com a Conta:
class TipoInvestimento
{	
	private:
	
	public:
		TipoInvestimento();
		TipoInvestimento(TipoInvest tipoInvest, float saldoInvestimento);
		~TipoInvestimento();
		
		TipoInvest getTipoInvest();
		float getSaldoInvestimento();
	
		void setTipoInvest(TipoInvest tipoInvest);
		void setSaldoInvestimento(float saldoInvestimento);
		
	protected:
		TipoInvest tipoInvest;
		float saldoInvestimento;
	
		string getNomeTipoInvest();
};

#endif
