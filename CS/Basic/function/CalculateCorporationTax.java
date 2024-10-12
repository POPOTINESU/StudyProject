package CS.Basic.function;

public class CalculateCorporationTax {
    private static final double DEFAULT_STATE_TAX_RATE = 0.05;
    private static final double FEDERAL_TAX_RATE = 0.21;
    private static final double ARIZONA_TAX_RATE = 0.049;
    private static final double CALIFORNIA_TAX_RATE = 0.0884;
    private static final double TEXAS_TAX_RATE = 0;
    private static final double NORTH_CAROLINA_TAX_RATE = 0.025;

    public static int calculateCorporationTax(String state, int year, int profit) {
        double federalTax = calculateFederalTax(profit, isLeapYear(year));
        double stateTax = calculateStateTax(profit, state);
        return (int) Math.ceil(federalTax + stateTax);
    }

    public static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    public static double calculateFederalTax(int profit, boolean isLeapYear) {
        if (isLeapYear) {
            return 0;
        }
        return profit * FEDERAL_TAX_RATE;
    }

    public static double calculateStateTax(int profit, String state) {
        double stateTaxRate;
        switch (state) {
            case "AZ":
                stateTaxRate = ARIZONA_TAX_RATE;
                break;
            case "CA":
                stateTaxRate = CALIFORNIA_TAX_RATE;
                break;
            case "TX":
                stateTaxRate = TEXAS_TAX_RATE;
                break;
            case "NC":
                stateTaxRate = NORTH_CAROLINA_TAX_RATE;
                break;
            default:
                stateTaxRate = DEFAULT_STATE_TAX_RATE;
                break;
        }
        return profit * stateTaxRate;
    }

    public static void main(String[] args) {
        System.out.println(calculateCorporationTax("CA", 2021, 100000));
    }
}