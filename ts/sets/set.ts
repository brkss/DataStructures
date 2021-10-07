class MySet {
  private collection: any = [];

  public has(v: any): boolean {
    return this.collection.findIndex((x: any) => x == v) !== -1;
  }

  public values(): any {
    return this.collection;
  }

  public add(v: any): boolean {
    if (!this.has(v)) {
      this.collection.push(v);
      return true;
    }
    return false;
  }

  public remove(v: any): boolean {
    if (this.has(v)) {
      delete this.collection[this.collection.findIndex((x: any) => x == v)];
      return true;
    }
    return false;
  }

  public union(st: MySet): boolean {
    const set = new Set();
    const firstSet = this.values();
    const secondSet = st.values();

    firstSet.forEach((element: any) => {
      set.add(element);
    });

    secondSet.forEach((element: any) => {
      set.add(element);
    });

    return true;
  }
}
