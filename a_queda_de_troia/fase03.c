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
	for (int x = 360; x < 360 + 550; x += 116) {
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

	//if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
	//	evento.mouse.x = evento.mouse.x;
	//	evento.mouse.y = evento.mouse.y;
	//	/*printf("\nMOUSE X %d\n", evento.mouse.x);
	//	printf("MOUSE Y %d\n", evento.mouse.y);*/
	//}

	//if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
	//	evento.mouse.x = evento.mouse.x;
	//	evento.mouse.y = evento.mouse.y;
	//	/*printf("\nMOUSE X %d\n", evento.mouse.x);
	//	printf("MOUSE Y %d\n", evento.mouse.y);*/
	//}

	// Lógica do Quebra-Cabeça
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		// Verifica se há alguma peça selecionada, havendo, a peça é colocada dentro do quadrante clicado setado falso para peça selecionada
		for (int j = 0; j < 25; j++) {
			// Seleciona a peça de sua posicao inicial
			if ((evento.mouse.x >= posicoesIniciais.posicoes[j].x && evento.mouse.x <= posicoesIniciais.posicoes[j].x + 110) && (evento.mouse.y >= posicoesIniciais.posicoes[j].y && evento.mouse.y <= posicoesIniciais.posicoes[j].y + 110) && posicoesIniciais.posicoes[j].contemPeca == true) {
				idPeca = pecasPuzzle.pecas[j].id;
				marcacaoX = posicoesIniciais.posicoes[j].x;
				marcacaoY = posicoesIniciais.posicoes[j].y;
				indice = j;
				first = true;
				pecaSelecionada = true;
				printf("\n1 ID PECA POSICAO INICIAL %d\n", idPeca);
			}

			// Verifica se há alguma peça selecionada, não havendo, a peça é colocada dentro do quadrante clicado setado falso para peça selecionada
			if (pecaSelecionada == true) {
				if ((evento.mouse.x >= quadrantePuzzle.quadrantes[j].X && evento.mouse.x <= quadrantePuzzle.quadrantes[j].X + 105) && (evento.mouse.y >= quadrantePuzzle.quadrantes[j].Y && evento.mouse.y <= quadrantePuzzle.quadrantes[j].Y + 105) && quadrantePuzzle.quadrantes[j].contemPeca == false) {
					//idQuadrante = quadrantePuzzle.quadrantes[j].id;
					quadrantePuzzle.quadrantes[j].idPecaRecebida = idPeca;
					guardaMovimentacao[somaPosicao] = indice;
					guardaIdPuzzle[somaPosicao] = j;
					quadrantePuzzle.quadrantes[j].contemPeca = true;
					somaPosicao += 1;
					guardaIdPuzzle[j] = j;
					nextInt += 1;
					//indiceQuadrante += 1;
					pecasPuzzle.pecas[indice].pos_atual_x = quadrantePuzzle.quadrantes[j].X;
					pecasPuzzle.pecas[indice].pos_atual_y = quadrantePuzzle.quadrantes[j].Y;
					posicoesIniciais.posicoes[indice].contemPeca = false;
					pecaSelecionada = false;
					printf("2 ID Quadrante %d\n", idQuadrante);
				}
			}

			// movimentação do marcador em todas as posições do quadrante
			if ((evento.mouse.x >= quadrantePuzzle.quadrantes[j].X && evento.mouse.x <= quadrantePuzzle.quadrantes[j].X + 105) && (evento.mouse.y >= quadrantePuzzle.quadrantes[j].Y && evento.mouse.y <= quadrantePuzzle.quadrantes[j].Y + 105)) {
				marcacaoX = quadrantePuzzle.quadrantes[j].X;
				marcacaoY = quadrantePuzzle.quadrantes[j].Y;
				printf("\nContem Peca 1 %s\n", quadrantePuzzle.quadrantes[j].contemPeca ? "true" : "false");
				printf("ID Quadrante %d\n", quadrantePuzzle.quadrantes[j].id);
				first = true;
			}

			// Move o marcador para as áreas iniciais do quadrante branco das posições iniciais
			if ((evento.mouse.x >= posicoesIniciais.posicoes[j].x && evento.mouse.x <= posicoesIniciais.posicoes[j].x + 110) && (evento.mouse.y >= posicoesIniciais.posicoes[j].y && evento.mouse.y <= posicoesIniciais.posicoes[j].y + 110)) {
				printf("\nID FORA %d\n", posicoesIniciais.posicoes[j].id);
				marcacaoX = posicoesIniciais.posicoes[j].x;
				marcacaoY = posicoesIniciais.posicoes[j].y;
				/*printf("\nContem Peca 2 %s\n", posicoesIniciais.posicoes[j].contemPeca ? "true" : "false");*/
				first = true;
			}
		}
	}

	// Area imagem puzzle
	al_draw_filled_rectangle(360, 65, 940, 645, al_map_rgb(255, 255, 255));
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

	// Verificação para desenhar um quadrado no entorno da peça selecionada apenas quando tiver uma peça selecionada
	if (first == true) {
		al_draw_rectangle(marcacaoX - 4.5, marcacaoY - 4.5, marcacaoX + 115, marcacaoY + 115, al_map_rgb(238, 173, 45), 9);
	}

	al_draw_textf(fonteMenu, al_map_rgb(255, 255, 255), 640, 10, ALLEGRO_ALIGN_CENTRE, "Creditos de Imagem: %d", contadorCreditos);

	if (next == false) {
		if (contadorCreditos >= 1) {
			al_draw_filled_rectangle(460, 665, 820, 710, al_map_rgb(222, 158, 30));
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 665, ALLEGRO_ALIGN_CENTRE, "Ver Puzzle Completo");
			if ((evento.mouse.x >= 460 && evento.mouse.x <= 820) && (evento.mouse.y >= 665 && evento.mouse.y <= 710)) {
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
			al_draw_filled_rectangle(460, 665, 820, 710, al_map_rgb(222, 158, 30));
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 665, ALLEGRO_ALIGN_CENTRE, "Ver Puzzle Completo");
			al_draw_filled_rectangle(460, 665, 820, 710, al_map_rgba(50, 50, 50, 128));
		}

		// Faz o cada peça movida na sequencia voltar para sua posição inicial
		if (somaPosicao > 0) {
			al_draw_filled_rectangle(75, 670, 285, 712, al_map_rgb(222, 158, 30));
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 180, 670, ALLEGRO_ALIGN_CENTRE, "Voltar Peca");
		}
		else {
			al_draw_filled_rectangle(75, 670, 285, 712, al_map_rgb(222, 158, 30));
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 180, 670, ALLEGRO_ALIGN_CENTRE, "Voltar Peca");
			al_draw_filled_rectangle(75, 670, 285, 712, al_map_rgba(50, 50, 50, 128));
		}
		if ((evento.mouse.x >= 75 && evento.mouse.x <= 285) && (evento.mouse.y >= 670 && evento.mouse.y <= 712) && somaPosicao > 0) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
			if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				nextInt -= 1;
				somaPosicao -= 1;
				swapDaPeca = guardaMovimentacao[somaPosicao];
				quadrantePuzzle.quadrantes[guardaIdPuzzle[somaPosicao]].contemPeca = false;
				quadrantePuzzle.quadrantes[swapDaPeca].contemPeca = false;
				posicoesIniciais.posicoes[swapDaPeca].contemPeca = true;
				pecasPuzzle.pecas[swapDaPeca].pos_atual_x = pecasPuzzle.pecas[swapDaPeca].pos_inicial_x;
				pecasPuzzle.pecas[swapDaPeca].pos_atual_y = pecasPuzzle.pecas[swapDaPeca].pos_inicial_y;
				printf("\n");
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
		al_draw_filled_rectangle(1040, 650, 1220, 690, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1130, 648, ALLEGRO_ALIGN_CENTRE, "Proximo");

		al_draw_filled_rectangle(460, 665, 820, 710, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 665, ALLEGRO_ALIGN_CENTRE, "Ver Puzzle Completo");
		al_draw_filled_rectangle(460, 665, 820, 710, al_map_rgba(50, 50, 50, 128));

		al_draw_filled_rectangle(75, 670, 285, 712, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 180, 670, ALLEGRO_ALIGN_CENTRE, "Voltar Peca");
		al_draw_filled_rectangle(75, 670, 285, 712, al_map_rgba(50, 50, 50, 128));

		if ((evento.mouse.x >= 1040 && evento.mouse.x <= 1220) && (evento.mouse.y >= 650 && evento.mouse.y <= 690)) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
			if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				navegacao += 1;
			}
		}
	}

	al_flip_display();
}