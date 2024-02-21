import numpy as np
import matplotlib.pyplot as plt

# Define time values
t = np.linspace(0, 10, 1000)  # Time values from 0 to 10

# Calculate displacement current
i_d = np.sin(t + np.pi/2)

# Plot the displacement current
plt.figure(figsize=(10, 6))
plt.plot(t, i_d, label='Displacement Current (i_d)')
plt.title('Displacement Current vs Time')
plt.xlabel('Time')
plt.ylabel('Displacement Current')
plt.grid(True)
plt.legend()
plt.show()

