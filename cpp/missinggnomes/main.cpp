#include <cstddef>
#include <iostream>
#include <vector>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n; // number of gnomes originally [1, 10^5]
  int m; // number of gnomes which were remained after the trick, [1,10^5]
  std::cin >> n >> m;

  // gnome i is missing if all_gnomes[i] == 0
  // gnome i was remained if all_gnomes[i] == 1
  std::vector<int> all_gnomes(n + 1, 0);

  // remaining ids of gnomes after removal
  std::vector<int> remaining_gnomes;
  remaining_gnomes.reserve(m);

  // read remaining gnomes
  int g; // gnome id
  for (int i = 0; i < m; ++i) {
    std::cin >> g;
    all_gnomes[g] = 1;
    remaining_gnomes.push_back(g);
  }

  // recovering places of gnomes which were removed
  std::size_t j = 0;
  for (std::size_t i = 1; i < all_gnomes.size(); ++i) {
    if (all_gnomes[i] == 0) {

      bool found_place = false;

      for (; j < remaining_gnomes.size(); ++j) {
        if (i < (std::size_t)remaining_gnomes[j]) {
          std::cout << i << "\n";
          found_place = true;
          break;
        } else {
          std::cout << remaining_gnomes[j] << "\n";
        }
      }
      if (!found_place) {
        std::cout << i << "\n";
      }
    }
  }
  // print what's left
  for (; j < remaining_gnomes.size(); ++j) {
    std::cout << remaining_gnomes[j] << "\n";
  }
  return 0;
}
