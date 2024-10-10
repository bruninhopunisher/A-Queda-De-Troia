#include "lib.h"

ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* evento;
ALLEGRO_DISPLAY* display;
ALLEGRO_BITMAP* backgroundMenu;
ALLEGRO_BITMAP* introducao1_1;
ALLEGRO_BITMAP* introducao1_2;
ALLEGRO_BITMAP* introducao1_3;
ALLEGRO_BITMAP* introducao1_4;
ALLEGRO_BITMAP* introducao1_5;
ALLEGRO_BITMAP* introducao1_6;
ALLEGRO_BITMAP* introducao1_7;
ALLEGRO_BITMAP* backgroundIntUm; // Imagem teste apenas
ALLEGRO_FONT* fonteMenu;

int displayX;
int displayY;
int mouseX;
int mouseY;
int intru01 = 1;

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

<<<<<<< HEAD
	introducao1_1 = al_load_bitmap("introducao1_1.jpg");
	testeInicializar(backgroundMenu, "introducao1_1");
	
	introducao1_2 = al_load_bitmap("introducao1_2.jpg");
	testeInicializar(backgroundMenu, "introducao1_2");

	introducao1_3 = al_load_bitmap("introducao1_3.jpg");
	testeInicializar(backgroundMenu, "introducao1_3");

	introducao1_4 = al_load_bitmap("introducao1_4.jpg");
	testeInicializar(backgroundMenu, "introducao1_4");

	introducao1_5 = al_load_bitmap("introducao1_5.jpg");
	testeInicializar(backgroundMenu, "introducao1_5");

	introducao1_6 = al_load_bitmap("introducao1_6.jpg");
	testeInicializar(backgroundMenu, "introducao1_6");

	introducao1_7 = al_load_bitmap("introducao1_7.jpg");
	testeInicializar(backgroundMenu, "introducao1_7");
	
	//Cria um ponteiro que recebe a Imagem do Menu
=======
>>>>>>> 013a76183f264ae7bc1f20d521e29900fe879bf3
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