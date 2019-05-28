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

#include "LISTA.H"
#include "TABULEIRO.H"
#include "PECA.H"

/***********************************************************************
*
*  $TC Tipo de dados: Descritor do tabuleiro
*
*
*  $ED Descrição do tipo
*     Struct que representa a 'classe' tabuleiro.
*
***********************************************************************/

typedef struct tgTabuleiro
{
		 LIS_tppLista tabuleiro ;	/* Ponteiro para a lista de listas de peça */

} tpTabuleiro;

/*****  Dados encapsulados no módulo  *****/

		static tpTabuleiro * t = NULL ;
				/* Ponteiro para o tabuleiro */

/***** Protótipos das funções encapuladas no módulo *****/

	static LIS_tppLista IrCasa( int nCasa ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: TAB  &Criar Tabuleiro
*  ****/

   TAB_tpCondRet TAB_CriarTabuleiro(
             void   ( * ExcluirValor ) ( void * pDado ) )
   {
      t = ( tpTabuleiro*)malloc( sizeof( tpTabuleiro )) ;
      if ( t == NULL )
      {
         return TAB_CondRetFaltouMemoria ;
      } /* if */

	  t->tabuleiro = NULL ;

      return TAB_CondRetOK ;

   } /* Fim função: TAB  &Criar Tabuleiro */

   /***************************************************************************
*
*  Função: TAB  &Destruir tabuleiro
*  ****/

   void TAB_DestruirTabuleiro( void )
   {

	   LIS_DestruirLista( t->tabuleiro ) ;

       free( t) ;
	   t=NULL;

   } /* Fim função: TAB  &Destruir tabuleiro */

      /***************************************************************************
*
*  Função: TAB  &Arruma tabuleiro
*  ****/
   /*Função auxiliar do Arruma Tabuleiro*/
   void Excluir(void*ponteiro)
   {
	   free(ponteiro);
   }
   /*Fim Função auxiliar do Arruma Tabuleiro*/

   TAB_tpCondRet TAB_ArrumarTabuleiro( void )
   {
	   int i;
	   TAB_tpCondRet aux;
	   if(t==NULL)
	   {
		   return TAB_CondRetTabNaoExiste;
	   }/*if*/
	   t->tabuleiro = LIS_CriarLista(Excluir);
	   if(t==NULL)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/
	   for(i=0;i<24;i++)
	   {
		   LIS_InserirElementoApos( t->tabuleiro ,
                                          LIS_CriarLista(Excluir));
	   }/*for*/

	   aux=TAB_InserirPecasCasa( 2, 'b', 1 );
	   if(aux==TAB_CondRetFaltouMemoria)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/

	   aux=TAB_InserirPecasCasa( 5, 'p', 6 );
	   if(aux==TAB_CondRetFaltouMemoria)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/

	   aux=TAB_InserirPecasCasa( 3, 'p', 8 );
	   if(aux==TAB_CondRetFaltouMemoria)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/

	   aux=TAB_InserirPecasCasa( 5, 'b', 12 );
	   if(aux==TAB_CondRetFaltouMemoria)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/

	   aux=TAB_InserirPecasCasa( 5, 'p', 13 );
	   if(aux==TAB_CondRetFaltouMemoria)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/

	   aux=TAB_InserirPecasCasa( 3, 'b', 17 );
	   if(aux==TAB_CondRetFaltouMemoria)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/

	   aux=TAB_InserirPecasCasa( 5, 'b', 19 );
	   if(aux==TAB_CondRetFaltouMemoria)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/

	   aux=TAB_InserirPecasCasa( 2, 'p', 24 );
	   if(aux==TAB_CondRetFaltouMemoria)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/

	   return TAB_CondRetOK;
   } 
	/* Fim função: TAB  &Arruma tabuleiro */

    /***************************************************************************
*
*  Função: TAB  &Print tabuleiro
*  ****/

   TAB_tpCondRet TAB_PrintTabuleiro( void ) 
   {
	   LIS_tppLista casa=NULL;
	   char cor;
	   int num=NULL, i, j;
	   if(t==NULL)
	   {
		   return TAB_CondRetTabNaoExiste;
	   }/*if*/

	   for(i=0;i<13;i++)
	   {
		   printf(" -");
	   }
	   printf("\n|");
	   for(j=1;j<=6;j++)
	   {
		   for(i=12;i>0;i--)
		   {
			   if(i==6)
			   {
				   printf("| ");
			   }

			   casa=IrCasa(i);
			   pegaNumElementos(casa, &num);
			   if(num>=j)
			   {
				   PEC_ObterCorPeca ((Peca*) LIS_ObterValor( casa ), &cor );
				   printf("%c ",cor);
			   }
			   else
			   {
				   printf("  ");
			   }
		   }
		   printf("|\n|");
	   }

	   for(i=0;i<13;i++)
	   {
		   printf("- ");
	   }

	   printf("|\n|");

	   for(j=6;j>=1;j--)
	   {
		   for(i=13;i<25;i++)
		   {
			   if(i==19)
			   {
				   printf("| ");
			   }

			   casa=IrCasa(i);
			   pegaNumElementos(casa, &num);
			   if(num>=j)
			   {
				   PEC_ObterCorPeca ((Peca*) LIS_ObterValor( casa ), &cor );
				   printf("%c ",cor);
			   }
			   else
			   {
				   printf("  ");
			   }
		   }
		   printf("|\n|");
	   }
	   for(i=0;i<13;i++)
	   {
		   printf("- ");
	   }

	   printf("\n\n\n");

	   return TAB_CondRetOK;
   }

   /* Fim função: TAB  &Print tabuleiro */

   /***************************************************************************
*
*  Função: TAB  &Move Peça
*  ****/

   TAB_tpCondRet TAB_MoverPeca( int casaIni, int casaFim, char corJogador ) 
   {
	   TAB_tpCondRet aux;
	   char corIni=NULL, corFim=NULL;
	   LIS_tppLista ini=NULL, fim=NULL;

	   if(t==NULL)
	   {
		   return TAB_CondRetTabNaoExiste;
	   }/*if*/
	   if((casaIni<1 || casaIni>24) || (casaFim<1 || casaFim>24))
	   {
		   return TAB_CondRetNumCasaNaoExiste;
	   }/*if*/

	   ini=IrCasa(casaIni);
	   IrFinalLista(ini) ;

	   if((Peca*) LIS_ObterValor( ini )==NULL)
	   {
		   return TAB_CondRetCasaVazia;
	   }/*if*/

	   PEC_ObterCorPeca ((Peca*) LIS_ObterValor( ini ), &corIni );
	   if(corIni!=corJogador)
	   {
		   return TAB_CondRetMovInvalido;
	   }/*if*/

	   LIS_ExcluirElemento( ini ) ;

	   fim=IrCasa(casaFim);
	   IrFinalLista(fim) ;

	   PEC_ObterCorPeca ((Peca*) LIS_ObterValor( fim ), &corFim);
	   if(corFim!=NULL && corFim != corJogador )
	   {
		   return TAB_CondRetMovInvalido;
	   }/*if*/

	   aux=TAB_InserirPecasCasa( 1, corIni, casaFim );
	   if(aux==TAB_CondRetFaltouMemoria)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/

	   return TAB_CondRetOK;
   }

   /* Fim função: TAB  &Move Peça */

   /***************************************************************************
*
*  Função: TAB  &Remove Peça
*  ****/
   TAB_tpCondRet TAB_RemoverPeca( int nCasa ) 
   {
	   LIS_tppLista casa=NULL;
	   if(t==NULL)
	   {
		   return TAB_CondRetTabNaoExiste;
	   }/*if*/
	   if(nCasa<1 || nCasa>24)
	   {
		   return TAB_CondRetNumCasaNaoExiste;
	   }/*if*/
	   casa=IrCasa(nCasa);
	   IrFinalLista(casa) ;
	   LIS_ExcluirElemento( casa ) ;
	   return TAB_CondRetOK;
   }

   /* Fim função: TAB  &Remove Peça */

      /***************************************************************************
*
*  Função: TAB  &Insere Peça em Casa
*  ****/
   TAB_tpCondRet TAB_InserirPecasCasa( int n, char cor, int nCasa ) 
   {
	   int cont=0;
	   LIS_tpCondRet auxTab;
	   PEC_tpCondRet auxPec;
	   Peca *p=NULL;
	   LIS_tppLista casaCorrente = IrCasa( nCasa );

	   if(t==NULL)
	   {
		   return TAB_CondRetTabNaoExiste;
	   }/*if*/

	   if(nCasa <1 || nCasa>24)
	   {
		   return TAB_CondRetNumCasaNaoExiste;
	   }/*if*/

	   while(cont<n)
	   {
		   auxPec=PEC_CriaPeca(&p, cor); 
		   if(auxPec==PEC_CondRetFaltouMemoria)
		   {
			   return TAB_CondRetFaltouMemoria;
		   }/*if*/
		   auxTab=LIS_InserirElementoApos( casaCorrente ,
                                         p );
		   if(auxTab==LIS_CondRetFaltouMemoria)
		   {
			   return TAB_CondRetFaltouMemoria;
		   }/*if*/
		   cont++;
	   }/*while*/
	   return TAB_CondRetOK;
   }
  
   /* Fim função: TAB  &Insere Peça em Casa */

   /*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: LIS  -Ir para Casa
*
*  $ED Descrição da função
*     Aponta o elemento corrente do tabuleiro para a nCasa desejada.
*
***********************************************************************/

   LIS_tppLista IrCasa( int nCasa ) 
   {
	   if(nCasa <1 || nCasa>24)
	   {
		   return NULL;
	   }/*if*/
	   IrInicioLista( t->tabuleiro ) ;
	   LIS_AvancarElementoCorrente(  t->tabuleiro ,
                                              nCasa-1) ;
	   return (LIS_tppLista)LIS_ObterValor( t->tabuleiro ) ;
   }

    /* Fim função: TAB  &Ir Casa */
