#include <iostream>
#include <vector>

int main(void)
{
  //freopen("input.txt", "r", stdin);

  int n, nmoves = 0;
  short m, s;
  std::cin >> n >> s >> m;
  int board[n];
  for (int i = 0; i < n; ++i) {
    short x;
    std::cin >> x;
    board[i] = x;
  }

  s--; // zero-base
  std::string state = "";
  for (;;) {
    if (s < 0) state = "left";
    else if (s >= n) state = "right";
    else if ((short)board[s] == m) state = "magic";
    else if (board[s]&(1<<31)) state = "cycle";
    if (state != "") break;
    board[s] |= 1 << 31;
    s += (short)board[s];
    nmoves++;
  }
  std::cout << state << "\n" << nmoves << std::endl;

  return 0;
}
