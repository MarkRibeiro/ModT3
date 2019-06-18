/***************************************************************************
*
*  $MCD Módulo de definição: Módulo DadoPontos
*
*  Arquivo gerado:              TestaDadoPontos.C
*  Letras identificadoras:      DP
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data    Observações
*       1.00   lb   8/05/2019 Começo da implementacao
*       2.00   lb   10/05/2019 Final do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um lançamento o DadoPontos
*
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct dadosPontos DadosPontos;

/***********************************************************************
*
*  $TC Tipo de dados: DP Condicoes de retorno
*
*
***********************************************************************/
typedef enum {

	DP_CondRetOk = 0,
	/* Executou correto */

	DP_CondRetNaoExiste = 1,
	/* DadosPontos nao incializado */

	DP_CondRetJogadorInvalido = 2,
	/*ID jogador invalido*/

	DP_CondRetJogadorNaoPodeDobrar = 3,
	/*Jogador nao pode dobrar*/

	DP_CondRetValorMaximoDado = 4,
	/*Valor maximo do dado atingido*/

	DP_CondRetFaltouMemoria = 5
	/* Faltou memória ao alocar dados */

} DP_tpCondRet;

/***********************************************************************
*
*  $FC Função: DP Criar DadosPontos
*
*  $ED Descrição da função
*     Inicializa DadosPontos
*
*  $FV Valor retornado
*     DP_CondRetOK
*     DP_CondRetFaltouMemoria
*
***********************************************************************/
DP_tpCondRet DP_criaDadosPontos(void);

/***********************************************************************
*
*  $FC Função: DP Dobrar
*
*  $ED Descrição da função
*     Dobra o valor da partida e troca o ultimo jogador para o jogador que pediu a dobra
*
*	Assertivas de entrada e saida:
*		AE:
*			char jogador contendo 'p' ou 'b'
*
*  $FV Valor retornado
*     DP_CondRetOk
*     DP_CondRetJogadorInvalido
*	  DP_CondRetJogadorNaoPodeDobrar
*	  DP_CondRetValorMaximoDado
*
***********************************************************************/
DP_tpCondRet DP_dobraValor(char jogador);

/***********************************************************************
*
*  $FC Função: DP Modifica pontos
*
*  $ED Descrição da função
*     Incrementa a pontuacao de um dado jogador
*
*	Assertivas de entrada e saida:
*		AE:
*			int valor : inteiro nao negativo
*			char jogador contendo 'p' ou 'b'
*
*
*  $FV Valor retornado
*     DP_CondRetOk
*	  DP_CondRetNaoExiste
*     DP_CondRetJogadorInvalido
*
***********************************************************************/
DP_tpCondRet DP_modificaPontos(int valor, char jogador);

/***********************************************************************
*
*  $FC Função: DP Ler pontos
*
*  $ED Descrição da função
*     Retorna a pontuacao de um dado jogador
*
*	  Assertivas de entrada e saida:
*		AE:
*			char jogador contendo 'p' ou 'b'
*			int *val um endereco que aponta para uma variavel do tipo inteiro
*
*  $FV Valor retornado
*     DP_CondRetOk
*	  DP_CondRetNaoExiste
*     DP_CondRetJogadorInvalido
*
***********************************************************************/
DP_tpCondRet DP_lerPontos(char jogador, int *val);

/***********************************************************************
*
*  $FC Função: DP Ler valor DadosPontos
*
*  $ED Descrição da função
*     Retorna o valor atual do DadosPontos
*
*	  Assertivas de entrada e saida:
*		AE:
*			int *val um endereco que aponta para uma variavel do tipo inteiro
*
*  $FV Valor retornado
*     DP_CondRetOk
*	  DP_CondRetNaoExiste
*
***********************************************************************/
DP_tpCondRet DP_lerValorDadosPontos(int *val);

/***********************************************************************
*
*  $FC Função: DP Ler ultimo jogador

*  $ED Descrição da função
*     Retorna o id do ultimo jogador a dobrar
*
*	  Assertivas de entrada e saida:
*		AE:
*			char cor contendo 'p' ou 'b'
*
*  $FV Valor retornado
*     DP_CondRetOk
*	  DP_CondRetNaoExiste
*
***********************************************************************/
DP_tpCondRet DP_lerUltimoJogador(char *cor);

/***********************************************************************
*
*  $FC Função: DP destroi DadosPontos

*  $ED Descrição da função
*     Libera memoria alocada
*
*	  Assertivas de entrada e saida:
*		AE:
*			<Funcao nao recebe nada>
*
*
*  $FV Valor retornado
*     DP_CondRetOk
*	  DP_CondRetNaoExiste
*
***********************************************************************/
DP_tpCondRet DP_destroiDadosPontos(void);
