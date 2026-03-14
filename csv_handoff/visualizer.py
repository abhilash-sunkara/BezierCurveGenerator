import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('data.csv', names=['x', 'y'])
plt.plot(data['x'], data['y'], 'b-')
plt.show()