import numpy as np
import matplotlib.pyplot as plt

# Load data from file
data = np.loadtxt('data.txt')
x = data[:, 0]
y = data[:, 1]

# Plot the graph
plt.plot(x, y, label=r'$y=\frac{1}{2}\sin(2x)$')
plt.xlabel('x')
plt.ylabel('y(x)')
plt.legend()
plt.grid(True)
plt.savefig('a.png')

