#include <iostream>
#include <vector>
#include <cmath>

int main(void)
{
  freopen("input.txt", "r", stdin);

  int n;
  std::cin >> n;
  
  int mindays = n;
  int printers = 2;

  while (printers < n) {
    int days = ceil(log2(printers)) + ceil((double)n / printers);
    if (days < mindays) mindays = days;
    printers++;
  }

  std::cout << mindays << std::endl;
  return 0;
}
