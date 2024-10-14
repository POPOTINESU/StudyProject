package CS.Basic.recursion;

public class SimpleSummation {
    public static int simpleSummation(int n) {
        if (n == 0) {
            return 0;
        }

        return simpleSummation(n - 1) + n;
    }

    public static void main(String[] args) {
        System.out.println(simpleSummation(100));
    }
}
