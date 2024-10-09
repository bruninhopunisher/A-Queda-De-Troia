#include "lib.h"
#include "menu.h"
#include "introducao01.h"

int main() {
	//Função Externa que inicia todos os Addons
	iniciarAddons();
	//Função Externa que inicia todas as Constantes
	iniciarConstantes();

	al_register_event_source(evento, al_get_keyboard_event_source());
	al_register_event_source(evento, al_get_display_event_source(display));
	al_register_event_source(evento, al_get_timer_event_source(timer));
	al_register_event_source(evento, al_get_mouse_event_source());

	bool redraw = true;
	ALLEGRO_EVENT event; 
	int navegacao = 0;
	bool rodando = true;

	al_start_timer(timer);
	while (rodando) {
		al_wait_for_event(evento, &event);
		if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true; 
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			printf("x-%d \n y-%d \n", event.mouse.x, event.mouse.y);	
		}
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || navegacao == -1) {
			break;
		}
		switch (navegacao) {
			case 0:
				menu(&navegacao, backgroundMenu, event, &rodando);				 	
				break;
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
				if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
					mouseX = event.mouse.x;
					mouseY = event.mouse.y;
				}
				al_draw_bitmap(introducao01_3, 0, 0, 0);
				al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
				al_flip_display();
				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
						navegacao += 1;
					}
				}
				break;
			case 4:
				if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
					mouseX = event.mouse.x;
					mouseY = event.mouse.y;
				}
				al_draw_bitmap(introducao01_4, 0, 0, 0);
				al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
				al_flip_display();
				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
						navegacao += 1;
					}
				}
				break;
			case 5:
				if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
					mouseX = event.mouse.x;
					mouseY = event.mouse.y;
				}
				al_draw_bitmap(introducao01_5, 0, 0, 0);
				al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
				al_flip_display();
				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
						navegacao += 1;
					}
				}
				break;
			case 6:
				if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
					mouseX = event.mouse.x;
					mouseY = event.mouse.y;
				}
				al_draw_bitmap(introducao01_6, 0, 0, 0);
				al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
				al_flip_display();
				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
						navegacao += 1;
					}
				}
				break;
			case 7:
				if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
					mouseX = event.mouse.x;
					mouseY = event.mouse.y;
				}
				al_draw_bitmap(introducao01_7, 0, 0, 0);
				al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
				al_flip_display();
				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
						navegacao += 1;
					}
				}
				break;
			case 8:
				al_draw_bitmap(backgroundIntUm, 0, 0, 0);
				al_flip_display();
				break;
		}
	}

	al_destroy_font(fonteMenu); 
	al_destroy_bitmap(backgroundIntUm);
	al_destroy_bitmap(backgroundMenu);
	al_destroy_bitmap(introducao01_1);
	al_destroy_bitmap(introducao01_2);
	al_destroy_bitmap(introducao01_3);
	al_destroy_bitmap(introducao01_4);
	al_destroy_bitmap(introducao01_5);
	al_destroy_bitmap(introducao01_6);
	al_destroy_bitmap(introducao01_7);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(evento);

	return 0;
}