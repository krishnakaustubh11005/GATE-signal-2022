import numpy as np
import matplotlib.pyplot as plt


c = np.loadtxt("data.dat", delimiter='\t')
plt.plot(c[:, 0], c[:, 1])
plt.title("Plot of function h(t)")
plt.grid(1)
plt.xlabel('t')
plt.ylabel('h(t)')
plt.savefig("fig_1.jpg")

