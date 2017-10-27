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

#include "ParcoursEnProfondeur.h"

template<typename GraphType>
class DirectedCycle {
private:
	/* A DEFINIR */
    std::vector<bool> marked;
    std::vector<bool> stacked;
    bool cycleFinded = false;
    const GraphType * g;
        
	
public:
	//constructeur
	DirectedCycle(const GraphType& g) {
            /* A IMPLEMENTER */
            
            marked.resize(g.V(), false);
            stacked.resize(g.V(), false);
            this->g = g;
            
	}
	
	//indique la presence d'un cycle
	bool HasCycle() {
            
            
            for(size_t i = 0; i < g.V(); ++i){
                if(cycleFinded)
                    return true;
                else if(!marked())
            }
		/* A IMPLEMENTER */
		//return ...
	}
	
	//liste les indexes des sommets formant une boucle
	std::list<int> Cycle() {
		/* A IMPLEMENTER */
                // Liste FIFO ajout 
		//return ...
	}
	
};

#endif
