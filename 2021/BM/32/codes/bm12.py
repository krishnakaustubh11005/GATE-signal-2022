import numpy as np
import matplotlib.pyplot as plt

# Given parameters
f_sample = 100e6  # 100 MHz
N = 1024          # Number of samples

# Generate time values
t = np.arange(0, N) / f_sample

# Generate a signal with multiple frequency components
signal = 2 * np.sin(2 * np.pi * 5e6 * t) + 1.5 * np.sin(2 * np.pi * 20e6 * t)

# Compute the FFT
fft_result = np.fft.fft(signal)

# Generate frequency points
frequencies = np.fft.fftfreq(N, d=1/f_sample) / 1e3  # Convert to kHz for better readability

# Plot the frequency spectrum
plt.plot(frequencies, np.abs(fft_result))
plt.title('Frequency Spectrum')
plt.xlabel('Frequency (kHz)')
plt.ylabel('Amplitude')
plt.show()

