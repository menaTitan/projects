// Lecture : let and const 

//ES5
/*
var  name5  = 'Jane Smith';
var age5 = 23;
name5 = 'Jane Miller';
console.log(name5);
*/
//ES6
/*
const name6 = 'Jane Smith';
let age6 = 23;
name6 = 'Jane Miller';
console.log(name6);
*/
//ES5
function deriverLicence5(passedTest){
   if(passedTest){
       var firstName = 'John';
       var yearOfBirth = 1990;
       console.log(firstName + ', born in '+ yearOfBirth + ', is now offically allowed to drive a car.');
   } 
}
deriverLicence5(true);
//ES6
function deriverLicence6(passedTest){
   if(passedTest){
       // let and const is block scope 
       let firstName = 'John';
       const yearOfBirth = 1990;
       console.log(firstName + ', born in '+ yearOfBirth + ', is now offically allowed to drive a car.');
   } 
}
deriverLicence6(true);

/////////////////////////////////////////
///lecture : Block and IIFES 
{
    //data inside the block is not accessble 
    const a = 1;
    let   b = 2;    
}
// this is going  to throw a error because the variable is not defind
//console.log(a + b)
//ES5 IFF
(function (){
    var c = 3;
})();
//console.log(c);


///////////////////////////////////
//Lecture Strings 
let firstName ='john';
let lastName = 'Smith';
const yearOfBirth = 1990;

function calcAge(year){
    return 2018 - year;
}
//ES5
console.log('This is '+ firstName + lastName + calcAge(yearOfBirth));

//ES6
console.log(`this is ${firstName} ${lastName}`);
const n = `${firstName}${lastName}`;
console.log(n.startsWith('hn'));
console.log(n.endsWith('MS'));
console.log(n.includes('hn'));
console.log(`${firstName} `.repeat(10));

////////////////////////////////
//Lecture arrow functions
const years = [1990, 1965,1982,1937];
//ES5
var ages5 = years.map(function(current, index, array){
    return calcAge(current);  
});
console.log(ages5);

//ES6
var ages = years.map(current => calcAge(current));
console.log(ages);
ages = years.map((cur, index) => `${cur}+${index}`);
console.log(ages);
//with more code add curly braces
ages = years.map((current,index) => {
    const now = new Date().getFullYear();
    const age = now - current;
    return `age element${index + 1} : ${age}`;
});
console.log(ages);
/////////////////////////////////////////
//lecture more arrow function 

//ES5 
/*
var box5 = {
     color : 'green',
     position : 1,
     clickMe : function(){
            var self = this;
            document.querySelector('.green').addEventListener('click', function(){
             var str = "This is box number " + self.position + " and it is " + self.color;  
             alert(str);
         });
     }
}
box5.clickMe();
*/
//ES6
const box6 = {
     color : 'green',
     position : 1,
     clickMe : function(){
             document.querySelector('.green').addEventListener('click',() => {
             var str = "This is box number " + this.position + " and it is " + this.color;  
             alert(str);
         });
     }
}
box6.clickMe();
/*
const box66 = {
     color : 'green',
     position : 1,
     clickMe : ()=> {
             document.querySelector('.green').addEventListener('click',() => {
             var str = "This is box number " + this.position + " and it is " + this.color;  
             alert(str);
         });
     }
}
box66.clickMe();
*/

function Person(name){
    this.name = name;
} 
//ES5 
Person.prototype.myFriends5 =
    function(friends){
    var arr = friends.map(function(el){
        return  this.name + ' is friends with ' + el;
    }.bind(this));
    console.log(arr);
}

var friends = ['Bob','Jane','Mark'];
new Person('John').myFriends5(friends);

//ES6
Person.prototype.myFriends6 = function(friends){
    var arr = friends.map((el) => this.name + ' is friends with ' + el);
    console.log(arr);
}
new Person('Mena').myFriends6(friends);
///////////////////////////////////////////////
//Lecture: Destructuring 
//ES5
var john = ['John', 26];
//var name = john[0];
//var age = john[1];

//ES6
const[name,age] = ['John',26];
console.log(name);
console.log(age);
const obj = {
    firstNames : 'John',
    lastNames : 'Smith'
}
const {firstNames,lastNames} = obj;
console.log(firstNames);
console.log(lastNames);
//we can change the varaible name

const{firstNames : a, lastNames : b} = obj;
console.log(a);
console.log(b);
////////////////////////
//function that use Destructuring
function calcAgeRetirement(year){
    const age = new Date().getFullYear() - year;
    return[age, 65-age];
}
const [agess, retirement] = calcAgeRetirement(1992);
console.log(agess);
console.log(retirement);

//////////////////////////////////////////////
//Lecture: Arrrays 
const boxes = document.querySelectorAll('.box');
//ES5
/*
var boxesArr5 = Array.prototype.slice.call(boxes);
console.log(boxesArr5);
boxesArr5.forEach(function(cur){
    cur.style.backgroundColor = 'dodgerblue';
});
*/
//ES6
//conver boxesArr6 to a array 
const boxesArr6 = Array.from(boxes);
boxesArr6.forEach((cur)=>cur.style.background = "dodgerblue");

//ES5
/*
for(var i = 0; i< boxesArr6.length; i++){
    if(boxesArr6[i].className === 'box blue') continue;
    boxesArr6[i].textContent = "I'm blue!";
}
*/
//ES6
//in for loop we can user break and  continue
for(const cur of boxesArr6){
    if(cur.className.includes('box blue')) continue;
    cur.textContent = "I'm changed value";
}
var agesss = [12,17,8,21,14,11];
var full = agesss.map(function(cur){
    return cur >= 18;
});
console.log(full);
console.log(full.indexOf(true));
console.log(agesss[full.indexOf(true)]);

//ES6
console.log(agesss.findIndex(cur => cur>=18));
console.log(agesss.find(cur => cur >= 18));

///////////////////////////////////////////////
//Lecture: Spread operator takes an array transforms it into single values
function addFourAges(a,b,c,d){
    return a+b+c+d;
}
var sum1 = addFourAges(18,30,12,21);
console.log(sum1);
//ES5
var agesArray = [18,30,12,21];
var sum2 = addFourAges.apply(null,agesArray);
console.log(sum2);
//ES6
const max3 = addFourAges(...agesArray);

const familySmith = ['John','Jane','Mark'];
const familyMiller = ['Mary', 'Bob', 'Ann'];
const bigFamily = [...familySmith,'Lily',...familyMiller];

console.log(bigFamily);

const h = document.querySelector('h1');
const boxess = document.querySelectorAll('.box')
console.log(boxess);
const all = [h,...boxess];
console.log(all);
//conver all into a array 
Array.from(all).forEach(cur => cur.style.color = 'purple');
////////////////////////////////////
//Lecture: Rest parameters 

//ES5
/*
function isFullAges5(){
    console.log(arguments);
    //converting the arguments to an array
    var argsArr = Array.prototype.slice.call(arguments);
    argsArr.forEach(function(cur){
        console.log (2016 - cur >= 18);
    })
}
isFullAges5(1990, 1999, 1965);
//ES6
function isFullAges6(...years){
    years.forEach(cur => console.log(2016 -cur >= 18));
}
isFullAges6(1990, 1999, 1965);
*/
//we adding extra argument to the parameters  
function isFullAges5(limit ){
    console.log(arguments);
    //converting the arguments to an array
    var argsArr = Array.prototype.slice.call(arguments,1);
    argsArr.forEach(function(cur){
        console.log (2016 - cur >= limit);
    })
}
isFullAges5(21,1990, 1999, 1965);
//ES6
function isFullAges6(limit,...years){
    years.forEach(cur => console.log(2016 -cur >= limit));
}
isFullAges6(12,1990, 1999, 1965);
///////////////////////////////////////////////////////
//Lecture: Default Parameters 
/*
//ES5
function SimthPerson(firstName,yearOfBirth,lastName,nationality){
    //*=> note to remember = luck is when opportunity meets with preparation 
    //*=>  note to remember = good luck is hard to come by, but when i work hard i find I'm much more susceptible to experience luck 
    this.firstName = firstName;
    this.yearOfBirth = yearOfBirth;
    this.lastName = lastName === undefined ? lastName = 'Smith': lastName;
    this.nationality = nationality === undefined ? nationality = 'American': nationality ;
}
*/
//ES6
function SimthPerson(firstName, yearOfBirth, lastName='Smith', nationality = 'American'){
    this.firstName = firstName;
    this.yearOfBirth = yearOfBirth;
    this.lastName = lastName;
    this.nationality = nationality;
}
var john = new SimthPerson('John',1990);
var emily = new SimthPerson ('Emily', 1983, 'Diaz', 'Spanish');
////////////////////////////////////////////////////
//Lecture: Maps
const question = new Map();
question.set("question", "what is the offical name of the latest major Javascript version ?");
question.set(1,"ES5");
question.set(2,"ES6");
question.set(3,"ES2015");
question.set(4,"ES7");
question.set("correct", 3);
question.set(true,"Correct answer :D ");
question.set(false,"Wrong, please try again!");
console.log(question.get('question'));
console.log(question.size);

if(question.has(4)){
   // question.delete(4);
    console.log("Answer 4 is here");
}else{
 console.log("it is arleady deleted");   
}
question.forEach((value, key) => console.log(`This is the ${key}, and this is the value ${value}`));

//deconstruction 
  console.log("Destructuring**************************8888");
for(let[key,value] of question.entries()){
    if(typeof(key) === 'number'){
         console.log(`This is the ${key}, and this is the value ${value}`)
    }
   
}

//const ans = parseInt(prompt('Write the correct answer '));
//console.log(question.get(ans === question.get('correct')));

//////////////////////////////////////////////////
//Lecture: Classes

//ES5
/*
var person5 = function(name, yearOfBirth, job){
    this.name = name;
    this.yearOfBirth = yearOfBirth;
    this.job = job;
}
person5.prototype.calculateAge = function(){
    var age = new Date().getFullYear() - this.yearOfBirth;
    console.log(age);
}

var john5 = new person5('John',1996,'developer');
john5.calculateAge();

//ES6
class Person6{
    constructor(name, yearOfBirth,job){
        this.name = name;
        this.yearOfBirth = yearOfBirth;
        this.job = job;
    }
    calculateAge(){
        var age = new Date().getFullYear() - this.yearOfBirth;
        console.log(age);
    }
    static greeting(){
        console.log('Hey there !');
    }
}

const john6 = new Person6('Mena',1998,'teacher');
john6.calculateAge();
Person6.greeting();
*/
///////////////////////////////////////////////////////////
//Lecture: Classs and subclasses 

var person5 = function(name, yearOfBirth, job){
    this.name = name;
    this.yearOfBirth = yearOfBirth;
    this.job = job;
}
person5.prototype.calculateAge = function(){
    var age = new Date().getFullYear() - this.yearOfBirth;
    console.log(age);
}
var Athlete5 = function(name, yearOfBirth, job, olymicGames, medals){
    person5.call(this, name, yearOfBirth, job);
    this.olymicGames = olymicGames;
    this.medals = medals;
}
Athlete5.prototype = Object.create(person5.prototype);
Athlete5.prototype.wonMedal = function(){
    this.medals++;
    console.log(this.medals);
}
var johnAthlete5 = new Athlete5('John', 1990, 'swimmer', 3, 10 );
console.log(johnAthlete5);
johnAthlete5.calculateAge();
johnAthlete5.wonMedal();



class Person6{
    constructor(name, yearOfBirth,job){
        this.name = name;
        this.yearOfBirth = yearOfBirth;
        this.job = job;
    }
    calculateAge(){
        var age = new Date().getFullYear() - this.yearOfBirth;
        console.log(age);
    }
}

class Athlete6 extends Person6{
    constructor (name, yearOfBirth,job, olympicGames,medals){
        super(name, yearOfBirth,job);
        this.olymicGames = olympicGames;
        this.medals = medals;
    }
    wonMedal(){
        this.medals++;
        console.log(this.medals);
    }
}
const johnAthlete6 = new Athlete6('John', 1989, 'swimmer', 3, 10 );
johnAthlete6.calculateAge();
johnAthlete6.wonMedal();