
import matplotlib.pyplot as plt

# settings

# importing module
from pandas import *
 
# reading CSV file
data = read_csv('data_avg_sheet.csv')

# converting column data to list
time = data['Time'].tolist()
pm_readings = data['Pm 2.5'].tolist()
wind_readings = data['Wind'].tolist()
string='Wind Direction(Â°)'
# string.encode(encoding = 'UTF-8', errors = 'strict')
# wind_directions = data[string].tolist()
print(time)
print(pm_readings)
print(wind_readings)
# print(wind_directions)

plt.yscale('symlog')

x1 = time #[1:len(time):1]
y1 = pm_readings #[1:len(pm_readings):1]



# plotting the line 1 points 
plt.plot(x1, y1, color = 'cyan', label = "PM2.5(ug/m3)")
plt.grid()
# line 2 points
x2 = time #[1:len(time):1]
y2 = wind_readings #[1:len(wind_readings):1]
# plotting the line 2 points 
plt.plot(x2, y2, color = 'violet', label = "Wind Speed(mph)")

#x3 = time[1:len(time):60]
#y3 = wind_directions[1:len(wind_directions):60]
# # plotting the line 2 points 
# plt.plot(x2, y2, label = "Wind Direction")
  
# naming the x axis
plt.xlabel('Time(days)')
# naming the y axis
plt.ylabel('Pm2.5(ug/m3)/Wind(mph)')
# giving a title to my graph
plt.title('Pm2.5/Wind Correlations In July')
ax = plt.gca()
ax.set_xticklabels(ax.get_xticks(), rotation = 45)
ax.set_yticklabels(ax.get_yticks(), rotation = 0)
# show a legend on the plot

plt.legend()
  
# function to show the plot
plt.show()