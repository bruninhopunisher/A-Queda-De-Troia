#include "lib.h"

//Variaveis Globais
ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* evento;
ALLEGRO_DISPLAY* display;
ALLEGRO_BITMAP* backgroundMenu;
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

//Introdução 1
ALLEGRO_BITMAP* fundoHelena;
ALLEGRO_BITMAP* fundoParis;
ALLEGRO_FONT* fonteIntro1;
bool renderizar = 0;

//Introdução 2
ALLEGRO_BITMAP* fundoAgamenom;
ALLEGRO_BITMAP* fundoMenelau;

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
//Personagem paris;
ALLEGRO_BITMAP* background_f2;
ALLEGRO_BITMAP* espada_player1;
ALLEGRO_BITMAP* espada_rei_f2;
ALLEGRO_BITMAP* barra_vida_cheia;
ALLEGRO_BITMAP* barra_vida_baixa;
ALLEGRO_BITMAP* barra_vidaRei_100;
ALLEGRO_BITMAP* barra_vidaRei_50;
ALLEGRO_BITMAP* soldadosEsparta;
int pressionado = 0;
int ultPressionado = 0;
int movimento = 0;
//HEITOR
int positionX1_heitor = 615;
int positionX2_heitor = 665;
int positionY1_heitor = 100;
int positionY2_heitor = 170;
//PARIS
ALLEGRO_BITMAP* ParisBaixoEsq;
ALLEGRO_BITMAP* ParisBaixoDir;
ALLEGRO_BITMAP* ParisBaixoNormal;
ALLEGRO_BITMAP* ParisEsqDir;
ALLEGRO_BITMAP* ParisEsqEsq;
ALLEGRO_BITMAP* ParisEsqNormal;
ALLEGRO_BITMAP* ParisCimaNormal;
ALLEGRO_BITMAP* ParisCimaEsq;
ALLEGRO_BITMAP* ParisCimaDir;
ALLEGRO_BITMAP* ParisDirNormal;
ALLEGRO_BITMAP* ParisDirEsq;
ALLEGRO_BITMAP* ParisDirDir;
int positionX1_f2 = 615;
int positionY1_f2 = 225;
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
bool verificaPuzzle = true;

//Fase 04
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

	testeInicializar(timer, "timer");
	testeInicializar(evento, "evento");

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

	//Introdução 2
	fundoAgamenom = al_load_bitmap("Imagens/Introducao_2/fundoAgamenom.jpg");
	fundoMenelau = al_load_bitmap("Imagens/Introducao_2/fundoMenelau.jpg");

	testeInicializar(fundoAgamenom, "fundo-agamenom-Intro2");
	testeInicializar(fundoAgamenom, "fundo-menelau-Intro2");

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
	background_f2 = al_load_bitmap("Imagens/Fase_02/background-f2.jpg");
	espada_rei_f2 = al_load_bitmap("Imagens/Fase_02/espada-rei-f2.jpg");
	espada_player1 = al_load_bitmap("Imagens/Fase_02/espada1-player-f2.jpg");
	barra_vidaRei_50 = al_load_bitmap("Imagens/Fase_02/barra-vida-50R.jpg");
	barra_vidaRei_100 = al_load_bitmap("Imagens/Fase_02/barra-vida-100R-f2.jpg");
	barra_vida_baixa = al_load_bitmap("Imagens/Fase_02/barra-vida-baixa.jpg");
	barra_vida_cheia = al_load_bitmap("Imagens/Fase_02/barra-vida-cheia.jpg");
	ParisBaixoDir = al_load_bitmap("Imagens/Fase_02/ParisBaixoDir.jpg");
	ParisBaixoEsq = al_load_bitmap("Imagens/Fase_02/ParisBaixoEsq.jpg");
	ParisBaixoNormal = al_load_bitmap("Imagens/Fase_02/ParisBaixoNormal.jpg");
	ParisEsqNormal = al_load_bitmap("Imagens/Fase_02/ParisEsqNormal.jpg");
	ParisEsqEsq = al_load_bitmap("Imagens/Fase_02/ParisEsqEsq.jpg");
	ParisEsqDir = al_load_bitmap("Imagens/Fase_02/ParisEsqDir.jpg");
	ParisCimaNormal = al_load_bitmap("Imagens/Fase_02/ParisCimaNormal.jpg");
	ParisCimaEsq = al_load_bitmap("Imagens/Fase_02/ParisCimaEsq.jpg");
	ParisCimaDir = al_load_bitmap("Imagens/Fase_02/ParisCimaDir.jpg");
	ParisDirNormal = al_load_bitmap("Imagens/Fase_02/ParisDirNormal.jpg");
	ParisDirEsq = al_load_bitmap("Imagens/Fase_02/ParisDirEsq.jpg");
	ParisDirDir = al_load_bitmap("Imagens/Fase_02/ParisDirDir.jpg");
	soldadosEsparta = al_load_bitmap("Imagens/Fase_02/soldadosEsparta.jpg");

	testeInicializar(soldadosEsparta, "soldados_esparta");
	testeInicializar(ParisDirDir, "Paris_Dir_Dir");
	testeInicializar(ParisDirEsq, "Paris_Dir_Esq");
	testeInicializar(ParisDirNormal, "Paris_Dir_Normal");
	testeInicializar(ParisCimaDir, "Paris_Cima_Dir");
	testeInicializar(ParisCimaEsq, "Paris_Cima_Esq");
	testeInicializar(ParisCimaNormal, "Paris_Cima_Normal");
	testeInicializar(ParisEsqDir, "Paris_Esq_Dir");
	testeInicializar(ParisEsqEsq, "Paris_Esq_Esq");
	testeInicializar(ParisEsqNormal, "Paris_Esq_Normal");
	testeInicializar(ParisBaixoNormal, "Paris_Baixo_Normal");
	testeInicializar(ParisBaixoEsq, "Paris_Baixo_Esq");
	testeInicializar(ParisBaixoDir, "Paris_Baixo_Dir");
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

void movimentarPlayer(ALLEGRO_EVENT evento, int* posicaoX, int* posicaoY) {

	//VERIFICA QUAL TECLA PRESSIONOU

	switch (evento.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
			pressionado = 1;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
			pressionado = 2;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
			pressionado = 3;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			pressionado = 4;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE) {
			atacando = true;
		}
		break;
	case ALLEGRO_EVENT_KEY_UP:
		if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
			ultPressionado = 1;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
			ultPressionado = 2;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
			ultPressionado = 3;
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			ultPressionado = 4;
		}
		if (pressionado == ultPressionado) {
			pressionado = 0;
			ultPressionado = 0;
		}
	}

	//MOVIMENTAÇÃO DO JOGADOR

	switch (pressionado)
	{
	case 1:
		*posicaoY -= 2;
		break;
	case 2:
		*posicaoX -= 2;
		break;
	case 3:
		*posicaoX += 2;
		break;
	case 4:
		*posicaoY += 2;
		break;
	}
}

void movimentoSprite(ALLEGRO_BITMAP* baixoN, ALLEGRO_BITMAP* baixoE, ALLEGRO_BITMAP* baixoD,
					 ALLEGRO_BITMAP* esquerdaN, ALLEGRO_BITMAP* esquerdaE, ALLEGRO_BITMAP* esquerdaD,
					 ALLEGRO_BITMAP* cimaN, ALLEGRO_BITMAP* cimaE, ALLEGRO_BITMAP* cimaD,
					 ALLEGRO_BITMAP* direitaN, ALLEGRO_BITMAP* direitaE, ALLEGRO_BITMAP* direitaD,
				     int posicaoX, int posicaoY) {
	switch (pressionado)
	{
	case 0:
		al_draw_bitmap(baixoN, posicaoX, posicaoY, 0);
		break;
	case 1:
		if (movimento >= 0 && movimento < 20) {
			al_draw_bitmap(cimaN, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento >= 20 && movimento < 40) {
			al_draw_bitmap(cimaE, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento == 40) {
			al_draw_bitmap(cimaD, posicaoX, posicaoY, 0);
			movimento = 0;
		}
		break;
	case 2:
		if (movimento >= 0 && movimento < 20) {
			al_draw_bitmap(esquerdaN, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento >= 20 && movimento < 40) {
			al_draw_bitmap(esquerdaE, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento == 40) {
			al_draw_bitmap(esquerdaD, posicaoX, posicaoY, 0);
			movimento = 0;
		}
		break;
	case 3:
		if (movimento >= 0 && movimento < 20) {
			al_draw_bitmap(direitaN, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento >= 20 && movimento < 40) {
			al_draw_bitmap(direitaE, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento == 40) {
			al_draw_bitmap(direitaD, posicaoX, posicaoY, 0);
			movimento = 0;
		}
		break;
	case 4:
		if (movimento >= 0 && movimento < 20) {
			al_draw_bitmap(baixoN, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento >= 20 && movimento < 40) {
			al_draw_bitmap(baixoE, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento == 40) {
			al_draw_bitmap(baixoD, posicaoX, posicaoY, 0);
			movimento = 0;
		}
	}
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
	al_destroy_timer(timer);
	al_destroy_event_queue(evento);
	al_destroy_display(display);

	//Audios e Musicas
	al_destroy_sample(audioMenu);

	//Menu
	al_destroy_bitmap(backgroundMenu);
	al_destroy_font(fonteMenu);

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

	//Introdução 2
	al_destroy_bitmap(fundoAgamenom);
	al_destroy_bitmap(fundoMenelau);

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
	al_destroy_bitmap(barra_vida_cheia);
	al_destroy_bitmap(barra_vida_baixa);
	al_destroy_bitmap(barra_vidaRei_100);
	al_destroy_bitmap(barra_vidaRei_50);
	al_destroy_bitmap(ParisBaixoDir);
	al_destroy_bitmap(ParisBaixoEsq);
	al_destroy_bitmap(ParisBaixoNormal);
	al_destroy_bitmap(ParisEsqDir);
	al_destroy_bitmap(ParisEsqEsq);
	al_destroy_bitmap(ParisEsqNormal);
	al_destroy_bitmap(ParisCimaDir);
	al_destroy_bitmap(ParisCimaEsq);
	al_destroy_bitmap(ParisCimaNormal);
	al_destroy_bitmap(ParisDirDir);
	al_destroy_bitmap(ParisDirEsq);
	al_destroy_bitmap(ParisDirNormal);
	al_destroy_bitmap(soldadosEsparta);

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
	printf("Destriudo");
}