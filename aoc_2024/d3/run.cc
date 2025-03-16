#include <bits/stdc++.h>

/*
int main(void) {
    //std::ifstream file("small_input.txt");
    std::ifstream file("input.txt");

    std::regex pattern(R"(mul\((\d+),(\d+)\))"); // Regex pattern for mul(X,Y)
    std::smatch match;
  
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string contents = buffer.str();

    auto begin = contents.cbegin();
    auto end = contents.cend();

    int acc = 0;
    while (std::regex_search(begin, end, match, pattern)) {
      acc += std::stoi(match[1]) * std::stoi(match[2]);
      begin = match.suffix().first;
    }

    std::cout << "part1: " << acc << std::endl;
    file.close();
    return 0;
}
*/

int main(void) {
    //std::ifstream file("small_input.txt");
    std::ifstream file("input.txt");

    std::regex pattern(R"(mul\((\d+),(\d+)\))"); // Regex pattern for mul(X,Y)
    std::smatch match;
  
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string contents = buffer.str();

    auto startpos = 0;
    auto endpos = 0;

    int acc = 0;
    while (startpos != std::string::npos) {

      endpos = contents.find("don't()", startpos);
      if (endpos == std::string::npos) {
        endpos = contents.size();
      }

      std::string section = contents.substr(startpos, endpos - startpos);
      auto begin = section.cbegin();
      auto end = section.cend();

      while (std::regex_search(begin, end, match, pattern)) {
        acc += std::stoi(match[1]) * std::stoi(match[2]);
        begin = match.suffix().first;
      }
      startpos = contents.find("do()", endpos) + 4;
      if (endpos == contents.size()) break;
    }


    std::cout << "part2: " << acc << std::endl;
    file.close();
    return 0;
}