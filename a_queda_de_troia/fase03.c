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
			al_draw_rectangle(x, y, x + 117, y + 116, al_map_rgb(0, 0, 0), 10);
		}
	}

	// Desenha linhas brancas nas posições iniciais
	for (int m = 0; m < 25; m++) {
		for (int n = 0; n < 25; n++) {
			al_draw_rectangle(posicaoInicialX[n] - 0.5, posicaoInicialY[n] - 0.5, posicaoInicialX[n] + 110, posicaoInicialY[n] + 110, al_map_rgb(255, 255, 255), 6);
		}
	}
}

void fase3(ALLEGRO_EVENT evento) {

	al_draw_bitmap(imgFundoPuzzle, 0, 0, 0);

	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
		printf("\nMOUSE X %d\n", mouseX);
		printf("MOUSE Y %d\n", mouseY);
	}

	// L�gica do Quebra-Cabeça
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		// Verifica se há alguma peça selecionada, havendo, a peça é colocada dentro do quadrante clicado setado falso para peça selecionada
		for (int j = 0; j < 25; j++) {
			// Seleciona a peça de sua posicao inicial
			if ((mouseX >= posicoesIniciais.posicoes[j].x && mouseX <= posicoesIniciais.posicoes[j].x + 110) && (mouseY >= posicoesIniciais.posicoes[j].y && mouseY <= posicoesIniciais.posicoes[j].y + 110) && posicoesIniciais.posicoes[j].contemPeca == true) {
				indice = j;
				idPeca = pecasPuzzle.pecas[j].id;
				pecaSelecionada = true;
				printf("ID PECA %d\n", idPeca);
				marcacaoX = posicoesIniciais.posicoes[j].x;
				marcacaoY = posicoesIniciais.posicoes[j].y;
				first = true;
			}

			// Verifica se há alguma peça selecionada, havendo, a peça é colocada dentro do quadrante clicado setado falso para peça selecionada
			if (pecaSelecionada == true) {
				if ((mouseX >= quadrantePuzzle.quadrantes[j].X && mouseX <= quadrantePuzzle.quadrantes[j].X + 105) && (mouseY >= quadrantePuzzle.quadrantes[j].Y && mouseY <= quadrantePuzzle.quadrantes[j].Y + 105) && quadrantePuzzle.quadrantes[j].contemPeca == false) {
					//idQuadrante = quadrantePuzzle.quadrantes[j].id;
					quadrantePuzzle.quadrantes[j].idPecaRecebida = idPeca;
					pecasPuzzle.pecas[indice].pos_atual_x = quadrantePuzzle.quadrantes[j].X;
					pecasPuzzle.pecas[indice].pos_atual_y = quadrantePuzzle.quadrantes[j].Y;
					posicoesIniciais.posicoes[indice].contemPeca = false;
					quadrantePuzzle.quadrantes[j].contemPeca = true;
					pecaSelecionada = false;
					printf("ID Quadrante %d\n", idQuadrante);
				}
			}

			//if ((mouseX >= posicoesIniciais.posicoes[j].x && mouseX <= posicoesIniciais.posicoes[j].x + 110) && (mouseY >= posicoesIniciais.posicoes[j].y && mouseY <= posicoesIniciais.posicoes[j].y + 110) && posicoesIniciais.posicoes[j].contemPeca == false && swapAtivo == true) {
			//	printf("ID P INICIAL %d\n", posicoesIniciais.posicoes[j].id);
			//	//marcacaoX = posicoesIniciais.posicoes[j].x;
			//	//marcacaoY = posicoesIniciais.posicoes[j].y;
			//	pecasPuzzle.pecas[j].pos_atual_x = swapX;
			//	pecasPuzzle.pecas[j].pos_atual_y = swapY;
			//	swapAtivo = false;
			//}

			// Verifica imagem dentro do quadrante para retirala
			if ((mouseX >= quadrantePuzzle.quadrantes[j].X && mouseX <= quadrantePuzzle.quadrantes[j].X + 105) && (mouseY >= quadrantePuzzle.quadrantes[j].Y && mouseY <= quadrantePuzzle.quadrantes[j].Y + 105)) {
				idPeca = quadrantePuzzle.quadrantes[j].idPecaRecebida;
				idPeca -= 1;
				printf("SUB %d\n", idPeca);
				printf("ID EEEQUADRANTE %d\n", quadrantePuzzle.quadrantes[j].id);
				swapX = pecasPuzzle.pecas[idPeca].pos_correta_x;
				swapY = pecasPuzzle.pecas[idPeca].pos_correta_y;
				swapAtivo = true;
			}

			// movimentação do marcador em todas as posições do quadrante
			if ((mouseX >= quadrantePuzzle.quadrantes[j].X && mouseX <= quadrantePuzzle.quadrantes[j].X + 105) && (mouseY >= quadrantePuzzle.quadrantes[j].Y && mouseY <= quadrantePuzzle.quadrantes[j].Y + 105)) {
				marcacaoX = quadrantePuzzle.quadrantes[j].X;
				marcacaoY = quadrantePuzzle.quadrantes[j].Y;
				first = true;
			}
		}
	}

	if (contadorCreditos >= 1) {
		al_draw_filled_rectangle(460, 665, 820, 710, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 665, ALLEGRO_ALIGN_CENTRE, "Ver Puzzle Completo");
		if ((mouseX >= 460 && mouseX <= 820) && (mouseY >= 665 && mouseY <= 710)) {
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

	al_draw_textf(fonteMenu, al_map_rgb(255, 255, 255), 640, 10, ALLEGRO_ALIGN_CENTRE, "Creditos de Imagem: %d", contadorCreditos);

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
		al_draw_rectangle(marcacaoX - 0.4, marcacaoY - 0.5, marcacaoX + 110, marcacaoY + 110, al_map_rgb(238, 173, 45), 6);
	}

	// Botão Próxima fase
	al_draw_filled_rectangle(1040, 650, 1220, 690, al_map_rgb(238, 173, 45));
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1130, 648, ALLEGRO_ALIGN_CENTRE, "Proximo");

	// Verificar se clicou em proximo
	if (mouseX >= 1040 && mouseY >= 650 && mouseX <= 1219 && mouseY <= 690) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			navegacao += 1;
		}
	}

	al_flip_display();
}