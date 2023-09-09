/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

/* Complete aqui */

#include "Grafo.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

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
int Grafo::num_arestas(){
    return num_arestas_;
}
int Grafo :: num_vertices(){
    return num_vertices_;
}

void Grafo::remove_aresta(Aresta e){  
    auto iterador = find(list_adj_[e.v1].begin(), list_adj_[e.v1].end(), e.v2);
        if (iterador != list_adj_[e.v1].end()) {
            list_adj_[e.v1].remove(e.v2);
            list_adj_[e.v2].remove(e.v1);
            num_arestas_--;
        }
}


void Grafo::imprime(){
    for(int i = 0;i < list_adj_.size();i++){
        cout <<  i << ":";
        for(const int& vertice : list_adj_[i]){
            cout<< " " << vertice;
        }
        cout << endl;
    }
}

void Grafo::remove_vertice(int v){
    if(v < 0 || v > num_vertices_){
        return;
    }
    for(int i =0;i < list_adj_.size();i++){
        if(i == v){
        for(auto vizinho: list_adj_[i]){
            Aresta e(v,vizinho);
            remove_aresta(e);
            break;
            }
        }
    }
    
    for(int i = 0;i < list_adj_.size();i++){
        for(int& vertice: list_adj_[i]){
            if(vertice > v){
                vertice -=1;
            }
        }
    }

    for(int i =0;i< list_adj_.size()-1;i++){
        if(i >=v){
            list_adj_[i] = list_adj_[i+1];
        }
    }
    num_vertices_--;
    list_adj_.resize(num_vertices_);
}


