package CS.Basic.function;

public class CalculateCorporationTax {
    public static int calculateCorporationTax(String state, int year, int profit) {
        return (int) Math.ceil(calculateFederalTax(profit, isLeapYear(year)) + calculateStateTax(profit, state));
    }

    public static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    public static double calculateFederalTax(int profit, boolean is_leap_year) {
        double FEDERAL_TAX = 0.21;
        if (is_leap_year) {
            FEDERAL_TAX = 0;
        }
        return profit * FEDERAL_TAX;
    }

    public static double calculateStateTax(int profit, String state) {
        double state_tax_rate = 0.05;

        if (state.equals("AZ")) {
            state_tax_rate = 0.049;
        } else if (state.equals("CA")) {
            state_tax_rate = 0.0884;
        } else if (state.equals("TX")) {
            state_tax_rate = 0;
        } else if (state.equals("NC")) {
            state_tax_rate = 0.025;
        }

        return profit * state_tax_rate;
    }

    public static void main(String[] args) {
        System.out.println(calculateCorporationTax("CA", 2021, 100000));
    }
}
