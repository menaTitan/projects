/*
(function(){
function Question(question,answers, correct){
    this.question = question;
    this.answers = answers;
    this.correct = correct;
}
Question.prototype.displayQuestion = function() {
    console.log(this.question);
    for(var i = 0; i < this.answers.length; i++ ){
        console.log(i+ ": "+ this.answers[i]);
    }
}

Question.prototype.checkAnswer = function (answer) {
        if(this.correct === answer){
            console.log("Right Answer, good job:)!");
        }else{
            console.log("Try again!");
        }
}
var q1 = new Question('Is JavaScript the coolest programming language in the world ?', ['Yes', 'No'], 0);
var q2 = new Question('What is the name of this course\'s teacher?',['John', 'Micheal', 'Jones'], 2);
var q3 = new Question('What does not describle coding?', ['Boring','Hard','Fun','Tedious'],2);


var question = [q1,q2,q3];

var n = Math.floor(Math.random()*question.length);

question[n].displayQuestion();
var answer = parseInt(prompt("Please select the correct answer"));
question[n].checkAnswer(answer);

})();*/

(function(){
function Question(question,answers, correct){
    this.question = question;
    this.answers = answers;
    this.correct = correct;
}
Question.prototype.displayQuestion = function() {
    console.log(this.question);
    for(var i = 0; i < this.answers.length; i++ ){
        console.log(i+ ": "+ this.answers[i]);
    }
}

Question.prototype.checkAnswer = function (answer,callBack) {
    var sc;
        if(this.correct === answer){
            console.log("Right Answer, good job:)!");
            sc = callBack(true);
        }else{
            console.log("Try again!");
            sc= callBack(false);
        }
    this.displayScore(sc);
}

Question.prototype.displayScore = function(score){
    console.log('Your current score is: '+ score);
    console.log('--------------------------------------');
}
var q1 = new Question('Is JavaScript the coolest programming language in the world ?', ['Yes', 'No'], 0);
var q2 = new Question('What is the name of this course\'s teacher?',['John', 'Micheal', 'Jones'], 2);
var q3 = new Question('What does not describle coding?', ['Boring','Hard','Fun','Tedious'],2);

function score (){
    var sc  = 0;
    return function(correct){
        if(correct){
            sc++;
        }
        return sc;
    }
}    
 var calcScore = score(); 
function nextQuestion(){
var question = [q1,q2,q3];
var n = Math.floor(Math.random()*question.length);
question[n].displayQuestion();
var answer = prompt("Please select the correct answer");
    if(answer !== 'exit'){
       question[n].checkAnswer(parseInt(answer),calcScore);
        //console.log(totalScore);
        nextQuestion();
    }
} 
    nextQuestion();
})();
