#include "lib.h"

ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* evento;
ALLEGRO_DISPLAY* display;
ALLEGRO_BITMAP* backgroundMenu;
ALLEGRO_BITMAP* backgroundIntUm;

void static testeInicializar(bool metodo, char* referencia) {
	if (!metodo) {
		printf("Falha ao iniciar o %s", referencia);
	} 
}

void static iniciarAddons() {
	//Inicia o Allegro
	testeInicializar(al_init(), "Allegro");
	//Inicia Addon do Teclado
	testeInicializar(al_install_keyboard(), "Teclado");
	//Inicia Addon da Imagem
	testeInicializar(al_init_image_addon(), "Imagem");
	//Inicia Addon das Primitivas
	testeInicializar(al_init_primitives_addon(), "Primitivas");
	//Inicia Addon do Mouse
	testeInicializar(al_install_mouse(), "Mouse");
}

void static iniciarConstantes() {
	//Cria um ponteiro timer que armazena o cronometro
	timer = al_create_timer(1.0 / 30.0);
	testeInicializar(timer, "timer");

	//Cria um ponteiro para uma fila de eventos
	evento = al_create_event_queue();
	testeInicializar(evento, "evento");

	//Cria um ponteiro para o Display
	display = al_create_display(1280, 720);
	testeInicializar(display, "display");

	//Cria um ponteiro que recebe a Imagem do Menu
	backgroundMenu = al_load_bitmap("background_login.png");
	testeInicializar(backgroundMenu, "imagem_menu");

	//Cria um ponteiro que recebe a Imagem do Menu
	backgroundIntUm = al_load_bitmap("backgroundI1.jpg");
	testeInicializar(backgroundIntUm, "imagem_menu");
}