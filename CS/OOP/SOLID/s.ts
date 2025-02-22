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
