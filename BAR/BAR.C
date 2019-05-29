/***************************************************************************
*  $MCI Módulo de implementação: Módulo bar
*
*  Arquivo gerado:              BAR.C
*  Letras identificadoras:      BAR
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: mr - Mark Ribeiro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data    Observações
*       1.00   mr   28/05/2019 Início do desenvolvimento
*
***************************************************************************/

#include<stdio.h>
#include"BAR.H"
#include"PECA.H"

/***************************************************************************
*
*  Função: BAR retira peca
*  ****/
	BAR_tpCondRet BAR_RetiraPeca(Peca **pecas, int ind)
	{
		printf("oi\n");

		return BAR_CondRetOK;
	}/* Fim função: BAR retira peca */


/***************************************************************************
*
*  Função: BAR retorna peca
*  ****/
	BAR_tpCondRet BAR_RetornaPeca(Peca **pecas, int ind)
	{

		printf("oi\n");

		return BAR_CondRetOK;
	}/* Fim função: BAR retorna peca */

/********** Fim do módulo de implementação: Módulo bar **********/

	int main ()
	{
		Peca *pecas[2] = {NULL, NULL};

		PEC_CriaPeca(&pecas[0], 'b');

		BAR_RetiraPeca(pecas, 0);

		return 0;
	}