package database;

import java.sql.*;

public class DB {

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

    public String[][] get(String Name) {
        String[][] result = new String[5][8];
        try {
            connect();
            ResultSet rs = stmt.executeQuery("select * from 20brs_cse1007 where Name='" + Name + "';");
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

    public void put(String[] input) {
        try {
            connect();
            String query = "insert into q2cse1007.20brs_cse1007 " +
                    "(RollNumber,Name,CAT1,CAT2,FAT,DA1,DA2,DA3) values (" +
                    input[0] + ",'" +
                    input[1] + "'," +
                    input[2] + "," +
                    input[3] + "," +
                    input[4] + "," +
                    input[5] + "," +
                    input[6] + "," +
                    input[7] + ");";
            System.out.println(query);
            stmt.execute(query);
            System.out.println("Student added");

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public String grades(Double marks) {
        if (marks > 90) {
            return "A";
        } else if ((marks > 85) && (marks < 90)) {
            return "B";
        } else if ((marks > 80) && (marks < 85)) {
            return "C";
        } else if ((marks > 70) && (marks < 80)) {
            return "D";
        } else if ((marks > 60) && (marks < 70)) {
            return "E";
        } else {
            return "F";
        }
    }
}
