#install.packages("BSDA")   #first install the library, if you have not this library installed....simply remove the # sign and run this line
library ("BSDA")           #load the library
Sample=c(9.7, 9.7, 8.9, 9.2, 9.4, 9.1, 9.5, 9.6, 8.9, 9.1, 9.5, 9.2, 9.5, 9.4, 9.6, 9.2, 9.9, 10, 9.3, 9.6) #lets put the values in a vector
PopulationMean= 9.5 #this is the population mean...or the historical time it has taken people to run 100m
PopulationSD=0.2 #this is the population standard deviation

z.test(x=Sample, alternative = "less", mu = PopulationMean, sigma.x = PopulationSD, conf.level = 0.95)


#the parameters needed to run a Z-test are self-explanatory. 
#x is the array with your sample data. alternative is the type 
#of test to run, in this case we want to check is the sample is 
#less than the population mean. mu is the population mean, and sigma.
#x is the standard deviation of the population. This function ask for 
#the confidence level, which as we indicated before is the complement 
#to the level of significance we use, in our case our significance 
#level is 0.05, so the confidence level will be 0.95





