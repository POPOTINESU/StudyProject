package CS.Basic.function;

public class GravityPlanet {
    public static int fallingDistance(String planet, int time) {
        return (int) Math.floor(convertMeterToMile(0.5 * gravitationalAcceleration(planet) * Math.pow(time, 2)));
    }

    public static double convertMeterToMile(double meter) {
        double MILE_PER_METER = 0.000621371;
        return meter * MILE_PER_METER;
    }

    public static double gravitationalAcceleration(String planet) {
        if (planet == "Earth")
            return 9.8;
        else if (planet == "Jupiter")
            return 24.79;
        else if (planet == "Mercury")
            return 3.7;
        return 0;
    }

    public static void main(String[] args) {
        System.out.println(fallingDistance("Earth", 10));
    }
}
