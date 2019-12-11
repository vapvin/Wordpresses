function Obj(arg, seg, trg) {
    this.arg = arg;
    this.seg = seg;
    this.trg = trg;
}

Obj.prototype.say = function () {
    return "Test";
}

const objective = new Obj(3, 7, 8);

console.log(objective.arg);
console.log(objective.seg);
console.log(objective.trg);
console.log(objective.say());