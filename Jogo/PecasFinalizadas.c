/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Pecas Finalizadas
*
*  Arquivo gerado:              PecasFinalizadas.C
*  Letras identificadoras:      PFN
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Gra�a Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*     Vers�o   Autores	  Data		Observa��es
*		 3		cgm		  11/06		Cria��o de scripts de teste do modulo
*		 2		cgm		  09/06		Finaliza��o do modulo
*	  	 1		mr		  07/06		Criado o m�dulo
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "PECA.H"
#include "LISTA.H"
#include "PecasFinalizadas.h"

/***********************************************************************
*
*  $TC Tipo de dados: Descritor do pecas Finalizadas 
*
*
*  $ED Descri��o do tipo
*     Struct que representa a 'classe' pecas Finalizadas.
*
***********************************************************************/

typedef struct tgPFN
{
		 LIS_tppLista pfn ;	/* Ponteiro para a lista de listas de pe�a */

} tpPFN;

/*****  Dados encapsulados no m�dulo  *****/

		static tpPFN * f = NULL ;
				/* Ponteiro para o pecasFinalizadas */

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: PFN  &CriarPFN
*  ****/
	/*Fun��o auxiliar do CriarPFN*/
   void Excluir(void*ponteiro)
   {
	   free(ponteiro);
   }
   /*Fim Fun��o auxiliar do CriarPFN*/

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

   } /* Fim fun��o: PFN  &CriarPFN */

 /***************************************************************************
*
*  Fun��o: PFN  &Inserir
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
		   IrInicioLista( f->pfn ) ;
	   }
	   
	   else
	   {
		   IrFinalLista( f->pfn ) ;
	   }

	   listaCorr=(LIS_tppLista)LIS_ObterValor( f->pfn ) ;
	   auxLis=LIS_InserirElementoApos( listaCorr , p);	
	   if(auxLis==LIS_CondRetFaltouMemoria)
	   {
		   return PFN_CondRetFaltouMemoria;
	   }/*if*/

	   return PFN_CondRetOK;

   } /* Fim fun��o: PFN  &Inserir */

 /***************************************************************************
*
*  Fun��o:  PFN  &NPecas
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

   } /* Fim fun��o: PFN  &NPecas */

   /***************************************************************************
*
*  Fun��o: PFN  &DestruirPFN
*  ****/

   void PFN_DestruirPFN( void )
   {

	   LIS_DestruirLista( f->pfn ) ;
	   f->pfn=NULL;
       free( f) ;
	   f=NULL;

   } /* Fim fun��o: PFN  &DestruirPFN */