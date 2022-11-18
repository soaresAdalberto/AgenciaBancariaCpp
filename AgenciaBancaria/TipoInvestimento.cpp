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

//M�todos GET:
TipoInvest TipoInvestimento::getTipoInvest(){
	return tipoInvest;
}

float TipoInvestimento::getSaldoInvestimento(){
	return saldoInvestimento;
}
	
//----------------------------------------------------------------------------------//	

//M�todos SET e regras de neg�cio:
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
				nomeTipoInvest = "Mercado de A��es";
				break;
		case 4:
				nomeTipoInvest = "Fundo Imobili�rio";
				break;
	}
	return nomeTipoInvest;
}
