import numpy as np
import matplotlib.pyplot as plt

# Load data
data = np.loadtxt('1.dat')

# Extract time and x(t) values
x = data[:, 0]
y = data[:, 1]

# Plot
plt.plot(x, y)
plt.plot(1000, 3, 'ro')
plt.xlabel('$\omega$')
plt.ylabel('$20log(|H(j\omega)|)$')
#plt.axhline(y=3, xmin=0, xmax=1000/x[-1], color='red', linestyle='--')
plt.axhline(y=3, xmin=0, xmax=(1000 - x[0]) / (x[-1] - x[0]), color='red', linestyle='--')
plt.plot([1000,1000], [plt.ylim()[0], 3], 'r--')
plt.text(1000, 4, '(1000, 3)', color='red', ha='right')
plt.grid(True)
plt.savefig('../figs/plot1.png')
plt.show()

