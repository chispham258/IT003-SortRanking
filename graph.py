import table as file
import numpy as np
import matplotlib.pyplot as plt

X = np.linspace(0, 140, 10)
sort_algorithms = ["QuickSort", "HeapSort", "MergeSort","Sort(C++)", "Sort(NumPy)"]

bar_width = 3

fig, ax = plt.subplots(figsize = (8, 6))
for i, sort_algorithm in enumerate(sort_algorithms):
    ax.bar(X + i * bar_width, file.data[sort_algorithm][0:10], width=bar_width, label=sort_algorithm)

for i in range(len(X)):
    for j, sort_algorithm in enumerate(sort_algorithms):
        ax.text(X[i] + j * bar_width, file.data[sort_algorithm][i], str(file.data[sort_algorithm][i]), ha='center', fontsize=15)

datasets = np.arange(len(X))

ax.set_xlabel("Dataset",fontsize=30)
ax.set_ylabel("Execution Time (ms)", fontsize=30)

ax.set_title("Kết quả thử nghiệm trên bộ dữ liệu", fontsize=30)

ax.set_xticks(X + bar_width * 2)
ax.set_xticklabels(datasets)
ax.grid()

ax.legend(fontsize=30)

plt.show()

