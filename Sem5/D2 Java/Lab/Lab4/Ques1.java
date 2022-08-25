public class Ques1 {
    private static int studentCount = 1;
    private String name;
    private int regNo;
    private String email;
    private String mobile;
    private int studentInstance;

    public Ques1(String name, int regNo, String email, String mobile) {
        this.name = name;
        this.regNo = regNo;
        this.email = email;
        this.mobile = mobile;
        this.studentInstance = studentCount;
        studentCount++;
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Registration Number: " + regNo);
        System.out.println("Email: " + email);
        System.out.println("Mobile: " + mobile);
        System.out.println("Number of students: " + studentInstance);
        System.out.println();
    }

    public static void main(String[] args) {
        Ques1 stud1 = new Ques1("Abdul", 202201, "abc@email.com", "12432123542");
        Ques1 stud2 = new Ques1("Bhihari", 202202, "def@email.com", "12931230512");
        Ques1 stud3 = new Ques1("Cheta", 202203, "ghi@email.com", "12931230512");
        Ques1 stud4 = new Ques1("Dhruv", 202204, "jkl@email.com", "12931230512");
        Ques1 stud5 = new Ques1("Frank", 202205, "mno@email.com", "12931230512");

        stud1.display();
        stud2.display();
        stud3.display();
        stud4.display();
        stud5.display();
    }
}