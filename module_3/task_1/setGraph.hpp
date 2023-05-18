#pragma once

#include <iostream>
#include <vector>
#include <set>

#include "task.hpp"

class setGraph : public IGraph {
public:
    setGraph(int verticesCount);
    setGraph(const IGraph& graph);
    virtual ~setGraph() = default;
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector< std::set<int> > graph_;
};
