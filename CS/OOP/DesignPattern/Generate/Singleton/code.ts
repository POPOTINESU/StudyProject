class Logger {
  private static instance: Logger;

  // これで外部から直接インスタンスを生成することができなくなる
  private constructor() {}

  static getInstance() {
    if (!this.instance) {
      this.instance = new Logger();
    }

    return this.instance;
  }

  output(content: string) {
    const now = new Date();
    console.log(`${now.toLocaleString('ja-JP')}: ${content}`);
  }
}
