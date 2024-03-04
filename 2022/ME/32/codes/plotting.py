import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("gen_values.txt")

x_values = data[:,0]
y_1_values = data[:,1]
y_2_values = data[:,2]
y_3_values = data[:,3]

plt.plot(x_values, y_1_values, label = "theta(s) = R = 1", color = "blue") 
plt.plot(x_values, y_2_values, label = "theta'(s) = R = 2", color = "red")
plt.plot(x_values, y_3_values, label = "theta'(S) = R = 3", color = "green")

plt.xlabel("t")
plt.ylabel("theta(t)")

plt.savefig("theta_t_plot")

