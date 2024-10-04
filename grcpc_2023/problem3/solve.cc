#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <set>

int main(int argc, char **argv)
{
  if (argc < 2) exit(-1);
  freopen(argv[1], "r", stdin);

  int m, n;
  std::string course;
  std::cin >> m;
  std::set<std::string> courses;

  while(m--) {
    std::cin >> course;
    courses.insert(course);
  }
  size_t original_sz = courses.size();

  std::cin >> n;
  while (n--) {
    std::cin >> course;
    courses.insert(course);
  }

  if (original_sz != courses.size()) std::cout << "0" << std::endl;
  else std::cout << "1" << std::endl;

  return 0;
}
