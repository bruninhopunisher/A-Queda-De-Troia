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
		//Movimentação do Player INICIO:
		//Define se esta andando
		if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			andando = true; //Define se esta andando
		}
		else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
			andando = false;
		}
		//Efeito da animação dos movimentos
		if (andando) {
			if (atraso_animacao > 4) { // velocidade animação de mudar imagem atualizada pro frame
				contador_passos = (contador_passos + 1) % 2;
				atraso_animacao = 0;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_UP && playY > 80) {
				playY -= PlayVel;
				atraso_animacao++;
				aquiles_Atual = contador_passos == 0 ? aquiles_Subindo_0 : aquiles_Subindo_1;
				if (playZ == 1) {
					playZ = 0;
				}
				PlayPosicao = 3;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN && playY < 580) {
				playY += PlayVel;
				atraso_animacao++;
				aquiles_Atual = contador_passos == 0 ? aquiles_Descendo_0 : aquiles_Descendo_1;
				if (playZ == 1) {
					playZ = 0;
				}
				PlayPosicao = 0;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT && playX > 0) {
				playX -= PlayVel;
				atraso_animacao++;
				aquiles_Atual = contador_passos == 0 ? aquiles_Lado_0 : aquiles_Lado_1;
				playZ = 0;
				PlayPosicao = 1;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT && playX < 1210) {
				playX += PlayVel;
				atraso_animacao++;
				aquiles_Atual = contador_passos == 0 ? aquiles_Lado_0 : aquiles_Lado_1;
				playZ = 1;
				PlayPosicao = 2;
			}
		}
		else {
			if (PlayPosicao == 0) { //parado para baixo
				aquiles_Atual = aquiles_Baixo;
			}
			if (PlayPosicao == 1) {//parado para esquerda
				aquiles_Atual = aquiles_Lado_0;
				playZ = 0;
			}
			if (PlayPosicao == 2) {//parado para direita
				aquiles_Atual = aquiles_Lado_0;
				playZ = 1;
			}
			if (PlayPosicao == 3) {//parado para cima
				aquiles_Atual = aquiles_Cima;
			}
		}
		al_draw_bitmap(aquiles_Atual, playX, playY, playZ); //Player 35x55
		//Movimentação do Player FIM:
		//Mobimentação do Lanceiro INICIO: 87x42
		if (Lanc_Atual[0] == NULL) { //Inicializa a imagem do lanceiro
			for (int i = 0; i < qtdLanc; i++) {
				if (lancZ[i] == 0) {
					Lanc_Atual[i] = Lanc_Lado_0;
				}
				else {
					Lanc_Atual[i] = Lanc_Lado_1;
				}
			}
		}
		for (int i = 0; i < qtdLanc; i++) {
			if (atraso_animacao_Lanc[i] > 10) { // velocidade animação de mudar imagem atualizada pro frame
				contador_passos_Lanc[i] = (contador_passos_Lanc[i] + 1) % 2;
				atraso_animacao_Lanc[i] = 0;
			}
			al_draw_bitmap(Lanc_Atual[i], lancX[i], lancY[i], lancZ[i]); //Inimigo 87x42
			//Movimentacao
			if (lancZ[i] == 0) { //Direita
				lancX[i] += iniVel;
				atraso_animacao_Lanc[i]++;
				Lanc_Atual[i] = contador_passos_Lanc[i] == 0 ? Lanc_Lado_0 : Lanc_Lado_1; //87x42
				if (lancX[i] > 1210) {
					lancZ[i] = 1;
				}
			}
			else if (lancZ[i] == 1) { //Esquerda
				lancX[i] -= iniVel;
				atraso_animacao_Lanc[i]++;
				Lanc_Atual[i] = contador_passos_Lanc[i] == 0 ? Lanc_Lado_0 : Lanc_Lado_1; //87x42
				if (lancX[i] < 0) {
					lancZ[i] = 0;
				}
			}
			//Colisao do lanceiro com player
			if (playX + 35 > lancX[i] && playX < lancX[i] + 82 && playY + 55 > lancY[i] && playY < lancY[i] + 42) { //82x42 tamanho do lanceiro
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
			if (playX + 35 > fleX[i] && playX < fleX[i] + 12 && playY + 55 > fleY[i] && playY < fleY[i] + 60) {
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