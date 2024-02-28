import numpy as np
import matplotlib.pyplot as plt

# Read data from the dat file
data = np.loadtxt("data6_1.dat")

# Extract time and y values
t_values = data[:, 0]
y_values = data[:, 1]

# Plot the graph
plt.plot(t_values, y_values, label=r'$y(t) = (1 - 2e^{-at})u(t)$')
plt.axhline(0, color='black', linewidth=1.5)
plt.axvline(0, color='black', linewidth=1.5)
plt.xlabel('t(in \u00B5 s)')
plt.ylabel('y(t)')
plt.legend()
plt.grid(True)
plt.show()
plt.clf()

# Read data from the dat file
data = np.loadtxt("data6_2.dat")

# Extract frequency and phase values
w_values = data[:, 0]
A_values = data[:, 1]

# Plot the graph
plt.plot(w_values, A_values)
plt.axhline(0, color='black', linewidth=1.5)
plt.axvline(0, color='black', linewidth=1.5)

tick_positions = [i for i in range(0, 7)]  # Adjust the range as needed
tick_labels = ['$10^{}$'.format(i) for i in range(0, 7)]

plt.xticks(tick_positions, tick_labels)

plt.xlabel('frequency')
plt.ylabel('Phase of H')
plt.legend()
plt.grid(True)
plt.show()
plt.clf()

# Read data from the dat file
data = np.loadtxt("data6_3.dat")

# Extract frequency and phase values
s_values = data[:, 0]
l_values = data[:, 1]

# Plot the graph
plt.plot(s_values, l_values)
plt.axhline(0, color='black', linewidth=1.5)
plt.axvline(0, color='black', linewidth=1.5)
plt.xlabel('s')
plt.ylabel('Y(s)')
plt.legend()
plt.grid(True)
plt.show()
plt.clf()

# Read data from the dat file
data = np.loadtxt("data6_4.dat")

# Extract frequency and phase values
s_values = data[:, 0]
l_values = data[:, 1]

# Plot the graph
plt.plot(s_values, l_values)
plt.axhline(0, color='black', linewidth=1.5)
plt.axvline(0, color='black', linewidth=1.5)
plt.xlabel('s')
plt.ylabel('Y(s)')
plt.legend()
plt.grid(True)
plt.show()



