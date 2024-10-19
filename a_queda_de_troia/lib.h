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

//Variaveis Globais
extern ALLEGRO_TIMER* timer;
extern ALLEGRO_EVENT_QUEUE* evento;
extern ALLEGRO_DISPLAY* display;
extern ALLEGRO_BITMAP* backgroundMenu;

//Opções
extern ALLEGRO_BITMAP* backgroundOpcoes;
extern ALLEGRO_BITMAP* comVolume;
extern ALLEGRO_BITMAP* semVolume;
extern ALLEGRO_BITMAP* comVolumeHover;
extern ALLEGRO_BITMAP* semVolumeHover;

//Introdução Um
extern ALLEGRO_BITMAP* introducao1_1;
extern ALLEGRO_BITMAP* introducao1_2;
extern ALLEGRO_BITMAP* introducao1_3;
extern ALLEGRO_BITMAP* introducao1_4;
extern ALLEGRO_BITMAP* introducao1_5;
extern ALLEGRO_BITMAP* introducao1_6;
extern ALLEGRO_BITMAP* introducao1_7;

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
extern int pressionado;
extern int positionX1_f2;
extern int positionX2_f2;
extern int positionY1_f2;
extern int positionY2_f2;

//Audios e Musicas
extern ALLEGRO_SAMPLE* musicaPadrao;

//Demais
extern ALLEGRO_BITMAP* backgroundIntUm; // Imagem teste
extern ALLEGRO_FONT* fonteMenu;

//Variáveis Globais
extern int displayX;
extern int displayY;
extern int mouseX;
extern int mouseY;
extern int intro;
extern int navegacao;
extern bool rodando;
extern bool boolVolume;

//Funções Iniciadoras e Destruidora
void testeInicializar(bool metodo, char* referencia);
void iniciarAddons();
void iniciarConstantes();
void audioJogo(int navegacao);
void destruidor();

#endif // !LIB_H

