#include <iostream>
#include <vector>
#include <set>
#include <queue>


int mst(const std::vector<std::vector<std::pair<int, int>>>& list) {
  std::priority_queue<std::pair<int, int>> heap;
  std::set<int> used;
  std::queue<int> vertices;
  vertices.push(0);

  int mst_sum = 0;

  while (used.size() + 1 < list.size()) {
    int vert = vertices.front();
    vertices.pop();
    used.insert(vert);
    for (auto [v, weight] : list[vert]) {
      if (!used.count(v)) {
        heap.push(std::make_pair(-weight, v));
      }
    }
    while (used.count(heap.top().second)) {
      heap.pop();
    }
    mst_sum += -heap.top().first;
    vertices.push(heap.top().second);
    heap.pop();
  }
  return mst_sum;
}


int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<std::pair<int, int>>> list(v);
  for (int i = 0; i < e; ++i) {
    int v1, v2, weight;
    std::cin >> v1 >> v2 >> weight;
    list[v1 - 1].push_back(std::make_pair(v2 - 1, weight));
    list[v2 - 1].push_back(std::make_pair(v1 - 1, weight));
  }

  std::cout << mst(list);

  return 0;
}