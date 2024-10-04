#include <iostream>
#include <vector>

typedef struct {
  int *board;
  bool *visited;
} Board_t;

Board_t *make_board(int n)
{
  Board_t *board = (Board_t *)malloc(sizeof(Board_t));
  board->board = (int *)malloc(n * sizeof(int));
  board->visited = (bool *)malloc(n * sizeof(bool));
  return board;
}

int main(void)
{
  //freopen("input.txt", "r", stdin);

  int n, s, m, nmoves = 0;
  std::cin >> n >> s >> m;
  Board_t *board = make_board(n);
  for (int i = 0; i < n; ++i) std::cin >> board->board[i];

  s--; // zero-base
  std::string state = "";
  for (;;) {
    if (s < 0) state = "left";
    else if (s >= n) state = "right";
    else if (board->board[s] == m) state = "magic";
    else if (board->visited[s]) state = "cycle";
    if (state != "") break;
    board->visited[s] = true;
    s += board->board[s];
    nmoves++;
  }
  std::cout << state << "\n" << nmoves << std::endl;

  return 0;
}
