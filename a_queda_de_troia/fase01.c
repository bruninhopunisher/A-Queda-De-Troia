#include "fase01.h"

void fase01(ALLEGRO_EVENT evento) {

    // Background
    al_draw_bitmap(backgroundFaseUm, 0, 0, 0);

    // carregando sprite inicial
    sprite_atual = ParisCimaNormal;
    sprite_atual2 =HeitorCimaN;

    if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) { // Remover posterior
        mouseX = evento.mouse.x;
        mouseY = evento.mouse.y;
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
            sprite_atual2 = contador_passos == 0 ? HeitorCimaE : HeitorCimaD;
        }
        else if (direcaoY == 1) { //  baixo
            sprite_atual = contador_passos == 0 ? ParisBaixoEsq : ParisBaixoDir;
            sprite_atual2 = contador_passos == 0 ? HeitorBaixoE : HeitorBaixoD;
        }
        else if (direcaoX == -1) { // esquerda
            sprite_atual = contador_passos == 0 ? ParisEsqEsq : ParisEsqDir;
           sprite_atual2 = contador_passos == 0 ? HeitorLadoEE : HeitorLadoED;
        }
        else if (direcaoX == 1) { // direita
            sprite_atual = contador_passos == 0 ? ParisDirEsq : ParisDirDir;
            sprite_atual2 = contador_passos == 0 ? HeitorLadoE : HeitorLadoD;
        }
    }
    else {
        // mantendo sprite da ultima posição, de acordo com os valores acima 
        if (ultima_direcaoY == -1) {
            sprite_atual = ParisCimaNormal;
            sprite_atual2 = HeitorCimaN;
        }
        else if (ultima_direcaoY == 1) {
            sprite_atual = ParisBaixoNormal;
            sprite_atual2 = HeitorBaixoN;
        }
        else if (ultima_direcaoX == -1) {
            sprite_atual = ParisEsqNormal;
            sprite_atual2 = HeitorLadoEN;
        }
        else if (ultima_direcaoX == 1) {
            sprite_atual = ParisDirNormal;
            sprite_atual2 = HeitorLadoN;
        }

    }
    // Desenhar o sprite do personagem
    al_draw_bitmap(sprite_atual, personagemParisX, personagemParisY, 0);
    al_draw_bitmap(sprite_atual2, personagemParisX -10, personagemParisY + 45, 0);
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
    bool dentro_da_area_restrita1 = (personagemParisX == 0  && personagemParisY >= 0 && personagemParisY <= 620);
    bool dentro_da_area_restrita2 = (personagemParisX >= 0 && personagemParisX <= 695 && personagemParisY == 100);
    bool dentro_da_area_restrita3 = (personagemParisX >= 0 && personagemParisX <= 1200 && personagemParisY +70 >= 575 && personagemParisY <= 620);
    bool dentro_da_area_restrita4 = (personagemParisX >= 696 && personagemParisX <= 1069 && personagemParisY + 70 >= 100 && personagemParisY + 70 <= 292);
    // Verifica colisão com a reta inclinada
    bool colisao_com_reta = false;
    float y_reta = 0.0f;

    if (personagemParisX >= 698 && personagemParisX <= 1069) {
        y_reta = 0.514f * personagemParisX - 254.572f;

        if (personagemParisY  == y_reta) {
            colisao_com_reta = true;
        }
        else if (personagemParisY < y_reta) {
            colisao_com_reta = true;
            personagemParisY = y_reta;
        }
    }
    bool colisao_com_reta2 = false;
    float y_reta2 = 0.0f;

    if (personagemParisX >= 692 && personagemParisX <= 1070) {
        y_reta2 = -0.864f * personagemParisX + 1190.23f;

        if (personagemParisY + 70 == y_reta2) {
            colisao_com_reta = true;
        }
        else if (personagemParisY > y_reta2) {
            colisao_com_reta2 = true;
            personagemParisY = y_reta2;
        }
    }
    // Atualiza a posição do personagem se ele estiver em movimento
    if (esta_movendo) {
        // Verifica se o personagem está dentro de uma área restrita
        if (dentro_da_area_restrita1 || dentro_da_area_restrita2 || dentro_da_area_restrita3 || dentro_da_area_restrita4 || colisao_com_reta || colisao_com_reta2 ) {
            //escape reta 3
            if (dentro_da_area_restrita3) {
                if (direcaoY < 0) {
                    personagemParisY += direcaoY * 5;
                }
                else if (direcaoX > 0 && personagemParisX > 693) {
                    personagemParisX += direcaoX * 5;
                }
                else if (direcaoX < 0) {
                    personagemParisX += direcaoX * 5;
                }
            }
            else if (colisao_com_reta) {
                // impede movimento para area restrita
                if (direcaoY > 0) {
                    personagemParisY += direcaoY * 5; // Permite subir
                    dentro_da_area_restrita1 = false;
                }
            }
            else if (colisao_com_reta2) {
                if (direcaoY > 0) {
                    personagemParisY  += direcaoY * 5; // Permite subir
                }

            }
            else {
                if (direcaoX > 0 && personagemParisX < 1080) {
                    personagemParisX += direcaoX * 5;
                }
                else if (direcaoX < 0 && personagemParisX > 0) {
                    personagemParisX += direcaoX * 5;
                }
                else if (direcaoY > 0 && personagemParisY < 624) {
                    personagemParisY += direcaoY * 5;
                }
                else if (direcaoY < 0 && personagemParisY > 100) {
                    personagemParisY += direcaoY * 5;
                }
            }
        }
        else {
            // Movimentação normal fora de áreas restritas
            personagemParisX += direcaoX * 5;
            personagemParisY += direcaoY * 5;
        }
        ultima_direcaoX = direcaoX;
        ultima_direcaoY = direcaoY;
    }
    // Verificar colisão com a area  da próxima fase
    if ((personagemParisX >= 700 && personagemParisX <= 841) && (personagemParisY >= 250 && personagemParisY <= 304)) {
        al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgba(50, 50, 50, 128));
        al_draw_filled_rectangle(500, 350, 780, 410, al_map_rgba(50, 50, 50, 128));
        al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, "PROXIMA FASE");
        // Verifica se o mouse  dentro da area do botão
        if ((mouseX >= 500 && mouseX <= 780) && (mouseY >= 350 && mouseY <= 410)) {
            al_draw_filled_rectangle(500, 350, 780, 410, al_map_rgb(255, 165, 0));
            al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, "PROXIMA FASE");
            al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {

                personagemParisX = 115;
                personagemParisY = 490;
                esta_movendo = false; // controlar o estado de movimento
                direcaoX = 0;    // Direção horizontal -1 = esquerda 1 = direita
                direcaoY = 0;    // Direção vertical -1 = cima, 1 = baixo
                contador_passos = 0;  // Contador para alternar entre os passos
                atraso_animacao = 0; // Controlar a velocidade da animação
                ultima_direcaoX = 0; // Última direção horizontal
                ultima_direcaoY = 0; // Última direção vertical

                navegacao += 1;
            }
        }
        else {
            al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
        }
    }
    al_flip_display();
}