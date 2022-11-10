import matplotlib.pyplot as plt
import numpy as np

data=np.loadtxt("./func_check/turn.csv",delimiter=",")
print(data.shape)

plt.plot(data[:,0],label="min")
plt.plot(data[:,1],label="mid")
plt.plot(data[:,2],label="max")
plt.legend()
plt.show()

