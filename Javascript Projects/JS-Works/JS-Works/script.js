///////////////////////////////////////
// Lecture: Hoisting

//function 
function calculateAge(year){
    console.log(2016-year);
}
//retirement(1990);
var retirement = function(year){
    console.log(65-(2016-year));
}
// variable 
console.log(age);
var age =23;

function foo(){
    //console.log(age);
    var age = 65;
    console.log(age);
}
foo();
console.log(age);
//**NOTE**//
/*
Scoping answer the question "where can we access a certain variable? "
*Each new function Creates a scope: the space/ environment, in which the variables it defines are the accessible.
*Lexical scoping: a function  that is lexically within another function gets access to the scope of the outer function.
*/















///////////////////////////////////////
// Lecture: Scoping


// First scoping example


var a = 'Hello!';
first();

function first() {
    var b = 'Hi!';
    second();

    function second() {
        var c = 'Hey!';
        console.log(a + b + c);
    }
}




// Example to show the differece between execution stack and scope chain


var a = 'Hello!';
first();

function first() {
    var b = 'Hi!';
    second();

    function second() {
        var c = 'Hey!';
        third()
    }
}

function third() {
    var d = 'John';
    console.log(a  + d);
}




///////////////////////////////////////
// Lecture: The this keyword
/*
#Regular function  call: the this is keyword points at the global object
(the windows object, in the browser).
#Merhod Call:The this variable points to the object that is calling the method.
 * the this keyWorld is not assigned a value until a function where it is defined is actually called/
*/
/*
calculateAge(1985);
function calculateAge(Year){
    console.log(2016 - Year);
    console.log(this);
}
*/


var john = {
    name:'John',
    yearOFBirth: 1990,
    calculateAge: function(){
    console.log(this);
    console.log( 2016 -this.yearOFBirth)
        /*
        function innerFunction(){
            console.log(this);
        }
        innerFunction();
        */
    } 
}
john.calculateAge();

var mike={
    name : "Mike",
    yearOFBirth: 1984
};
//method barwing 

mike.calculateAge = john.calculateAge;  
mike.calculateAge();









