import numpy as np
import matplotlib.pyplot as plt

def sin(t):
    return a * np.sin(2 * np.pi * f1 * t)
a = 4
f1 = 4000

d = 0.00025
t = np.linspace(0 , d , int(1e5))

plt.figure()
plt.plot(t,sin(t))
plt.xlabel('Time')
plt.ylabel('Voltage')
plt.title('Sinusoid')
plt.grid(True)
plt.show()
