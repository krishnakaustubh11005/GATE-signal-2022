import numpy as np
import matplotlib.pyplot as plt

# Read data from the dat file
data = np.loadtxt("data9.dat")

# Extract freq and mag values
w_values = data[:, 0]
m_values = data[:, 1]

# Plot the graph
plt.plot(w_values, m_values)
plt.axhline(0, color='black', linewidth=1.5)
plt.axvline(0, color='black', linewidth=1.5)
plt.xlabel('w(in rad/s)')
plt.ylabel('|T(s)|')
plt.legend()
plt.grid(True)
plt.show()
