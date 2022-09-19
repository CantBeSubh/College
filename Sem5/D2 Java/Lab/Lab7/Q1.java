abstract class Course {
    abstract Boolean isPassed();
}

class BooleanCourse extends Course {
    Boolean passed;

    BooleanCourse(Boolean passed) {
        this.passed = passed;
    }

    Boolean isPassed() {
        return passed;
    }
}

class GradedCourse extends Course {
    char Grade;

    GradedCourse(char Grade) {
        this.Grade = Grade;
    }

    Boolean isPassed() {
        if (Grade == 'F')
            return false;
        else
            return true;
    }
}

public class Q1 {
    public static void main(String args[]) {
        BooleanCourse subj1[] = new BooleanCourse[2];
        GradedCourse subj2[] = new GradedCourse[2];
        subj1[0] = new BooleanCourse(true);
        subj1[1] = new BooleanCourse(true);
        subj2[0] = new GradedCourse('A');
        subj2[1] = new GradedCourse('B');
        int count = 0;

        for (BooleanCourse i : subj1) {
            if (i.isPassed() == true)
                count++;

        }
        for (GradedCourse i : subj2) {
            if (i.isPassed() == true)
                count++;

        }
        System.out.println(count);
        if (count == 4)
            System.out.println("You passed your diploma!");
        else
            System.out.println("You failed your diploma!");
    }
}