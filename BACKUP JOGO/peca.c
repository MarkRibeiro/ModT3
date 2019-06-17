/***************************************************************************
*  $MCI Módulo de implementação: Módulo peça
*
*  Arquivo gerado:              PECA.H
*  Letras identificadoras:      PEC
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: mr - Mark RIbeiro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data    Observações
*       3.00   mr   11/05/2019 Documentaçâo
*       2.00   mr   10/05/2019 Final do desenvolvimento
*       1.00   mr   01/05/2019 Início do desenvolvimento
*
***************************************************************************/

#include "PECA.H"

/***********************************************************************
*
*  $TC Tipo de dados: PEC Descritor de peça
*
*
*  $ED Descrição do tipo
*     Descreve a organização da peça
*
***********************************************************************/

typedef struct peca{
	char cor;
}Peca;

/***************************************************************************
*
*  Função: PEC Cria peça
*  ****/

	PEC_tpCondRet PEC_CriaPeca( Peca **p,  char cor )
	{
		*p = (Peca*) malloc (sizeof(Peca));

		if(*p==NULL)
		{
			return PEC_CondRetFaltouMemoria;
		} /* if */

		else
		{
			(*p)->cor = cor;

			return PEC_CondRetOK;
		} /* if */
	}  /* Fim função: PEC Cria peça */

/***************************************************************************
*
*  Função: PEC Obter peça
*  ****/
	PEC_tpCondRet PEC_ObterCorPeca ( Peca *p, char *cor )
	{
		if( p==NULL )
		{
			return PEC_CondRetPecaNaoExiste;
		} /* if */

		*cor=p->cor;
		if(*cor!='b' && *cor!='p')
		{
			return PEC_CondRetInvalida;
		} /* if */

		return PEC_CondRetOK; 
	} /* Fim função: PEC Obter peça */

/***************************************************************************
*
*  Função: PEC Destroi peça
*  ****/
	PEC_tpCondRet PEC_DestroiPeca( Peca *p )
	{
		if(p==NULL)
		{
			return PEC_CondRetPecaNaoExiste;
		} /* if */
	 
		free(p);

		return PEC_CondRetOK;
	} /* Fim função: PEC Destroi peça */

/********** Fim do módulo de implementação: Módulo peça **********/