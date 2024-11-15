#include "fase04.h"

void reiniciar() { //Reinicia a fase
	vidaF4 -= 1;
	playX = 595;
	playY = 315;
	for (int i = 0; i < qtdLanc; i++) { //Reinicia posicao dos lanceiros
		if (i % 2 == 0) {
			lancX[i] = 0;
		}
		else {
			lancX[i] = 1210;
		}
	}
	for (int i = 0; i < qtdFle; i++) {
		if (i % 2 == 0) {
			fleY[i] = -60;
			fleZ[i] = 0;
		}
		else {
			fleY[i] = 720;
			fleZ[i] = 2;
		}
	}
	if (vidaF4 == 0) {
		gameOver = true;
	}
}

void fase4(ALLEGRO_EVENT evento) {
	if(gameOver == false){
		al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 255, 0)); //Criar um mapa de fundo
		if (vidaF4 == 3){
			al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 5, ALLEGRO_ALIGN_CENTRE, "Vidas: 3");
		}
		if (vidaF4 == 2) {
			al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 5, ALLEGRO_ALIGN_CENTRE, "Vidas: 2");
		}
		if (vidaF4 == 1) {
			al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 5, ALLEGRO_ALIGN_CENTRE, "Vidas: 1");
		}
		if (vidaF4 == 0) {
			al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 5, ALLEGRO_ALIGN_CENTRE, "Vidas: 0");
		}
		//Sistema de movimento do player (PADRONIZAR COM OUTRAS TELAS)
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
		//Sistema do lanceiro
		for (int i = 0; i < qtdLanc; i++) {
			al_draw_bitmap(inimigo, lancX[i], lancY[i], lancZ[i]); //Inimigo 70x70 COLOCAR INIMIGO COM LANÇA
			//Movimentacao
			if (lancZ[i] == 0) {
				lancX[i] += iniVel;
				if (lancX[i] > 1210) {
				lancZ[i] = 1;
				}
			}
			else if (lancZ[i] == 1) {
				lancX[i] -= iniVel;
				if (lancX[i] < 0) {
					lancZ[i] = 0;
				}
			}
			//Colisao do lanceiro com player
			if (playX + 70 > lancX[i] && playX < lancX[i] + 70 && playY + 70 > lancY[i] && playY < lancY[i] + 70) { //70x70 tamanho do lanceiro
				reiniciar();
			}
		}
		//Sistema da flecha
		for (int i = 0; i < qtdFle; i++) {
			al_draw_bitmap(flecha, fleX[i], fleY[i], fleZ[i]); //12x60 e o tamanho da flecha
			if (fleZ[i] == 0) {
				fleY[i] += iniVel;
				if (fleY[i] > 720) {
					fleZ[i] = 2;
				}
			}
			else if (fleZ[i] == 2) {
					fleY[i] -= iniVel;
				if (fleY[i] < -60) {
					fleZ[i] = 0;
				}
			}
			//Colisao da flecha com player
			if (playX + 70 > fleX[i] && playX < fleX[i] + 12 && playY + 70 > fleY[i] && playY < fleY[i] + 60) {
				reiniciar();
			}
		}
		al_flip_display();
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
			if (mouseX >= 530 && mouseX <= 750 && mouseY >= 440 && mouseY <= 475) { //VerCoordenadas corretas, esta errado
				gameOver = false;
				vidaF4 = 4;
				reiniciar();
			}
		}
	}
}