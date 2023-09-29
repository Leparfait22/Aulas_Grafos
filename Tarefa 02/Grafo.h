/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Komi Parfait Moussougan
 * Matricula: 2211100031
 */

#ifndef GRAFO_H

#define GRAFO_H
#include "Aresta.h"
#include <vector>
#include <list>


class Grafo {
    public:
    Grafo(int num_vertices);
    void insere_aresta(Aresta e);
    std::vector<int> busca_largura(int v);
    void imprime_comparsas(int v);
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>> list_adj_;
};

#endif /* GRAFO_H */
