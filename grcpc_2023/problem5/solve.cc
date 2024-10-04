#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

int main(int argc, char **argv)
{
  if (argc < 2) exit(-1);
  freopen(argv[1], "r", stdin);

  int n, m;
  std::cin >> n >> m;
  std::vector<double> temps(n);
  for (int i = 0; i < n; ++i) std::cin >> temps[i];

  double maxinc = 0;
  for (int lo = 0; lo < temps.size()-1; ++lo) {
    for (int hi = lo+1; hi < lo+m && hi < temps.size(); ++hi) {
      if (temps[hi] >= temps[lo] && temps[hi] - temps[lo] > maxinc) maxinc = temps[hi] - temps[lo];
    }
  }

  printf("%.6f\n", maxinc);

  return 0;
}
