#include "fase04.h"
void reiniciar() { //Reinicia a fase
	//Reiniciar a posi��o do Player e retira 1 vida: INICIO
	vidaF4 -= 1;
	playX = 605;
	playY = 325;
	playZ = 0;
	PlayPosicao = 0;
	andando = false;
	tempoRestante = 60;//Reseta o timer
	for (int i = 0; i < qtdLanc; i++) { //Reinicia posicao dos lanceiros
		if (i % 2 == 0) {
			lancX[i] = 0;
		}
		else {
			lancX[i] = 1210;
		}
	}
	for (int i = 0; i < qtdArq; i++) { //Reinicia a anima��o do arqueiro e das flechas
		if (arqZ[i] == 0) { //Arqueiros de cima
			arq_Atual[i] = arq_Frente_1;
			atraso_animacao_Arq[i] = 0;
			contador_passos_Arq[i] = 0;
			contador_passos_Arq[i] = (contador_passos_Arq[i] + 1) % 2; //J� para iniciar a anima��o do arqueiro
			atirando_Arq[i] = false;
			fleY[i] = 70; //Reinicia a posi��o da flecha
		}
		else if (arqZ[i] == 1) { //Arqueiros debaixo
			arq_Atual[i] = arq_Costas_1;
			atraso_animacao_Arq[i] = 0;
			contador_passos_Arq[i] = 0;
			contador_passos_Arq[i] = (contador_passos_Arq[i] + 1) % 2; //J� para iniciar a anima��o do arqueiro
			atirando_Arq[i] = false;
			fleY[i] = 670; //Reinicia a posi��o da flecha
		}
	}
	if (vidaF4 == 0) {
		gameOver = true;
	}
}
void fase4(ALLEGRO_EVENT evento) {
	if (gameOver == false) {
		al_draw_bitmap(backgroundFase04, 0, 0, 0); //Background 1280x720
		al_draw_textf(fonteIntro1, al_map_rgb(255, 255, 255), 640, 0, ALLEGRO_ALIGN_CENTRE, "vidas: %d", vidaF4);
		//Timer do tempo da fase INICIO:
		if (!timerOn){ //Inicializa o timer
			al_start_timer(timerFase04);
			timerOn = true;
		}
		if (evento.type == ALLEGRO_EVENT_TIMER && evento.timer.source == timerFase04) {
			tempoRestante--; //Vai decrementando de 1 em 1 segundo
			if (tempoRestante <= 0) {
				gameOver = true; // Tempo acabou
			}
		}
		al_draw_textf(fonteIntro1, al_map_rgb(255, 255, 255), 1100, 0, ALLEGRO_ALIGN_CENTER, "tempo: %d", tempoRestante);
		//Timer do tempo da fase FIM:
		//Movimenta��o do Player INICIO:
		//Define se esta andando
		if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			andando = true; //Define se esta andando
		}
		else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
			andando = false;
		}
		//Efeito da anima��o dos movimentos
		if (andando) {
			if (atraso_animacao > 4) { // velocidade anima��o de mudar imagem atualizada por frame
				contador_passos = (contador_passos + 1) % 2;
				atraso_animacao = 0;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_UP && playY > 100) {
				playY -= PlayVel;
				atraso_animacao++;
				aquiles_Atual = contador_passos == 0 ? aquiles_Subindo_0 : aquiles_Subindo_1;
				if (playZ == 1) {
					playZ = 0;
				}
				PlayPosicao = 3;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN && playY < 585) {
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
		//Movimenta��o do Player FIM:
		//Movimenta��o do Lanceiro INICIO: 82x42
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
			if (atraso_animacao_Lanc[i] > 10) { // velocidade anima��o de mudar imagem atualizada por frame
				contador_passos_Lanc[i] = (contador_passos_Lanc[i] + 1) % 2;
				atraso_animacao_Lanc[i] = 0;
			}
			al_draw_bitmap(Lanc_Atual[i], lancX[i], lancY[i], lancZ[i]); //Inimigo 82x42
			//Movimentacao
			if (lancZ[i] == 0) { //Direita
				lancX[i] += iniVel;
				atraso_animacao_Lanc[i]++;
				Lanc_Atual[i] = contador_passos_Lanc[i] == 0 ? Lanc_Lado_0 : Lanc_Lado_1; //82x42
				if (lancX[i] > 1210) {
					lancZ[i] = 1;
				}
			}
			else if (lancZ[i] == 1) { //Esquerda
				lancX[i] -= iniVel;
				atraso_animacao_Lanc[i]++;
				Lanc_Atual[i] = contador_passos_Lanc[i] == 0 ? Lanc_Lado_0 : Lanc_Lado_1; //82x42
				if (lancX[i] < 0) {
					lancZ[i] = 0;
				}
			}
			//Colisao do lanceiro com player
			if (playX + 35 > lancX[i] && playX < lancX[i] + 82 && playY + 55 > lancY[i] && playY < lancY[i] + 42) { //82x42 tamanho do lanceiro
				reiniciar();
			}
		}
		//Mobimenta��o do Lanceiro FIM: 82x42
		//Movimenta��o do Arqueiro/Flechas INICIO: Arqueiro 50x65 Flecha 12x30
		if (arq_Atual[0] == NULL) { //Inicializa a imagem do arqueiro
			for (int i = 0; i < qtdArq; i++) {
				if (arqZ[i] == 0) {
					arq_Atual[i] = arq_Frente_1;
				}
				else if (arqZ[i] == 1) {
					arq_Atual[i] = arq_Costas_1;
				}
			}
		}
		for (int i = 0; i < qtdArq; i++) {
			if (atraso_animacao_Arq[i] > 10) { // velocidade anima��o de mudar imagem atualizada por frame
				contador_passos_Arq[i] = (contador_passos_Arq[i] + 1) % 2;
				atraso_animacao_Arq[i] = 0;
				atirando_Arq[i] = true;
			}
			al_draw_bitmap(arq_Atual[i], arqX[i], arqY[i], arqZ[i]); //Arqueiro 50x65
			if (atirando_Arq[i]) {
				al_draw_bitmap(flecha, fleX[i], fleY[i], fleZ[i]); //10x30 e o tamanho da flecha
				if (fleZ[i] == 0) {
					fleY[i] += iniVel;
					if (fleY[i] > 750) {
						atirando_Arq[i] = false;
					}
				}
				else if (fleZ[i] == 2) {
					fleY[i] -= iniVel;
					if (fleY[i] < -30) {
						atirando_Arq[i] = false;
					}
				}
				//Colisao da flecha com player
				if (playX + 35 > fleX[i] && playX < fleX[i] + 12 && playY + 55 > fleY[i] && playY < fleY[i] + 30) {
					reiniciar();
				}
			}
			else {
				if (arqZ[i] == 0) { //Cima
					atraso_animacao_Arq[i]++;
					arq_Atual[i] = contador_passos_Arq[i] == 0 ? arq_Frente_1 : arq_Frente_2;
				}
				else if (arqZ[i] == 1) { //Baixo
					atraso_animacao_Arq[i]++;
					arq_Atual[i] = contador_passos_Arq[i] == 0 ? arq_Costas_1 : arq_Costas_2;
				}
				if (fleZ[i] == 0) {
					fleY[i] = 70;
				}
				else {
					fleY[i] = 670;
				}
			}
		}
		//Movimenta��o do Arqueiro/Flechas FIM: Arqueiro 50x65 Flecha 12x30
		al_flip_display();
	}
	else if (vidaF4 <= 0) {
		al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0));
		al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 250, ALLEGRO_ALIGN_CENTRE, "GAME OVER");
		al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 330, ALLEGRO_ALIGN_CENTRE, "Menu"); //580x695 340x375
		al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 430, ALLEGRO_ALIGN_CENTRE, "Continuar"); //215
		al_flip_display();
		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			//Clicar Menu direciona para o Menu
			if (evento.mouse.x >= 580 && evento.mouse.x <= 695 && evento.mouse.y >= 340 && evento.mouse.y <= 375) {
				navegacao = 0;
			}
			//Clicar continuar reseta a fase do comeco
			if (evento.mouse.x >= 530 && evento.mouse.x <= 750 && evento.mouse.y >= 440 && evento.mouse.y <= 475) {
				gameOver = false;
				vidaF4 = 4;
				reiniciar();
			}
		}
	}
	else {
		al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgb(0, 0, 0));
		al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 250, ALLEGRO_ALIGN_CENTRE, "Parabens, voce venceu o desafio");
		al_draw_text(fonteIntro1, al_map_rgb(255, 255, 255), 640, 330, ALLEGRO_ALIGN_CENTRE, "Continuar"); //530x750 340x375
		al_flip_display();
		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			//Clicar continuar direciona para pr�xima fase
			if (evento.mouse.x >= 530 && evento.mouse.x <= 750 && evento.mouse.y >= 340 && evento.mouse.y <= 375) {
				navegacao += 1;
			}
		}
	}
}