interface stack {
  peekLast(): any;
  pop(): any;
  push(value: any): void;
}

interface queue {
  peekFirst(): any;
  pool(): any;
  push(value: any): void;
}

class Dequeue implements stack, queue {
  // 今回はArrayで作成
  private dequeue: Array<any>;
  peekLast() {
    if (this.isEmpty()) return null;

    return this.dequeue[this.dequeue.length - 1];
  }

  peekFirst() {
    if (this.isEmpty()) return null;
    return this.dequeue[0];
  }
  pop() {
    if (this.isEmpty()) return null;
    return this.dequeue.pop();
  }

  pool() {
    if (this.isEmpty()) return null;
    this.dequeue = this.dequeue.slice(1);
    return this.dequeue.shift();
  }

  push(value: any): void {
    this.dequeue.push(value);
  }

  private isEmpty(): boolean {
    return this.dequeue.length == 0;
  }
}
