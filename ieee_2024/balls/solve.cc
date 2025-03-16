#include <bits/stdc++.h>

int main(void)
{
  unsigned long N, K, E;
  std::cin >> N >> K;
  std::vector<unsigned long> Es;
  Es.reserve(1000);

  while (K--) {
    std::cin >> E;
    Es.push_back(E);
  }
  //std::sort(Es.begin(), Es.end());
  
  unsigned long total = 0;
  unsigned long begin = 0;
  unsigned long step = 100000;
  while (begin <= N) {
    unsigned long end = std::min(begin+step, N);
    std::unordered_set<unsigned long> s;
    for (unsigned long e: Es) {
      unsigned int acc = e;
      while (acc <= end) {
        if (acc >= begin) s.insert(acc);
        acc += e;
      }
    }
    total += s.size();
    begin += step;
  }

  std::cout << total << std::endl;
  return 0;
}
