#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stack>

int main(int argc, char **argv)
{
  if (argc < 2) exit(-1);
  freopen(argv[1], "r", stdin);

  int n;
  std::cin >> n;
  std::stack<char> storage;

  bool invalid = false;
  while (n--) {
    char ch;
    std::cin >> ch;

    if (islower(ch)) {
      storage.push(toupper(ch));
    }
    else {
      if (storage.empty() or storage.top() != ch) {
        invalid = true;
        break;
      }
      storage.pop();
    }
  }

  if (!storage.empty() or invalid) std::cout << '0' << std::endl;
  else std::cout << '1' << std::endl;

  return 0;
}
