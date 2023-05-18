#include "listGraph.hpp"

listGraph::listGraph(int verticesCount) {
    graph_.resize(verticesCount);
}

listGraph::listGraph(const IGraph& graph) {
    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        graph_[i] = graph.GetNextVertices(i);
    }   
}

void listGraph::AddEdge(int from, int to) {
    graph_[from].push_back(to);
}

int listGraph::VerticesCount() const {
    return graph_.size();
}

std::vector<int> listGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (size_t i = 0; i < graph_[vertex].size(); ++i) {
        nextVertices.push_back(graph_[vertex][i]);
    }
    return nextVertices;
}

std::vector<int> listGraph::GetPrevVertices(int vertex) const {
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
