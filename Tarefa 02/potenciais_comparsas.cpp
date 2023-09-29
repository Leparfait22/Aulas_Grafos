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
#include <sstream>
#include <typeinfo>

using namespace std;

int main() {
    int P, L , X , Y, O;

    cin >> P >> L;
    cin.ignore();
    Grafo grafo(P);

    for(int i = 0; i < L ; i++){
        vector <string> operacao;
        string entrada;
        getline(cin, entrada);

        stringstream ss(entrada);

        while(ss >> entrada){
            operacao.push_back(entrada);
        }
        if((operacao[2] == "W")){
            X = stoi(operacao[0]);
            Y = stoi(operacao[1]);
            Aresta e(X,Y);
            grafo.insere_aresta(e);
        }

    }

    cin >> O;
    for(int i = 0; i < O;i++){
        int comparsa;
        cin >> comparsa;
        grafo.imprime_comparsas(comparsa);

    }

    return 0;
}
