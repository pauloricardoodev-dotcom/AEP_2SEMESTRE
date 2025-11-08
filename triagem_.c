#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

// Mantidos globais essenciais
char quadroPaciente[80], urgencia[80], recomendacoes[200], conclusao[40], orientacoes[500], nome[100], telefone[20];
int idade, opcao = 0, pontos = 0;

// ---------- PROTÓTIPOS ----------
void menu();
void pause();
void informacoesPaciente();
void iniciarTriagem();
void exibirPrognostico();
void observacoes();
int perguntasTriagem(char *msg);
void formatarTelefone(char *tel);
void calculoUrgencia(int pontos);

// ---------- MAIN ----------
int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("\n");
    printf("\n                                        Olá! Seja muito bem-vindo ao TRIATE(C)\n");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    while (opcao != 5)
    {
        menu();
        system("cls");
    }

    printf("\nTRIATE(C) Finalizado.\n");
    return 0;
}

// ---------- FUNÇÕES ----------
void pause()
{

    printf("ENTER para continuar");
    getchar();//conosme a entrada e limpa o buffer
}


void menu()
{
    printf("\n\tM E N U\n");
    printf("[1] Coletar informações do Paciente\n");
    printf("[2] Iniciar Triagem\n");
    printf("[3] Visualizar prognóstico\n");
    printf("[4] Visualizar Observações\n");
    printf("[5] Encerrar\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    getchar();//limpa o buffer

    switch (opcao)
    {
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
        printf("Opção inválida!\n");
        pause();
    }
}

void informacoesPaciente()
{
    system("cls");

    char nomeTmp[100];
    int i;

    printf("\nNOME: ");
    fgets(nomeTmp, sizeof(nomeTmp), stdin);
    nomeTmp[strcspn(nomeTmp, "\n")] = '\0';

    for(i=0;i<strlen(nomeTmp);i++){
        nome[i] = toupper(nomeTmp[i]);
    }


    printf("IDADE: ");
    scanf("%d", &idade);
    getchar();//limpa o buffer

    printf("TELEFONE: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    printf("\n==Informções Registradas==\n");
}

// ----------------- TRIAGEM -----------------
void iniciarTriagem()
{
    system("cls");

    //int pontos = 0;
    int febre = perguntasTriagem("Febre?");
    int tosse = perguntasTriagem("Tosse?");
    int dorG = perguntasTriagem("Dor de garganta?");
    int ar = perguntasTriagem("Falta de ar?");
    int contato = perguntasTriagem("Contato com doente?");
    int dorCab = perguntasTriagem("Dor de cabeça?");
    int fraq = perguntasTriagem("Fraqueza?");

    pontos += febre + tosse + dorG + ar + contato + dorCab + fraq;

    // Critérios especiais
    if (ar) pontos += 40;
    if (febre && tosse) pontos += 30;
    if (contato) pontos += 20;

    // Idade influencia
    if (idade <= 10 || idade >= 60) pontos += 15;

    // ----- ÁRVORE REFINADA -----
    if (pontos >= 90)
    {
        strcpy(quadroPaciente, "ALTO RISCO");
        strcpy(recomendacoes, "ATENDIMENTO IMEDIATO");
        strcpy(conclusao, "CRITICO");
    }
    else if (pontos >= 70)
    {
        strcpy(quadroPaciente, "RISCO MODERADO-ALTO");
        strcpy(recomendacoes, "AVALIAÇÃO PRESENCIAL");
        strcpy(conclusao, "GRAVE");
    }
    else if (pontos >= 45)
    {
        strcpy(quadroPaciente, "RISCO MODERADO");
        strcpy(recomendacoes, "ISOLAMENTO E MONITORAMENTO");
        strcpy(conclusao, "MODERADO");
    }
    else if (pontos >= 20)
    {
        strcpy(quadroPaciente, "QUADRO LEVE");
        strcpy(recomendacoes, "HIDRATAÇÃO E REPOUSO");
        strcpy(conclusao, "LEVE");
    }
    else
    {
        strcpy(quadroPaciente, "SEM INDICATIVOS");
        strcpy(recomendacoes, "VIDA NORMAL");
        strcpy(conclusao, "BOM");
    }

    calculoUrgencia(pontos);

    printf("==Tragem Finalizada==\n\n");
}

int perguntasTriagem(char *msg)
{
    char resposta;
    int nivel;

    while (1)
    {
        printf("%s (S/N): ", msg);
        scanf(" %c", &resposta);
        getchar();//limpar buffer

        if (toupper(resposta) == 'S')
        {
           do {
                printf("1=Leve / 2=Moderado / 3=Forte): ");
                scanf("%d", &nivel);
                getchar();// limpar buffer

                if(nivel < 1 || nivel > 3){
                    printf(" intensidade inválida, tente novamente\n");
                }
            }
            while (nivel < 1 || nivel > 3);

            printf("\n\n");
            return nivel * 10;
        }
        if (toupper(resposta) == 'N'){
            return 0;
        }

        printf("Entrada inválida!\n");
    }

}


void exibirPrognostico()
{
    system("cls");

    printf("\n=== PROGNÓSTICO ===\n");
    printf("Paciente: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("\n===================\n");
    printf("Quadro: %s\n", quadroPaciente);
    printf("Urgência: %s\n", urgencia);
    printf("Recomendações: %s\n", recomendacoes);
    printf("Conclusão: %s\n\n", conclusao);
}

// ----------------- OBSERVAÇÕES -----------------
void observacoes()
{
    system("cls");

    if (strcmp(conclusao, "CRITICO")==0)
    {
        strcpy(orientacoes,
                 "Paciente em estado CRÍTICO. AÇÕES IMEDIATAS:\n"
                 "- Encaminhar para emergência/UTI imediatamente; não administrar medicamentos sem prescrição;\n"
                 "- Evitar esforços, manter via aérea permeável; monitorizar sinais vitais continuamente;\n"
                 "- Preparar documentação médica e histórico; organizar transporte assistido (ambulância) se possível;\n"
                 "- Contatos: acionar serviço de emergência local;\n"
                 "- Observações adicionais: considerar suporte ventilatório e disponibilidade de leitos de UTI.\n");
    }
    else if (strcmp(conclusao, "GRAVE")==0)
    {
        strcpy(orientacoes,
                 "Paciente em estado GRAVE. AÇÕES RECOMENDADAS:\n"
                 "- Avaliação presencial com prioridade nas próximas horas; realizar exames (oximetria, RX toráxico, hemograma).\n"
                 "- Monitorar temperatura, frequência respiratória e oximetria a cada 2?4 horas; procurar urgência se houver queda de SpO2 < 94%% ou piora respiratória;\n"
                 "- Isolamento e uso de máscara, hidratação e evitar anti-inflamatórios sem orientação;\n"
                 "- Orientar transporte seguro e acompanhamento por profissional de saúde.\n");
    }
    else if (strcmp(conclusao, "MODERADO")==0)
    {
        strcpy(orientacoes,
                 "Quadro MODERADO. Tratamento e monitoramento:\n"
                 "- Isolamento domiciliar e observação: medir temperatura 2x/dia e oximetria quando disponível;\n"
                 "- Sintomas a monitorar: febre persistente (>38,5°C >48h), dispneia, confusão, sonolência excessiva ? procurar atendimento se ocorrerem;\n"
                 "- Manter hidratação, repouso, antipiréticos se necessário (paracetamol) e evitar automedicação;\n"
                 "- Reavaliar em 48?72 horas ou antes se houver piora.\n");// snprintf() : serve para formatar
    }
    else if (strcmp(conclusao, "LEVE")==0 || strcmp(conclusao, "BOM")==0)
    {
        strcpy(orientacoes,
                 "Quadro leve ou sem indicativos graves. Cuidados domiciliares:\n"
                 "- Hidratar, repousar, usar antipirético se necessário; manter isolamento até melhora de 24?48h dos sintomas;\n"
                 "- Orientações de retorno ao trabalho/escola: aguardar 24?48h sem febre e melhora sustentada; vacinação e prevenção respiratória recomendadas;\n"
                 "- Procurar assistência se surgirem sinais de alarme (dispneia, confusão, queda acentuada da saturação).\n");
    }
    else
    {
        strcpy(orientacoes, "Sem observações específicas.");
    }

    // Informação resumida ao usuário
    printf("\n==== OBSERVAÇÕES ====\n");
    printf("Paciente: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Contato: %s\n",telefone);
    printf("Pontos de Urgência: %d\n\n",pontos);
    printf("%s\n", orientacoes);
    printf("================================\n\n");
}

// ----- URGÊNCIA POR PONTUAÇÃO -----
void calculoUrgencia(int p)
{
    if (p >= 90) strcpy(urgencia, "CRITICA");
    else if (p >= 70) strcpy(urgencia, "ALTA");
    else if (p >= 45) strcpy(urgencia, "MEDIA");
    else if (p >= 20) strcpy(urgencia, "BAIXA");
    else strcpy(urgencia, "NULA");
}


