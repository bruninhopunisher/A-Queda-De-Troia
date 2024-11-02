#include "fase03.h"

void quebraCabeca() {
	Puzzle pecasPuzzle;
	pecasPuzzle.totalPecas = 25;

	pecasPuzzle.pecas[0].id = 1;
	pecasPuzzle.pecas[0].pos_correta_x = 340;
	pecasPuzzle.pecas[0].pos_correta_y = 60;
	pecasPuzzle.pecas[0].pos_atual_x = 0;
	pecasPuzzle.pecas[0].pos_atual_y = 0;
	pecasPuzzle.pecas[0].selecionada = false;
	pecasPuzzle.pecas[0].posicao_correta = false;
	// Copia e preenche o nome da imagem no vetor de peças e a posição correspondente
	strcpy_s(pecasPuzzle.pecas[0].nome, sizeof(pecasPuzzle.pecas[0].nome), "puzzle1.png");

	pecasPuzzle.pecas[1].id = 2;
	pecasPuzzle.pecas[1].pos_correta_x = 460;
	pecasPuzzle.pecas[1].pos_correta_y = 60;
	pecasPuzzle.pecas[1].pos_atual_x = 0;
	pecasPuzzle.pecas[1].pos_atual_y = 0;
	pecasPuzzle.pecas[1].selecionada = false;
	pecasPuzzle.pecas[1].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[1].nome, sizeof(pecasPuzzle.pecas[1].nome), "puzzle2.png");

	pecasPuzzle.pecas[2].id = 3;
	pecasPuzzle.pecas[2].pos_correta_x = 580;
	pecasPuzzle.pecas[2].pos_correta_y = 60;
	pecasPuzzle.pecas[2].pos_atual_x = 0;
	pecasPuzzle.pecas[2].pos_atual_y = 0;
	pecasPuzzle.pecas[2].selecionada = false;
	pecasPuzzle.pecas[2].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[2].nome, sizeof(pecasPuzzle.pecas[2].nome), "puzzle3.png");

	pecasPuzzle.pecas[3].id = 4;
	pecasPuzzle.pecas[3].pos_correta_x = 700;
	pecasPuzzle.pecas[3].pos_correta_y = 60;
	pecasPuzzle.pecas[3].pos_atual_x = 0;
	pecasPuzzle.pecas[3].pos_atual_y = 0;
	pecasPuzzle.pecas[3].selecionada = false;
	pecasPuzzle.pecas[3].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[3].nome, sizeof(pecasPuzzle.pecas[3].nome), "puzzle4.png");

	pecasPuzzle.pecas[4].id = 5;
	pecasPuzzle.pecas[4].pos_correta_x = 820;
	pecasPuzzle.pecas[4].pos_correta_y = 60;
	pecasPuzzle.pecas[4].pos_atual_x = 0;
	pecasPuzzle.pecas[4].pos_atual_y = 0;
	pecasPuzzle.pecas[4].selecionada = false;
	pecasPuzzle.pecas[4].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[4].nome, sizeof(pecasPuzzle.pecas[4].nome), "puzzle5.png");

	pecasPuzzle.pecas[5].id = 6;
	pecasPuzzle.pecas[5].pos_correta_x = 340;
	pecasPuzzle.pecas[5].pos_correta_y = 180;
	pecasPuzzle.pecas[5].pos_atual_x = 0;
	pecasPuzzle.pecas[5].pos_atual_y = 0;
	pecasPuzzle.pecas[5].selecionada = false;
	pecasPuzzle.pecas[5].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[5].nome, sizeof(pecasPuzzle.pecas[5].nome), "puzzle6.png");

	pecasPuzzle.pecas[6].id = 7;
	pecasPuzzle.pecas[6].pos_correta_x = 460;
	pecasPuzzle.pecas[6].pos_correta_y = 180;
	pecasPuzzle.pecas[6].pos_atual_x = 0;
	pecasPuzzle.pecas[6].pos_atual_y = 0;
	pecasPuzzle.pecas[6].selecionada = false;
	pecasPuzzle.pecas[6].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[6].nome, sizeof(pecasPuzzle.pecas[6].nome), "puzzle7.png");

	pecasPuzzle.pecas[7].id = 8;
	pecasPuzzle.pecas[7].pos_correta_x = 580;
	pecasPuzzle.pecas[7].pos_correta_y = 180;
	pecasPuzzle.pecas[7].pos_atual_x = 0;
	pecasPuzzle.pecas[7].pos_atual_y = 0;
	pecasPuzzle.pecas[7].selecionada = false;
	pecasPuzzle.pecas[7].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[7].nome, sizeof(pecasPuzzle.pecas[7].nome), "puzzle8.png");

	pecasPuzzle.pecas[8].id = 9;
	pecasPuzzle.pecas[8].pos_correta_x = 700;
	pecasPuzzle.pecas[8].pos_correta_y = 180;
	pecasPuzzle.pecas[8].pos_atual_x = 0;
	pecasPuzzle.pecas[8].pos_atual_y = 0;
	pecasPuzzle.pecas[8].selecionada = false;
	pecasPuzzle.pecas[8].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[8].nome, sizeof(pecasPuzzle.pecas[8].nome), "puzzle9.png");

	pecasPuzzle.pecas[9].id = 10;
	pecasPuzzle.pecas[9].pos_correta_x = 820;
	pecasPuzzle.pecas[9].pos_correta_y = 180;
	pecasPuzzle.pecas[9].pos_atual_x = 0;
	pecasPuzzle.pecas[9].pos_atual_y = 0;
	pecasPuzzle.pecas[9].selecionada = false;
	pecasPuzzle.pecas[9].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[9].nome, sizeof(pecasPuzzle.pecas[9].nome), "puzzle10.png");

	pecasPuzzle.pecas[10].id = 11;
	pecasPuzzle.pecas[10].pos_correta_x = 340;
	pecasPuzzle.pecas[10].pos_correta_y = 300;
	pecasPuzzle.pecas[10].pos_atual_x = 0;
	pecasPuzzle.pecas[10].pos_atual_y = 0;
	pecasPuzzle.pecas[10].selecionada = false;
	pecasPuzzle.pecas[10].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[10].nome, sizeof(pecasPuzzle.pecas[10].nome), "puzzle11.png");

	pecasPuzzle.pecas[11].id = 12;
	pecasPuzzle.pecas[11].pos_correta_x = 460;
	pecasPuzzle.pecas[11].pos_correta_y = 300;
	pecasPuzzle.pecas[11].pos_atual_x = 0;
	pecasPuzzle.pecas[11].pos_atual_y = 0;
	pecasPuzzle.pecas[11].selecionada = false;
	pecasPuzzle.pecas[11].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[11].nome, sizeof(pecasPuzzle.pecas[11].nome), "puzzle12.png");

	pecasPuzzle.pecas[12].id = 13;
	pecasPuzzle.pecas[12].pos_correta_x = 580;
	pecasPuzzle.pecas[12].pos_correta_y = 300;
	pecasPuzzle.pecas[12].pos_atual_x = 0;
	pecasPuzzle.pecas[12].pos_atual_y = 0;
	pecasPuzzle.pecas[12].selecionada = false;
	pecasPuzzle.pecas[12].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[12].nome, sizeof(pecasPuzzle.pecas[12].nome), "puzzle13.png");

	pecasPuzzle.pecas[13].id = 14;
	pecasPuzzle.pecas[13].pos_correta_x = 700;
	pecasPuzzle.pecas[13].pos_correta_y = 300;
	pecasPuzzle.pecas[13].pos_atual_x = 0;
	pecasPuzzle.pecas[13].pos_atual_y = 0;
	pecasPuzzle.pecas[13].selecionada = false;
	pecasPuzzle.pecas[13].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[13].nome, sizeof(pecasPuzzle.pecas[13].nome), "puzzle14.png");

	pecasPuzzle.pecas[14].id = 15;
	pecasPuzzle.pecas[14].pos_correta_x = 820;
	pecasPuzzle.pecas[14].pos_correta_y = 300;
	pecasPuzzle.pecas[14].pos_atual_x = 0;
	pecasPuzzle.pecas[14].pos_atual_y = 0;
	pecasPuzzle.pecas[14].selecionada = false;
	pecasPuzzle.pecas[14].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[14].nome, sizeof(pecasPuzzle.pecas[14].nome), "puzzle15.png");

	pecasPuzzle.pecas[15].id = 16;
	pecasPuzzle.pecas[15].pos_correta_x = 340;
	pecasPuzzle.pecas[15].pos_correta_y = 420;
	pecasPuzzle.pecas[15].pos_atual_x = 0;
	pecasPuzzle.pecas[15].pos_atual_y = 0;
	pecasPuzzle.pecas[15].selecionada = false;
	pecasPuzzle.pecas[15].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[15].nome, sizeof(pecasPuzzle.pecas[15].nome), "puzzle16.png");

	pecasPuzzle.pecas[16].id = 17;
	pecasPuzzle.pecas[16].pos_correta_x = 460;
	pecasPuzzle.pecas[16].pos_correta_y = 420;
	pecasPuzzle.pecas[16].pos_atual_x = 0;
	pecasPuzzle.pecas[16].pos_atual_y = 0;
	pecasPuzzle.pecas[16].selecionada = false;
	pecasPuzzle.pecas[16].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[16].nome, sizeof(pecasPuzzle.pecas[16].nome), "puzzle17.png");

	pecasPuzzle.pecas[17].id = 18;
	pecasPuzzle.pecas[17].pos_correta_x = 580;
	pecasPuzzle.pecas[17].pos_correta_y = 420;
	pecasPuzzle.pecas[17].pos_atual_x = 0;
	pecasPuzzle.pecas[17].pos_atual_y = 0;
	pecasPuzzle.pecas[17].selecionada = false;
	pecasPuzzle.pecas[17].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[17].nome, sizeof(pecasPuzzle.pecas[17].nome), "puzzle18.png");

	pecasPuzzle.pecas[18].id = 19;
	pecasPuzzle.pecas[18].pos_correta_x = 700;
	pecasPuzzle.pecas[18].pos_correta_y = 420;
	pecasPuzzle.pecas[18].pos_atual_x = 0;
	pecasPuzzle.pecas[18].pos_atual_y = 0;
	pecasPuzzle.pecas[18].selecionada = false;
	pecasPuzzle.pecas[18].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[18].nome, sizeof(pecasPuzzle.pecas[18].nome), "puzzle19.png");

	pecasPuzzle.pecas[19].id = 20;
	pecasPuzzle.pecas[19].pos_correta_x = 820;
	pecasPuzzle.pecas[19].pos_correta_y = 420;
	pecasPuzzle.pecas[19].pos_atual_x = 0;
	pecasPuzzle.pecas[19].pos_atual_y = 0;
	pecasPuzzle.pecas[19].selecionada = false;
	pecasPuzzle.pecas[19].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[19].nome, sizeof(pecasPuzzle.pecas[19].nome), "puzzle20.png");

	pecasPuzzle.pecas[20].id = 21;
	pecasPuzzle.pecas[20].pos_correta_x = 340;
	pecasPuzzle.pecas[20].pos_correta_y = 540;
	pecasPuzzle.pecas[20].pos_atual_x = 0;
	pecasPuzzle.pecas[20].pos_atual_y = 0;
	pecasPuzzle.pecas[20].selecionada = false;
	pecasPuzzle.pecas[20].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[20].nome, sizeof(pecasPuzzle.pecas[20].nome), "puzzle21.png");

	pecasPuzzle.pecas[21].id = 22;
	pecasPuzzle.pecas[21].pos_correta_x = 460;
	pecasPuzzle.pecas[21].pos_correta_y = 540;
	pecasPuzzle.pecas[21].pos_atual_x = 0;
	pecasPuzzle.pecas[21].pos_atual_y = 0;
	pecasPuzzle.pecas[21].selecionada = false;
	pecasPuzzle.pecas[21].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[21].nome, sizeof(pecasPuzzle.pecas[21].nome), "puzzle22.png");

	pecasPuzzle.pecas[22].id = 23;
	pecasPuzzle.pecas[22].pos_correta_x = 580;
	pecasPuzzle.pecas[22].pos_correta_y = 540;
	pecasPuzzle.pecas[22].pos_atual_x = 0;
	pecasPuzzle.pecas[22].pos_atual_y = 0;
	pecasPuzzle.pecas[22].selecionada = false;
	pecasPuzzle.pecas[22].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[22].nome, sizeof(pecasPuzzle.pecas[22].nome), "puzzle23.png");

	pecasPuzzle.pecas[23].id = 24;
	pecasPuzzle.pecas[23].pos_correta_x = 700;
	pecasPuzzle.pecas[23].pos_correta_y = 540;
	pecasPuzzle.pecas[23].pos_atual_x = 0;
	pecasPuzzle.pecas[23].pos_atual_y = 0;
	pecasPuzzle.pecas[23].selecionada = false;
	pecasPuzzle.pecas[23].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[23].nome, sizeof(pecasPuzzle.pecas[23].nome), "puzzle24.png");

	pecasPuzzle.pecas[24].id = 25;
	pecasPuzzle.pecas[24].pos_correta_x = 820;
	pecasPuzzle.pecas[24].pos_correta_y = 540;
	pecasPuzzle.pecas[24].pos_atual_x = 0;
	pecasPuzzle.pecas[24].pos_atual_y = 0;
	pecasPuzzle.pecas[24].selecionada = false;
	pecasPuzzle.pecas[24].posicao_correta = false;
	strcpy_s(pecasPuzzle.pecas[24].nome, sizeof(pecasPuzzle.pecas[24].nome), "puzzle25.png");

	// Inicializa o vetor de peças do puzzle
	if (verificaPuzzle == true) {
		for (int i = 0; i < pecasPuzzle.totalPecas; i++) {
			printf("Nome: %s\nID: %d\nPos Correta X %d:\nPos Correta Y %d:\n", pecasPuzzle.pecas[i].nome, pecasPuzzle.pecas[i].id, pecasPuzzle.pecas[i].pos_correta_x, pecasPuzzle.pecas[i].pos_correta_y);
			printf("\n");
		}
		verificaPuzzle = false;
	}
}