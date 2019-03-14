/*Everything is a object
*Object-oriented programming 
    => object interacting with one another through methods and properties;
    => Used to store data, structure application into modules and keeping code clean.
    => From  a constructor we can create many  instances
    => Inheritance is one object based on another object 
    => Also, inheritance is based upon object's properties and methods
    => JavaScript is Prototypes and prototype chains
    => Inheritance works by using prototypes.Prototypes makes inhertinace possible .
    => every object we create is a instinace of object constructor.
    =>prototype chain what makes inheritance possible 
*Summary
    => Every JavaScript object has a prototype property,which makes inheritance possible in JavaScript.
    => the prototype property of an object is where we put methods and properties that we want other object to inherit.
    => the Constructor's prototype property is NOT the protoype of the Constructor itself, it's the prototype of all instance that are created through it.
    => when a certin method (or property) is called, the search start in the object itself, and it cannnot be found, the search moves on to the object's prototype.This continues until the method is found: prototype chain. 
    */

 //Function constructor
var john = {
    name: 'John',
    yearOfBirth : 1990,
    jon : 'teacher' 
};

//Function constructor
/*
var Person = function (name, yearOfBirth, job){
    this.name = name;
    this.yearOfBirth = yearOfBirth;
    this.job = job;

   // this.calculateAge = function(){
      //  console.log(2016 - this.yearOfBirth);
   // }
}


Person.prototype.lastName= 'Mena';
Person.prototype.calculateAge = function(){
        console.log(2016 - this.yearOfBirth);
};
var john = new Person('John',1990, 'teacher');
var jane = new Person('Jane', 1969, 'desinger');
jane.calculateAge();
john.calculateAge();

console.log(jane.lastName);
console.log(john.lastName);
*/
/*
//Object.Create
var personProto = {
    calculateAge: function(){
        console.log(2016 - this.yearOfBirth);
    }
};
var john = Object.create(personProto);

john.name ='Mena';
john.yearOfBirth = 1992;
john.job = 'teacher';
console.log(john.calculateAge());
var jane = Object.create(personProto, 
{
    name : {value : 'jane'},
    yearOfBirth:{ value : 1969};
    job : {value : 'desinger'}
});
*/


// Primitives vs objects
//perimitive
var a = 23;
var b = a;
a=46;
console.log(a);
console.log(b);

var object1= {
    name : 'Mena',
    age  : 24 ,
    job  : "teacher"
};

var object2 = {
    name : 'John',
    age : 29,
    job : "desinger"
}
// object 
object2 = object1; 

object1.age = 30;
console.log(object2)
/*
    ****objecNOte on function ****
* A Function is an instance of the object type.
* A function behaves like any  other object.
* We can store functions in a veriable.
* We can  pass a function as an argument to another function
* We can return a function from  a function 

*/

var years = [1990, 1965, 1937,2005, 1998];
function arrayCalc(arr, fn){
    var arrRes = [];
    for(var i =0 ; i < arr.length; i++){
        arrRes.push(fn(arr[i]));
    }
    return arrRes;
}

function calculateAge(element){
    return 2016-element;
}
function MaxHeartRate(el){
    if(isFullage(el)){
        return Math.round(206.9 - (0.67 * el));
    }else{
        return -1;
    }
}
function isFullage(limit,el){
    return el >= limit;
}
var ages = arrayCalc(years, calculateAge);
console.log(ages);
var fullAges = arrayCalc(ages, isFullage.bind(this,18));
console.log(fullAges);
var heartRateAge= arrayCalc(ages, MaxHeartRate);
console.log(heartRateAge);

//using the bind on  isFullage
console.log("this is Japan Full age function");
var japanFullAge = arrayCalc(ages, isFullage.bind(this,20));
console.log(japanFullAge);





////////////////////////////////////////////
//Lecture: Functions returning function 
function interviewQuestion(job){
    if (job === 'designer'){
        return function(name){
            console.log(name + ", can you please explain what UX design is ?");
        }
    }else if (job === 'teacher'){
        return function(name){
            console.log("What subject do you teach, " + name + "?");
        }
    }else {
        return function(name){
            console.log("Hello "+ name + ", what do you do? ");
        }   
    }          
}
var teacherQuestion= interviewQuestion ("teacher");
teacherQuestion("lolo");

//another way for calling function returning function 
interviewQuestion("designer")("John");

////////////////////////////////////////
//lecture: IIFE immediately invoked function expression

function game(){
    var score = Math.random() * 10
    console.log(score >=5);
}
game();

//the same thing as the top  function, but with IIFF implemtation 
(function(){
    var score = Math.random() * 10 ;
    console.log(score >= 5);
})();

(function(goodLuck){
    var score = Math.random() * 10 ;
    console.log(score >= 5);
})(3);

//////////////////////////////////////////
//Lecture: closures  

function retirement(retirementAge){
    var a = ' year left untill  retirement. ';
    return function(yearOfBirth){
        var age = 2016- yearOfBirth;
        console.log(retirementAge - age + a);
    }
}

var retirementUS = retirement(66);
retirementUS(1990);
var retirementGermany = retirement(65)(1990); 
/*
**CLOSURES SUMMARY**
*An inner function has always access to the variable and parameters of its outer function,
even after the outter function has returned.
*/

function interviewQuestionWithClosures(job){
    return function(name){
        if(job === "designer"){
            console.log(name + ", can you please explain what UX design is ?");
        }else if(job === "teacher"){
            console.log("What subject do you teach, " + name + "?");
        }else{
            console.log("Hello "+ name + ", what do you do? ");
        }
    }
}

interviewQuestionWithClosures("teacher")("Abanob");
///////////////////////////////////////////////////////
/*Bind, call and apply*/
var john = {
    name: 'John',
    age: 26,
    job: 'teacher',
    presentation: function (style, timeOfDay){
        if(style === 'formal'){
            console.log('Good ' + timeOfDay + ', Ladies and gentlemen! I\'m ' +this.name + ', I\'m a ' + this.job + 'and I\'m ' + this.age + ' years old.')
        }else if(style === 'friendly'){
            console.log('Hey! what\'s up? I\'m ' +this.name + ', I\'m a '  + this.job + 'and I\'m ' + this.age + ' years old.');
      }
    }
};

john.presentation('formal', 'morning');

var mena = {
    name:'Mena',
    age: 25,
    job:'Programmer'
};
//method borrowing
john.presentation.call(mena,'friendly' , 'afternoon');
//apply method
john.presentation.apply(mena, ['friendly' , 'afternoon']);

//bind method 
var johnFriendly = john.presentation.bind(john,'friendly')('morning');

//other way you can call bild method
var menaFriendly = john.presentation.bind(mena,'formal');
menaFriendly('afternoon');