const form=document.getElementById("myForm");
const fname=document.getElementById("fname");
const lname=document.getElementById("lname");

form.addEventListener("submit",(event)=>{
    event.preventDefault();
    const firstNameDiv=document.createElement("div")
    firstNameDiv.textContent=fname.value+" "+lname.value;
    firstNameDiv.className="firstName";
    document.body.appendChild(firstNameDiv);
})



