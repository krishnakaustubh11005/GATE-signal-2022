import numpy as np
import matplotlib.pyplot as plt

# Load data from text files
data1 = np.loadtxt('data1.txt')
data2 = np.loadtxt('data2.txt')

# Separate time and voltage values for carrier and message signals
t1, carrier_signal = data1[:, 0], data1[:, 1]
t2, message_signal = data2[:, 0], data2[:, 1]

# Plotting
plt.plot(t1, carrier_signal, label='Carrier Signal (c(t))', color='blue')
plt.plot(t2, message_signal, label='Message Signal (m(t))', color='red')
plt.title('')
plt.xlabel('Time (s)')
plt.ylabel('Voltage (V)')
plt.legend()
plt.grid(True)
plt.show()

