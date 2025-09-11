const myArray = [];

function f1() {
  const myDate = document.querySelector('.input-date');
  const myElement = document.querySelector('.input');
  const name = myElement.value;
  const date = myDate.value;
  if (name && date) { // Ensure both name and date are not empty
    myArray.push({ Name: name, Date: date });
    myElement.value = '';
    myDate.value = '';
    f2();
  }
}

function deleteElement(index) {
  myArray.splice(index, 1);
  f2();
}

function f2() {
  let list = '';
  for (let i = 0; i < myArray.length; i++) {
    const element = myArray[i];
    let html = `<div class='grid-task'>
                  <div>${element.Name}</div> 
                  <div>${element.Date}</div> 
                  <button class="add-button" onclick="deleteElement(${i})">Delete</button>
                </div>`;
    list += html;
  }
  document.querySelector('.division').innerHTML = list;
}
