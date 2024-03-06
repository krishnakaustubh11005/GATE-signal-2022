import numpy as np
import matplotlib.pyplot as plt

# Define the function
def y(t):
    return (3 - 2*t)*np.exp(-0.5*t) * (t >= 0)

# Read data from file
with open("linspace.txt", "r") as file:
    t_values = [float(line.strip()) for line in file]

# Calculate y values
y_values = y(np.array(t_values))

# Plot the function
plt.plot(t_values, y_values, label='y(t)')
plt.xlabel('t')
plt.ylabel('y(t)')
plt.grid(True)
plt.savefig('fig1.png')
