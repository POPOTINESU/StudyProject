package CS.Basic.function;

class LatitudeAndLongitude {
    private static final int EQUATOR = 0;
    private static final int PRIME_MERIDIAN = 0;

    public static String calculateLocation(double latitude, double longitude) {
        return getLatitudeDirection(latitude) + "/" + getLongitudeDirection(longitude);
    }

    public static String getLatitudeDirection(double latitude) {
        if (latitude > EQUATOR)
            return "north";
        else if (latitude < EQUATOR)
            return "south";
        return "equator";
    }

    public static String getLongitudeDirection(double longitude) {
        if (longitude > PRIME_MERIDIAN)
            return "east";
        else if (longitude < PRIME_MERIDIAN)
            return "west";
        return "prime meridian";
    }

    public static void main(String[] args) {
        System.out.println(calculateLocation(35.6895, 139.6917)); // Tokyo: north/east
    }
}