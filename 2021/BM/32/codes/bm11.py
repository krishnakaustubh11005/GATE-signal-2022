import numpy as np
import matplotlib.pyplot as plt

# Given parameters
f_sample = 100e6  # 100 MHz
N = 1024          # Number of samples

# Generate time values
t = np.arange(0, N) / f_sample

# Generate a signal with multiple frequency components
signal = 2 * np.sin(2 * np.pi * 5e6 * t) + 1.5 * np.sin(2 * np.pi * 20e6 * t)

# Plot the time-domain signal
plt.plot(t * 1e6, signal)
plt.title('Time-Domain Signal')
plt.xlabel('Time (μs)')
plt.ylabel('Amplitude')
plt.show()

