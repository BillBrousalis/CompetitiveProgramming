#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

#define N 1000

bool descending_comp(int a, int b) { return a > b; }

int main(void)
{
  //std::ifstream inputFile("small_input.txt");
  std::ifstream inputFile("input.txt");
  std::string line;

  /*
  unsigned long acc = 0;
  while(std::getline(inputFile, line)) {
    std::vector<unsigned int> values;
    std::stringstream ss(line);
    unsigned int val;
    while (ss >> val) {
      values.push_back(val);
    }

    bool safe = true;
    if (!std::is_sorted(values.begin(), values.end()) &&
        !std::is_sorted(values.begin(), values.end(), descending_comp)) {
        safe = false;
        continue;
    }

    unsigned int prev = values[0];
    for (int i = 1; i < values.size(); ++i) {
      unsigned int curr = values[i];
      if (abs(curr - prev) > 3 or abs(curr - prev) < 1) {
        safe = false;
        break;
      }
      prev = curr;
    }
    acc += safe ? 1 : 0;
  }
  */

  unsigned long acc = 0;
  while(std::getline(inputFile, line)) {
    std::vector<unsigned int> values;
    std::stringstream ss(line);
    unsigned int val;
    while (ss >> val) {
      values.push_back(val);
    }

    bool safe;
    for (int off = 0; off < values.size(); ++off) {
      safe = true;
      std::vector<unsigned int> slice;
      for (int i = 0; i < values.size(); ++i) {
        if (i == off) continue;
        slice.push_back(values[i]);
      }

      if (!std::is_sorted(slice.begin(), slice.end()) &&
          !std::is_sorted(slice.begin(), slice.end(), descending_comp)) {
          safe = false;
          continue;
      }

      unsigned int prev = slice[0];
      for (int i = 1; i < slice.size(); ++i) {
        unsigned int curr = slice[i];
        if (abs(curr - prev) > 3 or abs(curr - prev) < 1) {
          safe = false;
          break;
        }
        prev = curr;
      }

      if (safe) {
        acc++;
        break;
      }
    }
  }

  std::cout << acc << std::endl;

  return 0;
}
