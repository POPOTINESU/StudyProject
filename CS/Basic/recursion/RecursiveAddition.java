package CS.Basic.recursion;

public class RecursiveAddition {
    public static int recursiveAddition(int m, int n) {
        int sumNumber = 2;
        int subMNumber = 1;
        int subNNumber = 1;

        // 再帰の練習
        if(m == 0 && n == 0){
            return 0;
        }

        if(m == 0){
            subMNumber = 0;
            sumNumber -= 1;
        }
        if(n == 0){
            subNNumber = 0;
            sumNumber -= 1;
        }

        return recursiveAddition(m - subMNumber, n - subNNumber) + sumNumber;
    }

    public static void main(String[] args) {
        System.out.println(recursiveAddition(21, 30));
    }
}
