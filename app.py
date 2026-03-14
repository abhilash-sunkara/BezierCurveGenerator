import numpy as np
import bezier_math
import matplotlib.pyplot as plt

control_points = np.array([
    [0.0, 0.0],  
    [2.5, 5.0],  
    [5.0, -2.0], 
    [10.0, 0.0]  
])

np_arr = bezier_math.get_bezier_curve(control_points)

print(np_arr)

plt.plot(np_arr[:, 0], np_arr[:, 1], "b-")
plt.axis("equal")
plt.show()