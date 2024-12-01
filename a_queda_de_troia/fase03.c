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
		printf("\n");
		for (int i = 0; i < 25; i++) {
			/*printf("GUARDA ID %d", guardaIdPeca[i]);
			printf(" - GUARDA ID QUADRANTE %d ", guardaIdQuadrante[i]);*/
			/*printf("ID PECA %d ", guardaIdPeca[i]);*/
			//printf("ID SALVA INDICE %d ", salvaIndice[i]);
			//printf("Quadrante %d %s", i, quadrantePuzzle.quadrantes[i].contemPeca ? "true" : "false");
			//printf("Posicao Inicial %d %s", i, posicoesIniciais.posicoes[i].contemPeca ? "true" : "false");
			printf("\n");
		}
		printf("\n");

		printf("BTO VOLTA %d\n", btoVolta);
	}

	// Area imagem puzzle
	al_draw_filled_rectangle(415, 65, 990, 645, al_map_rgb(255, 255, 255));
	desenhaQuadrados();

	//Colocando as imagens fora da área do retângulo
	al_draw_bitmap(puzzle1, pecasPuzzle.pecas[0].pos_atual_x, pecasPuzzle.pecas[0].pos_atual_y, 0);
	al_draw_bitmap(puzzle2, pecasPuzzle.pecas[1].pos_atual_x, pecasPuzzle.pecas[1].pos_atual_y, 0);	// Superior esquerda
	al_draw_bitmap(puzzle3, pecasPuzzle.pecas[2].pos_atual_x, pecasPuzzle.pecas[2].pos_atual_y, 0);	// Inferior esquerda
	al_draw_bitmap(puzzle4, pecasPuzzle.pecas[3].pos_atual_x, pecasPuzzle.pecas[3].pos_atual_y, 0);	// Inferior esquerda
	al_draw_bitmap(puzzle5, pecasPuzzle.pecas[4].pos_atual_x, pecasPuzzle.pecas[4].pos_atual_y, 0);	// Superior direita
	al_draw_bitmap(puzzle6, pecasPuzzle.pecas[5].pos_atual_x, pecasPuzzle.pecas[5].pos_atual_y, 0);	// Superior direita
	al_draw_bitmap(puzzle7, pecasPuzzle.pecas[6].pos_atual_x, pecasPuzzle.pecas[6].pos_atual_y, 0);	// Inferior direita
	al_draw_bitmap(puzzle8, pecasPuzzle.pecas[7].pos_atual_x, pecasPuzzle.pecas[7].pos_atual_y, 0);	// Inferior direita
	al_draw_bitmap(puzzle9, pecasPuzzle.pecas[8].pos_atual_x, pecasPuzzle.pecas[8].pos_atual_y, 0);	// Centro direita
	al_draw_bitmap(puzzle10, pecasPuzzle.pecas[9].pos_atual_x, pecasPuzzle.pecas[9].pos_atual_y, 0);  // Centro direita
	al_draw_bitmap(puzzle11, pecasPuzzle.pecas[10].pos_atual_x, pecasPuzzle.pecas[10].pos_atual_y, 0);	// Superior centro
	al_draw_bitmap(puzzle12, pecasPuzzle.pecas[11].pos_atual_x, pecasPuzzle.pecas[11].pos_atual_y, 0);	// Centro esquerda
	al_draw_bitmap(puzzle13, pecasPuzzle.pecas[12].pos_atual_x, pecasPuzzle.pecas[12].pos_atual_y, 0);	// Superior centro
	al_draw_bitmap(puzzle14, pecasPuzzle.pecas[13].pos_atual_x, pecasPuzzle.pecas[13].pos_atual_y, 0);	// Superior centro
	al_draw_bitmap(puzzle15, pecasPuzzle.pecas[14].pos_atual_x, pecasPuzzle.pecas[14].pos_atual_y, 0);	// Inferior centro
	al_draw_bitmap(puzzle16, pecasPuzzle.pecas[15].pos_atual_x, pecasPuzzle.pecas[15].pos_atual_y, 0);	// Inferior centro
	al_draw_bitmap(puzzle17, pecasPuzzle.pecas[16].pos_atual_x, pecasPuzzle.pecas[16].pos_atual_y, 0);	// Superior esquerda
	al_draw_bitmap(puzzle18, pecasPuzzle.pecas[17].pos_atual_x, pecasPuzzle.pecas[17].pos_atual_y, 0); // Inferior esquerda
	al_draw_bitmap(puzzle19, pecasPuzzle.pecas[18].pos_atual_x, pecasPuzzle.pecas[18].pos_atual_y, 0); // Superior direita
	al_draw_bitmap(puzzle20, pecasPuzzle.pecas[19].pos_atual_x, pecasPuzzle.pecas[19].pos_atual_y, 0); // Inferior direita
	al_draw_bitmap(puzzle21, pecasPuzzle.pecas[20].pos_atual_x, pecasPuzzle.pecas[20].pos_atual_y, 0); // Centro esquerda
	al_draw_bitmap(puzzle22, pecasPuzzle.pecas[21].pos_atual_x, pecasPuzzle.pecas[21].pos_atual_y, 0);	// Centro esquerda
	al_draw_bitmap(puzzle23, pecasPuzzle.pecas[22].pos_atual_x, pecasPuzzle.pecas[22].pos_atual_y, 0); // Centro esquerda
	al_draw_bitmap(puzzle24, pecasPuzzle.pecas[23].pos_atual_x, pecasPuzzle.pecas[23].pos_atual_y, 0); // Centro direita
	al_draw_bitmap(puzzle25, pecasPuzzle.pecas[24].pos_atual_x, pecasPuzzle.pecas[24].pos_atual_y, 0);	// Centro direita

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
				navegacao += 1;
			}
		}
	}
	al_flip_display();
}