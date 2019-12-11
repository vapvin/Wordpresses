class Writer {
    constructor(textArg, words, time = 2000) {
        this.textArg = textArg;
        this.words = words;
        this.txt = "";
        this.wordIndex = 0;
        this.time = parseInt(time, 10);
        this.type();
        this.isDeleting = false;
    }

    type() {
        const current = this.wordIndex % this.words.length;

        const fullTxt = this.words[current];

        if (this.isDeleting) {
            this.txt = fullTxt.substring(0, this.txt.length - 1);
        } else {
            this.txt = fullTxt.substring(0, this.txt.length + 1);
        }

        this.textArg.innerHTML = `<span class="txt">${this.txt}</span>`;

        let speed = 200;

        if (this.isDeleting) {
            speed /= 2;
        }

        if (!this.isDeleting && this.txt === fullTxt) {
            speed = this.time;

            this.isDeleting = true;
        } else if (this.isDeleting && this.txt === "") {
            this.isDeleting = false;

            this.wordIndex++;

            speed = 500;
        }

        setTimeout(() => this.type(), speed);
    }
}

document.addEventListener("DOMContentLoaded", isit);

function isit() {
    const textArg = document.querySelector(".txt-type");
    const words = JSON.parse(textArg.getAttribute("data-words"));
    const time = textArg.getAttribute("data-wait");

    new Writer(textArg, words, time);
}