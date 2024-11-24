#include "introducao2.h"

void introducao2(ALLEGRO_EVENT evento) {
	//printf("\nChegouuuuuuuuu intro 2");
	//printf("%d\n", intro);
	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}

	//printf("\nMOUSE X%d\n", mouseX);
	//printf("MOUSE Y%d\n", mouseY);
	switch (intro)
	{
	case 1:
		imagemIntro(fundoMenelau, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 570, 600, ALLEGRO_ALIGN_CENTRE, "Os troianos levaram Helena,");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 570, 650, ALLEGRO_ALIGN_CENTRE, "Eu quero ela de volta");
		al_flip_display();
		break;
	case 2:
		imagemIntro(fundoAgamenom, evento);
		al_flip_display();
		break;
	case 3:
		imagemIntro(fundoMenelau, evento);
		al_flip_display();
		break;
	case 4:
		imagemIntro(fundoMenelau, evento);
		al_flip_display();
		break;
	case 5:
		imagemIntro(fundoAgamenom, evento);
		al_flip_display();
		if ((mouseX >= 1016 && mouseX <= 1189) && (mouseY >= 653 && mouseY <= 692)) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
			if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				intro = 1;
				navegacao += 1;
			}
		}
		else {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
		}
		break;
	}
}
