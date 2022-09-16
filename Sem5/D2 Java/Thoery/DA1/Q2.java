
// Assume that an input array comprises of both even and odd numbers as its elements, write a simple java program to remove all the even elements alone from the array and then print the array comprising of odd numbers alone.
import java.util.*;

public class Q2 {
    static int[] Ans(int arr[], int n) {
        int pos = 0;
        int ans[] = new int[n];
        for (int i : arr) {
            if (i % 2 != 0) {
                ans[pos] = i;
                pos++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        int ans[] = Ans(arr, n);
        int i = 0;
        while (ans[i] != 0) {
            System.out.print(ans[i] + " ");
            i++;
        }

        sc.close();
    }
}
