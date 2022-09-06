class TollPlaze {
    String vehicleType;
    Boolean isGovt;
    int car = 50, van = 75, busLorry = 100;

    TollPlaze(String vType, Boolean isGov) {
        vehicleType = vType.toLowerCase();
        isGovt = isGov;
    }

    void tollRate() {
        switch (this.vehicleType) {
            case "car":
                System.out.println("Your fare is: " + car);
                break;
            case "van":
                System.out.println("Your fare is: " + van);
                break;
            case "bus":
                System.out.println("Your fare is: " + busLorry);
                break;
            case "lorry":
                System.out.println("Your fare is: " + busLorry);
                break;
            default:
                System.out.println("Unknown vehicle type. Considering car: " + car);
                break;
        }
    }

    void tollRate(Boolean isGovt) {
        tollRate();
        if (isGovt == true)
            System.out.println("Goverment Official detected.Final Fare: 0");
    }
}

public class Q3 {
    public static void main(String[] args) {
        TollPlaze car = new TollPlaze("Car", false);
        TollPlaze govtVan = new TollPlaze("Van", true);
        car.tollRate();
        govtVan.tollRate(govtVan.isGovt);
    }
}
