/*
 * File:   DirectedCycle.h
 * Author: Olivier Cuisenaire
 * Created on 08. octobre 2014, 10:46
 *
 * A implementer
 * Classe permettant la detection de cycle sur un graphe oriente
 */

#ifndef ASD2_DirectedCycle_h
#define ASD2_DirectedCycle_h

#include <list>

#include "ParcoursEnProfondeur.h"

template<typename GraphType>
class DirectedCycle {
private:
	/* A DEFINIR */
    std::vector<bool> marked;
    std::vector<bool> stacked;
    bool cycleFound = false;
    const GraphType * g;
        
	
public:
	//constructeur
	DirectedCycle(const GraphType& g) {
            /* Implémenté par nous */
            marked.resize(g.V(), false);
            stacked.resize(g.V(), false);
            this->g = g;
            /* Fin implémenté par nous */
	}
	
	//indique la presence d'un cycle
	bool HasCycle() {
            return HasCycleRecursiv(0);
	}
	
        
        
	//liste les indexes des sommets formant une boucle
	std::list<int> Cycle() {
		/* A IMPLEMENTER */
                // Liste FIFO ajout 
		//return ...
	}
private : 
        bool HasCycleRecursiv(int v){
            std::list<int> adjList = g.adjacent(v);
            marked[v] = true;
            stacked[v] = true;
            for(size_t w = 0; w < adjList.size(); ++w){
                if(cycleFound) {
                    return true;
                }
                else if(!marked[adjList[w]]){
                    HasCycle(adjList[w]);
                } 
                else if (stacked[adjList[w]]){
                    cycleFound = true;
                }
            }
            stacked[v] = false;
        }
};

#endif
