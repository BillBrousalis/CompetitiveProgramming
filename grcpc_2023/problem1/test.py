#!/usr/bin/env python3
from glob import glob
import subprocess

if __name__ == '__main__':
  print('[*] Running tests:')
  for i in range(0, 24):
    path = f'problem_1_dominant-points/inputs/input_{i:02d}_alloy'
    inpath, outpath = f'{path}.in', f'{path}.ans'
    print(f'Testing: {inpath} -> ', end='')
    # [:-1] since last space is junk
    out = list(map(lambda x: int(x), subprocess.run(['./run', inpath], stdout=subprocess.PIPE).stdout.decode().split(' ')[:-1]))
    out.sort()
    with open(outpath, 'r') as f:
      gt_out = list(map(lambda x: int(x), f.read().split(' ')))
      gt_out.sort()
    if out != gt_out:
      print(f'FAIL\n'
            f'Program output: {" ".join([str(x) for x in out])}\n'
            f'Correct output: {" ".join([str(x) for x in gt_out])}')
    else:
      print('PASS')
