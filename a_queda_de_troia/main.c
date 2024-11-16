 	#include "lib.h"

int main() {
	//Função Externa que inicia todos os Addons
	iniciarAddons();
	//Função Externa que inicia todas as Constantes
	iniciarConstantes();

	al_register_event_source(evento, al_get_keyboard_event_source());
	al_register_event_source(evento, al_get_display_event_source(display));
	al_register_event_source(evento, al_get_timer_event_source(timer));
	al_register_event_source(evento, al_get_mouse_event_source()); 

	ALLEGRO_EVENT event;
	bool redraw = true;
	al_start_timer(timer);

	while (rodando) {
		al_wait_for_event(evento, &event);
		if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true; 
		}
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_P) { // Atalho para passar de fase (APENAS DESENVOLVEDORES :p )
				navegacao += 1;
			}
		}
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_O) { // Atalho para DESATIVAR o som (APENAS DESENVOLVEDORES :p )
				boolVolume = false;
			}
		}
		/*audioJogo(navegacao);*/

		//if (event.type == ALLEGRO_EVENT_MOUSE_AXES) { // Remover posterior
		//	mouseX = event.mouse.x;
		//	mouseY = event.mouse.y;
		//	printf("X: %d Y: %d \n\n", mouseX, mouseY);
		//}

		switch (navegacao) {
			case 0:
				//fase3(event);
				//menu(event);
				//fase4(event);
				introducao1(event);
				break;
			case 1:  
				opcoes(event);
				break;
			case 2:
				printf("ATENCAO \n\n\n Opcao creditos nao concluida"); // Criar creditos
				rodando = false;
				break;
			case 3:
				introducao1(event);
				break;
			case 4:
				fase01(event);
				break;
			case 5:
				introducao2(event);
				break;
			case 6:
				fase2(event);
				break;
			case 7:
				introducao3(event);
				/*al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0));
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, "intro3 Em const");
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 420, ALLEGRO_ALIGN_CENTRE, "Proximo");
				al_flip_display();
				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					if (mouseX >= 572 && mouseX <= 710 && mouseY >= 430 && mouseY <= 455) {
						navegacao += 1;
					}
				}*/
				break;
			case 8:
				fase3(event);
				break;
			case 9:
				al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0));
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, "intro3 Em const");
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 420, ALLEGRO_ALIGN_CENTRE, "Proximo");
				al_flip_display();
				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					if (mouseX >= 572 && mouseX <= 710 && mouseY >= 430 && mouseY <= 455) {
						navegacao += 1;
					}
				}
				break;
			case 10:
				fase4(event);
				break;
			case 11:
				al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0));
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, "Final Game - Const");
				al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 420, ALLEGRO_ALIGN_CENTRE, "Sair");
				al_flip_display();
				if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					if (mouseX >= 572 && mouseX <= 710 && mouseY >= 430 && mouseY <= 455) {
						rodando = false;
					}
				}
				break;
		}
	}
	destruidor();
	return 0;
}