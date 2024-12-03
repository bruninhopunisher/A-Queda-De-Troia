#include "fase2.h" 

void fase2(ALLEGRO_EVENT evento) {

	//Pegar Posição do Mouse
	if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
		mouseX = evento.mouse.x;
		mouseY = evento.mouse.y;
	}

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

		//Nome Paris Personagem
		al_draw_text(fonteFase2, al_map_rgb(0, 0, 0), 1020, 6, ALLEGRO_ALIGN_CENTRE, "Rei Menelau");
		//Background Barra de Vida
		al_draw_bitmap(barra_vida_cheia, 950, 38, 0);
		//BARRA DE VIDA REI MENELAU
		if (vidaReiX > 970) {
			al_draw_filled_rectangle(958, 45, vidaReiX, 61, al_map_rgba(255, 0, 0, 1));
		}
		else {
			al_draw_filled_rectangle(958, 45, 970, 61, al_map_rgba(255, 0, 0, 1));
		}

		//Nome Paris Personagem
		al_draw_text(fonteFase2, al_map_rgb(0, 0, 0), 180, 6, ALLEGRO_ALIGN_CENTRE, "Paris ( Jogador )");
		//Background Barra de Vida
		al_draw_bitmap(barra_vida_cheia, 80, 38, 0);
		//BARRA DE VIDA PARIS ( JOGADOR )
		if (vidaJogador > 88)
			al_draw_filled_rectangle(88, 45, vidaJogador, 61, al_map_rgba(255, 0, 0, 1));

		//Timer Ataque Rei
		if (timerAtaqueRei > 0) {
			timerAtaqueRei -= 1;
		}

		////Gera posição e controla o Rei até o ponto aleatório
		if (positionReiX == pontoAndarX &&
			positionReiY == pontoAndarY) {
			pontoAndarX = rand() % 1280;
			pontoAndarY = 190 + rand() % 260;
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
		if (((areaAtaque(positionReiX + 2, positionReiY + 5, 83, 40, positionX1_f2 + 10, positionY1_f2 + 5, 30, 50) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 1) && (vidaJogador > 88)) {
			if (movRei >= 0 && movRei < 10) {
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
					vidaJogador -= 10;
				atacouRei == true;

				al_draw_bitmap(AtaqueRcima4, positionReiX, positionReiY, 0);
				movRei += 1;
				if (movRei == 40) {
					movRei = 0;
					timerAtaqueRei = 200;
				}
				if (timerAtaqueRei == 0) {
					atacouRei = false;
				}
			}
		}
		else {
			if (posicaoRei == 1) {
				movRei = 0;
			}
		}
		//Ataque para Esquerda Rei
		if (((areaAtaque((positionReiX - 50) + 2, positionReiY + 15, 100, 50, positionX1_f2 + 5, positionY1_f2 + 5, 30, 50) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 2) && (vidaJogador > 88)) {

			if (movRei >= 0 && movRei < 10) {
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
					vidaJogador -= 10;
				atacouRei == true;

				al_draw_bitmap(AtaqueRlado4, positionReiX - 50, positionReiY, 0);
				movRei += 1;
				if (movRei == 40) {
					movRei = 0;
					timerAtaqueRei = 200;
				}
				if (timerAtaqueRei == 0) {
					atacouRei = false;
				}
			}
		}
		else {
			if (posicaoRei == 2) {
				movRei = 0;
			}
		}
		//Ataque para Direita Rei
		if (((areaAtaque(positionX1_f2 + 10, positionY1_f2 + 5, 30, 50, positionReiX + 40, positionReiY + 20, 35, 30) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 3) && (vidaJogador > 88)) {

			if (movRei >= 0 && movRei < 10) {
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
					vidaJogador -= 10;
				atacouRei == true;

				al_draw_bitmap(AtaqueRlado4, positionReiX, positionReiY, 1);
				movRei += 1;
				if (movRei == 40) {
					movRei = 0;
					timerAtaqueRei = 200;
				}
				if (timerAtaqueRei == 0) {
					atacouRei = false;
				}
			}
		}
		else {
			if (posicaoRei == 3) {
				movRei = 0;
			}
		}
		//Ataque para Baixo Rei
		if (((areaAtaque(positionReiX + 5, positionReiY + 20, 55, 55, positionX1_f2 + 10, positionY1_f2 + 15, 30, 40) == true) && (timerAtaqueRei == 0)) && (posicaoRei == 4) && (vidaJogador > 88)) {

			if (movRei >= 0 && movRei < 10) {
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
					vidaJogador -= 10;
				atacouRei == true;

				al_draw_bitmap(AtaqueRbaixo4, positionReiX, positionReiY, 0);
				movRei += 1;
				if (movRei == 40) {
					movRei = 0;
					timerAtaqueRei = 200;
				}
				if (timerAtaqueRei == 0) {
					atacouRei = false;
				}
			}
		}
		else {
			if (posicaoRei == 4) {
				movRei = 0;
			}
		}
		if (vidaJogador > 88 && vidaJogador <= 300) {
			//MOVIMENTAÇÃO DO PARIS VIDA 100%
			if ((positionY1_f2 < 450 && positionY1_f2 > 150) && (positionX1_f2 > 1 && positionX1_f2 < displayX - 30)) {
				movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
			}
			else {
				if (positionY1_f2 >= 451) {
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
				if (positionY1_f2 <= 149) {
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
				if (positionX1_f2 <= 1) {
					if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
				}
				if (positionX1_f2 >= displayX - 30) {
					if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
						movimentarPlayer(evento, &positionX1_f2, &positionY1_f2);
					}
				}
			}
			//PARIS - CONTROLANDO
			movimentoSprite(ParisBaixoNormal, ParisBaixoEsq, ParisBaixoDir,
				ParisDirNormal, ParisDirEsq, ParisDirDir,
				ParisCimaNormal, ParisCimaEsq, ParisCimaDir,
				ParisDirNormal, ParisDirEsq, ParisDirDir,
				ParisAtaqueB1, ParisAtaqueB2, ParisAtaqueB3, ParisAtaqueB4,
				ParisAtaqueC1, ParisAtaqueC2, ParisAtaqueC3, ParisAtaqueC4,
				ParisAtaqueL1, ParisAtaqueL2, ParisAtaqueL3, ParisAtaqueL4,
				positionX1_f2, positionY1_f2);
			//HEITOR
			al_draw_bitmap(HeitorBaixoN, positionX1_heitor, positionY1_heitor, 0);
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
				//HEITOR
				al_draw_bitmap(HeitorBaixoN, positionX1_heitor, positionY1_heitor, 0);
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
					//HEITOR
					al_draw_bitmap(HeitorBaixoN, positionX1_heitor, positionY1_heitor, 0);
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
						//HEITOR
						al_draw_bitmap(HeitorBaixoN, positionX1_heitor, positionY1_heitor, 0);
					}
					else {
						if (positionY1_f2 <= 190) {
							switch (intro)
							{
							case 1:
								al_draw_bitmap(Intro1Fase2, 0, 0, 0);
								al_draw_filled_rectangle(1046, 653, 1205, 692, al_map_rgb(140, 70, 20));
								if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1195 && mouseY <= 692) {
									al_draw_filled_rectangle(1046, 653, 1205, 692, al_map_rgb(200, 100, 20));
									al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
								}
								else {
									al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
								}

								al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1125, 650, ALLEGRO_ALIGN_CENTRE, "Proximo");

								if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
									if (mouseX >= 1046 && mouseY >= 653 && mouseX <= 1205 && mouseY <= 692) {
										al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
										intro += 1;
									}
								}
								break;
							case 2:
								al_draw_bitmap(Intro2Fase2, 0, 0, 0);
								al_draw_filled_rectangle(1046, 653, 1205, 692, al_map_rgb(140, 70, 20));
								if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1195 && mouseY <= 692) {
									al_draw_filled_rectangle(1046, 653, 1205, 692, al_map_rgb(200, 100, 20));
									al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
								}
								else {
									al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
								}

								al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1125, 650, ALLEGRO_ALIGN_CENTRE, "Proximo");

								if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
									if (mouseX >= 1046 && mouseY >= 653 && mouseX <= 1205 && mouseY <= 692) {
										al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
										intro += 1;
									}
								}
								break;
							case 3:
								al_draw_bitmap(Intro3Fase2, 0, 0, 0);
								al_draw_filled_rectangle(1046, 653, 1205, 692, al_map_rgb(140, 70, 20));
								if (mouseX >= 1016 && mouseY >= 653 && mouseX <= 1195 && mouseY <= 692) {
									al_draw_filled_rectangle(1046, 653, 1205, 692, al_map_rgb(200, 100, 20));
									al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
								}
								else {
									al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
								}

								al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1125, 650, ALLEGRO_ALIGN_CENTRE, "Proximo");

								if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
									if (mouseX >= 1046 && mouseY >= 653 && mouseX <= 1205 && mouseY <= 692) {
										al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
										intro += 1;
									}
								}
								break;
							case 4:
								vidaJogador = 300;
								vidaReiX = 1170;
								pressionado = 0;
								ultPressionado = 0;
								controleJogador = true;
								break;
							}
						}
					}
				}
			}
		}

		break;

	case true:

		//Nome Paris Personagem
		al_draw_text(fonteFase2, al_map_rgb(0, 0, 0), 1020, 6, ALLEGRO_ALIGN_CENTRE, "Rei Menelau");
		//Background Barra de Vida
		al_draw_bitmap(barra_vida_cheia, 950, 38, 0);
		//BARRA DE VIDA REI MENELAU
		al_draw_filled_rectangle(958, 45, vidaReiX, 61, al_map_rgba(255, 0, 0, 1));

		//Nome Paris Personagem
		al_draw_text(fonteFase2, al_map_rgb(0, 0, 0), 180, 6, ALLEGRO_ALIGN_CENTRE, "Heitor ( Jogador )");
		//Background Barra de Vida
		al_draw_bitmap(barra_vida_cheia, 80, 38, 0);
		//BARRA DE VIDA PARIS ( JOGADOR )
		al_draw_filled_rectangle(88, 45, vidaJogador, 61, al_map_rgba(255, 0, 0, 1));

		if (vidaJogador > 88 && vidaReiX > 958) {

			//Timer Ataque Rei
			if (timerAtaqueRei > 0) {
				timerAtaqueRei -= 1;
			}

			////Gera posição e controla o Rei até o ponto aleatório
			if (positionReiX == pontoAndarX &&
				positionReiY == pontoAndarY) {
				if ((areaAtaque(positionX1_heitor, positionY1_heitor, 50, 65, positionReiX, positionReiY, 50, 70) == true) && positionY1_heitor + 50 > pontoAndarY) {
					while (pontoAndarY < positionY1_heitor + 60) {
						pontoAndarY = 190 + rand() % 260;
					}
					pontoAndarX = rand() % 1280;
				}
				else {
					pontoAndarY = 190 + rand() % 260;
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
				if (movRei >= 0 && movRei < 10) {
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
						timerAtaqueRei = 200;
					}
					if (timerAtaqueRei == 0) {
						atacouRei = false;
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
				if (movRei >= 0 && movRei < 10) {
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
						timerAtaqueRei = 200;
					}
					if (timerAtaqueRei == 0) {
						atacouRei = false;
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
				if (movRei >= 0 && movRei < 10) {
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
						timerAtaqueRei = 200;
					}
					if (timerAtaqueRei == 0) {
						atacouRei = false;
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
				if (movRei >= 0 && movRei < 10) {
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
						timerAtaqueRei = 200;
					}
					if (timerAtaqueRei == 0) {
						atacouRei = false;
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
			if (parisCaindoTimer >= 60 && parisCaindoTimer < 80) {
				al_draw_bitmap(ParisCaindo4, positionX1_f2, positionY1_f2, 0);
				parisCaindoTimer += 1;
			}
			if (parisCaindoTimer == 80) {
				al_draw_bitmap(ParisCaindo5, positionX1_f2, positionY1_f2, 0);
			}

			if ((positionY1_heitor < 450 && positionY1_heitor > 150) && (positionX1_heitor > 1 && positionX1_heitor < displayX - 30)) {
				movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
			}
			else {
				if (positionY1_heitor >= 451) {
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
				if (positionY1_heitor <= 149) {
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
				if (positionX1_heitor <= 1) {
					if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
				}
				if (positionX1_heitor >= displayX - 30) {
					if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT) {
						movimentarPlayer(evento, &positionX1_heitor, &positionY1_heitor);
					}
					if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
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
			if (vidaJogador <= 88) {
				al_draw_bitmap(GameOverFase2, 0, 0, 0);
				al_draw_filled_rectangle(525, 360, 755, 410, al_map_rgb(86, 86, 86));
				al_draw_filled_rectangle(525, 460, 755, 510, al_map_rgb(86, 86, 86));
				al_draw_text(fonteFase2, al_map_rgb(255, 255, 255), 640, 367, ALLEGRO_ALIGN_CENTRE, "Menu Inicial");
				al_draw_text(fonteFase2, al_map_rgb(255, 255, 255), 640, 467, ALLEGRO_ALIGN_CENTRE, "Fechar Jogo");

				if ((mouseX >= 525 && mouseY >= 360 && mouseX <= 755 && mouseY <= 410) || (mouseX >= 525 && mouseY >= 460 && mouseX <= 755 && mouseY <= 510)) {
					al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
				}
				else {
					al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				}
				if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (mouseX >= 525 && mouseY >= 360 && mouseX <= 755 && mouseY <= 410) {
						al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
						//Configs
						intro = 1;
						controleJogador = false;
						navegacao = 0;

						//Rei
						positionReiX = 650;
						positionReiY = 450;
						vidaReiX = 1170;

						//Paris e Heitor
						vidaJogador = 300;
						positionX1_f2 = 650;
						positionY1_f2 = 225;
						positionX1_heitor = 615;
						positionY1_heitor = 200;
					}
				}

				if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (mouseX >= 525 && mouseY >= 460 && mouseX <= 755 && mouseY <= 510) {
						al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
						rodando = false;
					}
				}
			}


			if (vidaReiX <= 958) {
				al_draw_bitmap(VitoriaFase2, 0, 0, 0);
				al_draw_filled_rectangle(525, 480, 755, 530, al_map_rgb(242, 183, 64));
				al_draw_text(fonteFase2, al_map_rgb(0, 0, 0), 640, 488, ALLEGRO_ALIGN_CENTRE, "Continuar");
				if ((mouseX >= 525 && mouseY >= 480 && mouseX <= 755 && mouseY <= 530) || (mouseX >= 525 && mouseY >= 460 && mouseX <= 755 && mouseY <= 510)) {
					al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
				}
				else {
					al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				}
				if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (mouseX >= 525 && mouseY >= 480 && mouseX <= 755 && mouseY <= 530) {
						al_set_system_mouse_cursor(display, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
						navegacao += 1;
					}
				}
			}
		}
		break;
	}
	al_flip_display();
}