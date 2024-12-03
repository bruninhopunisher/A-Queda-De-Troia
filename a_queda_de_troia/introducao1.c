#include "introducao1.h"

int introducao1(ALLEGRO_EVENT event) {

	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = event.mouse.x;
		mouseY = event.mouse.y;
	}
	switch (intro) {
	case 1:
		imagemIntro(mapaGrecia, event);
		break;
	case 2:
		imagemIntro(mapaAtenas, event);
		break;
	case 3 :
		imagemIntro(mapaTroia, event);
		break;
	case 4:
		imagemIntro(fundo1Intro1, event);
		//al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 600, ALLEGRO_ALIGN_CENTRE, "");
		break;
	case 5:
		imagemIntro(fundo2Intro1, event);
		//al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 600, ALLEGRO_ALIGN_CENTRE, "");
		break;
	case 6:
		imagemIntro(fundo3Intro1, event);
		//al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 600, ALLEGRO_ALIGN_CENTRE, "");
		break;
	case 7:
		imagemIntro(fundoHelena, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 600, ALLEGRO_ALIGN_CENTRE, "Nao devia estar aqui.");
		break;
	case 8:
		imagemIntro(fundoParis, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 600, ALLEGRO_ALIGN_CENTRE, "Foi o que disse ontem a noite.");
		break;
	case 9:
		imagemIntro(fundoHelena, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 600, ALLEGRO_ALIGN_CENTRE, "Ontem a noite foi um erro.");
		break;
	case 10:
		imagemIntro(fundoParis, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 580, 600, ALLEGRO_ALIGN_CENTRE, "E ante-ontem a noite?");
		break;
	case 11:
		imagemIntro(fundoHelena, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 600, 600, ALLEGRO_ALIGN_CENTRE, "Cometi muitos erros essa semana.");
		break;
	case 12:
		imagemIntro(fundoParis, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 580, 600, ALLEGRO_ALIGN_CENTRE, "Tome este colar.");
		break;
	case 13:
		imagemIntro(fundoHelena, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 590, 570, ALLEGRO_ALIGN_CENTRE, "Ele e lindo, mais nao posso usa-lo,");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 590, 630, ALLEGRO_ALIGN_CENTRE, "Menelau mataria nos dois.");
		break;
	case 14:
		imagemIntro(fundoParis, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 610, 570, ALLEGRO_ALIGN_CENTRE, "Nao tenha medo dele,");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 610, 630, ALLEGRO_ALIGN_CENTRE, "Venha comigo para Troia.");
		if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		}
		else {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
				al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				intro = 1;
				navegacao += 1;
			}
		}
		break;
	}
	al_flip_display();
}