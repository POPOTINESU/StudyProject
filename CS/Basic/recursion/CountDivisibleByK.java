package CS.Basic.recursion;

public class CountDivisibleByK {
    public static int countDivisibleByK(int n, int k) {
        if (n % k != 0) {
            return 0;
        }

        return countDivisibleByK(n / k, k) + 1;
    }

    public static void main(String[] args) {
        System.out.println(countDivisibleByK(1048576, 2));
    }
}
