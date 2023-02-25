#include <deque>
#include <iostream>
#include <queue>
#include <unordered_set>

int main() {
  std::deque<int> set;

  for (int i = 0; i < 20; ++i) {
    set.emplace_back(i);
  }

  std::queue<int> que;

  for (const auto &i : set) {
    std::cout << i << std::endl;
    que.push(i);
  }

  while (!que.empty()) {
    // std::cout << que.front() << std::endl;

    que.pop();
  }

  return 0;
}
