import java.sql.*;

public class CreateDB {

    static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver"; // JDBC driver name and database URL
    static final String DB_URL = "jdbc:mysql://localhost:3306/";
    static final String USER = "root"; // Database credentials
    static final String PASS = "root@123";

    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        Connection conn = null;
        Statement stmt = null;

        Class.forName(JDBC_DRIVER); // Step-1 : Register the Driver

        System.out.println("Connecting to database...");
        conn = DriverManager.getConnection(DB_URL, USER, PASS); // Step-2 : Create Connection

        System.out.println("Creating database..."); // Step-3 : Create Statement
        stmt = conn.createStatement();

        String sql = "CREATE DATABASE STUDENTS";
        stmt.executeUpdate(sql); // Step-4 : Execute Query

        System.out.println("Database created successfully...");

        conn.close();
        stmt.close(); // Step-5 : Close Connection

        System.out.println("Goodbye!");
    }
}
