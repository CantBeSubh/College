public class Ques2 {
    private static int regNo = 202201;
    private String name;
    private String dept;
    private String dob;
    private String email;
    private String mobile;
    private int regNoInstance;

    public Ques2(String name, String dept, String dob, String email, String mobile) {
        this.name = name;
        this.dept = dept;
        this.dob = dob;
        this.email = email;
        this.mobile = mobile;
        this.regNoInstance = regNo;
        regNo++;
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Registration Number: " + regNoInstance);
        System.out.println("Department: " + dept);
        System.out.println("Date of Birth: " + dob);
        System.out.println("Email: " + email);
        System.out.println("Mobile: " + mobile);
        System.out.println();
    }

    public static void main(String[] args) {
        Ques2 stud1 = new Ques2("Abdul", "CSE", "01/10/2000", "abc@email.com",
                "3213131123");
        Ques2 stud2 = new Ques2("Bihari", "ECE", "22/03/2000", "def@email.com",
                "3213131123");
        Ques2 stud3 = new Ques2("Cheta", "CSE", "13/5/2000", "ghi@email.com",
                "3213131123");
        Ques2 stud4 = new Ques2("Dhruv", "MECH", "24/4/2000", "jkl@email.com",
                "3213131123");
        Ques2 stud5 = new Ques2("Frank", "CSE", "5/12/2000", "mno@email.com",
                "3213131123");

        stud1.display();
        stud2.display();
        stud3.display();
        stud4.display();
        stud5.display();
    }
}