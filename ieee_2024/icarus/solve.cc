#include <bits/stdc++.h>

std::string moves;
int total_nodes = 0;

typedef struct Node_t {
  Node_t *U;
  Node_t *L;
  Node_t *R;
} Node_t;

Node_t *make_node(void)
{
  total_nodes++;
  Node_t *node = new Node_t {NULL, NULL, NULL};
  return node;
}

void print_tree(Node_t *root)
{
  int id = 2;
  std::queue<Node_t *> q;
  if (root == NULL) {
    std::cout << "ROOT IS NULL" << std::endl;
    return;
  }
  q.push(root);
  while (!q.empty()) {
    Node_t *node = q.front();
    q.pop();
    if (node->L != NULL) {
      q.push(node->L);
      std::cout << id++ << " ";
    }
    else {
      std::cout << "0 ";
    }
    if (node->R != NULL) {
      q.push(node->R);
      std::cout << id++ << std::endl;
    }
    else {
      std::cout << "0" << std::endl;
    }
  }
}

int main(void)
{
  std::cin >> moves;
  Node_t *node = make_node();
  Node_t *root = node;
  int lvl = 0, minlvl = 0;

  for (auto c: moves) {
    printf("root @ %p\n", root);
    switch (c) {
      case 'U':
        if (node->U == NULL) {
          Node_t *new_node = make_node();
          new_node->L = node;
          node->U = new_node;
        }
        node = node->U;
        lvl--;
        if (lvl < minlvl) {
          minlvl = lvl;
          root = node;
        }
        break;
      case 'L':
        if (node->L == NULL) {
          Node_t *new_node = make_node();
          new_node->U = node;
          node->L = new_node;
        }
        node = node->L;
        lvl++;
        break;
      case 'R':
        if (node->R == NULL) {
          Node_t *new_node = make_node();
          new_node->U = node;
          node->R = new_node;
        }
        node = node->R;
        lvl++;
        break;
      default:
        std::cout << "WTF" << std::endl;
        exit(-1);
    }
  }

  for (;;) {


  }

  print_tree(root);

  return 0;
}
