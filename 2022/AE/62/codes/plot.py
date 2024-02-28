import numpy as np
import matplotlib.pyplot as plt
import math
m=5
g=9.8
c=20.43
k=5000
x = np.linspace(0, 2.3*np.pi, 1000000)
A_0=math.sqrt(((m*g)/k)**2+((g*c)/(2*m*k))**2)
f1_x=np.exp(-(c*x)/(2*m))
f2_x=np.sin(math.sqrt(k/m-(c/(2*m))**2)*x+np.arctan((2*m*g*math.sqrt(k/m-(c/(2*m))**2))/(g*c)))
y = A_0*f1_x*f2_x+(m*g)/k

plt.plot(x, y, label='Displacement')
plt.grid(True)

plt.xlabel('t')
plt.ylabel('x(t)')
plt.legend()

plt.show()
