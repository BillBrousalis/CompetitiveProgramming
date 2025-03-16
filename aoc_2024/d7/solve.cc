#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>

typedef enum {
  ADD,
  MUL,
  OPS_END
} ops_t;

typedef struct node_t {
  unsigned long val;
  node_t **children;
} node_t;

node_t *createNode(unsigned long val)
{
  node_t *node = new node_t;
  node->val = val;
  node->children = new node_t*[OPS_END];
  return node;
}

void freeTree(node_t *root)
{
  if (root == nullptr) return;
  for (int op = ADD; op < OPS_END; ++op) {
    node_t *n = root->children[op];
    if (n != nullptr) freeTree(n);
  }
  delete root->children;
  delete root;
}

bool isSolvable(unsigned long target, std::vector<unsigned long> &args)
{
  // construct tree
  node_t *root = createNode(args[0]);
  root->val = args[0];
  std::stack<node_t *> nodestack;
  nodestack.push(root);
  for (int i = 1; i < args.size(); ++i) {
    std::vector<node_t *> leaves;
    while (!nodestack.empty()) {
      node_t *current = nodestack.top();
      nodestack.pop();
      for (int op = ADD; op < OPS_END; ++op) {
        node_t *node = createNode(args[i]);
        if (static_cast<ops_t>(op) == ADD) node->val = current->val + args[i];
        else if (static_cast<ops_t>(op) == MUL) node->val = current->val * args[i];
        current->children[(int)op] = node;
        leaves.push_back(node);
        if (i == args.size() - 1 and node->val == target) {
          freeTree(root);
          return true;
        }
      }
    }
    for (auto l : leaves) nodestack.push(l);
  }
  freeTree(root);
  return false;
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return -1;
  }
  std::ifstream input(argv[1]);
  std::string line;

  unsigned long acc = 0;
  while (std::getline(input, line)) {
    //std::cout << line << std::endl;
    std::stringstream ss(line);
    unsigned long target;
    char colon;
    std::vector<unsigned long> args;
    ss >> target >> colon;
    unsigned long arg;
    while (ss >> arg) args.push_back(arg);
    if (isSolvable(target, args)) acc += target;
  }

  std::cout << "part1: " << acc << std::endl;
  return 0;
}