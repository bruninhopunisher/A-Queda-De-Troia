#include "lib.h"

//Variaveis Globais
ALLEGRO_TIMER* timer; //Destruido
ALLEGRO_EVENT_QUEUE* evento; //Destruido
ALLEGRO_DISPLAY* display; // Destruido
ALLEGRO_BITMAP* backgroundMenu; //Destruido
ALLEGRO_BITMAP* logo; //Destruido
ALLEGRO_FONT* fonteMenu; //Destruido
ALLEGRO_FONT* font; // Destruido

bool iniciarConst = false;
int displayX;
int displayY;
int mouseX;
int mouseY;
int intro = 1;
int navegacao = 0;
int mouseAxesX;
int mouseAxesY;
bool rodando = true;
bool boolVolume = true;
efeitoDigitacao[4];

//Opções
ALLEGRO_BITMAP* backgroundOpcoes; //Destruido
ALLEGRO_BITMAP* comVolume; //Destruido
ALLEGRO_BITMAP* semVolume; //Destruido
ALLEGRO_BITMAP* comVolumeHover; //Destruido
ALLEGRO_BITMAP* semVolumeHover; //Destruido

//Creditos
char nomes[11][100] = {
	"A QUEDA DE TROIA",
	"OBRIGADO POR JOGAR!",
	"Esperamos que tenha aprendido algo nesta aventura e se divertido!",
	"DESENVOLVIDO POR",
	"BCC - TURMA A 2024",
	"Bruno",
	"Caua",
	"Keila",
	"Lucas Pinheiro",
	"Lucas Magalhaes",
	"Ate a proxima!"
};
int credY[11] = { 720, 800, 850, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1500 };
//Introdução 1
ALLEGRO_BITMAP* fundo1Intro1; //Destruido
ALLEGRO_BITMAP* fundo2Intro1; //Destruido
ALLEGRO_BITMAP* fundo3Intro1; //Destruido
ALLEGRO_BITMAP* fundoHelena; //Destruido
ALLEGRO_BITMAP* fundoParis; //Destruido
ALLEGRO_FONT* fonteIntro1; //Destruido
ALLEGRO_BITMAP* mapaAtenas; //Destruido
ALLEGRO_BITMAP* mapaTroia; //Destruido
ALLEGRO_BITMAP* mapaGrecia; //Destruido
bool renderizar = 0;

// Introdução 2
ALLEGRO_BITMAP * fundoAgamenom; //Destruido
ALLEGRO_BITMAP* fundoMenelau; //Destruido
ALLEGRO_BITMAP* fundoExplicacao;

//Introdução 3
ALLEGRO_BITMAP* pagina1; //Destruido
ALLEGRO_BITMAP* pagina2; //Destruido
ALLEGRO_BITMAP* pagina3; //Destruido
ALLEGRO_BITMAP* pagina4; //Destruido

//Introdução 4
ALLEGRO_BITMAP* pag1; //Destruido
ALLEGRO_BITMAP* pag2; //Destruido
ALLEGRO_BITMAP* pag3; //Destruido
ALLEGRO_BITMAP* pag4; //Destruido

//Telas finais
ALLEGRO_BITMAP* vitoria; //Destruido
ALLEGRO_BITMAP* derrota; //Destruido

//Fase 1
ALLEGRO_BITMAP* backgroundFaseUm; //Destruido
ALLEGRO_BITMAP* personagemHeitor; //Destruido
ALLEGRO_BITMAP* personagemHelena; //Destruido
ALLEGRO_BITMAP* frente_direito; //Destruido
ALLEGRO_BITMAP* frente_esquerdo; //Destruido
ALLEGRO_BITMAP* sprite_atual; //Destruido

int personagemParisX = 115;
int personagemParisY = 490;
int personagemHeitorX = 115;
int personagemHeitorY = 490;
int personagemHelenaX = 1150;
int personagemHelenaY = 585;
bool esta_movendo = false; // controlar o estado de movimento
int direcaoX = 0;    // Direção horizontal -1 = esquerda 1 = direita
int direcaoY = 0;    // Direção vertical -1 = cima, 1 = baixo
int contador_passos = 0;  // Contador para alternar entre os passos
int atraso_animacao = 0; // Controlar a velocidade da animação
int ultima_direcaoX = 0; // Última direção horizontal
int ultima_direcaoY = 0; // Última direção vertical

//Fase 2
//Personagem paris;
ALLEGRO_BITMAP* background_f2; //Destruido
ALLEGRO_BITMAP* espada_player1; //Destruido
ALLEGRO_BITMAP* espada_rei_f2; //Destruido
ALLEGRO_BITMAP* barra_vida_cheia; //Destruido
ALLEGRO_BITMAP* barra_vida_baixa; //Destruido
ALLEGRO_BITMAP* barra_vidaRei_100; //Destruido
ALLEGRO_BITMAP* barra_vidaRei_50; //Destruido
ALLEGRO_BITMAP* soldadosEsparta; //Destruido
ALLEGRO_BITMAP* soldadosTroia; //Destruido
int pressionado = 0;
int ultPressionado = 0;
int movimento = 0;
//HEITOR
int positionX1_heitor = 615;
int positionX2_heitor = 665;
int positionY1_heitor = 100;
int positionY2_heitor = 170;
//PARIS
ALLEGRO_BITMAP* ParisBaixoEsq; //Destruido
ALLEGRO_BITMAP* ParisBaixoDir; //Destruido
ALLEGRO_BITMAP* ParisBaixoNormal; //Destruido
ALLEGRO_BITMAP* ParisEsqDir; //Destruido
ALLEGRO_BITMAP* ParisEsqEsq; //Destruido
ALLEGRO_BITMAP* ParisEsqNormal; //Destruido
ALLEGRO_BITMAP* ParisCimaNormal; //Destruido
ALLEGRO_BITMAP* ParisCimaEsq; //Destruido
ALLEGRO_BITMAP* ParisCimaDir; //Destruido
ALLEGRO_BITMAP* ParisDirNormal; //Destruido
ALLEGRO_BITMAP* ParisDirEsq; //Destruido
ALLEGRO_BITMAP* ParisDirDir; //Destruido
ALLEGRO_BITMAP* ParisAtaqueB1; //Destruido
ALLEGRO_BITMAP* ParisAtaqueB2; //Destruido
ALLEGRO_BITMAP* ParisAtaqueB3; //Destruido
ALLEGRO_BITMAP* ParisAtaqueB4; //Destruido
int positionX1_f2 = 615;
int positionY1_f2 = 225;
int positionX_espada1 = 605;
int positionY_espada1 = 275;
int limiteAtaque = 0;
bool controleJogador = false;
bool atacando = false;
//REI MENELAU
ALLEGRO_BITMAP* MenelauEsqDirN; //Destruido
ALLEGRO_BITMAP* MenelauEsqDir1; //Destruido
ALLEGRO_BITMAP* MenelauEsqDir2; //Destruido
ALLEGRO_BITMAP* MenelauEsqDir3; //Destruido
ALLEGRO_BITMAP* MenelauCimaN; //Destruido
ALLEGRO_BITMAP* MenelauCima1; //Destruido
ALLEGRO_BITMAP* MenelauCima2; //Destruido
ALLEGRO_BITMAP* MenelauCima3; //Destruido
ALLEGRO_BITMAP* MenelauBaixoN; //Destruido
ALLEGRO_BITMAP* MenelauBaixo1; //Destruido
ALLEGRO_BITMAP* MenelauBaixo2; //Destruido
ALLEGRO_BITMAP* MenelauBaixo3; //Destruido
int positionReiX = 650;
int positionReiY = 450;
int vidaJogador = 100;
int movimentoRei = 0;
int ataqueReiTimer = 0;
int vidaReiX = 1200;
int pontoAndarX = 650;
int pontoAndarY = 450;

//Fase 3
ALLEGRO_BITMAP* imgPuzzle; //Destruido
ALLEGRO_BITMAP* imgFundoPuzzle; //Destruido
ALLEGRO_BITMAP* puzzle1; //Destruido
ALLEGRO_BITMAP* puzzle2; //Destruido
ALLEGRO_BITMAP* puzzle3; //Destruido
ALLEGRO_BITMAP* puzzle4; //Destruido
ALLEGRO_BITMAP* puzzle5; //Destruido
ALLEGRO_BITMAP* puzzle6; //Destruido
ALLEGRO_BITMAP* puzzle7; //Destruido
ALLEGRO_BITMAP* puzzle8; //Destruido
ALLEGRO_BITMAP* puzzle9; //Destruido
ALLEGRO_BITMAP* puzzle10; //Destruido
ALLEGRO_BITMAP* puzzle11; //Destruido
ALLEGRO_BITMAP* puzzle12; //Destruido
ALLEGRO_BITMAP* puzzle13; //Destruido
ALLEGRO_BITMAP* puzzle14; //Destruido
ALLEGRO_BITMAP* puzzle15; //Destruido
ALLEGRO_BITMAP* puzzle16; //Destruido
ALLEGRO_BITMAP* puzzle17; //Destruido
ALLEGRO_BITMAP* puzzle18; //Destruido
ALLEGRO_BITMAP* puzzle19; //Destruido
ALLEGRO_BITMAP* puzzle20; //Destruido
ALLEGRO_BITMAP* puzzle21; //Destruido
ALLEGRO_BITMAP* puzzle22; //Destruido
ALLEGRO_BITMAP* puzzle23; //Destruido
ALLEGRO_BITMAP* puzzle24; //Destruido
ALLEGRO_BITMAP* puzzle25; //Destruido
int contadorCreditos = 3;
bool verificaPuzzle = true;
int posicaoInicialX[25] = { 20, 20, 20, 20, 260, 140, 140, 140, 1030, 260, 1030, 140, 1150, 260, 1030, 1030, 1030, 1150, 1150, 1150, 1150, 20, 260, 260, 140 };
int posicaoInicialY[25] = { 20, 140, 260, 380, 20, 20, 140, 260, 20, 500, 500, 380, 20, 140, 140, 260, 380, 140, 260, 380, 500, 500, 260, 380, 500 };
int arrayVerificador[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
//int posicaoCorretaX[25] = { 365, 480, 710, 825, 325, 480, 595, 710, 825, 365, 480, 595, 710, 825, 365, 480, 595, 710, 825, 365, 480, 595, 710, 825 };
//int posicaoCorretaY[25] = { 70, 70, 70, 70, 185, 185, 185, 185, 185, 300, 300, 300, 300, 300, 415, 415, 415, 415, 415, 530, 530, 530, 530, 530 };
Puzzle pecasPuzzle;
Quadrante quadrantePuzzle;
PosicaoInicialStruct posicoesIniciais;
int swapX;
int swapY;
bool swapAtivo = false;
int idPeca;
int idPecaRetirada;
int idQuadrante;
int indice;
bool pecaSelecionada = false;
bool quadranteSelecionado = false;
bool first = false;
int marcacaoX;
int marcacaoY;
int somaVerificadora;
int guardaMovimentacao[26] = { 5745, 7854, 7581, 5404, 4540, 4540, 9980, 8845, 5408, 4804, 4878, 9870, 7487, 7854, 9804, 7870, 7874, 4548, 4840, 4540, 4570, 7874, 4960, 9807, 8707, 7087 };
int guardaIdPuzzle[26] = { 5745, 7854, 7581, 5404, 4540, 4540, 9980, 8845, 5408, 4804, 4878, 9870, 7487, 7854, 9804, 7870, 7874, 4548, 4840, 4540, 4570, 7874, 4960, 9807, 8707, 7087 };
int somaPosicao = 0;
int indiceQuadrante = 0;
int swapDaPeca;
int contg = 0;
bool next = false;
int nextInt = 0;

//Fase 04
//Background fase 4
ALLEGRO_BITMAP* backgroundFase04; //Destruido
//IMAGENS DO AQUILES - INICIO:
ALLEGRO_BITMAP* aquiles_Baixo; //Destruido
ALLEGRO_BITMAP* aquiles_Descendo_0; //Destruido
ALLEGRO_BITMAP* aquiles_Descendo_1; //Destruido
ALLEGRO_BITMAP* aquiles_Lado_0; //Destruido
ALLEGRO_BITMAP* aquiles_Lado_1; //Destruido
ALLEGRO_BITMAP* aquiles_Cima; //Destruido
ALLEGRO_BITMAP* aquiles_Subindo_0; //Destruido
ALLEGRO_BITMAP* aquiles_Subindo_1; //Destruido
ALLEGRO_BITMAP* aquiles_Atual; //NÃO PRECISA DESTRUIR
//IMAGENS DO AQUILES - FIM:
//IMAGENS DO LANCEIRO - INICIO:
ALLEGRO_BITMAP* Lanc_Lado_0; //Destruido
ALLEGRO_BITMAP* Lanc_Lado_1; //Destruido
ALLEGRO_BITMAP* Lanc_Atual[7]; //Não precisa destuir
//IMAGENS DO LANCEIRO - FIM:
//IMAGENS DOS ARQUEIROS - INICIO:
ALLEGRO_BITMAP* arq_Frente_1; //Destruido
ALLEGRO_BITMAP* arq_Frente_2; //Destruido
ALLEGRO_BITMAP* arq_Costas_1; //Destruido
ALLEGRO_BITMAP* arq_Costas_2; //Destruido
ALLEGRO_BITMAP* arq_Atual[32]; //Destruido
ALLEGRO_BITMAP* flecha; //Não precisa destuir
//IMAGENS DOS ARQUEIROS - FIM:
ALLEGRO_TIMER* timerFase04; //Destruido
int tempoRestante = 60; //Tempo da fase em segundos
bool timerOn = false;
bool gameOver = false;
int iniVel = 1; //Vel do inimigo
//player
int playX = 605; //Centro da tela
int playY = 325; //Centro da tela
int playZ = 0;
int PlayVel = 3; //Vel do player
int vidaF4 = 3; //QTD de vidas
int PlayPosicao = 0;
bool andando = false;
//inimigo de lança
int qtdLanc = 7;
int lancX[7] = { 0, 1210, 0, 1210, 0, 1210, 0 };
int lancY[7] = { 105, 185, 265, 345, 425, 505, 585 };
int lancZ[7] = { 0, 1, 0, 1, 0, 1, 0 };
int atraso_animacao_Lanc[7] = { 0, 0, 0, 0, 0, 0, 0 }; // Controlar a velocidade da animação
int contador_passos_Lanc[7] = { 0, 0, 0, 0, 0, 0, 0 };  // Contador para alternar entre os passos
//Arqueiros
int qtdArq = 32;
int arqX[32] = { 0, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400, 440, 480, 520, 560, 600, 640, 680, 
				720, 760, 800, 840, 880, 920, 960, 1000, 1040, 1080, 1120, 1160, 1200, 1240 };
int arqY[32] = { 45, 655, 45, 655, 45, 655, 45, 655, 45, 655, 45, 655, 45, 655, 45, 655,
				45, 655, 45, 655, 45, 655, 45, 655, 45, 655, 45, 655, 45, 655, 45, 655 };
int arqZ[32] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
int atraso_animacao_Arq[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // Controlar a velocidade da animação
int contador_passos_Arq[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // Contador para alternar entre os passos
bool atirando_Arq[32] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
					false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };


//Flecha
int qtdFle = 32;
int fleX[32] = { 20, 60, 100, 140, 180, 220, 260, 300, 340, 380, 420, 460, 500, 540, 580, 620, 660, 700, 740, 780, 820, 860, 900, 940, 980, 1020, 1060, 1100, 1140, 1180, 1220, 1260 };
int fleY[32] = { 70, 670, 70, 670, 70, 670, 70, 670, 70, 670, 70, 670, 70, 670, 70, 670, 70, 670, 70, 670,
				70, 670, 70, 670, 70, 670, 70, 670, 70, 670, 70, 670 };
int fleZ[32] = { 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2 };
//Fim Fase 04
//Audios e Musicas
ALLEGRO_SAMPLE* audioMenu; //Destruido

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
	srand(time(NULL));

	testeInicializar(timer, "timer");
	testeInicializar(evento, "evento");

	//Fonte
	fonteMenu = al_load_font("Fontes/MedievalSharp-Bold.ttf", 35, ALLEGRO_ALIGN_CENTRE);
	testeInicializar(fonteMenu, "fonteMenu");
	font = al_load_ttf_font("Fontes/MateSC-Regular.ttf", 35, 0);

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
	logo = al_load_bitmap("Imagens/Menu/logo.png");

	//Introdução 1
	fundo1Intro1 = al_load_bitmap("Imagens/Introducao_1/fundo1Intro1.jpg");
	fundo2Intro1 = al_load_bitmap("Imagens/Introducao_1/fundo2Intro1.jpg");
	fundo3Intro1 = al_load_bitmap("Imagens/Introducao_1/fundo3Intro1.jpg");
	fundoHelena = al_load_bitmap("Imagens/Introducao_1/helenaIntro1.jpg");
	fundoParis = al_load_bitmap("Imagens/Introducao_1/ParisIntro1.jpg");
	fonteIntro1 = al_load_font("Fontes/MateSC-Regular.ttf", 45, 0);
	mapaAtenas = al_load_bitmap("Imagens/Introducao_1/mapa_atenas.png");
	mapaTroia = al_load_bitmap("Imagens/Introducao_1/mapa_troia.png");
	mapaGrecia = al_load_bitmap("Imagens/Introducao_1/mapa_grecia.png");

	testeInicializar(fundo1Intro1, "fundo_1_intro1");
	testeInicializar(fundo2Intro1, "fundo_2_intro1");
	testeInicializar(fundo3Intro1, "fundo_3_intro1");
	testeInicializar(fonteIntro1, "fonte_intro_1");
	testeInicializar(fundoHelena, "fundo_helena-Intro1");
	testeInicializar(fundoParis, "fundo_paris_Intro1");
	testeInicializar(mapaAtenas, "mapaAtenas");
	testeInicializar(mapaTroia, "mapaTroia");
	testeInicializar(mapaGrecia, "mapaGrecia");

	//Introdução 2
	fundoAgamenom = al_load_bitmap("Imagens/Introducao_2/fundoAgamenom.jpg");
	fundoMenelau = al_load_bitmap("Imagens/Introducao_2/fundoMenelau.jpg");
	fundoExplicacao = al_load_bitmap("Imagens/Introducao_2/fundoExplicacao.jpg");

	testeInicializar(fundoAgamenom, "fundo-agamenom-Intro2");
	testeInicializar(fundoMenelau, "fundo-menelau-Intro2");
	testeInicializar(fundoExplicacao, "fundo-explicacao-Intro2");

	//Introdução 3
	pagina1 = al_load_bitmap("Imagens/Introducao_3/pagina1.jpg");
	pagina2 = al_load_bitmap("Imagens/Introducao_3/pagina2.jpg");
	pagina3 = al_load_bitmap("Imagens/Introducao_3/pagina3.jpg");
	pagina4 = al_load_bitmap("Imagens/Introducao_3/pagina4.jpg");

	testeInicializar(pagina1, "pagian-1-Intro3");
	testeInicializar(pagina2, "pagian-2-Intro3");
	testeInicializar(pagina3, "pagian-3-Intro3");
	testeInicializar(pagina4, "pagian-4-Intro3");

	//Introdução 4
	pag1 = al_load_bitmap("Imagens/Introducao_4/pag1.jpg");
	pag2 = al_load_bitmap("Imagens/Introducao_4/pag2.jpg");
	pag3 = al_load_bitmap("Imagens/Introducao_4/pag3.jpg");
	pag4 = al_load_bitmap("Imagens/Introducao_4/pag4.jpg");

	testeInicializar(pagina1, "pag-1-Intro4");
	testeInicializar(pagina2, "pag-2-Intro4");
	testeInicializar(pagina3, "pag-3-Intro4");
	testeInicializar(pagina4, "pag-4-Intro4");

	//telas finais
	vitoria = al_load_bitmap("Imagens/Final/vitoria.jpg");
	derrota = al_load_bitmap("Imagens/Final/derrota.jpg");

	testeInicializar(vitoria, "vitoria");
	testeInicializar(derrota, "derrota");

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
	sprite_atual = NULL;

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
	soldadosTroia = al_load_bitmap("Imagens/Fase_02/soldadosTroia.jpg");
	ParisAtaqueB1 = al_load_bitmap("Imagens/Fase_02/ataquebaixo1.jpg");
	ParisAtaqueB2 = al_load_bitmap("Imagens/Fase_02/ataquebaixo2.jpg");
	ParisAtaqueB3 = al_load_bitmap("Imagens/Fase_02/ataquebaixo3.jpg");
	ParisAtaqueB4 = al_load_bitmap("Imagens/Fase_02/ataquebaixo4.jpg");
	MenelauCimaN = al_load_bitmap("Imagens/Fase_02/MenelauCimaN.jpg");
	MenelauCima1 = al_load_bitmap("Imagens/Fase_02/MenelauCima1.jpg");
	MenelauCima2 = al_load_bitmap("Imagens/Fase_02/MenelauCima2.jpg");
	MenelauCima3 = al_load_bitmap("Imagens/Fase_02/MenelauCima3.jpg");
	MenelauEsqDirN = al_load_bitmap("Imagens/Fase_02/MenelauEsqN.jpg");
	MenelauEsqDir1 = al_load_bitmap("Imagens/Fase_02/MenelauEsqDir1.jpg");
	MenelauEsqDir2 = al_load_bitmap("Imagens/Fase_02/MenelauEsqDir2.jpg");
	MenelauEsqDir3 = al_load_bitmap("Imagens/Fase_02/MenelauEsqDir3.jpg");
	MenelauBaixoN = al_load_bitmap("Imagens/Fase_02/MenelauBaixoN.jpg");
	MenelauBaixo1 = al_load_bitmap("Imagens/Fase_02/MenelauBaixo1.jpg");
	MenelauBaixo2 = al_load_bitmap("Imagens/Fase_02/MenelauBaixo2.jpg");
	MenelauBaixo3 = al_load_bitmap("Imagens/Fase_02/MenelauBaixo3.jpg");

	testeInicializar(MenelauCimaN, "menelau_cima_n");
	testeInicializar(MenelauCima1, "menelau_cima_1");
	testeInicializar(MenelauCima2, "menelau_cima_2");
	testeInicializar(MenelauCima3, "menelau_cima_3");
	testeInicializar(MenelauBaixoN, "menelau_baixo_n");
	testeInicializar(MenelauBaixo1, "menelau_baixo_1");
	testeInicializar(MenelauBaixo2, "menelau_baixo_2");
	testeInicializar(MenelauBaixo3, "menelau_baixo_3");
	testeInicializar(MenelauEsqDirN, "menelau_esq_dir_n");
	testeInicializar(MenelauEsqDir1, "menelau_esq_dir_1");
	testeInicializar(MenelauEsqDir2, "menelau_esq_dir_2");
	testeInicializar(MenelauEsqDir3, "menelau_esq_dir_3");
	testeInicializar(soldadosTroia, "soldados_troia");
	testeInicializar(ParisAtaqueB1, "ataque_paris_b1");
	testeInicializar(ParisAtaqueB2, "ataque_paris_b2");
	testeInicializar(ParisAtaqueB3, "ataque_paris_b3");
	testeInicializar(ParisAtaqueB4, "ataque_paris_b4");
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

	posicoesIniciais.posicoes[0].id = 1;
	posicoesIniciais.posicoes[0].x = 20;
	posicoesIniciais.posicoes[0].y = 20;
	posicoesIniciais.posicoes[0].contemPeca = true;

	posicoesIniciais.posicoes[1].id = 2;
	posicoesIniciais.posicoes[1].x = 20;
	posicoesIniciais.posicoes[1].y = 140;
	posicoesIniciais.posicoes[1].contemPeca = true;

	posicoesIniciais.posicoes[2].id = 3;
	posicoesIniciais.posicoes[2].x = 20;
	posicoesIniciais.posicoes[2].y = 260;
	posicoesIniciais.posicoes[2].contemPeca = true;

	posicoesIniciais.posicoes[3].id = 4;
	posicoesIniciais.posicoes[3].x = 20;
	posicoesIniciais.posicoes[3].y = 380;
	posicoesIniciais.posicoes[3].contemPeca = true;

	posicoesIniciais.posicoes[4].id = 5;
	posicoesIniciais.posicoes[4].x = 260;
	posicoesIniciais.posicoes[4].y = 20;
	posicoesIniciais.posicoes[4].contemPeca = true;

	posicoesIniciais.posicoes[5].id = 6;
	posicoesIniciais.posicoes[5].x = 140;
	posicoesIniciais.posicoes[5].y = 20;
	posicoesIniciais.posicoes[5].contemPeca = true;

	posicoesIniciais.posicoes[6].id = 7;
	posicoesIniciais.posicoes[6].x = 140;
	posicoesIniciais.posicoes[6].y = 140;
	posicoesIniciais.posicoes[6].contemPeca = true;

	posicoesIniciais.posicoes[7].id = 8;
	posicoesIniciais.posicoes[7].x = 140;
	posicoesIniciais.posicoes[7].y = 260;
	posicoesIniciais.posicoes[7].contemPeca = true;

	posicoesIniciais.posicoes[8].id = 9;
	posicoesIniciais.posicoes[8].x = 1150;
	posicoesIniciais.posicoes[8].y = 20;
	posicoesIniciais.posicoes[8].contemPeca = true;

	posicoesIniciais.posicoes[9].id = 10;
	posicoesIniciais.posicoes[9].x = 260;
	posicoesIniciais.posicoes[9].y = 500;
	posicoesIniciais.posicoes[9].contemPeca = true;

	posicoesIniciais.posicoes[10].id = 11;
	posicoesIniciais.posicoes[10].x = 1030;
	posicoesIniciais.posicoes[10].y = 500;
	posicoesIniciais.posicoes[10].contemPeca = true;

	posicoesIniciais.posicoes[11].id = 12;
	posicoesIniciais.posicoes[11].x = 140;
	posicoesIniciais.posicoes[11].y = 380;
	posicoesIniciais.posicoes[11].contemPeca = true;

	posicoesIniciais.posicoes[12].id = 13;
	posicoesIniciais.posicoes[12].x = 1030;
	posicoesIniciais.posicoes[12].y = 20;
	posicoesIniciais.posicoes[12].contemPeca = true;

	posicoesIniciais.posicoes[13].id = 14;
	posicoesIniciais.posicoes[13].x = 260;
	posicoesIniciais.posicoes[13].y = 140;
	posicoesIniciais.posicoes[13].contemPeca = true;

	posicoesIniciais.posicoes[14].id = 15;
	posicoesIniciais.posicoes[14].x = 1030;
	posicoesIniciais.posicoes[14].y = 140;
	posicoesIniciais.posicoes[14].contemPeca = true;

	posicoesIniciais.posicoes[15].id = 16;
	posicoesIniciais.posicoes[15].x = 1030;
	posicoesIniciais.posicoes[15].y = 260;
	posicoesIniciais.posicoes[15].contemPeca = true;

	posicoesIniciais.posicoes[16].id = 17;
	posicoesIniciais.posicoes[16].x = 1030;
	posicoesIniciais.posicoes[16].y = 380;
	posicoesIniciais.posicoes[16].contemPeca = true;

	posicoesIniciais.posicoes[17].id = 18;
	posicoesIniciais.posicoes[17].x = 1150;
	posicoesIniciais.posicoes[17].y = 140;
	posicoesIniciais.posicoes[17].contemPeca = true;

	posicoesIniciais.posicoes[18].id = 19;
	posicoesIniciais.posicoes[18].x = 1150;
	posicoesIniciais.posicoes[18].y = 260;
	posicoesIniciais.posicoes[18].contemPeca = true;

	posicoesIniciais.posicoes[19].id = 20;
	posicoesIniciais.posicoes[19].x = 1150;
	posicoesIniciais.posicoes[19].y = 380;
	posicoesIniciais.posicoes[19].contemPeca = true;

	posicoesIniciais.posicoes[20].id = 21;
	posicoesIniciais.posicoes[20].x = 1150;
	posicoesIniciais.posicoes[20].y = 500;
	posicoesIniciais.posicoes[20].contemPeca = true;

	posicoesIniciais.posicoes[21].id = 22;
	posicoesIniciais.posicoes[21].x = 20;
	posicoesIniciais.posicoes[21].y = 500;
	posicoesIniciais.posicoes[21].contemPeca = true;

	posicoesIniciais.posicoes[22].id = 23;
	posicoesIniciais.posicoes[22].x = 260;
	posicoesIniciais.posicoes[22].y = 260;
	posicoesIniciais.posicoes[22].contemPeca = true;

	posicoesIniciais.posicoes[23].id = 24;
	posicoesIniciais.posicoes[23].x = 260;
	posicoesIniciais.posicoes[23].y = 380;
	posicoesIniciais.posicoes[23].contemPeca = true;

	posicoesIniciais.posicoes[24].id = 25;
	posicoesIniciais.posicoes[24].x = 140;
	posicoesIniciais.posicoes[24].y = 500;
	posicoesIniciais.posicoes[24].contemPeca = true;

	pecasPuzzle.pecas[0].id = 1;
	pecasPuzzle.pecas[0].pos_inicial_x = 20;
	pecasPuzzle.pecas[0].pos_inicial_y = 20;
	pecasPuzzle.pecas[0].pos_atual_x = 20;
	pecasPuzzle.pecas[0].pos_atual_y = 20;
	pecasPuzzle.pecas[0].selecionada = false;

	pecasPuzzle.pecas[1].id = 2;
	pecasPuzzle.pecas[1].pos_inicial_x = 20;
	pecasPuzzle.pecas[1].pos_inicial_y = 140;
	pecasPuzzle.pecas[1].pos_atual_x = 20;
	pecasPuzzle.pecas[1].pos_atual_y = 140;
	pecasPuzzle.pecas[1].selecionada = false;

	pecasPuzzle.pecas[2].id = 3;
	pecasPuzzle.pecas[2].pos_inicial_x = 20;
	pecasPuzzle.pecas[2].pos_inicial_y = 260;
	pecasPuzzle.pecas[2].pos_atual_x = 20;
	pecasPuzzle.pecas[2].pos_atual_y = 260;
	pecasPuzzle.pecas[2].selecionada = false;

	pecasPuzzle.pecas[3].id = 4;
	pecasPuzzle.pecas[3].pos_inicial_x = 20;
	pecasPuzzle.pecas[3].pos_inicial_y = 380;
	pecasPuzzle.pecas[3].pos_atual_x = 20;
	pecasPuzzle.pecas[3].pos_atual_y = 380;
	pecasPuzzle.pecas[3].selecionada = false;

	pecasPuzzle.pecas[4].id = 5;
	pecasPuzzle.pecas[4].pos_inicial_x = 260;
	pecasPuzzle.pecas[4].pos_inicial_y = 20;
	pecasPuzzle.pecas[4].pos_atual_x = 260;
	pecasPuzzle.pecas[4].pos_atual_y = 20;
	pecasPuzzle.pecas[4].selecionada = false;

	pecasPuzzle.pecas[5].id = 6;
	pecasPuzzle.pecas[5].pos_inicial_x = 140;
	pecasPuzzle.pecas[5].pos_inicial_y = 20;
	pecasPuzzle.pecas[5].pos_atual_x = 140;
	pecasPuzzle.pecas[5].pos_atual_y = 20;
	pecasPuzzle.pecas[5].selecionada = false;

	pecasPuzzle.pecas[6].id = 7;
	pecasPuzzle.pecas[6].pos_inicial_x = 140;
	pecasPuzzle.pecas[6].pos_inicial_y = 140;
	pecasPuzzle.pecas[6].pos_atual_x = 140;
	pecasPuzzle.pecas[6].pos_atual_y = 140;
	pecasPuzzle.pecas[6].selecionada = false;

	pecasPuzzle.pecas[7].id = 8;
	pecasPuzzle.pecas[7].pos_inicial_x = 140;
	pecasPuzzle.pecas[7].pos_inicial_y = 260;
	pecasPuzzle.pecas[7].pos_atual_x = 140;
	pecasPuzzle.pecas[7].pos_atual_y = 260;
	pecasPuzzle.pecas[7].selecionada = false;

	pecasPuzzle.pecas[8].id = 9;
	pecasPuzzle.pecas[8].pos_inicial_x = 1150;
	pecasPuzzle.pecas[8].pos_inicial_y = 20;
	pecasPuzzle.pecas[8].pos_atual_x = 1150;
	pecasPuzzle.pecas[8].pos_atual_y = 20;
	pecasPuzzle.pecas[8].selecionada = false;

	pecasPuzzle.pecas[9].id = 10;
	pecasPuzzle.pecas[9].pos_inicial_x = 260;
	pecasPuzzle.pecas[9].pos_inicial_y = 500;
	pecasPuzzle.pecas[9].pos_atual_x = 260;
	pecasPuzzle.pecas[9].pos_atual_y = 500;
	pecasPuzzle.pecas[9].selecionada = false;

	pecasPuzzle.pecas[10].id = 11;
	pecasPuzzle.pecas[10].pos_inicial_x = 1030;
	pecasPuzzle.pecas[10].pos_inicial_y = 500;
	pecasPuzzle.pecas[10].pos_atual_x = 1030;
	pecasPuzzle.pecas[10].pos_atual_y = 500;
	pecasPuzzle.pecas[10].selecionada = false;

	pecasPuzzle.pecas[11].id = 12;
	pecasPuzzle.pecas[11].pos_inicial_x = 140;
	pecasPuzzle.pecas[11].pos_inicial_y = 380;
	pecasPuzzle.pecas[11].pos_atual_x = 140;
	pecasPuzzle.pecas[11].pos_atual_y = 380;
	pecasPuzzle.pecas[11].selecionada = false;

	pecasPuzzle.pecas[12].id = 13;
	pecasPuzzle.pecas[12].pos_inicial_x = 1030;
	pecasPuzzle.pecas[12].pos_inicial_y = 20;
	pecasPuzzle.pecas[12].pos_atual_x = 1030;
	pecasPuzzle.pecas[12].pos_atual_y = 20;
	pecasPuzzle.pecas[12].selecionada = false;

	pecasPuzzle.pecas[13].id = 14;
	pecasPuzzle.pecas[13].pos_inicial_x = 260;
	pecasPuzzle.pecas[13].pos_inicial_y = 140;
	pecasPuzzle.pecas[13].pos_atual_x = 260;
	pecasPuzzle.pecas[13].pos_atual_y = 140;
	pecasPuzzle.pecas[13].selecionada = false;

	pecasPuzzle.pecas[14].id = 15;
	pecasPuzzle.pecas[14].pos_inicial_x = 1030;
	pecasPuzzle.pecas[14].pos_inicial_y = 140;
	pecasPuzzle.pecas[14].pos_atual_x = 1030;
	pecasPuzzle.pecas[14].pos_atual_y = 140;
	pecasPuzzle.pecas[14].selecionada = false;

	pecasPuzzle.pecas[15].id = 16;
	pecasPuzzle.pecas[15].pos_inicial_x = 1030;
	pecasPuzzle.pecas[15].pos_inicial_y = 260;
	pecasPuzzle.pecas[15].pos_atual_x = 1030;
	pecasPuzzle.pecas[15].pos_atual_y = 260;
	pecasPuzzle.pecas[15].selecionada = false;

	pecasPuzzle.pecas[16].id = 17;
	pecasPuzzle.pecas[16].pos_inicial_x = 1030;
	pecasPuzzle.pecas[16].pos_inicial_y = 380;
	pecasPuzzle.pecas[16].pos_atual_x = 1030;
	pecasPuzzle.pecas[16].pos_atual_y = 380;
	pecasPuzzle.pecas[16].selecionada = false;

	pecasPuzzle.pecas[17].id = 18;
	pecasPuzzle.pecas[17].pos_inicial_x = 1150;
	pecasPuzzle.pecas[17].pos_inicial_y = 140;
	pecasPuzzle.pecas[17].pos_atual_x = 1150;
	pecasPuzzle.pecas[17].pos_atual_y = 140;
	pecasPuzzle.pecas[17].selecionada = false;

	pecasPuzzle.pecas[18].id = 19;
	pecasPuzzle.pecas[18].pos_inicial_x = 1150;
	pecasPuzzle.pecas[18].pos_inicial_y = 260;
	pecasPuzzle.pecas[18].pos_atual_x = 1150;
	pecasPuzzle.pecas[18].pos_atual_y = 260;
	pecasPuzzle.pecas[18].selecionada = false;

	pecasPuzzle.pecas[19].id = 20;
	pecasPuzzle.pecas[19].pos_inicial_x = 1150;
	pecasPuzzle.pecas[19].pos_inicial_y = 380;
	pecasPuzzle.pecas[19].pos_atual_x = 1150;
	pecasPuzzle.pecas[19].pos_atual_y = 380;
	pecasPuzzle.pecas[19].selecionada = false;

	pecasPuzzle.pecas[20].id = 21;
	pecasPuzzle.pecas[20].pos_inicial_x = 1150;
	pecasPuzzle.pecas[20].pos_inicial_y = 500;
	pecasPuzzle.pecas[20].pos_atual_x = 1150;
	pecasPuzzle.pecas[20].pos_atual_y = 500;
	pecasPuzzle.pecas[20].selecionada = false;

	pecasPuzzle.pecas[21].id = 22;
	pecasPuzzle.pecas[21].pos_inicial_x = 20;
	pecasPuzzle.pecas[21].pos_inicial_y = 500;
	pecasPuzzle.pecas[21].pos_atual_x = 20;
	pecasPuzzle.pecas[21].pos_atual_y = 500;
	pecasPuzzle.pecas[21].selecionada = false;

	pecasPuzzle.pecas[22].id = 23;
	pecasPuzzle.pecas[22].pos_inicial_x = 260;
	pecasPuzzle.pecas[22].pos_inicial_y = 260;
	pecasPuzzle.pecas[22].pos_atual_x = 260;
	pecasPuzzle.pecas[22].pos_atual_y = 260;
	pecasPuzzle.pecas[22].selecionada = false;

	pecasPuzzle.pecas[23].id = 24;
	pecasPuzzle.pecas[23].pos_inicial_x = 260;
	pecasPuzzle.pecas[23].pos_inicial_y = 380;
	pecasPuzzle.pecas[23].pos_atual_x = 260;
	pecasPuzzle.pecas[23].pos_atual_y = 380;
	pecasPuzzle.pecas[23].selecionada = false;

	pecasPuzzle.pecas[24].id = 25;
	pecasPuzzle.pecas[24].pos_inicial_x = 140;
	pecasPuzzle.pecas[24].pos_inicial_y = 500;
	pecasPuzzle.pecas[24].pos_atual_x = 140;
	pecasPuzzle.pecas[24].pos_atual_y = 500;
	pecasPuzzle.pecas[24].selecionada = false;

	quadrantePuzzle.quadrantes[0].id = 1;
	quadrantePuzzle.quadrantes[0].X = 415;
	quadrantePuzzle.quadrantes[0].Y = 70;
	quadrantePuzzle.quadrantes[0].contemPeca = false;

	quadrantePuzzle.quadrantes[1].id = 2;
	quadrantePuzzle.quadrantes[1].X = 530;
	quadrantePuzzle.quadrantes[1].Y = 70;
	quadrantePuzzle.quadrantes[1].contemPeca = false;

	quadrantePuzzle.quadrantes[2].id = 3;
	quadrantePuzzle.quadrantes[2].X = 645;
	quadrantePuzzle.quadrantes[2].Y = 70;
	quadrantePuzzle.quadrantes[2].contemPeca = false;

	quadrantePuzzle.quadrantes[3].id = 4;
	quadrantePuzzle.quadrantes[3].X = 760;
	quadrantePuzzle.quadrantes[3].Y = 70;
	quadrantePuzzle.quadrantes[3].contemPeca = false;

	quadrantePuzzle.quadrantes[4].id = 5;
	quadrantePuzzle.quadrantes[4].X = 875;
	quadrantePuzzle.quadrantes[4].Y = 70;
	quadrantePuzzle.quadrantes[4].contemPeca = false;

	quadrantePuzzle.quadrantes[5].id = 6;
	quadrantePuzzle.quadrantes[5].X = 415;
	quadrantePuzzle.quadrantes[5].Y = 185;
	quadrantePuzzle.quadrantes[5].contemPeca = false;

	quadrantePuzzle.quadrantes[6].id = 7;
	quadrantePuzzle.quadrantes[6].X = 530;
	quadrantePuzzle.quadrantes[6].Y = 185;
	quadrantePuzzle.quadrantes[6].contemPeca = false;

	quadrantePuzzle.quadrantes[7].id = 8;
	quadrantePuzzle.quadrantes[7].X = 645;
	quadrantePuzzle.quadrantes[7].Y = 185;
	quadrantePuzzle.quadrantes[7].contemPeca = false;

	quadrantePuzzle.quadrantes[8].id = 9;
	quadrantePuzzle.quadrantes[8].X = 760;
	quadrantePuzzle.quadrantes[8].Y = 185;
	quadrantePuzzle.quadrantes[8].contemPeca = false;

	quadrantePuzzle.quadrantes[9].id = 10;
	quadrantePuzzle.quadrantes[9].X = 875;
	quadrantePuzzle.quadrantes[9].Y = 185;
	quadrantePuzzle.quadrantes[9].contemPeca = false;

	quadrantePuzzle.quadrantes[10].id = 11;
	quadrantePuzzle.quadrantes[10].X = 415;
	quadrantePuzzle.quadrantes[10].Y = 300;
	quadrantePuzzle.quadrantes[10].contemPeca = false;

	quadrantePuzzle.quadrantes[11].id = 12;
	quadrantePuzzle.quadrantes[11].X = 530;
	quadrantePuzzle.quadrantes[11].Y = 300;
	quadrantePuzzle.quadrantes[11].contemPeca = false;

	quadrantePuzzle.quadrantes[12].id = 13;
	quadrantePuzzle.quadrantes[12].X = 645;
	quadrantePuzzle.quadrantes[12].Y = 300;
	quadrantePuzzle.quadrantes[12].contemPeca = false;

	quadrantePuzzle.quadrantes[13].id = 14;
	quadrantePuzzle.quadrantes[13].X = 760;
	quadrantePuzzle.quadrantes[13].Y = 300;
	quadrantePuzzle.quadrantes[13].contemPeca = false;

	quadrantePuzzle.quadrantes[14].id = 15;
	quadrantePuzzle.quadrantes[14].X = 875;
	quadrantePuzzle.quadrantes[14].Y = 300;
	quadrantePuzzle.quadrantes[14].contemPeca = false;

	quadrantePuzzle.quadrantes[15].id = 16;
	quadrantePuzzle.quadrantes[15].X = 415;
	quadrantePuzzle.quadrantes[15].Y = 415;
	quadrantePuzzle.quadrantes[15].contemPeca = false;

	quadrantePuzzle.quadrantes[16].id = 17;
	quadrantePuzzle.quadrantes[16].X = 530;
	quadrantePuzzle.quadrantes[16].Y = 415;
	quadrantePuzzle.quadrantes[16].contemPeca = false;

	quadrantePuzzle.quadrantes[17].id = 18;
	quadrantePuzzle.quadrantes[17].X = 645;
	quadrantePuzzle.quadrantes[17].Y = 415;
	quadrantePuzzle.quadrantes[17].contemPeca = false;

	quadrantePuzzle.quadrantes[18].id = 19;
	quadrantePuzzle.quadrantes[18].X = 760;
	quadrantePuzzle.quadrantes[18].Y = 415;
	quadrantePuzzle.quadrantes[18].contemPeca = false;

	quadrantePuzzle.quadrantes[19].id = 20;
	quadrantePuzzle.quadrantes[19].X = 875;
	quadrantePuzzle.quadrantes[19].Y = 415;
	quadrantePuzzle.quadrantes[19].contemPeca = false;

	quadrantePuzzle.quadrantes[20].id = 21;
	quadrantePuzzle.quadrantes[20].X = 415;
	quadrantePuzzle.quadrantes[20].Y = 530;
	quadrantePuzzle.quadrantes[20].contemPeca = false;

	quadrantePuzzle.quadrantes[21].id = 22;
	quadrantePuzzle.quadrantes[21].X = 530;
	quadrantePuzzle.quadrantes[21].Y = 530;
	quadrantePuzzle.quadrantes[21].contemPeca = false;
	
	quadrantePuzzle.quadrantes[22].id = 23;
	quadrantePuzzle.quadrantes[22].X = 645;
	quadrantePuzzle.quadrantes[22].Y = 530;
	quadrantePuzzle.quadrantes[22].contemPeca = false;

	quadrantePuzzle.quadrantes[23].id = 24;
	quadrantePuzzle.quadrantes[23].X = 760;
	quadrantePuzzle.quadrantes[23].Y = 530;
	quadrantePuzzle.quadrantes[23].contemPeca = false;

	quadrantePuzzle.quadrantes[24].id = 25;
	quadrantePuzzle.quadrantes[24].X = 875;
	quadrantePuzzle.quadrantes[24].Y = 530;
	quadrantePuzzle.quadrantes[24].contemPeca = false;

	//fase 4
	timerFase04 = al_create_timer(1.0); //Timer da fase4
	backgroundFase04 = al_load_bitmap("Imagens/Fase_04/Background/backgroundF4.png");
	aquiles_Baixo = al_load_bitmap("Imagens/Fase_04/Aquiles/baixo.png");
	aquiles_Descendo_0 = al_load_bitmap("Imagens/Fase_04/Aquiles/frente_descendo0.png");
	aquiles_Descendo_1 = al_load_bitmap("Imagens/Fase_04/Aquiles/frente_descendo1.png");
	aquiles_Lado_0 = al_load_bitmap("Imagens/Fase_04/Aquiles/lado_0.png");
	aquiles_Lado_1 = al_load_bitmap("Imagens/Fase_04/Aquiles/lado_1.png");
	aquiles_Subindo_0 = al_load_bitmap("Imagens/Fase_04/Aquiles/subindo0.png");
	aquiles_Subindo_1 = al_load_bitmap("Imagens/Fase_04/Aquiles/subindo1.png");
	aquiles_Cima = al_load_bitmap("Imagens/Fase_04/Aquiles/cima.png");
	aquiles_Atual = NULL;
	Lanc_Lado_0 = al_load_bitmap("Imagens/Fase_04/Lanceiro/Lanc_Lado_0.png");
	Lanc_Lado_1 = al_load_bitmap("Imagens/Fase_04/Lanceiro/Lanc_Lado_1.png");
	Lanc_Atual[0] = NULL;
	Lanc_Atual[1] = NULL;
	Lanc_Atual[2] = NULL;
	Lanc_Atual[3] = NULL;
	Lanc_Atual[4] = NULL;
	Lanc_Atual[5] = NULL;
	Lanc_Atual[6] = NULL;
	arq_Frente_1 = al_load_bitmap("Imagens/Fase_04/Arqueiro/arqueiro_Frente_1.png");
	arq_Frente_2 = al_load_bitmap("Imagens/Fase_04/Arqueiro/arqueiro_Frente_2.png");
	arq_Costas_1 = al_load_bitmap("Imagens/Fase_04/Arqueiro/arqueiro_Costas_1.png");
	arq_Costas_2 = al_load_bitmap("Imagens/Fase_04/Arqueiro/arqueiro_Costas_2.png");
	arq_Atual[0] = NULL;
	arq_Atual[1] = NULL;
	arq_Atual[2] = NULL;
	arq_Atual[3] = NULL;
	arq_Atual[4] = NULL;
	arq_Atual[5] = NULL;
	arq_Atual[6] = NULL;
	arq_Atual[7] = NULL;
	arq_Atual[8] = NULL;
	arq_Atual[9] = NULL;
	arq_Atual[10] = NULL;
	arq_Atual[11] = NULL;
	arq_Atual[12] = NULL;
	arq_Atual[13] = NULL;
	arq_Atual[14] = NULL;
	arq_Atual[15] = NULL;
	arq_Atual[16] = NULL;
	arq_Atual[17] = NULL;
	arq_Atual[18] = NULL;
	arq_Atual[19] = NULL;
	arq_Atual[20] = NULL;
	arq_Atual[21] = NULL;
	arq_Atual[22] = NULL;
	arq_Atual[23] = NULL;
	arq_Atual[24] = NULL;
	arq_Atual[25] = NULL;
	arq_Atual[26] = NULL;
	arq_Atual[27] = NULL;
	arq_Atual[28] = NULL;
	arq_Atual[29] = NULL;
	arq_Atual[30] = NULL;
	arq_Atual[31] = NULL;
	flecha = al_load_bitmap("Imagens/Fase_04/Arqueiro/flecha.png");
	testeInicializar(backgroundFase04, "backgroundF4");
	testeInicializar(aquiles_Baixo, "aquilesBaixo");
	testeInicializar(aquiles_Descendo_0, "frente_descendo0");
	testeInicializar(aquiles_Descendo_1, "frente_descendo1");
	testeInicializar(aquiles_Lado_0, "aquiles_Lado_0");
	testeInicializar(aquiles_Lado_1, "aquiles_Lado_1");
	testeInicializar(aquiles_Cima, "aquilesCima");
	testeInicializar(aquiles_Subindo_0, "subindo0");
	testeInicializar(aquiles_Subindo_1, "subindo1");
	testeInicializar(Lanc_Lado_0, "Lanc_Lado_0");
	testeInicializar(Lanc_Lado_1, "Lanc_Lado_1");
	testeInicializar(arq_Frente_1, "arq_Frente_1");
	testeInicializar(arq_Frente_2, "arq_Frente_2");
	testeInicializar(arq_Costas_1, "arq_Costas_1");
	testeInicializar(arq_Costas_2, "arq_Costas_2");
	testeInicializar(flecha, "flecha");
}


void movimentarPlayer(ALLEGRO_EVENT evento, int* posicaoX, int* posicaoY) {

	//VERIFICA QUAL TECLA PRESSIONOU

	switch (evento.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
			if (atacando == false) {
				pressionado = 1;
			}
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
			if (atacando == false) {
				pressionado = 2;
			}
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
			if (atacando == false) {
				pressionado = 3;
			}
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			if (atacando == false) {
				pressionado = 4;
			}
		}
		if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE) {
			if (atacando == false) {
				pressionado = 5;
			}
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
		if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE) {
			ultPressionado = 5;
		}
		if (pressionado == ultPressionado && ultPressionado != 5) {
			pressionado = 0;
			ultPressionado = 0;
		}
	}

	//MOVIMENTAÇÃO DO JOGADOR

	switch (pressionado)
	{
	case 1:
		if (atacando == false) {
			*posicaoY -= 2;
		}
		break;
	case 2:
		if (atacando == false) {
			*posicaoX -= 2;
		}
		break;
	case 3:
		if (atacando == false) {
			*posicaoX += 2;
		}
		break;
	case 4:
		if (atacando == false) {
			*posicaoY += 2;
		}
		break;
	}
}
void movimentoSprite(ALLEGRO_BITMAP* baixoN, ALLEGRO_BITMAP* baixoE, ALLEGRO_BITMAP* baixoD,
	ALLEGRO_BITMAP* esquerdaN, ALLEGRO_BITMAP* esquerdaE, ALLEGRO_BITMAP* esquerdaD,
	ALLEGRO_BITMAP* cimaN, ALLEGRO_BITMAP* cimaE, ALLEGRO_BITMAP* cimaD,
	ALLEGRO_BITMAP* direitaN, ALLEGRO_BITMAP* direitaE, ALLEGRO_BITMAP* direitaD,
	ALLEGRO_BITMAP* ataqueBaixo1, ALLEGRO_BITMAP* ataqueBaixo2, ALLEGRO_BITMAP* ataqueBaixo3, ALLEGRO_BITMAP* ataquebaixo4,
	int posicaoX, int posicaoY) {
	switch (pressionado)
	{
	case 0:
		al_draw_bitmap(baixoN, posicaoX, posicaoY, 0);
		break;
	case 1:
		if (movimento >= 0 && movimento < 20 && atacando == false) {
			al_draw_bitmap(cimaN, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento >= 20 && movimento < 40 && atacando == false) {
			al_draw_bitmap(cimaE, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento == 40 && atacando == false) {
			al_draw_bitmap(cimaD, posicaoX, posicaoY, 0);
			movimento = 0;
		}
		break;
	case 2:
		if (movimento >= 0 && movimento < 20 && atacando == false) {
			al_draw_bitmap(esquerdaN, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento >= 20 && movimento < 40 && atacando == false) {
			al_draw_bitmap(esquerdaE, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento == 40 && atacando == false) {
			al_draw_bitmap(esquerdaD, posicaoX, posicaoY, 0);
			movimento = 0;
		}
		break;
	case 3:
		if (movimento >= 0 && movimento < 20 && atacando == false) {
			al_draw_bitmap(direitaN, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento >= 20 && movimento < 40 && atacando == false) {
			al_draw_bitmap(direitaE, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento == 40 && atacando == false) {
			al_draw_bitmap(direitaD, posicaoX, posicaoY, 0);
			movimento = 0;
		}
		break;
	case 4:
		if (movimento >= 0 && movimento < 20 && atacando == false) {
			al_draw_bitmap(baixoN, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento >= 20 && movimento < 40 && atacando == false) {
			al_draw_bitmap(baixoE, posicaoX, posicaoY, 0);
			movimento += 1;
		}
		if (movimento == 40 && atacando == false) {
			al_draw_bitmap(baixoD, posicaoX, posicaoY, 0);
			movimento = 0;
		}
		break;
	case 5:
		if (atacando == true) {
			if (movimento >= 0 && movimento < 15) {
				al_draw_bitmap(ParisAtaqueB1, posicaoX, posicaoY, 0);
				movimento += 1;
			}
			if (movimento >= 15 && movimento < 25) {
				al_draw_bitmap(ParisAtaqueB2, posicaoX, posicaoY, 0);
				movimento += 1;
			}
			if (movimento >= 25 && movimento < 45) {
				al_draw_bitmap(ParisAtaqueB3, posicaoX, posicaoY, 0);
				movimento += 1;
			}
			if (movimento == 45) {
				if ((positionY1_f2 + 65 >= positionReiY && positionY1_f2 + 65 <= positionReiY + 60) &&
					(positionX1_f2 >= positionReiX - 20 && positionX1_f2 - 20 <= positionReiX + 30 ||
					positionX1_f2 + 60 >= positionReiX && positionX1_f2 + 60 <= positionReiX + 30))
				{
					vidaReiX -= 10;
				}
				al_draw_bitmap(ParisAtaqueB4, posicaoX, posicaoY, 0);
				movimento = 0;
				atacando = false;
				ultPressionado = 0;
				pressionado = 0;
			}
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
	al_draw_filled_rectangle(1016, 653, 1175, 692, al_map_rgb(222, 158, 30));
	al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1095, 650, ALLEGRO_ALIGN_CENTRE, "Proximo");
	if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK); 
	}
	else {
		al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	}
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1189 && mouseY <= 692) {
			al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
			intro += 1;
		}
	}
}

//FUNÇÃO QUE DESTROI TODAS AS ALOCAÇÕES DE MEMÓRIA
void destruidor() {

	//Global
	al_destroy_timer(timer);
	al_destroy_event_queue(evento);
	/*al_destroy_display(display);*/

	//Audios e Musicas
	al_destroy_sample(audioMenu);

	//Menu
	al_destroy_bitmap(backgroundMenu);
	al_destroy_font(fonteMenu);
	al_destroy_font(font);

	//Opções
	al_destroy_bitmap(backgroundOpcoes);
	al_destroy_bitmap(comVolume);
	al_destroy_bitmap(semVolume);
	al_destroy_bitmap(comVolumeHover);
	al_destroy_bitmap(semVolumeHover);

	//Introdução 1
	al_destroy_bitmap(fundo1Intro1);
	al_destroy_bitmap(fundo2Intro1);
	al_destroy_bitmap(fundo3Intro1);
	al_destroy_bitmap(fundoHelena);
	al_destroy_bitmap(fundoParis);
	al_destroy_font(fonteIntro1);
	al_destroy_bitmap(mapaAtenas);
	al_destroy_bitmap(mapaGrecia);
	al_destroy_bitmap(mapaTroia);

	//Introdução 2
	al_destroy_bitmap(fundoAgamenom);
	al_destroy_bitmap(fundoMenelau);
	al_destroy_bitmap(fundoExplicacao);

	//Introdução 3
	al_destroy_bitmap(pagina1);
	al_destroy_bitmap(pagina2);
	al_destroy_bitmap(pagina3);
	al_destroy_bitmap(pagina4);

	//Introdução 4
	al_destroy_bitmap(pag1);
	al_destroy_bitmap(pag2);
	al_destroy_bitmap(pag3);
	al_destroy_bitmap(pag4);

	//telas finais
	al_destroy_bitmap(vitoria);
	al_destroy_bitmap(derrota);

	//Fase 1
	al_destroy_bitmap(backgroundFaseUm);
	al_destroy_bitmap(personagemHeitor);
	al_destroy_bitmap(personagemHelena);
	al_destroy_bitmap(frente_direito);
	al_destroy_bitmap(frente_esquerdo);

	//Fase 2
	al_destroy_bitmap(soldadosTroia);
	al_destroy_bitmap(soldadosEsparta);
	al_destroy_bitmap(background_f2);
	//Menelau
	al_destroy_bitmap(MenelauEsqDirN);
	al_destroy_bitmap(MenelauEsqDir1);
	al_destroy_bitmap(MenelauEsqDir2);
	al_destroy_bitmap(MenelauEsqDir3);
	al_destroy_bitmap(MenelauCimaN);
	al_destroy_bitmap(MenelauCima1);
	al_destroy_bitmap(MenelauCima2);
	al_destroy_bitmap(MenelauCima3);
	al_destroy_bitmap(MenelauBaixoN);
	al_destroy_bitmap(MenelauBaixo1);
	al_destroy_bitmap(MenelauBaixo2);
	al_destroy_bitmap(MenelauBaixo3);
	//Paris
	al_destroy_bitmap(ParisAtaqueB1);
	al_destroy_bitmap(ParisAtaqueB2);
	al_destroy_bitmap(ParisAtaqueB3);
	al_destroy_bitmap(ParisAtaqueB4);
	al_destroy_bitmap(ParisCimaNormal);
	al_destroy_bitmap(ParisCimaEsq);
	al_destroy_bitmap(ParisCimaDir);
	al_destroy_bitmap(ParisBaixoNormal);
	al_destroy_bitmap(ParisBaixoEsq);
	al_destroy_bitmap(ParisBaixoDir);
	al_destroy_bitmap(ParisEsqNormal);
	al_destroy_bitmap(ParisEsqEsq);
	al_destroy_bitmap(ParisEsqDir);
	al_destroy_bitmap(ParisDirNormal);
	al_destroy_bitmap(ParisDirEsq);
	al_destroy_bitmap(ParisDirDir);
	//Remover
	al_destroy_bitmap(barra_vida_cheia);
	al_destroy_bitmap(espada_rei_f2);
	al_destroy_bitmap(espada_player1);
	al_destroy_bitmap(barra_vida_baixa);
	al_destroy_bitmap(barra_vidaRei_100);
	al_destroy_bitmap(barra_vidaRei_50);

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

	//fase 4
	al_destroy_bitmap(backgroundFase04);
	al_destroy_timer(timerFase04);
	al_destroy_bitmap(aquiles_Baixo);
	al_destroy_bitmap(aquiles_Descendo_0);
	al_destroy_bitmap(aquiles_Descendo_1);
	al_destroy_bitmap(aquiles_Lado_0);
	al_destroy_bitmap(aquiles_Lado_1);
	al_destroy_bitmap(aquiles_Cima);
	al_destroy_bitmap(Lanc_Lado_0);
	al_destroy_bitmap(Lanc_Lado_1);
	al_destroy_bitmap(arq_Frente_1);
	al_destroy_bitmap(arq_Frente_2);
	al_destroy_bitmap(arq_Costas_1);
	al_destroy_bitmap(arq_Costas_2);
	al_destroy_bitmap(flecha);

}