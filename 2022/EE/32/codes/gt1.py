import numpy as np
import matplotlib.pyplot as plt

# Read coordinates from coordinate.txt
with open('coordinate.txt', 'r') as file:
    data = file.readline().split()
    V_rms, f, P = map(float, data)

# Plotting the output voltage waveform
V_m = np.sqrt(2) * V_rms
omega = 2 * np.pi * f
t = np.linspace(0, 3 * np.pi / omega, 1000)
Vo = V_m * np.abs(np.sin(omega * t))

plt.plot(omega * t, Vo)
plt.xlabel('$\omega t$')
plt.ylabel('$V_o$ (Volts)')

# Set x-axis ticks in terms of pi
plt.xticks([0, np.pi, 2*np.pi, 3*np.pi], ['$0$', '$\pi$', '$2\pi$', '$3\pi$'])

plt.grid(True)

# Save figure as a PNG image
plt.savefig('coordinate.png')

# Show the figure
plt.show()

