#include <stdlib.h>
#include "menu.c"
#include "lib.c"

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

	al_start_timer(timer);
	while (1) {
		al_wait_for_event(evento, &event);
		if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		//if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			//printf("x-%d \n y-%d \n", event.mouse.x, event.mouse.y);	
		//}
		if (redraw && al_is_event_queue_empty(evento)); {
			switch (navegacao) {
				case 0:
					menu(&navegacao, backgroundMenu, event);
					break;
				case 1:
					al_draw_bitmap(backgroundIntUm, 0, 0, 0);
					al_flip_display();
					break;
				case 2:
					al_draw_bitmap(backgroundIntUm, 0, 0, 0); 
					al_flip_display();
					break;
				case 3:
					al_draw_bitmap(backgroundIntUm, 0, 0, 0);
					al_flip_display();
					break;
			}
		}
	}
	al_destroy_bitmap(backgroundIntUm);
	al_destroy_bitmap(backgroundMenu);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(evento);

	return 0;
}