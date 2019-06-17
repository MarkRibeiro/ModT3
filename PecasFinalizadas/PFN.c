/***************************************************************************
*  $MCI Módulo de implementação: Módulo Pecas Finalizadas
*
*  Arquivo gerado:              PFN.C
*  Letras identificadoras:      PFN
*
*  Projeto: Trabaolho 3 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data		Observações
*		 4		cgm		  16/06		Ajustes na funcao de inserir
*		 3		cgm		  11/06		Criação de scripts de teste do modulo
*		 2		cgm		  09/06		Finalização do modulo
*	  	 1		mr		  07/06		Criado o módulo
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "PECA.H"
#include "LISTA.H"
#include "PFN.h"

/***********************************************************************
*
*  $TC Tipo de dados: Descritor do pecas Finalizadas 
*
*
*  $ED Descrição do tipo
*     Struct que representa a 'classe' pecas Finalizadas.
*
***********************************************************************/

typedef struct tgPFN
{
		 LIS_tppLista pfn ;	/* Ponteiro para a lista de listas de peça */

} tpPFN;

/*****  Dados encapsulados no módulo  *****/

		static tpPFN * f = NULL ;
				/* Ponteiro para o pecasFinalizadas */

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: PFN  &CriarPFN
*  ****/
	/*Função auxiliar do CriarPFN*/
   void Excluir(void*ponteiro)
   {
	   free(ponteiro);
   }
   /*Fim Função auxiliar do CriarPFN*/

   PFN_tpCondRet PFN_CriarPFN(
             void   ( * ExcluirValor ) ( void * pDado ) )
   {
	  int i;
      f = ( tpPFN*)malloc( sizeof( tpPFN )) ;
      if ( f == NULL )
      {
         return PFN_CondRetFaltouMemoria ;
      } /* if */

	  f->pfn=NULL;
	  f->pfn = LIS_CriarLista(Excluir);
	  if(f->pfn==NULL)
	  {
		  return PFN_CondRetFaltouMemoria;
	  }/*if*/

	  for(i=0;i<2;i++)
	   {
		   LIS_InserirElementoApos( f->pfn ,
                                          LIS_CriarLista(Excluir));
	   }/*for*/

      return PFN_CondRetOK ;

   } /* Fim função: PFN  &CriarPFN */

 /***************************************************************************
*
*  Função: PFN  &Inserir
*  ****/

   PFN_tpCondRet PFN_Inserir( char c, int n )
   {
	   int i=0;
	   Peca *p=NULL;
	   LIS_tppLista listaCorr=NULL;
	   LIS_tpCondRet auxLis;
	   PEC_tpCondRet auxPec;

	   if(c=='b')
	   {
		   IrInicioLista( f->pfn ) ;
	   }
	   
	   else
	   {
		   IrFinalLista( f->pfn ) ;
	   }

	   listaCorr=(LIS_tppLista)LIS_ObterValor( f->pfn ) ;

	   while(i<n)
	   {
		   auxPec = PEC_CriaPeca( &p, c );
		   if(auxPec ==PEC_CondRetFaltouMemoria)
		   {
			   return PFN_CondRetFaltouMemoria;
		   }

		   auxLis=LIS_InserirElementoApos( listaCorr , p);	
		   if(auxLis==LIS_CondRetFaltouMemoria)
		   {
			   return PFN_CondRetFaltouMemoria;
		   }/*if*/
		   i++;
	   }

	   return PFN_CondRetOK;

   } /* Fim função: PFN  &Inserir */

 /***************************************************************************
*
*  Função:  PFN  &NPecas
*  ****/

   PFN_tpCondRet PFN_NPecas( char c, int *n )
   {
	   LIS_tppLista listaCorr=NULL;

	   if(c=='b')
	   {
		   IrInicioLista( f->pfn ) ;
	   }
	   
	   else
	   {
		   IrFinalLista( f->pfn ) ;
	   }

	   listaCorr=(LIS_tppLista)LIS_ObterValor( f->pfn ) ;
	   pegaNumElementos( listaCorr , n );

	   return PFN_CondRetOK;

   } /* Fim função: PFN  &NPecas */

   /***************************************************************************
*
*  Função: PFN  &DestruirPFN
*  ****/

   void PFN_DestruirPFN( void )
   {

	   LIS_DestruirLista( f->pfn ) ;
	   f->pfn=NULL;
       free( f) ;
	   f=NULL;

   } /* Fim função: PFN  &DestruirPFN */