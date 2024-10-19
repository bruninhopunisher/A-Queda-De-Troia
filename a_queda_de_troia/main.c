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

	bool redraw = true;
	ALLEGRO_EVENT event; 
	int navegacao = 0;
	bool rodando = true;
	int intro = 1;

	//FASE 2
	int pressionado = 0;
	int positionX1_f2 = 615;
	int positionX2_f2 = 665;
	int positionY1_f2 = 225;
	int positionY2_f2 = 295;

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
		audioJogo(navegacao);
		switch (navegacao) {
			case 0:
				menu(&navegacao, backgroundMenu, event, &rodando);
				break;
			case 1:  
				introducao1(&intro, &navegacao, event);
				break;
			case 2:
				opcoes(&navegacao, event);
				break;
			case 3:
				faseUm(event, &navegacao);
				break;
			case 4:
				fase2(&navegacao, background_f2, &positionX1_f2, &positionX2_f2, &positionY1_f2, &positionY2_f2, event, &pressionado);
				break;
		}
	}

	destruidor();

	return 0;
}