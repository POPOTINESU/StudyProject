package CS.Basic.recursion;

public class LenString {
    public static int lenString(String string) {
        return lenStringHelper(string, 0, "");
    }

    public static int lenStringHelper(String string, int count, String res) {
        if (string == null || string.equals(res))
            return count;

        return lenStringHelper(string, count + 1, res + string.charAt(count));
    }

    public static void main(String[] args) {
        System.out.println(lenString("hello world"));
    }
}
