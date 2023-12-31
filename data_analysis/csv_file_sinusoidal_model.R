# libraries

# reads a specified CSV file
read_csv = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\2023-07-17'18.CSV", header = TRUE, stringsAsFactors = FALSE)
read_csv1 = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\2023-07-14'15.CSV", header = TRUE, stringsAsFactors = FALSE)
read_csv2 = read.csv("C:\\Users\\henry\\fs_sample_testing\\data_records\\averages\\data_avg_sheet.CSV", header = TRUE, stringsAsFactors = FALSE)

# variable names where column data is stored
file = read_csv
file1 = read_csv1
file2 = read_csv2

file_pm2.5 = file$Pm2.5.ug.m3.
file1_pm2.5 = file1$Pm2.5.ug.m3.
file_time = file$Time
file1_time = file1$Time
file_wind = file$Wind.mph.
file1_wind = file1$Wind.mph.
file_wind_direction = file$Wind.Direction...
file1_wind_direction = file1$Wind.Direction...
file_rain = file$Daily.Rain.in.
file1_rain = file1$Daily.Rain.in.
file2_wind = file2$Wind
file2_pm2.5 = file2$Pm.2.5

# graph labels

title = 'Standardized Residuals Under Two Deviations'
xlabel = 'Index'
ylabel = 'Standardized Residual Value'

#prints a statistical rundown of the data to the console

mean <- result <- mean(file_wind_direction) # mean
mean
sd <- result <- sd(file_pm2.5) #standard deviation
sd
median <- result <- median(file_pm2.5) #median
median
# stores csv file data into a frame

df <- data.frame(x = file_wind , y = file_pm2.5)
df1 <- data.frame(x = file1_wind, y = file1_pm2.5)

# creates a plot using 'df' where file data was stored

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

# plots a new data set with same model to test for model accuracy

plot(df1, xlab = xlabel, ylab = ylabel, main = title)
x_axis <- seq(0, 9, length=2000)
lines(x_axis, predict(fit1, data.frame(x=x_axis)), col='green')
lines(x_axis, predict(fit2, data.frame(x=x_axis)), col='red')
lines(x_axis, predict(fit3, data.frame(x=x_axis)), col='purple')
lines(x_axis, predict(fit4, data.frame(x=x_axis)), col='blue')
lines(x_axis, predict(fit5, data.frame(x=x_axis)), col='orange')

standard_res <- data.matrix(rstandard(fit4))
no_res_outliers <- subset(standard_res, abs(standard_res) < 2)

data_usage <- (length(no_res_outliers))/(length(standard_res))
data_usage

plot(no_res_outliers, xlab = xlabel, ylab = ylabel, main = paste(title, "(", (100-trunc(data_usage*100)),"% Outlier Exclusion)"))
abline(h=0, col = 'blue')