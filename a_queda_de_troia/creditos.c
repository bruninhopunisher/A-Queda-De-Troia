#include "lib.h"
void creditos(ALLEGRO_EVENT evento) {
	al_draw_bitmap(backgroundCreditos, 0, 0, 0); //Background 1280x720
	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}
	al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgba(50, 50, 50, 128));
	for (int i = 0; i < 13; i++) {
		al_draw_textf(fonteMenu, al_map_rgb(255, 255, 255), 640, credY[i], ALLEGRO_ALIGN_CENTRE, "%s", nomes[i]);
		if (credY[0] > 10) {
			credY[i] -= 1;
		}
	}
	al_draw_filled_rectangle(17, 650, 175, 690, al_map_rgb(140, 70, 20));
	if ((mouseX >= 17 && mouseX <= 175) && (mouseY >= 650 && mouseY <= 690)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		al_draw_filled_rectangle(17, 650, 175, 690, al_map_rgb(200, 100, 20));
	}
	else {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	}
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 96, 648, ALLEGRO_ALIGN_CENTRE, "VOLTAR");
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		if ((mouseX >= 17 && mouseX <= 175) && (mouseY >= 650 && mouseY <= 690)) {
			credY[0] = 720;
			credY[1] = 790;
			credY[2] = 860;
			credY[3] = 900;
			credY[4] = 985;
			credY[5] = 1015;
			credY[6] = 1085;
			credY[7] = 1115;
			credY[8] = 1150;
			credY[9] = 1185;
			credY[10] = 1215;
			credY[11] = 1295;
			credY[12] = 1345;
			navegacao = 0;
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
		}
	}
	al_flip_display();
}