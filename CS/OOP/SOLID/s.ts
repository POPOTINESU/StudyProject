// クラスは単一の責任を負うべきルールである
// 例1
class TodoList {
  items: Array<string>;

  constructor() {
    this.items = [];
  }

  addItem(text: string) {
    this.items.push(text);
  }

  removeItem(index) {
    this.items = this.items.splice(index, 1);
  }

  toString() {
    return this.items.toString();
  }
}

class FileManager {
  save(filename: string, data: string) {}

  load(filename: string) {}
}

// 例2
class LoginButton {
  onClick() {}

  render() {
    // ログインボタンの表示
  }
}

class Auth {
  login() {
    // ログイン機能
  }

  logout() {
    // ログアウト機能
  }
}

// 例3

class Payment {
  private strategy: PayMethod;

  constructor(strategy: PayMethod) {
    this.strategy = strategy;
  }

  confirmOrder(billingInfo: string, orderInfo: string) {
    this.strategy.confirm(billingInfo, orderInfo);
  }

  cancel(id: string) {
    this.strategy.cancel(id);
  }
}

class PayMethod {
  confirm(billingInfo: string, orderInfo: string): void {}
  cancel(id: string): void {}
}

class PayPay {
  confirm(billingInfo: string, orderInfo: string): void {}
  cancel(id: string): void {}
}

class Credit {
  confirm(billingInfo: string, orderInfo: string): void {}
  cancel(id: string): void {}
}
