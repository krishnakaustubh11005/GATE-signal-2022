import numpy as np
import matplotlib.pyplot as plt

# Load data from file using NumPy
data = np.loadtxt('data.txt')

# Separate frequencies and values
frequencies = data[:, 0]
values = data[:, 1]

# Plot the graph
plt.figure(figsize=(8, 6))
plt.plot(frequencies, values, label=r'X(f)', color='blue')
plt.xlabel('$f$')
plt.ylabel('$X(f)$')
plt.grid(True)
plt.legend()
plt.savefig("graph.png")
