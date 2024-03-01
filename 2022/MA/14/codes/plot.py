import matplotlib.pyplot as plt

# Read coordinates from data.txt
with open("data.txt", "r") as file:
    data = file.readlines()

# Extract x and y coordinates
x_coords = [float(line.split()[0]) for line in data]
y_coords = [float(line.split()[1]) for line in data]

# Plot the graph
plt.plot(x_coords, y_coords, color='blue')

# Mark the coordinate (-1,0) in red and add legend
plt.plot(-1, 0, 'ro', label='Pole at z=-1')

# Add legend only for the pole at (-1,0)
plt.legend()

# Add labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title('')

# Show plot
plt.grid(True)
plt.axis('equal')
plt.show()

