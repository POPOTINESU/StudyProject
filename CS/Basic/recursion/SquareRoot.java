package CS.Basic.recursion;

public class SquareRoot {

    public static boolean isSquareRootCloseEnough(double a, double b) {
        return 100 * Math.abs((a - b) / b) < 0.01;
    }

    public static double squareRootHelper(double x, double guess) {
        double newGuess = (guess + x / guess) / 2;

        if (isSquareRootCloseEnough(guess, newGuess)) {
            return newGuess;
        }

        return squareRootHelper(x, newGuess);
    }

    public static double squareRoot(double x) {
        return squareRootHelper(x, 1);
    }

    public static void main(String[] args) {
        System.out.println(squareRoot(65));
    }
}
