package CS.Basic.recursion;

public class SquareSummation {
    public static int squareSummation(int n) {
        if (n <= 1) {
            return 1;
        }

        return squareSummation(n - 1) + n * n;
    }

    public static void main(String[] args) {
        System.out.println(squareSummation(208));
    }
}
