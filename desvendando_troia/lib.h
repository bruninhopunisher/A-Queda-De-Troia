#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

extern ALLEGRO_TIMER* timer; 
extern ALLEGRO_EVENT_QUEUE* evento;
extern ALLEGRO_DISPLAY* display;
extern ALLEGRO_BITMAP* backgroundMenu;
extern ALLEGRO_BITMAP* backgroundIntUm;

void static testeInicializar(bool metodo, char* referencia);

void static iniciarAddons();
void static iniciarConstantes();

#endif // !LIB_H

