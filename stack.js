class Stack {
    constructor(maxSize) {
      if (isNaN(maxSize)) {
        maxSize = 10;
      }
      this.maxSize = maxSize;
      this.elements = []; 
    }
  
    push(element) {
      if (this.elements.length >= this.maxSize) {
        console.log("Stack Overflow!");
        return;
      }
      this.elements.push(element);
    }
    
    pop() {
      if (this.elements.length == 0) {
        console.log("Stack Underflow!");
        return;
      }
      this.elements.pop();
    }
    
    peek() {
      if (this.elements.length == 0) {
        console.log("Stack is empty.");
        return;
      }
      return this.elements[this.elements.length - 1];
    }
  }
  
  // Mari kita coba
  var tumpukanCD = new Stack(3); // Inisialisasi Stack, maxSize=3
  tumpukanCD.push("Harry Potter"); // Memasukkan Harry Potter
  tumpukanCD.push("Titanic"); // Memasukkan Titanic
  tumpukanCD.push("The Avengers"); // Memasukkan The Avengers
  tumpukanCD.push("Batman"); // Memasukkan Batman. Stack Overflow
  tumpukanCD.peek(); // Dapat The Avengers
  tumpukanCD.pop(); // Buang The Avengers
  console.log(tumpukanCD.peek()); // Dapat Titanic
  tumpukanCD.pop(); // Buang Titanic
  console.log(tumpukanCD.peek()); // Dapat Harry Potter
  tumpukanCD.pop(); // Buang Harry Potter
  console.log(tumpukanCD.peek()); // Dapat Stack Kosong
  tumpukanCD.pop(); // Stack Underflow