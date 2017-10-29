#include "DiGraph.h"

DiGraph::DiGraph(int V) 
{
        std::cout << "New Di Graphe from size : " << V << std::endl;
	adjacencyLists.resize(V);
        std::cout << "End DiGraph constructor" << std::endl;
}

DiGraph::DiGraph(std::istream& s) {
        std::cout << "New Di Graphe from stream" << std::endl;
	int V,E,v,w;
	
	s >> V;
	s >> E;

	adjacencyLists.resize(V);

	for (int i = 0; i < E; i++) {
		s >> v;
		s >> w;
                
                std::cout << "New Edge" << v << "," << w << ") " << std::endl;
		addEdge(v, w);
	}
        std::cout << "End DiGraph constructor" << std::endl;

}

void DiGraph::addEdge(int v, int w) {
	adjacencyLists.at(v).push_back(w);
}

DiGraph::Iterable DiGraph::adjacent(int v) const {
	return adjacencyLists.at(v);
}

int DiGraph::V() const {
	return (int)adjacencyLists.size();
}

DiGraph DiGraph::reverse() const {
	DiGraph dg(V());
	for(int v=0;v<V();++v)
		for(int w : adjacent(v))
			dg.addEdge(w,v);
	return dg;
}
