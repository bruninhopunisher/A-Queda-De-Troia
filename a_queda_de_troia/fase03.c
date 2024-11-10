#include "fase03.h"

// ATENÇÃO NÃO MEXER NO CÓDIGO DA PÁGINA

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
	// Define area de desenho
	int inicioX = 360;
	int inicioY = 65;
	int largura = 550;
	int altura = 550;

	// Cor 
	ALLEGRO_COLOR corLinha = al_map_rgb(0, 0, 0);

	// tamanho definido
	int tamanhoQuadrado = 116;

	for (int x = inicioX; x < inicioX + largura; x += tamanhoQuadrado) {
		for (int y = inicioY; y < inicioY + altura; y += tamanhoQuadrado) {
			al_draw_rectangle(x, y, x + tamanhoQuadrado, y + tamanhoQuadrado, corLinha, 10);
		}
	}
}

void fase3(ALLEGRO_EVENT evento) {
	
	al_draw_bitmap(imgFundoPuzzle, 0, 0, 0);

	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
		 printf("\nMOUSE X %d\n", mouseX);
		 printf("MOUSE Y %d\n", mouseY);
	}

	//if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
	//	for (int i = 0; i < 25; i++) {
	//		if ((mouseX >= posicaoInicialX[i] && mouseX <= posicaoInicialX[i] + 110) && (mouseY >= posicaoInicialY[i] && mouseY <= posicaoInicialY[i] + 110)) {
	//			indice = i;
	//			idPeca = pecasPuzzle.pecas[i].id;
	//			//swapX = pecasPuzzle.pecas[i].pos_atual_x;
	//			//swapY = pecasPuzzle.pecas[i].pos_atual_y;
	//			printf("ID Peca %d\n", idPeca);
	//			//printf("Swap X %d\n", swapX);
	//			//printf("Swap Y %d\n", swapY);
	//			printf("Indice %d\n", indice);
	//		}
	//	}
	//}

	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		for (int i = 0; i < 25; i++) {
			if ((mouseX >= posicaoInicialX[i] && mouseX <= posicaoInicialX[i] + 110) && (mouseY >= posicaoInicialY[i] && mouseY <= posicaoInicialY[i] + 110)) {
				indice = i;
				idPeca = pecasPuzzle.pecas[i].id;
				printf("ANTES %s\n", pecasPuzzle.pecas[i].selecionada ? "true" : "false");
				pecasPuzzle.pecas[i].selecionada = true;
			}
		}

		for (int j = 0; j < 25; j++) {
			if ((mouseX >= quadrantePuzzle.quadrantes[j].X && mouseX <= quadrantePuzzle.quadrantes[j].X + 105) && (mouseY >= quadrantePuzzle.quadrantes[j].Y && mouseY <= quadrantePuzzle.quadrantes[j].Y + 105)) {
				idQuadrante = quadrantePuzzle.quadrantes[j].id;
				swapX = quadrantePuzzle.quadrantes[j].X;
				swapY = quadrantePuzzle.quadrantes[j].Y;
				pecasPuzzle.pecas[indice].pos_atual_x = swapX;
				pecasPuzzle.pecas[indice].pos_atual_y = swapY;
				pecaPosicionada = true;
				printf("Swap X %d\n", swapX);
				printf("Swap Y %d\n", swapY);
				printf("ID Quadrante %d\n", idQuadrante);
			}
		}

		for (int k = 0; k < 25; k++) {
			if (pecaPosicionada == true) {
				idQuadrante = 0;
				swapX = 0;
				swapY = 0;
				pecasPuzzle.pecas[k].selecionada == false;
				pecaPosicionada = false;
				printf("DEPOIS %s\n", pecasPuzzle.pecas[k].selecionada ? "true" : "false");
			}
		}
	}

	//for (int i = 0; i < 25; i++) {
	//	if ((mouseAoVivoX >= posicaoInicialX[i] && mouseAoVivoX <= posicaoInicialX[i] + 110) && (mouseAoVivoY >= posicaoInicialY[i] && mouseAoVivoY <= posicaoInicialY[i] + 110)) {
	//		printf("ATeeeeeeeeeeee %d");
	//	}
	//}

	//for (int j = 0; j < 25; j++) {
	//	if ((mouseAoVivoX >= quadrantePuzzle.quadrantes[j].X && mouseAoVivoX <= quadrantePuzzle.quadrantes[j].X + 105) && (mouseAoVivoY >= quadrantePuzzle.quadrantes[j].Y && mouseAoVivoY <= quadrantePuzzle.quadrantes[j].Y + 105)) {
	//		printf("ATeeeeeeeeeeee %d");
	//	}
	//}

	al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);


	if (contadorCreditos >= 1)
	{
		al_draw_filled_rectangle(460, 665, 820, 710, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 665, ALLEGRO_ALIGN_CENTRE, "Ver Puzzle Completo");
		if ((mouseX >= 460 && mouseX <= 820) && (mouseY >= 665 && mouseY <= 710))
		{
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
			if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && contadorCreditos > 0)
			{
				imagemPuzzle();
			}
		}
		else
		{
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
		}
	}
	else if (contadorCreditos < 1)
	{
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
		al_draw_filled_rectangle(460, 665, 820, 710, al_map_rgb(222, 158, 30));
		al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 665, ALLEGRO_ALIGN_CENTRE, "Ver Puzzle Completo");
		al_draw_filled_rectangle(460, 665, 820, 710, al_map_rgba(50, 50, 50, 128));
	}

	al_draw_textf(fonteMenu, al_map_rgb(255, 255, 255), 640, 10, ALLEGRO_ALIGN_CENTRE, "Creditos de Imagem: %d", contadorCreditos);

	// Area imagem puzzle
	al_draw_filled_rectangle(360, 65, 940, 645, al_map_rgb(255, 255, 255));
	desenhaQuadrados();

	// ATENÇÃO NÃO MEXER NO CÓDIGO DA PÁGINA

	// AREA DE DEZENHO DO PUZZLE

	// Criar um valor x e y para cada peça do puzzle
	// Quando clicar a imagem ira ser arrastada com efeito do mouse
	// Quando soltar o mouse a imagem ira ficar no local
	// Quando todas as peças estiverem no local correto a imagem do puzzle ira aparecer o botão de próxima fase

	//al_draw_bitmap(puzzle1, 365, 70, 0);
	//al_draw_bitmap(puzzle2, 480, 70, 0);
	//al_draw_bitmap(puzzle3, 595, 70, 0);
	//al_draw_bitmap(puzzle4, 710, 70, 0);
	//al_draw_bitmap(puzzle5, 825, 70, 0);
	//al_draw_bitmap(puzzle6, 365, 185, 0);
	//al_draw_bitmap(puzzle7, 480, 185, 0);
	//al_draw_bitmap(puzzle8, 595, 185, 0);
	//al_draw_bitmap(puzzle9, 710, 185, 0);
	//al_draw_bitmap(puzzle10, 825, 185, 0);
	//al_draw_bitmap(puzzle11, 365, 300, 0);
	//al_draw_bitmap(puzzle12, 480, 300, 0);
	//al_draw_bitmap(puzzle13, 595, 300, 0);
	//al_draw_bitmap(puzzle14, 710, 300, 0);
	//al_draw_bitmap(puzzle15, 825, 300, 0);
	//al_draw_bitmap(puzzle16, 365, 415, 0);
	//al_draw_bitmap(puzzle17, 480, 415, 0);
	//al_draw_bitmap(puzzle18, 595, 415, 0);
	//al_draw_bitmap(puzzle19, 710, 415, 0);
	//al_draw_bitmap(puzzle20, 825, 415, 0);
	//al_draw_bitmap(puzzle21, 365, 530, 0);
	//al_draw_bitmap(puzzle22, 480, 530, 0);
	//al_draw_bitmap(puzzle23, 595, 530, 0);
	//al_draw_bitmap(puzzle24, 710, 530, 0);
	//al_draw_bitmap(puzzle25, 825, 530, 0);
	
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
	
	// Botão Próxima fase
	al_draw_filled_rectangle(1040, 650, 1220, 690, al_map_rgb(238, 173, 45));
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1130, 648, ALLEGRO_ALIGN_CENTRE, "Proximo");
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{ // Verificar se clicou em proximo
		if (mouseX >= 1088 && mouseY >= 660 && mouseX <= 1225 && mouseY <= 680)
		{
			navegacao += 1;
		}
	}

	al_flip_display();
}
