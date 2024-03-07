import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("data.txt", skiprows=0)
time, pyx_1B, pyx_2B = data[:, 0], data[:, 1], data[:, 2]


plt.plot(time, pyx_1B, label='x_1(t)',color = 'blue')
plt.plot(time, pyx_2B, label='x_2(t)', color='red')

# Set labels and legend
plt.xlabel('t')
plt.legend()
plt.grid(True)
plt.show()

