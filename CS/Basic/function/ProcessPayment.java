package CS.Basic.function;

public class ProcessPayment {
    final static double TAX_RATE = 0.1;

    public static double processPayment(String creditCardType, int cost) {
        if (!isCardValidate(creditCardType)) {
            return -1.0;
        }

        double totalCost = cost * (1 + TAX_RATE) + calculateChipFee(cost);

        if (totalCost > 300) {
            return -1.0;
        }

        return totalCost;
    }

    public static double calculateChipFee(int mealCost) {
        double chip_rate = 0.1;
        if (mealCost % 3 == 0) {
            chip_rate = 0.03;
        } else if (mealCost % 5 == 0) {
            chip_rate = 0.05;
        } else if (mealCost % 7 == 0) {
            chip_rate = 0.07;
        }

        return mealCost * (chip_rate);
    }

    public static boolean isCardValidate(String creditCardType) {
        return creditCardType == "MasterCard" || creditCardType == "Visa";
    }

    public static void main(String[] args){
        System.out.println(processPayment("Visa",210));
    }
}
