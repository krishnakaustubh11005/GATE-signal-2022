import numpy as np
import matplotlib.pyplot as plt

with open('x_data.txt', 'r') as file:
    x_values = [float(line.strip()) for line in file]
# Generate values for n from 0 to 5
n_values = np.arange(0, 30)

# Plot the stem plot
plt.stem(n_values, x_values)
plt.xlabel('n')
plt.ylabel('x(n)')
plt.grid(True)
plt.savefig('figs/fig.png')
plt.show()

