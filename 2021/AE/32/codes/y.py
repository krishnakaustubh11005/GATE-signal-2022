import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("data.txt", skiprows=0)
time, pyx_1C, pyx_2C = data[:, 0], data[:, 3], data[:, 4]


plt.plot(time, pyx_1C, label='x_1(t)',color = 'blue')
plt.plot(time, pyx_2C, label='x_2(t)', color='red')

# Set labels and legend
plt.xlabel('t')
plt.legend()
plt.grid(True)
plt.show()

