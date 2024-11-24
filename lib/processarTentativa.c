

#include "processarTentativa.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "cores.h"
#include "lib.h"

void converteMaiusculo(char *tentativa) {
    int tamanho = strlen(tentativa);  // Calcula o comprimento da string uma única vez
    for (int i = 0; i < tamanho; i++) {
        if (tentativa[i] >= 'a' && tentativa[i] <= 'z') {
            tentativa[i] -= 32;  // Converte para maiúscula
        }
    }
}


bool processarTentativa(const char *tentativa, const  char *resposta, int *N, int lvl) {

    char pista[11] = {'_','_','_','_','_','_','_','_','_','_','\0'};
    bool pistaTentativa[10] = {false, false, false, false, false, false, false, false, false, false};

    converteMaiusculo(tentativa);


    if(strlen(tentativa) != 4 + lvl) { // Verifica se a palavra tem 5 letras
        printf("ERRO! Digite uma palavra com %d letras!\n", 4 + lvl);
    } else {
        (*N)++; //Incrementa as tentativas
        if (strcmp(tentativa, resposta) == 0) { // Verifica se são iguais
            return true;
        }
        // Verifica se a letra esta na posicao correta
        for (int i = 0; i < 4 + lvl; i++) {
            if (tentativa[i] == resposta[i]) {
                pista[i] = 'A';
                pistaTentativa[i] = true;

            }
        }

        // Verifica se a letra existe mas em outra posicao
        for (int i = 0; i < 4 + lvl; i++) {
            if (pista[i] == '_') {
                for (int j = 0; j < 4 + lvl; j++) {
                    if (tentativa[i] == resposta[j] && !pistaTentativa[j]) {
                        pista[i] = 'Q';
                        pistaTentativa[j] = true;
                        break; // Acaba o loop para evitar varias pistas
                    }

                }
            }

        }
        printf("\n-----------------------------------------------------\n");

        for (int i = 0; i < 4 + lvl; i++) {
            if (pista[i] == 'A') {
                colorir(2);
                printf("%c", tentativa[i]);
                colorir(7);
            } else if (pista[i] == '_') {
                colorir(4);
                printf("%c", tentativa[i]);
                colorir(7);
            } else {
                colorir(6);
                printf("%c", tentativa[i]);
                colorir(7);
            }

        }

        printf("\n-----------------------------------------------------\n");

    }




    return false;

    }



char getTecladoJogador() {
    return _getch();
}



