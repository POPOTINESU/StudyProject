// インターフェースの利用者に対して、インターフェースを分離するべきものである

interface Creature {
  eat();
}

interface Animal extends Creature {
  eat();
  run();
}

interface Bird {
  eat();
  fly();
}

class Fish implements Creature {
  eat() {}
  swim() {}
}

const kaba = new Animal();
