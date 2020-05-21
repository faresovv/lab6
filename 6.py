import numpy as np
import numpy
import matplotlib.pyplot as plt
data = np.loadtxt("ans.dat")
plt.plot(data[:, 0], data[:, 1])
def makeData():
    x = numpy.arange(-20, 20, 0.1)
    y = numpy.arange(-20, 20, 0.1)
    xgrid, ygrid = numpy.meshgrid(x, y)
    zgrid = (xgrid*xgrid-22*xgrid+2*ygrid*ygrid+28*ygrid+222)
    return xgrid, ygrid, zgrid
x, y, z = makeData()
plt.contour(x, y, z, 50)
plt.show()

