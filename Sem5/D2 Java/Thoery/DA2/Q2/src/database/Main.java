package database;

import java.sql.*;

class Main {
    public static void main(String[] args) {
        try {
            final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
            final String DB_URL = "jdbc:mysql://localhost:3306/q2cse1007";
            final String USER = "root";
            final String PASS = "19293949";

            // Driver Registering (Loading)
            Class.forName(JDBC_DRIVER);

            // Connenction Establishment (Create Connection)
            Connection con = DriverManager.getConnection(DB_URL, USER, PASS);
            // Statement Creation
            Statement stmt = con.createStatement();
            // Execute a Statement
            ResultSet rs = stmt.executeQuery("select * from 20brs_cse1007");
            while (rs.next()) {
                String result = rs.getInt(1) + " "
                        + rs.getString(2) + " "
                        + rs.getString(3) + " "
                        + rs.getString(4) + " "
                        + rs.getString(5) + " "
                        + rs.getString(6) + " "
                        + rs.getString(7) + " "
                        + rs.getString(8) + " ";

                System.out.println(result);
            }
            con.close(); // Close Connection
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}