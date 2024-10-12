package CS.Basic.function;

public class CalculateGoalMoney {
    public static int calculateGoalMoney(int capital, int year) {
        double interestRate;

        // 元金が偶数か奇数かで利率を決定
        if (capital % 2 == 0) {
            interestRate = 0.02;  // 偶数なら2%
        } else {
            interestRate = 0.03;  // 奇数なら3%
        }

        // 複利計算: P(1 + i)^n
        double totalAmount = capital * Math.pow(1 + interestRate, year);

        // 小数点以下切り捨て
        return (int) Math.floor(totalAmount);
    }

    public static void main(String[] args) {
        // テストケース
        System.out.println(calculateGoalMoney(43, 14));  // 43元本、14年後の場合
        System.out.println(calculateGoalMoney(2, 3));    // 2元本、3年後の場合
    }
}