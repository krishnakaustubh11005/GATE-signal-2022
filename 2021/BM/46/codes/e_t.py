import matplotlib.pyplot as plt
import numpy as np


t = np.linspace(0, 2, 10000)

r = np.loadtxt("e_tcout.txt")

plt.plot(t, r)

plt.xlabel("Time ($t$)")
plt.ylabel("$e(t)$")

plt.savefig("e_t.png")
