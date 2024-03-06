import numpy as np
import matplotlib.pyplot as plt

def sin(t):
    return a * np.sin(2 * np.pi * f1 * t)
a = 4
f1 = 4000
f2 = 32000
dt = np.pi

d = 0.00025
t = np.linspace(0 , d , int(1e5))

l1 = [0]
l2 = [0]
j=1/32000
for i in np.arange(8):
    if l1[i] <= sin(j):
        l1.append(l1[i] + dt)
    else:
        l1.append(l1[i] - dt)
    l2.append(j)
    j+=1/32000

plt.figure()
plt.stem(l2,l1)
plt.xlabel('Time')
plt.ylabel('Voltage')
plt.title('Samples')
plt.grid(True)
plt.show()
