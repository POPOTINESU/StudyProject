package CS.Basic.recursion;

public class SplitAndAdd {
    public static int splitAndAdd(int digits){
        if (digits < 10) return digits;

        return digits % 10 + splitAndAdd(digits/10);
    }

    public static void main(String[] args) {
        System.out.println(splitAndAdd(19));
    }
}
