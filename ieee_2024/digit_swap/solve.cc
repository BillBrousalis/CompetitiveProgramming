#include <bits/stdc++.h>

std::string N = "";
int K;
int maxdig = 0;

typedef struct {
  int val;
  int idx;
} MD_t;

int to_num(int idx)
{
  return (int)(N[idx]-'0');
}

MD_t get_maxdig_t(int idx)
{
  int max = 0, max_idx = -1;
  for (int i = idx+1; i < N.size(); ++i) {
    if (to_num(i) >= max) {
      max = to_num(i);
      max_idx = i;
    }
  }
  return MD_t {max, max_idx};
}

int main(void)
{
  std::cin >> N >> K;
  int idx = 0;
  while (K > 0 and idx < N.size()) {
    MD_t maxdigt = get_maxdig_t(idx);
    if (maxdigt.idx != -1 and maxdigt.val > to_num(idx)) { // can swap
      std::swap(N[idx], N[maxdigt.idx]);
      K--;
    }
    idx++;
  }

  std::cout << N << std::endl;
  return 0;
}
