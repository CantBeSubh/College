// Create a class named AccountDetails. The AccountDetails class should have the facility to maintain the following information: Account holder name, age, date of birth, identity (Aadhar/PAN), account balance, account type etc. There a two major actions performed over the account namely Deposit and Withdrawal. When a deposit is made, the user should be prompted to enter the deposit amount and the same should be added to the account balance and update the balance. When a withdrawal is done, the user should be prompted to enter the withdrawal amount and a condition to check if the withdrawal amount is less than available balance is to be carried out. If less, subtract the withdrawal amount from the available balance and update the balance. Perform the Deposit and withdrawal operations using member methods and demonstrate the working of the class..

import java.util.*;

class AccountDetails {
    String name, dob, pan, accType;
    int age, accBal;

    AccountDetails(String name, String dob, String pan, String accType, int age, int accBal) {
        this.name = name;
        this.dob = dob;
        this.pan = pan;
        this.accType = accType;
        this.age = age;
        this.accBal = accBal;
    }

    void Deposit() {
        Scanner sc = new Scanner(System.in);
        int amt = sc.nextInt();
        accBal += amt;
        System.out.println("New Balance: " + accBal);
    }

    void Withdrawal() {
        Scanner sc = new Scanner(System.in);
        int amt = sc.nextInt();
        if (amt < accBal)
            accBal -= amt;
        else
            System.out.println("Requested ammount more than current balance!");
        System.out.println("New Balance: " + accBal);
    }
}

public class Q4 {
    public static void main(String[] args) {
        AccountDetails acc1 = new AccountDetails(
                "Subhranshu",
                "04-12-2001",
                "ABXY1001GG",
                "sav",
                20,
                20000);
        acc1.Withdrawal();
        acc1.Deposit();
        acc1.Withdrawal();
    }
}