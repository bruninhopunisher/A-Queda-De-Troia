#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "menu.h"
#include "opcoes.h"
#include "creditos.h"
#include "introducao1.h"
#include "introducao2.h"
#include "introducao3.h"
#include "introducao4.h"
#include "fase01.h"
#include "fase02.h"
#include "fase03.h"
#include "fase04.h"

//Variaveis Globais
extern ALLEGRO_TIMER* timer;
extern ALLEGRO_EVENT_QUEUE* evento;
extern ALLEGRO_DISPLAY* display;
extern ALLEGRO_BITMAP* backgroundMenu;
extern ALLEGRO_BITMAP* logo;
extern ALLEGRO_FONT* fonteMenu;
extern ALLEGRO_FONT* font;

extern bool iniciarConst;
extern int displayX;
extern int displayY;
extern int mouseX;
extern int mouseY;
extern int intro;
extern int navegacao;
extern int mouseAxesX;
extern int mouseAxesY;
extern bool rodando;
extern bool boolVolume;

//Audios e Musicas
extern ALLEGRO_SAMPLE* audioMenu;

//Opções
extern ALLEGRO_BITMAP* backgroundOpcoes;
extern ALLEGRO_BITMAP* comVolume;
extern ALLEGRO_BITMAP* semVolume;
extern ALLEGRO_BITMAP* comVolumeHover;
extern ALLEGRO_BITMAP* semVolumeHover;

//Creditos
extern ALLEGRO_BITMAP* backgroundCreditos;
extern char nomes[13][100];
extern int credY[13];

//Introdução 1
extern ALLEGRO_BITMAP* fundo1Intro1;
extern ALLEGRO_BITMAP* fundo2Intro1;
extern ALLEGRO_BITMAP* fundo3Intro1;
extern ALLEGRO_BITMAP* fundoHelena;
extern ALLEGRO_BITMAP* fundoParis;
extern ALLEGRO_FONT* fonteIntro1;
extern ALLEGRO_BITMAP* mapaAtenas;
extern ALLEGRO_BITMAP* mapaTroia;
extern ALLEGRO_BITMAP* mapaGrecia;
extern bool renderizar;

//Introdução 2
extern ALLEGRO_BITMAP* fundoAgamenom;
extern ALLEGRO_BITMAP* fundoMenelau;
extern ALLEGRO_BITMAP* fundoExplicacao;

//Introdução 3
extern ALLEGRO_BITMAP* pagina1;
extern ALLEGRO_BITMAP* pagina2;
extern ALLEGRO_BITMAP* pagina3;
extern ALLEGRO_BITMAP* pagina4;

//Introdução 4
extern ALLEGRO_BITMAP* pag1;
extern ALLEGRO_BITMAP* pag2;
extern ALLEGRO_BITMAP* pag3;
extern ALLEGRO_BITMAP* pag4;

//Fase 1
extern ALLEGRO_BITMAP* backgroundFaseUm;
extern ALLEGRO_BITMAP* personagemHeitor;
extern ALLEGRO_BITMAP* personagemHelena;
extern ALLEGRO_BITMAP* frente_direito;
extern ALLEGRO_BITMAP* frente_esquerdo;
extern ALLEGRO_BITMAP* ParisCimaNormal;
extern ALLEGRO_BITMAP* ParisCimaEsq;
extern ALLEGRO_BITMAP* ParisCimaDir;
extern ALLEGRO_BITMAP* ParisBaixoNormal;
extern ALLEGRO_BITMAP* ParisBaixoEsq;
extern ALLEGRO_BITMAP* ParisBaixoDir;
extern ALLEGRO_BITMAP* ParisEsqNormal;
extern ALLEGRO_BITMAP* ParisEsqEsq;
extern ALLEGRO_BITMAP* ParisEsqDir;
extern ALLEGRO_BITMAP* ParisDirNormal;
extern ALLEGRO_BITMAP* ParisDirEsq;
extern ALLEGRO_BITMAP* ParisDirDir;
extern ALLEGRO_BITMAP* sprite_atual;
extern int personagemParisX;
extern int personagemParisY;
extern int personagemHeitorX;
extern int personagemHeitorY;
extern int personagemHelenaX;
extern int personagemHelenaY;
bool esta_movendo;
extern int direcaoX;
extern int direcaoY;
extern int contador_passos;
extern int atraso_animacao;
extern int ultima_direcaoX;
extern int ultima_direcaoY;

//Fase 2
extern ALLEGRO_BITMAP* background_f2;
extern ALLEGRO_BITMAP* espada_player1;
extern ALLEGRO_BITMAP* espada_rei_f2;
extern ALLEGRO_BITMAP* barra_vida_cheia;
extern ALLEGRO_BITMAP* barra_vida_baixa;
extern ALLEGRO_BITMAP* barra_vidaRei_100;
extern ALLEGRO_BITMAP* barra_vidaRei_50;
extern ALLEGRO_BITMAP* soldadosEsparta;
extern ALLEGRO_BITMAP* soldadosTroia;
extern int pressionado;
extern int ultPressionado;
extern int movimento;

//typedef struct {
//    //Posicionado para Cima
//    ALLEGRO_BITMAP* CimaParado;
//    ALLEGRO_BITMAP* CimaPeEsquerdo1;
//    ALLEGRO_BITMAP* CimaPeEsquerdo2;
//    ALLEGRO_BITMAP* CimaPeDireito1;
//    ALLEGRO_BITMAP* CimaPeDireito2;
//    //Posicionado para Esquerda
//    ALLEGRO_BITMAP* EsqParado;
//    ALLEGRO_BITMAP* EsqPeEsquerdo1;
//    ALLEGRO_BITMAP* EsqPeEsquerdo2;
//    ALLEGRO_BITMAP* EsqPeDireito1;
//    ALLEGRO_BITMAP* EsqPeDireito2;
//    //Posicionado para Direita
//    ALLEGRO_BITMAP* DirParado;
//    ALLEGRO_BITMAP* DirPeEsquerdo1;
//    ALLEGRO_BITMAP* DirPeEsquerdo2;
//    ALLEGRO_BITMAP* DirPeDireito1;
//    ALLEGRO_BITMAP* DirPeDireito2;
//    //Posicionado para Baixo
//    ALLEGRO_BITMAP* BaixoParado;
//    ALLEGRO_BITMAP* BaixoPeEsquerdo1;
//    ALLEGRO_BITMAP* BaixoPeEsquerdo2;
//    ALLEGRO_BITMAP* BaixoPeDireito1;
//    ALLEGRO_BITMAP* BaixoPeDireito2;
//    char nome[20];
//    int posicaoX;
//    int posicaoY;
//    int vida;
//} Personagem;

//HEITOR
extern int positionX1_heitor;
extern int positionX2_heitor;
extern int positionY1_heitor;
extern int positionY2_heitor;
//PARIS
extern ALLEGRO_BITMAP* ParisBaixoEsq;
extern ALLEGRO_BITMAP* ParisBaixoDir;
extern ALLEGRO_BITMAP* ParisBaixoNormal;
extern ALLEGRO_BITMAP* ParisEsqDir;
extern ALLEGRO_BITMAP* ParisEsqEsq;
extern ALLEGRO_BITMAP* ParisEsqNormal;
extern ALLEGRO_BITMAP* ParisCimaNormal;
extern ALLEGRO_BITMAP* ParisCimaEsq;
extern ALLEGRO_BITMAP* ParisCimaDir;
extern ALLEGRO_BITMAP* ParisDirNormal;
extern ALLEGRO_BITMAP* ParisDirEsq;
extern ALLEGRO_BITMAP* ParisDirDir;
extern ALLEGRO_BITMAP* ParisAtaqueB1;
extern ALLEGRO_BITMAP* ParisAtaqueB2;
extern ALLEGRO_BITMAP* ParisAtaqueB3;
extern ALLEGRO_BITMAP* ParisAtaqueB4;
extern int positionX1_f2;
extern int positionY1_f2;
extern int positionX_espada1;
extern int positionY_espada1;
extern int vidaJogador;
extern bool controleJogador;
extern bool atacando;
//REI MENELAU
extern ALLEGRO_BITMAP* MenelauEsqDirN;
extern ALLEGRO_BITMAP* MenelauEsqDir1;
extern ALLEGRO_BITMAP* MenelauEsqDir2;
extern ALLEGRO_BITMAP* MenelauEsqDir3;
extern ALLEGRO_BITMAP* MenelauCimaN;
extern ALLEGRO_BITMAP* MenelauCima1;
extern ALLEGRO_BITMAP* MenelauCima2;
extern ALLEGRO_BITMAP* MenelauCima3;
extern ALLEGRO_BITMAP* MenelauBaixoN;
extern ALLEGRO_BITMAP* MenelauBaixo1;
extern ALLEGRO_BITMAP* MenelauBaixo2;
extern ALLEGRO_BITMAP* MenelauBaixo3;
extern int positionReiX;
extern int positionReiY;
extern int limiteAtaque;
extern int movimentoRei;
extern int vidaReiX;
extern int ataqueReiTimer;
extern int pontoAndarX;
extern int pontoAndarY;


//Fase 3
extern ALLEGRO_BITMAP* imgPuzzle;
extern ALLEGRO_BITMAP* imgFundoPuzzle;
extern ALLEGRO_BITMAP* puzzle1;
extern ALLEGRO_BITMAP* puzzle2;
extern ALLEGRO_BITMAP* puzzle3;
extern ALLEGRO_BITMAP* puzzle4;
extern ALLEGRO_BITMAP* puzzle5;
extern ALLEGRO_BITMAP* puzzle6;
extern ALLEGRO_BITMAP* puzzle7;
extern ALLEGRO_BITMAP* puzzle8;
extern ALLEGRO_BITMAP* puzzle9;
extern ALLEGRO_BITMAP* puzzle10;
extern ALLEGRO_BITMAP* puzzle11;
extern ALLEGRO_BITMAP* puzzle12;
extern ALLEGRO_BITMAP* puzzle13;
extern ALLEGRO_BITMAP* puzzle14;
extern ALLEGRO_BITMAP* puzzle15;
extern ALLEGRO_BITMAP* puzzle16;
extern ALLEGRO_BITMAP* puzzle17;
extern ALLEGRO_BITMAP* puzzle18;
extern ALLEGRO_BITMAP* puzzle19;
extern ALLEGRO_BITMAP* puzzle20;
extern ALLEGRO_BITMAP* puzzle21;
extern ALLEGRO_BITMAP* puzzle22;
extern ALLEGRO_BITMAP* puzzle23;
extern ALLEGRO_BITMAP* puzzle24;
extern ALLEGRO_BITMAP* puzzle25;
extern int contadorCreditos;

// Armazena as informações de cada peça do puzzle
typedef struct {
    int id;
    int pos_inicial_x;
    int pos_inicial_y;
    int pos_atual_x;
    int pos_atual_y;
    bool selecionada;
} infoPecas;

typedef struct {
    infoPecas pecas[25];
    int totalPecas;
} Puzzle;

// Armazena as informações de cada quadrante do puzzle
typedef struct {
    int idPecaRecebida;
	int id;
	int X;
	int Y;
	bool contemPeca;
} infoQuadrante;

typedef struct {
    infoQuadrante quadrantes[25];
	int totalQuadrantes;
} Quadrante;

// Armazena as informações de cada posição inicial do puzzle
typedef struct {
	int id;
	int x;
	int y;
	bool contemPeca;
} posicaoInicial;

typedef struct {
	posicaoInicial posicoes[26];
} PosicaoInicialStruct;

extern PosicaoInicialStruct posicoesIniciais;
extern Puzzle pecasPuzzle;
extern Quadrante quadrantePuzzle;

//extern ALLEGRO_BITMAP* imagensPuzzle[25];
extern bool verificaPuzzle;
extern int posicaoInicialX[25];
extern int posicaoInicialY[25];
extern int swapX;
extern int swapY;
extern bool swapAtivo;
extern int idPeca;
extern int idPecaRetirada;
extern int idQuadrante;
extern indice;
extern bool pecaPosicionada;
extern bool pecaSelecionada;
extern bool first;
extern int marcacaoX;
extern int marcacaoY;
extern int guardaIdQuadrante[26];
extern int guardaIdPeca[25];
extern int arrayVerificador[25];
extern int somaVerificadora;
extern int somaPosicao;
extern int indiceQuadrante;
extern int swapDaPeca;
extern int contg;
extern bool next;
extern nextInt;
extern bool acabouDeSerPosicionada;
extern int btoVolta;
extern int swapPecaX;
extern int swapPecaY;
extern int swapIDPeca;
extern int swapIDQuadrante;
extern int salvaIndice[25];
extern int swapIndice;

//Fase 4
extern ALLEGRO_BITMAP* backgroundFase04;
extern ALLEGRO_BITMAP* aquiles_Baixo; //Destruido
extern ALLEGRO_BITMAP* aquiles_Descendo_0; //Destruido
extern ALLEGRO_BITMAP* aquiles_Descendo_1; //Destruido
extern ALLEGRO_BITMAP* aquiles_Lado_0; //Destruido
extern ALLEGRO_BITMAP* aquiles_Lado_1; //Destruido
extern ALLEGRO_BITMAP* aquiles_Cima; //Destruido
extern ALLEGRO_BITMAP* aquiles_Subindo_0;//Destruido
extern ALLEGRO_BITMAP* aquiles_Subindo_1;//Destruido
extern ALLEGRO_BITMAP* aquiles_Atual; //NÃO PRECISA DESTRUIR
extern ALLEGRO_BITMAP* Lanc_Lado_0;//Destruido
extern ALLEGRO_BITMAP* Lanc_Lado_1;//Destruido
extern ALLEGRO_BITMAP* Lanc_Atual[7];//NÃO PRECISA DESTRUIR
extern ALLEGRO_BITMAP* arq_Frente_1; //Destruido
extern ALLEGRO_BITMAP* arq_Frente_2; //Destruido
extern ALLEGRO_BITMAP* arq_Costas_1; //Destruido
extern ALLEGRO_BITMAP* arq_Costas_2; //Destruido
extern ALLEGRO_BITMAP* arq_Atual[32]; //NÃO PRECISA DESTRUIR
extern ALLEGRO_BITMAP* flecha; //Destruido
extern ALLEGRO_TIMER* timerFase04; //Destruido
extern int tempoRestante;
extern bool timerOn;
extern bool gameOver;
extern int iniVel; //velocidade do inimigo
//player
extern int playX;
extern int playY;
extern int playZ;
extern int PlayVel;
extern int vidaF4;
extern int PlayPosicao;
extern bool andando;
//Lanceiro
extern int qtdLanc;
extern int lancX[7];
extern int lancY[7];
extern int lancZ[7];
extern int atraso_animacao_Lanc[7];
extern int contador_passos_Lanc[7];
//Arqueiros
extern int qtdArq;
extern int arqX[32];
extern int arqY[32];
extern int arqZ[32];
extern int atraso_animacao_Arq[32];
extern int contador_passos_Arq[32];
extern bool atirando_Arq[32];
//Flechas
extern int qtdFle;
extern int fleX[32];
extern int fleY[32];
extern int fleZ[32];
//FimFase4

//telas finais
extern ALLEGRO_BITMAP* vitoria;
extern ALLEGRO_BITMAP* derrota;


//Movimentação Jogador
void movimentarPlayer(ALLEGRO_EVENT evento,int* posicaoX,int* posicaoY);

//Movimento Sprite
void movimentoSprite(ALLEGRO_BITMAP* baixoN, ALLEGRO_BITMAP* baixoE, ALLEGRO_BITMAP* baixoD,
    ALLEGRO_BITMAP* esquerdaN, ALLEGRO_BITMAP* esquerdaE, ALLEGRO_BITMAP* esquerdaD,
    ALLEGRO_BITMAP* cimaN, ALLEGRO_BITMAP* cimaE, ALLEGRO_BITMAP* cimaD,
    ALLEGRO_BITMAP* direitaN, ALLEGRO_BITMAP* direitaE, ALLEGRO_BITMAP* direitaD,
    ALLEGRO_BITMAP* ataqueBaixo1, ALLEGRO_BITMAP* ataqueBaixo2, ALLEGRO_BITMAP* ataqueBaixo3, ALLEGRO_BITMAP* ataquebaixo4,
    int posicaoX, int posicaoY);

//Funções Iniciadoras e Destruidora
void testeInicializar(bool metodo, char* referencia);
void iniciarAddons();
void iniciarConstantes();
void audioJogo(int navegacao);
void imagemIntro(ALLEGRO_BITMAP* image, ALLEGRO_EVENT evento);
void destruidor();

#endif // !LIB_H
