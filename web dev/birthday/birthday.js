
ScrollReveal().reveal('.potrait1', {
    distance: '100px',
    origin: 'bottom',
    opacity: 0,
    duration: 3000,
    easing: 'ease-in-out',
    scale: 1,
    reset: true,
    mobile: true  
});

ScrollReveal().reveal('.potrait2', {
    distance: '100px',
    origin: 'bottom',
    opacity: 0,
    duration: 3000,
    easing: 'ease-in-out',
    scale: 1,
    reset: true,
    mobile: true
});

ScrollReveal().reveal('.main', {
    distance: '100px',
    origin: 'bottom',
    opacity: 0,
    duration: 1500,
    easing: 'ease-in-out',
    scale: 1,
    reset: true,
    mobile: true  
});

window.addEventListener('scroll', function() {
    var text3 = document.querySelector('.text3');
    var text3Top = text3.getBoundingClientRect().top;
    var text3Height = text3.offsetHeight;
    var windowHeight = window.innerHeight;
  
    if (text3Top <= windowHeight && text3Top + text3Height >= 0) {
      text3.style.animation = 'typing 2s steps(20, end), blink-caret .5s step-end infinite';
    } else {
      text3.style.animation = 'none';
    }
  });

// birthday.js

// Typing effect content
const textContent = `okay so it is your birthday and i have been working on this project for a long long while and it was so tough but again it is you who makes putting in all this effort totally worth it, i can't understand how you have this effect on me it just makes me want to do more and more and i can't stop loving you no matter what. you're the best, i don't know how i'm going to ever live without you. i don't ever want to. you're the prettiest girl i have ever laid my eyes on. you're my princess.`;

const typingElement = document.getElementById('typing-effect');
let index = 0;
const typingSpeed = 50; // Adjust typing speed

function typeText() {
  if (index < textContent.length) {
    typingElement.innerHTML += textContent.charAt(index);
    index++;
    setTimeout(typeText, typingSpeed);
  }
}

window.onload = function() {
  typeText();
};