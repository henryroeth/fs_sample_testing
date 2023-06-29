
import matplotlib.pyplot as plt

# settings

# importing module
from pandas import *
 
# reading CSV file
data = read_csv("2023-06-27&28.csv")
 
# converting column data to list
time = data['Time'].tolist()
pm_readings = data['Pm2.5(ug/m3)'].tolist()
wind_readings = data['Wind(mph)'].tolist()
print(time)
print(pm_readings)
x1 = time
y1 = pm_readings

# plotting the line 1 points 
plt.plot(x1, y1, label = "PM.5(ug/m3)")
  
# line 2 points
x2 = time
y2 = wind_readings
# plotting the line 2 points 
plt.plot(x2, y2, label = "Wind Speed")
  
# naming the x axis
plt.xlabel('Time')
# naming the y axis
plt.ylabel('Pm2.5(ug/mm3)')
# giving a title to my graph
plt.title('Pm2.5 Readings Over Time')
ax = plt.gca()
ax.set_xticklabels(ax.get_xticks(), rotation = 90)
ax.set_yticklabels(ax.get_yticks(), rotation = 90)
# show a legend on the plot
plt.legend()
  
# function to show the plot
plt.show()

