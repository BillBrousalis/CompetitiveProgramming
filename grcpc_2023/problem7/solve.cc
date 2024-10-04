#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stack>
#include <array>
#include <set>

#define IT std::set<int>::iterator

bool have_common_element(IT first1, IT last1, IT first2, IT last2) {
  while (first1 != last1 && first2 != last2) {
    if (*first1 < *first2) ++first1;
    else if (*first2 < *first1) ++first2;
    else return true;
  }
  return false;
}

int main(int argc, char **argv)
{
  if (argc < 2) exit(-1);
  freopen(argv[1], "r", stdin);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::set<int>> relations;

  while (m--) {
    int i, j;
    std::cin >> i >> j;
    if (i == j) {
      std::cout << "E\n";
      continue;
    }
    //std::cout << i << " " << j << std::endl;
    int idxi = -1, idxj = -1;
    //std::cout << "Relations:" << std::endl;
    for (int v = 0; v < relations.size(); ++v) {
      /*
      std::cout << "[" << v << "]: ";
      for (auto x: relations[v]) std::cout << x << " ";
      std::cout << std::endl;
      */
      if (idxi != -1 && idxj != -1) break;
      if (idxi == -1 && relations[v].find(i) != relations[v].end()) idxi = v;
      if (idxj == -1 && relations[v].find(j) != relations[v].end()) idxj = v;
    }

    int changed_idx;
    std::string print = "";
    if (idxi == -1 && idxj == -1) {
      relations.push_back(std::set<int>());
      relations[relations.size()-1].insert(i);
      relations[relations.size()-1].insert(j);
      changed_idx = relations.size() - 1;
      print = "N";
    }
    else if (idxi != -1 && idxj == -1) {
      print = "N";
      changed_idx = idxi;
      relations[idxi].insert(j);
      if (relations[idxi].find(-j) != relations[idxi].end()) {
        std::cout << "C\n";
        goto end;
      }
    }
    else if (idxi == -1 && idxj != -1) {
      print = "N";
      changed_idx = idxj;
      relations[idxj].insert(i);
      if (relations[idxj].find(-i) != relations[idxj].end()) {
        std::cout << "C\n";
        goto end;
      }
    }
    else if (idxi != -1 && idxj != -1) {
      changed_idx = idxi;
      if (idxi != idxj) {
        //merge and check
        relations[idxi].insert(relations[idxj].begin(), relations[idxj].end());
        relations.erase(relations.begin()+idxj);
        print = "N";
      }
      else {
        print = "E";
      }
    }

    /*
    std::cout << "(B) Relations:" << std::endl;
    for (int v = 0; v < relations.size(); ++v) {
      std::cout << "[" << v << "]: ";
      for (auto x: relations[v]) std::cout << x << " ";
      std::cout << std::endl;
    }
    */

    for (int v = 0; v < relations.size()-1; ++v) {
      if (v == changed_idx) continue;
      if (have_common_element(relations[v].begin(), relations[v].end(), relations[changed_idx].begin(), relations[changed_idx].end())) {
        //merge and check
        relations[v].insert(relations[changed_idx].begin(), relations[changed_idx].end());
        relations.erase(relations.begin()+changed_idx);
        for (auto x: relations[v]) {
          if (relations[v].find(-x) != relations[v].end()) {
            std::cout << "C\n";
            goto end;
          }
        }
        break;
      }
    }
    std::cout << print << "\n";
  }

end:
  return 0;
}
