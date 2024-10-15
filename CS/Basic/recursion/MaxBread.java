package CS.Basic.recursion;

public class MaxBread {
    public static int maxBread(int money, int price, int sticker) {
        final int bread = (int) Math.floor(money / price);
        return maxBreadHelper(sticker, bread, bread);
    }

    public static int maxBreadHelper(int sticker, int bread, int hold) {
        if (sticker > hold)
            return bread;
        final int newBread = (int) Math.floor(hold / sticker);
        return maxBreadHelper(sticker, bread + newBread, hold - sticker * newBread + newBread);
    }

    public static void main(String[] args) {
        System.out.println(maxBread(10, 2, 3));
        System.out.println(maxBread(15, 1, 3));
        System.out.println(maxBread(20, 2, 10));
        System.out.println(maxBread(50, 3, 2));
    }
}
