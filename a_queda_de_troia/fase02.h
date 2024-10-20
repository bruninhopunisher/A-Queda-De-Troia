#ifndef FASE2_H
#define FASE2_H

#include "lib.h"

void fase2(ALLEGRO_EVENT evento);
void ataquePlayer(int positionX, int* positionY, int positionPlayer, bool* atacando, int* limiteAtaque);

#endif