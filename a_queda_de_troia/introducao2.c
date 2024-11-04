#include "introducao2.h"

void introducao2(ALLEGRO_EVENT evento) {
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
		if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		}
		else {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_ARROW);
		}
		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
				al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_ARROW);
				intro += 1;
				navegacao += 1;
			}
		}
		break;
	}
}
