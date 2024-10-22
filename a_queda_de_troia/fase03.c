#include "fase03.h"

//ATENÇÃO NÃO MEXER NO CÓDIGO DA PÁGINA

//Mostra a imagem original do puzzle
void imagemPuzzle () {
    al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_draw_bitmap(imgFundoPuzzle, 0, 0, 0);
	al_draw_bitmap(imgPuzzle, 340, 60, 0);
	al_flip_display();
	al_rest(3);
    contadorCreditos -= 1;
}

void fase3(ALLEGRO_EVENT evento) {
    al_draw_bitmap(imgFundoPuzzle, 0, 0, 0);

    if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
        mouseX = evento.mouse.x;
        mouseY = evento.mouse.y;
        //printf("\nMOUSE X %d\n", mouseX);
        //printf("MOUSE Y %d\n", mouseY);
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

    switch (contadorCreditos) {
		case 3:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 10, ALLEGRO_ALIGN_CENTRE, "Creditos de Imagem: 3");
			break;
		case 2:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 10, ALLEGRO_ALIGN_CENTRE, "Creditos de Imagem: 2");
			break;
		case 1:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 10, ALLEGRO_ALIGN_CENTRE, "Creditos de Imagem: 1");
			break;
		case 0:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 10, ALLEGRO_ALIGN_CENTRE, "Creditos de Imagem: 0");
			break;
	}  

    //Area imagem puzzle
    al_draw_filled_rectangle(340, 60, 940, 660, al_map_rgb(255, 255, 255));



	//ATENÇÃO NÃO MEXER NO CÓDIGO DA PÁGINA

	//AREA DE DEZENHO DO PUZZLE

	//Criar um valor x e y para cada peça do puzzle
	//Quando clicar a imagem ira ser arrastada com efeito do mouse
	//Quando soltar o mouse a imagem ira ficar no local
	//Quando todas as peças estiverem no local correto a imagem do puzzle ira aparecer o botão de próxima fase





		/*al_draw_bitmap(puzzle1, 340, 60, 0);
	al_draw_bitmap(puzzle2, 460, 60, 0);
	al_draw_bitmap(puzzle3, 580, 60, 0);
	al_draw_bitmap(puzzle4, 700, 60, 0);
	al_draw_bitmap(puzzle5, 820, 60, 0);
	al_draw_bitmap(puzzle6, 340, 180, 0);
	al_draw_bitmap(puzzle7, 460, 180, 0);
	al_draw_bitmap(puzzle8, 580, 180, 0);
	al_draw_bitmap(puzzle9, 700, 180, 0);
	al_draw_bitmap(puzzle10, 820, 180, 0);
	al_draw_bitmap(puzzle11, 340, 300, 0);
	al_draw_bitmap(puzzle12, 460, 300, 0);
	al_draw_bitmap(puzzle13, 580, 300, 0);
	al_draw_bitmap(puzzle14, 700, 300, 0);
	al_draw_bitmap(puzzle15, 820, 300, 0);
	al_draw_bitmap(puzzle16, 340, 420, 0);
	al_draw_bitmap(puzzle17, 460, 420, 0);
	al_draw_bitmap(puzzle18, 580, 420, 0);
	al_draw_bitmap(puzzle19, 700, 420, 0);
	al_draw_bitmap(puzzle20, 820, 420, 0);
	al_draw_bitmap(puzzle21, 340, 540, 0);
	al_draw_bitmap(puzzle22, 460, 540, 0);
	al_draw_bitmap(puzzle23, 580, 540, 0);
	al_draw_bitmap(puzzle24, 700, 540, 0);
	al_draw_bitmap(puzzle25, 820, 540, 0);*/
	// Colocando as imagens fora da área do retângulo
	al_draw_bitmap(puzzle1, 10, 0, 0);      // Superior esquerda
	al_draw_bitmap(puzzle2, 10, 130, 0);      // Superior esquerda
	al_draw_bitmap(puzzle3, 10, 250, 0);      // Inferior esquerda
	al_draw_bitmap(puzzle4, 10, 370, 0);      // Inferior esquerda
	al_draw_bitmap(puzzle5, 130, 0, 0);     // Superior direita
	al_draw_bitmap(puzzle6, 130, 130, 0);     // Superior direita
	al_draw_bitmap(puzzle7, 130, 250, 0);     // Inferior direita
	al_draw_bitmap(puzzle8, 130, 370, 0);     // Inferior direita
	al_draw_bitmap(puzzle12, 130, 490, 0);      // Centro esquerda
	al_draw_bitmap(puzzle22, 10, 490, 0);     // Centro esquerda
	al_draw_bitmap(puzzle25, 10, 610, 0);    // Centro direita
	al_draw_bitmap(puzzle9, 950, 0, 0);    // Centro direita
	al_draw_bitmap(puzzle13, 1080, 0, 0);      // Superior centro
	al_draw_bitmap(puzzle14, 950, 130, 0);      // Superior centro
	al_draw_bitmap(puzzle15, 950, 130, 0);     // Inferior centro
	al_draw_bitmap(puzzle16, 950, 260, 0);     // Inferior centro
	al_draw_bitmap(puzzle17, 950, 380, 0);     // Superior esquerda
	al_draw_bitmap(puzzle18, 1080, 130, 0);     // Inferior esquerda
	al_draw_bitmap(puzzle19, 1080, 260, 0);     // Superior direita
	al_draw_bitmap(puzzle20, 1080, 380, 0);     // Inferior direita
	al_draw_bitmap(puzzle21, 1080, 490, 0);     // Centro esquerda
	al_draw_bitmap(puzzle10, 1080, 610, 0);     // Centro direita
	al_draw_bitmap(puzzle23, 1080, 730, 0);     // Centro esquerda
	al_draw_bitmap(puzzle24, 1080, 850, 0);     // Centro direita
	al_draw_bitmap(puzzle11, 950, 490, 0);     // Superior centro


	//Botão Próxima fase
al_draw_filled_rectangle(1075, 650, 1235, 690, al_map_rgb(238, 173, 45));
al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1155, 648, ALLEGRO_ALIGN_CENTRE, "Proximo");
if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) { //Verificar se clicou em proximo
	if (mouseX >= 1088 && mouseY >= 660 && mouseX <= 1225 && mouseY <= 680) {
		navegacao += 1;
	}
}
al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1080, 500, ALLEGRO_ALIGN_CENTRE, "Fase em Const");



	al_flip_display();
}
