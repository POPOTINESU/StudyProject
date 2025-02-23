class Product {
  getProduct(name: string) {
    console.log(`${name}を取得した`);
  }
}

class PaymentProcessor {
  makePayment(name: string) {
    console.log(`${name}の支払いが完了した`);
  }
}

class Invoice {
  sendInvoice(name: string) {
    console.log(`${name}の請求書が送信されました`);
  }
}

class OrderProcessor {
  placeOrder(name: string) {
    console.log('注文開始');

    const product = new Product();
    product.getProduct(name);

    const payment = new PaymentProcessor();
    payment.makePayment(name);

    const invoice = new Invoice();
    invoice.sendInvoice(name);

    console.log("注文は正常に管理用した")
  }
}
