#pragma once

#include <iostream>
#include <vector>

#include "task.hpp"

class matrixGraph : public IGraph {
public:
    matrixGraph(int verticesCount);
    matrixGraph(const IGraph& graph);
    virtual ~matrixGraph() = default;
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector< std::vector<int> > graph_;
};
