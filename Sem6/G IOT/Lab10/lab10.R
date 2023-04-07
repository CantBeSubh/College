df<-read.csv("C:\\Users\\subhr\\My Drive\\College\\Sem6\\G ECE3502-IOT\\Lab\\Lab10\\data.csv")
xlsx::write.xlsx(df,"lab10.xls",col.names=TRUE,row.names=TRUE,sheetName="sample")
summary(df)

#1
install.packages("stringr")
library("stringr")

df[c('Processor Size','OS Name')]<-str_split_fixed(df$OS,'bit',2)
df$`OS Name`<- gsub("Operating System","",df$`OS Name`)


#2
df[c('RAM','ABC')]<-str_split_fixed(df$RAM,' ',2)
df<-subset(df,select=-c(ABC))
colnames(df)[6]="RAM(Size in GB)"

#3
max(df$SSD,na.rm=TRUE)

#4
df[df$warranty=='2 Year Onsite Warranty',]

