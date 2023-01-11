//Bibliotecas
#include <stdio.h> /*Permite a utilização de operações de input e output*/
#include <string.h>/*Permite a utilização de strings e da sua comparação*/
#include <locale.h>/*Permite a utilização de caracteres portugueses*/

//definicao das constantes
#define tamnome 100
#define tammorada 50
#define numpessoas 200
#define tamamigos 50
#define tamlogin 30
#define tamsenha 10
#define tammail 100
#define tamutilizadores 200
#define tamdatanascimento 30

//Variáveis Globais
char numeroAmigos[tamamigos];
char data_de_nascimento[tamdatanascimento], nome[tamnome], mail[tammail];
char login[tamlogin], senha[tamsenha], login1[tamlogin], senha1[tamsenha];
long int telefone, diadenascimento,  mesdenascimento, anodenascimento;

//definiçao de tipos
typedef struct
{
	char nome[tamnome];
	char mail[tammail];
	long int diadenascimento;
	long int mesdenascimento;
	long int anodenascimento;
	long int telefone;
	char login[tamlogin];
	char senha[tamsenha];
		
}Assinante;

typedef struct
{
	char login1[tamlogin];
	char senha1[tamsenha];
}Login;
	


//funções

//decisoes
void decisao1() /*Menu secundário*/
{
    system("cls");/*Para limpar o ecrã*/

    int op10;

    printf("\n\n\t1 - Página Principal");
    printf("\n\n\t2 - Perfil");
    printf("\n\n\t0 - Voltar");
    printf("\n\nInsira a sua opção: ");
    scanf("%d", &op10);
    fflush(stdin);

    switch (op10)
    {
        case 1:
        	printf("A voltar ao menu principal...\n");
            system("pause");
            break;
        case 2:
			printf("Não disponível :(\n\n");
			printf("A voltar ao menu principal...\n");
            system("pause");
            break;
        case 0:
            printf("A voltar ao menu principal...\n");
            system("pause");
        default:
        	printf("Opção inválida, a voltar ao menu principal...\n");
        	system("pause");
    }  
}

//Registo
void InserirDados(Assinante pessoas[], int *totalpessoas){ /*Registo de Utilizador*/
	
	system("cls");/*Para limpar o ecrã*/
	
	Assinante ass;
	
	printf("\n\nInsira o seu primeiro nome: ");
	fflush (stdin); gets (ass.nome);
	
	printf("\nInsira o dia em que nasceu: ");
	scanf("%d", &ass.diadenascimento);
	
	printf("\nEm que mês: ");
	scanf("%d", &ass.mesdenascimento);
	
	printf("\nEm que ano: ");
	scanf("%d", &ass.anodenascimento);
	
	printf("\nInsira o seu e-mail: ");
	fflush (stdin); gets (ass.mail);
	
	printf("\nInsira o seu número de telefone: ");
	scanf("%d", &ass.telefone);
		
	printf("\nEscolha um nome de utilizador pretendido: ");
	scanf("%s", ass.login);
	
	printf("\nEscolha agora uma senha até 10 caracteres: ");
	scanf("%s", ass.senha);
	
	
	pessoas[*totalpessoas]=ass;
	(*totalpessoas)++;
}

//Login

void funcaoLogin (int totalpessoas, Assinante pessoas[]) { /*Autenticação do Utilizador*/
	
	system ("cls");/*Para limpar o ecrã*/
	
	int opcaol;
	char nomeAprocurar[tamlogin];
	char senhaAprocurar[tamsenha];
	int i=0, encontrou=0;
	
	printf ("Introduza o nome de utilizador: ");
	fflush(stdin); gets(nomeAprocurar);
	printf ("Introduza a sua senha: ");
	fflush(stdin); gets(senhaAprocurar);
	
	system("cls");/*Para limpar o ecrã*/
	while (i<totalpessoas && encontrou==0)
	{
		if (strcmp(pessoas[i].login,nomeAprocurar)==0 && strcmp(pessoas[i].senha,senhaAprocurar)==0 ){/*comparação das variáveis com as strings dos dados registados*/
		   
    		printf("*         Bem Vindo          *\n");
   		 	
   		 	system("pause");
   		 	
   		encontrou=1;
		   	
	    decisao1(); /*direcionamento para o menu secundário*/
	    
		}
		i++;	
	}
	
    if (encontrou==0)
	printf ("\n\nDados Inválidos!\n\n");		
	
    system("pause");
		
}

void listardados(Assinante pessoas[], int totalpessoas){ /*lista os dados completos de todas as contas existentes*/
	
	system("cls");/*Para limpar o ecrã*/
	
	int i, user;
	
	printf("Inicie sessão com Administrador:\n User: ");
	scanf("%d", &user);
	
	if(user == 0000){ /*Função que verifica as permissões do utilizador*/
	
		for(i=0; i<totalpessoas; i++)
		{		
			printf("\n nome: %s\n", pessoas[i].nome);
			printf(" nome de utilizador: %s\n", pessoas[i].login);
			printf(" e-mail: %s\n", pessoas[i].mail);
			printf(" telefone: %d\n", pessoas[i].telefone);
			printf(" data de nascimento: %d / %d / %d\n", pessoas[i].diadenascimento, pessoas[i].mesdenascimento, pessoas[i].anodenascimento);
			printf(" senha: %s\n", pessoas[i].senha);
			
		}
	
	}
	
	else{
	
		printf("*   Não tem autorização   *");
	
	} 
	
	system("pause");
}

void consultardados(Assinante pessoas[], int totalpessoas) /*consulta os dados de uma conta em especifico*/
{ 
	
	system("cls");/*Para limpar o ecrã*/
	
	char nome1[tamnome];
	int i=0, encontrou=0;
	
	printf("Introduza a conta a procurar: "); /*insere-se o nome de utilizador para procurar a conta*/
	fflush(stdin); //clears the output buffer//
	gets(nome1);	
		
	while(i<totalpessoas && encontrou==0)
	{
	
		if(strcmp(pessoas[i].login, nome1)==0) /*compara os nomes de utilizador registados no Array com o nome a procurar*/
		{
			
			printf("\n nome: %s\n", pessoas[i].nome);
			printf(" data de nascimento: %d / %d / %d\n", pessoas[i].diadenascimento, pessoas[i].mesdenascimento, pessoas[i].anodenascimento);
			
		}
			else{
			
				printf("\nnome não encontrado.");
				
				}
				
	i++;
	}	
}


int main()
{
	
	setlocale(LC_ALL, "Portuguese"); /*Permite a utilização de caracteres portugueses*/
	
	int totalpessoas = 0;
	
	Assinante pessoas[numpessoas];
	
	int opcao, datahj;
	
	printf(" Olá!!\nInsira a data de hoje (não separe os números):"); /*Noção de Tempo*/
	scanf("%d", &datahj);
	
	do{ 
		system("cls");/*Para limpar o ecrã*/
		
		printf("Menu Inicial\n\n  data:*   %d   *   \n\n", datahj);
		printf("1- Registar\n");
		printf("2- Login\n");
		printf("3- Procurar utilizador\n");
		printf("4- Listar utilizadores\n");
		printf("5- Total de assinantes\n");
		printf("6- Modo Anônimo\n");
		printf("0- sair\n");
		printf("Escolha uma opçao:\n");
		scanf("%d", &opcao);
	
		switch(opcao){
			case 1: InserirDados(pessoas, &totalpessoas);
				break;
			case 2:	funcaoLogin(totalpessoas, pessoas);
				break;
			case 3: consultardados(pessoas, totalpessoas); 
				break;
			case 4: listardados(pessoas, totalpessoas);
			    break;
			case 5: printf("\n total de assinantes: %d\n", totalpessoas);
				break;
			case 6:
			system("cls");
			printf("*   Bem vindo ´no one`\n   *");
				break;
			case 0: system("cls");/*Para limpar o ecrã*/
			
            	printf("\n\nVolte Sempre\n");
            	system("pause");
				break;
			default: printf("Opçao invalida");
		}
		system ("pause");
	} while (opcao!=0);
	
	return 1;
	
}
