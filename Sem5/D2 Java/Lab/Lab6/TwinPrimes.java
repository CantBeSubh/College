
//TwinPrimes.java
import primespackage.*;

public class TwinPrimes {
    Primes primes = new Primes();

    int[][] twinPrimes(int a, int b) {
        int res[][] = new int[10][10];
        int pos = 0;
        for (int i = a; i < b - 2; i++) {
            if (i % 2 == 0)
                continue;
            int j = i + 2;
            if (primes.CheckForPrime(i) && primes.CheckForPrime(j)) {
                res[pos][0] = i;
                res[pos][1] = j;
                pos++;
            }
        }
        return res;
    }

    public static void main(String args[]) {
        int[][] ans = new TwinPrimes().twinPrimes(1, 10);
        for (int[] i : ans) {
            if (i[0] != 0)
                System.out.println(i[0] + " " + i[1]);
        }
    }
}