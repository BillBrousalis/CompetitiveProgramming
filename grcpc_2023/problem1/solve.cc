#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

typedef struct {
  std::string id;
  float f;
  float c;
} Alloy_t;

bool compareAlloyCallback(Alloy_t *a1, Alloy_t *a2) { return a1->f == a2->f ? (a1->c < a2->c) : (a1->f < a2->f); }
bool compareConductivityCallback(Alloy_t *a1, Alloy_t *a2) { return a1->c < a2->c; }

bool isNonDominated(std::string id, std::vector<Alloy_t *> nonDominated)
{
  for (Alloy_t *alloy : nonDominated) {
    if (id == alloy->id) return true;
  }
  return false;
}

std::vector<Alloy_t *> merge_results(std::vector<Alloy_t *> leftAlloys, std::vector<Alloy_t *> rightAlloys)
{
  std::vector<Alloy_t *> merged;
  float maxC = std::numeric_limits<float>::min();

  for (Alloy_t *alloy : rightAlloys) {
    if (alloy->c >= maxC) {
      merged.push_back(alloy);
      maxC = alloy->c;
    }
  }
  for (Alloy_t *alloy : leftAlloys) {
    if (alloy->c >= maxC) {
      merged.push_back(alloy);
      maxC = alloy->c;
    }
  }

  return merged;
}

std::vector<Alloy_t *> solve(std::vector<Alloy_t *> alloys, int left, int right)
{
  if (left == right) return {alloys[left]};
  int mid = left + (right - left) / 2;
  std::vector<Alloy_t *> left_result = solve(alloys, left, mid);
  std::vector<Alloy_t *> right_result = solve(alloys, mid+1, right);
  return merge_results(left_result, right_result);
}

int main(int argc, char **argv)
{
  if (argc < 2) exit(-1);
  freopen(argv[1], "r", stdin);

  int n;
  std::cin >> n;
  std::vector<Alloy_t *> alloys;
  while (n--) {
    Alloy_t *alloy = new Alloy_t();
    std::cin >> alloy->id >> alloy->f >> alloy->c;
    alloys.push_back(alloy);
  }

  std::sort(alloys.begin(), alloys.end(), compareAlloyCallback);

  std::vector<Alloy_t *> nonDominatedAlloys = solve(alloys, 0, alloys.size()-1);
  // printing order -> order given (?)
  for (Alloy_t* alloy : alloys) {
    if (isNonDominated(alloy->id, nonDominatedAlloys)) std::cout << alloy->id << " ";
  }

  return 0;
}
