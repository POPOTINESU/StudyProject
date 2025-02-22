// 依存関係が、抽象クラス、具象クラスのみにあり、具象クラス同士に依存関係がない状態が最も柔軟性に優れいている

function print(method: PrintMethod) {
  method.print();
}

interface PrintMethod {
  print();
}

class BPrint implements PrintMethod {
  print() {
    console.log('ああああ');
  }
}

class APrint implements PrintMethod {
  print() {
    console.log('いいいい');
  }
}
