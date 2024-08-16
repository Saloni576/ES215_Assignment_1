import matplotlib.pyplot as plt

# Data for matrix sizes
sizes = [64, 128, 256, 512, 1024]

# Execution times in seconds for different cases
int_cpp_times = {
    'program': [0.002776578, 0.012428761, 0.095275735, 0.743238543, 7.323375098]
}

double_cpp_times = {
    'program': [0.002933383, 0.014053764, 0.095918318, 0.788467068, 11.331693040]
}

int_python_times = {
    'system': [0.010, 0.017, 0.098, 0.781, 6.176],
    'program': [0.061106682, 0.520728588, 4.110341311, 35.709860802, 360.108531713]
}

float_python_times = {
    'system': [0.010, 0.039, 0.263, 0.930, 5.975],
    'program': [0.062492609, 0.564885139, 4.191623688, 36.887437582, 341.926194191]
}

plt.figure(figsize=(12, 8))

# Plotting system execution times
plt.plot(sizes, int_python_times['system'], marker='^', linestyle='--', label='int Python (System Time)', color='coral')
plt.plot(sizes, float_python_times['system'], marker='d', linestyle='--', label='float Python (System Time)', color='lavender')

# Plotting program execution times
plt.plot(sizes, int_cpp_times['program'], marker='o', label='int C++ (Program Time)', color='blue')
plt.plot(sizes, double_cpp_times['program'], marker='s', label='double C++ (Program Time)', color='green')
plt.plot(sizes, int_python_times['program'], marker='^', label='int Python (Program Time)', color='coral')
plt.plot(sizes, float_python_times['program'], marker='d', label='float Python (Program Time)', color='purple')

# Adding titles and labels
plt.title('System vs. Program Execution Time of Matrix Multiplications')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Execution Time (Seconds)')
plt.xticks(sizes)  # Ensure all sizes are labeled on x-axis
plt.yscale('log')  # Log scale for better visibility of time differences
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend()
plt.show()
