import numpy as np
import matplotlib.pyplot as plt

# Define time vector from 0 to 4*pi with 1000 points (2 periods)
t = np.linspace(0, 4*np.pi, 1000)

# Generate the signal
signal = (1/np.sqrt(2)) * np.sin(t - np.pi/4)

# Plot the signal
plt.plot(t, signal)
plt.show()
