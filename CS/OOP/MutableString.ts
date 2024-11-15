class MutableString {
  str: Array<string>;

  constructor(string: string) {
    this.str = [string];
  }

  append(addString: string) {
    this.str.push(addString);
  }

  substring(start: number) {
    if (start >= this.str.length) {
      throw new Error("Index out of range");
    }
    return this.str.slice(start, this.str.length).join("");
  }

  concat(strArr: Array<string> | MutableString) {
    if (strArr instanceof MutableString) {
      strArr = strArr.str;
    }
    this.str = this.str.concat(strArr);
    console.log(this.str)
    return this.str.join("");
  }
}

const n: MutableString = new MutableString("aaa");
// console.log(n.substring(1));

const m: MutableString = new MutableString("bbb");
console.log(n.concat(m));
