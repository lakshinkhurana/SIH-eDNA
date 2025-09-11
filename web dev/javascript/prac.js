// script.js
const text = [
    "Hello, I'm ChatGPT. im just going to type random ass shit to create a new test to see if this works properly or elsegpt sucks",
    "I can help with web development.",
    "Let's learn how to create a typing effect!"
  ];
  
  let line = 0; // To keep track of lines
  let index = 0; // To keep track of characters in a line
  
  const typingSpeed = 100; // Time between each character
  const lineDelay = 1000; // Delay before starting the next line
  
  const typingElement = document.getElementById('typing-effect');
  
  // Function to type each line
  function typeLine() {
    if (line < text.length) {
      if (index < text[line].length) {
        typingElement.innerHTML += text[line][index];
        index++;
        setTimeout(typeLine, typingSpeed); // Call the function recursively for each character
      } else {
        // Start next line after a delay
        line++;
        index = 0;
        typingElement.innerHTML += '\n'; // Add a new line
        setTimeout(typeLine, lineDelay);
      }
    }
  }
  
  // Start typing effect
  typeLine();
  