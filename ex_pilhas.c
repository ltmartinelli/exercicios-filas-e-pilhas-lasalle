// Operacoees sobre pilhas
#include <stdio.h>
#include <stdlib.h>

// Definicao de cada elemento da pilha
typedef struct elemento
{
   float valor;
   struct elemento *anterior;
} elemento;



// Criacao de um elemento da pilha
elemento *cria_elemento(float valor)
{
   //  elemento * novo = malloc(sizeof(elemento));
   elemento *novo;
   novo = malloc(sizeof(elemento));

   novo->valor = valor;
   novo->anterior = NULL;
   return novo;
}

// Inserir elementos na pilha
elemento *push(elemento *topo, float valor)
{
   elemento *aux = topo;
   topo = cria_elemento(valor);
   topo->anterior = aux;
   return topo;
}


// Verifica se a pilha esta vazia (retorna 1) ou tem elementos (Retorna 0)
int empty(elemento *topo)
{
   if (topo == NULL)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

elemento *pop(elemento *topo)
{
   elemento *aux;
   if (empty(topo) == 0)
   { // se pilha n�o est� vazia
      aux = topo;
      topo = topo->anterior;
      free(aux);
   }
   else
   {
      printf("A pilha esta vazia! \n");
   }
   return topo;
}

/////////////////////////////////////////
//////////FUNCAO DO EXERCICIO///////////
////////////////////////////////////////

void concatena_pilhas(elemento **Pilha1, elemento *Pilha2)
{
   if (Pilha2->anterior != NULL)
   {
      concatena_pilhas(Pilha1, Pilha2->anterior);
   }
   *Pilha1 = push(*Pilha1, Pilha2->valor);
   pop(Pilha2);
   return;
}


void mostrar_pilha(elemento *topo)
{
   int first = 1;
   if (topo != NULL)
   {
      while (topo != NULL)
      {
         printf("   ---\n");
         if (first)
         {
            printf("   |%.1f| <---- Topo \n", topo->valor);
            first = 0;
         }
         else
         {
            printf("   |%.1f|\n", topo->valor);
         }
         if (topo->anterior == NULL)
         {
            printf("   ---\n");
         }
         topo = topo->anterior;
      }
   }
   else
   {

      printf("A pilha esta vazia! \n");
   }
}

int main()
{

//////////////////////////////////////////
///////////////DEMONSTRACAO///////////////
/////////////////////////////////////////

   float a = 1.0, b = 4.5, c = 2.1;
   float one = 9.8, two = 3.1, three = 7.2;

   elemento *Pilha1 = NULL; 
   elemento *Pilha2 = NULL;

   Pilha1 = push(Pilha1, a);
   Pilha1 = push(Pilha1, b);
   Pilha1 = push(Pilha1, c);
   Pilha2 = push(Pilha2, one);
   Pilha2 = push(Pilha2, two);
   Pilha2 = push(Pilha2, three);

   concatena_pilhas(&Pilha1, Pilha2);

   mostrar_pilha(Pilha1);
}
