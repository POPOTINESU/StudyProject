interface Stack<T> {
  peekLast(): T | null;
  pop(): T | null;
  push(value: T): void;
}

interface Queue<T> {
  peekFirst(): T | null;
  pool(): T | null;
  push(value: T): void;
}

class Dequeue<T> implements Stack<T>, Queue<T> {
  // 今回はArrayで作成、型はTにする
  private dequeue: T[] = [];

  peekLast(): T | null {
    if (this.isEmpty()) return null;
    return this.dequeue[this.dequeue.length - 1];
  }

  peekFirst(): T | null {
    if (this.isEmpty()) return null;
    return this.dequeue[0];
  }

  pop(): T | null {
    if (this.isEmpty()) return null;
    return this.dequeue.pop()!;
  }

  pool(): T | null {
    if (this.isEmpty()) return null;
    return this.dequeue.shift()!;
  }

  push(value: T): void {
    this.dequeue.push(value);
  }

  private isEmpty(): boolean {
    return this.dequeue.length === 0;
  }
}

const dequeue = new Dequeue<number>();
dequeue.push(10);
console.log(dequeue.peekLast());
