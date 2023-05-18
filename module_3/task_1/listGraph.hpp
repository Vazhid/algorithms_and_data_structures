#pragma once

#include <iostream>
#include <vector>

#include "task.hpp"

class listGraph : public IGraph {
public:
    listGraph(int verticesCount);
    listGraph(const IGraph& graph);
    virtual ~listGraph() = default;
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector< std::vector<int> > graph_;
};
