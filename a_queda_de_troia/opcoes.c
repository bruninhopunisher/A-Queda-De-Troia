#include "opcoes.h"

void opcoes(ALLEGRO_EVENT evento) {

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseAxesX = evento.mouse.x;
		mouseAxesY = evento.mouse.y;
	}

	al_draw_bitmap(backgroundOpcoes, 0, 0, 0);
	al_draw_bitmap(semVolume, 500, 300, 0);
	al_draw_bitmap(comVolume, 700, 300, 0);

	al_draw_filled_rectangle(17, 650, 175, 690, al_map_rgb(140, 70, 20));

	//Desenha o botão voltar
	if ((mouseAxesX >= 17 && mouseAxesX <= 175) && (mouseAxesY >= 650 && mouseAxesY <= 690)) {
		al_draw_filled_rectangle(17, 650, 175, 690, al_map_rgb(200, 100, 20));
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
	}
	else if ((mouseAxesX >= 506 && mouseAxesX <= 621) && (mouseAxesY >= 306 && mouseAxesY <= 421)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
	}
	else if ((mouseAxesX >= 706 && mouseAxesX <= 821) && (mouseAxesY >= 306 && mouseAxesY <= 421)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
	}
	else {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	}

	//Verifica se o botão com volume está ativo
	if (boolVolume == true) {
		al_draw_bitmap(comVolumeHover, 700, 300, 0);
		al_draw_bitmap(semVolume, 500, 300, 0);
	}
	else if (boolVolume == false) {
		al_draw_bitmap(comVolume, 700, 300, 0);
		al_draw_bitmap(semVolumeHover, 500, 300, 0);
	}
	else if (boolVolume == true) {
		al_draw_bitmap(comVolumeHover, 700, 300, 0);
		al_draw_bitmap(semVolume, 500, 300, 0);
	}
	else if (boolVolume == false) {
		al_draw_bitmap(comVolume, 700, 300, 0);
		al_draw_bitmap(semVolumeHover, 500, 300, 0);
	}

	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 150, ALLEGRO_ALIGN_CENTRE, "CONFIGURACOES DE AUDIO");
	
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 96, 648, ALLEGRO_ALIGN_CENTRE, "VOLTAR");

	al_flip_display();

	//Pega o click do mouse nos botões
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		//Botão voltar
		if ((mouseAxesX >= 17 && mouseAxesX <= 175) && (mouseAxesY >= 650 && mouseAxesY <= 690)) {
			navegacao = 0;
		}

		//Botão sem volume
		if ((mouseAxesX >= 506 && mouseAxesX <= 621) && (mouseAxesY >= 306 && mouseAxesY <= 421)) {
			boolVolume = false;
		}

		//Botão com volume
		if ((mouseAxesX >= 706 && mouseAxesX <= 821) && (mouseAxesY >= 306 && mouseAxesY)) {
			boolVolume = true;
		}
	}
}
