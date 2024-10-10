#include "opcoes.h"

void opcoes(int* navegacao, ALLEGRO_BITMAP* background, ALLEGRO_EVENT evento) {
	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}

	al_draw_bitmap(background, 0, 0, 0);
	al_draw_bitmap(semVolume, 740, 320, 0);
	al_draw_bitmap(comVolume, 540, 320, 0);
	
	al_draw_filled_rectangle(20, 650, 180, 690, al_map_rgb(238, 173, 45));

	if ((mouseX >= 20 && mouseX <= 180) && (mouseY >= 650 && mouseY <= 690)) {
		al_draw_filled_rectangle(20, 650, 180, 690, al_map_rgb(255, 165, 0));
	}

	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 150, ALLEGRO_ALIGN_CENTRE, "CONFIGURACOES DE AUDIO");
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 100, 648, ALLEGRO_ALIGN_CENTRE, "VOLTAR");
	al_flip_display();

	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		if (evento.mouse.x >= 20 && evento.mouse.x <= 180 && evento.mouse.y >= 650 && evento.mouse.y <= 690) {
			*navegacao = 0;
		}
	}
}