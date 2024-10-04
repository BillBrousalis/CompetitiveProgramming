#include <iostream>
#include <math.h>

#define CIRCLE_TO_SQUARE_AREA_RATIO 0.7853981633974483

int main(void)
{
  double r, m, c;
  for (;;) {
    std::cin >> r >> m >> c;
    if (r == 0 && m == 0 && c == 0) break;
    double true_area = M_PI * r * r;
    double estimate = true_area * (c / m) / CIRCLE_TO_SQUARE_AREA_RATIO;
    std::cout << true_area << " " << estimate << std::endl;
  }
  return 0;
}
