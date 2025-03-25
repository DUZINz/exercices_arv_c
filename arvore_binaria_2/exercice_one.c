// aqui vou fazer uma arvore que A árvore deve manter a propriedade de que o nó da esquerda tem
// um valor menor que o nó pai e o nó da direita tem um valor maior que o nó pa
#include <stdio.h>
#include <stdlib.h>

// define a estrutura para o nó
typedef struct _arvore
{
    int value;
    struct _arvore *esq;
    struct _arvore *dir;
} _arvore;

// função para criar um novo nó
_arvore *nov_arv(int value)
{
    _arvore *new_arv = (_arvore *)malloc(sizeof(_arvore));
    if (new_arv == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    new_arv->value = value;
    new_arv->esq = NULL;
    new_arv->dir = NULL;
    return new_arv;
}

// função para inserir um valor na arvore binaria de busca
_arvore *insert(_arvore *raiz, int value)
{
    // se a arvore ta vazia cria-se um nó
    if (raiz == NULL)
    {
        return nov_arv(value);
    }
    // Se o valor a ser inserido é menor que o valor do nó atual, insere à esquerda
    if (value < raiz->value)
    {
        raiz->esq = insert(raiz->dir, value);
    }
    // Se o valor a ser inserido é maior, insere à direita
    else if (value > raiz->value)
    {
        raiz->dir = insert(raiz->dir, value);
    }
    // aqui retorna a raiz
    return raiz;
}
// função para imprimir em ordem crescente
void imprimir_em_ordem(_arvore *raiz)
{
    if (raiz != NULL)
    {
        imprimir_em_ordem(raiz->esq); // visita a arvore da esquerda
        printf("%d", raiz->value);    // imprime o valor da arvore
        imprimir_em_ordem(raiz->dir); // visita a arvore direita
    }
}
// função para liberar a memoria
void liberar_arv(_arvore *raiz)
{
    if (raiz != NULL)
    {
        liberar_arv(raiz->esq); // libera a arv da esquerda
        liberar_arv(raiz->dir); // da direita
        free(raiz);             // e o nó
    }
}
// função principal
int main()
{
    _arvore *raiz = NULL;

    // se inseri elementos na arv
    raiz = insert(raiz, 50);
    raiz = insert(raiz, 30);
    raiz = insert(raiz, 20);
    raiz = insert(raiz, 40);
    raiz = insert(raiz, 70);
    raiz = insert(raiz, 60);
    raiz = insert(raiz, 80);

    printf("Elementos da arvore em ordem crescente:\n");
    imprimir_em_ordem(raiz);
    printf(" \n ");

    // libera a memoria da arv
    liberar_arv(raiz);

    return 0;
}