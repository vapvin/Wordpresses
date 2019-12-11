class Human {
    constructor(name, age, gender, country) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.country = country;
    }

    say() {
        return "안녕하세요";
    }
}

const bill = new Human("빌", 21, "남자", "미국");

const {
    name,
    age,
    gender,
    country,
} = bill;

const hello = bill.say();

console.log(bill);
console.log(name);
console.log(age);
console.log(gender);
console.log(country);
console.log(hello);