#!/usr/bin/env python3

def inBounds(dat, x, y): return x >= 0 and y >= 0 and x < len(dat) and y < len(dat[0])

'''
KEYWORD = 'XMAS'

def search(dat, x, y, dir, keyword_idx=0):
  if keyword_idx == len(KEYWORD): return True
  if not inBounds(dat, x, y): return False
  # right
  if dir == 'r':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x, y+1, 'r', keyword_idx+1)
  # left
  if dir == 'l':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x, y-1, 'l', keyword_idx+1)
  # up
  if dir == 'u':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x-1, y, 'u', keyword_idx+1)
  # down
  if dir == 'd':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x+1, y, 'd', keyword_idx+1)
  # up-right
  if dir == 'ur':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x-1, y+1, 'ur', keyword_idx+1)
  # up-left
  if dir == 'ul':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x-1, y-1, 'ul', keyword_idx+1)
  # down-right
  if dir == 'dr':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x+1, y+1, 'dr', keyword_idx+1)
  # down-left
  if dir == 'dl':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x+1, y-1, 'dl', keyword_idx+1)
  return False

#with open('small_input.txt', 'r') as f:
with open('input.txt', 'r') as f:
  dat = [list(line.strip()) for line in f.readlines()]

acc = 0
for x in range(len(dat)):
  for y in range(len(dat[0])):
    for dir in ('r', 'l', 'u', 'd', 'ur', 'ul', 'dr', 'dl'):
      if search(dat, x, y, dir=dir): acc += 1

print(acc)
'''

KEYWORD = 'MAS'
positions = {}

def search(dat, x, y, dir, keyword_idx=0, A_pos=None):
  if keyword_idx == len(KEYWORD):
    positions[A_pos] += 1
    return True
  if not inBounds(dat, x, y): return False
  # up-right
  if dat[x][y] == 'A':
    A_pos = (x, y)
    if A_pos not in positions.keys(): positions[A_pos] = 0
  if dir == 'ur':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x-1, y+1, 'ur', keyword_idx+1, A_pos)
  # up-left
  if dir == 'ul':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x-1, y-1, 'ul', keyword_idx+1, A_pos)
  # down-right
  if dir == 'dr':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x+1, y+1, 'dr', keyword_idx+1, A_pos)
  # down-left
  if dir == 'dl':
    if dat[x][y] == KEYWORD[keyword_idx]:
      return search(dat, x+1, y-1, 'dl', keyword_idx+1, A_pos)
  return False

#with open('small_input.txt', 'r') as f:
with open('input.txt', 'r') as f:
  dat = [list(line.strip()) for line in f.readlines()]

for x in range(len(dat)):
  for y in range(len(dat[0])):
    for dir in ('ur', 'ul', 'dr', 'dl'):
      search(dat, x, y, dir=dir)

acc = 0
for val in positions.values():
  if val >= 2: acc += 1

print(acc)