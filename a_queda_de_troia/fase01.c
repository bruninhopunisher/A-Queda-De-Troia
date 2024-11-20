#include "fase01.h"

void fase01(ALLEGRO_EVENT evento) {

    // Background
    al_draw_bitmap(backgroundFaseUm, 0, 0, 0);

    // carregando sprite inicial
   sprite_atual = ParisCimaNormal;

    if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) { // Remover posterior
        mouseX = evento.mouse.x;
        mouseY = evento.mouse.y;
        printf("X: %d Y: %d \n\n", mouseX, mouseY);
    }

    //alterna entre o pe dir e esq
    if (esta_movendo) {

        atraso_animacao++;
        if (atraso_animacao >= 10) { // velocidade animação de mudar o pe dir e esq atualizada pro frame
            contador_passos = (contador_passos + 1) % 2; // 0 e 1 direoiro e esquerdo
            atraso_animacao = 0;
        }

        // Determinar o sprite com base na direção e no passo
        if (direcaoY == -1) { //  cima
            sprite_atual = contador_passos == 0 ? ParisCimaEsq : ParisCimaDir;
        }
        else if (direcaoY == 1) { //  baixo
            sprite_atual = contador_passos == 0 ? ParisBaixoEsq : ParisBaixoDir;
        }
        else if (direcaoX == -1) { // esquerda
            sprite_atual = contador_passos == 0 ? ParisEsqEsq : ParisEsqDir;
        }
        else if (direcaoX == 1) { // direita
            sprite_atual = contador_passos == 0 ? ParisDirEsq : ParisDirDir;
        }
    }
    else {
        // mantendo sprite da ultima posição, de acordo com os valores acima 
        if (ultima_direcaoY == -1) {
            sprite_atual = ParisCimaNormal;
        }
        else if (ultima_direcaoY == 1) {
            sprite_atual = ParisBaixoNormal;
        }
        else if (ultima_direcaoX == -1) {
            sprite_atual = ParisEsqNormal;
        }
        else if (ultima_direcaoX == 1) {
            sprite_atual = ParisDirNormal;
        }

    }

    // Desenhar o sprite do personagem
    al_draw_bitmap(sprite_atual, personagemHeitorX, personagemHeitorY, 0);

    // Desenhar a Helena (caso exista)
    //al_draw_bitmap(personagemHelena, personagemHelenaX, personagemHelenaY, 0);

    // Verificar o evento
    if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
        esta_movendo = true; // Inicia o movimento

        // Define a direção com base na tecla pressionada
        switch (evento.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
            direcaoY = -1;
            direcaoX = 0;
            break;
        case ALLEGRO_KEY_DOWN:
            direcaoY = 1;
            direcaoX = 0;
            break;
        case ALLEGRO_KEY_LEFT:
            direcaoX = -1;
            direcaoY = 0;
            break;
        case ALLEGRO_KEY_RIGHT:
            direcaoX = 1;
            direcaoY = 0;
            break;
        }
    }
    else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
        // Para o movimento quando a tecla é liberada
        switch (evento.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
        case ALLEGRO_KEY_DOWN:
            direcaoY = 0;
            break;
        case ALLEGRO_KEY_LEFT:
        case ALLEGRO_KEY_RIGHT:
            direcaoX = 0;
            break;
        }

        // Para o movimento se nenhuma tecla de direção estiver pressionada
        if (direcaoX == 0 && direcaoY == 0) {
            esta_movendo = false;
        }
    }

    // Definindo as novas áreas restritas
    bool dentro_da_area_restrita1 = (personagemHeitorX >= 0 && personagemHeitorX <= 0 && personagemHeitorY >= 0 && personagemHeitorY <= 620);
    bool dentro_da_area_restrita2 = (personagemHeitorX >= 0 && personagemHeitorX <= 695 && personagemHeitorY == 100);
    bool dentro_da_area_restrita3 = (personagemHeitorX >= 0 && personagemHeitorX <= 695 && personagemHeitorY == 616);

    // Atualiza a posição do personagem se ele estiver em movimento
    if (esta_movendo) {
        // Verifica se o personagem ta dentro das area de colisão, impede o movimento dentro delas
        if (dentro_da_area_restrita1 || dentro_da_area_restrita2 || dentro_da_area_restrita3) {
            // Se o movimento for para a direita, ele pode sair da área
            if (direcaoX > 0 && !(personagemHeitorY == 621 && personagemHeitorX >= 0 && personagemHeitorX <= 693)) {
                personagemHeitorX += direcaoX * 5;
            }
            // Se o movimento for para baixo, ele pode sair da area
            else if (direcaoY > 0) {
                personagemHeitorY += direcaoY * 5;
            }
        }
        else {
            // se nao estiver em colisao o personagem se move normalmente
            personagemHeitorX += direcaoX * 5; // Ajuste a velocidade (5 pixels por frame)
            personagemHeitorY += direcaoY * 5; // Ajuste a velocidade (5 pixels por frame)
        }

        // Atualiza a direção aneterior personagem estava
        ultima_direcaoX = direcaoX;
        ultima_direcaoY = direcaoY;
    }

    // Verificar colisão com a area  da próxima fase
    if ((personagemHeitorX >= 700 && personagemHeitorX <= 841) && (personagemHeitorY >= 250 && personagemHeitorY <= 304)) {
        al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgba(50, 50, 50, 128));
        al_draw_filled_rectangle(500, 350, 780, 410, al_map_rgba(50, 50, 50, 128));
        al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, "PROXIMA FASE");

        // Verifica se o mouse  dentro da area do botão
        if ((mouseX >= 500 && mouseX <= 780) && (mouseY >= 350 && mouseY <= 410)) {
            al_draw_filled_rectangle(500, 350, 780, 410, al_map_rgb(255, 165, 0));
            al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, "PROXIMA FASE");
            al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);

            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                navegacao += 1;
            }
        }
        else {
            al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
        }
    }

    al_flip_display();
}