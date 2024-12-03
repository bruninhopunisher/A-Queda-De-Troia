#include "introducao3.h"

void introducao3(ALLEGRO_EVENT evento) {

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}
	switch (intro) {
	case 1:
		imagemIntro(pagina1, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 610, 600, ALLEGRO_ALIGN_CENTRE, "Os gregos preparam a maior estrategia de todos os tempos");
		al_draw_text(font, al_map_rgb(0, 0, 0), 610, 650, ALLEGRO_ALIGN_CENTRE, "A invasao de Troia comeca esta noite");
		break;
	case 2:
		imagemIntro(pagina2, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 380, 525, ALLEGRO_ALIGN_CENTRE, "Ulisses");
		al_draw_text(font, al_map_rgb(0, 0, 0), 690, 590, ALLEGRO_ALIGN_CENTRE, "Agora, irmaos, nosso destino esta nas maos deste cavalo");
		al_draw_text(font, al_map_rgb(0, 0, 0), 630, 627, ALLEGRO_ALIGN_CENTRE, "Ele sera a chave para a nossa vitoria. Mas, para");
		al_draw_text(font, al_map_rgb(0, 0, 0), 620, 665, ALLEGRO_ALIGN_CENTRE, " isso devemos monta-lo com precisao");
		break;
	case 3:
		imagemIntro(pagina3, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 540, 535, ALLEGRO_ALIGN_CENTRE, "AGAMENONM");
		al_draw_text(font, al_map_rgb(0, 0, 0), 795, 585, ALLEGRO_ALIGN_CENTRE, "Troia caira e o mundo se lembrara do poder dos gregos");
		al_draw_text(font, al_map_rgb(0, 0, 0), 650, 617, ALLEGRO_ALIGN_CENTRE, "Trabalhem rapido, mas com cuidado!");
		al_draw_text(font, al_map_rgb(0, 0, 0), 660, 647, ALLEGRO_ALIGN_CENTRE, "Nossos homens ja estao prontos para ");
		al_draw_text(font, al_map_rgb(0, 0, 0), 420, 675, ALLEGRO_ALIGN_CENTRE, "atacar!");
		break;
	case 4:
		imagemIntro(pagina4, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 160, ALLEGRO_ALIGN_CENTRE, "A astucia grega leva a criacao de");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 210, ALLEGRO_ALIGN_CENTRE, "uma estrategia engenhosa:");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 260, ALLEGRO_ALIGN_CENTRE, "o Cavalo de Troia");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 310, ALLEGRO_ALIGN_CENTRE, "Enquanto Troia celebra uma aparente");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 700, 360, ALLEGRO_ALIGN_CENTRE, "vitoria, um presente misterioso");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 700, 410, ALLEGRO_ALIGN_CENTRE, "surge diante de seus portoes,");

		break;
	case 5:
		imagemIntro(pagina4, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 700, 190, ALLEGRO_ALIGN_CENTRE, "marcando o proximo passo");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 700, 240, ALLEGRO_ALIGN_CENTRE, "dessa epica historia");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 290, ALLEGRO_ALIGN_CENTRE, "Prepare-se para desvendar o segredo por ");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 700, 340, ALLEGRO_ALIGN_CENTRE, "tras desse simbolo em um");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 700, 390, ALLEGRO_ALIGN_CENTRE, "desafio de quebra-cabeca!");
		break;
	case 6:
		imagemIntro(pagina4, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 700, 150, ALLEGRO_ALIGN_CENTRE, "Use a logica e a memoria para");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 720, 200, ALLEGRO_ALIGN_CENTRE, "resolver o quebra-cabeca.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 250, ALLEGRO_ALIGN_CENTRE, "Cada erro pode custar tempo valioso, e os gregos");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 300, ALLEGRO_ALIGN_CENTRE, "e os gregos contam com sua habilidade para que");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 350, ALLEGRO_ALIGN_CENTRE, "o plano funcione.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 450, ALLEGRO_ALIGN_CENTRE, "Boa sorte!");
	case 7:
		imagemIntro(pagina4, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 90, ALLEGRO_ALIGN_CENTRE, "Aqui estao as regras:");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 160, ALLEGRO_ALIGN_CENTRE, "Clique na peca e em seguida"); 
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 210, ALLEGRO_ALIGN_CENTRE, "clique no tabuleiro quadriculado");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 260, ALLEGRO_ALIGN_CENTRE, "Voce pode consultar a");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 690, 310, ALLEGRO_ALIGN_CENTRE, "imagem original apenas 3 vezes.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 690, 360, ALLEGRO_ALIGN_CENTRE, "Mas tenha muito cuidado, caso coloque");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 410, ALLEGRO_ALIGN_CENTRE, "uma peca errada no comeco, voce tera que");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 680, 460, ALLEGRO_ALIGN_CENTRE, "retroceder todas as pecas ja posicionadas");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 690, 510, ALLEGRO_ALIGN_CENTRE, "em seus lugares corretos!");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 700, 560, ALLEGRO_ALIGN_CENTRE, "Use-a com sabedoria!");
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