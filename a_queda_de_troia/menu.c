#include "menu.h"

void menu(ALLEGRO_EVENT evento) {
	al_draw_bitmap(backgroundMenu, 0, 0, 0);
	al_draw_bitmap(logo, 450, 0, 0);

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}

	al_draw_filled_rectangle(555, 400, 735, 460, al_map_rgb(140, 70, 20));
	al_draw_filled_rectangle(555, 480, 735, 540, al_map_rgb(140, 70, 20));
	al_draw_filled_rectangle(555, 560, 735, 620, al_map_rgb(140, 70, 20));
	al_draw_filled_rectangle(40, 650, 150, 690, al_map_rgb(140, 70, 20));

	if ((mouseX >= 555 && mouseX <= 735) && (mouseY >= 400 && mouseY <= 460)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		al_draw_filled_rectangle(555, 400, 735, 460, al_map_rgb(200, 100, 20));
	}
	else if ((mouseX >= 555 && mouseX <= 735) && (mouseY >= 480 && mouseY <= 540)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		al_draw_filled_rectangle(555, 480, 735, 540, al_map_rgb(200, 100, 20));
	}
	else if ((mouseX >= 555 && mouseX <= 735) && (mouseY >= 560 && mouseY <= 620)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		al_draw_filled_rectangle(555, 560, 735, 620, al_map_rgb(200, 100, 20));
	}
	else if ((mouseX >= 40 && mouseX <= 150) && (mouseY >= 650 && mouseY <= 690)) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		al_draw_filled_rectangle(40, 650, 150, 690, al_map_rgb(200, 100, 20));
	}
	else {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	}

	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 645, 407, ALLEGRO_ALIGN_CENTRE, "INICIAR");
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 645, 490, ALLEGRO_ALIGN_CENTRE, "OPCOES");
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 645, 565, ALLEGRO_ALIGN_CENTRE, "CREDITOS");
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 96, 648, ALLEGRO_ALIGN_CENTRE, "SAIR");
	al_flip_display();
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		if ((mouseX >= 555 && mouseX <= 735) && (mouseY >= 400 && mouseY <= 460)) {
			navegacao += 3; // Iniciar
		}
		else if ((mouseX >= 555 && mouseX <= 735) && (mouseY >= 480 && mouseY <= 540)) {
			navegacao += 1; // Opcoes
		}
		else if ((mouseX >= 555 && mouseX <= 735) && (mouseY >= 560 && mouseY <= 620)) {
			navegacao += 2; // Creditos
		}
		else if ((mouseX >= 40 && mouseX <= 150) && (mouseY >= 650 && mouseY <= 690)) {
			rodando = false; // SAIR
		}
	}
}