import numpy as np
import matplotlib.pyplot as plt

data_original = np.loadtxt('data1.txt', skiprows=1)
data_euler = np.loadtxt('data2.txt', skiprows=1)

t_original, y_original = data_original[:, 0], data_original[:, 1]
x_euler, y_euler = data_euler[:, 0], data_euler[:, 1]

plt.plot(t_original, y_original, color='blue', label='y(x)')
plt.stem(x_euler, y_euler, linefmt='r-', markerfmt='ro', basefmt=' ', label='_nolegend_')  

highlighted_index = np.where(x_euler == 1.4)[0][0]

plt.stem(x_euler[highlighted_index], y_euler[highlighted_index], linefmt='g-', markerfmt='go', basefmt=' ', label='_nolegend_')  
plt.scatter(1.4, y_euler[highlighted_index], color='green', marker='o', label='g(1.4) = {:.4f}'.format(y_euler[highlighted_index]))

plt.scatter(1.4, -5 * np.exp(-1.4 + 1) + 4 + 4 * 1.4, color='blue', marker='o', label='f(1.4) = {:.4f}'.format(-5 * np.exp(-1.4 + 1) + 4 + 4 * 1.4))

plt.scatter([], [], color='red', label='g(x)', marker='o')

plt.legend()

plt.xlabel('x')
plt.ylabel('y')

plt.grid(True)

plt.show()

