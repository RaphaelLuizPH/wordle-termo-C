
#ifndef MENU_H
#define MENU_H

#include "lib.h"

typedef enum { // enum para definir o modo de jogo
    LINEAR,
    PROCEDURAL,
} modo_t;


typedef struct Jogador {
    char name[50];
    int pontos;
    int lvlAtual;
    bool estado;
    modo_t modo;
    FILE *stats;
} jogador_t;




void displayMenu(jogador_t *jogador);


bool continuarJogo(jogador_t *jogador);


void mostrarEstatisticas(jogador_t *jogador);

void atualizarEstatisticas(jogador_t *jogador);



#endif //MENU_H
