
import re
import numpy as np
import matplotlib.pyplot as plt

with open("data.txt", "r") as file:
    data = file.read()

cases_of_interest = {
    ("-1.000000", "0.000000"),  # k_i = 0, k_p = -1
    ("9.000000", "0.000000"),   # k_i = 0, k_p = 9
    ("4.000000", "3.125000")    # k_i = 3.125, k_p = 4
}

marginal_cases = list(
    map(
        lambda match: (
            match.group(1),
            match.group(2),
            list(map(float, match.groups()[2:]))
        ),
        filter(
            lambda match: (match.group(1), match.group(2)) in cases_of_interest,
            re.finditer(
                r"For kp\s*=\s*([+-]?\d*\.\d+) and ki\s*=\s*([+-]?\d*\.\d+):\nRoot 1:\s*([+-]?\d*\.\d+)\s+([+-]?\d*\.\d+)\nRoot 2:\s*([+-]?\d*\.\d+)\s+([+-]?\d*\.\d+)\nRoot 3:\s*([+-]?\d*\.\d+)\s+([+-]?\d*\.\d+)\nRoot 4:\s*([+-]?\d*\.\d+)\s+([+-]?\d*\.\d+)", 
                data
            )
        )
    )
)

def plot_case(case, color):
    real_parts = np.array(case[2][::2])
    imag_parts = np.array(case[2][1::2])
    plt.scatter(real_parts, imag_parts, color=color)
    plt.xlabel('Real Part')
    plt.ylabel('Imaginary Part')
    plt.grid(True)
    plt.show()

plot_case(marginal_cases[0], 'red')
plot_case(marginal_cases[1], 'blue')
plot_case(marginal_cases[2], 'green')

