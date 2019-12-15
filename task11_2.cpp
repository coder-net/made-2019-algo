// Дан невзвешенный неориентированный граф. В графе может быть несколько кратчайших путей между какими-то вершинами. Найдите количество различных кратчайших путей между заданными вершинами. Требуемая сложность O(V+E).
// Ввод: v: кол-во вершин (макс. 50000), n: кол-во ребер (макс. 200000), n пар реберных вершин, пара вершин v, w для запроса.
// Вывод: количество кратчайших путей от v к w.

#include <iostream>
#include <vector>
#include <queue>


size_t bfs(const std::vector<std::vector<size_t>>& list, size_t start, size_t end) {
  std::queue<size_t> queue;
  std::vector<bool> visited(list.size(), false);
  queue.push(start);
  size_t path_counter = 0;
  while (path_counter == 0 && !queue.empty()) {
    std::queue<size_t> temp;
    while (!queue.empty()) {
      size_t curr = queue.front();
      queue.pop();

      if (curr == end) {
        ++path_counter;
        continue;
      }

      if (visited[curr]) {
        continue;
      }
      visited[curr] = true;

      for (size_t child : list[curr]) {
        temp.push(child);
      }
    }
    queue = temp;
  }
  return path_counter;
}


int main() {
  size_t v, n;
  std::cin >> v >> n;
  std::vector<std::vector<size_t>> list(v);
  for (size_t i = 0; i < n; ++i) {
    size_t v1, v2;
    std::cin >> v1 >> v2;
    list[v1].push_back(v2);
    list[v2].push_back(v1);
  }
  size_t start, end;
  std::cin >> start >> end;

  std::cout << bfs(list, start, end);

  return 0;
}