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
            marked.resize(g.G().V(), false);
            stacked.resize(g.G().V(), false);
            this->g = &g;
            /* Fin implémenté par nous */
	}
	
	//indique la presence d'un cycle
	bool HasCycle() {
            /* Implémenté par nous */
            std::cout << "(DirectedCycle) Debut du test de cycles pour  : " << g->G().V() << "sommets" << std::endl;
            
            for(int i = 0; i < g->G().V(); ++i){
                
                if(HasCycleRecursiv(i)) {
                    return true;
                }
            }
            
            std::cout << "(DirectedCycle) Fin du test de cycles :"<< std::endl;
            return false;
            /* Fin implémenté par nous */
	}
	
        
        
	//liste les indexes des sommets formant une boucle
	std::list<int> Cycle() {
            /* Implémenté par nous */
            // cycle contient actuellement le parcours en profondeur inerrompu lorsqu'on a trouvé une boucle.
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
            /*
            std::cout << "(DirectedCycle) Has Cycle Recursive for " << v <<" : " << std::endl;
            
            for(auto i = adjList.begin(); i != adjList.end(); i++){
                std::cout << "(" << *i<<") " << std::endl;
            }
            */
            
            
            std::list<int> adjList = g->G().adjacent(v);
            
            cycle.push_back(v);
            marked[v] = true;
            stacked[v] = true;
            
            std::cout << "Cycle of "<< g->name(v) <<" state :";
            for(int i : cycle){
                std::cout << g->name(i) << " ";
            }
            std::cout << std::endl;
            
            //parcours des voisins de v
            while(adjList.size()){
                if(cycleFound) {
                    return true;
                }
                else if(!marked.at(adjList.front())){
                    HasCycleRecursiv(adjList.front());
                    
                    if(!cycleFound) {
                        cycle.pop_back();

                        std::cout << "Cycle state3 :";
                        for(int i : cycle){
                            std::cout << g->name(i) << " ";
                        }
                        std::cout << std::endl;
                    }
                } 
                else if (stacked.at(adjList.front())){
                    
                    //ajoutes le dernier du cycle
                    cycle.push_back(adjList.front());
                    /*
                    std::cout << "Cycle state2 :";
                    for(int i : cycle){
                        std::cout << g->name(i) << " ";
                    }
                    std::cout << std::endl;
                    
                    std::cout << "\nCYCLE FOUND !!!\n";
                     */
                    cycleFound = true;
                }
                adjList.pop_front();
            }
            stacked[v] = false;
            return false;
        }
	/* End Définit par nous */
};

#endif
