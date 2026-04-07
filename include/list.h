#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

struct Node {
    string nome;
    Node* anterior;
    Node* proximo;
};

struct ListaDuplamenteEncadeada {
    int cardinalidade;
    Node* inicio;
    Node* fim;
};

ListaDuplamenteEncadeada* criaLista();
void destroiLista(ListaDuplamenteEncadeada &lista);
void insereInicio(ListaDuplamenteEncadeada &lista, string nome);
void insereFim(ListaDuplamenteEncadeada &lista, string nome);
void inserePosicao(ListaDuplamenteEncadeada &lista, string nome, int posicao);
void removeInicio(ListaDuplamenteEncadeada &lista);
void removeFim(ListaDuplamenteEncadeada &lista);
void buscaPorNome(const ListaDuplamenteEncadeada &lista, string nome);
void mostrarLista(const ListaDuplamenteEncadeada &lista);
void mostrarListaInversa(const ListaDuplamenteEncadeada &lista);
int numeroElementos(const ListaDuplamenteEncadeada &lista);

#endif
