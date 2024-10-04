#!/usr/bin/env python3
import subprocess

def format(s):
  s = s.split('\n')
  s[0] = int(s[0])
  s[1] = list(map(lambda x: int(x), s[1].split(' ')))
  s[1].sort()
  return s

if __name__ == '__main__':
  print('[*] Running tests:')
  for i in range(1, 21):
    path = f'problem_2_amazing_lakes/inputs/input_{i:02d}'
    inpath, outpath = f'{path}.in', f'{path}.ans'
    print(f'Testing: {inpath} -> ', end='')
    out = subprocess.run(['./run', inpath], stdout=subprocess.PIPE).stdout.decode().strip()
    outf = format(out)
    with open(outpath, 'r') as f:
      gt_out = f.read().strip()
      gt_outf = format(gt_out)
    if outf[0] != gt_outf[0] or outf[1] != gt_outf[1]:
      print(f'FAIL\n'
            f'Program output: {out}\n'
            f'Correct output: {gt_out}')
    else:
      print('PASS')
