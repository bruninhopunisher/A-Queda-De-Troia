#include "fase04.h"

void fase4(ALLEGRO_EVENT evento) {

	al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0)); //Criar um mapa de fundo

	//Sistema de movimento do player
	al_draw_bitmap(player, playX, playY, 0); //Player 70x70
	if (evento.keyboard.keycode == ALLEGRO_KEY_UP && playY > 10) {
		playY -= 10;
	}
	if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN && playY < 640) {
		playY += 10;
	}
	if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT && playX > 0) {
		playX -= 10;
	}
	if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT && playX < 1210) {
		playX += 10;
	}

	//Sistema de movimento do inimigo (ATENCAO, 6 e a QTD de inimigo)
	for (int i = 0; i < 6; i++) {
		al_draw_bitmap(inimigo, iniX[i], iniY[i], iniZ[i]); //Inimigo 70x70 COLOCAR INIMIGO COM LANÇA
		if (iniZ[i] == 0) {
			iniX[i] += 2;
		}
		else if (iniZ[i] == 1) {
			iniX[i] -= 2;
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
	for(int i = 0; i < 6; i++)
	if (playX + 70 > iniX[i] && playX < iniX[i] + 70 && playY + 70 > iniY[i] && playY < iniY[i] + 70) {
		playX = 640; // Colocar vida ou algo do tipo para ir abaixando
		playY = 100;
	}
}