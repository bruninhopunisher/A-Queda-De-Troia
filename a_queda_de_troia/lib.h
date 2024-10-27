	#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "menu.h"
#include "introducao1.h"
#include "opcoes.h"
#include "fase01.h"
#include "fase02.h"
#include "fase03.h"

//Variaveis Globais
extern ALLEGRO_TIMER* timer;
extern ALLEGRO_EVENT_QUEUE* evento;
extern ALLEGRO_DISPLAY* display;
extern ALLEGRO_BITMAP* backgroundMenu;
extern ALLEGRO_BITMAP* backgroundIntUm; // Imagem teste
extern ALLEGRO_FONT* fonteMenu;

extern int displayX;
extern int displayY;
extern int mouseX;
extern int mouseY;
extern int intro;
extern int navegacao;
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

//Introdução Um
extern ALLEGRO_BITMAP* fundoHelena;
extern ALLEGRO_BITMAP* fundoParis;
extern ALLEGRO_FONT* fonteIntro1;
extern bool renderizar;

//Fase 1
extern ALLEGRO_BITMAP* backgroundFaseUm;
extern ALLEGRO_BITMAP* personagemHeitor;
extern ALLEGRO_BITMAP* personagemHelena;
extern ALLEGRO_BITMAP* frente_direito;
extern ALLEGRO_BITMAP* frente_esquerdo;
extern int personagemHeitorX;
extern int personagemHeitorY;
extern int personagemHelenaX;
extern int personagemHelenaY;

//Fase 2
extern ALLEGRO_BITMAP* background_f2;
extern ALLEGRO_BITMAP* espada_player1;
extern ALLEGRO_BITMAP* espada_rei_f2;
extern ALLEGRO_BITMAP* barra_vida_cheia;
extern ALLEGRO_BITMAP* barra_vida_baixa;
extern ALLEGRO_BITMAP* barra_vidaRei_100;
extern ALLEGRO_BITMAP* barra_vidaRei_50;
extern int pressionado;
extern int ultPressionado;
//HEITOR
extern int positionX1_heitor;
extern int positionX2_heitor;
extern int positionY1_heitor;
extern int positionY2_heitor;
//PARIS
extern int positionX1_f2;
extern int positionX2_f2;
extern int positionY1_f2;
extern int positionY2_f2;
extern int positionX_espada1;
extern int positionY_espada1;
extern int vidaJogador;
extern bool controleJogador;
extern bool atacando;
//REI MENELAU
extern int positionX_espadaR;
extern int positionY_espadaR;
extern int limiteAtaque;
extern int limiteAtaqueR;
extern int vidaRei;
extern int ataqueReiTimer;


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

//Funções Iniciadoras e Destruidora
void testeInicializar(bool metodo, char* referencia);
void iniciarAddons();
void iniciarConstantes();
void audioJogo(int navegacao);
void imagemIntro(ALLEGRO_BITMAP* image, ALLEGRO_EVENT evento);
void destruidor();

#endif // !LIB_H

