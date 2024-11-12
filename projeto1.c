#include <stdio.h>// biblioteca 
#include <stdlib.h>// biblioteca
#include <locale.h>// biblioteca de aloca��o de texto por regi�o
#include <string.h>// biblioteca responsavel por cuidar das strings

int registrar()
{
	char arquivo[30];
	char cpf[40];
	char nome[30];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);// %s refere se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar valores das strings
	
	FILE *file;
	file = fopen(arquivo, "w");//cria o arquivo /w = escrever
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);	
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);	
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);	
	
	system("pause");
		
	
}

int consultar()
{
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para consulta: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o Registrado, informe outro CPF\n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as inform��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}
	
}

int deletar()
{
	char cpf[40];
	
	printf("digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
		
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o encontrado.\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
		printf("### cart�rio do vit�o ###\n\n"); //inicio do menu
		printf("Escolha uma op��o a seguir:\n\n");
		printf("\t1- REGISTRAR NOMES\n");
		printf("\t2- CONSULTAR NOMES\n");
		printf("\t3- DELETAR NOMES\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao);//armazenando escolha do usu�rio
	
		system("cls");// respons�vel por limpar tudo na tela
		
		switch(opcao)
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("essa op��o n�o est� dispon�vel");
			system("pause");
			break;
				
				
			
		}
	
	
}



}

