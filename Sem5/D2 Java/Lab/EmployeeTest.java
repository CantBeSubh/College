class Employee {
    String fName;
    String lName;
    double salary;

    Employee(String f, String l, double s) {
        this.fName = f;
        this.lName = l;
        if (s < 0) {
            this.salary = 0;
        } else {
            this.salary = s;
        }
    }

    void setfName(String fName) {
        this.fName = fName;
    }

    void setlName(String lName) {
        this.lName = lName;
    }

    void setSalary(double salary) {
        this.salary = salary;
    }

    String getName() {
        return this.fName + this.lName;
    }

    double getSalary() {
        return this.salary;
    }
}

public class EmployeeTest {
    public static void main(String args[]) {
        Employee emp1 = new Employee("Subhranshu", "Pati", 300);
        Employee emp2 = new Employee("Not", "Subhranshu", 400);
        System.out.println("EMP1");
        System.out.println("Name: " + emp1.getName());
        System.out.println("Salary: " + emp1.getSalary());
        System.out.println("--------------------------------------");
        System.out.println("EMP2");
        System.out.println("Name: " + emp2.getName());
        System.out.println("Salary: " + emp2.getSalary());
        System.out.println("--------------------------------------");
        System.out.println("After Increament");
        emp1.setSalary(emp1.getSalary() * 110 / 100);
        emp2.setSalary(emp2.getSalary() * 110 / 100);
        System.out.println("Salary for emp1: " + emp1.getSalary());
        System.out.println("Salary for emp2: " + emp2.getSalary());
        System.out.println("--------------------------------------");
    }

}
