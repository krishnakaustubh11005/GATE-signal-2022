import numpy as np
import matplotlib.pyplot as plt

# Reading values from file
with open("values.dat", 'r') as file:
    lines = file.readlines()

# Extracting y[n] and z[n] values as float type from values.dat line by line by splitting the line.
y_n_values = np.array(lines[0].split()).astype(float)
z_n_values = np.array(lines[1].split()[:16]).astype(float)

# Plotting y[n] and z[n]
plt.figure(figsize=(10, 6))
plt.stem(range(len(y_n_values)), y_n_values, linefmt='C0-', markerfmt='C0o', basefmt='C0-', label='y[n]') # plot wrt to the index of the y[n] and z[n]
plt.stem(range(len(z_n_values)), z_n_values, linefmt='C1-', markerfmt='C1o', basefmt='C1-', label='z[n]') # similar for z
plt.xlabel('n')
plt.ylabel('Value')
plt.legend()

# Highlighting that y[n] and z[n] are equal for n = 15 (values is 136 at that point)
plt.scatter(15, y_n_values[15], color='blue', marker='x', s=100, label=f'y[15] = {y_n_values[15]:.2f}')
plt.scatter(15, z_n_values[15], color='red', marker='^', s=100, label=f'z[15] = {z_n_values[15]:.2f}')

plt.grid(True)
plt.legend()
#plt.show()
plt.savefig("Figure_1")
