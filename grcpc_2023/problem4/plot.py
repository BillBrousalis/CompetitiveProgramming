#!/usr/bin/env python3
import matplotlib.pyplot as plt

y = list(map(lambda x: float(x), '31 32 33 25.91 31 30 35'.split (' ')))
x = [i for i in range(len(y))]

plt.plot(x, y)
plt.show()
