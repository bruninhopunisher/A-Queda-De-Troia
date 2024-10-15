#include "fase2.h" 

void fase2(int* navegacao, ALLEGRO_BITMAP* backgroundf2, int* positionX1, int* positionX2, int* positionY1, int* positionY2, ALLEGRO_EVENT evento, int* pressionado) {
	al_draw_bitmap(backgroundf2, 0, 0, 0);
	//SOLDADOS DE BAIXO
	al_draw_filled_rectangle(135, 565, 185, 635, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(295, 565, 345, 635, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(615, 565, 665, 635, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(935, 565, 985, 635, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(1095, 565, 1145, 635, al_map_rgba(0, 244, 244, 0.5));

	//SOLDADOS DE CIMA
	al_draw_filled_rectangle(135, 85, 185, 155, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(295, 85, 345, 155, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(615, 85, 665, 155, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(935, 85, 985, 155, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(1095, 85, 1145, 155, al_map_rgba(0, 244, 244, 0.5));

	switch (evento.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN: 
		if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
			*pressionado = 1;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
			*pressionado = 2;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
			*pressionado = 3;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			*pressionado = 4;
		}
		break;
	case ALLEGRO_EVENT_KEY_UP:
		*pressionado = 0;
		break;
	}

	switch (*pressionado)
	{
	case 1:
		*positionY1 -= 1;
		*positionY2 -= 1;
		break;
	case 2:
		*positionX1 -= 1;
		*positionX2 -= 1;
		break;
	case 3:
		*positionX1 += 1;
		*positionX2 += 1;
		break;
	case 4:
		*positionY1 += 1;
		*positionY2 += 1;
		break;
	}

	//PERSONAGEM DO JOGADOR
	al_draw_filled_rectangle(*positionX1, *positionY1, *positionX2, *positionY2, al_map_rgba(0, 244, 244, 0.5));

	//REI DE ESPARTA
	al_draw_filled_rectangle(615, 425, 665, 495, al_map_rgba(0, 244, 244, 0.5));


	al_flip_display();
}