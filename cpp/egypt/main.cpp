#include <algorithm>
#include <iostream>

bool is_right_triangle(int a, int b, int c) {
  int hyp = std::max({a, b, c});
  int sq_hyp = hyp * hyp;

  bool is_right = false;

  if (hyp == a) {
    if (sq_hyp == (b * b + c * c)) {
      is_right = true;
    }
  } else if (hyp == b) {
    if (sq_hyp == (a * a + c * c)) {
      is_right = true;
    }
  } else {
    if (sq_hyp == (a * a + b * b)) {
      is_right = true;
    }
  }
  return is_right;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int a, b, c; // triangle sides, [1, 30000]

  while (true) {
    std::cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
      break;
    }
    std::cout << (is_right_triangle(a, b, c) ? "right" : "wrong") << "\n";
  }
  return 0;
}
