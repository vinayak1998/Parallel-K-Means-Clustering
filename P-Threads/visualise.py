from csv import reader
from sys import argv
import numpy as np;
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

infile=reader(open(argv[1]),delimiter=" ");
data=np.array([[int(a) for a in b] for b in infile])

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1, facecolor="red")
ax = fig.gca(projection='3d')
ax.scatter(data[:,0],data[:,1],data[:,2],c=data[:,3])
plt.show()

