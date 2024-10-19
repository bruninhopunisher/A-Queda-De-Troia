#include "opcoes.h"

void opcoes(int *navegacao, ALLEGRO_EVENT evento) {

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}

	al_draw_bitmap(backgroundOpcoes, 0, 0, 0);
	al_draw_bitmap(semVolume, 500, 300, 0);
	al_draw_bitmap(comVolume, 700, 300, 0);
	
	al_draw_filled_rectangle(20, 650, 180, 690, al_map_rgb(238, 173, 45));

	//Desenha o botão voltar
	if ((mouseX >= 20 && mouseX <= 180) && (mouseY >= 650 && mouseY <= 690)) {
		al_draw_filled_rectangle(20, 650, 180, 690, al_map_rgb(255, 165, 0));
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
	}
	else if ((mouseX != 20 && mouseX != 180) && (mouseY != 650 && mouseY != 690)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	}

	//Mão ativa do botão sem volume
	if ((mouseX >= 506 && mouseX <= 621) && (mouseY >= 306 && mouseY <= 421)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
	}

	//Mão ativa do botão com volume
	if ((mouseX >= 706 && mouseX <= 821) && (mouseY >= 306 && mouseY <= 421)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
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

	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 150, ALLEGRO_ALIGN_CENTRE, "CONFIGURACOES DE AUDIO");
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 100, 648, ALLEGRO_ALIGN_CENTRE, "VOLTAR");
	al_flip_display();

	//Pega o click do mouse nos botões
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		//Botão voltar
		if (evento.mouse.x >= 20 && evento.mouse.x <= 180 && evento.mouse.y >= 650 && evento.mouse.y <= 690) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
			*navegacao = 0;
		}

		//Botão sem volume
		if ((evento.mouse.x >= 506 && evento.mouse.x <= 621) && (evento.mouse.y >= 306 && evento.mouse.y <= 421)) {
			boolVolume = false;
			//al_stop_samples();
		}

		//Botão com volume
		if ((evento.mouse.x >= 706 && evento.mouse.x <= 821) && (evento.mouse.y >= 306 && evento.mouse.y <= 421)) {
			boolVolume = true;
		}
	}
}
