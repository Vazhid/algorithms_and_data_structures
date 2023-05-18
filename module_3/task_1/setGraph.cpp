#include "setGraph.hpp"

setGraph::setGraph(int verticesCount) {
    graph_.resize(verticesCount);
}

setGraph::setGraph(const IGraph& graph) {
    graph_.resize(graph.VerticesCount());
    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        std::vector<int> vertices = graph.GetNextVertices(i);
        graph_[i].insert(vertices.begin(), vertices.end());  
    }   
}

void setGraph::AddEdge(int from, int to) {
    graph_[from].insert(to);
}

int setGraph::VerticesCount() const {
    return graph_.size();
}

std::vector<int> setGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (int i : graph_[vertex]) {
        nextVertices.push_back(i);
    }
    return nextVertices;
}

std::vector<int> setGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (size_t i = 0; i < graph_.size(); ++i) {
        for (int j : graph_[i]) {
            if (j == vertex) {
                prevVertices.push_back(i);
                break;
            }
        }
    }
    return prevVertices;
}
