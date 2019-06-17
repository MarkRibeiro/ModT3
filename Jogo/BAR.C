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
*		 4		cgm			16/06				Ajustes na funcao de inserir
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

#include "PECA.H"
#include "LISTA.H"
#include "BAR.h"

/***********************************************************************
*
*  $TC Tipo de dados: Descritor do pecas capturadas 
*
*
*  $ED Descri��o do tipo
*     Struct que representa a 'classe' pecas capturadas.
*
***********************************************************************/

typedef struct tgBAR
{
		 LIS_tppLista bar ;	/* Ponteiro para a lista de listas de pe�a */

} tpBar;

/*****  Dados encapsulados no m�dulo  *****/

		static tpBar * b = NULL ;
				/* Ponteiro para o BAR */

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: TAB  &Criar Tabuleiro
*  ****/
	/*Fun��o auxiliar do Criar BAR*/
   void ExcluirBAR(void*ponteiro)
   {
	   free(ponteiro);
   }
   /*Fim Fun��o auxiliar do Criar BAR*/

   BAR_tpCondRet BAR_CriarBAR()
   {
	  int i;
      b = ( tpBar*)malloc( sizeof( tpBar )) ;
      if ( b == NULL )
      {
         return BAR_CondRetFaltouMemoria ;
      } /* if */

	  b->bar=NULL;
	  b->bar = LIS_CriarLista(ExcluirBAR);
	  if(b->bar==NULL)
	  {
		  return BAR_CondRetFaltouMemoria;
	  }/*if*/

	  for(i=0;i<2;i++)
	   {
		   LIS_InserirElementoApos( b->bar ,
                                          LIS_CriarLista(ExcluirBAR));
	   }/*for*/

      return BAR_CondRetOK ;

   } /* Fim fun��o: TAB  &Criar BAR */

   /***************************************************************************
*
*  Fun��o: TAB  &Destruir BAR
*  ****/

   void BAR_DestruirBAR( void )
   {

	   LIS_DestruirLista( b->bar ) ;
	   b->bar=NULL;
       free( b) ;
	   b=NULL;

   } /* Fim fun��o: TAB  &Destruir BAR */

 /***************************************************************************
*
*  Fun��o: TAB  &Inserir BAR
*  ****/

   BAR_tpCondRet BAR_Inserir( char c, int n )
   {
	   int i=0;
	   Peca *p=NULL;
	   LIS_tppLista listaCorr=NULL;
	   LIS_tpCondRet auxLis;
	   PEC_tpCondRet auxPec;

	   if(c=='b')
	   {
		   IrInicioLista( b->bar ) ;
	   }
	   
	   else
	   {
		   IrFinalLista( b->bar ) ;
	   }

	   listaCorr=(LIS_tppLista)LIS_ObterValor( b->bar ) ;

	   while(i<n)
	   {
		   auxPec = PEC_CriaPeca( &p, c );
		   if(auxPec ==PEC_CondRetFaltouMemoria)
		   {
			   return BAR_CondRetFaltouMemoria;
		   }

		   auxLis=LIS_InserirElementoApos( listaCorr , p);	
		   if(auxLis==LIS_CondRetFaltouMemoria)
		   {
			   return BAR_CondRetFaltouMemoria;
		   }/*if*/
		   i++;
	   }

	   return BAR_CondRetOK;

   } /* Fim fun��o: TAB  &Inserir BAR */

    /***************************************************************************
*
*  Fun��o: TAB  &Excluir BAR
*  ****/

   BAR_tpCondRet BAR_Excluir( char c )
   {
	   LIS_tppLista listaCorr=NULL;
	   LIS_tpCondRet aux;

	   if(c=='b')
	   {
		   IrInicioLista( b->bar ) ;
	   }
	   
	   else
	   {
		   IrFinalLista( b->bar ) ;
	   }

	   listaCorr=(LIS_tppLista)LIS_ObterValor( b->bar ) ;
	   aux=LIS_ExcluirElemento( listaCorr);	
	   if(aux==LIS_CondRetListaVazia)
	   {
		   return BAR_CondRetVazio;
	   }/*if*/

	   return BAR_CondRetOK;

   } /* Fim fun��o: TAB  &Excluir BAR 

	 /***************************************************************************
*
*  Fun��o: TAB  &NPecas BAR
*  ****/

   BAR_tpCondRet BAR_NPecas( char c, int *n )
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

	   return BAR_CondRetOK;

   } /* Fim fun��o: TAB  &NPecas BAR */