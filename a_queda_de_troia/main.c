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
		audioJogo(navegacao);
		switch (navegacao) {
			case 0:
				menu(event);
				break;
			case 1:  
				introducao1(event);
				break;
			case 2:
				opcoes(event);
				break;
			case 3:
				faseUm(event);
				break;
			case 4:
				fase2(event);
				break;
		}
	}
	destruidor();
	return 0;
}