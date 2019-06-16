/***************************************************************************
*  $MCI Módulo de implementação: Módulo Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.C
*  Letras identificadoras:      TAB
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data					Observações
*		 4		cgm			16/06				Ajustes na funcao de inserir
*		 4		cgm			13/05				Ajustes finais
*		 3		cgm			11/05				Correção de bugs
*		 2		cgm			04/05				Revisão de algumas funções criadas
*	  	 1		cgm			03/05				Criado o módulo
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
*  $ED Descrição do tipo
*     Struct que representa a 'classe' pecas capturadas.
*
***********************************************************************/

typedef struct tgBAR
{
		 LIS_tppLista bar ;	/* Ponteiro para a lista de listas de peça */

} tpBar;

/*****  Dados encapsulados no módulo  *****/

		static tpBar * b = NULL ;
				/* Ponteiro para o BAR */

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: TAB  &Criar Tabuleiro
*  ****/
	/*Função auxiliar do Criar BAR*/
   void ExcluirBAR(void*ponteiro)
   {
	   free(ponteiro);
   }
   /*Fim Função auxiliar do Criar BAR*/

   BAR_tpCondRet BAR_CriarBAR(
             void   ( * ExcluirValor ) ( void * pDado ) )
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

   } /* Fim função: TAB  &Criar BAR */

   /***************************************************************************
*
*  Função: TAB  &Destruir BAR
*  ****/

   void BAR_DestruirBAR( void )
   {

	   LIS_DestruirLista( b->bar ) ;
	   b->bar=NULL;
       free( b) ;
	   b=NULL;

   } /* Fim função: TAB  &Destruir BAR */

 /***************************************************************************
*
*  Função: TAB  &Inserir BAR
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
		   n++;
	   }

	   return BAR_CondRetOK;

   } /* Fim função: TAB  &Inserir BAR */

    /***************************************************************************
*
*  Função: TAB  &Excluir BAR
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

   } /* Fim função: TAB  &Excluir BAR 

	 /***************************************************************************
*
*  Função: TAB  &NPecas BAR
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

   } /* Fim função: TAB  &NPecas BAR */