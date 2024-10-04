#!/usr/bin/env python3
import subprocess

if __name__ == '__main__':
  print('[*] Running tests:')
  for i in range(1, 21):
    path = f'problem_7_union_find_pain/inputs/input_{i:02d}'
    inpath, outpath = f'{path}.in', f'{path}.ans'
    print(f'Testing: {inpath} -> ', end='')
    out = subprocess.run(['./run', inpath], stdout=subprocess.PIPE).stdout.decode().strip()
    out = [x for x in out.split('\n') if x != '']
    with open(outpath, 'r') as f:
      gt_out = f.read().strip()
      gt_out = [x for x in gt_out.split('\n') if x != '']
    if out != gt_out:
      print(f'FAIL')#\n'
            #f'Program output: {out}\n'
            #f'Correct output: {gt_out}')
    else:
      print('PASS')
