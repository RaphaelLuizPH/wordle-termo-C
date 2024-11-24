

#ifndef PROCESSARTENTATIVA_H
#define PROCESSARTENTATIVA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backupPalavras.h"
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>

#include "menu.h"
#include "lib.h"



bool processarTentativa(const char *tentativa, const  char *resposta, int *N, int lvl);

char getTecladoJogador();



void converteMaiusculo(char *tentativa);

#endif //PROCESSARTENTATIVA_H
