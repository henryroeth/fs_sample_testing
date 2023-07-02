# Reads CSV file 
read_csv = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\2023-06-29&30.CSV")

#Where column name is stored
col_name=read_csv$Pm2.5.ug.m3.
col_name1=read_csv$Time
col_name2=read_csv$Wind.mph.
col_name3=read_csv$Wind.Direction...

#Find the mean the specified column
print(result <- mean(col_name))

#Find the standard deviation the specified column
print(result <- sd(col_name))

#Find the median the specified column
print(result <- median(col_name))

#Plots the data into a visual display by converting file data into a matrix
plot(x <- data.matrix(col_name2), y <- data.matrix(col_name), xlab = 'Wind(mph)', ylab = 'Pm2.5(ug/m3)', main = 'Wind & Pm2.5 Sinusoidal Regression Curves 2023-06-(10am)29to(10am)30')
df <- data.frame(x=data.matrix(col_name2),
                 y=data.matrix(col_name))
fit1 <- lm(y~x, data=df)
fit2 <- lm(y~poly(x,2,raw=TRUE), data=df)
fit3 <- lm(y~poly(x,3,raw=TRUE), data=df)
fit4 <- lm(y~poly(x,4,raw=TRUE), data=df)
fit5 <- lm(y~poly(x,5,raw=TRUE), data=df)

x_axis <- seq(0, 9, length=2000)

lines(x_axis, predict(fit1, data.frame(x=x_axis)), col='green')
lines(x_axis, predict(fit2, data.frame(x=x_axis)), col='red')
lines(x_axis, predict(fit3, data.frame(x=x_axis)), col='purple')
lines(x_axis, predict(fit4, data.frame(x=x_axis)), col='blue')
lines(x_axis, predict(fit5, data.frame(x=x_axis)), col='orange')