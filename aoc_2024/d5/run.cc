#include <bits/stdc++.h>

int solve1(const std::vector<std::pair<int, int>> &rules, const std::vector<std::vector<int>> &updates) {
  int acc = 0;
  for (auto u : updates) {
    bool valid = true;
    for (auto r : rules) {
      auto idx1 = std::find(u.begin(), u.end(), r.first);
      auto idx2 = std::find(u.begin(), u.end(), r.second);
      if (idx1 == u.end() || idx2 == u.end()) continue;
      if (idx1 > idx2) {
        valid = false;
        break;
      }
    }
    if (valid) acc += u[u.size() / 2];
  }

  return acc;
}

int solve2(const std::vector<std::pair<int, int>> &rules, std::vector<std::vector<int>> &updates) {
  int acc = 0;
  for (auto u : updates) {
    bool valid = true;
    for (auto r : rules) {
      auto idx1 = std::find(u.begin(), u.end(), r.first);
      auto idx2 = std::find(u.begin(), u.end(), r.second);
      if (idx1 == u.end() || idx2 == u.end()) continue;
      if (idx1 > idx2) {
        valid = false;
        break;
      }
    }
    if (valid) continue;

    while (!valid) {
      for (auto r : rules) {
        auto idx1 = std::find(u.begin(), u.end(), r.first);
        auto idx2 = std::find(u.begin(), u.end(), r.second);
        if (idx1 == u.end() || idx2 == u.end()) continue;
        if (idx1 > idx2) {
          valid = false;
          std::swap(u[idx1 - u.begin()], u[idx2 - u.begin()]);
          break;
        }
        valid = true;
      }
    }
    acc += u[u.size() / 2];
  }

  return acc;
}

int main(void) {
  //std::ifstream file("small_input.txt");
  std::ifstream file("input.txt");

  std::vector<std::pair<int, int>> rules;
  std::vector<std::vector<int>> updates;

  bool parsing_rules = true;
  while (!file.eof()) {
    std::string line;
    std::getline(file, line);

    if (line.empty()) parsing_rules = false;

    if (parsing_rules) {
      int r1, r2;
      sscanf(line.c_str(), "%d|%d", &r1, &r2);
      rules.push_back(std::make_pair(r1, r2));
    }
    else {
      std::string num;
      std::stringstream ss(line);
      std::vector<int> update;
      while (std::getline(ss, num, ','))
        update.push_back(std::stoi(num));
      if (update.size()) updates.push_back(update);
    }
  }

  std::cout << "part1: " << solve1(rules, updates) << std::endl;
  std::cout << "part2: " << solve2(rules, updates) << std::endl;
  file.close();
  return 0;
}