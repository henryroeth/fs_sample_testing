


#create table
data <- matrix(c(120, 90, 40, 110), ncol=2, byrow=TRUE)
colnames(data) <- c("PM2.5","Ozone")
rownames(data) <- c("Air.gov","Field Station")
data <- as.table(data)

data


#Perform Chi-Square Test of Independence
chisq.test(data)

