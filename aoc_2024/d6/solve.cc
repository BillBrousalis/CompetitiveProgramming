#include <bits/stdc++.h>

typedef enum {
  U=0,
  R,
  D,
  L,
  DIR_END
} dir_t;

bool inBounds(std::vector<std::string> &map, int x, int y)
{
  return x >= 0 && y >= 0 && x < map[0].size() && y < map.size();
}

void changeDir(dir_t &dir)
{
  dir = (dir_t)((dir + 1) % DIR_END);
}

int solve1(std::vector<std::string> map, int x, int y)
{
  dir_t dir = U;
  for (;;) {
    map[y][x] = 'X';
    int old_x = x;
    int old_y = y;
    switch (dir) {
    case U:
      y--;
      break;
    case R:
      x++;
      break;
    case D:
      y++;
      break;
    case L:
      x--;
      break;
    default:
      std::cout << "Wtf" << std::endl;
      return -1;
    }

    if (!inBounds(map, x, y)) break;
    if (map[y][x] == '#') {
      x = old_x;
      y = old_y;
      changeDir(dir);
    }
  }

  int acc = 0;
  for (auto l: map) {
    for (auto c: l) {
      acc += c == 'X' ? 1 : 0;
    }
  }
  return acc;
}

int solve2(std::vector<std::string> &map, int x, int y)
{
  int acc = 0;
  int init_x = x;
  int init_y = y;
  int steps;
  for (int i = 0; i < map.size(); ++i) {
    // sanity
    //if (i % 10 == 0) {
    //  std::cout << "ROW " << i << std::endl;
    //}
    for (int j = 0; j < map[0].size(); ++j) {
      if (map[i][j] == '#' or map[i][j] == '^') continue;
      // add obstacle
      map[i][j] = '#';

      x = init_x;
      y = init_y;

      // make history map
      std::vector<std::vector<std::vector<dir_t>>> history (map.size(), std::vector<std::vector<dir_t>>(map[0].size()));
      dir_t dir = U;

      steps = 0;
      while (true) {
        steps++;
        bool found = false;
        if (std::find(history[y][x].begin(), history[y][x].end(), dir) != history[y][x].end()) {
          // if already visited with same dir -> stuck in loop
          acc++;
          break;
        }
        history[y][x].push_back(dir);

        int old_x = x;
        int old_y = y;
        switch (dir) {
        case U:
          y--;
          break;
        case R:
          x++;
          break;
        case D:
          y++;
          break;
        case L:
          x--;
          break;
        default:
          std::cout << "Wtf" << std::endl;
          return -1;
        }
        if (!inBounds(map, x, y)) {
          break;
        }
        if (map[y][x] == '#') {
          x = old_x;
          y = old_y;
          changeDir(dir);
        }
      }

      // reset
      map[i][j] = '.';
    }
  }
  return acc;
}

int main(void)
{
  //std::ifstream input("small_input.txt");
  std::ifstream input("input.txt");

  std::vector<std::string> map;
  std::string line;
  int x, y;
  while (std::getline(input, line)) {
    map.push_back(line);
    for (int i = 0; i < line.size(); ++i) {
      // starting coords
      if (line[i] == '^') {
        x = i;
        y = map.size() - 1;
      }
    }
  }


  std::cout << "part1 = " << solve1(map, x, y) << std::endl;
  std::cout << "part2:" << solve2(map, x, y) << std::endl;

  return 0;
}
