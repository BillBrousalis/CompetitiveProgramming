#include <iostream>
#include <vector>
#include <algorithm>

int get_idx1(std::vector<int> problems, int D) {
  if (problems[problems.size()-1] <= D) return -1;
  for (int i = 0; i < problems.size(); ++i) {
    if (problems[i] > D) return i;
  }
  return -1;
}

int get_idx2(std::vector<int> problems, int D) {
  if (problems[0] > D) return -1;
  for (int i = 0; i < problems.size(); ++i) {
    if (problems[i] <= D) return i;
  }
  return -1;
}

int main(void)
{
  unsigned int N, Q, T, D;
  std::cin >> N >> Q;;
  std::vector<unsigned int> problems(N);
  for (int i = 0; i < N; ++i) std::cin >> problems[i];
  //std::sort(problems.begin(), problems.end());
  for (unsigned int i = 0; i < Q; ++i) {
    std::cin >> T >> D;
    int idx;
    idx = T == 1 ? get_idx1(problems, D) : get_idx2(problems, D);
    std::cout << (idx == -1 ? -1 : problems[idx]) << std::endl;
    if (idx != -1) problems.erase(problems.begin()+idx);
  }

  return 0;
}
