#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int main(void)
{
  //freopen("input.txt", "r", stdin);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> teams(n);
  for (int i = 0; i < n; ++i) {
    teams[i] = i+1;
  }
  
  for (int i = 0; i < m; ++i) {
    char T;
    int t1, t2;
    std::cin >> T >> t1 >> T >> t2;
    int idx1 = std::find(teams.begin(), teams.end(), t1) - teams.begin();
    int idx2 = std::find(teams.begin(), teams.end(), t2) - teams.begin();
    if (idx1 < idx2) continue;
    for (int j = idx2; j < idx1; ++j) {
      teams[j] = teams[j+1];
    }
    teams[idx1] = t2;
  }
  
  for (int i = 0; i < n; ++i)
    std::cout << "T" << teams[i] << " ";
  std::cout << std::endl;

  return 0;
}
