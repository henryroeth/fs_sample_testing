#install.packages("dplyr")
library(dplyr)
# Reads a specified CSV file
read_csv = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\2023-07-02'03.CSV")
read_csv1 = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\2023-07-01'02.CSV")
read_csv2 = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\2023-07-02'03.CSV")

#variable names Where column data is stored
pm2.5 = read_csv$Pm2.5.ug.m3.
time = data.frame(read_csv$Time)
wind = read_csv$Wind.mph.
wind_direction = read_csv$Wind.Direction...

#graph labels
title = 'Wind & Pm2.5 Sinusoidal Regression Curves 2023-06-(10am)29to(10am)30'
xlabel = 'Wind(mph)'
ylabel = 'Pm2.5(ug/m3)'

#find the mean of the specified column
print(result <- mean(col_name))

#find the standard deviation the specified column
print(result <- sd(col_name))

#find the median the specified column
print(result <- median(col_name))

#data set
df <- data.frame(x=data.matrix(wind), y=data.matrix(pm2.5))

#plots the data into a visual display by converting file data into a matrix
plot(df, xlab = xlabel, ylab = ylabel, main = title)

#regression lines
fit1 <- lm(y~x, data=df)
fit2 <- lm(y~poly(x,2,raw=TRUE), data=df)
fit3 <- lm(y~poly(x,3,raw=TRUE), data=df)
fit4 <- lm(y~poly(x,4,raw=TRUE), data=df)
fit5 <- lm(y~poly(x,5,raw=TRUE), data=df)

#prints regression equations
print(fit1)
print(fit2)
print(fit3)
print(fit4)
print(fit5)

#plots regression lines
x_axis <- seq(0, 9, length=2000)
lines(x_axis, predict(fit1, data.frame(x=x_axis)), col='green')
lines(x_axis, predict(fit2, data.frame(x=x_axis)), col='red')
lines(x_axis, predict(fit3, data.frame(x=x_axis)), col='purple')
lines(x_axis, predict(fit4, data.frame(x=x_axis)), col='blue')
lines(x_axis, predict(fit5, data.frame(x=x_axis)), col='orange')



