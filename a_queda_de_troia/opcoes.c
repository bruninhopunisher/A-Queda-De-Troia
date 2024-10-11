#include "opcoes.h"

void opcoes(int* navegacao, ALLEGRO_BITMAP* background, ALLEGRO_EVENT evento) {
	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}

	al_draw_bitmap(background, 0, 0, 0);
	al_draw_bitmap(semVolume, 500, 300, 0);
	al_draw_bitmap(comVolume, 700, 300, 0);
	
	al_draw_filled_rectangle(20, 650, 180, 690, al_map_rgb(238, 173, 45));

	if ((mouseX >= 20 && mouseX <= 180) && (mouseY >= 650 && mouseY <= 690)) {
		al_draw_filled_rectangle(20, 650, 180, 690, al_map_rgb(255, 165, 0));
	}

	if ((mouseX >= 506 && mouseX <= 621) && (mouseY >= 306 && mouseY <= 421)) {/*
		al_draw_filled_rounded_rectangle(504, 305, 624, 424, 27, 27, al_map_rgb(255, 165, 0));*/
		al_draw_bitmap(semVolumeHover, 500, 300, 0);

	}
	if ((mouseX >= 706 && mouseX <= 821) && (mouseY >= 306 && mouseY <= 421)) {
		//al_draw_filled_rounded_rectangle(703, 305, 824, 424, 27, 27, al_map_rgb(255, 165, 0));
		al_draw_bitmap(comVolumeHover, 700, 300, 0);
	}

	//if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
	//	mouseX = evento.mouse.x;
	//	mouseY = evento.mouse.y;
	//	printf("\n%d X\n", mouseX);
	//	printf("%d Y\n", mouseY);
	//}

	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 150, ALLEGRO_ALIGN_CENTRE, "CONFIGURACOES DE AUDIO");
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 100, 648, ALLEGRO_ALIGN_CENTRE, "VOLTAR");
	al_flip_display();

	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		if (evento.mouse.x >= 20 && evento.mouse.x <= 180 && evento.mouse.y >= 650 && evento.mouse.y <= 690) {
			*navegacao = 0;
		}
	}
}