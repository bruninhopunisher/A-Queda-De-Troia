#include "fase01.h"

void fase01(ALLEGRO_EVENT evento) {

    bool is_moving = false;

	al_draw_bitmap(backgroundFaseUm, 0, 0, 0);
	al_draw_bitmap(frente_direito, personagemHeitorX, personagemHeitorY, 0);
	al_draw_bitmap(personagemHelena, personagemHelenaX, personagemHelenaY, 0);
    if ((personagemHeitorX >= 1115 && personagemHeitorX <= 1185) && (personagemHeitorY >= 530 && personagemHeitorY <= 640)) {
        al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgba(50, 50, 50, 128));
        al_draw_filled_rectangle(500, 350, 780, 410, al_map_rgba(50, 50, 50, 128));
        al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, "PROXIMA FASE");

        // Verifica se o mouse está dentro da área do botão
        if ((mouseX >= 500 && mouseX <= 780) && (mouseY >= 350 && mouseY <= 410)) {
            al_draw_filled_rectangle(500, 350, 780, 410, al_map_rgb(255, 165, 0));
            al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 640, 360, ALLEGRO_ALIGN_CENTRE, "PROXIMA FASE");
            al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
            //printf("Aqui no botão");
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
                intro = 1;
                navegacao += 1;
            }
        }
        else {
            // Resetar o cursor apenas se o mouse estiver fora da área do botão
            al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
        }
    }

	al_flip_display();

    if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
        mouseX = evento.mouse.x;
        mouseY = evento.mouse.y;
        //printf("\nMOUSE X %d\n", mouseX);
        //printf("MOUSE Y %d\n", mouseY);
    }

    switch (evento.type) {
    case ALLEGRO_EVENT_KEY_DOWN:
        is_moving = true; // Personagem começa a se mover quando a tecla é pressionada
        switch (evento.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
            personagemHeitorY -= 25; // Move para cima
            al_draw_bitmap(frente_esquerdo, personagemHeitorX, personagemHeitorY, 0);
            //printf("Para cima\n");
            break;

        case ALLEGRO_KEY_DOWN:
            personagemHeitorY += 25; // Move para baixo
            al_draw_bitmap(personagemHeitor, personagemHeitorX, personagemHeitorY, 0);
            al_flip_display();
            //printf("Para baixo\n");
            break;

        case ALLEGRO_KEY_LEFT:
            personagemHeitorX -= 25; // Move para esquerda
            al_draw_bitmap(personagemHeitor, personagemHeitorX, personagemHeitorY, 0);
            al_flip_display();
            //printf("Para esquerda\n");
            break;

        case ALLEGRO_KEY_RIGHT:
            personagemHeitorX += 25; // Move para direita
            al_draw_bitmap(personagemHeitor, personagemHeitorX, personagemHeitorY, 0);
            al_flip_display();
            //printf("Para direita\n");
            break;
        }
        break;

    case ALLEGRO_EVENT_KEY_UP:
        is_moving = false; // Quando a tecla é solta, o personagem para
        //printf("Tecla solta\n");
        break;
    }
}