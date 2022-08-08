class Date {
    int date;
    int month;
    int year;

    Date(int d, int m, int y) {
        this.date = d;
        this.month = m;
        this.year = y;
    }

    void setDate(int d) {
        this.date = d;
    }

    void setMonth(int m) {
        this.month = m;
    }

    void setYear(int y) {
        this.year = y;
    }

    int getDate() {
        return this.date;
    }

    int getMonth() {
        return this.month;
    }

    int getYear() {
        return this.year;
    }

    String displayDate() {
        return this.date + " / " + this.month + " / " + this.year;
    }
}

public class DateTest {
    public static void main(String args[]) {
        Date date = new Date(0, 0, 0);
        date.setDate(9);
        date.setMonth(8);
        date.setYear(2022);
        System.out.println("Date: " + date.displayDate());

    }
}
