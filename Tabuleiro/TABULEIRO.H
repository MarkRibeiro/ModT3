/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.H
*  Letras identificadoras:      TAB
*
*  Projeto: Trabalho 3 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data					Observações
*		 4		cgm			13/06				Add func checa casa
*		 3		cgm			13/05				Ajustes finais
*		 2		cgm			11/05				Correção de bugs
*	  	 1		cgm			03/05				Criado o módulo
*
*  $ED Descrição do módulo
*		Módulo que contém as funções que o tabuleiro disponibiliza para 
*		serem usadas pelo jogo. Além disso também são disponibilizadas
*		as condiçoes de retorno das funções em questão.
*
***************************************************************************/

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condições de retorno
*
*
***********************************************************************/

   typedef enum {

         TAB_CondRetOK,
               /* Executou correto */

         TAB_CondRetFaltouMemoria,
               /* Faltou memória ao alocar dados */

         TAB_CondRetTabNaoExiste,
               /* Tabuleiro não existe */

         TAB_CondRetNumCasaNaoExiste,
               /* Numero da casa fornecida não existe */

         TAB_CondRetCasaVazia,
               /* A casa está vazia*/

		 TAB_CondRetMovInvalido,
               /* Movimento da peça inválido*/

   } TAB_tpCondRet ;


/***********************************************************************
*
*	$FC Função: TAB Criar tabuleiro
*
*  $ED Descrição da função
*     Cria um tabuleiro de gamão.
*
*	Assertivas de entrada e saida:
*	Função não recebe parâmetros.
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetFaltouMemoria
*
*************************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro( void ) ;

   /***********************************************************************
*
*	$FC Função: TAB Arrumar tabuleiro
*
*  $ED Descrição da função
*     Organiza o tabuleiro de gamão padrão de forma que todas as peças estejam 
*	  em suas posições iniciais.
*
*	Assertivas de entrada e saida:
*	Função não recebe parâmetros.
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*
*************************************************************************/

   TAB_tpCondRet TAB_ArrumarTabuleiro( void );


/*************************************************************************
*
*	$FC Função: TAB Destruir Tabuleiro
*
*  $ED Descrição da função
*     Remove o tabuleiro existente. Nada ocorre se não houver um tabuleiro
*	  já criado	
*	Assertivas de entrada e saida:
*	Funçao que não recebe parametros e tem valor de retorno void.
*
*************************************************************************/

   void TAB_DestruirTabuleiro( void ) ;


   /*************************************************************************
*
*	$FC Função: TAB Move Peça
*
*  $ED Descrição da função
*     Faz o movimento da peça.
*	
*	Assertivas de entrada e saida:
*	$EP Parâmetros:
*     $P casaIni - Casa de saída da peça
*     $P casaFim - Casa de destino da peça. -1 tira a peça do tabuleiro.
*
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetNumCasaNaoExiste
*		- TAB_CondRetMovInvalido
*
*************************************************************************/

   TAB_tpCondRet TAB_MoverPeca( int casaIni, int casaFim, char corJogador ) ;


/*************************************************************************
*
*	$FC Função: TAB Insere Peça na Casa
*
*  $ED Descrição da função
*     Insere uma peça com a cor escolhida na casa de numero selecionado.
*	
*	Assertivas de entrada e saida:
*	$EP Parâmetros:
*     $P nCasa - número da casa desejada
*     $P cor - cor da peça desejada. 'p' para preta e 'b' para branca
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetNumCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_InserirPecasCasa(int n, char cor, int nCasa ) ;


/*************************************************************************
*
*	$FC Função: TAB Remove Peça
*
*  $ED Descrição da função
*     Remove peça da casa desejada. Se a casa estiver vazia, não ocorre nada.
*	
*	Assertivas de entrada e saida:
*	$EP Parâmetros:
*     $P nCasa - número da casa que se deseja remover.
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetCasaVazia
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_RemoverPeca( int nCasa ) ;

/*************************************************************************
*
*	$FC Função: TAB Printa Tabuleiro
*
*  $ED Descrição da função
*     Printa na tela o tabuleiro ativo.
*
*	Assertivas de entrada e saida:
*	Nao existem parametros nessa função
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_PrintTabuleiro( void ) ;

   /*************************************************************************
*
*	$FC Função: TAB Checa Casa
*
*  $ED Descrição da função
*     Checa a presenca de pecas adversarias na casa em questao.
*
*	Assertivas de entrada e saida:
*	Nao existem parametros nessa função
*
*	$FV Valores de retorno:
*		- 0 se nao houverem pecas adversarias na casa
*		- 1 se houve uma peca adversaria na casa
*		- 2 se houver mais de uma peca adversaria na casa
*
*************************************************************************/
   int TAB_ChecaCasa (int nCasa, char c);

/********** Fim do módulo de definição: Módulo Tabuleiro **********/