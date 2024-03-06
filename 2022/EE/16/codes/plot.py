import numpy as np
import matplotlib.pyplot as plt

# Read data from the file
file_path = "Vout.txt"
data = np.genfromtxt(file_path, skip_header=1)  # Assuming the first line is a header

# Extract time and voltage data
time = data[:20, 0]
voltage = data[:20, 1]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(time, voltage, color='blue', linestyle='-')
plt.title('Voltage vs Time')
plt.xlabel('Time')
plt.ylabel('Voltage')
plt.grid(True)
plt.savefig("../figs/plot.png")
plt.show()

