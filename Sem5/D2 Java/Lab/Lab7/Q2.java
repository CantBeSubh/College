abstract class Themepark {
    int adultFee = 500, childrenFee = 300;
    int adult, children;

    abstract int total();

    abstract void playGame(int a);
}

class Queensland extends Themepark {

    Boolean games[] = new Boolean[30];

    Queensland(int a, int c) {
        adult = a;
        children = c;
        for (int i = 0; i < games.length; i++)
            games[i] = true;
    }

    int total() {
        return adultFee * adult + childrenFee * children;
    }

    void playGame(int a) {
        if (a < 0 || a > 30)
            System.out.println("Invalid Game Code!");
        else if (games[a] == false)
            System.out.println("Game Already Played!");
        else {
            System.out.println("Thank You For Playing!");
            games[a] = false;
        }
        return;
    }
}

class Wonderla extends Themepark {
    int games[] = new int[40];

    Wonderla(int a, int c) {
        adult = a;
        children = c;
        for (int i = 0; i < games.length; i++)
            games[i] = 0;
    }

    int total() {
        return adultFee * adult + childrenFee * children;
    }

    void playGame(int a) {
        if (a < 0 || a > 30)
            System.out.println("Invalid Game Code!");
        else {
            System.out.println("Thank You For Playing!");
            games[a] += 1;
        }
        return;
    }

    void count() {
        int a = 0, b = 0, c = 0;
        for (int i : games) {
            if (i > 1)
                a++;
            else if (i == 1)
                b++;
            else
                c++;
        }

        System.out.println("You played " + a + "games more than once, " + b + " games only once and " + c
                + " were not even played once.");
    }
}

public class Q2 {
    public static void main(String[] args) {
        Queensland A = new Queensland(10, 4);
        Wonderla B = new Wonderla(12, 6);
        System.out.println("Your total Fare: " + A.total());
        A.playGame(2);
        A.playGame(60);
        A.playGame(3);
        A.playGame(2);

        System.out.println("Your total Fare: " + B.total());
        B.playGame(2);
        B.playGame(60);
        B.playGame(3);
        B.playGame(2);
    }
}
