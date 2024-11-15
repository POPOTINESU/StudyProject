interface Fly {
  FlightHeight(): number;
  FlySpeed(): number;
}

interface IOT {
  Connect(): boolean;
}

class Drone implements Fly, IOT {
  private MAX_HEIGHT: number;
  private MAX_SPEED: number;

  constructor() {
    this.MAX_HEIGHT = 150;
    this.MAX_SPEED = 10;
  }

  public FlightHeight(): number {
    return this.MAX_HEIGHT;
  }

  public FlySpeed(): number {
    return this.MAX_SPEED;
  }

  public Connect(): boolean {
    return true;
  }
}

const drone: Fly = new Drone();

console.log(drone.FlightHeight());
