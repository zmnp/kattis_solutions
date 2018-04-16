#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

template <typename T> void print(std::vector<T> &v) {
  for (const auto &e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  print(v);
  while (true) {

    int x = -1;
    for (std::size_t i = 0; i < v.size() - 1; ++i) {
      if (v[i] < v[i + 1]) {
        x = i;
      }
    }
    if (x == -1) {
      break;
    }
    int y = -1;
    for (std::size_t i = 0; i < v.size(); ++i) {
      if (v[x] < v[i]) {
        y = i;
      }
    }
    int tmp = v[x];
    v[x] = v[y];
    v[y] = tmp;

    std::reverse(v.begin() + x + 1, v.end());
    print(v);
  }
  return 0;
}
