package database;

import java.sql.*;

class DB {

    private String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    private String DB_URL = "jdbc:mysql://localhost:3306/q2cse1007";
    private String USER = "root";
    private String PASS = "19293949";
    private Connection con;
    private Statement stmt;

    private void connect() {
        try {
            // Driver Registering (Loading)
            Class.forName(JDBC_DRIVER);
            // Connenction Establishment (Create Connection)
            con = DriverManager.getConnection(DB_URL, USER, PASS);
            // Statement Creation
            stmt = con.createStatement();

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    String[][] get(String Name) {
        String[][] result = new String[5][8];
        try {
            connect();
            ResultSet rs = stmt.executeQuery("select * from 20brs_cse1007 where Name=" + Name);
            int i = 0;
            while (rs.next() && i < 5) {
                result[i][0] = rs.getString(1);
                result[i][1] = rs.getString(2);
                result[i][2] = rs.getString(3);
                result[i][3] = rs.getString(4);
                result[i][4] = rs.getString(5);
                result[i][5] = rs.getString(6);
                result[i][6] = rs.getString(7);
                result[i][7] = rs.getString(8);

                System.out.println(result[i]);
            }
            // Close Connection
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
        return result;
    }

    void put(String[] input) {
        try {
            connect();
            String query = "insert into q2cse1007.20brs_cse1007 (RollNumber,Name,CAT1,CAT2,FAT,DA1,DA2,DA3) values (";
            for (int i = 0; i < input.length; i++)
                query += input[i];
            query += ");";

            ResultSet rs = stmt.executeQuery(query);
            System.out.println(rs.getString(1));

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
