#include "fase_um.h"

void faseUm(ALLEGRO_EVENT evento,int *navegacao) {

	al_draw_bitmap(backgroundFaseUm, 0, 0, 0);
	al_draw_bitmap(personagemHeitor, personagemHeitorX, personagemHeitorY, 0);
	al_draw_bitmap(personagemHelena, personagemHelenaX, personagemHelenaY, 0);
    if ((personagemHeitorX >= 1115 && personagemHeitorX <= 1185) && (personagemHeitorY >= 530 && personagemHeitorY <= 640)) {
        *navegacao = 4;
        al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgba(50, 50, 50, 128));
        al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), (displayX / 2), (displayY / 2), ALLEGRO_ALIGN_CENTRE, "PROXIMA FASE");
    }
	al_flip_display();

    if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
        mouseX = evento.mouse.x;
        mouseY = evento.mouse.y;
        //printf("\nMOUSE X %d\n", mouseX);
        //printf("MOUSE Y %d\n", mouseY);
    }

    if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (evento.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
            personagemHeitorY -= 25; // Move para cima
            printf("Para cima");
            break;
        case ALLEGRO_KEY_DOWN:
            personagemHeitorY += 25; // Move para baixo
            printf("Para baixo");
            break;
        case ALLEGRO_KEY_LEFT:
            personagemHeitorX -= 25; // Move para esquerda
            printf("Para esqueda");
            break;
        case ALLEGRO_KEY_RIGHT:
            personagemHeitorX += 25; // Move para direita
            printf("Para Direita");
            break;
        }
        printf("\nX %d\n", personagemHeitorX);
        printf("y %d\n", personagemHeitorY);
    }

   
}