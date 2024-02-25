import numpy as np
import matplotlib.pyplot as plt

# Load data from file
data = np.loadtxt('freq.dat')
omega_values = data[:, 0]
magnitude_values = data[:, 1]
phase_values = data[:, 2]

# Plot magnitude response
plt.figure(figsize=(8, 6))
plt.plot(omega_values, magnitude_values, 'b')
plt.xlabel('\u03C9')  # Omega symbol
plt.ylabel('|H(j\u03C9)|')
plt.xticks(np.arange(min(omega_values), max(omega_values)+1, 1))  # Set x-axis ticks as integers
plt.grid(True)
plt.savefig('freq.png')
plt.show()

# Plot phase response
plt.figure(figsize=(8, 6))
plt.plot(omega_values, phase_values, 'r')
plt.xlabel('\u03C9')  # Omega symbol
plt.ylabel('Phase (degrees)')
plt.xticks(np.arange(min(omega_values), max(omega_values)+1, 1))  # Set x-axis ticks as integers
plt.grid(True)
plt.savefig('phase.png')
plt.show()

