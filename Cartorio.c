#include <stdio.h> //blibioteca de comunica��o com o usu�rio
#include <stdlib.h> //bliblioteca de aloica��o de espa�o em mem�ria
#include <locale.h> //bliblioteca de aloca��o de texto por regi�o
#include <string.h> //bliblioteca respons�vl pelas strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arqeuivo
	fprintf(file,cpf); //salva o valor da variavel (cpf)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza informa��o no arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Usu�rio cadastrado!\n");
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // ler o arqeuivo
	
	if(file == NULL)
	{
		printf("CPF n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio ja n�o se encontra no sistema!\n");
		system("pause");
		
	}
	
}

int main()
 	{
 	int opcao=0; //definindo variavel
 	int laco=1; 
 	char senhadigitada[10]="a";
 	int comparacao;
 	
 	printf("### Cart�rio da EBAC ###\n\n");
 	printf("Login de administrador!\n\nDigite a sua senha: ");
 	scanf("%s",senhadigitada);
 	
 	comparacao = strcmp(senhadigitada, "admin");
 		
 	if(comparacao == 0)
 	{
 		system("cls");
 		for(laco=1;laco=1;)
 		{
		 	system("cls");
	 	
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar usu�rios.\n");
			printf("\t2 - Consultar usu�rios.\n");
			printf("\t3 - Deletar usu�rios.\n"); 
			printf("\t4 - Sair do sistema.\n\n"); //fim do menu
			printf("Op��o: ");
	
			scanf("%d", &opcao); //armazenando a escolha do usuario
			system("cls");
		
			switch(opcao)
			{
				case 1:
					registro();
					break;
				
				case 2:
					consulta();
					break;
				
				case 3:
					deletar();
					break;
				
				case 4:
					printf("Obrigado por usar o sistema!");
					return 0;
					break;
				
				
				default: 
					printf("Op��o inv�lida.\n");
					system("pause");
					break;				
			}
		}
	}
	else
		printf("\nSenha incorreta.");
}
