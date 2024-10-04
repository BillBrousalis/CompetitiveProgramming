#include <iostream>
#include <vector>

int main(void)
{
  float d;
  unsigned long n;
  std::cin >> d >> n;
  float acc = d;

  while (n-- > 0) {
    d /= 2.0f;
    acc += d;
    if (d == 0.0f) break;
  }

  std::cout << acc << std::endl;
  return 0;
}
