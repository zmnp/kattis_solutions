#include <cstdio>

/* calculate greatest common factor of two positive numbers using
 * euclidian algorithm */
int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  int fnum, fden; // numerator and denominator, [0, 1'000'000], den != 0
  // fnum / fden is a temperature in fahrenheit expressed as a fraction
  // input is in the form [-]a/b, where '-' is optional
  // we will consider that a can be negative number for simplicity
  std::scanf("%d/%d", &fnum, &fden);

  // C = (5/9)*(F - 32) - formula to convert fahrenheit to celsius
  // after some calculations we get:
  int cnum = fnum * 45 - 1440 * fden;
  int cden = 81 * fden;

  // save sign because gcd accepts only positive numbers
  int sign = 1;
  if (cnum < 0) {
    cnum = -cnum;
    sign = -1;
  }

  int gcf = gcd(cnum, cden);
  cnum /= gcf;
  cden /= gcf;

  if (sign < 0)
    std::putchar('-');

  std::printf("%d/%d\n", cnum, cden);
  return 0;
}
