#include "Grafo.h"
#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;


int main() {
    int vert,num;
    int captor_Aresta,captor_Vertice;
    int X,Y;
   // char operacao;

    cin >> vert >> num;
    cin.ignore();
    Grafo grafo(vert);
    for(int pass = 0;pass <num; pass++){
        vector <string> ope;
        string entrada;
        getline(cin, entrada);

        stringstream ss(entrada);

        while(ss >> entrada){
            ope.push_back(entrada);
        }
        // for(int i = 0; i< ope.size();i++){
        //     cout << "O tipo de " << ope[i] << "é : " << typeid(ope[i]).name() << endl;
        // }
        //cout << "Digite a operacão a realizar: ";
       // cin >> operacao >> X >> Y;
        if((ope[0]) == "I"){
             X = stoi(ope[1]);
             Y = stoi(ope[2]);
            Aresta e(X,Y);
            grafo.insere_aresta(e);
        }else if(ope[0] == "R"){
             X = stoi(ope[1]);
             Y = stoi(ope[2]);
            Aresta e(X,Y);
            grafo.remove_aresta(e);
        }else if(ope[0] == "E"){
            cout << grafo.num_arestas() << endl;
        }else if(ope[0] == "N"){
            cout << grafo.num_vertices() << endl;
        }else if (ope[0] == "Q"){
            X = stoi(ope[1]);
            grafo.remove_vertice(X);
        }else if(ope[0] == "P"){
            grafo.imprime();
        }
    }

    return 0;
}

 



//int V, O;
//     cin >> V >> O;
//     cin.ignore(); // Ignora o caractere de nova linha após a segunda entrada

//     Grafo meuGrafo(V);

//     for (int i = 0; i < O; i++) {
//         string entrada;
//         getline(cin, entrada);

//         istringstream iss(entrada);
//         char operacao;
//         int x = -1, y = -1; // Valores padrão

//         iss >> operacao;
//         if (operacao == 'I' || operacao == 'R') {
//             iss >> x >> y;
//         } else if (operacao == 'Q') {
//             iss >> x;
//         }


    // try {
    //     Grafo grafo(4);

    //     Aresta e(0,2);
    //     grafo.insere_aresta(e);
    //     Aresta e1(0,3);
    //     grafo.insere_aresta(e1);
    //     Aresta e2(1,3);
    //     grafo.insere_aresta(e2);
    //     grafo.remove_aresta(e);

    //     cout << grafo.num_arestas() << endl;
    //     grafo.remove_vertice(1);
    //     cout << grafo.num_vertices() << endl;

    //     grafo.imprime();

    // }
    // catch (const exception &e) {
    //     cerr << "exception: " << e.what() << "\n";
    // }