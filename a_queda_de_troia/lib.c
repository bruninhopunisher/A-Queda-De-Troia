#include "lib.h"

//Variaveis Globais
ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* evento; 
ALLEGRO_DISPLAY* display; 
ALLEGRO_BITMAP* backgroundMenu;
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

//Opções
ALLEGRO_BITMAP* backgroundOpcoes;
ALLEGRO_BITMAP* comVolume;
ALLEGRO_BITMAP* semVolume;
ALLEGRO_BITMAP* comVolumeHover;
ALLEGRO_BITMAP* semVolumeHover;

//Introdução Um
ALLEGRO_BITMAP* fundoHelena;
ALLEGRO_BITMAP* fundoParis;
ALLEGRO_FONT* fonteIntro1;
bool renderizar = 0;

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

//Fase 3
ALLEGRO_BITMAP* imgPuzzle;
ALLEGRO_BITMAP* imgFundoPuzzle;
ALLEGRO_BITMAP* puzzle1;
ALLEGRO_BITMAP* puzzle2;
ALLEGRO_BITMAP* puzzle3;
ALLEGRO_BITMAP* puzzle4;
ALLEGRO_BITMAP* puzzle5;
ALLEGRO_BITMAP* puzzle6;
ALLEGRO_BITMAP* puzzle7;
ALLEGRO_BITMAP* puzzle8;
ALLEGRO_BITMAP* puzzle9;
ALLEGRO_BITMAP* puzzle10;
ALLEGRO_BITMAP* puzzle11;
ALLEGRO_BITMAP* puzzle12;
ALLEGRO_BITMAP* puzzle13;
ALLEGRO_BITMAP* puzzle14;
ALLEGRO_BITMAP* puzzle15;
ALLEGRO_BITMAP* puzzle16;
ALLEGRO_BITMAP* puzzle17;
ALLEGRO_BITMAP* puzzle18;
ALLEGRO_BITMAP* puzzle19;
ALLEGRO_BITMAP* puzzle20;
ALLEGRO_BITMAP* puzzle21;
ALLEGRO_BITMAP* puzzle22;
ALLEGRO_BITMAP* puzzle23;
ALLEGRO_BITMAP* puzzle24;
ALLEGRO_BITMAP* puzzle25;
int contadorCreditos = 3;

//fase 04

ALLEGRO_BITMAP* player;
ALLEGRO_BITMAP* inimigo;
int playX = 640;
int playY = 360;
int iniX = 1280;
int iniY = 360;


//Audios e Musicas
ALLEGRO_SAMPLE* audioMenu;

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
	evento = al_create_event_queue();
	backgroundIntUm = al_load_bitmap("Imagens/Img_Testes/backgroundI1.jpg");

	testeInicializar(timer, "timer");
	testeInicializar(evento, "evento");
	testeInicializar(backgroundIntUm, "backgroundIntUm");

	//Fonte
	fonteMenu = al_load_font("Fontes/MedievalSharp-Bold.ttf", 35, ALLEGRO_ALIGN_CENTRE);
	testeInicializar(fonteMenu, "fonteMenu");

	//Audios Jogo
	audioMenu = al_load_sample("Audios/audio_menu.mp3");
	testeInicializar(audioMenu, "audio_menu");

	//TAMANHO E CRIAÇÃO DO DISPLAY
	displayX = 1280;	
	displayY = 720;
	display = al_create_display(displayX, displayY);
	testeInicializar(display, "display");

	//Menu
	backgroundMenu = al_load_bitmap("Imagens/Menu/background_login.jpg");
	testeInicializar(backgroundMenu, "imagem_menu");

	//Introdução 1
	fundoHelena = al_load_bitmap("Imagens/Introducao_1/helenaIntro1.jpg");
	fundoParis = al_load_bitmap("Imagens/Introducao_1/ParisIntro1.jpg");
	fonteIntro1 = al_load_font("Fontes/MateSC-Regular.ttf", 45, 0);

	testeInicializar(fonteIntro1, "fonte_intro_1");
	testeInicializar(fundoHelena, "fundo_helena-Intro1");
	testeInicializar(fundoParis, "fundo_paris_Intro1");

	//Opções
	backgroundOpcoes = al_load_bitmap("Imagens/Opcoes/background_opcoes.png");
	semVolume = al_load_bitmap("Imagens/Opcoes/sem-som.png");
	comVolume = al_load_bitmap("Imagens/Opcoes/som-musical.png");
	comVolumeHover = al_load_bitmap("Imagens/Opcoes/som-musical-hover.png");
	semVolumeHover = al_load_bitmap("Imagens/Opcoes/sem-som-hover.png");

	testeInicializar(backgroundOpcoes, "backgroundOpcoes");
	testeInicializar(semVolume, "semVolume");
	testeInicializar(comVolume, "comVolume");
	testeInicializar(comVolume, "comVolumeHover");
	testeInicializar(comVolume, "semVolumeHover");

	//Fase 1
	personagemHeitor = al_load_bitmap("Imagens/Fase_01/heitor_um.png");
	personagemHelena = al_load_bitmap("Imagens/Fase_01/helena_um.png");
	backgroundFaseUm = al_load_bitmap("Imagens/Fase_01/background_fase_um.jpg");
	frente_direito = al_load_bitmap("Imagens/Fase_01/frente_descendo.jpg");
	frente_esquerdo = al_load_bitmap("Imagens/Fase_01/frente_descendo_2.jpg");

	testeInicializar(personagemHeitor, "personagemHeitor");
	testeInicializar(personagemHelena, "personagemHelena");
	testeInicializar(backgroundFaseUm, "backgroundFaseUm");
	testeInicializar(frente_direito, "frente_descendo.jpg");
	testeInicializar(frente_esquerdo, "frente_descendo_2.jpg");

	//Fase 2
	background_f2 = al_load_bitmap("background-f2.jpg");
	espada_rei_f2 = al_load_bitmap("espada-rei-f2.jpg");
	espada_player1 = al_load_bitmap("espada1-player-f2.jpg");
	barra_vidaRei_50 = al_load_bitmap("barra-vida-50R.jpg");
	barra_vidaRei_100 = al_load_bitmap("barra-vida-100R-f2.jpg");
	barra_vida_baixa = al_load_bitmap("barra-vida-baixa.jpg");
	barra_vida_cheia = al_load_bitmap("barra-vida-cheia.jpg");

	testeInicializar(background_f2, "background-fase2");
	testeInicializar(espada_player1, "espada1-player1");
	testeInicializar(espada_rei_f2, "espada-rei-f2");
	testeInicializar(barra_vidaRei_50, "barra-vida-50R");
	testeInicializar(barra_vidaRei_100, "barra-vida-100R-f2");
	testeInicializar(barra_vida_baixa, "barra-vida-baixa");

	//Fase 3
	imgPuzzle = al_load_bitmap("Imagens/Fase_03/img_original.jpg");
	imgFundoPuzzle = al_load_bitmap("Imagens/Fase_03/img_fundo.jpg");
	puzzle1 = al_load_bitmap("Imagens/Fase_03/1.jpg");
	puzzle2 = al_load_bitmap("Imagens/Fase_03/2.jpg");
	puzzle3 = al_load_bitmap("Imagens/Fase_03/3.jpg");
	puzzle4 = al_load_bitmap("Imagens/Fase_03/4.jpg");
	puzzle5 = al_load_bitmap("Imagens/Fase_03/5.jpg");
	puzzle6 = al_load_bitmap("Imagens/Fase_03/6.jpg");
	puzzle7 = al_load_bitmap("Imagens/Fase_03/7.jpg");
	puzzle8 = al_load_bitmap("Imagens/Fase_03/8.jpg");
	puzzle9 = al_load_bitmap("Imagens/Fase_03/9.jpg");
	puzzle10 = al_load_bitmap("Imagens/Fase_03/10.jpg");
	puzzle11 = al_load_bitmap("Imagens/Fase_03/11.jpg");
	puzzle12 = al_load_bitmap("Imagens/Fase_03/12.jpg");
	puzzle13 = al_load_bitmap("Imagens/Fase_03/13.jpg");
	puzzle14 = al_load_bitmap("Imagens/Fase_03/14.jpg");
	puzzle15 = al_load_bitmap("Imagens/Fase_03/15.jpg");
	puzzle16 = al_load_bitmap("Imagens/Fase_03/16.jpg");
	puzzle17 = al_load_bitmap("Imagens/Fase_03/17.jpg");
	puzzle18 = al_load_bitmap("Imagens/Fase_03/18.jpg");
	puzzle19 = al_load_bitmap("Imagens/Fase_03/19.jpg");
	puzzle20 = al_load_bitmap("Imagens/Fase_03/20.jpg");
	puzzle21 = al_load_bitmap("Imagens/Fase_03/21.jpg");
	puzzle22 = al_load_bitmap("Imagens/Fase_03/22.jpg");
	puzzle23 = al_load_bitmap("Imagens/Fase_03/23.jpg");
	puzzle24 = al_load_bitmap("Imagens/Fase_03/24.jpg");
	puzzle25 = al_load_bitmap("Imagens/Fase_03/25.jpg");

	testeInicializar(imgPuzzle, "imgPuzzle");
	testeInicializar(imgFundoPuzzle, "imgFundoPuzzle");
	testeInicializar(puzzle1, "puzzle1");
	testeInicializar(puzzle2, "puzzle2");
	testeInicializar(puzzle3, "puzzle3");
	testeInicializar(puzzle4, "puzzle4");
	testeInicializar(puzzle5, "puzzle5");
	testeInicializar(puzzle6, "puzzle6");
	testeInicializar(puzzle7, "puzzle7");
	testeInicializar(puzzle8, "puzzle8");
	testeInicializar(puzzle9, "puzzle9");
	testeInicializar(puzzle10, "puzzle10");
	testeInicializar(puzzle11, "puzzle11");
	testeInicializar(puzzle12, "puzzle12");
	testeInicializar(puzzle13, "puzzle13");
	testeInicializar(puzzle14, "puzzle14");
	testeInicializar(puzzle15, "puzzle15");
	testeInicializar(puzzle16, "puzzle16");
	testeInicializar(puzzle17, "puzzle17");
	testeInicializar(puzzle18, "puzzle18");
	testeInicializar(puzzle19, "puzzle19");
	testeInicializar(puzzle20, "puzzle20");
	testeInicializar(puzzle21, "puzzle21");
	testeInicializar(puzzle22, "puzzle22");
	testeInicializar(puzzle23, "puzzle23");
	testeInicializar(puzzle24, "puzzle24");
	testeInicializar(puzzle25, "puzzle25");

	//fase 4

	player = al_load_bitmap("Imagens/Fase_04/player.jpg");
	inimigo = al_load_bitmap("Imagens/Fase_04/inimigo.jpg");
	testeInicializar(player, "player");
	testeInicializar(inimigo, "inimigo");

}

void audioJogo(int navegacao) {
	if (boolVolume == false) {
		al_stop_samples();
	}
	else {
		switch (navegacao) {
		case 0:
			//Audio menu
			al_play_sample(audioMenu, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 1:
			//Audio Introdução
			al_play_sample(audioMenu, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 2:
			//Audio opções
			al_play_sample(audioMenu, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 3:
			//Audio fase 1
			al_play_sample(audioMenu, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		case 4:
			//Audio fase 2
			al_play_sample(audioMenu, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			break;
		}
	}
}

void imagemIntro(ALLEGRO_BITMAP* imagem, ALLEGRO_EVENT evento) {
	al_draw_bitmap(imagem, 0, 0, 0);
	al_draw_filled_rectangle(1016, 653, 1189, 692, al_map_rgb(222, 158, 30));
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1095, 650, ALLEGRO_ALIGN_CENTRE, "Proximo");
	if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK); 
	}
	else {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_ARROW); 
	}
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
			intro += 1;
		}
	}
}

//FUNÇÃO QUE DESTROI TODAS AS ALOCAÇÕES DE MEMÓRIA
void destruidor() {

	//Global
	al_destroy_font(fonteMenu);
	al_destroy_bitmap(backgroundIntUm); //Img Teste

	//Audios e Musicas
	al_destroy_sample(audioMenu);

	//Menu
	al_destroy_bitmap(backgroundMenu);

	//Opções
	al_destroy_bitmap(backgroundOpcoes);
	al_destroy_bitmap(comVolume);
	al_destroy_bitmap(semVolume);
	al_destroy_bitmap(comVolumeHover);
	al_destroy_bitmap(semVolumeHover);

	//Introdução 1
	al_destroy_bitmap(fundoHelena);
	al_destroy_bitmap(fundoParis);
	al_destroy_font(fonteIntro1);

	//Fase 1
	al_destroy_bitmap(backgroundFaseUm);
	al_destroy_bitmap(personagemHeitor);
	al_destroy_bitmap(personagemHelena);
	al_destroy_bitmap(frente_direito);
	al_destroy_bitmap(frente_esquerdo);
	
	//Fase 2
	al_destroy_bitmap(background_f2);
	al_destroy_bitmap(espada_player1);
	al_destroy_bitmap(espada_rei_f2);

	//Fase 3
	al_destroy_bitmap(imgPuzzle);
	al_destroy_bitmap(imgFundoPuzzle);
	al_destroy_bitmap(puzzle1);
	al_destroy_bitmap(puzzle2);
	al_destroy_bitmap(puzzle3);
	al_destroy_bitmap(puzzle4);
	al_destroy_bitmap(puzzle5);
	al_destroy_bitmap(puzzle6);
	al_destroy_bitmap(puzzle7);
	al_destroy_bitmap(puzzle8);
	al_destroy_bitmap(puzzle9);
	al_destroy_bitmap(puzzle10);
	al_destroy_bitmap(puzzle11);
	al_destroy_bitmap(puzzle12);
	al_destroy_bitmap(puzzle13);
	al_destroy_bitmap(puzzle14);
	al_destroy_bitmap(puzzle15);
	al_destroy_bitmap(puzzle16);
	al_destroy_bitmap(puzzle17);
	al_destroy_bitmap(puzzle18);
	al_destroy_bitmap(puzzle19);
	al_destroy_bitmap(puzzle20);
	al_destroy_bitmap(puzzle21);
	al_destroy_bitmap(puzzle22);
	al_destroy_bitmap(puzzle23);
	al_destroy_bitmap(puzzle24);
	al_destroy_bitmap(puzzle25);

	//fese 4
	al_destroy_bitmap (player);
	al_destroy_bitmap (inimigo);
}