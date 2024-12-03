#include "fase03.h"

// Mostra a imagem original do puzzle
void imagemPuzzle() {
	al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	al_draw_bitmap(imgFundoPuzzle, 0, 0, 0);
	al_draw_bitmap(imgPuzzle, 340, 60, 0);
	al_flip_display();
	al_rest(3);
	contadorCreditos -= 1;
}

void desenhaQuadrados() {
	//Desenha quadrante
	for (float x = 410.5; x < 410.5 + 550; x += 116) {
		for (int y = 65; y < 65 + 550; y += 116) {
			al_draw_rectangle(x, y, x + 116, y + 116, al_map_rgb(0, 0, 0), 10);
		}
	}

	// Desenha linhas brancas nas posições iniciais
	for (int m = 0; m < 25; m++) {
		for (int n = 0; n < 25; n++) {
			al_draw_rectangle(posicaoInicialX[n] - 3, posicaoInicialY[n] - 3, posicaoInicialX[n] + 114, posicaoInicialY[n] + 114, al_map_rgb(255, 255, 255), 7);
		}
	}
}

void resetF3() {
	posicoesIniciais.posicoes[0].id = 1;
	posicoesIniciais.posicoes[0].x = 20;
	posicoesIniciais.posicoes[0].y = 20;
	posicoesIniciais.posicoes[0].contemPeca = true;

	posicoesIniciais.posicoes[1].id = 2;
	posicoesIniciais.posicoes[1].x = 20;
	posicoesIniciais.posicoes[1].y = 140;
	posicoesIniciais.posicoes[1].contemPeca = true;

	posicoesIniciais.posicoes[2].id = 3;
	posicoesIniciais.posicoes[2].x = 20;
	posicoesIniciais.posicoes[2].y = 260;
	posicoesIniciais.posicoes[2].contemPeca = true;

	posicoesIniciais.posicoes[3].id = 4;
	posicoesIniciais.posicoes[3].x = 20;
	posicoesIniciais.posicoes[3].y = 380;
	posicoesIniciais.posicoes[3].contemPeca = true;

	posicoesIniciais.posicoes[4].id = 5;
	posicoesIniciais.posicoes[4].x = 260;
	posicoesIniciais.posicoes[4].y = 20;
	posicoesIniciais.posicoes[4].contemPeca = true;

	posicoesIniciais.posicoes[5].id = 6;
	posicoesIniciais.posicoes[5].x = 140;
	posicoesIniciais.posicoes[5].y = 20;
	posicoesIniciais.posicoes[5].contemPeca = true;

	posicoesIniciais.posicoes[6].id = 7;
	posicoesIniciais.posicoes[6].x = 140;
	posicoesIniciais.posicoes[6].y = 140;
	posicoesIniciais.posicoes[6].contemPeca = true;

	posicoesIniciais.posicoes[7].id = 8;
	posicoesIniciais.posicoes[7].x = 140;
	posicoesIniciais.posicoes[7].y = 260;
	posicoesIniciais.posicoes[7].contemPeca = true;

	posicoesIniciais.posicoes[8].id = 9;
	posicoesIniciais.posicoes[8].x = 1150;
	posicoesIniciais.posicoes[8].y = 20;
	posicoesIniciais.posicoes[8].contemPeca = true;

	posicoesIniciais.posicoes[9].id = 10;
	posicoesIniciais.posicoes[9].x = 260;
	posicoesIniciais.posicoes[9].y = 500;
	posicoesIniciais.posicoes[9].contemPeca = true;

	posicoesIniciais.posicoes[10].id = 11;
	posicoesIniciais.posicoes[10].x = 1030;
	posicoesIniciais.posicoes[10].y = 500;
	posicoesIniciais.posicoes[10].contemPeca = true;

	posicoesIniciais.posicoes[11].id = 12;
	posicoesIniciais.posicoes[11].x = 140;
	posicoesIniciais.posicoes[11].y = 380;
	posicoesIniciais.posicoes[11].contemPeca = true;

	posicoesIniciais.posicoes[12].id = 13;
	posicoesIniciais.posicoes[12].x = 1030;
	posicoesIniciais.posicoes[12].y = 20;
	posicoesIniciais.posicoes[12].contemPeca = true;

	posicoesIniciais.posicoes[13].id = 14;
	posicoesIniciais.posicoes[13].x = 260;
	posicoesIniciais.posicoes[13].y = 140;
	posicoesIniciais.posicoes[13].contemPeca = true;

	posicoesIniciais.posicoes[14].id = 15;
	posicoesIniciais.posicoes[14].x = 1030;
	posicoesIniciais.posicoes[14].y = 140;
	posicoesIniciais.posicoes[14].contemPeca = true;

	posicoesIniciais.posicoes[15].id = 16;
	posicoesIniciais.posicoes[15].x = 1030;
	posicoesIniciais.posicoes[15].y = 260;
	posicoesIniciais.posicoes[15].contemPeca = true;

	posicoesIniciais.posicoes[16].id = 17;
	posicoesIniciais.posicoes[16].x = 1030;
	posicoesIniciais.posicoes[16].y = 380;
	posicoesIniciais.posicoes[16].contemPeca = true;

	posicoesIniciais.posicoes[17].id = 18;
	posicoesIniciais.posicoes[17].x = 1150;
	posicoesIniciais.posicoes[17].y = 140;
	posicoesIniciais.posicoes[17].contemPeca = true;

	posicoesIniciais.posicoes[18].id = 19;
	posicoesIniciais.posicoes[18].x = 1150;
	posicoesIniciais.posicoes[18].y = 260;
	posicoesIniciais.posicoes[18].contemPeca = true;

	posicoesIniciais.posicoes[19].id = 20;
	posicoesIniciais.posicoes[19].x = 1150;
	posicoesIniciais.posicoes[19].y = 380;
	posicoesIniciais.posicoes[19].contemPeca = true;

	posicoesIniciais.posicoes[20].id = 21;
	posicoesIniciais.posicoes[20].x = 1150;
	posicoesIniciais.posicoes[20].y = 500;
	posicoesIniciais.posicoes[20].contemPeca = true;

	posicoesIniciais.posicoes[21].id = 22;
	posicoesIniciais.posicoes[21].x = 20;
	posicoesIniciais.posicoes[21].y = 500;
	posicoesIniciais.posicoes[21].contemPeca = true;

	posicoesIniciais.posicoes[22].id = 23;
	posicoesIniciais.posicoes[22].x = 260;
	posicoesIniciais.posicoes[22].y = 260;
	posicoesIniciais.posicoes[22].contemPeca = true;

	posicoesIniciais.posicoes[23].id = 24;
	posicoesIniciais.posicoes[23].x = 260;
	posicoesIniciais.posicoes[23].y = 380;
	posicoesIniciais.posicoes[23].contemPeca = true;

	posicoesIniciais.posicoes[24].id = 25;
	posicoesIniciais.posicoes[24].x = 140;
	posicoesIniciais.posicoes[24].y = 500;
	posicoesIniciais.posicoes[24].contemPeca = true;

	pecasPuzzle.pecas[0].id = 1;
	pecasPuzzle.pecas[0].pos_inicial_x = 20;
	pecasPuzzle.pecas[0].pos_inicial_y = 20;
	pecasPuzzle.pecas[0].pos_atual_x = 20;
	pecasPuzzle.pecas[0].pos_atual_y = 20;
	pecasPuzzle.pecas[0].selecionada = false;

	pecasPuzzle.pecas[1].id = 2;
	pecasPuzzle.pecas[1].pos_inicial_x = 20;
	pecasPuzzle.pecas[1].pos_inicial_y = 140;
	pecasPuzzle.pecas[1].pos_atual_x = 20;
	pecasPuzzle.pecas[1].pos_atual_y = 140;
	pecasPuzzle.pecas[1].selecionada = false;

	pecasPuzzle.pecas[2].id = 3;
	pecasPuzzle.pecas[2].pos_inicial_x = 20;
	pecasPuzzle.pecas[2].pos_inicial_y = 260;
	pecasPuzzle.pecas[2].pos_atual_x = 20;
	pecasPuzzle.pecas[2].pos_atual_y = 260;
	pecasPuzzle.pecas[2].selecionada = false;

	pecasPuzzle.pecas[3].id = 4;
	pecasPuzzle.pecas[3].pos_inicial_x = 20;
	pecasPuzzle.pecas[3].pos_inicial_y = 380;
	pecasPuzzle.pecas[3].pos_atual_x = 20;
	pecasPuzzle.pecas[3].pos_atual_y = 380;
	pecasPuzzle.pecas[3].selecionada = false;

	pecasPuzzle.pecas[4].id = 5;
	pecasPuzzle.pecas[4].pos_inicial_x = 260;
	pecasPuzzle.pecas[4].pos_inicial_y = 20;
	pecasPuzzle.pecas[4].pos_atual_x = 260;
	pecasPuzzle.pecas[4].pos_atual_y = 20;
	pecasPuzzle.pecas[4].selecionada = false;

	pecasPuzzle.pecas[5].id = 6;
	pecasPuzzle.pecas[5].pos_inicial_x = 140;
	pecasPuzzle.pecas[5].pos_inicial_y = 20;
	pecasPuzzle.pecas[5].pos_atual_x = 140;
	pecasPuzzle.pecas[5].pos_atual_y = 20;
	pecasPuzzle.pecas[5].selecionada = false;

	pecasPuzzle.pecas[6].id = 7;
	pecasPuzzle.pecas[6].pos_inicial_x = 140;
	pecasPuzzle.pecas[6].pos_inicial_y = 140;
	pecasPuzzle.pecas[6].pos_atual_x = 140;
	pecasPuzzle.pecas[6].pos_atual_y = 140;
	pecasPuzzle.pecas[6].selecionada = false;

	pecasPuzzle.pecas[7].id = 8;
	pecasPuzzle.pecas[7].pos_inicial_x = 140;
	pecasPuzzle.pecas[7].pos_inicial_y = 260;
	pecasPuzzle.pecas[7].pos_atual_x = 140;
	pecasPuzzle.pecas[7].pos_atual_y = 260;
	pecasPuzzle.pecas[7].selecionada = false;

	pecasPuzzle.pecas[8].id = 9;
	pecasPuzzle.pecas[8].pos_inicial_x = 1150;
	pecasPuzzle.pecas[8].pos_inicial_y = 20;
	pecasPuzzle.pecas[8].pos_atual_x = 1150;
	pecasPuzzle.pecas[8].pos_atual_y = 20;
	pecasPuzzle.pecas[8].selecionada = false;

	pecasPuzzle.pecas[9].id = 10;
	pecasPuzzle.pecas[9].pos_inicial_x = 260;
	pecasPuzzle.pecas[9].pos_inicial_y = 500;
	pecasPuzzle.pecas[9].pos_atual_x = 260;
	pecasPuzzle.pecas[9].pos_atual_y = 500;
	pecasPuzzle.pecas[9].selecionada = false;

	pecasPuzzle.pecas[10].id = 11;
	pecasPuzzle.pecas[10].pos_inicial_x = 1030;
	pecasPuzzle.pecas[10].pos_inicial_y = 500;
	pecasPuzzle.pecas[10].pos_atual_x = 1030;
	pecasPuzzle.pecas[10].pos_atual_y = 500;
	pecasPuzzle.pecas[10].selecionada = false;

	pecasPuzzle.pecas[11].id = 12;
	pecasPuzzle.pecas[11].pos_inicial_x = 140;
	pecasPuzzle.pecas[11].pos_inicial_y = 380;
	pecasPuzzle.pecas[11].pos_atual_x = 140;
	pecasPuzzle.pecas[11].pos_atual_y = 380;
	pecasPuzzle.pecas[11].selecionada = false;

	pecasPuzzle.pecas[12].id = 13;
	pecasPuzzle.pecas[12].pos_inicial_x = 1030;
	pecasPuzzle.pecas[12].pos_inicial_y = 20;
	pecasPuzzle.pecas[12].pos_atual_x = 1030;
	pecasPuzzle.pecas[12].pos_atual_y = 20;
	pecasPuzzle.pecas[12].selecionada = false;

	pecasPuzzle.pecas[13].id = 14;
	pecasPuzzle.pecas[13].pos_inicial_x = 260;
	pecasPuzzle.pecas[13].pos_inicial_y = 140;
	pecasPuzzle.pecas[13].pos_atual_x = 260;
	pecasPuzzle.pecas[13].pos_atual_y = 140;
	pecasPuzzle.pecas[13].selecionada = false;

	pecasPuzzle.pecas[14].id = 15;
	pecasPuzzle.pecas[14].pos_inicial_x = 1030;
	pecasPuzzle.pecas[14].pos_inicial_y = 140;
	pecasPuzzle.pecas[14].pos_atual_x = 1030;
	pecasPuzzle.pecas[14].pos_atual_y = 140;
	pecasPuzzle.pecas[14].selecionada = false;

	pecasPuzzle.pecas[15].id = 16;
	pecasPuzzle.pecas[15].pos_inicial_x = 1030;
	pecasPuzzle.pecas[15].pos_inicial_y = 260;
	pecasPuzzle.pecas[15].pos_atual_x = 1030;
	pecasPuzzle.pecas[15].pos_atual_y = 260;
	pecasPuzzle.pecas[15].selecionada = false;

	pecasPuzzle.pecas[16].id = 17;
	pecasPuzzle.pecas[16].pos_inicial_x = 1030;
	pecasPuzzle.pecas[16].pos_inicial_y = 380;
	pecasPuzzle.pecas[16].pos_atual_x = 1030;
	pecasPuzzle.pecas[16].pos_atual_y = 380;
	pecasPuzzle.pecas[16].selecionada = false;

	pecasPuzzle.pecas[17].id = 18;
	pecasPuzzle.pecas[17].pos_inicial_x = 1150;
	pecasPuzzle.pecas[17].pos_inicial_y = 140;
	pecasPuzzle.pecas[17].pos_atual_x = 1150;
	pecasPuzzle.pecas[17].pos_atual_y = 140;
	pecasPuzzle.pecas[17].selecionada = false;

	pecasPuzzle.pecas[18].id = 19;
	pecasPuzzle.pecas[18].pos_inicial_x = 1150;
	pecasPuzzle.pecas[18].pos_inicial_y = 260;
	pecasPuzzle.pecas[18].pos_atual_x = 1150;
	pecasPuzzle.pecas[18].pos_atual_y = 260;
	pecasPuzzle.pecas[18].selecionada = false;

	pecasPuzzle.pecas[19].id = 20;
	pecasPuzzle.pecas[19].pos_inicial_x = 1150;
	pecasPuzzle.pecas[19].pos_inicial_y = 380;
	pecasPuzzle.pecas[19].pos_atual_x = 1150;
	pecasPuzzle.pecas[19].pos_atual_y = 380;
	pecasPuzzle.pecas[19].selecionada = false;

	pecasPuzzle.pecas[20].id = 21;
	pecasPuzzle.pecas[20].pos_inicial_x = 1150;
	pecasPuzzle.pecas[20].pos_inicial_y = 500;
	pecasPuzzle.pecas[20].pos_atual_x = 1150;
	pecasPuzzle.pecas[20].pos_atual_y = 500;
	pecasPuzzle.pecas[20].selecionada = false;

	pecasPuzzle.pecas[21].id = 22;
	pecasPuzzle.pecas[21].pos_inicial_x = 20;
	pecasPuzzle.pecas[21].pos_inicial_y = 500;
	pecasPuzzle.pecas[21].pos_atual_x = 20;
	pecasPuzzle.pecas[21].pos_atual_y = 500;
	pecasPuzzle.pecas[21].selecionada = false;

	pecasPuzzle.pecas[22].id = 23;
	pecasPuzzle.pecas[22].pos_inicial_x = 260;
	pecasPuzzle.pecas[22].pos_inicial_y = 260;
	pecasPuzzle.pecas[22].pos_atual_x = 260;
	pecasPuzzle.pecas[22].pos_atual_y = 260;
	pecasPuzzle.pecas[22].selecionada = false;

	pecasPuzzle.pecas[23].id = 24;
	pecasPuzzle.pecas[23].pos_inicial_x = 260;
	pecasPuzzle.pecas[23].pos_inicial_y = 380;
	pecasPuzzle.pecas[23].pos_atual_x = 260;
	pecasPuzzle.pecas[23].pos_atual_y = 380;
	pecasPuzzle.pecas[23].selecionada = false;

	pecasPuzzle.pecas[24].id = 25;
	pecasPuzzle.pecas[24].pos_inicial_x = 140;
	pecasPuzzle.pecas[24].pos_inicial_y = 500;
	pecasPuzzle.pecas[24].pos_atual_x = 140;
	pecasPuzzle.pecas[24].pos_atual_y = 500;
	pecasPuzzle.pecas[24].selecionada = false;

	quadrantePuzzle.quadrantes[0].id = 1;
	quadrantePuzzle.quadrantes[0].X = 415;
	quadrantePuzzle.quadrantes[0].Y = 70;
	quadrantePuzzle.quadrantes[0].contemPeca = false;

	quadrantePuzzle.quadrantes[1].id = 2;
	quadrantePuzzle.quadrantes[1].X = 530;
	quadrantePuzzle.quadrantes[1].Y = 70;
	quadrantePuzzle.quadrantes[1].contemPeca = false;

	quadrantePuzzle.quadrantes[2].id = 3;
	quadrantePuzzle.quadrantes[2].X = 645;
	quadrantePuzzle.quadrantes[2].Y = 70;
	quadrantePuzzle.quadrantes[2].contemPeca = false;

	quadrantePuzzle.quadrantes[3].id = 4;
	quadrantePuzzle.quadrantes[3].X = 760;
	quadrantePuzzle.quadrantes[3].Y = 70;
	quadrantePuzzle.quadrantes[3].contemPeca = false;

	quadrantePuzzle.quadrantes[4].id = 5;
	quadrantePuzzle.quadrantes[4].X = 875;
	quadrantePuzzle.quadrantes[4].Y = 70;
	quadrantePuzzle.quadrantes[4].contemPeca = false;

	quadrantePuzzle.quadrantes[5].id = 6;
	quadrantePuzzle.quadrantes[5].X = 415;
	quadrantePuzzle.quadrantes[5].Y = 185;
	quadrantePuzzle.quadrantes[5].contemPeca = false;

	quadrantePuzzle.quadrantes[6].id = 7;
	quadrantePuzzle.quadrantes[6].X = 530;
	quadrantePuzzle.quadrantes[6].Y = 185;
	quadrantePuzzle.quadrantes[6].contemPeca = false;

	quadrantePuzzle.quadrantes[7].id = 8;
	quadrantePuzzle.quadrantes[7].X = 645;
	quadrantePuzzle.quadrantes[7].Y = 185;
	quadrantePuzzle.quadrantes[7].contemPeca = false;

	quadrantePuzzle.quadrantes[8].id = 9;
	quadrantePuzzle.quadrantes[8].X = 760;
	quadrantePuzzle.quadrantes[8].Y = 185;
	quadrantePuzzle.quadrantes[8].contemPeca = false;

	quadrantePuzzle.quadrantes[9].id = 10;
	quadrantePuzzle.quadrantes[9].X = 875;
	quadrantePuzzle.quadrantes[9].Y = 185;
	quadrantePuzzle.quadrantes[9].contemPeca = false;

	quadrantePuzzle.quadrantes[10].id = 11;
	quadrantePuzzle.quadrantes[10].X = 415;
	quadrantePuzzle.quadrantes[10].Y = 300;
	quadrantePuzzle.quadrantes[10].contemPeca = false;

	quadrantePuzzle.quadrantes[11].id = 12;
	quadrantePuzzle.quadrantes[11].X = 530;
	quadrantePuzzle.quadrantes[11].Y = 300;
	quadrantePuzzle.quadrantes[11].contemPeca = false;

	quadrantePuzzle.quadrantes[12].id = 13;
	quadrantePuzzle.quadrantes[12].X = 645;
	quadrantePuzzle.quadrantes[12].Y = 300;
	quadrantePuzzle.quadrantes[12].contemPeca = false;

	quadrantePuzzle.quadrantes[13].id = 14;
	quadrantePuzzle.quadrantes[13].X = 760;
	quadrantePuzzle.quadrantes[13].Y = 300;
	quadrantePuzzle.quadrantes[13].contemPeca = false;

	quadrantePuzzle.quadrantes[14].id = 15;
	quadrantePuzzle.quadrantes[14].X = 875;
	quadrantePuzzle.quadrantes[14].Y = 300;
	quadrantePuzzle.quadrantes[14].contemPeca = false;

	quadrantePuzzle.quadrantes[15].id = 16;
	quadrantePuzzle.quadrantes[15].X = 415;
	quadrantePuzzle.quadrantes[15].Y = 415;
	quadrantePuzzle.quadrantes[15].contemPeca = false;

	quadrantePuzzle.quadrantes[16].id = 17;
	quadrantePuzzle.quadrantes[16].X = 530;
	quadrantePuzzle.quadrantes[16].Y = 415;
	quadrantePuzzle.quadrantes[16].contemPeca = false;

	quadrantePuzzle.quadrantes[17].id = 18;
	quadrantePuzzle.quadrantes[17].X = 645;
	quadrantePuzzle.quadrantes[17].Y = 415;
	quadrantePuzzle.quadrantes[17].contemPeca = false;

	quadrantePuzzle.quadrantes[18].id = 19;
	quadrantePuzzle.quadrantes[18].X = 760;
	quadrantePuzzle.quadrantes[18].Y = 415;
	quadrantePuzzle.quadrantes[18].contemPeca = false;

	quadrantePuzzle.quadrantes[19].id = 20;
	quadrantePuzzle.quadrantes[19].X = 875;
	quadrantePuzzle.quadrantes[19].Y = 415;
	quadrantePuzzle.quadrantes[19].contemPeca = false;

	quadrantePuzzle.quadrantes[20].id = 21;
	quadrantePuzzle.quadrantes[20].X = 415;
	quadrantePuzzle.quadrantes[20].Y = 530;
	quadrantePuzzle.quadrantes[20].contemPeca = false;

	quadrantePuzzle.quadrantes[21].id = 22;
	quadrantePuzzle.quadrantes[21].X = 530;
	quadrantePuzzle.quadrantes[21].Y = 530;
	quadrantePuzzle.quadrantes[21].contemPeca = false;

	quadrantePuzzle.quadrantes[22].id = 23;
	quadrantePuzzle.quadrantes[22].X = 645;
	quadrantePuzzle.quadrantes[22].Y = 530;
	quadrantePuzzle.quadrantes[22].contemPeca = false;

	quadrantePuzzle.quadrantes[23].id = 24;
	quadrantePuzzle.quadrantes[23].X = 760;
	quadrantePuzzle.quadrantes[23].Y = 530;
	quadrantePuzzle.quadrantes[23].contemPeca = false;

	quadrantePuzzle.quadrantes[24].id = 25;
	quadrantePuzzle.quadrantes[24].X = 875;
	quadrantePuzzle.quadrantes[24].Y = 530;
	quadrantePuzzle.quadrantes[24].contemPeca = false;
}

void fase3(ALLEGRO_EVENT evento) {

	al_draw_bitmap(imgFundoPuzzle, 0, 0, 0);

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseAxesX = evento.mouse.x;
		mouseAxesY = evento.mouse.y;
		/*printf("\nMOUSE X %d\n", mouseX);
		printf("MOUSE Y %d\n", mouseY);*/
	}
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
		//printf("\nMOUSE X %d\n", mouseX);
		//printf("MOUSE Y %d\n", mouseY);
	}

	// Lógica do Quebra-Cabeça

	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		// Verifica se há alguma peça selecionada, havendo, a peça é colocada dentro do quadrante clicado setado falso para peça selecionada
		for (int j = 0; j < 25; j++) {
			// Seleciona a peça de sua posicao inicial
			if ((mouseX >= posicoesIniciais.posicoes[j].x && mouseX <= posicoesIniciais.posicoes[j].x + 110) && (mouseY >= posicoesIniciais.posicoes[j].y && mouseY <= posicoesIniciais.posicoes[j].y + 110) && posicoesIniciais.posicoes[j].contemPeca == true) {
				indice = j;
				idPeca = pecasPuzzle.pecas[j].id;
				marcacaoX = posicoesIniciais.posicoes[j].x;
				marcacaoY = posicoesIniciais.posicoes[j].y;
				first = true;
				pecaSelecionada = true;
				//printf("\n1 ID PECA POSICAO INICIAL %d\n", idPeca);
			}

			// Verifica se há alguma peça selecionada, não havendo, a peça é colocada dentro do quadrante clicado setado falso para peça selecionada
			if (pecaSelecionada == true) {
				if ((mouseX >= quadrantePuzzle.quadrantes[j].X && mouseX <= quadrantePuzzle.quadrantes[j].X + 105) && (mouseY >= quadrantePuzzle.quadrantes[j].Y && mouseY <= quadrantePuzzle.quadrantes[j].Y + 105) && quadrantePuzzle.quadrantes[j].contemPeca == false) {
					quadrantePuzzle.quadrantes[j].idPecaRecebida = idPeca;
					guardaIdQuadrante[btoVolta] = quadrantePuzzle.quadrantes[j].id;
					guardaIdPeca[btoVolta] = idPeca;
					pecasPuzzle.pecas[indice].pos_atual_x = quadrantePuzzle.quadrantes[j].X;
					pecasPuzzle.pecas[indice].pos_atual_y = quadrantePuzzle.quadrantes[j].Y;
					quadrantePuzzle.quadrantes[j].contemPeca = true;
					posicoesIniciais.posicoes[indice].contemPeca = false;
					salvaIndice[btoVolta] = indice;
					foiPosicionada = true;
					pecaSelecionada = false;
					btoVolta += 1;
					somaPosicao += 1;
					nextInt += 1;
					//printf("2 ID Quadrante %d\n", idQuadrante);
				}
			}
			if ((mouseX >= quadrantePuzzle.quadrantes[j].X && mouseX <= quadrantePuzzle.quadrantes[j].X + 105) && (mouseY >= quadrantePuzzle.quadrantes[j].Y && mouseY <= quadrantePuzzle.quadrantes[j].Y + 105)) {
				marcacaoX = quadrantePuzzle.quadrantes[j].X;
				marcacaoY = quadrantePuzzle.quadrantes[j].Y;
				/*printf("%s\n", quadrantePuzzle.quadrantes[j].contemPeca ? "true" : "false");*/
				first = true;
			}

			// Move o marcador para as áreas iniciais do quadrante branco das posições iniciais
			if ((mouseX >= posicoesIniciais.posicoes[j].x && mouseX <= posicoesIniciais.posicoes[j].x + 110) && (mouseY >= posicoesIniciais.posicoes[j].y && mouseY <= posicoesIniciais.posicoes[j].y + 110)) {
				/*printf("\nID FORA %d\n", posicoesIniciais.posicoes[j].id);*/
				marcacaoX = posicoesIniciais.posicoes[j].x;
				marcacaoY = posicoesIniciais.posicoes[j].y;
				first = true;
			}
		}
	}

	// Area imagem puzzle
	al_draw_filled_rectangle(415, 65, 990, 645, al_map_rgb(255, 255, 255));
	desenhaQuadrados();

	//Colocando as imagens fora da área do retângulo
	al_draw_bitmap(arrayPuzzle[0], pecasPuzzle.pecas[0].pos_atual_x, pecasPuzzle.pecas[0].pos_atual_y, 0);
	al_draw_bitmap(arrayPuzzle[1], pecasPuzzle.pecas[1].pos_atual_x, pecasPuzzle.pecas[1].pos_atual_y, 0);	// Superior esquerda
	al_draw_bitmap(arrayPuzzle[2], pecasPuzzle.pecas[2].pos_atual_x, pecasPuzzle.pecas[2].pos_atual_y, 0);	// Inferior esquerda
	al_draw_bitmap(arrayPuzzle[3], pecasPuzzle.pecas[3].pos_atual_x, pecasPuzzle.pecas[3].pos_atual_y, 0);	// Inferior esquerda
	al_draw_bitmap(arrayPuzzle[4], pecasPuzzle.pecas[4].pos_atual_x, pecasPuzzle.pecas[4].pos_atual_y, 0);	// Superior direita
	al_draw_bitmap(arrayPuzzle[5], pecasPuzzle.pecas[5].pos_atual_x, pecasPuzzle.pecas[5].pos_atual_y, 0);	// Superior direita
	al_draw_bitmap(arrayPuzzle[6], pecasPuzzle.pecas[6].pos_atual_x, pecasPuzzle.pecas[6].pos_atual_y, 0);	// Inferior direita
	al_draw_bitmap(arrayPuzzle[7], pecasPuzzle.pecas[7].pos_atual_x, pecasPuzzle.pecas[7].pos_atual_y, 0);	// Inferior direita
	al_draw_bitmap(arrayPuzzle[8], pecasPuzzle.pecas[8].pos_atual_x, pecasPuzzle.pecas[8].pos_atual_y, 0);	// Centro direita
	al_draw_bitmap(arrayPuzzle[9], pecasPuzzle.pecas[9].pos_atual_x, pecasPuzzle.pecas[9].pos_atual_y, 0);  // Centro direita
	al_draw_bitmap(arrayPuzzle[10], pecasPuzzle.pecas[10].pos_atual_x, pecasPuzzle.pecas[10].pos_atual_y, 0);	// Superior centro
	al_draw_bitmap(arrayPuzzle[11], pecasPuzzle.pecas[11].pos_atual_x, pecasPuzzle.pecas[11].pos_atual_y, 0);	// Centro esquerda
	al_draw_bitmap(arrayPuzzle[12], pecasPuzzle.pecas[12].pos_atual_x, pecasPuzzle.pecas[12].pos_atual_y, 0);	// Superior centro
	al_draw_bitmap(arrayPuzzle[13], pecasPuzzle.pecas[13].pos_atual_x, pecasPuzzle.pecas[13].pos_atual_y, 0);	// Superior centro
	al_draw_bitmap(arrayPuzzle[14], pecasPuzzle.pecas[14].pos_atual_x, pecasPuzzle.pecas[14].pos_atual_y, 0);	// Inferior centro
	al_draw_bitmap(arrayPuzzle[15], pecasPuzzle.pecas[15].pos_atual_x, pecasPuzzle.pecas[15].pos_atual_y, 0);	// Inferior centro
	al_draw_bitmap(arrayPuzzle[16], pecasPuzzle.pecas[16].pos_atual_x, pecasPuzzle.pecas[16].pos_atual_y, 0);	// Superior esquerda
	al_draw_bitmap(arrayPuzzle[17], pecasPuzzle.pecas[17].pos_atual_x, pecasPuzzle.pecas[17].pos_atual_y, 0); // Inferior esquerda
	al_draw_bitmap(arrayPuzzle[18], pecasPuzzle.pecas[18].pos_atual_x, pecasPuzzle.pecas[18].pos_atual_y, 0); // Superior direita
	al_draw_bitmap(arrayPuzzle[19], pecasPuzzle.pecas[19].pos_atual_x, pecasPuzzle.pecas[19].pos_atual_y, 0); // Inferior direita
	al_draw_bitmap(arrayPuzzle[20], pecasPuzzle.pecas[20].pos_atual_x, pecasPuzzle.pecas[20].pos_atual_y, 0); // Centro esquerda
	al_draw_bitmap(arrayPuzzle[21], pecasPuzzle.pecas[21].pos_atual_x, pecasPuzzle.pecas[21].pos_atual_y, 0);	// Centro esquerda
	al_draw_bitmap(arrayPuzzle[22], pecasPuzzle.pecas[22].pos_atual_x, pecasPuzzle.pecas[22].pos_atual_y, 0); // Centro esquerda
	al_draw_bitmap(arrayPuzzle[23], pecasPuzzle.pecas[23].pos_atual_x, pecasPuzzle.pecas[23].pos_atual_y, 0); // Centro direita
	al_draw_bitmap(arrayPuzzle[24], pecasPuzzle.pecas[24].pos_atual_x, pecasPuzzle.pecas[24].pos_atual_y, 0);	// Centro direita

	if (foiPosicionada == true) {
		marcacaoX = -78745;
		marcacaoY = -78745;
		foiPosicionada = false;
	}

	// Verificação para desenhar um quadrado no entorno da peça selecionada apenas quando tiver uma peça selecionada
	if (first == true) {
		al_draw_rectangle(marcacaoX - 4.5, marcacaoY - 4.5, marcacaoX + 115, marcacaoY + 115, al_map_rgb(238, 173, 45), 9);
	}

	al_draw_textf(fonteMenu, al_map_rgb(255, 255, 255), 680, 10, ALLEGRO_ALIGN_CENTRE, "Creditos de Imagem: %d", contadorCreditos);

	if (next == false) {
		if (contadorCreditos >= 1) {
			al_draw_filled_rectangle(520, 665, 880, 710, al_map_rgb(222, 158, 30));
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 700, 665, ALLEGRO_ALIGN_CENTRE, "Ver Puzzle Completo");
			if ((mouseAxesX >= 520 && mouseAxesX <= 880) && (mouseAxesY >= 665 && mouseAxesY <= 710)) {
				al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
				if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && contadorCreditos > 0) {
					imagemPuzzle();
				}
			}
			else {
				al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
			}
		}
		else if (contadorCreditos < 1) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
			al_draw_filled_rectangle(520, 665, 880, 710, al_map_rgb(222, 158, 30));
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 700, 665, ALLEGRO_ALIGN_CENTRE, "Ver Puzzle Completo");
			al_draw_filled_rectangle(520, 665, 880, 710, al_map_rgba(50, 50, 50, 128));
		}

		// Faz o cada peça movida na sequencia voltar para sua posição inicial
		if (btoVolta > 0) {
			al_draw_filled_rectangle(91, 640, 301, 682, al_map_rgb(222, 158, 30));
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 195, 640, ALLEGRO_ALIGN_CENTRE, "Voltar Peca");
		}
		else {
			al_draw_filled_rectangle(91, 640, 301, 682, al_map_rgb(222, 158, 30));
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 195, 640, ALLEGRO_ALIGN_CENTRE, "Voltar Peca");
			al_draw_filled_rectangle(91, 640, 301, 682, al_map_rgba(50, 50, 50, 128));
		}
		if ((mouseAxesX >= 91 && mouseAxesX <= 301) && (mouseAxesY >= 640 && mouseAxesY <= 682) && btoVolta > 0) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
			if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				swapIDQuadrante = guardaIdQuadrante[somaPosicao - 1];
				swapIDPeca = guardaIdPeca[somaPosicao - 1];
				swapIndice = salvaIndice[somaPosicao - 1];
				pecasPuzzle.pecas[swapIDPeca - 1].pos_atual_x = pecasPuzzle.pecas[swapIDPeca - 1].pos_inicial_x;
				pecasPuzzle.pecas[swapIDPeca - 1].pos_atual_y = pecasPuzzle.pecas[swapIDPeca - 1].pos_inicial_y;
				quadrantePuzzle.quadrantes[swapIDQuadrante - 1].contemPeca = false;
				posicoesIniciais.posicoes[swapIndice].contemPeca = true;
				guardaIdQuadrante[btoVolta - 1] = 8980;
				guardaIdPeca[btoVolta - 1] = 8781;
				salvaIndice[btoVolta - 1] = 8781;
				somaPosicao -= 1;
				btoVolta -= 1;
				nextInt -= 1;
			}
		}
	}
	// Valida as posições para liberar o botão de próximo
	if (nextInt == 25) {
		for (int i = 0; i < 25; i++) {
			//printf("Sequencia de id %d\n", quadrantePuzzle.quadrantes[i].idPecaRecebida);
			if (quadrantePuzzle.quadrantes[i].idPecaRecebida == arrayVerificador[i]) {
				somaVerificadora += 1;
				//printf("SOMAVERIFICADORA %d", somaVerificadora);
			}
			else {
				somaVerificadora = 0;
			}
			if (somaVerificadora == 25) {
				next = true;
			}
		}
	}

	if (next == true) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
		al_draw_filled_rectangle(1065, 650, 1225, 690, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1145, 648, ALLEGRO_ALIGN_CENTRE, "Proximo");

		al_draw_filled_rectangle(520, 665, 880, 710, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 700, 665, ALLEGRO_ALIGN_CENTRE, "Ver Puzzle Completo");
		al_draw_filled_rectangle(520, 665, 880, 710, al_map_rgba(50, 50, 50, 128));

		al_draw_filled_rectangle(91, 640, 301, 682, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 195, 640, ALLEGRO_ALIGN_CENTRE, "Voltar Peca");
		al_draw_filled_rectangle(91, 640, 301, 682, al_map_rgba(50, 50, 50, 128));

		if ((mouseAxesX >= 1065 && mouseAxesX <= 1225) && (mouseAxesY >= 650 && mouseAxesY <= 690)) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
			if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

				for (int i = 0; i < 25; i++) {
					guardaIdPeca[i] = 0;
					salvaIndice[i] = 0;
				}
				for (int j = 0; j < 26; j++) {
					guardaIdQuadrante[j] = 0;
				}
				resetF3();
				somaVerificadora = 0;
				nextInt = 0;
				btoVolta = 0;
				somaPosicao = 0;
				contadorCreditos = 3;
				first = false;
				next = false;
				swapAtivo = false;
				verificaPuzzle = true;
				foiPosicionada = false;
				pecaSelecionada = false;
				navegacao += 1;
			}
		}
	}
	al_flip_display();
}