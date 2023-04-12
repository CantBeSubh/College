x <- c(1, 2, 3, 4, 5)
y <- c(3, 4, 2, 4, 5)
relation <- lm(y ~ x)
print(summary(relation))
sqrt(mean(relation$residuals^2))
png(file = "lab8.png")

plot(y, x,
    col = "blue", pch = 16, cex = 1.3, abline(lm(x ~ y)),
    main = "Linear Regression", xlab = "x", ylab = "y"
)
dev.off()
