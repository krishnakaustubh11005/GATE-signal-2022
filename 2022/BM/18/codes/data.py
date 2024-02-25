import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("data.txt", skiprows=0)
t_values, x_1_t, x_2_t = data[:, 0], data[:, 1], data[:, 2]

plt.plot(t_values, x_1_t, 'r-', label='signal1')
plt.plot(t_values, x_2_t, 'b-', label='signal2')
plt.plot(0.790000,2.998857, marker ='o', markersize=5,markeredgecolor="yellow", markerfacecolor="green",label='peak_2')
plt.plot(0.870000,1.999744, marker ='o', markersize=5,markeredgecolor="yellow", markerfacecolor="violet",label='peak_1')
plt.xlabel('t')
plt.legend()
plt.grid(True)
plt.show()
