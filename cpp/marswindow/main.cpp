#include <cstdio>

int main() {
  int given_year; // [2018, 10000]
  std::scanf("%d", &given_year);

  if (given_year == 2018) {
    std::printf("yes\n");
    return 0;
  }

  const int launch_year = 2018;    // optimal launch year
  const int launch_month = 3;      // optimal launch month
  const int months_in_period = 26; // optimal launch occurs every 26 months

  // number of months from Apr 2018(not from Jan 2018, that's why
  // we substract 3) to Jan given_year
  int months_diff = (given_year - launch_year) * 12 - launch_month;

  // months_diff will always be not divisible by 26
  int periods = months_diff / months_in_period + 1; // number of launch windows

  // months to add to Jan given_year
  int months_to_add = periods * months_in_period - months_diff;

  if (months_to_add < 12)
    std::printf("yes\n");
  else
    std::printf("no\n");

  return 0;
}
