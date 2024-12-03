#include "introducao2.h"

void introducao2(ALLEGRO_EVENT evento) {
	
	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}

	switch (intro)
	{
	case 1:
		imagemIntro(fundoEmbarcacao1, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 450, 585, ALLEGRO_ALIGN_CENTRE, "Apos roubar Helena de Esparta, ambos fogem para Troia.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 450, 615, ALLEGRO_ALIGN_CENTRE, "Mas essa escolha ira mudar o destino de duas nacoes...");
		break;
	case 2:
		imagemIntro(fundoEmbarcacao2, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 600, 585, ALLEGRO_ALIGN_CENTRE, "Voce tem ideia do que fez, Paris? ");
		al_draw_text(font, al_map_rgb(0, 0, 0), 600, 615, ALLEGRO_ALIGN_CENTRE, "Isso nao e amor, e guerra.");
		break;
	case 3:
		imagemIntro(fundoEmbarcacao3, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 600, 585, ALLEGRO_ALIGN_CENTRE, "O amor nao pode ser errado, irmao.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 600, 615, ALLEGRO_ALIGN_CENTRE, "Eu fiz o que o coracao mandou!");
		break;
	case 4:
		imagemIntro(fundoMenelau, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 450, 585, ALLEGRO_ALIGN_CENTRE, "Irmao, isso e mais que uma afronta a minha honra.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 450, 615, ALLEGRO_ALIGN_CENTRE, "toda a Grecia! Troia deve pagar pelo que fez.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 450, 650, ALLEGRO_ALIGN_CENTRE, "Paris nao apenas roubou minha esposa, mas insultou");
		al_draw_text(font, al_map_rgb(0, 0, 0), 450, 685, ALLEGRO_ALIGN_CENTRE, "toda a Grecia! Troia deve pagar pelo que fez.");
		break;
	case 5:
		imagemIntro(fundoAgamenom, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 780, 585, ALLEGRO_ALIGN_CENTRE, "E pagara. Mas nao e so por Helena que estamos aqui,");
		al_draw_text(font, al_map_rgb(0, 0, 0), 810, 615, ALLEGRO_ALIGN_CENTRE, "Menelau. Troia e a chave para o controle do Egeu. Se cair,");
		al_draw_text(font, al_map_rgb(0, 0, 0), 690, 650, ALLEGRO_ALIGN_CENTRE, "dominaremos todas as rotas comerciais.");
		break;
	case 6:
		imagemIntro(fundoMenelau, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 430, 585, ALLEGRO_ALIGN_CENTRE, "Para voce, isso e um jogo de poder! Para mim, e pessoal.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 450, 615, ALLEGRO_ALIGN_CENTRE, "Aquele troiano insolente roubou o que e meu. Nao");
		al_draw_text(font, al_map_rgb(0, 0, 0), 450, 650, ALLEGRO_ALIGN_CENTRE, "descansarei ate ve-lo morto e minha esposa de volta");
		break;
	case 7:
		imagemIntro(fundoAgamenom, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 780, 585, ALLEGRO_ALIGN_CENTRE, "Paris e um garoto. Ele nao merece sua ira. E Heitor");
		al_draw_text(font, al_map_rgb(0, 0, 0), 780, 615, ALLEGRO_ALIGN_CENTRE, "que mantem Troia de pe, e e ele que devemos derrubar.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 690, 650, ALLEGRO_ALIGN_CENTRE, " Mas tenha paciencia, irmao.");
		break;
	case 8:
		imagemIntro(fundoAgamenom, evento);
		al_draw_text(font, al_map_rgb(0, 0, 0), 780, 585, ALLEGRO_ALIGN_CENTRE, "O sangue deles manchara a areia antes do amanhecer.");
		al_draw_text(font, al_map_rgb(0, 0, 0), 780, 615, ALLEGRO_ALIGN_CENTRE, "Prepare os homens. Amanha, Troia.vera o verdadeiro");
		al_draw_text(font, al_map_rgb(0, 0, 0), 690, 650, ALLEGRO_ALIGN_CENTRE, "poder da Grecia.");
		break;
	case 9:
		imagemIntro(fundoExplicacao, evento);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 190, ALLEGRO_ALIGN_CENTRE, "Ajude Heito em uma batalha epica.");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 240, ALLEGRO_ALIGN_CENTRE, "contra Menelau e as defesas");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 290, ALLEGRO_ALIGN_CENTRE, "gregas. Prepare-se para lutar,");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 340, ALLEGRO_ALIGN_CENTRE, "proteger as muralhas e impedir o");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 390, ALLEGRO_ALIGN_CENTRE, "avanco inimigo no mini-jogo de");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 440, ALLEGRO_ALIGN_CENTRE, "combate!");

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
