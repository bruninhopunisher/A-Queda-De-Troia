#include "menu.h"

void menu(ALLEGRO_EVENT evento) {

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}


	al_draw_bitmap(backgroundMenu, 0, 0, 0);
	al_draw_bitmap(logo, 450, 0, 0);
	al_draw_filled_rectangle((displayX / 2) - 100, (displayY / 2) - 30, (displayX / 2) + 100, (displayY / 2) + 30, al_map_rgb(140, 70, 20));
	al_draw_filled_rectangle(540, 410, 740, 470, al_map_rgb(140, 70, 20));
	al_draw_filled_rectangle(540, 490, 740, 550, al_map_rgb(140, 70, 20));
	if (mouseX >= (displayX / 2) - 100 && mouseX <= (displayX / 2) + 100 && mouseY >= (displayY / 2) - 30 && mouseY <= (displayY / 2) + 30){
		al_draw_filled_rectangle((displayX / 2) - 100, (displayY / 2) - 30, (displayX / 2) + 100, (displayY / 2) + 30, al_map_rgb(200, 100, 20));
	}else {
		if (mouseX >= (displayX / 2) - 100 && mouseX <= (displayX / 2) + 100 && mouseY >= 410 && mouseY <= 470) {
	 		al_draw_filled_rectangle((displayX / 2) - 100, 410, (displayX / 2) + 100, 470, al_map_rgb(200, 100, 20));
		}
		else {
			if (mouseX >= (displayX / 2) - 100 && mouseX <= (displayX / 2) + 100 && mouseY >= 490 && mouseY <= 550) {
			 	al_draw_filled_rectangle((displayX / 2) - 100, 490, (displayX / 2) + 100, 550, al_map_rgb(200, 100, 20));
			}
		}
	}
	al_draw_filled_rectangle(38, 650, 150, 690, al_map_rgb(140, 70, 20)); 
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), (displayX / 2), (displayY / 2) - 25, ALLEGRO_ALIGN_CENTRE, "INICIAR"); 
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), (displayX / 2), (displayY / 2) + 55, ALLEGRO_ALIGN_CENTRE, "OPCOES");
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), (displayX / 2), (displayY / 2) + 135, ALLEGRO_ALIGN_CENTRE, "CREDITOS");
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 96, 648, ALLEGRO_ALIGN_CENTRE, "SAIR");
	al_flip_display();
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		if (evento.mouse.x >= (displayX / 2) - 100 && evento.mouse.x <= (displayX / 2) + 100 && evento.mouse.y >= (displayY / 2) - 30 && evento.mouse.y <= (displayY / 2) + 30) {
			navegacao += 3; // Iniciar
		}
		else if (evento.mouse.x >= (displayX / 2) - 100 && evento.mouse.x <= (displayX / 2) + 100 && evento.mouse.y >= 410 && evento.mouse.y <= 470) {
			navegacao += 1; // Opcoes
		}
		else if (evento.mouse.x >= (displayX / 2) - 100 && evento.mouse.x <= (displayX / 2) + 100 && evento.mouse.y >= 490 && evento.mouse.y <= 550) {
			navegacao += 2; // Creditos
		}
		else if (evento.mouse.x >= 38 && evento.mouse.x <= 150 && evento.mouse.y >= 650 && evento.mouse.y <= 690) {
			rodando = false;
		}
	}
}