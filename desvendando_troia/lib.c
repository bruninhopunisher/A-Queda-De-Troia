#include "lib.h"

ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* evento;
ALLEGRO_DISPLAY* display;
ALLEGRO_BITMAP* backgroundMenu;
ALLEGRO_BITMAP* backgroundIntUm;
ALLEGRO_FONT* fonteMenu;

int displayX;
int displayY;
int mouseX;
int mouseY;

void testeInicializar(bool metodo, char* referencia) {
	if (!metodo) {
		printf("Falha ao iniciar o %s", referencia);
	} 
}

//Inicia o Allegro
void iniciarAddons() {

	testeInicializar(al_init(), "Allegro");
	testeInicializar(al_install_keyboard(), "Teclado");
	testeInicializar(al_init_image_addon(), "Imagem");
	testeInicializar(al_init_primitives_addon(), "Primitivas");
	testeInicializar(al_install_mouse(), "Mouse");
	testeInicializar(al_init_font_addon(), "Fonte");
	testeInicializar(al_init_ttf_addon(), "TTF"); 
}

void iniciarConstantes() {
	timer = al_create_timer(1.0 / 30.0);
	testeInicializar(timer, "timer");

	evento = al_create_event_queue();
	testeInicializar(evento, "evento");

	displayX = 1280;	
	displayY = 720;
	display = al_create_display(displayX, displayY);
	testeInicializar(display, "display");

	backgroundMenu = al_load_bitmap("background_login.png");
	testeInicializar(backgroundMenu, "imagem_menu");

	backgroundIntUm = al_load_bitmap("backgroundI1.jpg");
	testeInicializar(backgroundIntUm, "imagemMenu");

	fonteMenu = al_load_font("MedievalSharp-Bold.ttf", 35, ALLEGRO_ALIGN_CENTRE);
	testeInicializar(fonteMenu, "fonteMenu");

}

void destroiComponentes() {
	al_destroy_font(fonteMenu);
	al_destroy_bitmap(backgroundIntUm);
	al_destroy_bitmap(backgroundMenu);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(evento);
}