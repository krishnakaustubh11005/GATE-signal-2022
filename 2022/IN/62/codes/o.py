# Define the function V(t)
def v_t(t):
    if t < np.pi / 10000:
        return 10 * np.cos(10**4 * t)
    else:
        return -10

# Generate values for t
t_values = np.linspace(0, np.pi / 5000, 1000)  # Adjust the number of points as needed

# Calculate corresponding values for V(t)
v_values = np.vectorize(v_t)(t_values)

# Plot the graph
plt.plot(t_values, v_values, label='V(t)')
plt.xlabel('t')
plt.ylabel('V(t)')
plt.title('V(t) vs t')
plt.axvline(np.pi / 10000, color='r', linestyle='--', label='t = π/10000')  # Vertical line at t=π/10000
# Set x-labels as 1/10000, 2/10000, 3/10000, 4/10000, 5/10000, 6/10000
xticks = np.array([1, 2, 3, 4, 5, 6]) / 10000
xticklabels = [f'{i:.6f}' for i in xticks]
plt.xticks(xticks, xticklabels)

plt.legend()
plt.grid(True)
plt.show()
import numpy as np
import matplotlib.pyplot as plt

# Define the function V(t)
def v_t(t):
    if t < np.pi / 10000:
        return 10 * np.cos(10**4 * t)
    else:
        return -10
        # Generate values for t
t_values = np.linspace(0, np.pi / 5000, 1000)  # Adjust the number of points as needed

# Calculate corresponding values for V(t)
v_values = np.vectorize(v_t)(t_values)

# Plot the graph
plt.plot(t_values, v_values, label='V(t)')
plt.xlabel('t')
plt.ylabel('V(t)')
plt.title('V(t) vs t')


