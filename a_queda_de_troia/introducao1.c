#include "introducao1.h"

int introducao1(ALLEGRO_EVENT event) {

	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = event.mouse.x;
		mouseY = event.mouse.y;
	}

	switch (intro)
	{
	case 1:
		imagemIntro(fundoHelena, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 600, ALLEGRO_ALIGN_CENTRE, "Nao devia estar aqui.");
		al_flip_display();
		break;
	case 2:
		imagemIntro(fundoParis, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 640, 600, ALLEGRO_ALIGN_CENTRE, "Foi o que disse ontem a noite.");
		al_flip_display();
		break;
	case 3:
		imagemIntro(fundoHelena, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 670, 600, ALLEGRO_ALIGN_CENTRE, "Ontem a noite foi um erro.");
		al_flip_display();
		break;
	case 4:
		imagemIntro(fundoParis, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 580, 600, ALLEGRO_ALIGN_CENTRE, "E ante-ontem a noite?");
		al_flip_display();
		break;
	case 5:
		imagemIntro(fundoHelena, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 600, 600, ALLEGRO_ALIGN_CENTRE, "Cometi muitos erros essa semana.");
		al_flip_display();
		break;
	case 6:
		imagemIntro(fundoParis, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 580, 600, ALLEGRO_ALIGN_CENTRE, "Tome este colar.");
		al_flip_display();
		break;
	case 7:
		imagemIntro(fundoHelena, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 590, 570, ALLEGRO_ALIGN_CENTRE, "Ele e lindo, mais nao posso usa-lo,");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 590, 630, ALLEGRO_ALIGN_CENTRE, "Menelau mataria nos dois.");
		al_flip_display();
		break;
	case 8:
		imagemIntro(fundoParis, event);
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 610, 570, ALLEGRO_ALIGN_CENTRE, "Nao tenha medo dele,");
		al_draw_text(fonteIntro1, al_map_rgb(0, 0, 0), 610, 630, ALLEGRO_ALIGN_CENTRE, "Venha comigo para Troia.");
		al_flip_display();
		if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		}
		else {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_ARROW);
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
				intro += 1;
				navegacao += 1;
			}
		}
		break;
	}

	//if (intro == 1) {
	//	imagemIntro(fundoHelena);
	//	al_draw_filled_rectangle(800, 510, 950, 550, al_map_rgb(222, 158, 30));
	//	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 875, 510, ALLEGRO_ALIGN_CENTRE, "Proximo");
	//al_flip_display(); 
	//if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) { 
	//	if (mouseX >= 800 && mouseY >= 510 && mouseX <= 950 && mouseY <= 550) {
	//		intro += 1;
	//	}
	//}
	//}
	//else if (intro == 2) {
	//	imagemIntro(fundoParis);
	//	al_draw_filled_rectangle(800, 550, 950, 590, al_map_rgb(222, 158, 30));
	//	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 875, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
	//	al_flip_display();
	//	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
	//		if (mouseX >= 800 && mouseY >= 550 && mouseX <= 950 && mouseY <= 590) {
	//			intro += 1;
	//		}
	//	} 
	//}
	//else if (intro == 3) {
	//	imagemIntro(fundoHelena);
	//	al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
	//	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
	//	al_flip_display();
	//	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
	//		if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
	//			intro += 1;
	//		}
	//	}
	//}
	//else if (intro == 4) {
	//	imagemIntro(fundoParis);
	//	al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
	//	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
	//	al_flip_display();
	//	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
	//		if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
	//			intro += 1;
	//		}
	//	}
	//}
	//else if (intro == 5) {
	//	imagemIntro(fundoHelena);
	//	al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
	//	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
	//	al_flip_display();
	//	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
	//		if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
	//			intro += 1;
	//		}
	//	}
	//}
	//else if (intro == 6) {
	//	imagemIntro(fundoParis);
	//	al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
	//	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
	//	al_flip_display();
	//	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
	//		if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
	//			intro += 1;
	//		}
	//	}
	//}
	//else if (intro == 7) {
	//	imagemIntro(fundoHelena);
	//	al_draw_filled_rectangle(565, 550, 715, 590, al_map_rgb(222, 158, 30));
	//	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "Proximo");
	//	al_flip_display();
	//	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
	//		if (mouseX >= 565 && mouseY >= 550 && mouseX <= 715 && mouseY <= 590) {
	//			intro = 1; //Reseta a intro para utilizar em outra funcao
	//			navegacao += 1;
	//		}
	//	}
	//}
}