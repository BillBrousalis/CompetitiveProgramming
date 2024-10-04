#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

//#define DEBUG

typedef struct {
  int rows;
  int cols;
  char **maze;
  bool **visited;
  std::stack<std::pair<int, int>> stack;
  char walls;

  void stack_push(std::pair<int, int> coords) {
    stack.push(coords);
  }

  void stack_pop() {
    if (!stack.empty()) stack.pop();
    else std::cout << "Stack is empty, cannot pop!" << std::endl;
  }

  std::pair<int, int> stack_top() const {
    if (stack.empty()) throw "Stack is empty!";
    return stack.top();
  }

  bool stack_isEmpty() const {
    return stack.empty();
  }

  size_t stack_size() {
    return stack.size();
  }

  void stack_clear() {
    stack = std::stack<std::pair<int, int>>();
  }

} Solver_t;

void reset_solver(Solver_t *solver)
{
  solver->stack_clear();
  for (int r = 0; r < solver->rows; ++r) {
    for (int c = 0; c < solver->cols; ++c)
      solver->visited[r][c] = false;
  }
}

Solver_t *make_solver(unsigned int rows, unsigned int cols)
{
  Solver_t *solver = new Solver_t();
  solver->rows = rows;
  solver->cols = cols;
  solver->maze = new char *[solver->rows];
  solver->visited = new bool*[solver->rows];
  for (int i = 0; i < solver->rows; ++i) {
    solver->maze[i] = new char[solver->cols];
    solver->visited[i] = new bool[solver->cols];
  }
  return solver;
}

void parse_maze(Solver_t *solver)
{
  for (int r = 0; r < solver->rows; ++r) {
    for (int c = 0; c < solver->cols; ++c)
      std::cin >> solver->maze[r][c];
  }
}

std::pair<int, int> get_next_adjacent(Solver_t *solver, int r, int c, int r2, int c2)
{
  if (r+1 < solver->rows && solver->maze[r+1][c] != solver->walls && !solver->visited[r+1][c]) return std::make_pair(r+1, c);
  if (c+1 < solver->cols && solver->maze[r][c+1] != solver->walls && !solver->visited[r][c+1]) return std::make_pair(r, c+1);
  if (r-1 >= 0 && solver->maze[r-1][c] != solver->walls && !solver->visited[r-1][c])           return std::make_pair(r-1, c);
  if (c-1 >= 0 && solver->maze[r][c-1] != solver->walls && !solver->visited[r][c-1])           return std::make_pair(r, c-1);
  return std::pair<int, int>(-1, -1);
}

std::string solver_dfs(Solver_t *solver, int r1, int c1, int r2, int c2)
{
  solver->stack_push(std::make_pair(r1, c1));
  solver->visited[r1][c1] = true;
  while (r1 != r2 || c1 != c2) {
    if (!solver->visited[r1][c1]) {
      solver->visited[r1][c1] = true;
      solver->stack_push(std::make_pair(r1, c1));
    }
    std::pair<int, int> next_coords = get_next_adjacent(solver, r1, c1, r2, c2);
    if (next_coords.first != -1 && next_coords.second != -1) {
      r1 = next_coords.first;
      c1 = next_coords.second;
      continue;
    }
    solver->stack_pop();
    if (solver->stack_isEmpty()) return "neither";
    next_coords = solver->stack_top();
    r1 = next_coords.first;
    c1 = next_coords.second;
  }
  return solver->maze[r2][c2] == '0' ? "binary" : "decimal";
}

int main(void)
{
  //freopen("input.txt", "r", stdin);

  unsigned int r, c;
  std::cin >> r >> c;
  Solver_t *solver = make_solver(r, c);
  parse_maze(solver);

  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;
    if (solver->maze[r1-1][c1-1] != solver->maze[r2-1][c2-1]) {
      std::cout << "neither" << std::endl;
      continue;
    }
    reset_solver(solver);
    solver->walls = solver->maze[r1-1][c1-1] == '0' ? '1' : '0';
    std::cout << solver_dfs(solver, r1-1, c1-1, r2-1, c2-1) << std::endl;
  }

  return 0;
}
