var Stack = /** @class */ (function () {
    function Stack() {
        this.storage = {};
        this.count = 0;
    }
    Stack.prototype.pop = function () {
        if (this.count == 0)
            return undefined;
        var result = this.storage[this.count];
        delete this.storage[this.count];
        this.count--;
        return result;
    };
    Stack.prototype.push = function (value) {
        this.storage[this.count] = value;
        this.count++;
    };
    Stack.prototype.size = function () {
        return this.count;
    };
    Stack.prototype.peek = function () {
        return this.storage[this.count - 1];
    };
    Stack.prototype.show = function () {
        for (var i = 0; i < this.size(); i++) {
            console.log("[" + i + "] : " + this.storage[i]);
        }
    };
    return Stack;
}());
(function () {
    var s = new Stack();
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
