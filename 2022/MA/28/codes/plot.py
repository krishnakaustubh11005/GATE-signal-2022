import numpy as np
import matplotlib.pyplot as plt

# Define the complex numbers
theta = np.linspace(0, 2*np.pi, 100)
radius_of_convergence = np.sqrt(1/3)
circle_real = radius_of_convergence * np.cos(theta)
circle_imag = radius_of_convergence * np.sin(theta)

# Plot the circle representing the region of convergence
plt.figure(figsize=(8, 8))
plt.title("Region of Convergence")
plt.plot(circle_real, circle_imag, label=f'Radius of Convergence: {radius_of_convergence:.3f}', color='blue')
plt.fill(circle_real, circle_imag, color='blue', alpha=0.3)  # Fill the region inside the circle
plt.scatter([0], [0], color='red', marker='x', label='Center (0, 0)')
plt.xlabel('Re(z)')
plt.ylabel('Im(z)')
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.grid(color='gray', linestyle='--', linewidth=0.5)
plt.legend()
plt.axis('equal')
plt.show()

