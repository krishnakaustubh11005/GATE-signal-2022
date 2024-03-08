import matplotlib.pyplot as plt

# Read the output signal from the text file
with open("output.txt", "r") as file:
    output_signal = [int(line.strip()) for line in file]

# Plot the graph
plt.stem(output_signal)
plt.xlabel('n')
plt.ylabel('y[n]')
plt.grid(True)
plt.show()

