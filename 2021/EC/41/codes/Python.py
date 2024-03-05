import numpy as np
import matplotlib.pyplot as plt

# Read data from file
data = np.loadtxt("data.txt")

# Separate data into n and z(n) values
n_values = data[:, 0]
z_values = data[:, 1]

# Plot data
plt.stem(n_values, z_values)
plt.xlabel('$n$')
plt.ylabel('$z(n)$')
plt.grid(True)
highlight_n = 0
highlight_z = z_values[np.where(n_values == highlight_n)][0]
plt.plot(highlight_n, highlight_z, 'ro') 
plt.show()

