// Operacoes sobre filas
#include <stdio.h>
#include <stdlib.h>

// Definicao de cada elemento da fila
typedef struct elemento
{
  int valor;
  struct elemento *ptr_proximo;
} elemento;

// Definicao do descritor. Ponteiros que armazezam o inicio e o final da fila
typedef struct descritor
{
  struct elemento *ptr_inicio_fila;
  struct elemento *ptr_fim_fila;
} descritor;

///////////////////////////////////////////
////////////FUNÇÃO DO EXERCÍCIO///////////
//////////////////////////////////////////

// Calcula o maior, menor, e a média aritmética da fila
void calcular_elementos(elemento *fila)
{

  int maior = fila->valor, menor = fila->valor, count = 0;
  float soma = 0, media = 0;

  while (fila != NULL)
  {

    if (fila->valor > maior)
    {
      maior = fila->valor;
    }
    if (fila->valor < menor)
    {
      menor = fila->valor;
    }

    soma += fila->valor;
    count += 1;

    fila = fila->ptr_proximo;
  }

  media = soma / count;
  printf("\nMaior: %d\nMenor: %d\nMedia:%.2f\n", maior, menor, media);
}

// Criacao de um elemento da fila
elemento *cria_elemento(int valor)
{
  elemento *novo = malloc(sizeof(elemento));
  novo->valor = valor;
  novo->ptr_proximo = NULL;
  return novo;
}

// Verifica se a fila esta vazia. Se fila vazia retorna 1, sen�o retorna 0
int empty(descritor *desc)
{
  if (desc->ptr_inicio_fila == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// Insere um elemento na fila seguindo o criterio FIFO
void enqueue(descritor *desc, elemento *novo)
{
  if (empty(desc) == 1)
  { // se fila vazia
    desc->ptr_inicio_fila = novo;
    desc->ptr_fim_fila = novo;
  }
  else
  { // se fila n�o vazia
    desc->ptr_fim_fila->ptr_proximo = novo;
    desc->ptr_fim_fila = novo;
  }
}

// Remove um elemento da fila seguindo o criterio FIFO
elemento *dequeue(descritor *desc)
{
  if (empty(desc) == 0)
  { // se fila nao vazia
    elemento *aux = desc->ptr_inicio_fila;
    desc->ptr_inicio_fila = aux->ptr_proximo;
    if (desc->ptr_inicio_fila == NULL)
    { // se o elemento era unico na fila atualiza o final da fila tamb�m para NULL
      desc->ptr_fim_fila == NULL;
    }
    aux->ptr_proximo = NULL;
    return aux;
  }
  else
  {
    printf("A fila esta vazia! \n");
    return NULL;
  }
}

// Mostra os elementos da fila
void mostrar_fila(elemento *fila)
{

  while (fila != NULL)
  {
    printf(" |%d|", fila->valor);
    if (fila->ptr_proximo == NULL)
    {
      printf("   ---\n");
    }
    fila = fila->ptr_proximo;
  }
}

// Monta o menu do programa
void monta_menu()
{

  printf("//////////////////////////////////////////////////////////////// \n");
  printf("Operacoes sobre Filas \n");
  printf("Selecione a Opcao Desejada: \n");
  printf("   1 - Incluir \n");
  printf("   2 - Excluir \n");
  printf("   3 - Mostrar Fila \n");
  printf("   4 - Mostrar Maior, Menor e Media\n");
  printf("   0 - Sair \n");
  printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n \n");
  printf("Qual a sua opcao: ");
}

int main()
{
  int op = 1;
  int valor = 0;

  descritor *desc = (descritor *)malloc(sizeof(descritor));
  desc->ptr_inicio_fila = NULL;
  desc->ptr_fim_fila = NULL;

  elemento *excluido = NULL;
  elemento *novo = NULL;
  do
  {
    monta_menu();
    scanf("%d", &op);
    // system("clear");
    switch (op)
    {
    case 1:
      printf("Informe um valor para o novo elemento da fila: ");
      scanf("%d", &valor);
      novo = cria_elemento(valor);
      enqueue(desc, novo);
      break;
    case 2:

      excluido = dequeue(desc);
      if (excluido != NULL)
      {
        printf("Valor do elemento excluido: %d \n", excluido->valor);
        free(excluido);
      }
      break;
    case 3:
      mostrar_fila(desc->ptr_inicio_fila);
      break;
    //////////////////////////////////////////////////////////////////////////////////////////
    ////DEMONSTRACAO DO EXERCICIO(preencher a fila previamente com as operações anteriores)///
    //////////////////////////////////////////////////////////////////////////////////////////
    case 4:
      calcular_elementos(desc->ptr_inicio_fila);
      break;
    }
    system("pause");
  } while (op != 0);
}
