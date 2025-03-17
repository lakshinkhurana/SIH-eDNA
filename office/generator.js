// function makeIterator(start=0,end=Infinity,step=1){
//     let curIndex=start;
//     return {
//         next(){
//             let result=curIndex<end?{value:curIndex,done:false}:{value:undefined,done:true};
//             curIndex+=step;
//             return result;
//         }
//     }
// }
// let myIterator=makeIterator(0,10,2);
// let result=myIterator.next();
// while(!result.done){
//     console.log(result.value);
//     result=myIterator.next();
// }

function* makeIterator(start=0,end=Infinity,step=1){
    for(let i=start;i<end;i+=step){
        yield i;
    }
}

for(const val of makeIterator(0,10,2)){
    console.log(val);
}