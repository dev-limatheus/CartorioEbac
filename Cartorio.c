#include <stdio.h> //blibioteca de comunicação com o usuário
#include <stdlib.h> //bliblioteca de aloicação de espaço em memória
#include <locale.h> //bliblioteca de alocação de texto por região
#include <string.h> //bliblioteca responsávl pelas strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arqeuivo
	fprintf(file,cpf); //salva o valor da variavel (cpf)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza informação no arquivo
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
	
	printf("Usuário cadastrado!\n");
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
		printf("CPF não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário ja não se encontra no sistema!\n");
		system("pause");
		
	}
	
}

int main()
 	{
 	int opcao=0; //definindo variavel
 	int laco=1; 
 	char senhadigitada[10]="a";
 	int comparacao;
 	
 	printf("### Cartório da EBAC ###\n\n");
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
	
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar usuários.\n");
			printf("\t2 - Consultar usuários.\n");
			printf("\t3 - Deletar usuários.\n"); 
			printf("\t4 - Sair do sistema.\n\n"); //fim do menu
			printf("Opção: ");
	
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
					printf("Opção inválida.\n");
					system("pause");
					break;				
			}
		}
	}
	else
		printf("\nSenha incorreta.");
}
