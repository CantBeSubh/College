
// Assume that an input array comprises of 10 numbers. Write a java program to find the difference between the largest and smallest element in the array and print the difference value. 
import java.util.*;

public class Q3 {
    static int Ans(int arr[], int n) {
        int min = 999, max = -999;
        for (int i : arr) {
            if (i > max)
                max = i;
            if (i < min)
                min = i;

        }
        return max - min;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 10;
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        int Solution = Ans(arr, n);
        System.out.println("Solution: " + Solution);
        sc.close();
    }
}