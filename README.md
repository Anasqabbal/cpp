# The Goal of Module00
- ex00 : creat a simple program that takes input as a argument and print it to the user in uppercase format

# what is OOP
objected oriented programming is approach that makes you view your program as objects instead a series of steps, it views it as a group of objects that have certain properties and can take certain actions

## New thing based on C

.<< : insertion opearator.\
.>> : extraction operator.

<< >> : in C you can use them to shift bits and in c++ you can use them for shift bits left and right and also this << as insertion operator to take the data from a stream and\
this operator >> to display data to a stream.

:: scope resolution operator

1. accesse a global var when there is a local var with the same name
2. to define a function outside a class
3. to access a class's static var.
4. in case of multiple inheritance 
5. for namespace


## basic things to know in C++
**name space**: Namespaces allows you to group entities like classes objects and functions under a 
name\
**classes** is an expanded concept of a data structure, instead of holding only the data, it can hold the both data and functions\
you can declare class using the keyword `class`
**object**: is an instantiation of a `class`.\
**member functions**: is operators and functions that are declared as members of a class, the body of member function is analysed after the class declaration. so you can use the data or member that is inside your class in your member function.
- member functions : they have access to data members and other member functions of the class
- you can invoke the member function using the dote operator after the name of your object.
- when a member function is defined with const. it  can be called on a constant object and will not modify the object.

**const member function** is a memer function in its prototype we found the keyword *const* like this\
 `void	displayStatus( void ) const;`

### overloaded functions

the overloaded functions reduce the number of functions names to be remembered.
with overloading you can several functions with the same name but with different parameters

### constructor 
A constructor is a member function that is executed automatically whenever an object is created. the constructor its name like the class name.

### destructor



# STDIO STREAM

### stream
out context of programming you can imagine it is like flowing of water from a side to another one, but in the contex of programming it means the flows of data also from the side to another one

**stdio streams**: is a c++ way of formating input and output to a variety of sources, including the console, files, and string buffer.

### console
the console is the manner that the user uses to interact with the system programs of the OS or with another console applications.
the interaction consist of the text input from the STDIN  usually the keyboard, or the text displayed that is in this case is STDOUT.

## formated and unformated IO in C++
### formated input/ output
you can take from the user or put to the user the values in different formats (int, char, float ...). this input is separated by white space characters, the data type of the user input must be similar to the data types fo the varables which are declared inside your  program.


## ex00
the first exercice in this Module is about printing some output to the user in the console in different cases
- without paremeter
- with parameters
- parameters with spaces in the begin and the end and you should ignore them. 


bouth the cin and cout in c++ is objects which you can use them to get the input and also to print the output to the user.

\
  ```cout << "Hello User" << "\n";```

## ex01
in this section you will creat a program that can accept three command ADD, SEARCH and EXIT. in this program you can save until 8 contacts with the following inforamation.
firstname, lastname, nickname, phonenumber, and darkest secrets. every time you run ADD, you will add new one until reach the max that is 8, then the old one will be replaced by the new one. don't worry once you quit the program all your data will be losted forever, and you can display this information while you running the SEARCH, this command will print to you all contacts that is saved with its index. then will prompt you to enter an index to see full information for some contact.

#### input buffering
#### what is buffer
a buffer contains data that is strored for as short amount of time, typically in teh compuer't memory (RAM) The purpose of a buffer is to hold data right before it is used 


### just things I try avoid to lose them

UNFORMATED AND FORMATED IO operations 
	UNFORMATED I/O operations,
		unformated input operations, 

	FORMATED I/O operation
		is read  / write from / to the stream in a specified format to control the appearance
	and interpretation of data 
	(char, int, float ...).
