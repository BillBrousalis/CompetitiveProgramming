#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <bitset>
#include <stack>

#define MAXROWS 1000
#define MAXCOLS 1000

int ROWS, COLS;

typedef struct {
  int x;
  int y;
} Coords_t;

Coords_t get_next_adjacent(std::vector<std::bitset<MAXCOLS>> map, int x, int y)
{
  if (x+1 < ROWS && map[x+1][y])  return Coords_t {x+1, y};
  if (y+1 < COLS && map[x][y+1])  return Coords_t {x, y+1};
  if (x-1 >= 0 && map[x-1][y])    return Coords_t {x-1, y};
  if (y-1 >= 0 && map[x][y-1])    return Coords_t {x, y-1};
  return Coords_t {-1, -1};
}

int solve(std::vector<std::bitset<MAXCOLS>>& map, int x, int y)
{
  int acc = 0;
  std::stack<Coords_t> stack;
  for (;;) {
    if (map[x][y]) {
      acc++;
      stack.push(Coords_t {x, y});
    }
    map[x][y] = 0; // adjust given map -> visited
    Coords_t next_coords = get_next_adjacent(map, x, y);
    if (next_coords.x != -1 && next_coords.y != -1) {
      x = next_coords.x;
      y = next_coords.y;
      continue;
    }
    stack.pop();
    if (stack.empty()) break;
    next_coords = stack.top();
    x = next_coords.x;
    y = next_coords.y;
  }
  return acc;
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cout << "[-] Provide input file" << std::endl;
    exit(-1);
  }
  freopen(argv[1], "r", stdin);

  std::cin >> ROWS >> COLS;
  std::vector<std::bitset<MAXCOLS>> map(ROWS);
  for (int r = 0; r < ROWS; ++r) std::cin >> map[r];

  std::vector<int> answers;
  for (int r = 0; r < ROWS; ++r) {
    for (int c = 0; c < COLS; ++c)
      if (map[r][c]) answers.push_back(solve(map, r, c));
  }

  std::cout << answers.size() << std::endl;
  for (int sz : answers) std::cout << sz << " ";
  std::cout << std::endl;
  
  return 0;
}
