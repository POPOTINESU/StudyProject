/**
 * 結合度とは、モジュール間のデータ参照や接続の依存度合いを表す指標である
 * クラス同士の結びつきを弱める疎結合を目指す頃でモジュール同士の独立性を高め、再利用しやすいコードを意識する
 */

// 練習1
interface Person {
  getName(): string;
}

class Teacher implements Person {
  private name: string;
  private subject: string;

  constructor(name: string, subject: string) {
    this.name = name;
    this.subject = subject;
  }

  getName(): string {
    return this.name;
  }

  getSubject(): string {
    return this.subject;
  }
}

class Student implements Person {
  private name: string;

  constructor(name: string) {
    this.name = name;
  }

  getName(): string {
    return this.name;
  }

  startLesson(teacher: Teacher) {
    console.log(`Hello, Mr.${teacher.getName()}! I'm ${this.name}.`);
  }
}

class Lesson {
  private students: Student[];
  private teacher: Teacher;

  constructor(students: Student[], teacher: Teacher) {
    this.students = students;
    this.teacher = teacher;
  }

  start() {
    for (const student of this.students) {
      student.startLesson(this.teacher);
    }
  }

  setTeacher(teacher: Teacher) {
    this.teacher = teacher;
  }
}

// 練習2
class Delivery {
  private area = {
    hokkaido: 1000,
    tohoku: 600,
    kanto: 600,
    chubu: 600,
    kinki: 800,
    chugoku: 800,
    shikoku: 800,
    kyushu: 1000,
  };

  getDelivery(area: string) {
    return this.area[area] ?? new Error('対応していないエリアです');
  }
}

class Item {
  private name: string;
  private price: number;
  private quantity: number;

  constructor(name: string, price: number, quantity: number) {
    this.name = name;
    this.price = price;
    this.quantity = quantity;
  }

  getName(): string {
    return this.name;
  }

  getPrice(): number {
    return this.price;
  }

  getQuantity(): number {
    return this.quantity;
  }
}

class Cart {
  private items: Item[];
  constructor(items: Item[]) {
    this.items = [...items];
  }

  addItem(item: Item) {
    this.items.push(item);
  }

  removeItem(itemName: string) {
    this.items = this.items.filter((i) => i.getName() !== itemName);
  }

  getItems() {
    return [...this.items];
  }

  getItemTotal() {
    return this.items.reduce((total, item) => {
      return total + item.getPrice() * item.getQuantity();
    }, 0);
  }
}

class Order {
  private cart: Cart;
  private delivery: Delivery;

  constructor(cart: Cart, delivery: Delivery) {
    this.cart = cart;
    this.delivery = delivery;
  }

  getTotalPrice(area: string) {
    const itemTotal = this.cart.getItemTotal();
    const delivery = this.delivery.getDelivery(area);

    return itemTotal + delivery;
  }

  confirm(area: string) {
    return {
      items: this.cart.getItems(),
      total: `${this.getTotalPrice(area)}円`,
    };
  }
}
