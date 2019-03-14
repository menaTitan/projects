/*
GAME RULES:
- The game has 2 players, playing in rounds
- In each turn, a player rolls a dice as many times as he whishes. Each result get added to his ROUND score
- BUT, if the player rolls a 1, all his ROUND score gets lost. After that, it's the next player's turn
- The player can choose to 'Hold', which means that his ROUND score gets added to his GLBAL score. After that, it's the next player's turn
- The first player to reach 100 points on GLOBAL score wins the game
*/

var scores, roundScores, activePlayer;
init();


 //dice = Math.floor(Math.random() * 6) + 1;
//document.querySelector("#current-" + activePlayer).textContent = dice;


document.querySelector('.btn-hold').addEventListener('click',function(){
    // add Current score to global score
    scores[activePlayer] += roundScores;
    document.getElementById("score-" + activePlayer ).innerHTML  = scores[activePlayer];
    // check if the player won the game 
     checkIfPlayerWon();
     nextPlayer();
});
document.querySelector('.btn-roll').addEventListener('click',function(){
     document.querySelector(".player-"+activePlayer+"-panel").classList.add('active');
    
    //1.Random number
    var dice = Math.floor(Math.random() * 6) + 1;
    //2.Display the result
    var diceDOM= document.querySelector('.dice');
    diceDOM.src = 'dice-' + dice + '.png';
    diceDOM.style.display ='block';
    //3.update the round score IF the rolled number was not a 1
    if(dice == 1 ){
        nextPlayer();
    }else{
        //document.querySelector(".player-"+activePlayer+"-panel").classList.toggle('active');
        document.querySelector('.dice').style.display = 'block';
        roundScores +=dice;
        document.querySelector("#current-" + activePlayer).textContent = roundScores;
   
    }
});
document.querySelector(".btn-new").addEventListener('click',init);

function nextPlayer(){
    document.querySelector("#current-" + activePlayer).textContent = 0;
        document.querySelector(".player-0-panel").classList.toggle('active');
        document.querySelector(".player-1-panel").classList.toggle('active');
        document.querySelector('.dice').style.display = 'none';
        activePlayer === 0 ? activePlayer = 1 : activePlayer = 0; 
        roundScores = 0;
         // document.querySelector(".player-"+activePlayer+"-panel").classList.add('active');
}
function checkIfPlayerWon(){
      if(scores[activePlayer] >= 20){
          var displayWinner = activePlayer + 1; 
         document.querySelector("#name-" + activePlayer).textContent= "Player " + displayWinner + " won the game! ";
         document.querySelector(".dice").style.display = 'none';
         document.querySelector(".player-"+ activePlayer+"-panel").classList.add('winner');
         document.querySelector(".player-"+ activePlayer+"-panel").classList.remove('active');
         document.querySelector('.btn-roll').disabled = true;
         document.querySelector('.btn-hold').disabled = true;
    }else{
        //nextPlayer();
    }
}

function init(){
    scores=[0, 0];
    activePlayer = 0 ;
    roundScores = 0;
document.getElementById("current-0").innerHTML= 0;
document.getElementById("current-1").innerHTML= 0;
document.getElementById("score-0").innerHTML  = 0;
document.getElementById("score-1").innerHTML  = 0;
document.querySelector('.dice').style.display = 'none';
document.querySelector("#name-0").textContent= "Player 1";
document.querySelector("#name-1").textContent= "Player 2";
document.querySelector('.btn-roll').disabled = false;
document.querySelector('.btn-hold').disabled = false;
document.querySelector(".player-0-panel").classList.remove('winner');
document.querySelector(".player-1-panel").classList.remove('winner');
document.querySelector(".player-0-panel").classList.remove('active');
document.querySelector(".player-1-panel").classList.remove('active');
 document.querySelector(".player-"+ activePlayer+"-panel").classList.add('active');
}
/*
switch(dice){
    case 1:
    document.querySelector(".dice").src= "dice-1.png";
    break;
    case 2:
    document.querySelector(".dice").src= "dice-2.png";
    break;
    case 3:
    document.querySelector(".dice").src= "dice-3.png";
    break;
    case 4:
    document.querySelector(".dice").src= "dice-4.png";
    break;
    case 5:
    document.querySelector(".dice").src= "dice-5.png";
    break;
    case 6:
    document.querySelector(".dice").src= "dice-6.png";
    break;
    }




*/






