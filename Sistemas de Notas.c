#include <stdio.h>
#include <stdlib.h> // alocação de memoria e controle de processos, segundo o \Wikipedia
#include <string.h> //manipular strings
#include <locale.h> // Biblioteca de Linguagens

typedef struct {
	char Nome [60];
	float Notas [3];
	int Status;
} Aluno;
Aluno Alunos[100];

void menu();
void Cadastro_de_Aluno();
void Lista_de_Alunos();
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	menu();
	
	return 0;
}

void menu() {
	
	int op;
	do{	
		system("cls");
		system("clear");
		printf("\n1 >Cadastra Aluno");
		printf("\n2 >Lista de Alunos");
		printf("\n0 >Sair \n");
		scanf("%d", &op);
		getchar();
		printf("\n");
		
		switch(op) {
			case 1:
				Cadastro_de_Aluno();
			break;
			
			case 2:
				Lista_de_Alunos();
			break;
			
			default:
				printf("Opção Invalida!\n");
		}
		getchar();
	}while(op!=0);
}

void Cadastro_de_Aluno() {
	system("cls");
	//system("clear");
	
	FILE *Sys_Uni;
	Sys_Uni = fopen("Sys_Uni.txt", "a");
	
	char Nome [60];
	float Notas [3];
	int op;
	int i; // variavel de apoio
	do {	 
		printf("\n Nome: ");
		fgets (Nome,sizeof(Nome),stdin);
		printf("\n1° VA: ");
		scanf("%f", &Notas[0]);
		printf("\n2° VA: ");
		scanf("%f", &Notas[1]);
		printf("\n3° VA: ");
		scanf("%f", &Notas[2]);
		
		for (i = 0; i < 100; i++) {
			if (Alunos[i].Status == 0) {
				Alunos[i].Notas[0] = Notas[0];
				Alunos[i].Notas[1] = Notas[1];
				Alunos[i].Notas[2] = Notas[2];
				strcpy(Alunos[i].Nome, Nome); //função para atribuição a uma string.
				Alunos[i].Status = 1;
                break;
			}
		}
		
		for (i = 0; i < 100; i++) {
			if(Alunos[i].Status == 1) {
				fprintf(Sys_Uni, "Nome: %s\n", Alunos[i].Nome);
				fprintf(Sys_Uni, "1° VA: %0.2f\n", Alunos[i].Notas[0]);
				fprintf(Sys_Uni, "2° VA: %0.2f\n", Alunos[i].Notas[1]);
				fprintf(Sys_Uni, "3° VA: %0.2f\n", Alunos[i].Notas[2]);
				float Media;
					Media = (Notas[0] + Notas[1] + Notas[2]);
					Media = Media / 3;
					fprintf(Sys_Uni, "\n");
					if (Media >= 60) {
						fprintf(Sys_Uni, "Aluno aprovado.\nMédia: %0.2f", Media);
					}
					if (Media < 60) {
						fprintf(Sys_Uni, "Aluno reprovado.\nMédia: %0.2f", Media);
					}
					if (Media > 100) {
						fprintf(Sys_Uni, "Há algo errado com as notas, revise e tente novamente.\nMédia: %0.2f", Media);
					}
			fprintf(Sys_Uni, "\n""------------------------------""\n");
			}
		}
		fclose(Sys_Uni);
		
		printf("\n1 >Continuar");
		printf("\n0 >Sair");
		printf("\n");
		scanf("%d", &op);
		getchar();
		
	}while(op != 0);
}

void Lista_de_Alunos() {
	system("cls");
	//system("clear");
	FILE *Sys_Uni;
	Sys_Uni = fopen("Sys_Uni.txt", "r");
	
	int op;
	do {
	
		if(Sys_Uni == NULL) {
			printf("Não foi possivel abrir o arquivo. \n");
			getchar();//deixar msg na tela.
			exit(0);
		}
	
		char Linha[100];
		
		while (fgets(Linha, 100, Sys_Uni) != NULL) {
			printf("%s", Linha);
		}
		
	fclose(Sys_Uni);
			
	printf("\n1 >Continuar");
	printf("\n0 >Sair");
	printf("\n");
	scanf("%d", &op);
	getchar();
		
	}while(op != 0);
}
