
#create table
data <- matrix(c(90, 90), ncol=1, byrow=TRUE)
colnames(data) <- c("PM2.5")
rownames(data) <- c("Air.gov","Field Station")
data <- as.table(data)

data


#Perform Chi-Square Test of Independence
chisq.test(data)

#create table
data <- matrix(c(120, 90), ncol=1, byrow=TRUE)
colnames(data) <- c("Ozone")
rownames(data) <- c("Air.gov","Field Station")
data <- as.table(data)

data


#Perform Chi-Square Test of Independence
chisq.test(data)