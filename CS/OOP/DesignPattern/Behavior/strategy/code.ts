interface MathStrategy {
  math(x: number, y: number);
}

class Plus implements MathStrategy {
  math(x: number, y: number) {
    return x + y;
  }
}

class Minus implements MathStrategy {
  math(x: number, y: number) {
    return x - y;
  }
}
