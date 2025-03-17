score={
    wins:0,
    losses:0,
    tie:0
  };
  function f1(){
    const number = Math.random();
    if (number>0 && number <=1/3){
      computerMove="Rock"
    }
    else if (number>1/3 && number<=2/3) {
      computerMove="Paper"
    } 
    else {
      computerMove="Scissors"
    }

  };

  function f2(playerMove){
    f1()
    if (playerMove=='Rock'){
      if (computerMove=='Rock'){
        score.tie+=1
        result='tied';
         document.querySelector('.js-comp-move').innerHTML=('Computer Move:<img src="images/rock-emoji.png" class="icon">');
      }
      else if(computerMove='Paper'){
        score.losses+=1
        result='lost'
        document.querySelector('.js-comp-move').innerHTML=('Computer Move:<img src="images/paper-emoji.png" class="icon">');
      }
      else if(computerMove='Scissors'){
        score.wins+=1
        result='won'
        document.querySelector('.js-comp-move').innerHTML=('Computer Move:<img src="images/scissor-emoji.png" class="icon">');
      }
    }

    if (playerMove=='Paper'){
      if (computerMove=='Rock'){
        score.wins+=1
        result='won';
        document.querySelector('.js-comp-move').innerHTML=('Computer Move: <img src="images/rock-emoji.png" class="icon">');
      }
      else if(computerMove='Paper'){
        score.tie+=1
        result='tied'
        document.querySelector('.js-comp-move').innerHTML=('Computer Move:<img src="images/paper-emoji.png" class="icon">');
      }
      else if(computerMove='Scissors'){
        score.losses+=1
        result='lost'
        document.querySelector('.js-comp-move').innerHTML=('Computer Move:<img src="images/scissor-emoji.png" class="icon">');
      }
    }
    if (playerMove=='Scissors'){
      if (computerMove=='Rock'){
        score.losses+=1
        result='lost';
        document.querySelector('.js-comp-move').innerHTML=('Computer Move: <img src="images/rock-emoji.png" class="icon">');
      }
      else if(computerMove='Paper'){
        score.wins+=1
        result='won'
        document.querySelector('.js-comp-move').innerHTML=('Computer Move:<img src="images/paper-emoji.png" class="icon">');
      }
      else if(computerMove='Scissors'){
        score.tie+=1
        result='tied'
        document.querySelector('.js-comp-move').innerHTML=('Computer Move:<img src="images/scissor-emoji.png" class="icon">');
      }
    }
    document.querySelector('.js-score').innerHTML=(`Wins ${score.wins} , Losses ${score.losses} , Ties ${score.tie}`); 
    document.querySelector('.js-result').innerHTML=(`You ${result}`)
  }

  function f3(){
    score={
      wins:0,
      losses:0,
      tie:0
    }
    alert('The score has been reset')
    document.querySelector('.js-score').innerHTML=(`Wins 0 , Losses 0 , Ties 0`)
    document.querySelector('.js-result').innerHTML=('<span> &#8203;</span>')
    document.querySelector('.js-comp-move').innerHTML=('Computer Move:');

  }

document.body.addEventListener('keydown',(keyPressed)=>{
  if (keyPressed.key=='r'){
    f2('Rock')
  }
  else if(keyPressed.key=='p'){
    f2('Paper')
  }
  else if(keyPressed.key=='s'){
    f2('Scissors')
  }
})