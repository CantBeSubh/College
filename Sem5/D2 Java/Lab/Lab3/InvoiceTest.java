class invoice {
    String part_number;
    String part_desc;
    int part_qty;
    double part_price;

    invoice(String number, String desc, int qty, double price) {
        this.part_number = number;
        this.part_desc = desc;

        if (qty < 0) {
            this.part_qty = 0;
        } else {
            this.part_qty = qty;
        }

        if (price < 0.0) {
            this.part_price = 0.0;
        } else {
            this.part_price = price;
        }
    }

    void setNumber(String number) {
        this.part_number = number;
    }

    String getNumber() {
        return this.part_number;
    }

    void setDesc(String desc) {
        this.part_desc = desc;
    }

    String getDesc() {
        return this.part_desc;
    }

    void setQty(int qty) {
        if (qty < 0) {
            this.part_qty = 0;
        } else {
            this.part_qty = qty;
        }
    }

    int getQty() {
        return this.part_qty;
    }

    void setPrice(double price) {
        if (price < 0.0) {
            this.part_price = 0.0;
        } else {
            this.part_price = price;
        }
    }

    double getPrice() {
        return this.part_price;
    }

    double getInvoice() {
        return this.part_price * this.part_qty;
    }
}

public class InvoiceTest {
    public static void main(String[] args) {
        invoice inv = new invoice("abc", "def", 1, 456.7);
        System.out.println("number: " + inv.getNumber());
        inv.setNumber("1234");
        System.out.println("number: " + inv.getNumber());
        System.out.println("desc: " + inv.getDesc());
        System.out.println("price: " + inv.getPrice());
        System.out.println("qty: " + inv.getQty());

        System.out.println("invoice: " + inv.getInvoice());

    }
}
