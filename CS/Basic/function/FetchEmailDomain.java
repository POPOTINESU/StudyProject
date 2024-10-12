package CS.Basic.function;

public class FetchEmailDomain {

    //　メソッドチェーンの勉強のためあえて１行で書いている
    public static String upperCaseDomain(String email) {
        return email.substring(email.indexOf('@') + 1).toUpperCase();
    }

    public static void main(String[] args) {
        System.out.println(upperCaseDomain("email@test.com"));
    }
}
