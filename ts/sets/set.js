var MySet = /** @class */ (function () {
    function MySet() {
        this.collection = [];
    }
    MySet.prototype.has = function (v) {
        return this.collection.findIndex(function (x) { return x == v; }) !== -1;
    };
    MySet.prototype.values = function () {
        return this.collection;
    };
    MySet.prototype.add = function (v) {
        if (!this.has(v)) {
            this.collection.push(v);
            return true;
        }
        return false;
    };
    MySet.prototype.remove = function (v) {
        if (this.has(v)) {
            delete this.collection[this.collection.findIndex(function (x) { return x == v; })];
            return true;
        }
        return false;
    };
    return MySet;
}());
