import matplotlib.pyplot as plt
import matplotlib.ticker as mtick
from sys import argv as args

handle = open(args[1], "r")
dev_y = []
for date in handle:
    dev_y.append(int(date.split(".")[0]))

maxd = max(dev_y)
for i in range(len(dev_y)):
    dev_y[i] = dev_y[i] / maxd * 100

plt.plot([i for i in range(len(dev_y))], dev_y)

pos = len(dev_y) / 5
for i in range(6):
    plt.axvline(x = (pos * i - 1 * (i / 5)), color='r')

plt.ylabel("Success rate")
plt.xlabel("Epoch")
plt.gca().yaxis.set_major_formatter(mtick.PercentFormatter())

plt.show()
