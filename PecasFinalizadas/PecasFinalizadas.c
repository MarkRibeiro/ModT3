/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.C
*  Letras identificadoras:      TAB
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Gra�a Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*     Vers�o   Autores	  Data					Observa��es
*		 4		cgm			13/05				Ajustes finais
*		 3		cgm			11/05				Corre��o de bugs
*		 2		cgm			04/05				Revis�o de algumas fun��es criadas
*	  	 1		cgm			03/05				Criado o m�dulo
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "../ModT3/Peca/PECA.H"
#include "LISTA.H"
#include "PecasFinalizadas.h"

/***********************************************************************
*
*  $TC Tipo de dados: Descritor do pecas capturadas 
*
*
*  $ED Descri��o do tipo
*     Struct que representa a 'classe' pecas capturadas.
*
***********************************************************************/

typedef struct tgPFN
{
		 LIS_tppLista bar ;	/* Ponteiro para a lista de listas de pe�a */

} tpPFN;

/*****  Dados encapsulados no m�dulo  *****/

		static tpPFN * b = NULL ;
				/* Ponteiro para o BAR */

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: TAB  &Criar Tabuleiro
*  ****/
	/*Fun��o auxiliar do Criar BAR*/
   void Excluir(void*ponteiro)
   {
	   free(ponteiro);
   }
   /*Fim Fun��o auxiliar do Criar BAR*/

   PFN_tpCondRet PFN_CriarPFN(
             void   ( * ExcluirValor ) ( void * pDado ) )
   {
	  int i;
      b = ( tpPFN*)malloc( sizeof( tpPFN )) ;
      if ( b == NULL )
      {
         return PFN_CondRetFaltouMemoria ;
      } /* if */

	  b->bar=NULL;
	  b->bar = LIS_CriarLista(Excluir);
	  if(b->bar==NULL)
	  {
		  return PFN_CondRetFaltouMemoria;
	  }/*if*/

	  for(i=0;i<2;i++)
	   {
		   LIS_InserirElementoApos( b->bar ,
                                          LIS_CriarLista(Excluir));
	   }/*for*/

      return PFN_CondRetOK ;

   } /* Fim fun��o: TAB  &Criar BAR */

 /***************************************************************************
*
*  Fun��o: TAB  &Inserir BAR
*  ****/

   PFN_tpCondRet PFN_Inserir( char c )
   {
	   Peca *p=NULL;
	   LIS_tppLista listaCorr=NULL;
	   LIS_tpCondRet auxLis;
	   PEC_tpCondRet auxPec;

	   auxPec = PEC_CriaPeca( &p, c );
	   if(auxPec ==PEC_CondRetFaltouMemoria)
	   {
		   return PFN_CondRetFaltouMemoria;
	   }

	   if(c=='b')
	   {
		   IrInicioLista( b->bar ) ;
	   }
	   
	   else
	   {
		   IrFinalLista( b->bar ) ;
	   }

	   listaCorr=(LIS_tppLista)LIS_ObterValor( b->bar ) ;
	   auxLis=LIS_InserirElementoApos( listaCorr , p);	
	   if(auxLis==LIS_CondRetFaltouMemoria)
	   {
		   return PFN_CondRetFaltouMemoria;
	   }/*if*/

	   return PFN_CondRetOK;

   } /* Fim fun��o: TAB  &Inserir BAR */

 /***************************************************************************
*
*  Fun��o: TAB  &NPecas BAR
*  ****/

   PFN_tpCondRet PFN_NPecas( char c, int *n )
   {
	   LIS_tppLista listaCorr=NULL;

	   if(c=='b')
	   {
		   IrInicioLista( b->bar ) ;
	   }
	   
	   else
	   {
		   IrFinalLista( b->bar ) ;
	   }

	   listaCorr=(LIS_tppLista)LIS_ObterValor( b->bar ) ;
	   pegaNumElementos( listaCorr , n );

	   return PFN_CondRetOK;

   } /* Fim fun��o: TAB  &NPecas BAR */