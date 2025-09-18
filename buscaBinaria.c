#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaração das Funções


//1.Busca Sequencial

int buscaSequencialIterativa(const char* lista[],int tamanho,const char* item);
int buscaSequencialRecursiva(const char* lista[],int tamanho,const char* item);
int buscaSequencialRecursiva_aux(const char* lista[],int tamanho,const char* item,int indice);

//2.Busca Binária

int buscaBinariaIterativa(const char* lista[],int tamanho,const char*item);
int buscaBinariaRecursiva(const char* lista[],int tamanho,const char* item);
int buscaBinariaRecursiva_aux(const char* lista[],const char* item,int inicio,int fim);

//Função auxiliar para imprimir os resultados de forma organizada

void imprimirResultado(const char* nomeDaBusca,const char* item,int resultado);

//---Função Principal---
int main(){
    //Para Busca Binaria Funcionar a lista deve estar ordenada alfabeticamente
    const char* listaDeCompras[]={
        "arroz",
        "batata",
        "cebola",
        "detergente",
        "feijão",
        "leite",
        "macarrao",
        "oleo",
        "sal",
        "tomate"
    };

    //calcular o numero de itens da lista.
    int tamanhoDaLista=sizeof(listaDeCompras)/sizeof(listaDeCompras[0]);

    //itens que vamos procurar para demostrar os algotitmos.
    const char* itemExistente="leite";
    const char* itemInexistente="queijo";

    printf("---DEMONSTRACAO DE ALGORITMOS DE BUSCA EM LISTA DE TEXTO ---\n");
    printf("lista utilizada:[arroz,batata,cebola,detergente,feijao,leite,macarrao,oleo,sal,tomate]\n");
    printf("----------------------------------------------------------------\n");

    //testando a Busca sequencial---

    printf("---1. BUSCA SEQUENCIAL ----\n");
    //1.1 versao iterativa
    int res1=buscaSequencialIterativa(listaDeCompras,tamanhoDaLista,itemExistente);
    imprimirResultado("Sequencial Iterativa",itemExistente,res1);

    int res2=buscaSequencialIterativa(listaDeCompras,tamanhoDaLista,itemInexistente);
    imprimirResultado("Sequencia Iterativa",itemInexistente,res2);
    printf("\n");

    //1.2 versao Recursiva---
    int res3=buscaSequencialRecursiva(listaDeCompras,tamanhoDaLista,itemExistente);
    imprimirResultado("Sequencial Recursiva",itemExistente,res3);

    int res4=buscaSequencialRecursiva(listaDeCompras,tamanhoDaLista,itemInexistente);
    imprimirResultado("Sequencial Recursiva",itemInexistente,res4);
    printf("----------------------------------------------------\n\n");

    //Testando a Busca Binaria---
    
    printf("----2.BUSCA BINARIA(requer lista ordenada)---\n");
    //2.1-versao iterativa

    int res5=buscaBinariaIterativa(listaDeCompras,tamanhoDaLista,itemExistente);
    imprimirResultado("Binaria Iterativa",itemExistente,res5);

    int res6=buscaBinariaIterativa(listaDeCompras,tamanhoDaLista,itemInexistente);
    imprimirResultado("Binaria Iterativa",itemInexistente,res6);
    printf("\n");

    //2.2 Versao Recursiva

    int res7=buscaBinariaRecursiva(listaDeCompras,tamanhoDaLista,itemExistente);
    imprimirResultado("Binaria Recursiva",itemExistente,res7);

    int res8=buscaBinariaRecursiva(listaDeCompras,tamanhoDaLista,itemInexistente);
    imprimirResultado("Binaria Recursiva",itemInexistente,res8);

     printf("----------------------------------------------------\n");



    return 0;
}

//imprementação das funações
/**
 * @brief //busca sequencial usando um lago
 * @param lista // o arrayy de string onde a busca sera feita
 * @param tamanho//o numero de elemnetos da lista
 * @param item//a strinf que esta sendo procurada
 * @return // o indice do item se encontrado,ou -1 caso contratio
 */

int buscaSequencialIterativa(const char* lista[],int tamanho,const char* item){
    //um laço for percorre toda a lista de 0 a -1
    for (int i = 0; i < tamanho; i++)
    {
        if (strcmp(lista[i],item)==0)
        {
            // se a strings forem iguais encontramos o item
           return i;
        }
        
    }
    //se o laço terminar e nao tivemos retornado nada significa
    //que o item nao esta na lista
    return -1;
}
/**
 * @brief funcao para busca sequencia recursiva
 * ela esconde a completidade do paramentro do indice 
 * 
 */

int buscaSequencialRecursiva(const char* lista[],int tamanho,const char* item){

    return buscaSequencialRecursiva_aux(lista,tamanho,item,0);
}
/**
 * @brief funcoa auxiliar que implementa a logica recursiva da busca sequencial
 * @param indice indice do elemento atual a ser verificado
 * @return o indice do item se encontrado ou -1 caso contratio
 */
int buscaSequencialRecursiva_aux(const char* lista[],int tamanho,const char* item,int indice){
    if (indice>=tamanho)
    {
        return -1;
    }
    if (strcmp(lista[indice],item)==0)
    {
       return indice;
    }
    
    return buscaSequencialRecursiva_aux(lista,tamanho,item,indice+1);

}

//2.Busca Binária

int buscaBinariaIterativa(const char* lista[],int tamanho,const char*item){
    int inicio=0;
    int fim=tamanho-1;
    int meio;

    while (inicio<=fim)
    {
        meio=inicio+(fim-inicio)/2;
        int comparacao=strcmp(lista[meio],item);
        if (comparacao==0)
        {
           return meio;
        }
        else if (comparacao>0)
        {
            fim=meio-1;
        }
        else{
            inicio=meio+1;
        }
        
    }
    return-1;
}
int buscaBinariaRecursiva(const char* lista[],int tamanho,const char* item){
    return buscaBinariaRecursiva_aux(lista,item,0,tamanho-1);

}
int buscaBinariaRecursiva_aux(const char* lista[],const char* item,int inicio,int fim){
    if (inicio>fim)
    {
        return -1;
    }
    int meio=inicio+(fim-inicio)/2;
    int comparacao=strcmp(lista[meio],item);

    if (comparacao==0)
    {
       return meio;
    }
    else if (comparacao>0)
    {
        return buscaBinariaRecursiva_aux(lista,item,inicio,meio-1);
    }
    else{
        return buscaBinariaRecursiva_aux(lista,item,meio+1,fim);
    }
}

void imprimirResultado(const char* nomeDaBusca,const char* item,int resultado) {
        printf("[%s] Buscando por \"%s\"... \n",nomeDaBusca,item);
        if (resultado !=-1)
        {
           printf("   -> Resultado : Item encontrado no indice %d.\n",resultado);

        }
        else{
            printf("   -> Resultado : Item nao encontrado na lista.\n");
        }
    }