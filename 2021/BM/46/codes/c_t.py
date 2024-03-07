import matplotlib.pyplot as plt
import numpy as np


t = np.linspace(0, 2, 10000)

r = np.loadtxt("c_tcout.txt")

plt.plot(t, r)

plt.xlabel("Time ($t$)")
plt.ylabel("$c(t)$")

plt.savefig("c_t.png")
