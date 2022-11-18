#include "TipoInvestimento.h"

//Construtor e destrutor:
TipoInvestimento::TipoInvestimento()
{
}

TipoInvestimento::TipoInvestimento(TipoInvest tipoInvest, float saldoInvestimento) 
{
	setTipoInvest(tipoInvest);
	setSaldoInvestimento(saldoInvestimento);
}

TipoInvestimento::~TipoInvestimento()
{
}

//----------------------------------------------------------------------------------//	

//Métodos GET:
TipoInvest TipoInvestimento::getTipoInvest(){
	return tipoInvest;
}

float TipoInvestimento::getSaldoInvestimento(){
	return saldoInvestimento;
}
	
//----------------------------------------------------------------------------------//	

//Métodos SET e regras de negócio:
void TipoInvestimento::setTipoInvest(TipoInvest tipoInvest){
	this->tipoInvest = tipoInvest;
}

void TipoInvestimento::setSaldoInvestimento(float saldoInvestimento){
	this->saldoInvestimento = (saldoInvestimento > 0) ? saldoInvestimento : 0;
}
	
string TipoInvestimento::getNomeTipoInvest(){
	string nomeTipoInvest = "";
	
	switch(tipoInvest){
		case 1:
				nomeTipoInvest = "CDB";
				break;
		case 2:
				nomeTipoInvest = "Tesouro Direto";
				break;
		case 3:
				nomeTipoInvest = "Mercado de Ações";
				break;
		case 4:
				nomeTipoInvest = "Fundo Imobiliário";
				break;
	}
	return nomeTipoInvest;
}
