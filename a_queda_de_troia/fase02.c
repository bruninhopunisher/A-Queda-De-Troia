#include "fase2.h" 

void ataquePlayer(int* positionX, int* positionY, int positionPlayer, bool* atacando,int* limitAtaque) {
	switch (positionPlayer)
	{
	case 1:
		if (*limitAtaque < 10) {
			*positionY -= 2;
			*limitAtaque += 1;
		}
		else {
			*positionY += 20;
			*limitAtaque = 0;	
			*atacando = false;
		}
		break;
	case 2:
		positionX += 10;
		break;
	case 3: 
		if (*limitAtaque < 10) {
			*positionY += 2;
			*limitAtaque += 1;
		}else{
			if (positionX_espada1 + 20 >= 615 &&
				positionX_espada1 + 20 <= 665 &&
				positionY_espada1 + 91 >= 425 &&
				positionY_espada1 + 91<= 495 && controleJogador == true) {
				vidaRei -= 500;
			}
			*positionY -= 20;
			*limitAtaque = 0;
			*atacando = false;
		}
		break;
	case 4:
		positionX += 10;
		break;
	}
}

void fase2(ALLEGRO_EVENT evento) {
	
	al_draw_bitmap(background_f2, 0, 0, 0);

	//SOLDADOS DE BAIXO
	al_draw_filled_rectangle(135, 565, 185, 635, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(295, 565, 345, 635, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(615, 565, 665, 635, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(935, 565, 985, 635, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(1095, 565, 1145, 635, al_map_rgba(0, 244, 244, 0.5));

	//SOLDADOS DE CIMA
	al_draw_filled_rectangle(135, 100, 185, 170, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(295, 100, 345, 170, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(935, 100, 985, 170, al_map_rgba(0, 244, 244, 0.5));
	al_draw_filled_rectangle(1095, 100, 1145, 170, al_map_rgba(0, 244, 244, 0.5));


	//ATAQUE DO REI
	if (limiteAtaqueR < 10 && ataqueReiTimer == 200) {
		positionY_espadaR -= 2;
		limiteAtaqueR += 1;
		if (positionX_espadaR + 20 >= positionX1_f2 &&
			positionX_espadaR + 20 <= positionX2_f2 &&
			positionY_espadaR >= positionY1_f2 &&
			positionY_espadaR <= positionY2_f2) {
			vidaJogador = 15;
		}
	}
	else {
		if (ataqueReiTimer == 200) {
			positionY_espadaR += 20;
			limiteAtaqueR = 0;
			ataqueReiTimer = 0;
		}
		else {
			ataqueReiTimer += 1;
		}
	}

	//ESPADA REI
	al_draw_bitmap(espada_rei_f2, positionX_espadaR, positionY_espadaR, 0);
	
	//REI DE ESPARTA
	al_draw_filled_rectangle(615, 425, 665, 495, al_map_rgba(0, 244, 244, 0.5));
	
	switch (controleJogador)
	{
	case false:

		//BARRA DE VIDA PARIS
		switch (vidaJogador)
		{
		case 100:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 180, 6, ALLEGRO_ALIGN_CENTRE, "PARIS"); 
			al_draw_bitmap(barra_vida_cheia, 30, 30, 0);
			break;
		case 15:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 180, 6, ALLEGRO_ALIGN_CENTRE, "PARIS");
			al_draw_bitmap(barra_vida_baixa, 30, 30, 0);
			break;
		}

		//BARRA DE VIDA REI MENELAU
		switch (vidaRei)
		{
		case 1000:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1120, 6, ALLEGRO_ALIGN_CENTRE, "REI MENELAU");
			al_draw_bitmap(barra_vidaRei_100, 937, 30, 0);
			break;
		}

		//EVENTO DE TECLA DO JOGADOR
		switch (evento.type)
		{

		case ALLEGRO_EVENT_KEY_DOWN:
			if (evento.keyboard.keycode == ALLEGRO_KEY_UP && vidaJogador == 100) {
				pressionado = 1;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT && vidaJogador == 100) {
				pressionado = 2;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT && vidaJogador == 100) {
				pressionado = 3;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN && vidaJogador == 100) {
				pressionado = 4;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE && vidaJogador == 100) {
				atacando = true;
			}
			break;

		case ALLEGRO_EVENT_KEY_UP:
			if (evento.keyboard.keycode == ALLEGRO_KEY_UP && vidaJogador == 100) {
				ultPressionado = 1;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT && vidaJogador == 100) {
				ultPressionado = 2;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT && vidaJogador == 100) {
				ultPressionado = 3;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN && vidaJogador == 100) {
				ultPressionado = 4;
			}
			if (pressionado == ultPressionado && vidaJogador == 100) {
				pressionado = 0;
				ultPressionado = 0;
			}
			break;
		}

		switch (vidaJogador)
		{

		case 100:
			//MOVIMENTAÇÃO DO PARIS VIDA 100%
			switch (pressionado)
			{
			case 1:
				positionY1_f2 -= 2;
				positionY2_f2 -= 2;
				positionY_espada1 -= 2;
				break;
			case 2:
				positionX1_f2 -= 2;
				positionX2_f2 -= 2;
				positionX_espada1 -= 2;
				break;
			case 3:
				positionX1_f2 += 2;
				positionX2_f2 += 2;
				positionX_espada1 += 2;
				break;
			case 4:
				positionY1_f2 += 2;
				positionY2_f2 += 2;
				positionY_espada1 += 2;
				break;
			}
			//ATAQUE PARIS
			if (atacando == true) {
				ataquePlayer(&positionX_espada1, &positionY_espada1, 3, &atacando, &limiteAtaque);
			}
			break;

		case 15:
			if (positionX1_f2 < 615){
				positionX1_f2 += 1;
				positionX2_f2 += 1;
				positionX_espada1 += 1;
			}
			if (positionX1_f2 > 665 || positionX2_f2 > 665) {
				positionX1_f2 -= 1;
				positionX2_f2 -= 1;
				positionX_espada1 -= 1;
			}
			if (positionY1_f2 > 190) {
				positionY1_f2 -= 1;
				positionY2_f2 -= 1;
				positionY_espada1 -= 1;
			}
			if (positionY1_f2 <= 190) {
				positionX_espada1 = 605;
				positionY_espada1 = 150;
				vidaJogador = 100;
				pressionado = 0;
				ultPressionado = 0;
				controleJogador = true;
			}
		}


		//ESPADA PARIS
		al_draw_bitmap(espada_player1, positionX_espada1, positionY_espada1, 0);

		//PARIS - CONTROLANDO
		switch (pressionado)
		{
		case 0:
			al_draw_bitmap(ParisBaixoNormal, positionX1_f2, positionY1_f2, 0);
			break;
		case 1:
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
			break;
		case 2:
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
			break;
		case 3:
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
			break;
		case 4:
			if (movimento >= 0 && movimento < 20) {
				al_draw_bitmap(ParisBaixoNormal, positionX1_f2, positionY1_f2, 0);
				movimento += 1;
			}
			if (movimento >= 20&& movimento < 40 ) {
				al_draw_bitmap(ParisBaixoEsq, positionX1_f2, positionY1_f2, 0);
				movimento += 1;
			}
			if (movimento == 40) {
				al_draw_bitmap(ParisBaixoEsq, positionX1_f2, positionY1_f2, 0);
				movimento = 0;
			}
		}
		
		//HEITOR
		al_draw_filled_rectangle(positionX1_heitor, positionY1_heitor, positionX2_heitor, positionY2_heitor, al_map_rgba(0, 244, 244, 0.5));

		break;

	case true:


		//BARRA DE VIDA HEITOR
		switch (vidaJogador)
		{
		case 100:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 180, 6, ALLEGRO_ALIGN_CENTRE, "HEITOR");
			al_draw_bitmap(barra_vida_cheia, 30, 30, 0);
			break;

		}

		//BARRA DE VIDA REI MENELAU
		switch (vidaRei)
		{
		case 1000:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1120, 6, ALLEGRO_ALIGN_CENTRE, "REI MENELAU");
			al_draw_bitmap(barra_vidaRei_100, 937, 30, 0);
			break;
		case 500:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1120, 6, ALLEGRO_ALIGN_CENTRE, "REI MENELAU");
			al_draw_bitmap(barra_vidaRei_50, 937, 30, 0);
			break;
		case 0:
			al_draw_text(fonteMenu, al_map_rgb(255, 255, 255), 1120, 6, ALLEGRO_ALIGN_CENTRE, "REI MENELAU");
			al_draw_bitmap(barra_vida_baixa, 937, 30, 0);
			break;
		}

		if (vidaRei == 0) {
			navegacao += 1;
		}

		//EVENTO DE TECLA HEITOR
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
			if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN ) {
				ultPressionado = 4;
			}
			if (pressionado == ultPressionado) {
				pressionado = 0;
				ultPressionado = 0;
			}
			break;
		}

		//MOVIMENTAÇÃO DO HEITOR
		switch (pressionado)
		{
		case 1:
			positionY1_heitor -= 2;
			positionY2_heitor -= 2;
			positionY_espada1 -= 2;
			break;
		case 2:
			positionX1_heitor -= 2;
			positionX2_heitor -= 2;
			positionX_espada1 -= 2;
			break;
		case 3:
			positionX1_heitor += 2;
			positionX2_heitor += 2;
			positionX_espada1 += 2;
			break;
		case 4:
			positionY1_heitor += 2;
			positionY2_heitor += 2;
			positionY_espada1 += 2;
			break;
		}

		//ATAQUE JOGADOR
		if (atacando == true) {
			ataquePlayer(&positionX_espada1, &positionY_espada1, 3, &atacando, &limiteAtaque);
		}

		//ESPADA HEITOR
		al_draw_bitmap(espada_player1, positionX_espada1, positionY_espada1, 0);

		//HEITOR - CONTROLANDO
		al_draw_filled_rectangle(positionX1_heitor, positionY1_heitor, positionX2_heitor, positionY2_heitor, al_map_rgba(0, 244, 244, 0.5));

		//PARIS
		al_draw_filled_rectangle(615, 20, 665, 90, al_map_rgba(0, 244, 244, 1));

		break;
	}

	al_flip_display();
}