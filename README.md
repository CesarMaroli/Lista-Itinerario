## Descricao
Sistema de gerenciamento de itinerario de onibus desenvolvido em C++, utilizando lista duplamente encadeada como estrutura de dados principal. O sistema permite cadastrar, remover, buscar e listar paradas de uma rota de transporte coletivo por meio de um menu interativo.

--------------------------------

## Requisitos
- Compilador C++ (g++ ou equivalente)

--------------------------------

## Compilacao e Execucao

```bash
g++ -o main main.cpp src/list.cpp -I include
./main
```

Para executar os testes:
```bash
g++ -o tests tests/tests.cpp src/list.cpp -I include
./tests
```

--------------------------------

## Pontos de Analise e Justificativa

### 1. Qual variacao de lista foi escolhida?

Foi escolhida a **lista duplamente encadeada**. Nessa estrutura, cada node possui dois ponteiros: um para o proximo node (`proximo`) e outro para o node anterior (`anterior`). A struct da lista tambem possui um ponteiro `fim` que aponta para o ultimo elemento.

### 2. Por que essa estrutura e mais adequada para esse problema?

A lista duplamente encadeada e a mais adequada pelas seguintes razoes, com base nas operacoes exigidas:

- **Listar rota em ordem inversa**: como cada node possui um ponteiro para o anterior, basta percorrer a lista a partir do `fim` ate o `inicio`, sem precisar de recursao ou estruturas auxiliares.
- **Remover ultima parada**: com o ponteiro `fim` e o ponteiro `anterior` do ultimo node, a remocao do final e feita diretamente, sem precisar percorrer toda a lista como seria necessario numa lista simplesmente encadeada.
- **Inserir no inicio e no fim**: ambas as operacoes sao diretas gracas aos ponteiros `inicio` e `fim`.
- **Inserir por posicao**: a navegacao bidirecional permite percorrer a lista em ambas as direcoes.

Numa lista simplesmente encadeada nao haveria o ponteiro `anterior`, tornando a listagem inversa e a remocao do ultimo elemento operacoes mais custosas.

### 3. Haveria algum cenario real em que outra variacao seria mais vantajosa?

Sim. Em uma **linha circular de onibus**, onde o trajeto nao tem ponto de inicio e fim definidos (o onibus percorre continuamente o mesmo circuito), uma **lista circular encadeada** seria mais vantajosa. Nessa estrutura, o ultimo node aponta de volta para o primeiro, formando um ciclo. Isso permite simular o percurso continuo do onibus sem precisar verificar se chegou ao fim da lista — ao atingir o ultimo ponto, a travessia continua naturalmente pelo primeiro.
