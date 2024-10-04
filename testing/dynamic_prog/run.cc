#include <iostream>
#include <limits>
#include <set>

#define INF 10000
#define N 11
std::set<int> coins = {1, 3, 4};

bool ready[N];
int value[N];

int solve(int x) {
  if (x < 0) return INF;
  if (x == 0) return 0;
  if (ready[x]) return value[x];
  int best = INF;
  for (auto c : coins) {
    best = std::min(best, solve(x-c)+1);
  }
  value[x] = best;
  ready[x] = true;
  for (int i = 0; i < N; ++i) {
    if (ready[i])
      std::cout << "[" << i << "] = " << value[i] << std::endl;
  }
  return best;
}

int main(void)
{
  std::cout << "inf = " << INF << std::endl;
  int best = solve(10);
  std::cout << best << std::endl;
  return 0;
}
