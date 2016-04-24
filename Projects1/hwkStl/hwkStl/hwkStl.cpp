/*
Name:Mena Sergeyous
Date:9/21/2015
*/

#include <iostream>
#include<vector>
#include<string>
#include<array>
#include<list>
#include <forward_list>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::array;
using std::list;
using std:: forward_list;
int main(){
	
	
    cout << "---------------------- STL vector ----------------------\n";
    // declare container here
	vector<int> v;
	int input;
    cout << "Enter numbers to store in STL containers (enter a letter to stop)\n";
    // read in integers from STDIN here and store them in the vector
	
	while(cin>>input !='\0'){
	    v.push_back(input);	
	}

	 cout << "There are " <<v.size() << " integers in the vector" << endl;
	
   // print out the contents of the container in the reverse order that they were read in if possible (otherwise print why it's not possible and the contents)
    
	  vector<int>::reverse_iterator it=v.rbegin();
	 while (it != v.rend())
	 {
		 cout<<*it<<endl;
		 ++it;
	 }
	 
	 
	 

    cout << "---------------------- STL array ----------------------\n";
    // declare container here
	 array<int,100>a;
    // copy elements from the vector into this container (in the order that they were entered) 
	 for(unsigned int i=0;i<v.size();i++){
	     
		 a.at(i)= v.at(i);

	 }
    
    cout << "There are " <<  a.size()   << " elements in the array" << endl;
    
    // print out the contents of the container in the reverse order that they were read in if possible (otherwise print why it's not possible and the contents)
    
	for(unsigned int i=v.size();i>0;i--){
	
	      cout<<a.at(i-1)<<endl;
	}
	
	
    cout << "---------------------- STL list ----------------------\n";
    // declare container here
	list<int>l;
    // copy elements from the vector into this container (in the order that they were entered) 
    
    cout << "There are " << l.size()<< " integers in the list" << endl;
	for(unsigned int i=0; i<v.size();i++){
	
	    l.push_back(v.at(i));
	
	}
	 
    // print out the contents of the container in the reverse order that they were read in if possible (otherwise print why it's not possible and the contents)
	 
	  list <int>::reverse_iterator itlist=l.rbegin();
	 while (itlist!= l.rend())
	 {
		 cout<<*itlist<<endl;
		 ++itlist;
	 }
	 
    cout << "---------------------- STL forward_list ----------------------\n";
    // declare container here
	forward_list<int> flist;
    // copy elements from the vector into this container (in the order that they were entered) 
    for(int i=0; i<v.size();i++){
	
	    flist.push_front(v.at(i));
	
	}
    cout << "There are " << ((sizeof(flist)/sizeof(int))* v.size())<< " integers in the forward_list" << endl;

    // print out the contents of the container in the reverse order that they were read in if possible (otherwise print why it's not possible and the contents)
	/*
    cout << "---------------------- STL deque ----------------------\n";
    // declare container here

    // copy elements from the vector into this container (in the order that they were entered) 
    
    cout << "There are " <<          << " integers in the deque" << endl;

    // print out the contents of the container in the reverse order that they were read in if possible (otherwise print why it's not possible and the contents)
    
    cout << "---------------------- STL stack ----------------------\n";
    // declare container here

    // copy elements from the vector into this container (in the order that they were entered) 
    
    cout << "There are " <<          << " integers in the stack" << endl;

    // print out the contents of the container in the reverse order that they were read in if possible (otherwise print why it's not possible and the contents)
    
    cout << "---------------------- STL queue ----------------------\n";
    // declare container here

    // copy elements from the vector into this container (in the order that they were entered) 
    
    cout << "There are " <<          << " integers in the queue" << endl;

    // print out the contents of the container in the reverse order that they were read in if possible (otherwise print why it's not possible and the contents)
    
    cout << "---------------------- STL priority_queue ----------------------\n";
    // declare container here

    // copy elements from the vector into this container (in the order that they were entered) 
    
    cout << "There are " <<          << " integers in the priority_queue" << endl;

    // print out the contents of the container in the reverse order that they were read in if possible (otherwise print why it's not possible and the contents)
    
    cout << "\nCan the number of elements and the contents be printed out in the order that they were entered for associative containers? Why?\n";
    
    // Answer the question here with a cout statement

    
    cout << "\n\n---------------------- Printing out the contents in the ordered entered using iterators ----------------------\n\n";
    
    cout << "---------------------- STL vector ----------------------\n";
    // use STL iterators to print out the values stored in the container if possible (otherwise print out why it's not possible)
    
    cout << "---------------------- STL array ----------------------\n";
    // use STL iterators to print out the values stored in the container if possible (otherwise print out why it's not possible)
    
    cout << "---------------------- STL list ----------------------\n";
    // use STL iterators to print out the values stored in the container if possible (otherwise print out why it's not possible)

    cout << "---------------------- STL forward_list ----------------------\n";
    // use STL iterators to print out the values stored in the container if possible (otherwise print out why it's not possible)
    
    cout << "---------------------- STL deque ----------------------\n";
    // use STL iterators to print out the values stored in the container if possible (otherwise print out why it's not possible)

    cout << "---------------------- STL stack ----------------------\n";
    // use STL iterators to print out the values stored in the container if possible (otherwise print out why it's not possible)
    
    cout << "---------------------- STL queue ----------------------\n";
    // use STL iterators to print out the values stored in the container if possible (otherwise print out why it's not possible)
    
    cout << "---------------------- STL priority_queue ----------------------\n";
    // use STL iterators to print out the values stored in the container if possible (otherwise print out why it's not possible)
    

    cout << "\n---------------------- Determine the unique elements in the vector (using STL algorithms) and print them out ----------------------\n\n";

    // determine the unique elements in the vector (using STL algorithms)
    
    cout << "There are a total of " <<          << " unique integers:\n";

    // print out the unique elements
    */
    return 0;
}