import numpy as np
import matplotlib.pyplot as plt

# Read data from the file
data = np.loadtxt('data.out')

# Extract values of n and H_d(n)
n_values = data[:, 0]
H_values = data[:, 1]

# Plotting
plt.stem(n_values, H_values, markerfmt='o', linefmt='-')
plt.xlabel('$n$')
plt.ylabel('$H_d(n)$')
plt.grid(True)
plt.savefig('plot.png')
plt.show()

