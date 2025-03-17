function f1(){
    const inputElement = document.querySelector('.js-input')
    let cost = Number(inputElement.value);
    if (cost<50) {
        console.log('$10 shipping');
        cost=cost+10
        document.querySelector('.js-cost').innerHTML=(`cost = ${cost}`)
    } else {
        console.log('Free shipping')
        document.querySelector('.js-cost').innerHTML=(`cost = ${cost}`)

    }
}

let cartValue = 0

function f2(k){
    cartValue=cartValue+k
    if (cartValue==0 || cartValue<0) {
        cartValue=0;
    }
    document.querySelector('.js-cart-value').innerHTML= `cart value : ${cartValue}`;
    console.log(cartValue)
}
function f3(){
    cartValue=0
    console.log(cartValue)
    document.querySelector('.js-cart-value').innerHTML= `cart value : ${cartValue}`;
}
