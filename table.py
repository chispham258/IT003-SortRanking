import pandas as pd
import numpy as np

sort = {
    0 : "QuickSort",
    1 : "HeapSort" ,
    2 : "MergeSort",
    3 : "Sort(C++)",
    4 : "Sort(NumPy)"
}

data = {
    "QuickSort"   : [],
    "HeapSort"    : [],
    "MergeSort"   : [],
    "Sort(C++)"   : [],
    "Sort(NumPy)" : []
}

mean_arr = []

path = "/home/chispham258/code/IT003/SortRanking/result.txt"
with open(path, "r") as file:
    index_sort = 0
    for line in file:
        content = line.strip()
        content = content.split(" ")

        for i in range(1, 11):
            data[sort[index_sort]].append(int(content[i]))
        data[sort[index_sort]].append(int(np.mean(data[sort[index_sort]])))
        index_sort += 1


df = pd.DataFrame(data)
df = df.rename(index = {10 : "Mean"})
df.to_csv("table.csv", index=True)
print(df)
