#!/usr/bin/env python3

with open("input.txt", "r") as f:
  lines = f.readlines()

nums1 = [int(line.split("   ")[0]) for line in lines]
nums2 = [int(line.split("   ")[1]) for line in lines]
nums1.sort()
nums2.sort()

acc = 0
for num1, num2 in zip(nums1, nums2):
  acc += abs(num1 - num2)
print(acc)
