import numpy as np
import matplotlib.pyplot as plt
c = np.loadtxt("data.dat", delimiter='\t')


plt.plot(c[:, 0], c[:, 1], label = r'Transfer Function')
plt.plot([316227.76], [1], 'ro', label=r'maxima')
plt.title("Plot of function |H(j, ω)|")
plt.grid(1)
plt.legend()
plt.xlabel('ω')
plt.ylabel('|H(j, ω)|')
plt.savefig('fig_1.jpg')





