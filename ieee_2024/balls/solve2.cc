#include <bits/stdc++.h>

int main(void)
{
  unsigned long N, K, E;
  std::cin >> N >> K;
  long acc = 0;
  std::vector<unsigned long> Es;
  Es.reserve(1000);

  while (K--) {
    std::cin >> E;
    Es.push_back(E);
  }
  std::sort(Es.begin(), Es.end());

  for (int i = 0; i < (int)Es.size(); ++i) {
    acc += N / Es[i];
    unsigned long lcm = Es[i];
    for (int j = i+1; j < (int)Es.size(); ++j) {
      if (i == (int)Es.size()-1) continue;
      if (lcm > N) break;
      lcm = std::lcm(lcm, Es[j]);
      acc -= N / lcm;
    }
  }

  std::cout << acc << std::endl;
  return 0;
}
