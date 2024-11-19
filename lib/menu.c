

#include "menu.h"
#include "lib.h"





void displayMenu(jogador_t *jogador, bool *estado) {
    printf("\n\n\n");

    colorir(COR_ROXO);
    printf(" _____ ___ ___ __ __ ___ \n");
    printf(" |_ _| __ | _  \\ \\/ |/ _ \\ \n");
    printf("  | | | _|| /  |\\/| | (_) |\n");
    printf("  |_| |___|_|_ \\_| |_|\\___/ \n");
    colorir(COR_BRANCO);

    printf("\n\n\n");

    printf(" 1. INICIAR\n");

    printf(" 2. ESTATÍSTICAS\n");

    printf(" 3. PROCEDURAL\n");

    printf(" 4. SAIR\n");

    switch(getTecladoJogador()) {
        case '1':
            system("cls");

        colorir(COR_ROXO);
        printf(" _____ ___ ___ __ __ ___ \n");
        printf(" |_ _| __ | _  \\ \\/ |/ _ \\ \n");
        printf("  | | | _|| /  |\\/| | (_) |\n");
        printf("  |_| |___|_|_ \\_| |_|\\___/ \n");
        colorir(COR_BRANCO);

        break;

        case '2':
        //Função para mostrar as estatísticas do jogador
            atualizarEstatisticas(jogador); // Atualiza o arquivo de estatisticas.dat
            mostrarEstatisticas(jogador); //Mostra as estatistics de estatisticas.dat



        case '3':
            jogador->modo = PROCEDURAL;

            break;

        case '4':
        system("cls");
        fflush(stdout);
        if(!continuarJogo(estado, jogador)) {
            Sleep(1000);
            *estado = false;

        } else {
            displayMenu(jogador, estado);
        }

        break;


        default:
            displayMenu(jogador, estado);
    }


};


bool continuarJogo(bool *estado, jogador_t *jogador) {
    char c;

    fflush(stdin);
    colorir(COR_VERDE);
    printf("\nS PARA CONTINUAR\n");
    colorir(COR_VERMELHO);
    printf("\nN PARA SAIR\n");
    colorir(COR_BRANCO);
    colorir(COR_AMARELO);
    printf("\nM PARA MENU PRINCIPAL\n");
    colorir(COR_BRANCO);
    c = getTecladoJogador();


    if (c == 's' || c == 'S') {
        system("cls");
        return true;
    }

    if(c == 'n' || c == 'N') {
        return false;
    }

    if(c == 'M' || c == 'm') {
        system("cls");
        displayMenu(jogador, estado);
        return true;
    }
    system("cls");
    return true;
}



void mostrarEstatisticas(jogador_t *jogador){
    FILE *arq1;
    char texto[256];

    arq1 = fopen("estatisticas.dat", "rb");

    if (arq1 == NULL){
        printf("Erro na abertura do arquivo");
        return;
    }

    fseek(arq1, 0, SEEK_SET);  // Move para o in�cio do arquivo antes de ler
    size_t bytesLidos = fread(texto, sizeof(char), sizeof(texto) - 1, arq1);
    if (bytesLidos > 0) {
        texto[bytesLidos] = '\0'; // Garantir que o texto esteja sempre null-terminated
        printf("%s", texto);
    }


    fclose(arq1);

}

void atualizarEstatisticas(jogador_t *jogador){
    FILE *arq1;
    char texto[256];

    arq1 = fopen("estatisticas.dat", "wb"); //Abrir o arquivo estatisticas e escrever em binário
    if (arq1 == NULL){
        printf("Erro na abertura do arquivo");
        return;
    }
    sprintf(texto, "\n--- Estatísticas do Jogo ---\nJogador: %s\nPontos %d\nLevel record: %hd\n\n",
            jogador->name, jogador->pontos, jogador->lvlAtual);

    fwrite(texto, sizeof(char), strlen(texto), arq1);

    fclose(arq1);
}
