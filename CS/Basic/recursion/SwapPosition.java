package CS.Basic.recursion;

public class SwapPosition {
    public static String swapPosition(String s) {
        
        System.out.println(s.length());
        if (s.length() <= 1) {
            return s;
        } 
        else if (s.length() == 2) {
            return s.substring(1, 2) + s.substring(0, 1);
        }

        return s.substring(1, 2) + s.substring(0, 1) + swapPosition(s.substring(2, s.length()));
    }

    public static void main(String[] args) {

        System.out.println(swapPosition("abcd"));
    }
}
