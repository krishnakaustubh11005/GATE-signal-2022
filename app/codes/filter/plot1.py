import numpy as np
import matplotlib.pyplot as plt

# Read data from the dat file
data = np.loadtxt("data.dat")

# Extract time and y(t) values
t_values = data[:, 0]
y_t1_values = data[:, 1]
y_t2_values = data[:, 2]
y_t3_values = data[:, 3]

# Plot the graph
plt.plot(t_values, y_t1_values, label = 'overdamped')
plt.plot(t_values, y_t2_values, label = 'cridamped')
plt.plot(t_values, y_t3_values, label = 'underdamped')

plt.axhline(0, color='black', linewidth=1.5)
plt.axvline(0, color='black', linewidth=1.5)
plt.xlabel('t(in s)')
plt.ylabel('y(t)')
plt.legend()
plt.grid(True)
plt.legend(['overdamped', 'cridamped', 'underdamped'])
plt.show()

