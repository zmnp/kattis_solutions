#include <iostream>
#include <utility>
#include <vector>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;    // number of times water was boiled, [1, 1000]
  int a, b; // start and end of the interval of distraction, [0, 1000], a <= b

  std::cin >> n;

  std::vector<std::pair<int, int>> intervals;

  // is it possible that all the pots started boiling at the same point in time
  bool is_possible = true;

  for (int i = 0; i < n; ++i) {
    std::cin >> a >> b;

    bool has_intersection = true;
    for (const std::pair<int, int> &interval : intervals) {
      if (!(a <= interval.second && interval.first <= b)) {
        has_intersection = false;
        break;
      }
    }
    if (has_intersection) {
      intervals.push_back(std::make_pair(a, b));
    } else {
      is_possible = false;
      break;
    }
  }
  if (is_possible) {
    std::cout << "gunilla has a point\n";
  } else {
    std::cout << "edward is right\n";
  }
  return 0;
}
