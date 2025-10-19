#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main(){
	
	int resposta, x, y, tam, DoencaEscolhida, adSint;
	char nome[100], NOME[100], doencaSint[50];
	char sintomas[5][50];

	
	setlocale(LC_ALL, "Portuguese");
	
	
	strcpy(sintomas[0],  "Febre");
    strcpy(sintomas[1],  "Dor de cabeça");
    strcpy(sintomas[2],  "Dor no corpo (mialgia)");
    strcpy(sintomas[3],  "Cansaço ou fadiga");
    strcpy(sintomas[4],  "Perda de apetite");
    strcpy(sintomas[5],  "Tosse seca");
    strcpy(sintomas[6],  "Tosse com catarro (tosse produtiva)");
    strcpy(sintomas[7],  "Coriza (nariz escorrendo)");
    strcpy(sintomas[8],  "Espirros");
    strcpy(sintomas[9],  "Dor ou irritação na garganta");
    strcpy(sintomas[10], "Dificuldade para respirar (dispneia)");

	
	
/*---------------------------------------------------MENU----------------------------------------------*/
	printf("\n");
	printf("\n                                        Olá! Seja muito bem vindo ao consulte(c)\n"); //pegou o trocadilho?
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");	
	printf("\n");
	printf("\n");
	
	printf("    Por favor insira o numero conforme o que deseja fazer");
	printf("\n");
	printf("    ---------------------------------------------------------");
	printf("\n");
	printf("   		 Digite: \n");
	printf("\n       	[1]         Para iniciar a consulta\n");
	printf("\n       	[2]               Para ler o manual\n");
	printf("\n       	[3]   Para ler a conclusão resumida\n");
	printf("\n       	[4]  Para ler a conclusão detalhada\n");
	printf("\n       	[5]  	   Para encerrar o programa\n");
	printf("\n");
	printf("\n");
	printf("               Resposta: ");
	scanf("%d", &resposta);
	printf("    ---------------------------------------------------------");
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");	
	getchar();
	system("cls || clear");
	switch(resposta){
		case 1: 
//---------------------------------------------------iniciar consulta----------------------------------------------------------
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");	
			printf("\n");
			printf("                                      Perfeito! Vamos iniciar a conulta");
			printf("\n");
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");	
			printf("\n");
			printf("   Por favor me diga seu nome: ");
			fgets(nome, 100, stdin);
			nome[strcspn(nome, "\n")] = '\0';
			tam = strlen(nome);							//todo esse trampo só pra deixar o nome maiusculo =(
			for(x=0; x<tam; x++){
				NOME[x] = toupper(nome[x]);
			}
			printf("\n");
			printf("\n");
			printf("\n       		                                    SEJA BEM VINDO %s! \n", NOME);
			printf("\n       		 Por favor isira o numero conforme a tabela abaixo que corresponde com seus sintomas!\n");
			printf("\n");
			printf("\n");										//tive que repesquisar sobre arrays em c
			printf("            ______________________________________________________________________________________________\n");
			
		 	for(x = 0; x < 11; x++) {
                printf("            [%d] %s\n", x + 1, sintomas[x]);
            }

//------------------------------------------------Atribuição de sintomas---------------------------------------------------------------------
            printf("\n");
            printf("\n");
            printf("Adicionar sintoma?(Digite 0 para não e 1 para sim): \n");
            scanf("%d", adSint);
            getchar();
            
            while(adSint == 1){
            	switch(DoencaEscolhida){
	            	printf("Digite o número do sintoma (1 a 11): ");
                scanf("%d", &DoencaEscolhida);
                getchar();

                if (DoencaEscolhida >= 1 && DoencaEscolhida <= 11) {
                    strcat(doencaSint, sintomas[DoencaEscolhida - 1]);
                    strcat(doencaSint, ", ");
                    printf("Sintoma '%s' adicionado!\n", sintomas[DoencaEscolhida - 1]);
                } else {
                    printf("Número inválido!\n");
                }

                printf("\nDeseja adicionar outro sintoma? (1 = sim / 0 = não): ");
                scanf("%d", &adSint);
                getchar();
            }

            printf("\n\nResumo dos sintomas adicionados:\n%s\n", doencaSint);
            break;
	
				}		
			break;
		case 2: 
			//iniciar consulta
			break;
		case 3: 
			//iniciar consulta
			break;
		case 4: 
			//iniciar consulta
			break;
		case 5: 
			//iniciar consulta
			break;
	}
printf("\n");
printf("\n");
printf("\n");
	
}

