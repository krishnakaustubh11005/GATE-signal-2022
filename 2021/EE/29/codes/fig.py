import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('data.dat')
time = data[:, 0]
function_values = data[:, 1]

plt.figure(figsize=(8, 6))
plt.plot(time, function_values, label='Function f(t)')
plt.xlabel('Time (t)')
plt.ylabel('Function Value')
plt.title('Plot of Function f(t)')
plt.grid(1)
plt.legend()
plt.savefig('fig_3.jpg')

