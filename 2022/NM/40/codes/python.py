import matplotlib.pyplot as plt
import numpy as np

# Load data from the "output.dat" file using numpy's loadtxt
data = np.loadtxt("output.dat")

# Extract n_values and y_values from the data
x = data[:, 0]
y = data[:, 1]

plt.figure(figsize=(10, 5))

# Create a stem plot
plt.plot(x, y)

plt.yticks([6.4], ['6.4'])
plt.xticks([0,0.25,0.50,1.0], ['0','0.25','0.50','1.0'])

plt.plot([0.25, 0], [6.4, 6.4], 'r--')
plt.plot([0.25, 0.25], [6.4, 0], 'r--')
plt.plot([0.50, 0.50], [6.4, 0], 'r--')

plt.annotate('', xy=(max(x), 0), xytext=(0, 0), arrowprops=dict(arrowstyle='->'))
plt.annotate('', xy=(0, max(y)), xytext=(0, 0), arrowprops=dict(arrowstyle='->'))

plt.xlabel('$\omega (rad/s)$')
plt.ylabel('$S_{\eta \eta(\omega)(m^2s/rad)}$')

plt.savefig('../figs/qfig.png')
