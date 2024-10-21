#include "introducao1.h"

int introducao1(ALLEGRO_EVENT event) {

	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = event.mouse.x;
		mouseY = event.mouse.y;
	}

	if (intro == 1) {
		al_draw_bitmap(introducao1_1, 0, 0, 0);
		al_draw_filled_rectangle(800, 510, 950, 550, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 875, 510, ALLEGRO_ALIGN_CENTRE, "Proximo");
		al_flip_display();
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 800 && mouseY >= 510 && mouseX <= 950 && mouseY <= 550) {
				intro += 1;
			}
		}
	}
	else if (intro == 2) {
		al_draw_bitmap(introducao1_2, 0, 0, 0);
		al_draw_filled_rectangle(800, 550, 950, 590, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 875, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
		al_flip_display();
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 800 && mouseY >= 550 && mouseX <= 950 && mouseY <= 590) {
				intro += 1;
			}
		}
	}
	else if (intro == 3) {
		al_draw_bitmap(introducao1_3, 0, 0, 0);
		al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
		al_flip_display();
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
				intro += 1;
			}
		}
	}
	else if (intro == 4) {
		al_draw_bitmap(introducao1_4, 0, 0, 0);
		al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
		al_flip_display();
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
				intro += 1;
			}
		}
	}
	else if (intro == 5) {
		al_draw_bitmap(introducao1_5, 0, 0, 0);
		al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
		al_flip_display();
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
				intro += 1;
			}
		}
	}
	else if (intro == 6) {
		al_draw_bitmap(introducao1_6, 0, 0, 0);
		al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
		al_flip_display();
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
				intro += 1;
			}
		}
	}
	else if (intro == 7) {
		al_draw_bitmap(introducao1_7, 0, 0, 0);
		al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
		al_flip_display();
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
				intro = 1; //Reseta a intro para utilizar em outra funcao
				navegacao += 1;
			}
		}
	}
}