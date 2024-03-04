import numpy as np
import matplotlib.pyplot as plt

# Load data from values.dat
data = np.loadtxt('values.dat')
f = data[:, 0]
X = data[:, 1]
X_2f = data[:, 2]
convolution = data[:, 3]

# Create subplots for X(f) and X(2f) horizontally
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))  # Adjust width

# Plot X(f)
ax1.plot(f, X, color='blue')
ax1.set_xlabel('$f (kHz)$')
ax1.set_ylabel('$X(f)$')
ax1.grid(True)
ax1.set_xticks([-10, 0, 10])
ax1.set_xlim(-20, 20)
ax1.set_yticklabels([])  # Remove y-axis labels

# Plot X(2f)
ax2.plot(f, X_2f, color='red')
ax2.set_xlabel('$f (kHz)$')
ax2.set_ylabel('$X(2f)$')
ax2.grid(True)
ax2.set_xticks([-5, 0, 5])
ax2.set_xlim(-10, 10)
ax2.set_yticklabels([])  # Remove y-axis labels

# Add convolution symbol between X(f) and X(2f)
ax1.annotate('*', xy=(1.2, 0.5), xycoords='axes fraction', fontsize=50, ha='center', va='center')

# Adjust layout and save plot1.png
plt.subplots_adjust(wspace=0.5)  # Increase the horizontal space between subplots
plt.savefig('plot1.png')
plt.show()

# Plot convolution (Y(f))
plt.figure(figsize=(8, 6))
plt.plot(f, convolution, color='green')
plt.xlabel('$f (kHz)$')
plt.ylabel('$Y(f)$')
plt.grid(True)
plt.xticks([-15, 0, 15])  # Adjust x-axis ticks
plt.xlim(-20, 20)  # Adjust x-axis limits
plt.gca().set_yticklabels([])  # Remove y-axis labels
plt.savefig('plot2.png')
plt.show()

