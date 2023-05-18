#pragma once

#include <iostream>
#include <vector>

#include "task.hpp"

class arcGraph : public IGraph {
public:
    arcGraph(int verticesCount);
    arcGraph(const IGraph& graph);
    virtual ~arcGraph() = default;
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector< std::pair<int, int> > graph_;
};
