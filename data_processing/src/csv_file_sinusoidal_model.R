# dependencies

# reads a specified CSV file
read_csv = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\beta_records\\2023-06-29&30.CSV")
read_csv1 = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\2023-07-01'02.CSV")
read_csv2 = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\2023-07-02'03.CSV")

# variable names where column data is stored
file = read_csv

pm2.5 = file$Pm2.5.ug.m3.
time = data.frame(file$Time)
wind = file$Wind.mph.
wind_direction = file$Wind.Direction...

# graph labels

title = 'Standardized Residuals Under Two Deviations'
xlabel = 'Index'
ylabel = 'Standardized Residual Value'

#prints a statistical rundown of the data to the console

mean <- result <- mean(pm2.5) # mean

sd <- result <- sd(pm2.5) #standard deviation

median <- result <- median(pm2.5) #median

# stores csv file data into a frame

df <- data.frame(x=data.matrix(wind), y=data.matrix(pm2.5))

# plots the data into a visual display by converting file data into a matrix

plot(df, xlab = xlabel, ylab = ylabel, main = title)

# regression lines
fit1 <- lm(y~x, data=df)
fit2 <- lm(y~poly(x,2,raw=TRUE), data=df)
fit3 <- lm(y~poly(x,3,raw=TRUE), data=df)
fit4 <- lm(y~poly(x,4,raw=TRUE), data=df)
fit5 <- lm(y~poly(x,5,raw=TRUE), data=df)

# prints regression equations
print(fit1)
print(fit2)
print(fit3)
print(fit4)
print(fit5)

# plots regression lines
x_axis <- seq(0, 9, length=2000)
lines(x_axis, predict(fit1, data.frame(x=x_axis)), col='green')
lines(x_axis, predict(fit2, data.frame(x=x_axis)), col='red')
lines(x_axis, predict(fit3, data.frame(x=x_axis)), col='purple')
lines(x_axis, predict(fit4, data.frame(x=x_axis)), col='blue')
lines(x_axis, predict(fit5, data.frame(x=x_axis)), col='orange')

standard_res <- data.matrix(rstandard(fit4))
no_res_outliers <- subset(standard_res, abs(standard_res) < 2)

data_usage <- (length(standard_res))/(length(no_res_outliers))
data_usage

plot(no_res_outliers, xlab = xlabel, ylab = ylabel, main = paste(title, "(", (trunc(data_usage*100)),"% Outlier Exclusion)"))
abline(h=0, col = 'blue')