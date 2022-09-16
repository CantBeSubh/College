import java.util.*;

public class Q1 {

    static int[] Ans(int arr[], int n) {
        int max = -999, pos = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
                pos = i;
            }
        }
        int ans[] = { max, pos };
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        int Solution[] = Ans(arr, n);
        System.out.println("Maximum element: " + Solution[0] + " at index: " + Solution[1]);
        sc.close();
    }
}