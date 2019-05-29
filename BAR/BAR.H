/***************************************************************************
*  $MCD Módulo de definição: Módulo bar
*
*  Arquivo gerado:              BAR.H
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
*  $ED Descrição do módulo
*     Este módulo implementa a retirada e o retorno de uma
*	  peca.
*
***************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condicoes de retorno
*
*
***********************************************************************/

	typedef enum {
			BAR_CondRetOK = 0 ,
	               /* Executou correto */

	        BAR_CondRetFaltouMemoria = 1 ,
	               /* Faltou memória ao alocar dados */
	     } BAR_tpCondRet ;

/***********************************************************************
*
*  $FC Função: BAR retira peca
*
*  $ED Descrição da função
*     
*     
*
*  $FV Valor retornado
*     
*     
*
***********************************************************************/

	BAR_tpCondRet BAR_RetiraPeca();

/***********************************************************************
*
*  $FC Função: BAR retorna peca
*
*  $ED Descrição da função
*     
*     
*
*  $FV Valor retornado
*     
*     
*
***********************************************************************/

	BAR_tpCondRet BAR_RetornaPeca();