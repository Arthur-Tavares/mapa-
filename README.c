#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 10

typedef struct dados{
	int codigo;
	char nome[50];
	char descricao[100];
	int ano;
	int status;
	char gerente[50];
	char prazo[50];
	char setor[50];
	float orcamento;
}base_projetos;

int posicao = 0;

void cadastrarProjeto(base_projetos cadastro[MAX]);
void relatorioProjeto(base_projetos cadastro[MAX]);
void imprimeAFazer (base_projetos cadastro[MAX]);
void imprimeFazendo (base_projetos cadastro[MAX]);
void imprimeConcluido (base_projetos cadastro[MAX]);

int main(){
	setlocale(LC_ALL, "Portuguese");
	base_projetos cadastro[MAX];
	
	int escolha;
	
	system("cls");	
	do{
		system("cls");
		printf("****************************************************");
		printf("\n GESTÃO DE PROJETO ");
		printf("\n****************************************************");
		printf("\n 1 - Cadastro");
		printf("\n 2 - Imprime todos");
		printf("\n 3 - Imprime a fazer");
		printf("\n 4 - Imprime em andamento");
		printf("\n 5 - Imprime concluidos");		
		printf("\n 6 - Sair");
		printf("\n << Escolha uma opção do menu: ");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				cadastrarProjeto(cadastro);			
				break;
			case 2:
				relatorioProjeto(cadastro);
				break;
			case 3:
				imprimeAFazer(cadastro);
				break;
			case 4:
				imprimeFazendo(cadastro);
				break;
			case 5:
				imprimeConcluido(cadastro);
				break;
			case 6:
				printf("\nSaindo da Aplicação\n");
				system("Pause");
				break;
			default:
				printf("\nEscolha errada!!!\n");
				system("Pause");
		}
	}while(escolha != 6);
	return 0;
}

void cadastrarProjeto(base_projetos cadastro[MAX]){
	system("cls");
	printf("---------------------------------------");
	printf("\n CADASTRANDO UM PROJETO");
	printf("\n---------------------------------------");
	char resp = 's';	
	while(resp == 's' && posicao <= MAX){
		posicao++;
		printf("\nCódigo: %d ", posicao);		
		cadastro[posicao].codigo = posicao;
		printf("\nInforme o nome: ");
		fflush(stdin);
		gets(cadastro[posicao].nome);
		printf("\nInforme a descricao: ");
		fflush(stdin);
		gets(cadastro[posicao].descricao);		
		printf("\nInforme o ano: ");
		fflush(stdin);
		scanf("%d",&cadastro[posicao].ano);		
		printf("\nInforme o Status: ");
		printf("\n [1] = A fazer.\n [2] = Fazendo. \n [3] = Concluido");
		fflush(stdin);
		scanf("\n%d",&cadastro[posicao].status);
		printf("\nInforme o gerente: ");
		fflush(stdin);
		gets(cadastro[posicao].gerente);
		printf("\nInforme o prazo por extenso: ");
		fflush(stdin);
		gets(cadastro[posicao].prazo);
		printf("\nInforme o setor: ");
		fflush(stdin);
		gets(cadastro[posicao].setor);				
		printf("\nInforme o orçamento do projeto: ");
		fflush(stdin);
		scanf("%f",&cadastro[posicao].orcamento);		
		if(posicao < MAX){
			printf("\n\nDeseja cadastrar novo Projeto? [s] Sim [n] Não: ");
			fflush(stdin);
			scanf("%c", &resp);
		}else{
			printf("\nNão é possivel continuar cadastrando\n");
			resp = 'n';
		}
	}
}
void relatorioProjeto(base_projetos cadastro[MAX]){
	system("cls");
	printf("***************************************");
	printf("\n IMPRIMINDO TODOS OS PROJETOS ");
	printf("\n***************************************\n");
	int vertical=1;
	
	if(posicao >= 1){
		while(vertical <= posicao){
				printf("%d - %s - %s - %d - %d - %s - %s - %s - %f\n", cadastro[vertical].codigo,cadastro[vertical].nome,cadastro[vertical].descricao,cadastro[vertical].ano,cadastro[vertical].status,cadastro[vertical].gerente,cadastro[vertical].prazo,cadastro[vertical].setor,cadastro[vertical].orcamento);
				vertical++;
		}	
			
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void imprimeAFazer (base_projetos cadastro[MAX])
{
	system ("cls");
	printf("---------------------------------------");
	printf("\nIMPRIME OS ''A FAZER''");
	printf("\n---------------------------------------");
	int vertical=1;
 
	if (posicao >= 1){
		while(cadastro[vertical].status == 1){
			printf("%d - %s - %s - %d - %d - %s - %s - %s - %f\n", cadastro[vertical].codigo,cadastro[vertical].nome,cadastro[vertical].descricao,cadastro[vertical].ano,cadastro[vertical].status,cadastro[vertical].gerente,cadastro[vertical].prazo,cadastro[vertical].setor,cadastro[vertical].orcamento);
			vertical++;
		}
   
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}
void imprimeFazendo (base_projetos cadastro[MAX])
{
	system ("cls");
	printf("---------------------------------------");
	printf("\nIMPRIME OS ''Fazendo''");
	printf("\n---------------------------------------");
	int vertical=1;
	if (posicao >= 1){
		if (cadastro[vertical].status == 2){
			printf("%d - %s - %s - %d - %d - %s - %s - %s - %f\n", cadastro[vertical].codigo,cadastro[vertical].nome,cadastro[vertical].descricao,cadastro[vertical].ano,cadastro[vertical].status,cadastro[vertical].gerente,cadastro[vertical].prazo,cadastro[vertical].setor,cadastro[vertical].orcamento);
			vertical++;
		}
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}
void imprimeConcluido (base_projetos cadastro[MAX])
{
	system ("cls");
	printf("---------------------------------------");
	printf("\nIMPRIME OS ''Concluidos''");
	printf("\n---------------------------------------");
	int vertical=1;
	if (posicao >= 1){
		if (cadastro[vertical].status == 3){
			printf("%d - %s - %s - %d - %d - %s - %s - %s - %f\n", cadastro[vertical].codigo,cadastro[vertical].nome,cadastro[vertical].descricao,cadastro[vertical].ano,cadastro[vertical].status,cadastro[vertical].gerente,cadastro[vertical].prazo,cadastro[vertical].setor,cadastro[vertical].orcamento);
			vertical++;
		}
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}
	
