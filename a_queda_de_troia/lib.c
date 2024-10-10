#include "lib.h"

ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* evento;
ALLEGRO_DISPLAY* display;
ALLEGRO_BITMAP* backgroundMenu;
ALLEGRO_BITMAP* backgroundOpcoes;
ALLEGRO_BITMAP* comVolume;
ALLEGRO_BITMAP* semVolume;
ALLEGRO_BITMAP* introducao1_1;
ALLEGRO_BITMAP* introducao1_2;
ALLEGRO_BITMAP* introducao1_3;
ALLEGRO_BITMAP* introducao1_4;
ALLEGRO_BITMAP* introducao1_5;
ALLEGRO_BITMAP* introducao1_6;
ALLEGRO_BITMAP* introducao1_7;
ALLEGRO_BITMAP* backgroundIntUm; // Imagem teste
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

//Inicia os Addons
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

	backgroundMenu = al_load_bitmap("Imagens/Menu/background_login.jpg");
	testeInicializar(backgroundMenu, "imagem_menu");

	introducao1_1 = al_load_bitmap("Imagens/Introducao_1/intro1.jpg");
	testeInicializar(backgroundMenu, "introducao1_1");
	
	introducao1_2 = al_load_bitmap("Imagens/Introducao_1/intro2.jpg");
	testeInicializar(backgroundMenu, "introducao1_2");
	
	introducao1_3 = al_load_bitmap("Imagens/Introducao_1/intro3.jpg");
	testeInicializar(backgroundMenu, "introducao1_3");

	introducao1_4 = al_load_bitmap("Imagens/Introducao_1/intro4.jpg");
	testeInicializar(backgroundMenu, "introducao1_4");

	introducao1_5 = al_load_bitmap("Imagens/Introducao_1/intro5.jpg");
	testeInicializar(backgroundMenu, "introducao1_5");

	introducao1_6 = al_load_bitmap("Imagens/Introducao_1/intro6.jpg");
	testeInicializar(backgroundMenu, "introducao1_6");

	introducao1_7 = al_load_bitmap("Imagens/Introducao_1/intro7.jpg");
	testeInicializar(backgroundMenu, "introducao1_7");

	backgroundIntUm = al_load_bitmap("Imagens/Img_Testes/backgroundI1.jpg");
	testeInicializar(backgroundIntUm, "imagemMenu");

	backgroundOpcoes = al_load_bitmap("Imagens/Opcoes/background_opcoes.png");
	testeInicializar(backgroundOpcoes, "backgroundOpcoes");

	semVolume = al_load_bitmap("Imagens/Opcoes/sem_volume.png");
	testeInicializar(semVolume, "semVolume");

	comVolume = al_load_bitmap("Imagens/Opcoes/com_volume.png");
	testeInicializar(comVolume, "comVolume");

	fonteMenu = al_load_font("Fontes/MedievalSharp-Bold.ttf", 35, ALLEGRO_ALIGN_CENTRE);
	testeInicializar(fonteMenu, "fonteMenu");

}

void destruidor() {
	al_destroy_font(fonteMenu);
	al_destroy_bitmap(backgroundIntUm);
	al_destroy_bitmap(backgroundMenu);
	al_destroy_bitmap(backgroundOpcoes);
	al_destroy_bitmap(introducao1_1);
	al_destroy_bitmap(introducao1_2);
	al_destroy_bitmap(introducao1_3);
	al_destroy_bitmap(introducao1_4);
	al_destroy_bitmap(introducao1_5);
	al_destroy_bitmap(introducao1_6);
	al_destroy_bitmap(introducao1_7);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(evento);
	al_destroy_bitmap(comVolume);
	al_destroy_bitmap(semVolume);
}