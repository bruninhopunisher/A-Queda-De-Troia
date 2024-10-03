#include "menu.h"

void static menu(int* navegacao, ALLEGRO_BITMAP* background, ALLEGRO_EVENT evento) {
	al_draw_bitmap(background, 0, 0, 0);
	al_draw_filled_rectangle(540, 330, 740, 390, al_map_rgba_f(0, 0, 0.5, 0.5)); 
	al_draw_filled_rectangle(540, 410, 740, 470, al_map_rgba_f(0, 0, 0.5, 0.5));
	al_draw_filled_rectangle(540, 490, 740, 550, al_map_rgba_f(0, 0, 0.5, 0.5));
	al_draw_filled_rectangle(38, 650, 150, 690, al_map_rgba_f(0, 0, 0.5, 0.5));
	al_flip_display();
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		if (evento.mouse.x >= 540 && evento.mouse.x <= 740 && evento.mouse.y >= 330 && evento.mouse.y <= 390) {
			*navegacao = 1;
		}
		else if (evento.mouse.x >= 540 && evento.mouse.x <= 740 && evento.mouse.y >= 410 && evento.mouse.y <= 470) {
			*navegacao = 2;
		}
		else if (evento.mouse.x >= 540 && evento.mouse.x <= 740 && evento.mouse.y >= 490 && evento.mouse.y <= 550) {
			*navegacao = 3;
		}
	}
}