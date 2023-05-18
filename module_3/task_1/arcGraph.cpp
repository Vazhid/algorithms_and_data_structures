#include "arcGraph.hpp"

arcGraph::arcGraph(int verticesCount) {
    graph_.resize(verticesCount);
}

arcGraph::arcGraph(const IGraph& graph) {
    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        std::vector<int> vertices = graph.GetNextVertices(i);
        for (int j : vertices) {
            std::pair<int, int> from_to(i, j);
            graph_.push_back(from_to);
        }
    }   
}

void arcGraph::AddEdge(int from, int to) {
    std::pair<int, int> from_to(from, to);
    graph_.push_back(from_to);
}

int arcGraph::VerticesCount() const {
    return graph_.size();
}

std::vector<int> arcGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (auto i : graph_) {
        if (i.first == vertex) {
            nextVertices.push_back(i.second);
        }
    }
    return nextVertices;
}

std::vector<int> arcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (auto i : graph_) {
        if (i.second == vertex) {
            prevVertices.push_back(i.first);
        }
    }
    return prevVertices;
}
