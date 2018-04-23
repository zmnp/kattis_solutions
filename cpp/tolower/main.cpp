#include <cctype>
#include <cstdio>

int main() {
  int p; // number of problems in the contest
  int t; // number of test cases for every problem
  int c; // current character

  std::scanf("%d%d", &p, &t);
  std::getchar(); // skip '\n'

  int nsp = 0; // number of problems that will be solved during the contest

  for (int i = 0; i < p; ++i) {
    bool is_solved = true;
    for (int j = 0; j < t; ++j) {
      // read test case
      for (int k = 0; (c = std::getchar()) != '\n'; ++k) {
        // don't check the first char of the current string
        if (k != 0 && !std::islower(c)) {
          is_solved = false;
        }
      }
    }
    if (is_solved)
      ++nsp;
  }
  std::printf("%d\n", nsp);
  return 0;
}
