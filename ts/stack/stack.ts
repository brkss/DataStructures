class Stack {
  private storage: any = {};
  private count: number = 0;

  pop() {
    if (this.count == 0) return undefined;

    let result = this.storage[this.count];
    delete this.storage[this.count];
    this.count--;
    return result;
  }

  push(value: any) {
    this.storage[this.count] = value;
    this.count++;
  }

  size() {
    return this.count;
  }

  peek() {
    return this.storage[this.count - 1];
  }

  show() {
    for (let i = 0; i < this.size(); i++) {
      console.log(`[${i}] : ${this.storage[i]}`);
    }
  }
}

(() => {
  let s = new Stack();
  s.push(5);
  s.push(22);
  s.push(1);
  s.show();
  s.pop();
  console.log("================");
  s.show();
  console.log("stack peek : ", s.peek());
  console.log("stack size : ", s.size());
})();
