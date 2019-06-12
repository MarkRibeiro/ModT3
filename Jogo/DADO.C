/***************************************************************************
*  $MCI Módulo de implementação: Módulo dado
*
*  Arquivo gerado:              DADO.C
*  Letras identificadoras:      DAD
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: mr - Mark Ribeiro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data    Observações
*       3.00   mr   11/05/2019 Documentação
*		2.00   mr   05/05/2019 Final do desenvolvimento
*       1.00   mr   27/04/2019 Início do desenvolvimento
*
***************************************************************************/

#include "DADO.H"

/***************************************************************************
*
*  Função: DAD Joga dados
*  ****/
	DAD_tpCondRet DAD_JogaDados(int *d)
	{
		time_t t;
		srand((unsigned) time(&t));

		d[0] = (rand() % 6) + 1;
		d[1] = (rand() % 6) + 1;

		if(d[0] == d[1])
		{
			d[2] = d[0];
			d[3] = d[0];
		} /* if */

		return DAD_CondRetOK;
	}  /* Fim função: DAD Joga dados */

/********** Fim do módulo de implementação: Módulo dado **********/