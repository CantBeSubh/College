class EMP {

    // Eid, EName, Edesig, EbasicPay and a method ComputeSalary() to compute the
    // salary of an employee.
    // Additional grade pay (AGP), Dearness allowances (DA), Travel Allowances (TA)
    // & House Rental allowances(HRA).

    int AGP = 1000, DA = 1500, TA = 2000, HRA = 3000;
    int Eid, EbasicPay = 50000;
    String EName, EDesig;

    EMP(String name, int id) {
        this.Eid = id;
        this.EName = name;
    }

    int ComputeSalary() {
        return EbasicPay;
    }
}

class ProjectManager extends EMP {
    ProjectManager(String name, int id) {
        super(name, id);
        super.EDesig = "ProjectManager";
    }

    @Override
    int ComputeSalary() {
        return super.EbasicPay + super.AGP + super.DA + super.HRA;
    }
}

class SystemEngineer extends EMP {
    SystemEngineer(String name, int id) {
        super(name, id);
        super.EDesig = "System Engineer";
    }

    @Override
    int ComputeSalary() {
        return super.EbasicPay + super.TA;
    }
}

class TechnicalAssistant extends EMP {
    TechnicalAssistant(String name, int id) {
        super(name, id);
        super.EDesig = "System Engineer";
    }

    @Override
    int ComputeSalary() {
        return super.EbasicPay;
    }
}

public class Q4 {
    public static void main(String[] args) {
        EMP emp1 = new EMP("abc", 1000);
        ProjectManager emp2 = new ProjectManager("def", 1001);
        SystemEngineer emp3 = new SystemEngineer("ghi", 1002);
        TechnicalAssistant emp4 = new TechnicalAssistant("jkl", 1003);
        System.out.println("Salary: " + emp1.ComputeSalary());
        System.out.println("Salary: " + emp2.ComputeSalary());
        System.out.println("Salary: " + emp3.ComputeSalary());
        System.out.println("Salary: " + emp4.ComputeSalary());
    }
}
