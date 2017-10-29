/*
 * File:   DirectedCycle.h
 * Author: Olivier Cuisenaire
 * Modified by: Alleman Adrien, Chatillon Jérémie et James Smith
 * 
 * Created on 08. octobre 2014, 10:46
 * Modified on 27.10.17
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
            this->g = &g;
            /* Fin implémenté par nous */
	}
	
	//indique la presence d'un cycle
	bool HasCycle() {
            /* Implémenté par nous */
            // Test de cycle sur tous les sommets
            for(int i = 0; i < g->V(); ++i){
                if(HasCycleRecursiv(i)) {
                    return true;
                }
            }
            
            return false;
            /* Fin implémenté par nous */
	}
	
	//liste les indexes des sommets formant une boucle
	std::list<int> Cycle() {
            /* Implémenté par nous */
            // cycle contient actuellement le parcours en profondeur interrompu lorsqu'on a trouvé une boucle.
            // on va le vider jusqu'à trover le node terminal de la boucle pour isoler celle-ci.
            while(cycle.front() != cycle.back()){
                cycle.pop_front();
            }
            return cycle;
            /* Fin implémenté par nous */
	}
private : 
	/* Définit par nous */
        bool HasCycleRecursiv(int v){
            std::list<int> adjList = g->adjacent(v);
            
            cycle.push_back(v);
            marked[v] = true;
            stacked[v] = true;
            
            //parcours des voisins de v
            while(adjList.size()){
                if(cycleFound) {
                    return true;
                }
                // Encore des voisins à parcourir
                else if(!marked.at(adjList.front())){
                    HasCycleRecursiv(adjList.front());
                } 
                // Cycle trouvé!
                else if (stacked.at(adjList.front())){
                    
                    //ajoutes le dernier du cycle
                    cycle.push_back(adjList.front());
                     
                    cycleFound = true;
                }
                adjList.pop_front();
            }
            stacked[v] = false;
            //retour d'un appel récursif sans avoir trouvé de cycle on retire de la liste
            if(!cycleFound) {
                cycle.pop_back();
            }
            return cycleFound;
        }
	/* End Définit par nous */
};

#endif
