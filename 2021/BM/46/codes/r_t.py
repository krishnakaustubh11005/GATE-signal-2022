import matplotlib.pyplot as plt
import numpy as np


t = np.linspace(0, 2, 10000)

r = np.loadtxt("r_tcout.txt")

plt.plot(t, r)

plt.xlabel("Time ($t$)")
plt.ylabel("$r(t)$")

plt.savefig("r_t.png")
