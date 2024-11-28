#include "lib.h"
void creditos(ALLEGRO_EVENT evento) {
	al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0)); //fundo preto
	for (int i = 0; i < 11; i++) {
		al_draw_textf(fonteMenu, al_map_rgb(255, 255, 255), 640, credY[i], ALLEGRO_ALIGN_CENTRE, "%s", nomes[i]);
		credY[i] -= 1;
		if (credY[10] < -50) {
			navegacao = 0;
		}
	}
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && evento.mouse.x >= 38 && evento.mouse.x <= 150 
		&& evento.mouse.y >= 620 && evento.mouse.y <= 660){
		navegacao = 0;
	}
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 96, 618, ALLEGRO_ALIGN_CENTRE, "MENU");
	al_flip_display();
}