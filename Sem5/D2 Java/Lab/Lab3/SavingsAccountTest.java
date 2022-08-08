class SavingsAccount {
    public static double annualInterestRate;
    private double savingsBalance;

    SavingsAccount() {
        annualInterestRate = 0.0;
        savingsBalance = 0.0;
    }

    SavingsAccount(double intRate, double savBal) {
        annualInterestRate = intRate;
        savingsBalance = savBal;
    }

    double calculateMonthlyInterest() {
        double intRate = (savingsBalance * annualInterestRate / 12);
        savingsBalance = savingsBalance + intRate;
        return intRate;
    }

    static void modifyInterestRate(double newInteresRate) {
        annualInterestRate = newInteresRate;
    }

    void setSavingsBalance(double newBal) {
        savingsBalance = newBal;
    }

    double getSavingsBalance() {
        return savingsBalance;
    }

    double getAnnualInterestRate() {
        return annualInterestRate;
    }
}

public class SavingsAccountTest {
    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount();
        SavingsAccount saver2 = new SavingsAccount();
        saver1.setSavingsBalance(2000.00);
        saver2.setSavingsBalance(3000.00);
        SavingsAccount.modifyInterestRate(0.04);
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        System.out.println("New Balance for Saver1= " + saver1.getSavingsBalance());
        System.out.println("New Balance for Saver2= " + saver2.getSavingsBalance());

        SavingsAccount.modifyInterestRate(0.05);
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        System.out.println("New Balance for Saver1= " + saver1.getSavingsBalance());
        System.out.println("New Balance for Saver2= " + saver2.getSavingsBalance());

    }
}