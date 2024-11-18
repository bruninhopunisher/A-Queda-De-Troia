#include "opcoes.h"

void opcoes(ALLEGRO_EVENT evento) {

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseAxesX = evento.mouse.x;
		mouseAxesY = evento.mouse.y;
	}

	al_draw_bitmap(backgroundOpcoes, 0, 0, 0);
	al_draw_bitmap(semVolume, 500, 300, 0);
	al_draw_bitmap(comVolume, 700, 300, 0);
	
	al_draw_filled_rectangle(20, 650, 180, 690, al_map_rgb(238, 173, 45));

	//Desenha o bot�o voltar
	if ((mouseAxesX >= 20 && mouseAxesX <= 180) && (mouseAxesY >= 650 && mouseAxesY <= 690)) {
		al_draw_filled_rectangle(20, 650, 180, 690, al_map_rgb(255, 165, 0));
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
	}
	else if ((mouseAxesX != 20 && mouseAxesX != 180) && (mouseAxesY != 650 && mouseAxesY != 690)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	}

	//M�o ativa do bot�o sem volume
	if ((mouseAxesX >= 506 && mouseAxesX <= 621) && (mouseAxesY >= 306 && mouseAxesY <= 421)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
	}

	//M�o ativa do bot�o com volume
	if ((mouseAxesX >= 706 && mouseAxesX <= 821) && (mouseAxesY >= 306 && mouseAxesY <= 421)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
	}

	//Verifica se o bot�o com volume est� ativo
	if (boolVolume == true) {
		al_draw_bitmap(comVolumeHover, 700, 300, 0);
		al_draw_bitmap(semVolume, 500, 300, 0);
	}
	else if (boolVolume == false) {
		al_draw_bitmap(comVolume, 700, 300, 0);
		al_draw_bitmap(semVolumeHover, 500, 300, 0);
	}

	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 150, ALLEGRO_ALIGN_CENTRE, "CONFIGURACOES DE AUDIO");
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 100, 648, ALLEGRO_ALIGN_CENTRE, "VOLTAR");
	al_flip_display();

	//Pega o click do mouse nos bot�es
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		//Bot�o voltar
		if (evento.mouse.x >= 20 && evento.mouse.x <= 180 && evento.mouse.y >= 650 && evento.mouse.y <= 690) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
			navegacao = 0;
		}

		//Bot�o sem volume
		if ((evento.mouse.x >= 506 && evento.mouse.x <= 621) && (evento.mouse.y >= 306 && evento.mouse.y <= 421)) {
			boolVolume = false;
		}

		//Bot�o com volume
		if ((evento.mouse.x >= 706 && evento.mouse.x <= 821) && (evento.mouse.y >= 306 && evento.mouse.y <= 421)) {
			boolVolume = true;
		}
	}
}
