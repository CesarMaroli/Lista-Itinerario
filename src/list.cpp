#include "list.h"
#include <iostream>

using namespace std;

ListaDuplamenteEncadeada* criaLista() {
    ListaDuplamenteEncadeada* lista = new ListaDuplamenteEncadeada();
    lista->cardinalidade = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void destroiLista(ListaDuplamenteEncadeada &lista) {
    Node* temp;

    while (lista.inicio != NULL) {
        temp = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete temp;
    }

    lista.cardinalidade = 0;
    lista.fim = NULL;
}

void insereInicio(ListaDuplamenteEncadeada &lista, string nome) {
    Node* novoNode = new Node();
    novoNode->nome = nome;
    novoNode->anterior = NULL;
    novoNode->proximo = lista.inicio;

    if (lista.inicio != NULL) {
        lista.inicio->anterior = novoNode;
    } else {
        lista.fim = novoNode;
    }

    lista.inicio = novoNode;
    lista.cardinalidade++;
}

void insereFim(ListaDuplamenteEncadeada &lista, string nome) {
    Node* novoNode = new Node();
    novoNode->nome = nome;
    novoNode->proximo = NULL;
    novoNode->anterior = lista.fim;

    if (lista.fim != NULL) {
        lista.fim->proximo = novoNode;
    } else {
        lista.inicio = novoNode;
    }

    lista.fim = novoNode;
    lista.cardinalidade++;
}

void inserePosicao(ListaDuplamenteEncadeada &lista, string nome, int posicao) {
    if (posicao < 0 || posicao > lista.cardinalidade) {
        cout << "Posicao invalida para insercao." << endl;
        return;
    }

    if (posicao == 0) {
        insereInicio(lista, nome);
        return;
    }

    if (posicao == lista.cardinalidade) {
        insereFim(lista, nome);
        return;
    }

    Node* novoNode = new Node();
    novoNode->nome = nome;

    Node* atual = lista.inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    novoNode->anterior = atual->anterior;
    novoNode->proximo = atual;
    atual->anterior->proximo = novoNode;
    atual->anterior = novoNode;
    lista.cardinalidade++;
}

void removeInicio(ListaDuplamenteEncadeada &lista) {
    if (lista.inicio == NULL) {
        cout << "Nao e possivel remover: lista vazia." << endl;
        return;
    }

    Node* removido = lista.inicio;
    cout << "Parada removida: " << removido->nome << endl;

    if (lista.inicio == lista.fim) {
        lista.inicio = NULL;
        lista.fim = NULL;
    } else {
        lista.inicio = lista.inicio->proximo;
        lista.inicio->anterior = NULL;
    }

    delete removido;
    lista.cardinalidade--;
}

void removeFim(ListaDuplamenteEncadeada &lista) {
    if (lista.fim == NULL) {
        cout << "Nao e possivel remover: lista vazia." << endl;
        return;
    }

    Node* removido = lista.fim;
    cout << "Parada removida: " << removido->nome << endl;

    if (lista.inicio == lista.fim) {
        lista.inicio = NULL;
        lista.fim = NULL;
    } else {
        lista.fim = lista.fim->anterior;
        lista.fim->proximo = NULL;
    }

    delete removido;
    lista.cardinalidade--;
}

void buscaPorNome(const ListaDuplamenteEncadeada &lista, string nome) {
    if (lista.inicio == NULL) {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* atual = lista.inicio;
    int pos = 0;
    bool encontrou = false;

    while (atual != NULL) {
        if (atual->nome.find(nome) != string::npos) {
            cout << "Encontrada: " << atual->nome << " (posicao " << pos << ")" << endl;
            encontrou = true;
        }
        atual = atual->proximo;
        pos++;
    }

    if (!encontrou) {
        cout << "Nenhuma parada encontrada com o termo: " << nome << endl;
    }
}

void mostrarLista(const ListaDuplamenteEncadeada &lista) {
    if (lista.inicio == NULL) {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* atual = lista.inicio;
    int pos = 1;

    cout << "Rota (ida):" << endl;
    while (atual != NULL) {
        cout << pos << ". " << atual->nome << endl;
        atual = atual->proximo;
        pos++;
    }
}

void mostrarListaInversa(const ListaDuplamenteEncadeada &lista) {
    if (lista.fim == NULL) {
        cout << "Lista vazia." << endl;
        return;
    }

    Node* atual = lista.fim;
    int pos = lista.cardinalidade;

    cout << "Rota (volta):" << endl;
    while (atual != NULL) {
        cout << pos << ". " << atual->nome << endl;
        atual = atual->anterior;
        pos--;
    }
}

int numeroElementos(const ListaDuplamenteEncadeada &lista) {
    return lista.cardinalidade;
}
