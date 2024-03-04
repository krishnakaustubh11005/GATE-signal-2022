import numpy as np
import matplotlib.pyplot as plt

# Load data
data = np.loadtxt('data77.dat')
n = data[:, 0]
x = data[:, 1]

# Plot
plt.stem(n, x)
plt.xlabel('n')
plt.ylabel('x(n)')
plt.grid(True)
plt.savefig('transform.png')
