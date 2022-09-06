               int swap = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = swap;
                System.out.print(m[i][j]);