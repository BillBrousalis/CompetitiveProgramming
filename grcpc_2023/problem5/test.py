#!/usr/bin/env python3
import subprocess

if __name__ == '__main__':
  print('[*] Running tests:')
  for i in (1, 3, 4, 7): # ???
    path = f'problem_5_maxgrowht/inputs/input_{i}_tempe'
    inpath, outpath = f'{path}.in', f'{path}.ans'
    print(f'Testing: {inpath} -> ', end='')
    out = subprocess.run(['./run', inpath], stdout=subprocess.PIPE).stdout.decode().strip()
    with open(outpath, 'r') as f:
      gt_out = f.read().strip()
    if out != gt_out:
      print(f'FAIL\n'
            f'Program output: {out}\n'
            f'Correct output: {gt_out}')
    else:
      print('PASS')
