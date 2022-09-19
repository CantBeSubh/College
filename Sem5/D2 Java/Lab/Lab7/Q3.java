import java.util.NoSuchElementException;
import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Roll Number: ");
        String rollNo = sc.nextLine();
        System.out.println("Enter Mobile Number: ");
        String number = sc.nextLine();
        try {
            if (rollNo.length() != 9 || number.length() != 10)
                throw new IllegalArgumentException("Invalid Length");
            long num = Long.parseLong(number);
            for (int i = 0; i < rollNo.length(); i++) {
                if (!Character.isLetter(rollNo.charAt(i)) && !Character.isDigit(rollNo.charAt(i)))
                    throw new NoSuchElementException();
            }

            System.out.println("Valid");
        } catch (NumberFormatException e) {
            System.out.println(e);
            System.out.println("Invalid");

        } catch (IllegalArgumentException e) {
            System.out.println(e);
            System.out.println("Invalid");
        }
        sc.close();
    }
}