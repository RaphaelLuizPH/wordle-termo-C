

#include "menu.h"
#include "lib.h"





void displayMenu(jogador_t *jogador) {
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

    printf(" \n\n\n");
    colorir(COR_VERDE);
    printf("========= REGRAS DO JOGO TERMO/WORDLE =========\n");
    colorir(COR_BRANCO);
    printf("1. Objetivo do Jogo: Adivinhe a palavra secreta em até 6 tentativas.\n");
    printf("2. Feedback de Palpite:\n");
    colorir(COR_VERDE);
    printf("   - Letra correta na posição correta: A letra é mostrada em verde.\n");
    colorir(COR_AMARELO);
    printf("   - Letra correta na posição errada: A letra é mostrada em amarelo.\n");
    colorir(COR_VERMELHO);
    printf("   - Letra incorreta: A letra é mostrada em vermelho.\n");
    colorir(COR_BRANCO);
    printf("3. Número de Tentativas: Você tem 6 tentativas para adivinhar a palavra secreta.\n");
    colorir(COR_VERDE);
    printf("===============================================\n");
    colorir(COR_BRANCO);
    printf(" \n\n\n");

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

            mostrarEstatisticas(jogador); //Mostra as estatistics de estatisticas.bin

            break;


        case '3':
            jogador->modo = PROCEDURAL;

            break;

        case '4':
        system("cls");
        fflush(stdout);
        if(!continuarJogo(&*jogador)) {
            jogador->estado = false;
            break;
        }
            displayMenu(jogador);


        break;


        default:
            system("cls");
            displayMenu(jogador);
        break;
    }









};


bool continuarJogo(jogador_t *jogador) {
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
        displayMenu(jogador);
        atualizarEstatisticas(jogador); // Atualiza as estatisticas do jogador quando voltar ao menu
        return true;
    }

    system("cls");
    return true;
}



void mostrarEstatisticas(jogador_t *jogador){
    char texto[256];    
    FILE *arq;    
    system("cls");

    arq = fopen("cmake-build-debug/estatisticas.bin", "rb");

    if (arq == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

    fread(texto, sizof(char), sizof(arq), arq);

        printf("%s", texto);

    fclose(arq);
    continuarJogo(jogador);
}

void atualizarEstatisticas(jogador_t *jogador){
    char texto[256];
    FILE *arq;

    arq = fopen("cmake-build-debug/estatisticas.bin", "a");

    if (arq == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

    //Usa o snprintf para limitar o tamanho do vetor texto para não ultrapassar 
     snprintf(texto,sizeof(texto), "\n--- Estatísticas do Jogo ---\nJogador: %s\nPontos %d\nLevel: %d\n\n",
            jogador->name, jogador->pontos, jogador->lvlAtual+1);

    // escreve o texto no arquivo
    // size_t mostra o tamanho digitado em bytes 
    size_t bytesEscritos = fwrite(texto, sizeof(char), strlen(texto), arq); // Usa-se o strlen texto para escrever de acordo com o tamanho de caracteres do vetor texto.
    
    // verifica se o texto escrito no arquivo é diferente do vetor texto
        if (bytesEscritos != strlen(texto)){ // Os bytesEscritos serão apenas a quantidade de bytes dos caracteres do vetor texto, não se compara com o sizeof(texto), pois este mostrará o tamanho em bytes totais do buffer
            printf("Erro na escrita do arquivo!!!\n");
        }
    
    fclose(arq); 
}
