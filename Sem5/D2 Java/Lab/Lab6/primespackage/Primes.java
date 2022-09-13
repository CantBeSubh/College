//primespackage->Priems.java
package primespackage;

public class Primes {
    public Boolean CheckForPrime(int a) {
        if (a <= 1)
            return false;
        Boolean res = true;
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                res = false;
                break;
            }
        }
        return res;
    }
}