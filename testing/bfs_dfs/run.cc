#include <iostream>
#include <stack>

class Node {
public:
  char C;
  Node *left;
  Node *right;

  Node(char c) {
    C = c;
    left = nullptr;
    right = nullptr;
  }
};

void dfs(Node& root)
{
  std::stack<Node> nodestack;
  nodestack.push(root);
}

int main(void)
{
  return 0;
}
