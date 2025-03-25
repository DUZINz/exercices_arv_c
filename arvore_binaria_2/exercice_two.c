#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    int value;
    struct arv *um;
    struct arv *dois;
} arv;

arv *nova_arv(int value)
{
    arv *nov_arv = (arv *)malloc(sizeof(arv));
    if (nov_arv == NULL)
    {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    nov_arv->value = value;
    nov_arv->um = NULL;
    nov_arv->dois = NULL;
    return nov_arv;
}
arv *inserir(arv *raiz, int value)
{
    if (raiz == NULL)
    {
        return nova_arv(value);
    }
    if (value < raiz->value)
    {
        raiz->um = insert(raiz->dois, value);
    }
    else if (value > raiz->value)
    {
        raiz->um = insert(raiz->dois, value);
    }
    return raiz;
}