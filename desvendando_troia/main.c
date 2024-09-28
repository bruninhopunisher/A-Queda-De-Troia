#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdbool.h>

// Inicia Allegro e pacotes
static void iniciarPacotes() {
	if (!al_init()) {
		printf("Falha ao inicializar o Allegro!\n");
	}
    if (!al_init_image_addon()) {
        printf("Falha ao inicializar o addon de imagens!\n");
    }
    if (!al_init_primitives_addon()) {
        printf("Falha ao inicializar o addon de primitivas!\n");
    }
    if (!al_install_mouse()) {
        printf("Falha ao inicializar o addon do mouse!\n");
    }
}

// Atribuição de valores para variaveis
static void atribuirValores(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue, ALLEGRO_BITMAP **background) {

    *display = al_create_display(1280, 720);
    if (!*display) {
        printf("Falha ao criar o display!\n");
        return;
    }

    *event_queue = al_create_event_queue();
    if (!*event_queue) {
        printf("Falha ao criar a fila de eventos!\n");
        al_destroy_display(*display);
        return;
    }

    *background = al_load_bitmap("background_login.png");
    if (!*background) {
        printf("Falha ao carregar a imagem de fundo!\n");
        al_destroy_display(*display);
        al_destroy_event_queue(*event_queue);
        return;
    }
}

// Destruir pacotes
static void destruirPacotes(ALLEGRO_BITMAP* background, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_DISPLAY* display) {
    if (background) {
        al_destroy_bitmap(background);
    }
    if (event_queue) {
        al_destroy_event_queue(event_queue);
    }
    if (display) {
        al_destroy_display(display);
    }
}

int main() {
    iniciarPacotes();

    // Declaração das variaveis
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_BITMAP *background = NULL;

    atribuirValores(&display, &event_queue, &background);

	// Verifica inicialização
    if (!display || !event_queue || !background) {
        return -1;
    }

    // Registra as fontes de eventos
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    // Controle de coordenadas do mouse
    float mouse_x = 0, mouse_y = 0;
    bool mouse_pressed = false;
    bool running = true;

    // Loop principal
    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        // Verifica o tipo de evento
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;  // Encerra o programa se a janela for fechada
        }
        else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
            // Captura a posição do mouse
            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
            printf("x-%0.2f-\n", mouse_x);
            printf("y-%0.2f\n", mouse_y);
        }
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            // Detecta o clique do mouse 
            mouse_pressed = true;
            //Encerra o display e destroi os eventos ao clicar em Sair
            if (mouse_pressed == true &&
                (mouse_x >= 72 && mouse_x <= 173) &&
                (mouse_y >= 650 && mouse_y <= 681)){
                destruirPacotes(background, event_queue, display);
                return 0;
            }
        }
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            // Detecta quando o botão do mouse é solto
            mouse_pressed = false;
        }

        // Desenha a imagem de fundo
        al_draw_bitmap(background, 0, 0, 0);

        // Atualiza a tela
        al_flip_display();
    }

	destruirPacotes(background, event_queue, display);

    return 0;
}