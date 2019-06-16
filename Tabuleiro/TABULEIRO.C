/***************************************************************************
*  $MCI Módulo de implementação: Módulo Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.C
*  Letras identificadoras:      TAB
*
*  Projeto: Trabaolho 3 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data					Observações
*		 6		cgm			16/06				Add func quadrante
*		 5		cgm			13/06				Add func Checa casa e ajuste na mover peca
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
	/*Função auxiliar do Criar Tabuleiro*/
   void ExcluirTabuleiro(void*ponteiro)
   {
	   free(ponteiro);
   }
   /*Fim Função auxiliar do Criar Tabuleiro*/
   TAB_tpCondRet TAB_CriarTabuleiro(
             void   ( * ExcluirValor ) ( void * pDado ) )
   {
	   int i;
      t = ( tpTabuleiro*)malloc( sizeof( tpTabuleiro )) ;
      if ( t == NULL )
      {
         return TAB_CondRetFaltouMemoria ;
      } /* if */

	  t->tabuleiro = NULL ;

	  t->tabuleiro = LIS_CriarLista(ExcluirTabuleiro);
	   if(t==NULL)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }/*if*/
	   for(i=0;i<24;i++)
	   {
		   LIS_InserirElementoApos( t->tabuleiro ,
                                          LIS_CriarLista(ExcluirTabuleiro));
	   }/*for*/

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

   TAB_tpCondRet TAB_ArrumarTabuleiro( void )
   {
	   int i;
	   TAB_tpCondRet aux;
	   if(t==NULL)
	   {
		   return TAB_CondRetTabNaoExiste;
	   }/*if*/

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

	   printf("\n");
	   for(i=0;i<13;i++)
	   {
		   if(i<6)
		   {
			    if(i<3)
				{
					printf(" %d", 12-i);
				}/*if*/
				else
				{
					printf("  %d", 12-i);
				}/*else*/
		   }/*if*/
		   else if(i>6)
		   {
				if(13-i==6)
				{
					printf("   ");
				}/*if*/
				printf("  %d", 13-i);
		   }/*else if*/
	   }/*for*/
	   printf("\n");

	   for(i=0;i<13;i++)
	   {
		   printf(" --");
	   }/*for*/

	   printf("\n|");
	   for(j=1;j<=6;j++)
	   {
		   for(i=12;i>0;i--)
		   {
			   if(i==6)
			   {
				   printf("|| ");
			   }/*if*/

			   casa=IrCasa(i);
			   pegaNumElementos(casa, &num);
			   if(num>=j)
			   {
				   PEC_ObterCorPeca ((Peca*) LIS_ObterValor( casa ), &cor );
				   printf(" %c ",cor);
			   }/*if*/
			   else
			   {
				   printf("   ");
			   }/*if*/
		   }/*for*/
		   printf("|\n|");
	   }/*for*/

	   for(i=0;i<13;i++)
	   {
		   printf("-- ");
	   }/*for*/

	   printf("|\n|");

	   for(j=6;j>=1;j--)
	   {
		   for(i=13;i<25;i++)
		   {
			   if(i==19)
			   {
				   printf("|| ");
			   }/*if*/

			   casa=IrCasa(i);
			   pegaNumElementos(casa, &num);
			   if(num>=j)
			   {
				   PEC_ObterCorPeca ((Peca*) LIS_ObterValor( casa ), &cor );
				   if(j==6 && num>6)
				   {
					   printf(" %d ",num);
				   }/*if*/
				   else
				   {
					   printf(" %c ",cor);
				   }/*else*/
			   }/*if*/
			   else
			   {
				   printf("   ");
			   }/*else*/
		   }/*for*/
		   printf("|\n|");
	   }/*for*/

	   for(i=0;i<13;i++)
	   {
		   printf("-- ");
	   }/*for*/

	   printf("\n");
	   for(i=13;i<25;i++)
	   {
		   if(i==19)
			   printf("   ");
		   printf(" %d", i);
	   }/*for*/

	   printf("\n\n\n");

	   return TAB_CondRetOK;
   }

   /* Fim função: TAB  &Print tabuleiro */

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
*  Função: TAB  &Checa Casa
*  ****/
   int TAB_ChecaCasa (int nCasa, char c)
   {
	   int num;
	   char corFim=NULL;
	   LIS_tppLista casa=IrCasa(nCasa);
	   pegaNumElementos(casa, &num);
	   IrFinalLista(casa) ;
	   PEC_ObterCorPeca ((Peca*) LIS_ObterValor( casa ), &corFim);
	   if(num>1 && corFim!=c)
	   {
		   return num;
	   }/*if*/
	   else if(num==1 && corFim!=c)
	   {
		   return 1;
	   }/*else if*/
	   else
	   {
		   return 0;
	   }/*else*/
   }
   /* Fim função: TAB  &Checa Casa */

         /***************************************************************************
*
*  Função: TAB  &Checa Quadrante
*  ****/
   int TAB_ChecaQuadrante (char c)
   {
	   int num, i, sum=0;
	   char corAux;
	   LIS_tppLista casa;
	   if(c=='b')
	   {
			for(i=19;i<25;i++)
			{
				casa=IrCasa(i);
				PEC_ObterCorPeca ((Peca*) LIS_ObterValor( casa ), &corAux);
				if(corAux=='b')
				{
					pegaNumElementos(casa, &num);
					sum = sum + num;
				}
			}
	   }
	   else
	   {
		   for(i=1;i<7;i++)
			{
				casa=IrCasa(i);
				PEC_ObterCorPeca ((Peca*) LIS_ObterValor( casa ), &corAux);
				if(corAux=='p')
				{
					pegaNumElementos(casa, &num);
					sum = sum + num;
				}
			}
	   }
	   if(sum==12)
	   {
		   return 1;
	   }/*if*/
	   else
	   {
		   return 0;
	   }/*else*/
   }
   /* Fim função: TAB  &Checa Quadrante */

   /***************************************************************************
*
*  Função: TAB  &Move Peça
*  ****/

   TAB_tpCondRet TAB_MoverPeca( int casaIni, int casaFim, char corJogador ) 
   {
	   int validaCasa;
	   TAB_tpCondRet aux;
	   char corIni=NULL, corFim=NULL;
	   LIS_tppLista ini=NULL, fim=NULL;

	   validaCasa=TAB_ChecaCasa(casaFim, corJogador);

	   if(validaCasa==2)
	   {
		   return TAB_CondRetMovInvalido;
	   }/*if*/

	   if(validaCasa==1)
	   {
		   TAB_RemoverPeca(casaFim);
	   }

	   if(t==NULL)
	   {
		   return TAB_CondRetTabNaoExiste;
	   }/*if*/
	   if((corJogador=='b' && casaFim<casaIni) || (corJogador=='p' && casaIni<casaFim))
	   {
		   return TAB_CondRetMovInvalido;
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

	   fim=IrCasa(casaFim);
	   IrFinalLista(fim) ;

	   PEC_ObterCorPeca ((Peca*) LIS_ObterValor( fim ), &corFim);
	   if(corFim!=NULL && corFim != corJogador )
	   {
		   return TAB_CondRetMovInvalido;
	   }/*if*/

	   LIS_ExcluirElemento( ini ) ;

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
