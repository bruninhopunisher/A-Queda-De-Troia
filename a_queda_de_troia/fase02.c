#include "fase2.h" 

void fase2(ALLEGRO_EVENT evento) {

	al_draw_bitmap(background_f2, 0, 0, 0);

	if (vidaReiX <= 1000) {
		controleJogador = true;
	}


	//SOLDADOS DE BAIXO
	al_draw_bitmap(soldadosEsparta, 100, 600, 0);
	al_draw_bitmap(soldadosEsparta, 200, 600, 0);
	al_draw_bitmap(soldadosEsparta, 300, 600, 0);
	al_draw_bitmap(soldadosEsparta, 400, 600, 0);
	al_draw_bitmap(soldadosEsparta, 500, 600, 0);
	al_draw_bitmap(soldadosEsparta, 600, 600, 0);
	al_draw_bitmap(soldadosEsparta, 700, 600, 0);
	al_draw_bitmap(soldadosEsparta, 800, 600, 0);
	al_draw_bitmap(soldadosEsparta, 900, 600, 0);
	al_draw_bitmap(soldadosEsparta, 1000, 600, 0);
	al_draw_bitmap(soldadosEsparta, 1100, 600, 0);

	al_draw_bitmap(soldadosEsparta, 100, 550, 0);
	al_draw_bitmap(soldadosEsparta, 200, 550, 0);
	al_draw_bitmap(soldadosEsparta, 300, 550, 0);
	al_draw_bitmap(soldadosEsparta, 400, 550, 0);
	al_draw_bitmap(soldadosEsparta, 500, 550, 0);
	al_draw_bitmap(soldadosEsparta, 600, 550, 0);
	al_draw_bitmap(soldadosEsparta, 700, 550, 0);
	al_draw_bitmap(soldadosEsparta, 800, 550, 0);
	al_draw_bitmap(soldadosEsparta, 900, 550, 0);
	al_draw_bitmap(soldadosEsparta, 1000, 550, 0);
	al_draw_bitmap(soldadosEsparta, 1100, 550, 0);

	al_draw_bitmap(soldadosEsparta, 200, 500, 0);
	al_draw_bitmap(soldadosEsparta, 400, 500, 0);
	al_draw_bitmap(soldadosEsparta, 600, 500, 0);
	al_draw_bitmap(soldadosEsparta, 800, 500, 0);
	al_draw_bitmap(soldadosEsparta, 1000, 500, 0);

	//SOLDADOS DE CIMA
	al_draw_bitmap(soldadosTroia, 100, 50, 0);
	al_draw_bitmap(soldadosTroia, 200, 50, 0);
	al_draw_bitmap(soldadosTroia, 300, 50, 0);
	al_draw_bitmap(soldadosTroia, 400, 50, 0);
	al_draw_bitmap(soldadosTroia, 500, 50, 0);
	al_draw_bitmap(soldadosTroia, 600, 50, 0);
	al_draw_bitmap(soldadosTroia, 700, 50, 0);
	al_draw_bitmap(soldadosTroia, 800, 50, 0);
	al_draw_bitmap(soldadosTroia, 900, 50, 0);
	al_draw_bitmap(soldadosTroia, 1000, 50, 0);
	al_draw_bitmap(soldadosTroia, 1100, 50, 0);

	al_draw_bitmap(soldadosTroia, 100, 100, 0);
	al_draw_bitmap(soldadosTroia, 200, 100, 0);
	al_draw_bitmap(soldadosTroia, 300, 100, 0);
	al_draw_bitmap(soldadosTroia, 400, 100, 0);
	al_draw_bitmap(soldadosTroia, 500, 100, 0);
	al_draw_bitmap(soldadosTroia, 600, 100, 0);
	al_draw_bitmap(soldadosTroia, 700, 100, 0);
	al_draw_bitmap(soldadosTroia, 800, 100, 0);
	al_draw_bitmap(soldadosTroia, 900, 100, 0);
	al_draw_bitmap(soldadosTroia, 1000, 100, 0);
	al_draw_bitmap(soldadosTroia, 1100, 100, 0);

	al_draw_bitmap(soldadosTroia, 200, 150, 0);
	al_draw_bitmap(soldadosTroia, 400, 150, 0);
	al_draw_bitmap(soldadosTroia, 600, 150, 0);
	al_draw_bitmap(soldadosTroia, 800, 150, 0);
	al_draw_bitmap(soldadosTroia, 1000, 150, 0);


	switch (controleJogador)
	{
	case false:

		//BARRA DE VIDA REI MENELAU
		al_draw_filled_rectangle(1000, 25, vidaReiX, 55, al_map_rgba(255, 0, 0, 1));
		//BARRA DE VIDA PARIS ( JOGADOR )
		if (vidaJogador > 100)
			al_draw_filled_rectangle(100, 25, vidaJogador, 55, al_map_rgba(255, 0, 0, 1));

		//Timer Ataque Rei
		if (timerAtaqueRei > 0) {
			timerAtaqueRei -= 1;
		}

		////Gera posição e controla o Rei até o ponto aleatório
		if (positionReiX == pontoAndarX &&
			positionReiY == pontoAndarY) {
			pontoAndarX = rand() % 1280;
			pontoAndarY = 180 + rand() % 320;
		}
		else {
			if ((positionReiY < pontoAndarY) && (movRei == 0)) {
				if (movimentoRei >= 0 && movimentoRei < 20) {
					al_draw_bitmap(MenelauBaixoN, positionReiX, positionReiY, 0);
					movimentoRei += 1;
				}
				if (movimentoRei >= 20 && movimentoRei < 30) {
					al_draw_bitmap(MenelauBaixo1, positionReiX, positionReiY, 0);
					movimentoRei += 1;
				}
				if (movimentoRei >= 30 && movimentoRei < 40) {
					al_draw_bitmap(MenelauBaixoN, positionReiX, positionReiY, 0);
					movimentoRei += 1;
				}
				if (movimentoRei >= 40 && movimentoRei < 50) {
					al_draw_bitmap(MenelauBaixo3, positionReiX, positionReiY, 0);
					movimentoRei = 0;
				}
				positionReiY += 0.5;
				posicaoRei = 4;
			}
			else {
				if (positionReiY > pontoAndarY && (movRei == 0)) {
					if (movimentoRei >= 0 && movimentoRei < 20) {
						al_draw_bitmap(MenelauCimaN, positionReiX, positionReiY, 0);
						movimentoRei += 1;
					}
					if (movimentoRei >= 20 && movimentoRei < 30) {
						al_draw_bitmap(MenelauCima1, positionReiX, positionReiY, 0);
						movimentoRei += 1;
					}
					if (movimentoRei >= 30 && movimentoRei < 40) {
						al_draw_bitmap(MenelauCimaN, positionReiX, positionReiY, 0);
						movimentoRei += 1;
					}
					if (movimentoRei >= 40 && movimentoRei < 50) {
						al_draw_bitmap(MenelauCima3, positionReiX, positionReiY, 0);
						movimentoRei = 0;
					}
					positionReiY -= 0.5;
					posicaoRei = 1;
				}
				else {
					if (positionReiX < pontoAndarX && (movRei == 0)) {
						if (movimentoRei >= 0 && movimentoRei < 20) {
							al_draw_bitmap(MenelauEsqDirN, positionReiX, positionReiY, 1);
							movimentoRei += 1;
						}
						if (movimentoRei >= 20 && movimentoRei < 30) {
							al_draw_bitmap(MenelauEsqDir1, positionReiX, positionReiY, 1);
							movimentoRei += 1;
						}
						if (movimentoRei >= 30 && movimentoRei < 40) {
							al_draw_bitmap(MenelauEsqDirN, positionReiX, positionReiY, 1);
							movimentoRei += 1;
						}
						if (movimentoRei >= 40 && movimentoRei < 50) {
							al_draw_bitmap(MenelauEsqDir3, positionReiX, positionReiY, 1);
							movimentoRei = 0;
						}
						positionReiX += 0.5;
						posicaoRei = 3;
					}
					else {
						if (positionReiX > pontoAndarX && (movRei == 0)) {
							if (movimentoRei >= 0 && movimentoRei < 20) {
								al_draw_bitmap(MenelauEsqDirN, positionReiX, positionReiY, 0);
								movimentoRei += 1;
							}
							if (movimentoRei >= 20 && movimentoRei < 30) {
								al_draw_bitmap(MenelauEsqDir1, positionReiX, positionReiY, 0);
								movimentoRei += 1;
							}
							if (movimentoRei >= 30 && movimentoRei < 40) {
								al_draw_bitmap(MenelauEsqDirN, positionReiX, positionReiY, 0);
								movimentoRei += 1;
							}
							if (movimentoRei >= 40 && movimentoRei < 50) {
								al_draw_bitmap(MenelauEsqDir3, positionReiX, positionReiY, 0);
								movimentoRei = 0;
							}
							positionReiX -= 0.5;
							posicaoRei = 2;
						}
					}
				}
			}
		}

		//Ataque para Cima Rei
		if (((areaAtaque(positionReiX + 2, positionReiY + 5, 83, 40, positionX1_f2 + 10, positionY1_f2 + 5, 30, 50) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 1) && (vidaJogador > 100)) {
			printf("aqui");
			if (movRei >= 0 && movRei < 10) {
				printf("Entrei");
				al_draw_bitmap(AtaqueRcima1, positionReiX, positionReiY, 0);
				movRei += 1;
			}
			if (movRei >= 10 && movRei < 20) {
				al_draw_bitmap(AtaqueRcima2, positionReiX, positionReiY, 0);
				movRei += 1;
			}
			if (movRei >= 20 && movRei < 30) {
				al_draw_bitmap(AtaqueRcima3, positionReiX, positionReiY, 0);
				movRei += 1;
			}
			if (movRei >= 30 && movRei <= 40) {
				if (atacouRei == false)
					vidaJogador -= 2;
				atacouRei == true;

				al_draw_bitmap(AtaqueRcima4, positionReiX, positionReiY, 0);
				movRei += 1;
				if (movRei == 40) {
					movRei = 0;
					atacouRei = false;
					timerAtaqueRei = 10;
				}
			}
		}
		else {
			if (posicaoRei == 1) {
				movRei = 0;
			}
		}
		//Ataque para Esquerda Rei
		if (((areaAtaque((positionReiX - 50) + 2, positionReiY + 15, 113, 65, positionX1_f2 + 5, positionY1_f2 + 5, 30, 50) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 2) && (vidaJogador > 100)) {
			printf("aqui");
			if (movRei >= 0 && movRei < 10) {
				printf("Entrei");
				al_draw_bitmap(AtaqueRlado1, positionReiX, positionReiY, 0);
				movRei += 1;
			}
			if (movRei >= 10 && movRei < 20) {
				al_draw_bitmap(AtaqueRlado2, positionReiX, positionReiY, 0);
				movRei += 1;
			}
			if (movRei >= 20 && movRei < 30) {
				al_draw_bitmap(AtaqueRlado3, positionReiX - 50, positionReiY, 0);
				movRei += 1;
			}
			if (movRei >= 30 && movRei <= 40) {
				if (atacouRei == false)
					vidaJogador -= 2;
				atacouRei == true;

				al_draw_bitmap(AtaqueRlado4, positionReiX - 50, positionReiY, 0);
				movRei += 1;
				if (movRei == 40) {
					movRei = 0;
					atacouRei = false;
					timerAtaqueRei = 50;
				}
			}
		}
		else {
			if (posicaoRei == 2) {
				movRei = 0;
			}
		}
		//Ataque para Direita Rei
		if (((areaAtaque(positionX1_f2 + 10, positionY1_f2 + 5, 30, 50, positionReiX + 40, positionReiY + 20, 35, 30) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 3) && (vidaJogador > 100)) {
			printf("aqui");
			if (movRei >= 0 && movRei < 10) {
				printf("Entrei");
				al_draw_bitmap(AtaqueRlado1, positionReiX, positionReiY, 1);
				movRei += 1;
			}
			if (movRei >= 10 && movRei < 20) {
				al_draw_bitmap(AtaqueRlado2, positionReiX, positionReiY, 1);
				movRei += 1;
			}
			if (movRei >= 20 && movRei < 30) {
				al_draw_bitmap(AtaqueRlado3, positionReiX, positionReiY, 1);
				movRei += 1;
			}
			if (movRei >= 30 && movRei <= 40) {
				if (atacouRei == false)
					vidaJogador -= 2;
				atacouRei == true;

				al_draw_bitmap(AtaqueRlado4, positionReiX, positionReiY, 1);
				movRei += 1;
				if (movRei == 40) {
					movRei = 0;
					atacouRei = false;
					timerAtaqueRei = 50;
				}
			}
		}
		else {
			if (posicaoRei == 3) {
				movRei = 0;
			}
		}
		//Ataque para Baixo Rei
		if (((areaAtaque(positionReiX + 5, positionReiY + 20, 55, 55, positionX1_f2 + 10, positionY1_f2 + 15, 30, 40) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 4) && (vidaJogador > 100)) {
			printf("aqui");
			if (movRei >= 0 && movRei < 10) {
				printf("Entrei");
				al_draw_bitmap(AtaqueRbaixo1, positionReiX, positionReiY, 0);
				movRei += 1;
			}
			if (movRei >= 10 && movRei < 20) {
				al_draw_bitmap(AtaqueRbaixo2, positionReiX, positionReiY, 0);
				movRei += 1;
			}
			if (movRei >= 20 && movRei < 30) {
				al_draw_bitmap(AtaqueRbaixo3, positionReiX, positionReiY, 0);
				movRei += 1;
			}
			if (movRei >= 30 && movRei <= 40) {
				if (atacouRei == false)
					vidaJogador -= 2;
				atacouRei == true;

				al_draw_bitmap(AtaqueRbaixo4, positionReiX, positionReiY, 0);
				movRei += 1;
				if (movRei == 40) {
					movRei = 0;
					atacouRei = false;
					timerAtaqueRei = 50;
				}
			}
		}
		else {
			if (posicaoRei == 4) {
				movRei = 0;
			}
		}


		if (vidaJogador > 100 && vidaJogador <= 300) {
			//MOVIMENTAÇÃO DO PARIS VIDA 100%
			if (positionY1_f2 < 450 && positionY1_f2 > 150) {
				movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
			}
			else {
				printf("Y-%d", positionY1_f2);
				if (positionY1_f2 >= 451) {
					printf("To aqui");
					if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
				}
				if (positionY1_f2 <= 149 || (positionY1_f2 >= positionReiY && positionY1_f2 <= positionReiY + 60)) {
					if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
				}
			}
			//PARIS - CONTROLANDO
			movimentoSprite(ParisBaixoNormal, ParisBaixoEsq, ParisBaixoDir,
				ParisEsqNormal, ParisEsqEsq, ParisEsqDir,
				ParisCimaNormal, ParisCimaEsq, ParisCimaDir,
				ParisDirNormal, ParisDirEsq, ParisDirDir,
				ParisAtaqueB1, ParisAtaqueB2, ParisAtaqueB3, ParisAtaqueB4,
				ParisAtaqueC1, ParisAtaqueC2, ParisAtaqueC3, ParisAtaqueC4,
				ParisAtaqueL1, ParisAtaqueL2, ParisAtaqueL3, ParisAtaqueL4,
				positionX1_f2, positionY1_f2);
		}
		else {
			if (positionX1_f2 < 650) {
				positionX1_f2 += 1;
				positionX_espada1 += 1;
				if (movimento >= 0 && movimento < 20) {
					al_draw_bitmap(ParisDirNormal, positionX1_f2, positionY1_f2, 0);
					movimento += 1;
				}
				if (movimento >= 20 && movimento < 40) {
					al_draw_bitmap(ParisDirEsq, positionX1_f2, positionY1_f2, 0);
					movimento += 1;
				}
				if (movimento == 40) {
					al_draw_bitmap(ParisDirDir, positionX1_f2, positionY1_f2, 0);
					movimento = 0;
				}
			}
			else {
				if (positionX1_f2 > 650) {
					positionX1_f2 -= 1;
					positionX_espada1 -= 1;
					if (movimento >= 0 && movimento < 20) {
						al_draw_bitmap(ParisEsqNormal, positionX1_f2, positionY1_f2, 0);
						movimento += 1;
					}
					if (movimento >= 20 && movimento < 40) {
						al_draw_bitmap(ParisEsqEsq, positionX1_f2, positionY1_f2, 0);
						movimento += 1;
					}
					if (movimento == 40) {
						al_draw_bitmap(ParisEsqDir, positionX1_f2, positionY1_f2, 0);
						movimento = 0;
					}
				}
				else {
					if (positionY1_f2 > 190) {
						positionY1_f2 -= 1;
						positionY_espada1 -= 1;
						if (movimento >= 0 && movimento < 20) {
							al_draw_bitmap(ParisCimaNormal, positionX1_f2, positionY1_f2, 0);
							movimento += 1;
						}
						if (movimento >= 20 && movimento < 40) {
							al_draw_bitmap(ParisCimaEsq, positionX1_f2, positionY1_f2, 0);
							movimento += 1;
						}
						if (movimento == 40) {
							al_draw_bitmap(ParisCimaDir, positionX1_f2, positionY1_f2, 0);
							movimento = 0;
						}
					}
					else {
						if (positionY1_f2 <= 190) {
							vidaJogador = 300;
							vidaReiX = 1200;
							pressionado = 0;
							ultPressionado = 0;
							controleJogador = true;
						}
					}
				}
			}
		}


		//HEITOR
		al_draw_bitmap(HeitorBaixoN, positionX1_heitor, positionY1_heitor, 0);

		controleJogador = true;

		break;

	case true:

		if (vidaJogador > 100) {
			//BARRA DE VIDA REI MENELAU
			al_draw_filled_rectangle(1000, 25, vidaReiX, 55, al_map_rgba(255, 0, 0, 1));
			//BARRA DE VIDA PARIS ( JOGADOR )
			al_draw_filled_rectangle(100, 25, vidaJogador, 55, al_map_rgba(255, 0, 0, 1));

			//Timer Ataque Rei
			if (timerAtaqueRei > 0) {
				timerAtaqueRei -= 1;
			}

			////Gera posição e controla o Rei até o ponto aleatório
			if (positionReiX == pontoAndarX &&
				positionReiY == pontoAndarY) {
				if ((areaAtaque(positionX1_heitor, positionY1_heitor, 50, 65, positionReiX, positionReiY, 50, 70) == true) && positionY1_heitor + 50 > pontoAndarY) {
					while (pontoAndarY < positionY1_heitor + 60) {
						pontoAndarY = 180 + rand() % 320;
					}
					pontoAndarX = rand() % 1280;
				}
				else {
					pontoAndarY = 180 + rand() % 320;
					pontoAndarX = rand() % 1280;
				}
			}
			else {
				if ((positionReiY < pontoAndarY) && (movRei == 0)) {
					if (movimentoRei >= 0 && movimentoRei < 20) {
						al_draw_bitmap(MenelauBaixoN, positionReiX, positionReiY, 0);
						movimentoRei += 1;
					}
					if (movimentoRei >= 20 && movimentoRei < 30) {
						al_draw_bitmap(MenelauBaixo1, positionReiX, positionReiY, 0);
						movimentoRei += 1;
					}
					if (movimentoRei >= 30 && movimentoRei < 40) {
						al_draw_bitmap(MenelauBaixoN, positionReiX, positionReiY, 0);
						movimentoRei += 1;
					}
					if (movimentoRei >= 40 && movimentoRei < 50) {
						al_draw_bitmap(MenelauBaixo3, positionReiX, positionReiY, 0);
						movimentoRei = 0;
					}
					positionReiY += 0.5;
					posicaoRei = 4;
				}
				else {
					if (positionReiY > pontoAndarY && (movRei == 0)) {
						if (movimentoRei >= 0 && movimentoRei < 20) {
							al_draw_bitmap(MenelauCimaN, positionReiX, positionReiY, 0);
							movimentoRei += 1;
						}
						if (movimentoRei >= 20 && movimentoRei < 30) {
							al_draw_bitmap(MenelauCima1, positionReiX, positionReiY, 0);
							movimentoRei += 1;
						}
						if (movimentoRei >= 30 && movimentoRei < 40) {
							al_draw_bitmap(MenelauCimaN, positionReiX, positionReiY, 0);
							movimentoRei += 1;
						}
						if (movimentoRei >= 40 && movimentoRei < 50) {
							al_draw_bitmap(MenelauCima3, positionReiX, positionReiY, 0);
							movimentoRei = 0;
						}
						positionReiY -= 0.5;
						posicaoRei = 1;
					}
					else {
						if (positionReiX < pontoAndarX && (movRei == 0)) {
							if (movimentoRei >= 0 && movimentoRei < 20) {
								al_draw_bitmap(MenelauEsqDirN, positionReiX, positionReiY, 1);
								movimentoRei += 1;
							}
							if (movimentoRei >= 20 && movimentoRei < 30) {
								al_draw_bitmap(MenelauEsqDir1, positionReiX, positionReiY, 1);
								movimentoRei += 1;
							}
							if (movimentoRei >= 30 && movimentoRei < 40) {
								al_draw_bitmap(MenelauEsqDirN, positionReiX, positionReiY, 1);
								movimentoRei += 1;
							}
							if (movimentoRei >= 40 && movimentoRei < 50) {
								al_draw_bitmap(MenelauEsqDir3, positionReiX, positionReiY, 1);
								movimentoRei = 0;
							}
							positionReiX += 0.5;
							posicaoRei = 3;
						}
						else {
							if (positionReiX > pontoAndarX && (movRei == 0)) {
								if (movimentoRei >= 0 && movimentoRei < 20) {
									al_draw_bitmap(MenelauEsqDirN, positionReiX, positionReiY, 0);
									movimentoRei += 1;
								}
								if (movimentoRei >= 20 && movimentoRei < 30) {
									al_draw_bitmap(MenelauEsqDir1, positionReiX, positionReiY, 0);
									movimentoRei += 1;
								}
								if (movimentoRei >= 30 && movimentoRei < 40) {
									al_draw_bitmap(MenelauEsqDirN, positionReiX, positionReiY, 0);
									movimentoRei += 1;
								}
								if (movimentoRei >= 40 && movimentoRei < 50) {
									al_draw_bitmap(MenelauEsqDir3, positionReiX, positionReiY, 0);
									movimentoRei = 0;
								}
								positionReiX -= 0.5;
								posicaoRei = 2;
							}
						}
					}
				}
			}

			//Ataque para Cima Rei
			if (((areaAtaque(positionReiX + 2, positionReiY + 5, 83, 40, positionX1_heitor + 10, positionY1_heitor + 5, 30, 50) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 1)) {
				printf("aqui");
				if (movRei >= 0 && movRei < 10) {
					printf("Entrei");
					al_draw_bitmap(AtaqueRcima1, positionReiX, positionReiY, 0);
					movRei += 1;
				}
				if (movRei >= 10 && movRei < 20) {
					al_draw_bitmap(AtaqueRcima2, positionReiX, positionReiY, 0);
					movRei += 1;
				}
				if (movRei >= 20 && movRei < 30) {
					al_draw_bitmap(AtaqueRcima3, positionReiX, positionReiY, 0);
					movRei += 1;
				}
				if (movRei >= 30 && movRei <= 40) {
					if (atacouRei == false)
						vidaJogador -= 2;
					atacouRei == true;

					al_draw_bitmap(AtaqueRcima4, positionReiX, positionReiY, 0);
					movRei += 1;
					if (movRei == 40) {
						movRei = 0;
						atacouRei = false;
						timerAtaqueRei = 10;
					}
				}
			}
			else {
				if (posicaoRei == 1) {
					movRei = 0;
				}
			}
			//Ataque para Esquerda Rei
			if (((areaAtaque((positionReiX - 50) + 2, positionReiY + 15, 113, 65, positionX1_heitor + 5, positionY1_heitor + 5, 30, 50) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 2)) {
				printf("aqui");
				if (movRei >= 0 && movRei < 10) {
					printf("Entrei");
					al_draw_bitmap(AtaqueRlado1, positionReiX, positionReiY, 0);
					movRei += 1;
				}
				if (movRei >= 10 && movRei < 20) {
					al_draw_bitmap(AtaqueRlado2, positionReiX, positionReiY, 0);
					movRei += 1;
				}
				if (movRei >= 20 && movRei < 30) {
					al_draw_bitmap(AtaqueRlado3, positionReiX - 50, positionReiY, 0);
					movRei += 1;
				}
				if (movRei >= 30 && movRei <= 40) {
					if (atacouRei == false)
						vidaJogador -= 2;
					atacouRei == true;

					al_draw_bitmap(AtaqueRlado4, positionReiX - 50, positionReiY, 0);
					movRei += 1;
					if (movRei == 40) {
						movRei = 0;
						atacouRei = false;
						timerAtaqueRei = 50;
					}
				}
			}
			else {
				if (posicaoRei == 2) {
					movRei = 0;
				}
			}
			//Ataque para Direita Rei
			if (((areaAtaque(positionX1_heitor + 10, positionY1_heitor + 5, 30, 50, positionReiX + 40, positionReiY + 20, 35, 30) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 3)) {
				printf("aqui");
				if (movRei >= 0 && movRei < 10) {
					printf("Entrei");
					al_draw_bitmap(AtaqueRlado1, positionReiX, positionReiY, 1);
					movRei += 1;
				}
				if (movRei >= 10 && movRei < 20) {
					al_draw_bitmap(AtaqueRlado2, positionReiX, positionReiY, 1);
					movRei += 1;
				}
				if (movRei >= 20 && movRei < 30) {
					al_draw_bitmap(AtaqueRlado3, positionReiX, positionReiY, 1);
					movRei += 1;
				}
				if (movRei >= 30 && movRei <= 40) {
					if (atacouRei == false)
						vidaJogador -= 2;
					atacouRei == true;

					al_draw_bitmap(AtaqueRlado4, positionReiX, positionReiY, 1);
					movRei += 1;
					if (movRei == 40) {
						movRei = 0;
						atacouRei = false;
						timerAtaqueRei = 50;
					}
				}
			}
			else {
				if (posicaoRei == 3) {
					movRei = 0;
				}
			}
			//Ataque para Baixo Rei
			if (((areaAtaque(positionReiX + 5, positionReiY + 20, 55, 55, positionX1_heitor + 10, positionY1_heitor + 15, 30, 40) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 4)) {
				printf("aqui");
				if (movRei >= 0 && movRei < 10) {
					printf("Entrei");
					al_draw_bitmap(AtaqueRbaixo1, positionReiX, positionReiY, 0);
					movRei += 1;
				}
				if (movRei >= 10 && movRei < 20) {
					al_draw_bitmap(AtaqueRbaixo2, positionReiX, positionReiY, 0);
					movRei += 1;
				}
				if (movRei >= 20 && movRei < 30) {
					al_draw_bitmap(AtaqueRbaixo3, positionReiX, positionReiY, 0);
					movRei += 1;
				}
				if (movRei >= 30 && movRei <= 40) {
					if (atacouRei == false)
						vidaJogador -= 2;
					atacouRei == true;

					al_draw_bitmap(AtaqueRbaixo4, positionReiX, positionReiY, 0);
					movRei += 1;
					if (movRei == 40) {
						movRei = 0;
						atacouRei = false;
						timerAtaqueRei = 50;
					}
				}
			}
			else {
				if (posicaoRei == 4) {
					movRei = 0;
				}
			}

			//Paris Caido
			if (parisCaindoTimer >= 0 && parisCaindoTimer <= 20) {
				al_draw_bitmap(ParisCaindo1, positionX1_f2, positionY1_f2, 0);
				parisCaindoTimer += 1;
			}
			if (parisCaindoTimer >= 20 && parisCaindoTimer <= 40) {
				al_draw_bitmap(ParisCaindo2, positionX1_f2, positionY1_f2, 0);
				parisCaindoTimer += 1;
			}
			if (parisCaindoTimer >= 40 && parisCaindoTimer <= 60) {
				al_draw_bitmap(ParisCaindo3, positionX1_f2, positionY1_f2, 0);
				parisCaindoTimer += 1;
			}
			if (parisCaindoTimer >= 60 && parisCaindoTimer <= 80) {
				al_draw_bitmap(ParisCaindo4, positionX1_f2, positionY1_f2, 0);
				parisCaindoTimer += 1;
			}
			if (parisCaindoTimer >= 80) {
				al_draw_bitmap(ParisCaindo5, positionX1_f2, positionY1_f2, 0);
			}

			//Controlando Heitor
			if ((positionY1_heitor < 450 && positionY1_heitor > 150)) {
				movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
			}
			else {
				printf("Y-%d", positionY1_heitor);
				if (positionY1_heitor >= 450) {
					printf("To aqui");
					if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
				}
				if (positionY1_heitor <= 150) {
					if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
				}
			}

			//Movimentação Heitor
			movimentoSprite(HeitorBaixoN, HeitorBaixoE, HeitorBaixoD,
				HeitorLadoN, HeitorLadoE, HeitorLadoD,
				HeitorCimaN, HeitorCimaE, HeitorCimaD,
				HeitorLadoN, HeitorLadoE, HeitorLadoD,
				HeitorAtaqueB1, HeitorAtaqueB2, HeitorAtaqueB3, HeitorAtaqueB4,
				HeitorAtaqueC1, HeitorAtaqueC2, HeitorAtaqueC3, HeitorAtaqueC4,
				HeitorAtaqueL1, HeitorAtaqueL2, HeitorAtaqueL3, HeitorAtaqueL4,
				positionX1_heitor, positionY1_heitor);
		}
		else {
			navegacao += 1;
		}
			break;
		}
	al_flip_display();
}