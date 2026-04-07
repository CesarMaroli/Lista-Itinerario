#include <cassert>
#include <iostream>
#include "../include/list.h"

using namespace std;

void teste_criaLista() {
    cout << "Testando criaLista()..." << endl;

    ListaDuplamenteEncadeada* lista = criaLista();
    assert(lista != NULL);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);
    assert(lista->fim == NULL);

    delete lista;
    cout << "criaLista() passou em todos os testes" << endl;
}

void teste_insereInicio() {
    cout << "Testando insereInicio()..." << endl;

    ListaDuplamenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    insereInicio(*lista, "Terminal Centro");
    assert(lista->cardinalidade == 1);
    assert(lista->inicio->nome == "Terminal Centro");
    assert(lista->inicio == lista->fim);

    insereInicio(*lista, "Praca XV");
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->nome == "Praca XV");
    assert(lista->fim->nome == "Terminal Centro");

    destroiLista(*lista);
    delete lista;
    cout << "insereInicio() passou em todos os testes" << endl;
}

void teste_insereFim() {
    cout << "Testando insereFim()..." << endl;

    ListaDuplamenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    insereFim(*lista, "Terminal Centro");
    assert(lista->cardinalidade == 1);
    assert(lista->inicio->nome == "Terminal Centro");
    assert(lista->inicio == lista->fim);

    insereFim(*lista, "Shopping");
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->nome == "Terminal Centro");
    assert(lista->fim->nome == "Shopping");

    destroiLista(*lista);
    delete lista;
    cout << "insereFim() passou em todos os testes" << endl;
}

void teste_inserePosicao() {
    cout << "Testando inserePosicao()..." << endl;

    ListaDuplamenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    inserePosicao(*lista, "Terminal", 0);
    assert(lista->cardinalidade == 1);

    inserePosicao(*lista, "Shopping", 1);
    assert(lista->cardinalidade == 2);

    inserePosicao(*lista, "Hospital", 1);
    assert(lista->cardinalidade == 3);
    assert(lista->inicio->proximo->nome == "Hospital");

    destroiLista(*lista);
    delete lista;
    cout << "inserePosicao() passou em todos os testes" << endl;
}

void teste_removeInicio() {
    cout << "Testando removeInicio()..." << endl;

    ListaDuplamenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    insereFim(*lista, "Terminal");
    insereFim(*lista, "Shopping");
    insereFim(*lista, "Universidade");

    removeInicio(*lista);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->nome == "Shopping");

    destroiLista(*lista);
    delete lista;
    cout << "removeInicio() passou em todos os testes" << endl;
}

void teste_removeFim() {
    cout << "Testando removeFim()..." << endl;

    ListaDuplamenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    insereFim(*lista, "Terminal");
    insereFim(*lista, "Shopping");
    insereFim(*lista, "Universidade");

    removeFim(*lista);
    assert(lista->cardinalidade == 2);
    assert(lista->fim->nome == "Shopping");

    destroiLista(*lista);
    delete lista;
    cout << "removeFim() passou em todos os testes" << endl;
}

void teste_numeroElementos() {
    cout << "Testando numeroElementos()..." << endl;

    ListaDuplamenteEncadeada* lista = criaLista();
    assert(lista != NULL);

    assert(numeroElementos(*lista) == 0);

    insereFim(*lista, "Terminal");
    assert(numeroElementos(*lista) == 1);

    insereFim(*lista, "Shopping");
    assert(numeroElementos(*lista) == 2);

    removeInicio(*lista);
    assert(numeroElementos(*lista) == 1);

    destroiLista(*lista);
    delete lista;
    cout << "numeroElementos() passou em todos os testes" << endl;
}

int main() {
    cout << "\n=========================================" << endl;
    cout << "  INICIANDO TESTES DA LISTA ENCADEADA" << endl;
    cout << "=========================================" << endl << endl;

    teste_criaLista();
    teste_insereInicio();
    teste_insereFim();
    teste_inserePosicao();
    teste_removeInicio();
    teste_removeFim();
    teste_numeroElementos();

    cout << "\n=========================================" << endl;
    cout << "  TODOS OS TESTES PASSARAM COM SUCESSO!" << endl;
    cout << "=========================================" << endl << endl;

    return 0;
}
