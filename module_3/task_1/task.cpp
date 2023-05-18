#include "task.hpp"
#include "listGraph.hpp"
#include "matrixGraph.hpp"
#include "setGraph.hpp"
#include "arcGraph.hpp"

void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, std::function<void(int)>& out, size_t count) {
  visited[vertex] = true;
  out(vertex);

  for (auto child : graph.GetNextVertices(vertex)) {
    if (!visited[child]) {
      ++count;
      DFS(graph, child, visited, out, count);
    }
  }
}

void mainDFS(const IGraph& graph, std::function<void(int)> out) {
  std::vector<bool> visited;
  visited.resize(graph.VerticesCount(), false);
  size_t count = 0;

  for (int i = 0; i < graph.VerticesCount(); ++i) {
    if (!visited[i]) {
      ++count;
      DFS(graph, i, visited, out, count);
    }
  }
}

int main() {
    listGraph list_graph(10);

    list_graph.AddEdge(0, 1);
    list_graph.AddEdge(1, 2);
    list_graph.AddEdge(1, 5);
    list_graph.AddEdge(2, 3);
    list_graph.AddEdge(3, 4);
    list_graph.AddEdge(4, 2);
    list_graph.AddEdge(5, 6);
    list_graph.AddEdge(5, 7);
    list_graph.AddEdge(9, 7);
    list_graph.AddEdge(6, 8);

    auto out = [](int v) { 
        std::cout << v << " "; 
    };

    std::cout << "Size of listGraph: " << list_graph.VerticesCount() << std::endl;
    mainDFS(list_graph, out);
    std::cout << std::endl;
    std::cout << std::endl;

    matrixGraph matrix_graph(list_graph);
    std::cout << "Size of matrixGraph: " << matrix_graph.VerticesCount() << std::endl;
    mainDFS(matrix_graph, out);
    std::cout << std::endl;
    std::cout << std::endl;

    setGraph set_graph(matrix_graph);
    std::cout << "Size of setGraph: " << set_graph.VerticesCount() << std::endl;
    mainDFS(set_graph, out);
    std::cout << std::endl;
    std::cout << std::endl;

    arcGraph arc_graph(set_graph);
    std::cout << "Size of arcGraph: " << arc_graph.VerticesCount() << std::endl;
    mainDFS(arc_graph, out);
    std::cout << std::endl;
    std::cout << std::endl;
}
