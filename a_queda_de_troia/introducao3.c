#include "introducao3.h"

void introducao3(ALLEGRO_EVENT evento) {

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}
	switch (intro) {
	case 1:
		imagemIntro(pagina1, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 610, 610, ALLEGRO_ALIGN_CENTRE, "Os gregos preparam a maior estrategia de todos os tempos.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 610, 650, ALLEGRO_ALIGN_CENTRE, "A invasao de Troia comeca esta noite.");
		break;
	case 2:
		imagemIntro(pagina2, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 380, 525, ALLEGRO_ALIGN_CENTRE, "Ulisses");
		al_draw_text(font, al_map_rgb(0, 0, 0), 690, 580, ALLEGRO_ALIGN_CENTRE, "Agora, irmaos, nosso destino esta nas maos deste cavalo.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 670, 615, ALLEGRO_ALIGN_CENTRE, "Ele sera a chave para a nossa vitoria. Mas para isso,");
		al_draw_text(font, al_map_rgb(0, 0, 0), 670, 655, ALLEGRO_ALIGN_CENTRE, "devemos monta-lo com precisao.");
		break;
	case 3:
		imagemIntro(pagina3, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 540, 535, ALLEGRO_ALIGN_CENTRE, "AGAMENONM");
		al_draw_text(font, al_map_rgb(0, 0, 0), 790, 580, ALLEGRO_ALIGN_CENTRE, "Troia caira, e o mundo se lembrara do poder dos gregos.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 710, 610, ALLEGRO_ALIGN_CENTRE, "Trabalhem rapido, mas com cuidado.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 710, 640, ALLEGRO_ALIGN_CENTRE, "Nossos homens ja estao prontos ");
		al_draw_text(font, al_map_rgb(0, 0, 0), 690, 670, ALLEGRO_ALIGN_CENTRE, "para atacar!");
		break;
	case 4:
		imagemIntro(pagina4, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 165, ALLEGRO_ALIGN_CENTRE, "Agora, e hora de ajudar os gregos");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 215, ALLEGRO_ALIGN_CENTRE, " a montar o Cavalo de Troia.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 265, ALLEGRO_ALIGN_CENTRE, "Este sera o artificio que levara a");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 315, ALLEGRO_ALIGN_CENTRE, "queda de Troia.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 365, ALLEGRO_ALIGN_CENTRE, " Complete o quebra-cabeca para finalizar");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 415, ALLEGRO_ALIGN_CENTRE, " a construcao do cavalo.");
		break;
	case 5:
		imagemIntro(pagina4, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 640, 115, ALLEGRO_ALIGN_CENTRE, "Aqui estao as regras:");
		al_draw_text(font, al_map_rgb(0, 0, 0), 640, 215, ALLEGRO_ALIGN_CENTRE, "Arraste e posicione as pecas para formar a figura");
		al_draw_text(font, al_map_rgb(0, 0, 0), 680, 265, ALLEGRO_ALIGN_CENTRE, "Voce pode consultar a imagem original apenas 3 vezes.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 640, 365, ALLEGRO_ALIGN_CENTRE, "Use-a com sabedoria!");
		break;
	case 6:
		imagemIntro(pagina4, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 680, 215, ALLEGRO_ALIGN_CENTRE, "Use a logica e a memoria para resolver o quebra-cabeca.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 640, 265, ALLEGRO_ALIGN_CENTRE, " Cada erro pode custar tempo valioso, e os gregos");
		al_draw_text(font, al_map_rgb(0, 0, 0), 680, 315, ALLEGRO_ALIGN_CENTRE, "contam com sua habilidade para que o plano funcione.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 640, 415, ALLEGRO_ALIGN_CENTRE, "Boa sorte!");

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