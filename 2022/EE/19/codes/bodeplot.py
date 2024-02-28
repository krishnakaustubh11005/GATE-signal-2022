import numpy as np
import matplotlib.pyplot as plt

# Define the transfer function
def G(w, k):
    return k / np.sqrt(w**4 + 8*w**2 + 25)

# Generate frequency range
w = np.logspace(-2, 2, 1000)

# Plot the Bode plot for different values of k
k_values = [3,4,5,6, 7]
for k in k_values:
    plt.semilogx(w, 20*np.log10(G(w, k)), label=f'$k={k}$')

plt.xlabel('Frequency (rad/s)')
plt.ylabel('Magnitude (dB)')
plt.title('Bode Plot of Transfer Function')
plt.grid(True)
plt.legend()
plt.show()

