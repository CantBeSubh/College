# C:\Users\subhr\My Drive\College\Sem6\G ECE3502-IOT\Lab\lab11\Advertisement.csv
library(datasets) 
library(caTools) 
library(party) 
library(dplyr) 
library(magrittr) 


path_to_file<-"C:\\Users\\subhr\\My Drive\\College\\Sem6\\G ECE3502-IOT\\Lab\\lab11\\Advertisement.csv"
data=read.csv(path_to_file)
data=data[,-1]
data$Gender[data$Gender=="Male"]=as.integer(1)
data$Gender[data$Gender=="Female"]=as.integer(0)
data$Gender=as.integer(data$Gender)
head(data)
summary(data)


sample_data = sample.split(data, SplitRatio = 0.6)

train_data <- subset(data, sample_data == TRUE)

test_data <- subset(data, sample_data == FALSE)

model<- ctree(Purchased ~ ., train_data) 
plot(model)


# testing the people who are native speakers
# and those who are not

#predict_model<-predict(ctree, test_data) 
predit_model<-predict(model,test_data)
# creates a table to count how many are classified 
# as native speakers and how many are not

m_at <- table(test_data$Purchased, predit_model) 
m_at

ac_Test = sum(diag(m_at)) / sum(m_at)

print(paste('Accuracy for test is found to be', ac_Test))

library(rpart)
set.seed(1234)
train <- sample(nrow(data), 0.7 * nrow(data))
data_train <- data[train, ]
data_test <- data[-train, ]
model <- rpart(Purchased ~ ., data = data_train, method = "class")
library(rpart.plot)
rpart.plot(model)
predictions <- predict(model, data_test, type = "class")
m_at=table(data_test$Purchased, predictions)

m_at
ac_Test = sum(diag(m_at)) / sum(m_at)
print(paste('Accuracy for test is found to be', ac_Test))

