#include "fase04.h"

void fase4(ALLEGRO_EVENT evento) {

	al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0));
	al_draw_bitmap(player, playX, playY, 0);
	al_draw_bitmap(inimigo, iniX, iniY, 0);
	al_flip_display();

	if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
		playY -= 10;
	}
	if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
		playY += 10;
	}
	if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
		playX -= 10;
	}
	if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
		playX += 10;
	}

	iniX -= 2;

	if (iniX <= -125) {
		iniX = 1285;
	}
}