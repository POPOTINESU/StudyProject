package CS.Basic.recursion;

public class InfectedPeople {
    public static int infectedPeople(int day) {
        if (day == 0) {
            return 1;
        }

        return infectedPeople(day - 1) * 2;
    }

    public static void main(String[] args) {
        System.out.println(infectedPeople(15));
    }
}
