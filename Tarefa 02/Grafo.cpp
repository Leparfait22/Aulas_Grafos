/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      Komi Parfait Moussougan
 * Matricula: 2211100031
 */

#include "Grafo.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

Grafo:: Grafo(int num_vertices){
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    list_adj_.resize(num_vertices);
}

void Grafo::insere_aresta(Aresta e){
    if(e.v1 == e.v2){
        return;
    }
    auto iterador = find(list_adj_[e.v1].begin(), list_adj_[e.v1].end(), e.v2);
    if (iterador != list_adj_[e.v1].end()) {
    } else {
        list_adj_[e.v1].push_front(e.v2);
        list_adj_[e.v2].push_front(e.v1);

        num_arestas_++;
    }
}


std::vector<int> Grafo::busca_largura(int v){
    std::queue<int> fila;
    std::vector<int> marcado(num_vertices_,0);
    std::vector<int> dist(num_vertices_,0);
    std::vector<int> pai(num_vertices_,0);

    marcado[v] = 1;
    pai[v] = -1;
    dist[v] = 0;
    fila.push(v);
    while(!fila.empty()){
        int w = fila.front();
        fila.pop();
        for(int u = 0; u < num_vertices_; u++){
            Aresta e(w,u);
            auto iterador = find(list_adj_[e.v1].begin(),list_adj_[e.v1].end(), e.v2);

            if(iterador!= list_adj_[e.v1].end()){
                if(marcado[u] == 0){
                        marcado[u] = 1;
                        pai[u] = w;
                        dist[u] = dist[w] + 1;
                        fila.push(u);   
                }
            }
        }
    }
    return dist;
    
}

void Grafo::imprime_comparsas(int v){

    std::vector<int> resultado = busca_largura(v);
    std::vector<int> comparsas;


    for(int i =0; i< resultado.size(); i++){
        if(resultado[i] <= 3 && resultado[i] != 0){
            comparsas.push_back(i);
        }
    } 
    std::sort(comparsas.begin(),comparsas.end());
    cout << v << ": " ;
    for(int i = 0; i < comparsas.size(); i++){
        cout << comparsas[i] << " ";
    }
    cout << endl;

}

