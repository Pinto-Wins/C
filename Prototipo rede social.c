//Bibliotecas
#include <stdio.h> /*Permite a utilização de operações de input e output*/
#include <string.h>/*Permite a utilização de strings e da sua comparação*/
#include <locale.h>/*Permite a utilização de caracteres portugueses*/
#include <stdlib.h>/*system, size_t*/

//definicao das constantes
#define tamnome 100
#define tammorada 50
#define numpessoas 200
#define tamamigos 50
#define tamlogin 30
#define tamsenha 11     /* 10 chars + '\0' */
#define tammail 100
#define tamutilizadores 200
#define tamdatanascimento 30

// Helpers de input seguros
static void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static void read_line(char *buf, size_t size) {
    if (!buf || size == 0) return;
    if (fgets(buf, (int)size, stdin)) {
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';
        else clear_input_buffer(); // remove resto da linha se excedeu o buffer
    } else {
        buf[0] = '\0';
        clear_input_buffer();
    }
}

//Variáveis Globais
char numeroAmigos[tamamigos];
char data_de_nascimento[tamdatanascimento], nome[tamnome], mail[tammail];
char login[tamlogin], senha[tamsenha], login1[tamlogin], senha1[tamsenha];
long int telefone, diadenascimento,  mesdenascimento, anodenascimento;

//definição de tipos
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
} Assinante;

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
    clear_input_buffer();

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
            break;
        default:
            printf("Opção inválida, a voltar ao menu principal...\n");
            system("pause");
            break;
    }
}

//Registo
void InserirDados(Assinante pessoas[], int *totalpessoas){ /*Registo de Utilizador*/
    system("cls");/*Para limpar o ecrã*/

    if (*totalpessoas >= numpessoas) {
        printf("Capacidade esgotada.\n");
        system("pause");
        return;
    }

    Assinante ass;

    printf("\n\nInsira o seu primeiro nome: ");
    read_line(ass.nome, sizeof ass.nome);

    printf("\nInsira o dia em que nasceu: ");
    scanf("%ld", &ass.diadenascimento);
    clear_input_buffer();

    printf("\nEm que mês: ");
    scanf("%ld", &ass.mesdenascimento);
    clear_input_buffer();

    printf("\nEm que ano: ");
    scanf("%ld", &ass.anodenascimento);
    clear_input_buffer();

    printf("\nInsira o seu e-mail: ");
    read_line(ass.mail, sizeof ass.mail);

    printf("\nInsira o seu número de telefone: ");
    scanf("%ld", &ass.telefone);
    clear_input_buffer();

    printf("\nEscolha um nome de utilizador pretendido: ");
    read_line(ass.login, sizeof ass.login);

    printf("\nEscolha agora uma senha até 10 caracteres: ");
    read_line(ass.senha, sizeof ass.senha);

    pessoas[*totalpessoas]=ass;
    (*totalpessoas)++;
}

//Login
void funcaoLogin (int totalpessoas, Assinante pessoas[]) { /*Autenticação do Utilizador*/
    system ("cls");/*Para limpar o ecrã*/

    char nomeAprocurar[tamlogin];
    char senhaAprocurar[tamsenha];
    int i=0, encontrou=0;

    printf ("Introduza o nome de utilizador: ");
    read_line(nomeAprocurar, sizeof nomeAprocurar);
    printf ("Introduza a sua senha: ");
    read_line(senhaAprocurar, sizeof senhaAprocurar);

    system("cls");/*Para limpar o ecrã*/
    while (i<totalpessoas && !encontrou)
    {
        if (strcmp(pessoas[i].login,nomeAprocurar)==0 && strcmp(pessoas[i].senha,senhaAprocurar)==0){
            printf("*         Bem Vindo          *\n");
            system("pause");
            encontrou=1;
            decisao1(); /*direcionamento para o menu secundário*/
            break;
        }
        i++;
    }

    if (!encontrou) {
        printf ("\n\nDados Inválidos!\n\n");
        system("pause");
    }
}

void listardados(Assinante pessoas[], int totalpessoas){ /*lista os dados completos de todas as contas existentes*/
    system("cls");/*Para limpar o ecrã*/

    int i, user;

    printf("Inicie sessão com Administrador:\n User: ");
    scanf("%d", &user);
    clear_input_buffer();

    if(user == 0000){ /*Função que verifica as permissões do utilizador*/
        for(i=0; i<totalpessoas; i++)
        {
            printf("\n nome: %s\n", pessoas[i].nome);
            printf(" nome de utilizador: %s\n", pessoas[i].login);
            printf(" e-mail: %s\n", pessoas[i].mail);
            printf(" telefone: %ld\n", pessoas[i].telefone);
            printf(" data de nascimento: %ld / %ld / %ld\n", pessoas[i].diadenascimento, pessoas[i].mesdenascimento, pessoas[i].anodenascimento);
            // Não imprimir senha por segurança
        }
    } else {
        printf("*   Não tem autorização   *");
    }

    system("pause");
}

void consultardados(Assinante pessoas[], int totalpessoas) /*consulta os dados de uma conta em especifico*/
{
    system("cls");/*Para limpar o ecrã*/

    char nome1[tamnome];
    int i=0, encontrou=0;

    printf("Introduza a conta a procurar: ");
    read_line(nome1, sizeof nome1);

    while(i<totalpessoas)
    {
        if(strcmp(pessoas[i].login, nome1)==0)
        {
            printf("\n nome: %s\n", pessoas[i].nome);
            printf(" data de nascimento: %ld / %ld / %ld\n", pessoas[i].diadenascimento, pessoas[i].mesdenascimento, pessoas[i].anodenascimento);
            encontrou = 1;
            break;
        }
        i++;
    }

    if (!encontrou) {
        printf("\nnome não encontrado.\n");
    }
    system("pause");
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); /*Permite a utilização de caracteres portugueses*/

    int totalpessoas = 0;
    Assinante pessoas[numpessoas];

    int opcao, datahj;

    printf(" Olá!!\nInsira a data de hoje (não separe os números):"); /*Noção de Tempo*/
    scanf("%d", &datahj);
    clear_input_buffer();

    do{
        system("cls");/*Para limpar o ecrã*/

        printf("Menu Inicial\n\n  data:*   %d   *   \n\n", datahj);
        printf("1- Registar\n");
        printf("2- Login\n");
        printf("3- Procurar utilizador\n");
        printf("4- Listar utilizadores\n");
        printf("5- Total de assinantes\n");
        printf("6- Modo Anónimo\n");
        printf("0- sair\n");
        printf("Escolha uma opção:\n");
        scanf("%d", &opcao);
        clear_input_buffer();

        switch(opcao){
            case 1: InserirDados(pessoas, &totalpessoas);
                break;
            case 2: funcaoLogin(totalpessoas, pessoas);
                break;
            case 3: consultardados(pessoas, totalpessoas);
                break;
            case 4: listardados(pessoas, totalpessoas);
                break;
            case 5: printf("\n total de assinantes: %d\n", totalpessoas);
                break;
            case 6:
                system("cls");
                printf("*   Bem vindo à no one`   *\n");
                break;
            case 0:
                system("cls");/*Para limpar o ecrã*/
                printf("\n\nVolte Sempre\n");
                system("pause");
                break;
            default:
                printf("Opção invalida");
        }
        system ("pause");
    } while (opcao!=0);

    return 0;
}
