import numpy as np
import matplotlib.pyplot as plt

# Load data from file
data = np.loadtxt('data3.txt')

# Extract time, modulating signal, carrier signal, and amplitude modulated signal
t = data[:, 0]
m_t = data[:, 1]
c_t = data[:, 2]
s_t = data[:, 3]

# Plot modulating signal
plt.subplot(3, 1, 1)
plt.plot(t, m_t, 'b')
plt.title('Modulating Signal')
plt.xlabel('Time')
plt.ylabel('Amplitude')

# Plot carrier signal
plt.subplot(3, 1, 2)
plt.plot(t, c_t, 'r')
plt.title('Carrier Signal')
plt.xlabel('Time')
plt.ylabel('Amplitude')

# Plot amplitude modulated signal
plt.subplot(3, 1, 3)
plt.plot(t, s_t, 'g')
plt.title('Amplitude Modulated Signal')
plt.xlabel('Time')
plt.ylabel('Amplitude')

plt.tight_layout()
plt.show()

