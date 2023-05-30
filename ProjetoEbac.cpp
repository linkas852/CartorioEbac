#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Insira o CPF que deseja registrar: \n");
	scanf("%s", cpf); // %s salva a string que o usuario inserir
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //O W representa a criação de um novo arquivo
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //O A representa atualizar arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	
	system("pause");
	
	
}
int consultar()
{
	setlocale(LC_ALL, "Portuguese");

	char cpf[40];
	char conteudo[200];
	printf("Digite o CPF que deseja consultar: \n");
	scanf("%s", cpf);
	
	
	FILE *file;
	file= fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Arquivo não encontrado no banco de dados. \n");
		
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
	
	printf("Digite o cpf que deseja excluir do banco de dados: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	FILE*file;
	file = fopen(cpf, "r");
	
	
	if (file == NULL)
	{
		printf("Usuario deletado com sucesso! \n");
		system("pause");

	}
}
int main()
{
	int opcao = 0;
	char laco = 1;
	
	for(laco!=1;laco=1;) 
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("###Cartório da EBAC###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Resgistrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
		printf("\t4 - Sair do sistema\n\n");
		scanf("%d", &opcao); //salva o char que o usuario inserir
	
		system("cls");
		
			switch(opcao)
			{
				case 1:
				registro();
				break;
				
				case 2:
				consultar();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar nosso sistema!\n");
				return 0;
				break;
				
				default:
				printf("Escolha uma opção válida \n");
				system("pause");
				break; 
			}
				
		
	}
		//printf("Esse software é de livro uso.\n");

}
