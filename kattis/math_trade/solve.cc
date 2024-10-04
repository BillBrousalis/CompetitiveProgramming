#include <iostream>
#include <vector>

int main(void)
{
  freopen("input.txt", "r", stdin);

  int n;
  std::cin >> n;
  std::vector<std::pair<std::string, std::string>> ppl;
  for (int i = 0; i < n; ++i) {
    std::string person, has, needs;
    std::cin >> person >> has >> needs;
    ppl.push_back(std::make_pair(has, needs));
  }

  int max_trade = 0, trade;
  for (int i = 0; i < n; ++i) {
    int unsatisfied = 0;
    for (int j = 0; j < n; ++j) {
      std::vector<std::pair<std::string, std::string>> test = ppl;
      if (i == j) continue;
      int x = 0;
      do {
        if (test[i].second == test[j+x].first) {
          test[j].first = test[i].first;
          test[i].first = test[i].second;
          x++;
          if (test[j].first != test[j].second) unsatisfied++;
        }
      } while(unsatisfied != 0);
    }
  }

  return 0;
}
