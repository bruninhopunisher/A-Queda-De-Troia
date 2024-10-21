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
		audioJogo(navegacao);
		switch (navegacao) {
			case 0:
				menu(event);
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
				fase2(event);
				break;
			case 6:
				
				fase3(event);
				break;
		}
	}
	destruidor();
	return 0;
}