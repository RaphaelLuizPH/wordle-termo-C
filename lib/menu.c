

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
    jogador_t dados_binario;
    system("cls");

    arq = fopen("cmake-build-debug/estatisticas.bin", "rb");

    if (arq == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

   // Lê os dados binários do arquivo
    while (fread(&dados_binario, sizeof(jogador_t), 1, arq) == 1) {
        printf("\n--- Estatísticas do Jogo ---\n");
        printf("Jogador: %s\n", dados_binario.name);
        printf("Pontos: %d\n", dados_binario.pontos);
        printf("Level: %d\n\n", dados_binario.lvlAtual + 1);
    }

    fclose(arq);
    continuarJogo(jogador);
}

void atualizarEstatisticas(jogador_t *jogador){
    char texto[256];
    FILE *arq;

    arq = fopen("cmake-build-debug/estatisticas.bin", "ab");

    if (arq == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }


    // Primeiro o fwrite é executado e o if verifica se não deu algum erro
    if(fwrite(jogador, sizeof(jogador_t), 1, arq) != 1) { //Caso o fwrite seja bem sucedido ele retornará 1, caso não ele mostrará essa mensagem de erro, fechará o arquivo e sairá da função.
        printf("Erro ao escrever no arquivo\n");
        fclose(arq);
        return;
    }

    fclose(arq); 
    

}
