
class Account {
    String customerName, accountNumber, TOA;
    int balance = 0;

    Account(String name, String accNo, String toa) {
        customerName = name;
        accountNumber = accNo;
        TOA = toa;
    }
}

class cur_acct extends Account {
    cur_acct(String name, String accNo) {
        super(name, accNo, "CA");
    }

    void checkBal() {
        if (balance < 1000)
            balance -= 250;
        return;
    }

    void deposit(int moni) {
        balance += moni;
    }

    void withdrawl(int moni) {
        balance -= moni;
        checkBal();
    }

    void display() {
        System.out.println("Your balance is: " + balance);
    }
}

class sav_acct extends Account {
    sav_acct(String name, String accNo) {
        super(name, accNo, "SA");
    }

    void deposit(int moni) {
        balance += moni;
    }

    void withdrawl(int moni) {
        balance -= moni;
    }

    double intrest(int tp) {
        double TP = tp;
        double I = balance * Math.pow((1 + 0.07), TP);
        balance += (int) I;
        return I;
    }

    void display() {
        System.out.println("Your balance is: " + balance);
    }
}

public class Q2 {
    public static void main(String[] args) {
        cur_acct A = new cur_acct("Ramesh", "1001R");
        sav_acct B = new sav_acct("Suresh", "10002S");
        A.deposit(10000);
        B.deposit(25000);
        A.display();
        B.display();
        System.out.println("Your Intrest is: " + B.intrest(2));
        A.withdrawl(4000);
        A.checkBal();
    }
}