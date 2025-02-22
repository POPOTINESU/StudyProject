//  Inheritance
// コードを再利用することができ、 Dog is a Animalのようにis-aの関係が成立する
// 一括でコードをサブクラスに提供することができるが、変更の難易度が上がるため十分注意して行わなければならない

class Animal {
  eat() {
    console.log('食べる');
  }
  sleep() {
    console.log('寝る');
  }
}

class Dog extends Animal {
  sleep(): void {
    console.log('犬小屋で寝る');
  }
}

const dog = new Dog();
dog.eat();
dog.sleep();

// Composition
// 特定のクラスの機能を自分が使うクラスにも持たせたい場合に、継承を使わずに、プロパティとしてそのクラスをもつこと
// has - aの関係を持つ
//　継承と比べて、柔軟性を持つことができるが、複雑化する可能性がある。最近はコンポジションが好まれる傾向がある
class Tire {
  roll() {
    console.log('回る');
  }
}

class Handle {
  grip() {
    console.log('握る');
  }
}

class Car {
  private tire: Tire;
  private handle: Handle;

  constructor(tire: Tire, handle: Handle) {
    this.tire = tire;
    this.handle = handle;
  }

  getHandle() {
    return this.handle;
  }

  getTire() {
    return this.tire;
  }
}
