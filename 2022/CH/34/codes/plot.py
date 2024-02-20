import numpy as np
import matplotlib.pyplot as plt

# Load data from the file
data_file = 'data5.dat'
data = np.loadtxt(data_file)

# Separate values of s and Y(s)
s_values, Y_values = data[:, 0], data[:, 1]

# Plot the graph
plt.plot(s_values, Y_values, label=r'$Y(t) = 1 + e^{-t/5}$')
plt.xlabel('t')
plt.ylabel('Y(t)')
plt.legend()
plt.grid(True)
plt.show()

