// クラスの拡張にオープンであり、修正にはクローズドであるべき
// 既存の機能に変更を変えずに拡張できるようにすべきである

// クローズ
function printEmployee(employee) {
  employee.printDescription();
  employee.printMembers();
}

class Employee {
  private description: string;
  private members;
  constructor(description, members) {
    this.description = description;
    this.members = members;
  }

  printDescription() {
    console.log(this.description);
  }

  printMembers() {
    this.members.array.forEach((member) => {
      console.log(member);
    });
  }
}

// オープン
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
