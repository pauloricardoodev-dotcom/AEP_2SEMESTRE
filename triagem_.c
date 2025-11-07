#include <stdio.h>  
#include <stdlib.h> 
#include <ctype.h>
#include <string.h> 
#include <locale.h>  

// ------------------- Variáveis globais -------------------
char quadroPaciente[100], urgencia[100], recomendacoes[100], conclusao[100], orientacoes[500];
char nome[100], telefone[20];
int idade;
int opcao = 0, pontos = 0;

// ------------------- MÉTODOS -------------------
void menu();
void pause();
void informacoesPaciente();
void iniciarTriagem();
void exibirPrognostico();
void observacoes();

int perguntasTriagem(char *mensagem);
char* urgenciaPontuacao(int pontuacao);

// ------------------- EXECUÇÃO -------------------
int main() {

    setlocale(LC_ALL,"Portuguese");

    printf("\n");
    printf("\n                                        Olá! Seja muito bem-vindo ao TRIATE(C)\n");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    while(opcao != 5){
        menu();
    }

    printf("\nTRIATE(C) Finalizado!\n");

    return 0;
}

void pause(){
    char enter=' ';
    printf("\n");
    printf("\tENTER para continuar ");
    scanf("%c",&enter);
}


// ------------------- MENU -------------------
void menu(){
	setlocale(LC_ALL,"Portuguese");
    printf("\n\tM E N U\n");
    printf("\n        [1]\tColetar informações do Paciente\n");
    printf("        [2]\tIniciar Triagem\n");
    printf("        [3]\tPrognóstico\n");
    printf("        [4]\tObservações\n");
    printf("        [5]\tEncerrar programa\n");
    printf("\n\tOpção: ");

    scanf("%d",&opcao);
    getchar();    // para consumir a quebra de linha

    switch (opcao){
        case 1:
            informacoesPaciente();
            pause(); 
            break;
        case 2:
            iniciarTriagem();
            pause();
            break;
        case 3:
            exibirPrognostico();
            pause();
            break;
        case 4:
            observacoes();
            pause();
            break;
        case 5:
            break;
        default:
            printf("\n\tOpção inválida!\n");
            pause();
            break;
    }

}

// ------------------- INFORMAÇÕES DO PACIENTE -------------------
void informacoesPaciente(){

    char nomeTemp[100];
    int i;

    system("cls");
    setlocale(LC_ALL,"Portuguese");
    printf("\nNOME DO PACIENTE: ");
    fgets(nomeTemp,sizeof(nomeTemp),stdin);
    nomeTemp[strcspn(nomeTemp,"\n")] = '\0';

    for(i=0;i<strlen(nomeTemp);i++){
        nome[i] = toupper(nomeTemp[i]);
    }

    printf("IDADE DO PACIENTE: ");
    scanf("%d",&idade);
    getchar(); // limpar buffer

    printf("TELEFONE PARA CONTATO (DD) XXXX-XXXX: ");
    fgets(telefone,sizeof(telefone),stdin);
    telefone[strcspn(telefone,"\n")] = '\0';
}

// ------------------- ÁRVORE DE DECISÃO -------------------
void iniciarTriagem() {
    system("cls");
    setlocale(LC_ALL,"Portuguese");

    int febre       = perguntasTriagem("POSSUI FEBRE?");
    int tosse       = perguntasTriagem("POSSUI TOSSE?");
    int dorGarganta = perguntasTriagem("POSSUI DOR DE GARGANTA?");
    int faltaAr     = perguntasTriagem("POSSUI FALTA DE AR?");
    int dorCabeca   = perguntasTriagem("POSSUI DOR DE CABECA?");
    int fraqueza    = perguntasTriagem("SENTE FRAQUEZA?");
    int contato     = perguntasTriagem("TEVE CONTATO COM PESSOA DOENTE?");

    printf("\n=== RESULTADO DA TRIAGEM ===\n\n");

    // ------------------- ÁRVORE DE DECISÃO + PRIORIDADE -------------------
    if (faltaAr) {
        strcpy(quadroPaciente, "POSSIVEL CASO GRAVE");
        strcpy(urgencia, "ALTISSIMA");
        pontos = 100;
        urgenciaPontuacao(pontos);
        strcpy(recomendacoes, "ENCAMINHAR PARA ATENDIMENTO IMEDIATO");
        strcpy(conclusao, "CRITICO");

    } else if (febre && tosse && fraqueza) {
        strcpy(quadroPaciente, "SINAIS COMPATIVEIS COM INFECCAO RESPIRATORIA");
        strcpy(urgencia, "ALTA");
        pontos = 80;
        urgenciaPontuacao(pontos);
        strcpy(recomendacoes, "AVALIACAO PRESENCIAL");
        strcpy(conclusao, "GRAVE");

    } else if (febre && contato) {
        strcpy(quadroPaciente, "SUSPEITA DE QUADRO VIRAL");
        strcpy(urgencia, "MEDIA");
        pontos = 60;
        urgenciaPontuacao(pontos);
        strcpy(recomendacoes, "ORIENTAR ISOLAMENTO E TESTAGEM");
        strcpy(conclusao, "MODERADO");

    } else if (dorGarganta && dorCabeca) {
        
        strcpy(quadroPaciente, "POSSIVEL GRIPE COMUM");
        //strcpy(urgencia, "BAIXA");
        pontos = 40;
        urgenciaPontuacao(pontos);
        strcpy(recomendacoes, "HIDRATACAO, REPOUSO E MONITORAMENTO");
        strcpy(conclusao, "LEVE");

    } else if (tosse || dorGarganta || dorCabeca) {
        strcpy(quadroPaciente, "QUADRO LEVE");
        strcpy(urgencia, "BAIXA");
        pontos = 20;
        urgenciaPontuacao(pontos);
        strcpy(recomendacoes, "CUIDADOS EM CASA");
        strcpy(conclusao, "LEVE");

    } else {
        strcpy(quadroPaciente, "SEM INDICATIVO GRIPAL");
        strcpy(urgencia, "SEM URGÊNCIA");
        pontos = 0;
        urgenciaPontuacao(pontos);
        strcpy(recomendacoes, "VIDA NORMAL");
        strcpy(conclusao, "BOM");
    }

    // printf("Quadro do paciente: %s\n", quadroPaciente);
    // printf("Urgência: %s\n", urgencia);
    // printf("Recomendações: %s\n", recomendacoes);
    // printf("Conclusão: %s\n\n", conclusao);
   
}

// ------------------- PERGUNTAS SIM/NÃO -------------------
int perguntasTriagem(char *mensagem) {
	setlocale(LC_ALL,"Portuguese");
    char resposta = ' ';

    while (1) {
        printf("%s (S/N): ", mensagem);
        scanf(" %c", &resposta);
        getchar(); // limpar buffer
        resposta = toupper(resposta);

        if(resposta == 'S') return 1;
        if(resposta == 'N') return 0;

        printf("Entrada inválida! Digite S ou N.\n\n");
    }
}

// ------------------- PROGNÓSTICO -------------------
void exibirPrognostico() {
	setlocale(LC_ALL,"Portuguese");
    system("cls");
    printf("\n\n===== PROGNÓSTICO DO PACIENTE =====\n");
    printf("Condição do Paciente: %s\n", quadroPaciente);
    printf("Nível de Urgência: %s\n", urgencia);
    printf("Recomendações Iniciais: %s\n", recomendacoes);
    printf("Conclusão: %s\n", conclusao);
    printf("====================================\n\n");
}

// ------------------- DICAS -------------------
void observacoes() {
	setlocale(LC_ALL,"Portuguese");
    system("cls");
    if (strcmp(conclusao, "CRITICO") == 0) {  
        strcpy(orientacoes,
           "BUSCAR UTI IMEDIATAMENTE; EVITAR ESFORCOS; ACOMPANHAMENTO CONTINUO; "
           "DOCUMENTACAO DISPONIVEL; PREPARAR TRANSFERENCIA SE NECESSARIO.");
    } 
    else if (strcmp(conclusao, "GRAVE") == 0) {  
        strcpy(orientacoes,
           "MONITORAR SINAIS; SEGUIR TRATAMENTO; HIDRATACAO; REPOUSO TOTAL; "
           "NOTIFICAR AGRAVAMENTO AO MEDICO.");
    } 
    else if (strcmp(conclusao, "MODERADO") == 0) {  
        strcpy(orientacoes,
           "TRATAMENTO; REPOUSO MODERADO; HIDRATACAO; REAVALIAR EM 48-72H; "
           "ISOLAMENTO SE NECESSARIO.");
    } 
    else if (strcmp(conclusao, "LEVE") == 0 || strcmp(conclusao, "BOM") == 0) {  
        strcpy(orientacoes,
           "HIDRATACAO; REPOUSO LEVE; ALIMENTACAO SAUDAVEL; MONITORAR MELHORA.");
    } 
    else {
        strcpy(orientacoes, "SEM OBSERVACOES DISPONIVEIS.");
    }


    printf("\n\n===== ORIENTACOES =====\n");
    printf("O Paciente %s\n",nome);
    printf("Idade: %d\n",idade);
    printf("Contato: %s\n",telefone);
    printf("Oberservações: %s\n", orientacoes);
    printf("===============================\n\n");
}

char* urgenciaPontuacao(int pontuacao){
	setlocale(LC_ALL,"Portuguese");
    
    switch (pontuacao)
    {
    case 100:
        strcpy(urgencia,"100 PONTOS - URGÊNCIA CRÍTICA");
        break;
    case 80:
        strcpy(urgencia,"80 PONTOS - URGÊNCIA ALTA");
        break;
    case 60:
        strcpy(urgencia,"60 PONTOS - URGÊNCIA MÉDIA");
        break;
    case 40:
        strcpy(urgencia,"40 PONTOS - URGÊNCIA BAIXA");
        break;
    case 20:
        strcpy(urgencia,"20 PONTOS - URGÊNCIA LEVE");
        break;
    case 0:
        strcpy(urgencia,"0 PONTOS - SEM URGÊNCIA ");
        break;
    default:
    
        break;
    }
}



