#include <iostream>
#include <string>
#include <unordered_set>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int p;                 // number of parts the boat consists of, [1,1000]
  int n;                 // number of days in the boating seasonk, [1,1000]
  std::string boat_part; // type of boat part

  std::cin >> p >> n;

  std::unordered_set<std::string> dparts; // distinct parts that was bought

  int day;
  for (day = 1; day <= n; ++day) {
    std::cin >> boat_part;
    dparts.insert(boat_part);
    if (dparts.size() == p) {
      // all parts from previous season are replaced
      break;
    }
  }

  if (dparts.size() == p)
    std::cout << day << "\n";
  else
    std::cout << "paradox avoided\n";

  return 0;
}
