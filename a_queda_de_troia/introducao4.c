#include "introducao4.h"

void introducao4(ALLEGRO_EVENT evento) {

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}
	switch (intro) {
	case 1:
		imagemIntro(pag1, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 830, 535, ALLEGRO_ALIGN_CENTRE, "Aquiles");
		al_draw_text(font, al_map_rgb(0, 0, 0), 470, 580, ALLEGRO_ALIGN_CENTRE, "Troia esta ruindo, mas isso nao significa que ja vencemos.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 470, 620, ALLEGRO_ALIGN_CENTRE, "Os troianos ainda lutam, e voce precisa ser mais rapido");
		al_draw_text(font, al_map_rgb(0, 0, 0), 470, 660, ALLEGRO_ALIGN_CENTRE, "que eles. Lembre-se: 'A gloria e de quem luta!'");
		break;
	case 2:
		imagemIntro(pag2, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 830, 535, ALLEGRO_ALIGN_CENTRE, "Menelau");
		al_draw_text(font, al_map_rgb(0, 0, 0), 490, 580, ALLEGRO_ALIGN_CENTRE, "Essa cidade roubou tudo de mim! 'Agora vamos mostrar a eles");
		al_draw_text(font, al_map_rgb(0, 0, 0), 470, 620, ALLEGRO_ALIGN_CENTRE, "que nem seus muros, nem seus deuses podem salva - los.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 470, 660, ALLEGRO_ALIGN_CENTRE, "'Nao hesite, nao recue. Troia precisa cair hoje!");
		break;
	case 3:
		imagemIntro(pag3, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 870, 535, ALLEGRO_ALIGN_CENTRE, "Ulisses");
		al_draw_text(font, al_map_rgb(0, 0, 0), 530, 580, ALLEGRO_ALIGN_CENTRE, "Voce sabe o que esta em jogo aqui. 'Troia caira, nao por sorte,");
		al_draw_text(font, al_map_rgb(0, 0, 0), 530, 620, ALLEGRO_ALIGN_CENTRE, "mas pela nossa astucia e determinacao.'");
		al_draw_text(font, al_map_rgb(0, 0, 0), 530, 660, ALLEGRO_ALIGN_CENTRE, " Mostre que voce esta a altura deste destino.");
		break;
	case 4:
		imagemIntro(pag4, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 215, ALLEGRO_ALIGN_CENTRE, " O percurso sera perigoso.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 265, ALLEGRO_ALIGN_CENTRE, "Voce tera que ser agil");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 315, ALLEGRO_ALIGN_CENTRE, " e preciso para desviar dos obstaculos.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 365, ALLEGRO_ALIGN_CENTRE, " E o unico jeito de Troia cair.");
		break;
	case 5:
		imagemIntro(pag4, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 165, ALLEGRO_ALIGN_CENTRE, "Lembre-se: sua vida e limitada!");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 265, ALLEGRO_ALIGN_CENTRE, "Se chegar ao fim com energia suficiente,");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 315, ALLEGRO_ALIGN_CENTRE, "Troia sera sua. Mas, se cair no");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 365, ALLEGRO_ALIGN_CENTRE, "caminho... sera o fim de nosso sonho");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 415, ALLEGRO_ALIGN_CENTRE, "de vitoria.");

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
	al_flip_display();
}