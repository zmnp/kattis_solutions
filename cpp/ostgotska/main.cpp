#include <iostream>
#include <string>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::string word;
  int tnw = 0; // total number of words
  int onw = 0; // number of ostgotska words (contain "ae")
  while (std::cin >> word) {
    ++tnw;
    if (word.find("ae") != std::string::npos) {
      ++onw;
    }
  }
  // calc percent of ostgotska words in the sentence
  double op = onw * 100.0 / tnw;
  // the sentence is written in ostgotska if at least
  // 40% of the words in the sentence contain the substring "ae"
  if (op >= 40.0) {
    std::cout << "dae ae ju traeligt va\n";
  } else {
    std::cout << "haer talar vi rikssvenska\n";
  }
  return 0;
}
