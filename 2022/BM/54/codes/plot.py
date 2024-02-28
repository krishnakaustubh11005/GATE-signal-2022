import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("data.txt")

inductance = data[:, 0]
current = data[:, 1]

highlight_index = np.argmax(current)
highlight_inductance = inductance[highlight_index]
highlight_current = current[highlight_index]

plt.plot(inductance, current, label="Current vs Inductor")
plt.scatter(highlight_inductance, highlight_current, color='red', label=f"L: {highlight_inductance:.2f}, Iₘₐₓ: {highlight_current:.6f}")
plt.xlabel("Inductor (H)")
plt.ylabel("Current (A)")
plt.legend()
plt.grid(True)
plt.show()

