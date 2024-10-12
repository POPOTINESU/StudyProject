package CS.Basic.function;

public class IsPerfectSquare {
    public static boolean isPerfectSquare(int x, int y) {
        return isNaturalNumber(pythagorasNumber(x, y));
    }

    public static boolean isNaturalNumber(double number) {
        return number - (int) number == 0;
    }

    public static double pythagorasNumber(double x, double y) {
        return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
    }

    public static void main(String[] args) {
        System.out.println(isPerfectSquare(5, 12));
    }
}
