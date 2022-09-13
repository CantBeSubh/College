public class Q2 {
    public static void main(String[] args) {
        int m[][] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        int size = m[0].length;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (i == j)
                    continue;
                int swap = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = swap;
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                System.out.print(m[i][j]);
            System.out.println("");
        }
    }
}
