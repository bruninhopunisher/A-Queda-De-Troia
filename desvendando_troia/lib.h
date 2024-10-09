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

extern ALLEGRO_TIMER* timer; 
extern ALLEGRO_EVENT_QUEUE* evento;
extern ALLEGRO_DISPLAY* display;
extern ALLEGRO_BITMAP* backgroundMenu;
extern ALLEGRO_BITMAP* introducao01_1;
extern ALLEGRO_BITMAP* introducao01_2;
extern ALLEGRO_BITMAP* introducao01_3;
extern ALLEGRO_BITMAP* introducao01_4;
extern ALLEGRO_BITMAP* introducao01_5;
extern ALLEGRO_BITMAP* introducao01_6;
extern ALLEGRO_BITMAP* introducao01_7;
extern ALLEGRO_BITMAP* backgroundIntUm;
extern ALLEGRO_FONT* fonteMenu;

extern int displayX;
extern int displayY;
extern int mouseX;
extern int mouseY;
extern int intru01;

void testeInicializar(bool metodo, char* referencia);
void iniciarAddons();
void iniciarConstantes();

#endif // !LIB_H

