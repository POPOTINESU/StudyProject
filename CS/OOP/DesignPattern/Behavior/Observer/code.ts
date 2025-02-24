interface Observer {
  update(name: string);
}

class StoreObserver implements Observer {
  update(name: string) {
    console.log(`${name}が入荷された`);
  }
}

class PersonalObserver implements Observer {
  update(name: string) {
    console.log(`${name}が入荷された`);
  }
}

abstract class ItemSubject {
  private observers: Observer[] = [];

  constructor(private name: string) {}

  attach(observer: Observer) {
    this.observers.push(observer);
  }

  detach(observer: Observer) {
    this.observers.filter((obs) => obs !== observer);
  }

  notify() {
    this.observers.forEach((obs) => obs.update(this.name));
  }

  abstract restock();
}

class TvGameSubject extends ItemSubject {
  private inStock: boolean;

  constructor(name: string) {
    super(name);
    this.inStock = false;
  }

  restock() {
    console.log('TVゲームの入荷');

    this.inStock = true;
    this.notify();
  }
}
