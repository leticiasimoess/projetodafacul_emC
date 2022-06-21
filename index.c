#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 200

// DECLARAÇÃO DAS VARIAVEIS
char nome[SIZE][40];
char email[SIZE][40];
int cpf[9];
char rua[SIZE];
int numero[SIZE];
char bairro[SIZE];
char cidade[SIZE];
char estado[4];
int cep[SIZE];
int telefone[SIZE];
int diadenasc[SIZE];
int mesdenasc[SIZE];
int anodenasc[SIZE];
int diadodiagnostico[SIZE];
int mesdodiagnostico[SIZE];
int anododiagnostico[SIZE];
char comorbidade[SIZE];
int op;
char result;
void Login();
void cadastropaciente();
void pesquisagp_risco();
int cpfpesquisa;
int emailpesquisa;
int anoatual;
int anodenascimento;
int idade;
FILE *fpi;

// FUNÇÃO DO LOGIN - USUARIO E SENHA

typedef struct
{

  char login[40];
  char senha[40];

} pessoa;
pessoa p[1];

int main(void)
{
  char login[40];
  char senha[40];

  strcpy(p[0].login, "Leticia");
  strcpy(p[0].senha, "12345");

  printf("\n\n\t\t--INSIRA O LOGIN E A SENHA--\n\n");

  printf("\n\n\t\tDigite o login: ");
  scanf("%s", &login);

  printf("\n\n\t\tDigite sua senha: ");
  scanf("%s", &senha);

  if ((strcmp(login, p[0].login) == 0) && strcmp(senha, p[0].senha) == 0)
  {

    printf("usuario nao logado ");
  }
  else
  {
    printf("\n\t\tUsuario logado com sucesso! \n");
  }
  if ((strcmp(login, p[0].login) == 0) && (strcmp(senha, p[0].senha) == 0))
  {
  }
  do
  {
    system("pause");

    system("cls");

    printf("\n\t\t\t--SEJA BEM VINDO-- ");
    printf("\n\t\tCENTRO DE DIAGNOSTICO COVID-19\n ");
    printf("\n\tAtencao profissional da saude! Informe o resultado da testagem.\n");
    printf("\n\t\t1-POSITIVO\n\t\t2-NEGATIVO\n");
    printf("\n\t\t  <<<insira o resultado>>> ");
    scanf("%d", &op);
    printf("\n\n\t O teste do seu paciente foi positivo para covid-19.\n");
    printf("\n ");
    printf("\n\t\t-----MENU-----\n");
    printf("\n\t\t\n1-cadastropaciente\n2-pesquisagp_risco\n3-sair\n");
    scanf("%i", &op);
    switch (op)
    {

    case 1:
      cadastropaciente();
      break;

    case 2:
      pesquisagp_risco();
      break;

    case 3:
      system("exit");

      break;

    default:
      printf("opcao invalida");
      break;
    }
  } while (op = 3);
}

void cadastropaciente()
{
  static int linha;
  do
  {
    printf("\n\n\t\t\tSeja bem vindo(a)!");
    printf("\n\n\t\tInsira algumas informacoes para o cadastro: \n");
    printf("\n\tDigite o nome do paciente: ");
    scanf("%s", &nome[linha]);
    printf("\n\tDigite o email: ");
    scanf("%s", &email[linha]);
    printf("\n\tDigite o cpf: ");
    scanf("%d", &cpf[linha]);
    printf("\n\tDigite a rua: ");
    scanf("%s", &rua[linha]);
    printf("\n\tNumero: ");
    scanf("%d", &numero[linha]);
    printf("\n\tDigite o bairro: ");
    scanf("%s", &bairro[linha]);
    printf("\n\tDigite a cidade: ");
    scanf("%s", &cidade[linha]);
    printf("\n\tDigite o estado: ");
    scanf("%s", &estado[linha]);
    printf("\n\tQual o cep: ");
    scanf("%d", &cep[linha]);
    printf("\n\tDigite o telefone: ");
    scanf("%d", &telefone[linha]);
    printf("\n\tDigite o dia do nascimento: ");
    scanf("%d", &diadenasc[linha]);
    printf("\n\tDigite o mes do nascimento: ");
    scanf("%d", &mesdenasc[linha]);
    printf("\n\tDigite o ano do nascimento: ");
    scanf("%d", &anodenasc[linha]);
    printf("\n\tDigite o dia do diagnostico: ");
    scanf("%d", &diadodiagnostico[linha]);
    printf("\n\tDigite o mes do diagnostico: ");
    scanf("%d", &mesdodiagnostico[linha]);
    printf("\n\tDigite o ano do diagnostico: ");
    scanf("%d", &anododiagnostico[linha]);
    printf("\n\tDigite se possui alguma comorbidade: ");
    scanf("%s", &comorbidade[linha]);
    printf("\n\tDigite o ano atual: ");
    scanf("%d", &anoatual);
    printf("\n\tDIGITE 1 PARA SEGUIR OU 0 PARA SAIR");
    scanf("%i", &op);
    linha++;
  } while (op == 1);

  do
  {

    FILE *arq;
    fpi = fopen("grupoderisco.txt", "a");
    idade = (anoatual - anodenascimento);
    if ((idade >= 65) && (comorbidade == "hipertensao", "obesidade", "tuberculose", "COVID-19", "diabetes"))
      ;
    {

      fprintf(fpi, "***DADOS***\nNOME:  %s\nCOMORBIDADE:  %S\nCEP: %d", nome, comorbidade, idade, cep);
      fclose(fpi);
      system("pause");
      return 0;
    }

  } while (fpi == NULL);
  printf("\nErro ao tentar criar arquivo\n");
  exit(0);
}

// GRUPO DE RISCO

void pesquisagp_risco()
{
  int cpfpesquisa;
  char emailpesquisa[40];
  int i;

  do
  {
    printf("\nDigite 1 para pesquisar por cpf ou digite 2 para pesquisar pelo email: ");
    scanf("%i", &op);
    switch (op)
    {
    case 1:
      printf("\nDIGITE O CPF: ");
      scanf("%i", &cpfpesquisa);
      printf("\nPaciente esta no grupo de risco.\n ");
      for (i = 0; i < SIZE; i++)
      {
        if (cpf[i] == cpfpesquisa)
          ;
        printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
      }

      break;
    case 2:
      printf("\nDIGITE O EMAIL: ");
      scanf("%s", &emailpesquisa);
      for (i = 0; i < SIZE; i++)
      {
        if (strcmp(email[i], emailpesquisa) == 0)
        {
          printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
        }
      }

      break;
    default:
      printf("Opcao invalida");
      break;
    }
    printf("\nDigite 1 para continuar a pesquisando ");
    scanf("%i", &op);
  } while (op == 1);
}