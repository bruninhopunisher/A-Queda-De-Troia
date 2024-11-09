#include "fase04.h"

void fase4(ALLEGRO_EVENT evento) {
	if(gameOver == false){
		al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0)); //Criar um mapa de fundo
		if(vidaF4 == 3){
			al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 670, 5, ALLEGRO_ALIGN_CENTRE, "Vidas: 3");
		}
		if (vidaF4 == 2) {
			al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 670, 5, ALLEGRO_ALIGN_CENTRE, "Vidas: 2");
		}
		if (vidaF4 == 1) {
			al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 670, 5, ALLEGRO_ALIGN_CENTRE, "Vidas: 1");
		}
		if (vidaF4 == 0) {
			al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 670, 5, ALLEGRO_ALIGN_CENTRE, "Vidas: 0");
		}

		//Sistema de movimento do player
		al_draw_bitmap(player, playX, playY, 0); //Player 70x70
		if (evento.keyboard.keycode == ALLEGRO_KEY_UP && playY > 80) {
			playY -= PlayVel;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN && playY < 580) {
			playY += PlayVel;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT && playX > 0) {
			playX -= PlayVel;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT && playX < 1210) {
			playX += PlayVel;
		}

		//Sistema de movimento do inimigo (ATENCAO, 6 e a QTD de inimigo)
		for (int i = 0; i < 6; i++) {
			al_draw_bitmap(inimigo, iniX[i], iniY[i], iniZ[i]); //Inimigo 70x70 COLOCAR INIMIGO COM LANÇA
			if (iniZ[i] == 0) {
				iniX[i] += iniVel;
			}
			else if (iniZ[i] == 1) {
				iniX[i] -= iniVel;
			}
			if (iniX[i] < 0) {
				iniZ[i] = 0;
			}
			else if (iniX[i] > 1210) {
				iniZ[i] = 1;
			}
		}
		al_flip_display();

		//Sistema de colisao com inimigo
		for(int i = 0; i < 6; i++){
			if (playX + 70 > iniX[i] && playX < iniX[i] + 70 && playY + 70 > iniY[i] && playY < iniY[i] + 70) { //70x70 e o tamanho dos inimigos
				playX = 640; // Colocar vida ou algo do tipo para ir abaixando
				playY = 100;
				vidaF4 -= 1;
				iniX[0] = 0;
				iniX[1] = 1210;
				iniX[2] = 0;
				iniX[3] = 1210;
				iniX[4] = 0;
				iniX[5] = 1210;
				if (vidaF4 < 0) {
					gameOver = true;
				}
			}
		}
	}	

	else {
		al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0));
		al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 250, ALLEGRO_ALIGN_CENTRE, "GAME OVER");
		al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 330, ALLEGRO_ALIGN_CENTRE, "Menu"); //115tamanho // 50de espaço entre os 2
		al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 430, ALLEGRO_ALIGN_CENTRE, "Continuar"); //215
		al_flip_display();
		if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			//Clicar Menu direciona para o Menu
			if (mouseX >= 580 && mouseX <= 695 && mouseY >= 340 && mouseY <= 375) {
				navegacao = 0;
			}
			//Clicar continuar reseta a fase do comeco
			if (mouseX >= 530 && mouseX <= 750 && mouseY >= 440 && mouseY <= 475) {
				gameOver = false;
				vidaF4 = 3;
				iniX[0] = 0;
				iniX[1] = 1210;
				iniX[2] = 0;
				iniX[3] = 1210;
				iniX[4] = 0;
				iniX[5] = 1210;
			}
		}
	}


	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) { // Remover posterior
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
		printf("X: %d Y: %d \n", mouseX, mouseY);
	}
}