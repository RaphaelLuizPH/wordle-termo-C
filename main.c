#include "lib/lib.h" // Inclusão de uma biblioteca

const int MAX_PALAVRAS = 301; // Definição de uma constante para o número máximo de palavras






        int main() {
//função que inicializa o programa em C
        // Configurações de console para suportar caracteres UTF-8
        SetConsoleCP(CP_UTF8); //Configuração de codificação de carateres do console de entrada
        SetConsoleOutputCP(CP_UTF8); //Configuração de codificação de carateres do console de saída
        setlocale(LC_ALL, ".UTF8"); //função da biblioteca para a configuração de localidade do programa

        // Variáveis de controle do estado do jogo
        bool estadoJogo = true; // Flag para verificar se o jogo está ativo ou não
        bool *state = &estadoJogo; //Ponteiro para acessar e modificar o estado do jogo

        jogador_t *jogador = malloc(sizeof(jogador_t)); // Aloca memória para o jogador inicializa seus pontos com 0
        jogador->pontos = 0; //inicializa o jogo com os pontos do jogador com 0 pontos
        jogador->lvlAtual = 0;
        jogador->modo = LINEAR;
        displayMenu(jogador, state); //Exibe o menu inicial do jogo








        srand(time(NULL)); // Inicializa o gerador de números aleatórios com a semente baseada no tempo atual


        printf("\n\n\n\n\n");
        // Selecionando uma palavra aleatória da lista

        // Inicia o loop principal do jogo
        while(estadoJogo) {

            char **listaPalavras = calloc(MAX_PALAVRAS, sizeof(char*)); // Aloca memória para a lista de palavras e para uma palavra temporária
            char *palavra = malloc(10 * sizeof(char)); // Palavras têm até 5 caracteres (6 para o terminador '\0')
            int contadorPalavra = 0; // Contador para o número de palavras lidas do arquivo
            FILE *arqPalavras;

            if(jogador->pontos > (jogador->lvlAtual+1) * 20 && jogador->modo == LINEAR) {
                jogador->lvlAtual++;
            }

            if(jogador->modo == PROCEDURAL) {
                jogador->lvlAtual = rand() % 4;
            }

            switch(jogador->lvlAtual) {

                case 0:

                arqPalavras = fopen("../palavras0.txt", "r"); // Abrindo o arquivo de palavras

                // Se as palavras não forem carregadas
                if (arqPalavras == NULL) {
                    printf("Erro abrindo lista de palavras\n\n \n \n \n");
                    fclose(arqPalavras); // Fecha o arquivo caso o arquivo não abra (pois o fopen falhou)
                }

                arqPalavras = fopen("../palavras0.txt", "r"); //Reabre o arquivo, caso tenha sido gerado, para leitura após o backup

                // Loops para ler o arquivo e colocar as palavras em uma lista
                while(fscanf(arqPalavras, "%s", palavra) != EOF) {
                    listaPalavras[contadorPalavra] = palavra; // Armazena cada palavra lida na lista
                    contadorPalavra++; // Incrementa o contador de palavras
                    palavra = malloc(5 * sizeof(char)); // Aloca novamente a memória para a próxima palavra

                    fflush(stdout); // Garante que a saída seja exibida imediatamente

                }
                system("cls"); // Limpa a tela após o carregamento

                fclose(arqPalavras); // Fecha o arquivo de palavras após o processamento

                break;

                case 1:
                    arqPalavras = fopen("../palavras1.txt", "r"); // Abrindo o arquivo de palavras

                // Se as palavras não forem carregadas
                if (arqPalavras == NULL) {
                    printf("Erro abrindo lista de palavras\n \n \n \n \n");
                    fclose(arqPalavras); // Fecha o arquivo caso o arquivo não abra (pois o fopen falhou)

                }

                arqPalavras = fopen("../palavras1.txt", "r"); //Reabre o arquivo, caso tenha sido gerado, para leitura após o backup

                // Loops para ler o arquivo e colocar as palavras em uma lista
                while(fscanf(arqPalavras, "%s", palavra) != EOF) {
                    listaPalavras[contadorPalavra] = palavra; // Armazena cada palavra lida na lista
                    contadorPalavra++; // Incrementa o contador de palavras
                    palavra = malloc(6 * sizeof(char)); // Aloca novamente a memória para a próxima palavra

                    fflush(stdout); // Garante que a saída seja exibida imediatamente

                }
                system("cls"); // Limpa a tela após o carregamento



                fclose(arqPalavras); // Fecha o arquivo de palavras após o processamento
                break;

                case 2:
                    arqPalavras = fopen("../palavras2.txt", "r"); // Abrindo o arquivo de palavras

                // Se as palavras não forem carregadas
                if (arqPalavras == NULL) {
                    printf("Erro abrindo lista de palavras\n \n \n \n \n");
                    fclose(arqPalavras); // Fecha o arquivo caso o arquivo não abra (pois o fopen falhou)

                }

                arqPalavras = fopen("../palavras2.txt", "r"); //Reabre o arquivo, caso tenha sido gerado, para leitura após o backup

                // Loops para ler o arquivo e colocar as palavras em uma lista
                while(fscanf(arqPalavras, "%s", palavra) != EOF) {
                    listaPalavras[contadorPalavra] = palavra; // Armazena cada palavra lida na lista
                    contadorPalavra++; // Incrementa o contador de palavras
                    palavra = malloc(7 * sizeof(char)); // Aloca novamente a memória para a próxima palavra

                    fflush(stdout); // Garante que a saída seja exibida imediatamente

                }
                system("cls"); // Limpa a tela após o carregamento



                fclose(arqPalavras); // Fecha o arquivo de palavras após o processamento
                break;


                case 3:
                    arqPalavras = fopen("../palavras3.txt", "r"); // Abrindo o arquivo de palavras

                // Se as palavras não forem carregadas
                if (arqPalavras == NULL) {
                    printf("Erro abrindo lista de palavras\n \n \n \n \n");
                    fclose(arqPalavras); // Fecha o arquivo caso o arquivo não abra (pois o fopen falhou)

                }

                arqPalavras = fopen("../palavras3.txt", "r"); //Reabre o arquivo, caso tenha sido gerado, para leitura após o backup

                // Loops para ler o arquivo e colocar as palavras em uma lista
                while(fscanf(arqPalavras, "%s", palavra) != EOF) {
                    listaPalavras[contadorPalavra] = palavra; // Armazena cada palavra lida na lista
                    contadorPalavra++; // Incrementa o contador de palavras
                    palavra = malloc(8 * sizeof(char)); // Aloca novamente a memória para a próxima palavra

                    fflush(stdout); // Garante que a saída seja exibida imediatamente

                }
                system("cls"); // Limpa a tela após o carregamento



                fclose(arqPalavras); // Fecha o arquivo de palavras após o processamento
                break;

                case 4:
                    arqPalavras = fopen("../palavras4.txt", "r"); // Abrindo o arquivo de palavras

                // Se as palavras não forem carregadas
                if (arqPalavras == NULL) {
                    printf("Erro abrindo lista de palavras\n \n \n \n \n");
                    fclose(arqPalavras); // Fecha o arquivo caso o arquivo não abra (pois o fopen falhou)

                }

                arqPalavras = fopen("../palavras4.txt", "r"); //Reabre o arquivo, caso tenha sido gerado, para leitura após o backup

                // Loops para ler o arquivo e colocar as palavras em uma lista
                while(fscanf(arqPalavras, "%s", palavra) != EOF) {
                    listaPalavras[contadorPalavra] = palavra; // Armazena cada palavra lida na lista
                    contadorPalavra++; // Incrementa o contador de palavras
                    palavra = malloc(9 * sizeof(char)); // Aloca novamente a memória para a próxima palavra

                    fflush(stdout); // Garante que a saída seja exibida imediatamente

                }
                system("cls"); // Limpa a tela após o carregamento



                fclose(arqPalavras); // Fecha o arquivo de palavras após o processamento
                break;



            }


            char *resposta = listaPalavras[rand() % contadorPalavra]; // Seleciona uma palavra aleatória da lista
            int NumeroTentativas = 0; // Contador de tentativas feitas pelo jogador
            int *N = &NumeroTentativas; // Ponteiro para o contador de tentativas
            bool acertou_palavras = false; // Flag para verificar se o jogador acertou a palavra
            char *tentativa = malloc((10 + jogador->lvlAtual) * sizeof(char)); // Aloca memória para armazenar a tentativa do jogador

            colorir(COR_ROXO); // Exibe a arte do jogo
            printf(" _____ ___ ___ __ __ ___ \n");
            printf(" |_ _| __ | _  \\ \\/ |/ _ \\ \n");
            printf("  | | | _|| /  |\\/| | (_) |\n");
            printf("  |_| |___|_|_ \\_| |_|\\___/ \n");
            colorir(COR_BRANCO);
            printf("\n\n\n");
            colorir(COR_AMARELO);
            printf("LEVEL ATUAL: %d\n", jogador->lvlAtual + 1);
            colorir(COR_VERDE_CLARO);
            printf("PONTOS: %d", jogador->pontos);
            printf("\n\n\n\n\n");
            colorir(COR_BRANCO);
            // Loop de tentativas de adivinhar a palavra
            while(NumeroTentativas < 6 && !acertou_palavras) {
                fflush(stdin); // Limpa o buffer de entrada
                printf("\n\n");

                printf("Digite uma palavra com %d letras: \n", jogador->lvlAtual + 4);
                fgets(tentativa, 10 + jogador->lvlAtual, stdin);
                tentativa[strcspn(tentativa, "\n")] = 0;

                acertou_palavras = processarTentativa(tentativa, resposta, N, jogador->lvlAtual); // Processa a tentativa e verifica se a palavra está correta


                printf("Tentativas: %d\n", NumeroTentativas); // Exibe o número de tentativas restantes
            }

            // Se o jogador acertar a palavra
            if (acertou_palavras) {
                colorir(COR_VERDE); // Altera a cor
                printf("-----------------------------------------------------\n");
                printf("               A PALAVRA ESTÁ CORRETA!                \n");
                printf("-----------------------------------------------------\n");
                colorir(COR_BRANCO);


                jogador->pontos += (7 - NumeroTentativas); // A pontuação do jogador aumenta de acordo com as tentativas usadas
                colorir(COR_BRANCO);
                printf("\nPontução da rodada: ");
                colorir(COR_VERDE);
                printf("%d\n", 7 - NumeroTentativas);  // Exibe a pontuação
                colorir(COR_BRANCO);
                printf("Pontuação total do jogador: ");
                colorir(COR_VERDE);
                printf("%d\n", jogador->pontos); // Exibe a pontuação total
                colorir(COR_ROSA);
                printf("Próxima fase em: %d pontos", ((jogador->lvlAtual+1) * 20) - jogador->pontos);
                colorir(COR_BRANCO);

              // Caso o jogador não acertar
            } else {
                colorir(COR_VERMELHO); // Altera a cor para vermelho
                printf("-----------------------------------------------------\n");
                printf("               FIM DE JOGO! SEM MAIS TENTATIVAS.       \n ");
                printf("-----------------------------------------------------\n");
                colorir(COR_VERDE);
                printf("-----------------------RESPOSTA: %s------------\n", resposta); // Exibe a resposta correta
                colorir(COR_BRANCO);


                colorir(COR_BRANCO);
                printf("\nPontução da rodada: ");
                colorir(COR_VERDE);
                printf("%d\n", 0); // Exibe a pontuação da partida
                colorir(COR_BRANCO);
                printf("Pontuação total do jogador:");
                colorir(COR_VERDE);
                printf("%d\n", jogador->pontos); // Exibe a pontuação total
                colorir(COR_BRANCO);
                colorir(COR_ROSA);
                printf("Próxima fase em: %d pontos", ((jogador->lvlAtual+1) * 20) - jogador->pontos);
                colorir(COR_BRANCO);


            }

            printf("\n\n\n"); // Pergunta se o jogador deseja continuar jogando


            // Função que verifica se o jogador deseja continuar jogo
            if(!continuarJogo(&estadoJogo, jogador)) {
                free(listaPalavras); // Libera a memória alocada para a lista de palavras
                free(palavra); // Libera a memória alocada para a palavra temporária
                free(jogador); // Libera a memória alocada para o jogador
                free(tentativa); // Libera a memória alocada para a tentativa
                break; //Encerra o jogo

            }




        }







    return 0; //o retorno 0 serve para indicar que o programa terminou sem erros

}

/*
Agradecimentos:
- Erica Jaislane Campos Fernandes: Ajudou na implementação da lógica de verificação das palavras.
- Gabriel Rodrigues Alves: Contribuiu com melhorias na estrutura e desempenho do código.
- Lucas Ataide Martins: Auxiliou na revisão do código e no desenvolvimento de funções auxiliares.
- Nicole Reinaldo de Carvalho: Responsável pelos testes de funcionalidade e correção de erros.
- Raphael Luiz de Sousa: Criou a ideia inicial e a estrutura geral do jogo.

Agradecemos a colaboração de todos os envolvidos no projeto!
*/

