/*
 * File:   TopologicalSort.h
 * Author: Olivier Cuisenaire
 *
 * Created on 08. octobre 2014, 14:07
 *
 * A implementer
 * Classe permettant le tri topologique d'un graphe oriente
 */

#ifndef ASD2_TopologicalSort_h
#define ASD2_TopologicalSort_h

#include "DirectedCycle.h"
#include <list>
#include <vector>
#include <exception>

template < typename GraphType >
class TopologicalSort {
private:
	/* A DEFINIR */
    const GraphType & g;
    std::vector<int> postOrder;
    std::vector<int> preOrder;
    std::vector<int> reversePostOrder;
    
public:
    //constructeur
    TopologicalSort(const GraphType & g) {
        /* A IMPLEMENTER */
        
        this->g = g;
        
        
        /* vous devez verifier la presence d'un cycle, auquel cas il faut lancer une  GraphNotDAGException*/
    }
    
    void addVertexPostOrder(const int v){
        postOrder.push_back(v);
    }
    
    void addVertexPreOrder(const int v){
        preOrder.push_back(v);
    }
    
    void CreateReversePostOrder(){
        for(auto i = postOrder.end(); i != postOrder.begin(); --i)
            reversePostOrder.push_back(*i);
    }
    
    //tableau contenant l'ordre de parcours des indexes des sommets dans le graphe
    const std::vector<int>& Order() {
        
        g.visitGraph<addVertexPreOrder, addVertexPostOrder>();
        CreateReversePostOrder();
        return &reversePostOrder;
        
        
        /* A IMPLEMENTER */
        //return ...
    }
    
    //exception si le graphe n'est pas un DAG (Directed Acyclic Graph)
    class GraphNotDAGException : public std::exception {
        
    private:
        //indexes des sommets du cycle qui empeche le tris topologique
        const std::list<int> cycle;
        
    public:
        GraphNotDAGException(const std::list<int> cycle) noexcept : exception(), cycle(cycle) {
            std::copy( cycle.begin(), liste1.end());
            printf(what());
            for(auto i = cycle.begin(); i < cycle.end(); ++i){
                printf(*i + " ");
            }
        }
        
        virtual const char* what() const noexcept {
            return "Topological sort impossible : the graph is not a DAG";
        }
        
            const std::list<int>& Cycle() const noexcept {
            return cycle;
        }
    };
};


#endif
