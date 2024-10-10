﻿#include "lib.h"

int main() {
	iniciarAddons();
	iniciarConstantes();

	al_register_event_source(evento, al_get_keyboard_event_source());
	al_register_event_source(evento, al_get_display_event_source(display));
	al_register_event_source(evento, al_get_timer_event_source(timer));
	al_register_event_source(evento, al_get_mouse_event_source());

	bool redraw = true;
	ALLEGRO_EVENT event; 
	int navegacao = 0;
	bool rodando = true;
	int intro = 1;

	al_start_timer(timer);
	while (rodando) {
		al_wait_for_event(evento, &event);
		if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true; 
		}
		//if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
		//	printf("x-%d \n y-%d \n", event.mouse.x, event.mouse.y);	
		//}
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || navegacao == -1) {
			break;
		}
		switch (navegacao) {
			case 0:
				menu(&navegacao, backgroundMenu, event, &rodando);				 	
				break;
			case 1:  
				introducao1(&intro, &navegacao, event, introducao1_1, introducao1_2, introducao1_3, 
					introducao1_4, introducao1_5, introducao1_6, introducao1_7);
				break;
			case 2:
				al_draw_bitmap(backgroundIntUm, 0, 0, 0);
				al_flip_display();
				break;
		}
	}

<<<<<<< HEAD
	al_destroy_font(fonteMenu); 
	al_destroy_bitmap(backgroundIntUm);
	al_destroy_bitmap(backgroundMenu);
	al_destroy_bitmap(introducao1_1);
	al_destroy_bitmap(introducao1_2);
	al_destroy_bitmap(introducao1_3);
	al_destroy_bitmap(introducao1_4);
	al_destroy_bitmap(introducao1_5);
	al_destroy_bitmap(introducao1_6);
	al_destroy_bitmap(introducao1_7);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(evento);
=======
	destroiComponentes();
>>>>>>> 013a76183f264ae7bc1f20d521e29900fe879bf3

	return 0;
}