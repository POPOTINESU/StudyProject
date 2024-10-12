package CS.Basic.function;

public class GetEmotion {
    public static String getEmotion(int height, String planet) {
        double gravitationalAcceleration = getGravitationalAcceleration(planet);

        if (gravitationalAcceleration == 0) {
            return "no data";
        }

        return getFearLevel(calculateMaxSpeed(height, gravitationalAcceleration));
    }

    public static double calculateMaxSpeed(int height, double gravitationalAcceleration) {
        return Math.sqrt(2 * gravitationalAcceleration * height);
    }

    public static String getFearLevel(double maxSpeed) {
        if (maxSpeed >= 80) {
            return "terrified";
        } else if (maxSpeed >= 60) {
            return "frighten";
        } else if (maxSpeed >= 40) {
            return "scared";
        } else {
            return "afraid";
        }
    }

    public static double getGravitationalAcceleration(String planet) {
        if (planet.equals("Earth")) {
            return 9.8;
        } else if (planet.equals("Jupiter")) {
            return 24.79;
        } else if (planet.equals("Mars")) {
            return 3.71;
        } else if (planet.equals("Pluto")) {
            return 0.58;
        } else if (planet.equals("Moon")) {
            return 1.62;
        }

        return 0;
    }

    public static void main(String[] args) {
        System.out.println(getEmotion(0, null));
    }
}