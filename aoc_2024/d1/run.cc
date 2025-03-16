#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define N 1000

int main(void)
{
  freopen("input.txt", "r", stdin);

  std::vector<long> nums1(N);
  std::vector<long> nums2(N);

  for (int i = 0; i < N; ++i)
    std::cin >> nums1[i] >> nums2[i];

  std::sort(nums1.begin(), nums1.end());
  std::sort(nums2.begin(), nums2.end());

  long diff = 0;
  for (int i = 0; i < N; ++i)
    diff += abs(nums1[i] - nums2[i]);

  std::cout << "part1: " << diff << std::endl;

  long similarity_score = 0;
  for (int i = 0; i < N; ++i)
    similarity_score += nums1[i] * std::count(nums2.begin(), nums2.end(), nums1[i]);

  std::cout << "part2: " << similarity_score << std::endl;

  return 0;
}
