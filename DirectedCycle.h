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
    /* Définit par nous */
    std::vector<bool> marked;
    std::vector<bool> stacked;
    std::list<int> cycle;
    
    bool cycleFound = false;
    const GraphType * g;
    /* End Définit par nous */
        
	
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
            /* Implémenté par nous */
            return HasCycleRecursiv(0);
            /* Fin implémenté par nous */
	}
	
        
        
	//liste les indexes des sommets formant une boucle
	std::list<int> Cycle() {
            /* Implémenté par nous */
            // cycle contient actuellement le parcours en profondeur inerrompu lorsqu'on a trouvé une boucle.
            // on va le vider jusqu'à trover le node terminal de la boucle pour isoler celle-ci.
            while(cycle.front() != cycle.end()){
                cycle.pop_front();
            }
            return cycle;
            /* Fin implémenté par nous */
	}
private : 
	/* Définit par nous */
        bool HasCycleRecursiv(int v){
            std::list<int> adjList = g.adjacent(v);
            marked[v] = true;
            stacked[v] = true;
            for(size_t w = 0; w < adjList.size(); ++w){
                if(cycleFound) {
                    return true;
                }
                else if(!marked[adjList[w]]){
                    HasCycleRecursiv(adjList[w]);
                } 
                else if (stacked[adjList[w]]){
                    cycleFound = true;
                }
            }
            stacked[v] = false;
        }
	/* End Définit par nous */
};

#endif
