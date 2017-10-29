/*
 * File:   DFSOrder.h
 * Author: Cuisenaire
 *
 * Modified by: Alleman Adrien, Chatillon Jérémie and Smith James
 * Modified the: 29.10.2017
 * Labo 2
 * Created on 3. novembre 2014, 08:23
 */


#include <cstdlib>
#include <iostream>
#include "DiGraph.h"
#include "TopologicalSort.h"

// vous devez reutiliser celui du labo 1, ex 2 (cf. donnee)
#include "Util.h"
#include "SymbolGraph.h"

using namespace std;

//methode permettant de verifier le graphe trie par rapport au fichier d'entree
bool checkOrder(const std::vector<int>& order,
                const SymbolGraph<DiGraph>& SG,
                const std::string& filename,
                char delim) {

    std::vector<int> positionInOrder(order.size());
    for( size_t i = 0; i < order.size(); ++i )
        positionInOrder[order[i]] = int(i);
    
    bool ok = true;
    
    std::string line;
    
    std::ifstream s(filename);
    while (std::getline(s, line))
    {
        auto names = split(line,delim);
        
        for(size_t i = 1; i < names.size(); ++i) {
         
            int v = SG.index(names[0]); // module
            int w = SG.index(names[i]); // ieme prerequis
            
            if ( positionInOrder[ v ] < positionInOrder [ w ]) {
                cout << "Erreur d'ordre : " << names[0] << " avant " << names[i] << endl;
                ok = false;
            } 
        }
    }
    s.close();
    
    return ok;
}



int main(int argc, const char * argv[]) {

    string fileName1 = "prerequis.txt";
    string fileName2 = "prerequis2.txt";
    
    //crée un SymboleGraphe avec le fichier 1
    SymbolGraph<DiGraph> g1(fileName1, ',');
    
    try {
        
        cout << fileName1 << " ";
        
        TopologicalSort<DiGraph> ts1(g1.G());
        
        cout << "est un DAG" << endl;
        
        vector<int> ordre = ts1.Order();
        for(int i : ordre){
            cout << "<" << g1.name(i) << "> ";
        }
        cout << endl;
    } catch(TopologicalSort<DiGraph>::GraphNotDAGException &e){
        cout << "n'est pas un DAG" << endl << "Cycle trouvé:" << endl;
        std::list<int> cycle = e.Cycle();
        
        for(auto i = cycle.begin(); i != cycle.end(); i++){
            cout << "<" << g1.name(*i) << "> ";
        }
        cout << endl;
    }
    
    
    //crée un SymboleGraphe avec le fichier 1
    SymbolGraph<DiGraph> g2(fileName2, ',');
    
    try {
        
        cout << endl <<  fileName2 << " ";
        
        TopologicalSort<DiGraph> ts2(g2.G());
        
        cout << "est un DAG" << endl;
        
        vector<int> ordre = ts2.Order();
        for(int i : ordre){
            cout << "<" << g2.name(i) << "> ";
        }
        
    } catch(TopologicalSort<DiGraph>::GraphNotDAGException &e){
        cout << "n'est pas un DAG" << endl << "Cycle trouvé:" << endl;
        std::list<int> cycle = e.Cycle();
        
        for(auto i = cycle.begin(); i != cycle.end(); i++){
            cout << "<" << g2.name(*i) << "> ";
        }
        cout << endl;
    }
    
    return EXIT_SUCCESS;
}
