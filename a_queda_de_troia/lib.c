#include "lib.h"

//Variaveis Globais
ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* evento; 
ALLEGRO_DISPLAY* display; 
ALLEGRO_BITMAP* backgroundMenu;

//Opções
ALLEGRO_BITMAP* backgroundOpcoes;
ALLEGRO_BITMAP* comVolume;
ALLEGRO_BITMAP* semVolume;
ALLEGRO_BITMAP* comVolumeHover;
ALLEGRO_BITMAP* semVolumeHover;

//Introdução Um
ALLEGRO_BITMAP* introducao1_1;
ALLEGRO_BITMAP* introducao1_2;
ALLEGRO_BITMAP* introducao1_3;
ALLEGRO_BITMAP* introducao1_4;
ALLEGRO_BITMAP* introducao1_5;
ALLEGRO_BITMAP* introducao1_6;
ALLEGRO_BITMAP* introducao1_7;

//Fase 1
ALLEGRO_BITMAP* backgroundFaseUm;
ALLEGRO_BITMAP* personagemHeitor;
ALLEGRO_BITMAP* personagemHelena;
ALLEGRO_BITMAP* frente_direito;
ALLEGRO_BITMAP* frente_esquerdo;

int personagemHeitorX = 115;
int personagemHeitorY = 490;
int personagemHelenaX = 1150;
int personagemHelenaY = 585;
 
//Fase 2
ALLEGRO_BITMAP* background_f2;
ALLEGRO_BITMAP* espada_player1;
ALLEGRO_BITMAP* espada_rei_f2;
ALLEGRO_BITMAP* barra_vida_cheia;
ALLEGRO_BITMAP* barra_vida_baixa;
ALLEGRO_BITMAP* barra_vidaRei_100;
ALLEGRO_BITMAP* barra_vidaRei_50;
int pressionado = 0;
int ultPressionado = 0;
//HEITOR
int positionX1_heitor = 615;
int positionX2_heitor = 665;
int positionY1_heitor = 100;
int positionY2_heitor = 170;
//PARIS
int positionX1_f2 = 615;
int positionX2_f2 = 665;
int positionY1_f2 = 225;
int positionY2_f2 = 295;
int positionX_espada1 = 605;
int positionY_espada1 = 275;
int limiteAtaque = 0;
bool controleJogador = false;
bool atacando = false;
//REI MENELAU
int positionX_espadaR = 630;
int positionY_espadaR = 355;
int vidaJogador = 100;
int limiteAtaqueR = 0;
int ataqueReiTimer = 0;
int vidaRei = 1000;

//Audios e Musicas
ALLEGRO_SAMPLE* musicaPadrao;

//Demais
ALLEGRO_BITMAP* backgroundIntUm; // Imagem teste
ALLEGRO_FONT* fonteMenu;

int displayX;
int displayY;
int mouseX;
int mouseY;
int intro = 1;
int navegacao = 0;
bool rodando = true;
bool boolVolume = true;

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
	testeInicializar(al_install_audio(), "audio");
	testeInicializar(al_init_acodec_addon(), "audio codecs");
	//Toca 16 sons simultaneamente
	testeInicializar(al_reserve_samples(16), "reserve samples");
}

void iniciarConstantes() {
	//Global
	timer = al_create_timer(0.5 / 30.0);
	testeInicializar(timer, "timer");

	evento = al_create_event_queue();
	testeInicializar(evento, "evento");



	//TAMANHO E CRIAÇÃO DO DISPLAY
	displayX = 1280;	
	displayY = 720;
	display = al_create_display(displayX, displayY);
	testeInicializar(display, "display");



	//Menu
	backgroundMenu = al_load_bitmap("Imagens/Menu/background_login.jpg");
	testeInicializar(backgroundMenu, "imagem_menu");



	//Introdução 1
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



	//Opções
	backgroundOpcoes = al_load_bitmap("Imagens/Opcoes/background_opcoes.png");
	testeInicializar(backgroundOpcoes, "backgroundOpcoes");

	semVolume = al_load_bitmap("Imagens/Opcoes/sem-som.png");
	testeInicializar(semVolume, "semVolume");

	comVolume = al_load_bitmap("Imagens/Opcoes/som-musical.png");
	testeInicializar(comVolume, "comVolume");

	comVolumeHover = al_load_bitmap("Imagens/Opcoes/som-musical-hover.png");
	testeInicializar(comVolume, "comVolumeHover");

	semVolumeHover = al_load_bitmap("Imagens/Opcoes/sem-som-hover.png");
	testeInicializar(comVolume, "semVolumeHover");



	//Fase 1
	personagemHeitor = al_load_bitmap("Imagens/Fase_Um/heitor_um.png");
	testeInicializar(personagemHeitor, "personagemHeitor");

	personagemHelena = al_load_bitmap("Imagens/Fase_Um/helena_um.png");
	testeInicializar(personagemHelena, "personagemHelena");

	backgroundFaseUm = al_load_bitmap("Imagens/Fase_Um/background_fase_um.jpg");
	testeInicializar(backgroundFaseUm, "backgroundFaseUm");

	frente_direito = al_load_bitmap("Imagens/Fase_Um/frente_descendo.jpg");
	testeInicializar(frente_direito, "frente_descendo.jpg");

	frente_esquerdo = al_load_bitmap("Imagens/Fase_Um/frente_descendo_2.jpg");
	testeInicializar(frente_esquerdo, "frente_descendo_2.jpg");



	//Fase 2
	background_f2 = al_load_bitmap("background-f2.jpg");
	testeInicializar(background_f2, "background-fase2");

	espada_player1 = al_load_bitmap("espada1-player-f2.jpg");
	testeInicializar(espada_player1, "espada1-player1");
	
	espada_rei_f2 = al_load_bitmap("espada-rei-f2.jpg");
	testeInicializar(espada_rei_f2, "espada-rei-f2");

	barra_vida_cheia = al_load_bitmap("barra-vida-cheia.jpg");
	testeInicializar(barra_vida_cheia, "barra_vida_cheia-f2");

	barra_vida_baixa = al_load_bitmap("barra-vida-baixa.jpg");
	testeInicializar(barra_vida_baixa, "barra_vida_baixa-f2");

	barra_vidaRei_100 = al_load_bitmap("barra-vida-100R-f2.jpg");
	testeInicializar(barra_vidaRei_100, "barra_vida_Rei_100");

	barra_vidaRei_50 = al_load_bitmap("barra-vida-50R.jpg");
	testeInicializar(barra_vidaRei_50, "barra_vida_Rei_50");


	//Fonte
	fonteMenu = al_load_font("Fontes/MedievalSharp-Bold.ttf", 35, ALLEGRO_ALIGN_CENTRE);
	testeInicializar(fonteMenu, "fonteMenu");



	//Audios Jogo
	musicaPadrao = al_load_sample("Audios/audio_padrao.mp3");
	testeInicializar(musicaPadrao, "musica_padrao");
}

void audioJogo(int navegacao) {
	if (boolVolume == false) {
		al_stop_samples();
	}
	else {
		switch (navegacao) {
		case 0:
			//Audio menu
			al_play_sample(musicaPadrao, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 1:
			//Audio Introdução
			al_play_sample(musicaPadrao, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 2:
			//Audio opções
			al_play_sample(musicaPadrao, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 3:
			//Audio fase 1
			al_play_sample(musicaPadrao, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 4:
			//Audio fase 2
			al_play_sample(musicaPadrao, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		}
	}
}

//FUNÇÃO QUE DESTROI TODAS AS ALOCAÇÕES DE MEMÓRIA
void destruidor() {
	//Fase 2
	al_destroy_bitmap(background_f2);
	al_destroy_bitmap(espada_player1);
	al_destroy_bitmap(espada_rei_f2);
	al_destroy_bitmap(barra_vida_cheia);
	al_destroy_bitmap(barra_vida_baixa);
	al_destroy_bitmap(barra_vidaRei_100);
	al_destroy_bitmap(barra_vidaRei_50);
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
	al_destroy_bitmap(comVolumeHover);
	al_destroy_bitmap(semVolumeHover);
	al_destroy_sample(musicaPadrao);
	al_destroy_bitmap(backgroundFaseUm);
	al_destroy_bitmap(personagemHeitor);
	al_destroy_bitmap(personagemHelena);
	al_destroy_bitmap(frente_direito);
	al_destroy_bitmap(frente_esquerdo);
}