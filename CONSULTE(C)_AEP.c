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
    printf("\n");

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

    printf("\n	ENTER para continuar");
    getchar(); // conosme a entrada e limpa o buffer
}

void menu()
{
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t						M E N U\n");
    printf("\n		[1] Coletar informações do Paciente\n");
    printf("\n		[2] Iniciar Triagem\n");
    printf("\n		[3] Visualizar prognóstico\n");
    printf("\n		[4] Visualizar Observações\n");
    printf("\n		[5] Encerrar\n");
    printf("\n");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    getchar(); // limpa o buffer

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
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("					Perfeito vamos cadastrar o paciente!");
    printf("\n");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n 		INFORME O NOME: ");
    fgets(nomeTmp, sizeof(nomeTmp), stdin);
    nomeTmp[strcspn(nomeTmp, "\n")] = '\0';

    for (i = 0; i < strlen(nomeTmp); i++)
    {
        nome[i] = toupper(nomeTmp[i]);
    }

    printf("\n 	       INFORME A IDADE: ");
    scanf("%d", &idade);
    getchar(); // limpa o buffer

    printf("\n            INFORME O TELEFONE: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    printf("\n========================================Informções Registradas Com Sucesso=============================================\n");
}

// ----------------- TRIAGEM -----------------
void iniciarTriagem()
{
    system("cls");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");

    printf("			      Triagem iniciada, digite (S) para sim e (N) para não\n");
    printf("\n");
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    // int pontos = 0;
    int febre = perguntasTriagem("	Febre: ");
    int tosse = perguntasTriagem("	Tosse: ");
    int dorG = perguntasTriagem("	Dor de garganta: ");
    int ar = perguntasTriagem("	Falta de ar:");
    int contato = perguntasTriagem("	Contato com doente:");
    int dorCab = perguntasTriagem("	Dor de cabeça: ");
    int fraq = perguntasTriagem("	Fraqueza: ");

    pontos += febre + tosse + dorG + ar + contato + dorCab + fraq;

    // Critérios especiais
    if (ar)
        pontos += 40;
    if (febre && tosse)
        pontos += 30;
    if (contato)
        pontos += 20;

    // Idade influencia
    if (idade <= 10 || idade >= 60)
        pontos += 15;

    // ----- ÁRVORE REFINADA -----
    if (pontos >= 90)
    {
        strcpy(quadroPaciente, "	ALTO RISCO !	");
        strcpy(recomendacoes, "	!ATENDIMENTO IMEDIATO!	");
        strcpy(conclusao, "	!!CRITICO!!	");
    }
    else if (pontos >= 70)
    {
        strcpy(quadroPaciente, "	RISCO MODERADO-ALTO	");
        strcpy(recomendacoes, "	AVALIAÇÃO PRESENCIAL	");
        strcpy(conclusao, " GRAVE	");
    }
    else if (pontos >= 45)
    {
        strcpy(quadroPaciente, "	RISCO MODERADO	");
        strcpy(recomendacoes, "	ISOLAMENTO E MONITORAMENTO	");
        strcpy(conclusao, "	MODERADO	");
    }
    else if (pontos >= 20)
    {
        strcpy(quadroPaciente, "	QUADRO LEVE	");
        strcpy(recomendacoes, "	HIDRATAÇÃO E REPOUSO	");
        strcpy(conclusao, "	LEVE	");
    }
    else
    {
        strcpy(quadroPaciente, "	SEM INDICATIVOS	");
        strcpy(recomendacoes, "	CONTINUE O BOM TRABALHO	");
        strcpy(conclusao, "	BOM	");
    }

    calculoUrgencia(pontos);
    printf("\n");
    printf("===============================================Triagem Finalizada========================================================\n\n");
}

int perguntasTriagem(char *msg)
{
    char resposta;
    int nivel;

    while (1)
    {
        printf("%s (S/N): ", msg);
        scanf(" %c", &resposta);
        getchar(); // limpar buffer

        if (toupper(resposta) == 'S')
        {
            do
            {
                printf("\n		(1=Leve / 2=Moderado / 3=Forte): ");
                scanf("%d", &nivel);
                getchar(); // limpar buffer

                if (nivel < 1 || nivel > 3)
                {
                    printf("\n ! intensidade inválida, tente novamente ! \n");
                }
            } while (nivel < 1 || nivel > 3);

            printf("\n\n");
            return nivel * 10;
        }
        if (toupper(resposta) == 'N')
        {
            return 0;
        }

        printf("		Entrada inválida!\n");
    }
}

void exibirPrognostico()
{
    system("cls");

    printf("\n============================================= PROGNÓSTICO ===================================\n");
    printf("\n");
    printf("\n         Informações coletadas: ");
    printf("\n");
    printf("\n						Paciente: %s\n", nome);
    printf("\n						Idade: %d\n", idade);
    printf("\n");
    printf("\n= 		          ==================================================\n");
    printf("\n");
    printf("						Quadro: %s\n", quadroPaciente);
    printf("						Urgência: %s\n", urgencia);
    printf("						Recomendações: %s\n", recomendacoes);
    printf("\n----------------------------------------------------------------------------------------------------------\n");
    printf("\n						Conclusão: %s\n\n", conclusao);
}

// ----------------- OBSERVAÇÕES -----------------
void observacoes()
{
    system("cls");

    if (strcmp(conclusao, "	!!CRITICO!!	") == 0)
    {
        strcpy(orientacoes,
               "Paciente em estado CRÍTICO. AÇÕES IMEDIATAS:\n"
               "- Encaminhar para emergência/UTI imediatamente; não administrar medicamentos sem prescrição;\n"
               "- Evitar esforços, manter via aérea permeável; monitorizar sinais vitais continuamente;\n"
               "- Preparar documentação médica e histórico; organizar transporte assistido (ambulância) se possível;\n"
               "- Contatos: acionar serviço de emergência local;\n"
               "- Observações adicionais: considerar suporte ventilatório e disponibilidade de leitos de UTI.\n");
    }
    else if (strcmp(conclusao, " GRAVE	") == 0)
    {
        strcpy(orientacoes,
               "Paciente em estado GRAVE. AÇÕES RECOMENDADAS:\n"
               "- Avaliação presencial com prioridade nas próximas horas; realizar exames (oximetria, RX toráxico, hemograma).\n"
               "- Monitorar temperatura, frequência respiratória e oximetria a cada 2?4 horas; procurar urgência se houver queda de SpO2 < 94%% ou piora respiratória;\n"
               "- Isolamento e uso de máscara, hidratação e evitar anti-inflamatórios sem orientação;\n"
               "- Orientar transporte seguro e acompanhamento por profissional de saúde.\n");
    }
    else if (strcmp(conclusao, " MODERADO	") == 0)
    {
        strcpy(orientacoes,
               "Quadro MODERADO. Tratamento e monitoramento:\n"
               "- Isolamento domiciliar e observação: medir temperatura 2x/dia e oximetria quando disponível;\n"
               "- Sintomas a monitorar: febre persistente (>38,5°C >48h), dispneia, confusão, sonolência excessiva ? procurar atendimento se ocorrerem;\n"
               "- Manter hidratação, repouso, antipiréticos se necessário (paracetamol) e evitar automedicação;\n"
               "- Reavaliar em 48?72 horas ou antes se houver piora.\n"); // snprintf() : serve para formatar
    }
    else if (strcmp(conclusao, " LEVE	") == 0 )
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
    printf("\n======================================================= OBSERVAÇÕES ==================================================\n");
    printf("\n");
    printf("\n		Paciente: %s\n", nome);
    printf("\n		Idade: %d\n", idade);
    printf("\n		Contato: %s\n", telefone);
    printf("\n		Pontos de Urgência: %d\n\n", pontos);
    printf("\n		%s\n", orientacoes);
    printf("\n");
    printf("========================================================================================================================\n\n");
}

// ----- URGÊNCIA POR PONTUAÇÃO -----
void calculoUrgencia(int p)
{
    if (p >= 90)
        strcpy(urgencia, "CRITICA");
    else if (p >= 70)
        strcpy(urgencia, "ALTA");
    else if (p >= 45)
        strcpy(urgencia, "MEDIA");
    else if (p >= 20)
        strcpy(urgencia, "BAIXA");
    else
        strcpy(urgencia, "NULA");
}
