import numpy as np
import os
import time

path = "/home/chispham258/code/IT003/SortRanking/data"
data = []

for i in range(10):
    a = np.array([])
    file = "data" + str(i) + ".txt"
    file_path = os.path.join(path, file)
    
    with open(file_path, "r") as file:
        arr = np.array([float(line.strip()) for line in file])            
        start = time.time()
        arr = np.sort(arr)
        end = time.time()
        elapsed_time = (end - start) * 1000
        data.append(int(elapsed_time))

# # print(data)
path = "/home/chispham258/code/IT003/SortRanking/result.txt"
with open(path, "a") as file:
    file.write("pysort ")
    for x in data:
        file.write(f"{x} ")