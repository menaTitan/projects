 //creating budget module 
var budgetController = (function(){
    var Expense = function (id , description, value){
        this.id = id;
        this.description = description;
        this.value = value; 
        this.percentage = -1;
        
    };
    Expense.prototype.calcPercentage = function(totalIncome){
        this.percentage = totalIncome >  0 ? Math.round((this.value / totalIncome) * 100) : -1;
    };
    Expense.prototype.getPercentage = function(){return this.percentage};
    var Income = function (id , description, value){
        this.id = id;
        this.description = description;
        this.value = value;
    };
    var calculateTotal = function(type){
        var sum = 0;
        data.allItems[type].forEach(function(current, index, index){
            sum += current.value;
        });
        data.totals[type] = sum;
    }; 
    var data = {
        allItems : {
            exp : [],
            inc : [] 
        },
        totals: {
            exp : 0,
            inc : 0
        },
        budget : 0,
        percentage : -1 
    };
    
    return {
        addItem: function(type,des, val){
            var newItem, Id;
            //create new id
             Id = data.allItems[type].length > 0 ? (data.allItems[type][data.allItems[type].length - 1].id )+ 1 : 0;
            //creating new item based on 'inc' or 'exp' type.
            newItem =  type === 'exp' ? new Expense (Id , des , val) : new Income (Id , des , val);
            //push it into our data structure
            data.allItems[type].push(newItem);
            //return the new element
            return newItem;
        },
        calculatePercentages: function(){
            data.allItems['exp'].forEach(function(current){
                current.calcPercentage( data.totals.inc);
            });
        },
        getPercentages: function(){
            var allperc = data.allItems.exp.map(function(current){
                return current.getPercentage();
            });
            return allperc;
        },
        deleteItem : function(Id, type){
            var ids, index;
            
            data.allItems[type].forEach(function(current, index){
                if(current.id === Id){
                    console.log("this the value: id  " )
                  data.allItems[type].splice(index,1);
                }
            });
            
            /* the same thing as the top forEach
                id = 6
                data.allItem[type][id];
                index = 3
            */
            /*
            var ids = data.allItems[type].map(function(current){
                return current.id;
            });
           
            index = ids.indexOf(Id);
             console.log(index);
            if(index !== -1){
                console.log('inside the splice');
               data.allItems[type].splice(index,1);
            }
            */
        },
        calculateBudget: function (){
            //calculate total income and expenses
            calculateTotal('exp');
            calculateTotal('inc');
            //calculate the budget: income - expenses
            data.budget = data.totals.inc - data.totals.exp;
            //calcaute the percentage of income that we spent 
            if(data.totals.inc > 0){
                data.percentage = Math.round((data.totals.exp/ data.totals.inc) * 100 );
            }else{
                data.percentage = -1;
            }
        },
        getBudget : function(){
            return {
                budget : data.budget,
                totalInc : data.totals.inc,
                totalExp : data.totals.exp,
                percentage : data.percentage
            }
        },
        //for testing only 
        displyData : function(){
            for(var i = 0 ; i < data.allItems['inc'].length; i++){
                console.log(data.allItems['inc'][i]);
            }
        }
        
    }
        

})();

//creating UI controller
var UIController = (function (){
    var DOMStrings = {
        inputType   : '.add__type',
        inputDescription : '.add__description',
        inputValue  : '.add__value',
        inputBtn    : '.add__btn',
        incomeContainer : '.income__list',
        expensesContainer : '.expenses__list',
        budgetLabel  :'.budget__value',
        incomeLabel: '.budget__income--value',
        expensesLabel : '.budget__expenses--value',
        procentageLabel : '.budget__expenses--percentage',
        container  : '.container',
        expensePercLabel: '.item__percentage',
        dateLabel : '.budget__title--month'
    };
     var nodeListForEach = function(list, callback){
                for(var i= 0; i < list.length; i++){
                    callback(list[i], i);
                }
            };
    return{
        getInput : function (){
               //return object of values from the dom 
              return{
              //The value of type will have one of two: inc or exp.
             type : document.querySelector(DOMStrings.inputType).value,
             description :document.querySelector(DOMStrings.inputDescription).value,
             amount : parseFloat(document.querySelector(DOMStrings.inputValue).value)
            }
        },
        addListItem: function(obj, type){
            var html, newHtml, element;
        
            //Create HTML string with placeholder text
                        // html for income
             if (type === 'inc'){
                    element = DOMStrings.incomeContainer;
                    html =  '<div class="item clearfix" id="inc-%id%"> <div class="item__description">%description%</div> <div class="right clearfix"> <div class="item__value"> %value% </div> <div class="item__delete"> <button class="item__delete--btn"><i class="ion-ios-close-outline"></i></button> </div> </div> </div> ';
             }else if (type === 'exp'){
                        //html  for expance 
                    element = DOMStrings.expensesContainer; 
                    html=  ' <div class="item clearfix" id="exp-%id%"> <div class="item__description">%description%</div>  <div class="right clearfix"> <div class="item__value"> %value% </div> <div class="item__percentage"> %expPerc% %</div> <div class="item__delete"> <button class="item__delete--btn"><i class="ion-ios-close-outline"></i></button> </div> </div> </div> ';
             }
            // Replace the placeholder text with some actual data
            newHtml = html.replace('%id%', obj.id);
            newHtml = newHtml.replace('%description%',obj.description);
            newHtml = newHtml.replace('%value%', this.formatNumber(obj.value, type));
            
            // Insert the HTML into the DOM 
            document.querySelector(element).insertAdjacentHTML('beforeend', newHtml);
           
        },
        deleteListItem: function(selectorID){
          var el = document.getElementById(selectorID);
            document.getElementById(selectorID).parentNode.removeChild(el);
        },
        displayBudget : function(obj){
            var type = obj.budget >0 ? 'inc' : 'exp';
            document.querySelector(DOMStrings.budgetLabel).textContent = this.formatNumber(obj.budget,type);
            document.querySelector(DOMStrings.expensesLabel).textContent = this.formatNumber(obj.totalExp,'exp');
            document.querySelector(DOMStrings.incomeLabel).textContent = this.formatNumber(obj.totalInc,'inc');
            document.querySelector(DOMStrings.procentageLabel).textContent = obj.percentage >= 0 ? obj.percentage+'%' 
            :'---';
            
        },
        displayPercentages: function(percentages){
            var fields = document.querySelectorAll(DOMStrings.expensePercLabel);
            nodeListForEach(fields, function(current, index){
                current.textContent = percentages[index] >= 0 ? percentages[index]+'%' : '---'; 
            });
        },
        formatNumber: function(num, type){
            var numSplit,int,dec, pre, value, maxIndex, finalNumber;
            var arr = new Array();
            finalNumber = "%";
            /*
              + or - before number 
              exactrly 2 decimal points 
              comma separating the thousands
              ex => 2310.4567 -> + 2, 310.46
            */
            num = Math.abs(num);
            num = num.toFixed(2);
            console.log(num);
            numSplit = num.split('.');
            int = numSplit[0];
            value = int; 
            pre = 0 ;
            maxIndex = 0 ;
            for(var i = 1 ; i <= int.length; i++){
               console.log(i);
                if(i%3 === 0 && i !== 0){
                    console.log("this % " + i);
                    arr.push(value.substr(pre,1)+','+value.substr(pre+1,2));
                    pre = i;
                    maxIndex = i;
                } 
            }
            if(int.length - maxIndex > 0){
                for(var x = maxIndex;  x < int.length; x++){
                    console.log("the number of the index : " + int[x]);
                    arr.push(int[x]);
                }
            }
            //1,234,567,89
            for(var x =0; x < arr.length; x++){
                console.log("this is inside the  array : "+arr[x]);
                finalNumber += arr[x];
            }
            value = finalNumber.substr(1,finalNumber.length-1);
            dec = numSplit[1];
            type === 'exp' ? sign = '-' : sign = '+';
            console.log((type === 'exp' ? '-' : '+') +' '+ value + '.' + dec)
            return(type === 'exp' ? '-' : '+') +' '+ value + '.' + dec;
        },
        getDOMStrings : function () {
            return DOMStrings;
        },
        clearFields : function (){
            var fields ;
            fields = document.querySelectorAll(DOMStrings.inputDescription + ', ' + DOMStrings.inputValue);
            // it helps in converting list into  a array.
            var fieldsArray = Array.prototype.slice.call(fields);
            fieldsArray.forEach(function(current, index, array){
                  console.log("The current value is: " + current.value);
                  console.log("The index value is: " + index.value);
                  console.log("The Array value is: " + array.value);
                 current.value = "" ; 
            });
            //it focus back on description.
            fieldsArray[0].focus();
        },
        displayMonth: function (){
            var date, year, month, monthName;
            date = new Date();
            year = date.getFullYear();
            month = date.getMonth();
            month = parseInt(month);
            monthName =["January","February", "March","April","May","June","July" 
                        ,"August" , "September", "October","November","December"]
            document.querySelector(DOMStrings.dateLabel).innerHTML = monthName[month] + ' '+ year;
        },
        changeTypeColor: function(){
         var fields  =  document.querySelectorAll(DOMStrings.inputType + ',' + DOMStrings.inputDescription + ',' + DOMStrings.inputValue);
            console.log("this is fields: ", fields);
        nodeListForEach(fields, function(cur) {
            cur.classList.toggle('red-focus');
        });
       document.querySelector(DOMStrings.inputBtn).classList.toggle('red');
     }
    };
})();

// creating app controller
var controller = (function(budgetCtrl, UICtrl){ 
    var setupEventListeners = function (){
        var DOMVar = UICtrl.getDOMStrings();
        UICtrl.displayMonth();
        document.querySelector(DOMVar.inputBtn).addEventListener('click' ,ctrlAddItem);
        document.addEventListener('keypress', function(event){
        if(event.keyCode === 13  || event.which === 13){
            ctrlAddItem();
        }
        document.querySelector(DOMVar.container).addEventListener('click',ctrlDeleteItem);    
    });
       document.querySelector(DOMVar.inputType).addEventListener('change',UICtrl.changeTypeColor);
};
    var updateBudget = function(){
        var DOMVal = UICtrl.getDOMStrings();
         //1. Calculate the budget 
         budgetCtrl.calculateBudget();
        // 2. mathod return budget
        var getBudget = budgetCtrl.getBudget();
       //3. display  the budget on the UI
        UICtrl.displayBudget(getBudget);
        
    };

    var updatePercentage = function (){
        var percentages, prec;
      //1. calcuate percentages 
        budgetCtrl.calculatePercentages()
      //2. Read percentages from the budgest controller
         percentages = budgetCtrl.getPercentages();
      //3. update the UI with the new percentages 
        UICtrl.displayPercentages(percentages);
    };
    
    var ctrlAddItem = function(){
        //1. Get the field input data 
        var UICtrlResult = UICtrl.getInput();
        if(UICtrlResult.description !== "" && !isNaN(UICtrlResult.amount)){
       //2. Add the item to the budget controller
        var newItem = budgetCtrl.addItem(UICtrlResult.type, UICtrlResult.description, UICtrlResult.amount);
        budgetCtrl.displyData();
       //3. Add the item to the UI 
        UICtrl.addListItem(newItem,UICtrlResult.type);
       //4. clear fields
        UICtrl.clearFields();
       //5. Calculate the budget  & update budget
        updateBudget();
        //6. update percentage
        updatePercentage();
        }
       
    };
    var ctrlDeleteItem = function(event){
         var itemId, splitId,type,Id;
         itemId = event.target.parentNode.parentNode.parentNode.parentNode.id;
        if (itemId){
            //return array["inc", "1"]
           splitId = itemId.split('-');
            type = splitId[0];
            Id   = parseInt(splitId[1]);
        
            //1. Delete the item from the data structure
            budgetCtrl.deleteItem(Id,type);
            //2. Delete the item from the UI
             UICtrl.deleteListItem(itemId);
            //3. Update and show the new budget
            updateBudget();
            //4.update percentage 
            updatePercentage();
        }
        
        
    };
    //initialize the application
    return{
        init : function (){
        console.log('Application has started. ');
         UICtrl.displayBudget({
                budget : 0,
                totalInc : 0,
                totalExp :  0,
                percentage : -1
         });
        setupEventListeners();
        }
    };
 
})(budgetController, UIController);

controller.init();
