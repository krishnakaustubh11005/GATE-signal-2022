import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("values.dat", skiprows=1)  # Skip the header row

freq = data[:, 0]# Extract frequency data from values.dat
magnitude = data[:, 1]# Extract magnitude data from values.dat
phase = data[:, 2]# Extract phase data from values.dat

# Plot the magnitude response plot (printed in decibel previously)
plt.figure(figsize=(10, 6))
plt.semilogx(freq, magnitude)
plt.xlabel('Frequency [radians / second]')
plt.ylabel('Magnitude [dB]')
plt.grid()
plt.savefig("Figure_1.jpg")
#plt.show()

# Plot the phase response plot (printed in degrees previously)
plt.figure(figsize=(10, 6))
plt.semilogx(freq, phase)
plt.xlabel('Frequency [radians / second]')
plt.ylabel('Phase [degrees]')
plt.grid()
plt.savefig("Figure_2.jpg")
#plt.show()
