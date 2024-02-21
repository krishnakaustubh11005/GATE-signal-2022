import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import find_peaks

# Load data from files
data_theoretical = np.loadtxt('data_theoretical.txt')
data_practical = np.loadtxt('data_practical.txt')

# Plot theoretical and practical results
plt.plot(data_theoretical[:, 0], data_theoretical[:, 1], label='Theoretical Displacement Current', color='blue')
plt.plot(data_practical[:, 0], data_practical[:, 1], label='Practical Displacement Current', color='red')
plt.xlabel('Time')
plt.ylabel('Displacement Current')
plt.title('Theoretical vs Practical Displacement Current')
plt.legend()
plt.grid(True)
plt.show()

