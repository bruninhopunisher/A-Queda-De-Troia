#include "introducao01.h"

void introducao01(int* navegacao,ALLEGRO_BITMAP* introducao01_1, ALLEGRO_EVENT event, ALLEGRO_BITMAP* introducao01_2) {

	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = event.mouse.x;
		mouseY = event.mouse.y;
	}
	switch (intru01)
	{
	case 1:
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			mouseX = event.mouse.x;
			mouseY = event.mouse.y;
		}
		al_draw_bitmap(introducao01_1, 0, 0, 0);
		al_draw_filled_rectangle(800, 510, 950, 550, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 875, 510, ALLEGRO_ALIGN_CENTRE, "Proximo");
		al_flip_display();
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 800 && mouseY >= 510 && mouseX <= 950 && mouseY <= 550) {
				navegacao += 1;
			}
		}
		break;
	case 2:
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			mouseX = event.mouse.x;
			mouseY = event.mouse.y;
		}
		al_draw_bitmap(introducao01_2, 0, 0, 0);
		al_draw_filled_rectangle(800, 550, 950, 590, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 875, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
		al_flip_display();
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 800 && mouseY >= 550 && mouseX <= 950 && mouseY <= 590) {
				navegacao += 1;
			}
		}
		break;
	case 3:
		al_draw_bitmap(backgroundIntUm, 0, 0, 0);
		al_flip_display();
		break;
	default:
		break;
	}

	


}