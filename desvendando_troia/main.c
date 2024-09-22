#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdbool.h>

//Novo tipo que é um ponteiro a uma função que retorna um valor Booleano.
typedef bool(*IniciarAddon)();

static void iniciarAddons(IniciarAddon refAddon,char *nomeAddon) {
    if (!refAddon()) {
        printf("Addon %s não inicializado!", nomeAddon);
    }
}

int main() {

    // Inicializa o Allegro
    if (!al_init()) {
        printf("Falha ao inicializar o Allegro!\n");
        return -1;
    }

    //Inicializando addon de Imagens
    iniciarAddons(al_init_image_addon, "imagem");
    //Inicializando addon de Primiticas ( Desenha formas geometricas )
    iniciarAddons(al_init_primitives_addon, "primitivas");
    //Inicializando addon do Mouse
    iniciarAddons(al_install_mouse, "mouse");


    // Cria o display (janela) de 800x600
    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);
    if (!display) {
        printf("Falha ao criar o display!\n");
        return -1;
    }

    // Cria a fila de eventos
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    if (!event_queue) {
        printf("Falha ao criar a fila de eventos!\n");
        al_destroy_display(display);
        return -1;
    }

    // Carrega a imagem de fundo (certifique-se de que a imagem existe)
    ALLEGRO_BITMAP* background = al_load_bitmap("background_login.png");
    if (!background) {
        printf("Falha ao carregar a imagem de fundo!\n");
        al_destroy_display(display);
        al_destroy_event_queue(event_queue);
        return -1;
    }

    // Registra as fontes de eventos
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    // Vari�veis para controlar o mouse
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
            // Captura a posi��o do mouse
            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
            printf("x-%0.2f-\n", mouse_x);
            printf("y-%0.2f\n", mouse_y);
        }
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            // Detecta o clique do mouse 
            mouse_pressed = true;
            //Encerra o display e destroi os eventos ao clicar em Sair
            if (mouse_pressed = true &&
                (mouse_x >= 72 && mouse_x <= 173) &&
                (mouse_y >= 650 && mouse_y <= 681)){
                al_destroy_bitmap(background); 
                al_destroy_event_queue(event_queue);
                al_destroy_display(display);
                return 0;
            }
        }
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            // Detecta quando o bot�o do mouse � solto
            mouse_pressed = false;
        }

        // Desenha a imagem de fundo
        al_draw_bitmap(background, 0, 0, 0);

        // Atualiza a tela
        al_flip_display();
    }

    // Limpeza de recursos
    al_destroy_bitmap(background);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    return 0;
}