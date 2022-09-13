class complex {
    int x, y;

    complex(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class multi {
    int MyMulitiplication(int x, int y) {
        return x * y;
    }

    double MyMulitiplication(double x, double y) {
        return x * y;
    }

    complex MyMulitiplication(complex X, complex Y) {
        int a = X.x * Y.x - X.y * Y.y;
        int b = X.x * Y.y + X.y * Y.x;
        complex res = new complex(a, b);
        return res;
    }

}

public class Q3 {
    public static void main(String[] args) {
        // System.out.println("");
        multi m = new multi();
        complex a = new complex(1, 2);
        complex b = new complex(3, 4);
        System.out.println(m.MyMulitiplication(10, 20));
        System.out.println(m.MyMulitiplication(10.0, 20.0));
        complex c = m.MyMulitiplication(a, b);
        System.out.println(c.x + "+" + c.y + "i");
    }
}
