#include <iostream>
#include "list.h"

using namespace std;

int main() {
    ListaDuplamenteEncadeada* lista = criaLista();

    int opcao;
    string nome;
    int posicao;

    do {
        cout << "\n===== Sistema de Itinerario =====" << endl;
        cout << "1. Inserir parada no inicio" << endl;
        cout << "2. Inserir parada no fim" << endl;
        cout << "3. Inserir parada por posicao" << endl;
        cout << "4. Remover primeira parada" << endl;
        cout << "5. Remover ultima parada" << endl;
        cout << "6. Buscar parada por nome" << endl;
        cout << "7. Listar rota completa (ida)" << endl;
        cout << "8. Listar rota em ordem inversa" << endl;
        cout << "9. Contar paradas" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cout << "Nome da parada: ";
                getline(cin, nome);
                insereInicio(*lista, nome);
                break;
            case 2:
                cout << "Nome da parada: ";
                getline(cin, nome);
                insereFim(*lista, nome);
                break;
            case 3:
                cout << "Posicao (0 a " << numeroElementos(*lista) << "): ";
                cin >> posicao;
                cin.ignore();
                cout << "Nome da parada: ";
                getline(cin, nome);
                inserePosicao(*lista, nome, posicao);
                break;
            case 4:
                removeInicio(*lista);
                break;
            case 5:
                removeFim(*lista);
                break;
            case 6:
                cout << "Termo de busca: ";
                getline(cin, nome);
                buscaPorNome(*lista, nome);
                break;
            case 7:
                mostrarLista(*lista);
                break;
            case 8:
                mostrarListaInversa(*lista);
                break;
            case 9:
                cout << "Total de paradas: " << numeroElementos(*lista) << endl;
                break;
            case 0:
                cout << "Encerrando o sistema." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    } while (opcao != 0);

    destroiLista(*lista);
    delete lista;

    return 0;
}
