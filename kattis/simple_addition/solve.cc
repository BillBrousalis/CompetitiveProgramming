#include <iostream>
#include <vector>

int main(void)
{
  std::string x1, x2;
  std::cin >> x1 >> x2;
  std::vector<int> out;
  if (x1.size() < x2.size()) swap(x1, x2);
  x2.insert(0, x1.size() - x2.size(), '0');

  int carry = 0, i = x1.size() - 1;
  while (i >= 0 || carry > 0) {
    int digit = (i<0 ? 0 : (x1[i]-'0' + x2[i]-'0')) + carry;
    carry = digit / 10;
    out.insert(out.begin(), digit % 10);
    i--;
  }

  for (int i = 0; i < out.size(); ++i)
    std::cout << out[i];
  std::cout << std::endl;

  return 0;
}
