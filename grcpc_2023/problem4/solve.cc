#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

unsigned int solve(std::vector<unsigned int> terrain)
{
  // trim useless parts
  while (terrain.size() > 2) {
    if (terrain[0] <= terrain[1]) { terrain.erase(terrain.begin()); continue; }
    if (terrain[terrain.size()-1] <= terrain[terrain.size()-2]) { terrain.erase(terrain.end()-1); continue; }
    break;
  }
  if (terrain.size() <= 2) return 0;

  unsigned int lo = 0;
  unsigned int hi = 1;
  unsigned int maxh_idx = 0;
  unsigned int maxh = 0;
  unsigned int acc = 0;

  while (lo < terrain.size()-2) {
    if (terrain[hi] > maxh) {
      maxh = terrain[hi];
      maxh_idx = hi;
    }
    if (hi == terrain.size()-1) {
      if (maxh_idx == lo+1) {
        lo = maxh_idx;
        hi = lo+1;
        maxh = 0;
        maxh_idx = 0;
        continue;
      }
      // calculate
      unsigned int minh = std::min(terrain[lo], terrain[maxh_idx]);
      for (unsigned int i = lo+1; i < maxh_idx; ++i) acc += minh - terrain[i];
      lo = maxh_idx;
      hi = lo+1;
      maxh = 0;
      maxh_idx = 0;
    }
    else if (terrain[lo] > terrain[hi]) {
      hi++;
    }
    else {
      if (hi == lo+1) {
        lo = hi;
        hi = lo+1;
        maxh = 0;
        maxh_idx = 0;
        continue;
      }
      // calculate
      unsigned int minh = std::min(terrain[lo], terrain[hi]);
      for (unsigned int i = lo+1; i < hi; ++i) acc += minh - terrain[i];
      lo = hi;
      hi = lo+1;
      maxh = 0;
      maxh_idx = 0;
    }
  }

  return acc;
}

int main(int argc, char **argv)
{
  if (argc < 2) exit(-1);
  freopen(argv[1], "r", stdin);

  int n;
  std::cin >> n;
  std::vector<std::vector<unsigned int>> terrains(1, std::vector<unsigned int>());

  unsigned int ti = 0;
  while (n--) {
    unsigned int x;
    std::cin >> x;
    if (x == 0) {
      ti++;
      terrains.push_back(std::vector<unsigned int>());
    }
    else {
      terrains[ti].push_back(x);
    }
  }
  
  unsigned int acc = 0;
  for (auto terrain: terrains) acc += solve(terrain);
  std::cout << acc << std::endl;

  return 0;
}
