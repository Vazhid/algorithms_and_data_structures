#include "matrixGraph.hpp"

matrixGraph::matrixGraph(int verticesCount) {
    std::vector<std::vector<int>> tmpGraph(verticesCount, std::vector<int>(verticesCount, 0));
    graph_ = std::move(tmpGraph);
}

matrixGraph::matrixGraph(const IGraph& graph) {
    std::vector<std::vector<int>> tmpGraph(graph.VerticesCount(), std::vector<int>(graph.VerticesCount(), 0));
    graph_ = std::move(tmpGraph);

    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        std::vector<int> vertices = graph.GetNextVertices(i);
        for (int j : vertices) {
            graph_[i][j] = 1;
        }       
    }   
}

void matrixGraph::AddEdge(int from, int to) {
    graph_[from][to] = 1;
}

int matrixGraph::VerticesCount() const {
    return graph_.size();
}

std::vector<int> matrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (size_t i = 0; i < graph_[vertex].size(); ++i) {
        if (graph_[vertex][i] == 1) {
            nextVertices.push_back(i);
        }
    }
    return nextVertices;
}

std::vector<int> matrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (int i = 0; i != graph_.size(); ++i) {
        if (graph_[i][vertex] == 1) {
            prevVertices.push_back(i);
        }
    }
    return prevVertices;
}
