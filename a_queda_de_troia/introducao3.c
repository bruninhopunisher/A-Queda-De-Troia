#include "introducao3.h"

void introducao3(ALLEGRO_EVENT evento) {

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}

	switch (intro)
	{
	case 1:
		imagemIntro(pagina1, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 610, 610, ALLEGRO_ALIGN_CENTRE, "Os gregos preparam a maior estrategia de todos os tempos.",35);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 610, 650, ALLEGRO_ALIGN_CENTRE, "A invasao de Troia comeca esta noite.");
		al_flip_display();
		break;
	case 2:
		imagemIntro(pagina2, evento);		
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 580, ALLEGRO_ALIGN_CENTRE, "O destino de Troia esta em nossas maos.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 620, ALLEGRO_ALIGN_CENTRE, " Vamos entrar em suas portas");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 660, ALLEGRO_ALIGN_CENTRE, " de forma silenciosa.");
		al_flip_display();
		break;
	case 3:
		imagemIntro(pagina3, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 610, 620, ALLEGRO_ALIGN_CENTRE, "Os troianos festejam disaridos do que esta por vim");
		al_flip_display();
		break;
	case 4:
		imagemIntro(pagina4, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 115, ALLEGRO_ALIGN_CENTRE, "Abrir o portao e essencial.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 165, ALLEGRO_ALIGN_CENTRE, " Sem isso,nossos irmaos do lado de fora");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 215, ALLEGRO_ALIGN_CENTRE, "nao terao chance de lutar.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 265, ALLEGRO_ALIGN_CENTRE, " E o unico jeito de Troia cair.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 315, ALLEGRO_ALIGN_CENTRE, "O mecanismo do portao foi feito");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 365, ALLEGRO_ALIGN_CENTRE, " para impedir invasores.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 415, ALLEGRO_ALIGN_CENTRE, "Voce precisara resolver esse ");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 465, ALLEGRO_ALIGN_CENTRE, "quebra-cabeca para destrava-lo..");
		al_flip_display();
		break;
	case 5:
		imagemIntro(pagina5, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 165, ALLEGRO_ALIGN_CENTRE, "Estude o mecanismo");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 215, ALLEGRO_ALIGN_CENTRE, " e memorize cada detalhe.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 265, ALLEGRO_ALIGN_CENTRE, "Voce podera consultar o diagrama");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 315, ALLEGRO_ALIGN_CENTRE, " original apenas tres vezes.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 365, ALLEGRO_ALIGN_CENTRE, "Depois disso, estara por sua conta!");
		al_flip_display();
		break;
	case 6:
		imagemIntro(pagina6, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 215, ALLEGRO_ALIGN_CENTRE, "Cada movimento deve ser preciso.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 265, ALLEGRO_ALIGN_CENTRE, "Nao temos margem para erro!");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 315, ALLEGRO_ALIGN_CENTRE, "Boa sorte, soldado.");
		al_flip_display();
		if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		}
		else {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_ARROW);
		}
		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
				intro += 1;
				navegacao += 1;
			}
		}
		break;
	}
}
