   int number1 = 0; // first integer read from user
   int number2 = 0; // second integer read from user

   cout << "Enter two integers: "; // prompt
   cin >> number1 >> number2; // read two integers from user

   // using modulus operator
   if ( number1 % number2 == 0 )
      cout << number1 << " is a multiple of " << number2 << endl;

   if ( number1 % number2 != 0 )
      cout << number1 << " is not a multiple of " << number2 << endl;
  
---------------------------------------
  
   char symbol = ' '; // char read from user

   cout << "Enter a character: "; // prompt user for data             
   cin >> symbol; // read the character from the keyboard

   cout << symbol << "'s integer equivalent is "
      << static_cast< int >( symbol ) << endl;
	  
---------------------------------------

   int number = 0; // integer read from user

   cout << "Enter a five-digit integer: "; // prompt
   cin >> number; // read integer from user

   cout << number / 10000 << "   ";
   number = number % 10000;
   cout << number / 1000 << "   ";
   number = number % 1000;
   cout << number / 100 << "   ";
   number = number % 100;
   cout << number / 10 << "   ";
   number = number % 10;
   cout << number << endl;

---------------------------------------

   // variables to store weight and height
   int weight = 0;
   int height = 0; 

   // prompt the user for their weight and height and read them in
   cout << "Enter weight (lbs): ";
   cin >> weight;
   cout << "Enter height (in): ";
   cin >> height;

   // calculate bmi (rounds down due to integer division)
   int bmi = ( weight * 703 ) / ( height * height );

   cout << "\nYour BMI is: " << bmi << "\n\n"; // display user's BMI

   // display BMI information table
   cout << "BMI VALUES                        \n";
   cout << "Underweight: less than 18.5       \n";
   cout << "Normal:      between 18.5 and 24.9\n";
   cout << "Overweight:  between 25 and 29.9  \n";
   cout << "Obese:       30 or greater        \n";
 --------------------------------
 
    // variables to store statistics
   int miles = 0;
   int cost = 0;
   int mpg = 0;
   int parking = 0;
   int tolls = 0;

   // prompt user for each variable and read it in
   cout << "Enter miles driven per day: ";
   cin >> miles;
   cout << "Enter cost per gallon of gas (in cents): ";
   cin >> cost;
   cout << "Enter average miles per gallon: ";
   cin >> mpg;
   cout << "Enter parking fees per day (in dollars): ";
   cin >> parking;
   cout << "Enter tolls per day (in dollars): ";
   cin >> tolls;

   // calculate their daily cost in dollars
   int total = miles * cost / mpg / 100 + parking + tolls;

   // display cost
   cout << "\nYour daily driving cost is: " << total << endl;
   -------------------------------------------------
//Class with a member function
#include <iostream>
using namespace std;

class GradeBook
{
	public:
		void displayMessage() const
		{
			cout << "Hello" << endl;
		}
};

int main()
{
	GradeBook myGradeBook;
	myGradeBook.displayMessage();
}
---------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class GradeBook
{
	public:
		void displayMessage(string courseName) const
		{
			cout << courseName << endl;
		}
};

int main()
{
	string nameofCourse;
	GradeBook myGradeBook;
	
	cout << "Enter course name: " << endl;
	getline(cin, nameofCourse);
	
	myGradeBook.displayMessage(nameofCourse);
}
   
  -----------
/* Define class GradeBook that contains a courseName data member and member functions to set and get its value;
Create and manipulate a GradeBook object with these functions. */
#include <iostream>
#include <string>
using namespace std;

class GradeBook
{
	public:
		//function that sets the course name
		void setCourseName(string name)
		{
			courseName = name;
		}
		
		//function that gets the course name
		string getCourseName() const
		{
			return courseName;
		}
		
		//function that displays a welcome message
		void displayMessage() const
		{
			cout << getCourseName() << endl;
		}
		
	private:
		string courseName;
};

int main()
{
	string nameofCourse;
	GradeBook myGradeBook;
	
	cout << myGradeBook.getCourseName() << endl;
	
	cout << "\NPlease enter the course name: " << endl;
	getline(cin, nameofCourse);
	
	myGradeBook.setCourseName(nameofCourse);
	
	myGradeBook.displayMessage();
}
---------------------
// Instantiating multiple objects of the GradeBook class and using
// the GradeBook constructor to specify the course name
// when each GradeBook object is created.
#include <iostream>
#include <string> // program uses C++ standard string class
using namespace std;

// GradeBook class definition
class GradeBook
{
	public:
		// constructor initializes courseName with string supplied as argument
		explicit GradeBook( string name )
				: courseName( name ) // member initializer to initialize courseName
		{
		// empty body
		} // end GradeBook constructor

		// function to set the course name
		void setCourseName( string name )
		{
			courseName = name; // store the course name in the object
		} // end function setCourseName
		
		// function to get the course name
		string getCourseName() const
		{
			return courseName; // return object's courseName
		} // end function getCourseName

		// display a welcome message to the GradeBook user
		void displayMessage() const
		{
			// call getCourseName to get the courseName
			cout << "Welcome to the grade book for\n" <<
				<< "!" << endl;
		} // end function displayMessage
		
	private:
		string courseName; // course name for this GradeBook
}; // end class GradeBook

// function main begins program execution
int main()
{
	// create two GradeBook objects
	GradeBook gradeBook1( "CS101 Introduction to C++ Programming" );
	GradeBook gradeBook2( "CS102 Data Structures in C++" );

	// display initial value of courseName for each GradeBook
	cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
			<< "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
			<< endl;
} // end main

-----------------------------
//GradeBook.h
-----------------------------
// GradeBook class definition in a separate file from main.
#include <iostream> 
#include <string> // class GradeBook uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   // constructor initializes courseName with string supplied as argument
   explicit GradeBook( std::string name )
      : courseName( name ) // member initializer to initialize courseName 
   {
      // empty body
   } // end GradeBook constructor

   // function to set the course name
   void setCourseName( std::string name )
   {
      courseName = name; // store the course name in the object
   } // end function setCourseName

   // function to get the course name
   std::string getCourseName() const
   {
      return courseName; // return object's courseName
   } // end function getCourseName

   // display a welcome message to the GradeBook user
   void displayMessage() const
   {
      // call getCourseName to get the courseName
      std::cout << "Welcome to the grade book for\n" << getCourseName()  
         << "!" << std::endl;
   } // end function displayMessage
private:
   std::string courseName; // course name for this GradeBook
}; // end class GradeBook  

#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// function main begins program execution
int main()
{
   // create two GradeBook objects
   GradeBook gradeBook1( "CS101 Introduction to C++ Programming" );
   GradeBook gradeBook2( "CS102 Data Structures in C++" );

   // display initial value of courseName for each GradeBook
   cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
      << "\ngradeBook2 created for course: " << gradeBook2.getCourseName() 
      << endl;
} // end main
-----------------------
//GradeBook.h
// GradeBook class definition. This file presents GradeBook's public 
// interface without revealing the implementations of GradeBook's member
// functions, which are defined in GradeBook.cpp.
#include <string> // class GradeBook uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // constructor initialize courseName
   void setCourseName( std::string ); // sets the course name
   std::string getCourseName() const; // gets the course name
   void displayMessage() const; // displays a welcome message
private:
   std::string courseName; // course name for this GradeBook
}; // end class GradeBook  

//GradeBook.cpp
----------------
// GradeBook member-function definitions. This file contains
// implementations of the member functions prototyped in GradeBook.h.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name )
   : courseName( name ) // member initializer to initialize courseName 
{                                                                      
   // empty body
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName( string name )
{
   courseName = name; // store the course name in the object
} // end function setCourseName

// function to get the course name
string GradeBook::getCourseName() const
{
   return courseName; // return object's courseName
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // call getCourseName to get the courseName
   cout << "Welcome to the grade book for\n" << getCourseName() 
      << "!" << endl;
} // end function displayMessage

// Fig. 3.13: fig03_13.cpp
// GradeBook class demonstration after separating 
// its interface from its implementation.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// function main begins program execution
int main()
{
   // create two GradeBook objects
   GradeBook gradeBook1( "CS101 Introduction to C++ Programming" );
   GradeBook gradeBook2( "CS102 Data Structures in C++" );

   // display initial value of courseName for each GradeBook
   cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
      << "\ngradeBook2 created for course: " << gradeBook2.getCourseName() 
      << endl;
} // end main

// Fig. 3.15: GradeBook.h
// GradeBook class definition presents the public interface of  
// the class. Member-function definitions appear in GradeBook.cpp.
#include <string> // program uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // constructor initialize courseName
   void setCourseName( std::string ); // sets the course name
   std::string getCourseName() const; // gets the course name
   void displayMessage() const; // displays a welcome message
private:
   std::string courseName; // course name for this GradeBook
}; // end class GradeBook  

// Fig. 3.16: GradeBook.cpp
// Implementations of the GradeBook member-function definitions.
// The setCourseName function performs validation.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name )
{
   setCourseName( name ); // validate and store courseName
} // end GradeBook constructor

// function that sets the course name;
// ensures that the course name has at most 25 characters
void GradeBook::setCourseName( string name )
{
   if ( name.size() <= 25 ) // if name has 25 or fewer characters
      courseName = name; // store the course name in the object

   if ( name.size() > 25 ) // if name has more than 25 characters
   { 
      // set courseName to first 25 characters of parameter name
      courseName = name.substr( 0, 25 ); // start at 0, length of 25

      cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
         << "Limiting courseName to first 25 characters.\n" << endl;
   } // end if
} // end function setCourseName

// function to get the course name
string GradeBook::getCourseName() const
{
   return courseName; // return object's courseName
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // call getCourseName to get the courseName
   cout << "Welcome to the grade book for\n" << getCourseName()  
      << "!" << endl;
} // end function displayMessage

// Fig. 3.17: fig03_16.cpp
// Create and manipulate a GradeBook object; illustrate validation.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// function main begins program execution
int main()
{
   // create two GradeBook objects; 
   // initial course name of gradeBook1 is too long
   GradeBook gradeBook1( "CS101 Introduction to Programming in C++" );
   GradeBook gradeBook2( "CS102 C++ Data Structures" );

   // display each GradeBook's courseName 
   cout << "gradeBook1's initial course name is: " 
      << gradeBook1.getCourseName()
      << "\ngradeBook2's initial course name is: " 
      << gradeBook2.getCourseName() << endl;

   // modify gradeBook1's courseName (with a valid-length string)
   gradeBook1.setCourseName( "CS101 C++ Programming" );

   // display each GradeBook's courseName 
   cout << "\ngradeBook1's course name is: " 
      << gradeBook1.getCourseName()
      << "\ngradeBook2's course name is: " 
      << gradeBook2.getCourseName() << endl;
} // end main

// Exercise 3.11 Solution: GradeBook.h
// Definition of GradeBook class that stores an instructor's name.
#include <string> // program uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   // constructor initializes course name and instructor name
   GradeBook( std::string, std::string );
   void setCourseName( std::string ); // function to set the course name
   std::string getCourseName(); // function to retrieve the course name
   void setInstructorName( std::string ); // function to set instructor name
   std::string getInstructorName(); // function to retrieve instructor name
   void displayMessage(); // display welcome message and instructor name
private:
   std::string courseName; // course name for this GradeBook
   std::string instructorName; // instructor name for this GradeBook
}; // end class GradeBook  

// Exercise 3.11 Solution: GradeBook.cpp
// Member-function definitions for class GradeBook.
#include <iostream>
#include "GradeBook.h"
using namespace std;

// constructor initializes courseName and instructorName 
// with strings supplied as arguments
GradeBook::GradeBook( string course, string instructor )
{
   setCourseName( course ); // initializes courseName
   setInstructorName( instructor ); // initialiZes instructorName
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName( string name )
{
   courseName = name; // store the course name
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName()
{
   return courseName;
} // end function getCourseName

// function to set the instructor name
void GradeBook::setInstructorName( string name )
{
   instructorName = name; // store the instructor name
} // end function setInstructorName

// function to retrieve the instructor name
string GradeBook::getInstructorName()
{
   return instructorName;
} // end function getInstructorName

// display a welcome message and the instructor's name
void GradeBook::displayMessage()
{
   // display a welcome message containing the course name
   cout << "Welcome to the grade book for\n" << getCourseName() << "!" 
      << endl;

   // display the instructor's name
   cout << "This course is presented by: " << getInstructorName() << endl;
} // end function displayMessage

// Exercise 3.11 Solution: ex03_11.cpp
// Test program for modified GradeBook class.
#include <iostream>
#include "GradeBook.h"
using namespace std;

// function main begins program execution
int main()
{
   // create a GradeBook object; pass a course name and instructor name
   GradeBook gradeBook( 
      "CS101 Introduction to C++ Programming", "Professor Smith" );

   // display initial value of instructorName of GradeBook object
   cout << "gradeBook instructor name is: " 
      << gradeBook.getInstructorName() << "\n\n"; 

   // modify the instructorName using set function
   gradeBook.setInstructorName( "Assistant Professor Bates" );

   // display new value of instructorName
   cout << "new gradeBook instructor name is: " 
      << gradeBook.getInstructorName() << "\n\n";

   // display welcome message and instructor's name
   gradeBook.displayMessage(); 
} // end main

// Exercise 3.12 Solution: Account.h
// Definition of Account class.
class Account
{
public:
   explicit Account( int ); // constructor initializes balance
   void credit( int ); // add an amount to the account balance
   void debit( int ); // subtract an amount from the account balance
   int getBalance(); // return the account balance
private:
   int balance; // data member that stores the balance
}; // end class Account

// Exercise 3.12 Solution: Account.cpp
// Member-function definitions for class Account.
#include <iostream>
#include "Account.h" // include definition of class Account
using namespace std;

// Account constructor initializes data member balance
Account::Account( int initialBalance )
{
   balance = 0; // assume that the balance begins at 0

   // if initialBalance is greater than 0, set this value as the
   // balance of the Account; otherwise, balance remains 0
   if ( initialBalance > 0 )
      balance = initialBalance;

   // if initialBalance is negative, print error message
   if ( initialBalance < 0 )
      cout << "Error: Initial balance cannot be negative.\n" << endl;
} // end Account constructor

// credit (add) an amount to the account balance
void Account::credit( int amount )
{
   balance = balance + amount; // add amount to balance
} // end function credit

// debit (subtract) an amount from the account balance
void Account::debit( int amount )
{
   if ( amount > balance ) // debit amount exceeds balance
      cout << "Debit amount exceeded account balance.\n" << endl;

   if ( amount <= balance ) // debit amount does not exceed balance
      balance = balance - amount;
} // end function debit

// return the account balance
int Account::getBalance()
{
   return balance; // gives the value of balance to the calling function
} // end function getBalance

// Exercise 3.12 Solution: ex03_12.cpp
// Create and manipulate Account objects.
#include <iostream>
#include "Account.h"
using namespace std;

// function main begins program execution
int main()
{
   Account account1( 50 ); // create Account object
   Account account2( 25 ); // create Account object

   // display initial balance of each object
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;

   int withdrawalAmount; // stores withdrawal amount read from user

   cout << "\nEnter withdrawal amount for account1: "; // prompt
   cin >> withdrawalAmount; // obtain user input
   cout << "\nattempting to subtract " << withdrawalAmount 
      << " from account1 balance\n\n";
   account1.debit( withdrawalAmount ); // try to subtract from account1

   // display balances
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;

   cout << "\nEnter withdrawal amount for account2: "; // prompt
   cin >> withdrawalAmount; // obtain user input
   cout << "\nattempting to subtract " << withdrawalAmount 
      << " from account2 balance\n\n";
   account2.debit( withdrawalAmount ); // try to subtract from account2

   // display balances
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
} // end main

// Exercise 3.13 Solution: Invoice.h
// Definition of Invoice class that represents an invoice
// for an item sold at a hardware store.
#include <string> // program uses C++ standard string class

// Invoice class definition
class Invoice
{
public:
   // constructor initializes the four data members
   Invoice( std::string, std::string, int, int );

   // set and get functions for the four data members
   void setPartNumber( std::string ); // part number
   std::string getPartNumber(); 
   void setPartDescription( std::string ); // part description
   std::string getPartDescription();
   void setQuantity( int ); // quantity
   int getQuantity();
   void setPricePerItem( int ); // price per item
   int getPricePerItem();

   // calculates invoice amount by multiplying quantity x price per item
   int getInvoiceAmount(); 
private:
   std::string partNumber; // the number of the part being sold
   std::string partDescription; // description of the part being sold
   int quantity; // how many of the items are being sold
   int pricePerItem; // price per item
}; // end class Invoice

// Exercise 3.13 Solution: Invoice.cpp
// Member-function definitions for class Invoice.
#include <iostream>
#include "Invoice.h"
using namespace std;

// Invoice constructor initializes the class's four data members
Invoice::Invoice( string number, string description, int count, 
   int price )
{
   setPartNumber( number ); // store partNumber
   setPartDescription( description ); // store partDescription
   setQuantity( count ); // validate and store quantity
   setPricePerItem( price ); // validate and store pricePerItem
} // end Invoice constructor

// set part number
void Invoice::setPartNumber( string number )
{
   partNumber = number; // no validation needed
} // end function setPartNumber

// get part number
string Invoice::getPartNumber()
{
   return partNumber;
} // end function getPartNumber

// set part description
void Invoice::setPartDescription( string description )
{
   partDescription = description; // no validation needed
} // end function setPartDescription

// get part description
string Invoice::getPartDescription()
{
   return partDescription;
} // end function getPartDescription

// set quantity; if not positive, set to 0
void Invoice::setQuantity( int count )
{
   if ( count > 0 ) // if quantity is positive
      quantity = count; // set quantity to count

   if ( count <= 0 ) // if quantity is not positive
   {
      quantity = 0; // set quantity to 0
      cout << "\nquantity cannot be negative. quantity set to 0.\n";
   } // end if
} // end function setQuantity
   
// get quantity
int Invoice::getQuantity()
{
   return quantity;
} // end function getQuantity
   
// set price per item; if not positive, set to 0
void Invoice::setPricePerItem( int price )
{
   if ( price > 0 ) // if price is positive
      pricePerItem = price; // set pricePerItem to price

   if ( price <= 0 ) // if price is not positive
   {
      pricePerItem = 0; // set pricePerItem to 0
      cout << "\npricePerItem cannot be negative. "
         << "pricePerItem set to 0.\n";
   } // end if
} // end function setPricePerItem

// get price per item
int Invoice::getPricePerItem()
{
   return pricePerItem;
} // end function getPricePerItem

// calulates invoice amount by multiplying quantity x price per item
int Invoice::getInvoiceAmount()
{
   return getQuantity() * getPricePerItem();
} // end function getInvoiceAmount

// Exercise 3.13 Solution: ex03_13.cpp
// Create and manipulate an Invoice object.
#include <iostream>
#include "Invoice.h"
using namespace std;

// function main begins program execution
int main()
{
   // create an Invoice object
   Invoice invoice( "12345", "Hammer", 100, 5 ); 

   // display the invoice data members and calculate the amount
   cout << "Part number: " << invoice.getPartNumber() << endl;
   cout << "Part description: " << invoice.getPartDescription() << endl;
   cout << "Quantity: " << invoice.getQuantity() << endl;
   cout << "Price per item: $" << invoice.getPricePerItem() << endl;
   cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;

   // modify the invoice data members
   invoice.setPartNumber( "123456" );
   invoice.setPartDescription( "Saw" );
   invoice.setQuantity( -5 ); // negative quantity, so quantity set to 0 
   invoice.setPricePerItem( 10 );
   cout << "\nInvoice data members modified.\n\n";

   // display the modified invoice data members and calculate new amount
   cout << "Part number: " << invoice.getPartNumber() << endl;
   cout << "Part description: " << invoice.getPartDescription() << endl;
   cout << "Quantity: " << invoice.getQuantity() << endl;
   cout << "Price per item: $" << invoice.getPricePerItem() << endl;
   cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
} // end main

// Exercise 3.14 Solution: Employee.h
// Employee class definition.
#include <string> // program uses C++ standard string class

// Employee class definition
class Employee 
{
public:
   Employee( std::string, std::string, int ); // constructor sets data members
   void setFirstName( std::string ); // set first name
   std::string getFirstName(); // return first name
   void setLastName( std::string ); // set last name
   std::string getLastName(); // return last name
   void setMonthlySalary( int ); // set monthly salary
   int getMonthlySalary(); // return monthly salary
private:
   std::string firstName; // Employee's first name
   std::string lastName; // Employee's last name
   int monthlySalary; // Employee's salary per month
}; // end class Employee

// Exercise 3.14 Solution: Employee.cpp
// Employee class member-function definitions.
#include <iostream>
#include "Employee.h" // Employee class definition
using namespace std;

// Employee constructor initializes the three data members
Employee::Employee( string first, string last, int salary )
{ 
   setFirstName( first ); // store first name
   setLastName( last ); // store last name
   setMonthlySalary( salary ); // validate and store monthly salary
} // end Employee constructor

// set first name
void Employee::setFirstName( string name )
{
   firstName = name; // no validation needed
} // end function setFirstName

// return first name
string Employee::getFirstName()
{
   return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName( string name )
{
   lastName = name; // no validation needed
} // end function setLastName

// return last name
string Employee::getLastName()
{
   return lastName;
} // end function getLastName

// set monthly salary; if not positive, set to 0
void Employee::setMonthlySalary( int salary )
{ 
   if ( salary > 0 ) // if salary is positive
      monthlySalary = salary; // set monthlySalary to salary

   if ( salary <= 0 ) // if salary is not positive
      monthlySalary = 0; // set monthlySalary to 0
} // end function setMonthlySalary

// return monthly salary
int Employee::getMonthlySalary()
{
   return monthlySalary;
} // end function getMonthlySalary

// Exercise 3.14 Solution: ex03_14.cpp
// Create and manipulate two Employee objects.
#include <iostream>
#include "Employee.h" // include definition of class Employee
using namespace std;

// function main begins program execution
int main()
{
   // create two Employee objects
   Employee employee1( "Lisa", "Roberts", 4500 );
   Employee employee2( "Mark", "Stein", 4000 );

   // display each Employee's yearly salary
   cout << "Employees' yearly salaries: " << endl;

   // retrieve and display employee1's monthly salary multiplied by 12
   int monthlySalary1 = employee1.getMonthlySalary();
   cout << employee1.getFirstName() << " " << employee1.getLastName() 
      << ": $" << monthlySalary1 * 12 << endl;

   // retrieve and display employee2's monthly salary multiplied by 12
   int monthlySalary2 = employee2.getMonthlySalary();
   cout << employee2.getFirstName() << " " << employee2.getLastName() 
      << ": $" << monthlySalary2 * 12 << endl;

   // give each Employee a 10% raise
   employee1.setMonthlySalary( monthlySalary1 + monthlySalary1 / 10 );
   employee2.setMonthlySalary( monthlySalary2 + monthlySalary2 / 10 );

   // display each Employee's yearly salary again
   cout << "\nEmployees' yearly salaries after 10% raise: " << endl;

   // retrieve and display employee1's monthly salary multiplied by 12
   monthlySalary1 = employee1.getMonthlySalary();
   cout << employee1.getFirstName() << " " << employee1.getLastName() 
      << ": $" << monthlySalary1 * 12 << endl;
   
   monthlySalary2 = employee2.getMonthlySalary();
   cout << employee2.getFirstName() << " " << employee2.getLastName() 
      << ": $" << monthlySalary2 * 12 << endl;
} // end main

// Exercise 3.15 Solution: Date.h
// Definition of class Date.

// class Date definition
class Date 
{
public:
   Date( int, int, int ); // constructor initializes data members
   void setMonth( int ); // set month
   int getMonth(); // return month
   void setDay( int ); // set day
   int getDay(); // return day
   void setYear( int ); // set year
   int getYear(); // return year
   void displayDate(); // displays date in mm/dd/yyyy format
private:
   int month; // the month of the date
   int day; // the day of the date
   int year; // the year of the date
}; // end class Date

// Exercise 3.15 Solution: Date.cpp
// Member-function definitions for class Date.
#include <iostream>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

// Date constructor that initializes the three data members;
// assume values provided are correct (really should validate)
Date::Date( int m, int d, int y )
{
   setMonth( m );
   setDay( d );
   setYear( y );
} // end Date constructor 

// set month
void Date::setMonth( int m )
{
   month = m;

   if ( month < 1 )
      month = 1;

   if ( month > 12 )
      month = 1;
} // end function setMonth

// return month
int Date::getMonth()
{
   return month;
} // end function getMonth

// set day
void Date::setDay( int d )
{
   day = d;
} // end function setDay

// return day
int Date::getDay()
{
   return day;
} // end function getDay

// set year
void Date::setYear( int y )
{
   year = y;
} // end function setYear

// return year
int Date::getYear()
{
   return year;
} // end function getYear

// print Date in the format mm/dd/yyyy
void Date::displayDate() 
{ 
   cout << month << '/' << day << '/' << year << endl; 
} // end function displayDate

// Exercise 3.15 Solution: ex03_15.cpp
// Demonstrates class Date's capabilities.
#include <iostream>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

// function main begins program execution
int main()
{
   Date date( 5, 6, 1981 ); // create a Date object for May 6, 1981
   
   // display the values of the three Date data members
   cout << "Month: " << date.getMonth() << endl;
   cout << "Day: " << date.getDay() << endl;
   cout << "Year: " << date.getYear() << endl;

   cout << "\nOriginal date:" << endl;
   date.displayDate(); // output the Date as 5/6/1981

   // modify the Date 
   date.setMonth( 13 ); // invalid month
   date.setDay( 1 );
   date.setYear( 2005 );
   
   cout << "\nNew date:" << endl;
   date.displayDate(); // output the modified date (1/1/2005)
} // end main

// Exercise 3.16 Solution: HeartRates.h
// HeartRates class for computing target heart rates.
#include <string>

class HeartRates
{
public:
   // Constructor
   HeartRates( std::string first, std::string last, int m, int d, int y )
   {
      setFirstName( first ); // set first name
      setLastName( last ); // set last name
      setBirthMonth( m ); // set month
      setBirthDay( d ); // set day
      setBirthYear( y ); // set year
   } // end constructor

   // set first name
   void setFirstName( std::string first )
   {
      firstName = first;
   } // end function setFirstName

   // get first name
   std::string getFirstName()
   {
      return firstName;
   } // end function getFirstName

   // set last name
   void setLastName( std::string last )
   {
      lastName = last;
   } // end function setLastName

   // get last name
   std::string getLastName()
   {
      return lastName;
   } // end function getLastName

   // set birth month
   void setBirthMonth( int m )
   {
      birthMonth = m;
   } // end function setBirthMonth

   // get birth month
   int getBirthMonth()
   {
      return birthMonth;
   } // end function getBirthMonth

   // set birth day
   void setBirthDay( int d )
   {
      birthDay = d;
   } // end function setBirthDay

   // get birth day
   int getBirthDay()
   {
      return birthDay;
   } // end function getBirthDay

   // set birth year
   void setBirthYear( int y )
   {
      birthYear = y;
   } // end function setBirthYear

   // get birth year
   int getBirthYear()
   {
      return birthYear;
   } // end function getBirthYear

   // calculate age
   int getAge()
   {
      // if current date has not yet been set, get it from user
      if ( currentYear == 0 )
      {
         cout << "Please enter today's month, day, and year:" << endl;
         cin >> currentMonth >> currentDay >> currentYear;
      } // end if

      if ( currentMonth >= birthMonth )
         if ( currentDay >= birthDay )
            return currentYear - birthYear;

      return currentYear - birthYear - 1;
   } // end function getAge

   // get maximum heart rate
   int getMaximumHeartRate()
   {
      return 220 - getAge();
   } // end function getMaximumHeartRate

   // calculate minimum target heart rate
   int getMinimumTargetHeartRate()
   {
      return 50 * getMaximumHeartRate() / 100;
   } // end function getMinimumTargetHeartRate

   // calculate maximum target heart rate
   int getMaximumTargetHeartRate()
   {
      return 85 * getMaximumHeartRate() / 100;
   } // end function getMaximumTargetHeartRate
private:
   std::string firstName; // user's first name
   std::string lastName; // user's last name
   int birthMonth; // user's birth month
   int birthDay; // user's birth day
   int birthYear; // user's birth year
   int currentMonth; // current month
   int currentDay; // current day
   int currentYear; // current year
}; // end class HeartRates

// Exercise 3.16 Solution: ex03_16.cpp
// Driver program for HeartRates class
#include <iostream>
#include <string>
#include "HeartRates.h"
using namespace std;

int main()
{
   string first, last; // first name, last name
   int month, day, year; // birth month, day, year

   // get user input
   cout << "Please enter first and last name:" << endl;
   cin >> first >> last;
   cout << "Please enter month, day, and year of birth:" << endl;
   cin >> month >> day >> year;

   // create a HeartRates object
   HeartRates heartRates( first, last, month, day, year );

   // display user information
   cout << "First Name: " << heartRates.getFirstName() << "\n";
   cout << "Last Name: " << heartRates.getLastName() << "\n";
   cout << "Date of Birth: " << heartRates.getBirthMonth() << "/"
      << heartRates.getBirthDay() << "/"
      << heartRates.getBirthYear() << "\n";
   cout << "Age: " << heartRates.getAge() << "\n";
   cout << "Maximum Heart Rate: "
      << heartRates.getMaximumHeartRate() << "\n";
   cout << "Target Heart Rate: "
      << heartRates.getMinimumTargetHeartRate() << "-"
      << heartRates.getMaximumTargetHeartRate() << "\n";
} // end main

// Exercise 3.17 Solution: HealthProfile.h
// HealthProfile class for storing medical data.
#include <string>

class HealthProfile
{
public:
   // Constructor
   HealthProfile( std::string first, std::string last, char g,
      int m, int d, int y, int h, int w )
   {
      setFirstName( first ); // set first name
      setLastName( last ); // set last name
      setGender( g ); // set gender
      setBirthMonth( m ); // set month
      setBirthDay( d ); // set day
      setBirthYear( y ); // set year
      setHeight( h ); // set height
      setWeight( w ); // set weight
   } // end constructor

   // set first name
   void setFirstName( std::string first )
   {
      firstName = first;
   } // end function setFirstName

   // get first name
   std::string getFirstName()
   {
      return firstName;
   } // end function getFirstName

   // set last name
   void setLastName( std::string last )
   {
      lastName = last;
   } // end function setLastName

   // get last name
   std::string getLastName()
   {
      return lastName;
   } // end function getLastName

   // set gender
   void setGender( char g )
   {
      gender = g;
   } // end function setGender

   // get gender
   char getGender()
   {
      return gender;
   } // end function getGender

   // set birth month
   void setBirthMonth( int m )
   {
      birthMonth = m;
   } // end function setBirthMonth

   // get birth month
   int getBirthMonth()
   {
      return birthMonth;
   } // end function getBirthMonth

   // set birth day
   void setBirthDay( int d )
   {
      birthDay = d;
   } // end function setBirthDay

   // get birth day
   int getBirthDay()
   {
      return birthDay;
   } // end function getBirthDay

   // set birth year
   void setBirthYear( int y )
   {
      birthYear = y;
   } // end function setBirthYear

   // get birth year
   int getBirthYear()
   {
      return birthYear;
   } // end function getBirthYear

   // set height
   void setHeight( int h )
   {
      height = h;
   } // end function setHeight

   // get height
   int getHeight()
   {
      return height;
   } // end function getHeight

   // set weight
   void setWeight( int w )
   {
      weight = w;
   } // end function setWeight

   // get weight
   int getWeight()
   {
      return weight;
   } // end function getWeight

   // calculate age
   int getAge()
   {
      // if current date has not yet been set, get it from user
      if ( currentYear == 0 )
      {
         cout << "Please enter today's month, day, and year:" << endl;
         cin >> currentMonth >> currentDay >> currentYear;
      } // end if

      if ( currentMonth >= birthMonth )
         if ( currentDay >= birthDay )
            return currentYear - birthYear;

      return currentYear - birthYear - 1;
   } // end function getAge

   // get maximum heart rate
   int getMaximumHeartRate()
   {
      return 220 - getAge();
   } // end function getMaximumHeartRate

   // calculate minimum target heart rate
   int getMinimumTargetHeartRate()
   {
      return 50 * getMaximumHeartRate() / 100;
   } // end function getMinimumTargetHeartRate

   // calculate maximum target heart rate
   int getMaximumTargetHeartRate()
   {
      return 85 * getMaximumHeartRate() / 100;
   } // end function getMaximumTargetHeartRate

   // calculate body mass index
   int getBodyMassIndex()
   {
      return getWeight() * 703 / ( getHeight() * getHeight() );
   } // end function getBMI
private:
   std::string firstName; // person's first name
   std::string lastName; // person's last name
   char gender; // person's gender
   int birthMonth; // person's birth month
   int birthDay; // person's birth day
   int birthYear; // person's birth year
   int height; // person's height in inches
   int weight; // person's weight in pounds
   int currentMonth; // current month
   int currentDay; // current day
   int currentYear; // current year
}; // end class HealthProfile

// Exercise 3.17 Solution: ex03_17.cpp
// Driver program for HealthProfile class
#include <iostream>
#include <string>
#include "HealthProfile.h"
using namespace std;

int main()
{
   string first, last; // first name, last name
   int month, day, year; // birth month, day, year
   int height, weight; // height (inches) and weight (pounds)
   char gender; // gender (M or F)

   // get user input
   cout << "Please enter first and last name:\n";
   cin >> first >> last;
   cout << "Please enter gender (M or F):\n";
   cin >> gender;
   cout << "Please enter month, day, and year of birth:\n";
   cin >> month >> day >> year;
   cout << "Please enter height (in inches) and weight (in pounds):\n";
   cin >> height >> weight;

   // create a HealthProfile object
   HealthProfile profile( first, last, gender,
      month, day, year, height, weight );

   // display user information
   cout << "First Name: " << profile.getFirstName() << "\n";
   cout << "Last Name: " << profile.getLastName() << "\n";
   cout << "Gender: " << profile.getGender() << "\n";
   cout << "Date of Birth: " << profile.getBirthMonth() << "/"
      << profile.getBirthDay() << "/"
      << profile.getBirthYear() << "\n";
   cout << "Height (inches): " << profile.getHeight() << "\n";
   cout << "Weight (pounds): " << profile.getWeight() << "\n";
   cout << "Age: " << profile.getAge() << "\n";
   cout << "Maximum Heart Rate: "
      << profile.getMaximumHeartRate() << "\n";
   cout << "Target Heart Rate: "
      << profile.getMinimumTargetHeartRate() << "-"
      << profile.getMaximumTargetHeartRate() << "\n";
   cout << "Body Mass Index: " << profile.getBodyMassIndex() << "\n\n";

   // display BMI information table
   cout << "BMI VALUES                        \n";
   cout << "Underweight: less than 18.5       \n";
   cout << "Normal:      between 18.5 and 24.9\n";
   cout << "Overweight:  between 25 and 29.9  \n";
   cout << "Obese:       30 or greater        \n";
} // end main

// Exercise 4.8 Solution: ex04_08.cpp
// Raise x to the y power. 
#include <iostream>
using namespace std;

int main()
{
   unsigned int i = 1; // initialize i to begin counting from 1
   unsigned int power = 1; // initialize power

   cout << "Enter base as an integer: ";  // prompt for base
   unsigned int x; // base 
   cin >> x; // input base

   cout << "Enter exponent as an integer: "; // prompt for exponent
   unsigned int y; // exponent
   cin >> y; // input exponent

   // count from 1 to y and multiply power by x each time
   while ( i <= y ) 
   {
      power *= x;
      ++i;
   } // end while

   cout << power << endl; // display result
} // end main

// Exercise 4.12: ex04_12.cpp
// What does this program print?
#include <iostream>
using namespace std;

int main()
{
   unsigned int y = 0; // declare and initialize y
   unsigned int x = 1; // declare and initialize x
   unsigned int total = 0; // declare and initialize total

   while ( x <= 10 ) // loop 10 times
   {    
      y = x * x; // perform calculation
      cout << y << endl; // output result
      total += y; // add y to total
      ++x; // increment counter x
   } // end while

   cout << "Total is " << total << endl; // display result
} // end main

// Exercise 4.21: ex04_21.cpp
// What does this program print?
#include <iostream>
using namespace std;

int main()
{
   unsigned int count = 1; // initialize count

   while ( count <= 10 ) // loop 10 times
   {   
      // output line of text
      cout << ( count % 2 ? "****" : "++++++++" ) << endl;
      ++count; // increment count
   } // end while
} // end main

#include <iostream>
using namespace std;

int main()
{
    unsigned int row = 10; // initialize row

    while (row >= 1) // loop until row < 1
    {
        unsigned int column = 1; // set column to 1 as iteration begins

        while (column <= 10) // loop 10 times
        {
            cout << (row % 2 ? "<" : ">"); // output
            ++column; // increment column
        } // end inner while

        --row; // decrement row
        cout << endl; // begin new output line
    } // end outer while
} // end main
output:
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<

// Fig. 4.8: GradeBook.h
// Definition of class GradeBook that determines a class average.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // initializes course name
   void setCourseName( std::string ); // set the course name
   std::string getCourseName() const; // retrieve the course name
   void displayMessage() const; // display a welcome message
   void determineClassAverage() const; // averages user-entered grades 
private:
   std::string courseName; // course name for this GradeBook
}; // end class GradeBook 

// Fig. 4.9: GradeBook.cpp
// Member-function definitions for class GradeBook that solves the 
// class average program with counter-controlled repetition.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name )
{
   setCourseName( name ); // validate and store courseName
} // end GradeBook constructor

// function to set the course name;
// ensures that the course name has at most 25 characters
void GradeBook::setCourseName( string name )
{
   if ( name.size() <= 25 ) // if name has 25 or fewer characters
      courseName = name; // store the course name in the object
   else // if name is longer than 25 characters
   { // set courseName to first 25 characters of parameter name
      courseName = name.substr( 0, 25 ); // select first 25 characters
      cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
         << "Limiting courseName to first 25 characters.\n" << endl;
   } // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
   return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   cout << "Welcome to the grade book for\n" << getCourseName() << "!\n" 
      << endl;
} // end function displayMessage

// determine class average based on 10 grades entered by user
void GradeBook::determineClassAverage() const
{
   // initialization phase
   int total = 0; // sum of grades entered by user
   unsigned int gradeCounter = 1; // number of grade to be entered next

   // processing phase
   while ( gradeCounter <= 10 ) // loop 10 times
   {
      cout << "Enter grade: "; // prompt for input
      int grade = 0; // grade value entered by user
      cin >> grade; // input next grade
      total = total + grade; // add grade to total
      gradeCounter = gradeCounter + 1; // increment counter by 1
   } // end while

   // termination phase
   int average = total / 10; // ok to mix declaration and calculation

   // display total and average of grades
   cout << "\nTotal of all 10 grades is " << total << endl;
   cout << "Class average is " << average << endl; 
} // end function determineClassAverage

// Fig. 4.10: fig04_10.cpp
// Create GradeBook object and invoke its determineClassAverage function.
#include "GradeBook.h" // include definition of class GradeBook

int main()
{
   // create GradeBook object myGradeBook and 
   // pass course name to constructor
   GradeBook myGradeBook( "CS101 C++ Programming" );

   myGradeBook.displayMessage(); // display welcome message
   myGradeBook.determineClassAverage(); // find average of 10 grades
} // end main

// Fig. 4.12: GradeBook.h
// Definition of class GradeBook that determines a class average.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // initializes course name
   void setCourseName( std::string ); // set the course name
   std::string getCourseName() const; // retrieve the course name
   void displayMessage() const; // display a welcome message
   void determineClassAverage() const; // averages user-entered grades
private:
   std::string courseName; // course name for this GradeBook
}; // end class GradeBook 

// Fig. 4.13: GradeBook.cpp
// Member-function definitions for class GradeBook that solves the 
// class average program with sentinel-controlled repetition.
#include <iostream>
#include <iomanip> // parameterized stream manipulators  
#include "GradeBook.h" // include definition of class GradeBook 
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name )
{
   setCourseName( name ); // validate and store courseName
} // end GradeBook constructor

// function to set the course name;
// ensures that the course name has at most 25 characters
void GradeBook::setCourseName( string name )
{
   if ( name.size() <= 25 ) // if name has 25 or fewer characters
      courseName = name; // store the course name in the object
   else // if name is longer than 25 characters
   { // set courseName to first 25 characters of parameter name
      courseName = name.substr( 0, 25 ); // select first 25 characters
      cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
         << "Limiting courseName to first 25 characters.\n" << endl;
   } // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
   return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   cout << "Welcome to the grade book for\n" << getCourseName() << "!\n" 
      << endl;
} // end function displayMessage

// determine class average based on 10 grades entered by user
void GradeBook::determineClassAverage() const
{
   // initialization phase
   int total = 0; // sum of grades entered by user
   unsigned int gradeCounter = 0; // number of grades entered

   // processing phase
   // prompt for input and read grade from user  
   cout << "Enter grade or -1 to quit: ";        
   int grade = 0; // grade value
   cin >> grade; // input grade or sentinel value

   // loop until sentinel value read from user   
   while ( grade != -1 ) // while grade is not -1
   {                  
      total = total + grade; // add grade to total
      gradeCounter = gradeCounter + 1; // increment counter
      
      // prompt for input and read next grade from user
      cout << "Enter grade or -1 to quit: ";           
      cin >> grade; // input grade or sentinel value   
   } // end while

   // termination phase
   if ( gradeCounter != 0 ) // if user entered at least one grade...
   {
      // calculate average of all grades entered              
      double average = static_cast< double >( total ) / gradeCounter;
      
      // display 7total and average (with two digits of precision)
      cout << "\nTotal of all " << gradeCounter << " grades entered is " 
         << total << endl;
      cout << setprecision( 2 ) << fixed;
      cout << "Class average is " << average << endl;
   } // end if
   else // no grades were entered, so output appropriate message
      cout << "No grades were entered" << endl;
} // end function determineClassAverage

// Fig. 4.14: fig04_14.cpp
// Create GradeBook object and invoke its determineClassAverage function.
#include "GradeBook.h" // include definition of class GradeBook

int main()
{
   // create GradeBook object myGradeBook and 
   // pass course name to constructor
   GradeBook myGradeBook( "CS101 C++ Programming" );

   myGradeBook.displayMessage(); // display welcome message
   myGradeBook.determineClassAverage(); // find average of 10 grades
} // end main

#include <iostream>
using namespace std;

int main()
{
   // initializing variables in declarations 
   unsigned int passes = 0; // number of passes       
   unsigned int failures = 0; // number of failures   
   unsigned int studentCounter = 1; // student counter

   // process 10 students using counter-controlled loop
   while ( studentCounter <= 10 ) 
   {
      // prompt user for input and obtain value from user
      cout << "Enter result (1 = pass, 2 = fail): ";
      int result = 0; // one exam result (1 = pass, 2 = fail)
      cin >> result; // input result

      // if...else nested in while                           
      if ( result == 1 )          // if result is 1,         
         passes = passes + 1;     // increment passes;       
      else                        // else result is not 1, so
         failures = failures + 1; // increment failures      

      // increment studentCounter so loop eventually terminates
      studentCounter = studentCounter + 1; 
   } // end while 

   // termination phase; display number of passes and failures
   cout << "Passed " << passes << "\nFailed " << failures << endl;

   // determine whether more than eight students passed
   if ( passes > 8 )
      cout << "Bonus to instructor!" << endl; 
} // end main

// Exercise 4.13 Solution: ex04_13.cpp
// Calculate average MPG with sentinel-controlled repetition.
#include <iostream>
using namespace std;

int main()
{
   double gallons = 0; // gallons used for current trip
   double miles = 0; // miles driven for current trip
   double totalGallons = 0; // total gallons used
   double totalMiles = 0; // total miles driven

   double milesPerGallon; // miles per gallon for trip
   double totalMilesPerGallon; // miles per gallon for trip

   // processing phase
   // get miles used for first trip
   cout << "Enter miles driven (-1 to quit): ";
   cin >> miles;
   cout << fixed; // set floating-point number format

   // exit if the input is -1; otherwise, proceed with the program
   while ( miles != -1 )
   {
      // prompt user for gallons and obtain the input from user
      cout << "Enter gallons used: ";
      cin >> gallons;

      // add gallons and miles for this trip to total
      totalMiles += miles;
      totalGallons += gallons;

      // calculate miles per gallon for the current trip
      if ( gallons != 0 )
      {
         milesPerGallon =  miles / gallons;
         cout << "MPG this trip: " << milesPerGallon;            
      } // end if 

      // calculate miles per gallon for the total trip
      if ( totalGallons != 0 )
      {
         totalMilesPerGallon = totalMiles / totalGallons;
         cout << "\nTotal MPG: " << totalMilesPerGallon;
      } // end if 

      // prompt user for new value for miles
      cout << "\n\nEnter miles driven (-1 to quit): ";
      cin >> miles;
   } // end while       
} // end main

// Exercise 4.14 Solution: ex04_14.cpp
// Calculate credit balances.
#include <iostream>
#include <iomanip> // parameterized stream manipulators
using namespace std;

int main()
{
   unsigned int account = 0; // account number
   double balance = 0; // account balance
   double charges = 0; // total charges
   double credits = 0; // total credits
   double creditLimit = 0; // allowed credit limit

   cout << "Enter account number (or -1 to quit): ";
   cin >> account; // read in account number

   // set floating-point number format
   cout << fixed << setprecision( 2 );

   // exit if the input is -1; otherwise proceed with the program
   while ( account != -1 )
   {
      cout << "Enter beginning balance: ";
      cin >> balance; // read in original balance

      cout << "Enter total charges: ";
      cin >> charges; // read in charges

      cout << "Enter total credits: ";
      cin >> credits; // read in credits

      cout << "Enter credit limit: ";
      cin >> creditLimit; // read in credit limit

      // calculate and display new balance
      balance = balance + charges - credits;
      cout << "New balance is " << balance;

      // display a warning if the user has exceed the credit limit
      if ( balance > creditLimit )
         cout << "\nAccount:      " << account
            << "\nCredit limit: " << creditLimit 
            << "\nBalance:      " << balance 
            << "\nCredit Limit Exceeded.";

      cout << "\n\nEnter account number (or -1 to quit): ";
      cin >> account; // read in next account number
   } // end while
} // end main

// Exercise 4.15 Solution: ex04_15.cpp
// Calculate salesperson earnings.
#include <iostream>
#include <iomanip> // parameterized stream manipulators
using namespace std; // sets numeric output precision

int main()
{
   double sales = 0; // gross weekly sales
   double wage = 0; // commissioned earnings
   
   // processing phase
   // get first sales
   cout << "Enter sales in dollars (-1 to end): ";
   cin >> sales;

   // set floating-point number format
   cout << fixed << setprecision( 2 );

   // loop until sentinel value read from user
   while ( sales != -1.0 ) 
   {    
      wage = 200.0 + 0.09 * sales; // calculate wage
      cout << "Salary is: $" << wage; // display salary
      
      // prompt for next sales
      cout << "\n\nEnter sales in dollars (-1 to end): ";
      cin >> sales;
   } // end while
} // end main

// Exercise 4.16 Solution: ex04_16.cpp
// Calculating wages.
#include <iostream>
#include <iomanip> // parameterized stream manipulators
using namespace std; 

int main()
{
   double hours = 0; // total hours worked
   double rate = 0; // hourly pay rate
   double salary = 0; // gross pay

   // processing phase
   // get first employee's hours worked
   cout << "Enter hours worked (-1 to end): ";
   cin >> hours;

   // set floating-point number format
   cout << fixed << setprecision( 2 );

   // loop until sentinel value read from user
   while ( hours != -1.0 ) 
   {
      // get hourly rate
      cout << "Enter hourly rate of the employee ($00.00): ";
      cin >> rate;
      
      // if employee worked less than 40 hours
      if ( hours <= 40 )
         salary = hours * rate;
      else // else, compute "time-and-a-half" pay
         salary = 40.0 * rate + ( hours - 40.0 ) * rate * 1.5;
      
      cout << "Salary is $" << salary; // display gross pay

      // prompt for next employee's data
      cout << "\n\nEnter hours worked (-1 to end): ";
      cin >> hours;
   } // end while
} // end main

// Exercise 4.17 Solution: ex04_17.cpp
// Finding the largest number.
#include <iostream>
#include <iomanip> // parameterized stream manipulators
using namespace std; 

int main()
{
   int counter = 0; // counter for 10 repetitions 
   int number = 0; // current number input
   int largest = 0; // largest number found so far
   
   cout << "Enter the first number: "; // prompt for first number
   cin >> largest; // get first number

   while ( ++counter < 10 ) // loop 10 times
   {
      cout << "Enter the next number : "; // prompt for next input 
      cin >> number; // get next number
      
      // if current number input is greater than largest number,
      // update largest
      if ( number > largest )
         largest = number;
   } // end while
   
   cout << "Largest is " << largest << endl; // display largest number
} // end main

//Find the two largest numbers;
#include <iostream>
using namespace std;

int main()
{
	int number = 0; //current number input
	int largest = 0; //largest number found
	int secondLargest = 0; //second-largest number found
	
	cout << "Enter the first number: ";
	cin >> largest;
	
	cout << "Enter next number: ";
	cin >> number;
	
	//compare second number with first number
	if(number > largest)
	{
		secondLargest = largest;
		largest = number;
	}
	else
		secondLargest = number;
	
	unsigned int counter = 2; //counter for remaining inputs
	
	//get rest of the numbers and find the largest and secondLargest
	while(counter < 10)
	{
		cout << "Enter next number: ";  //prompt for next number
		cin >> number; //get next number
		
		//compare current number with largest and secondLargest
		if(number > largest)
		{
			secondLargest = largest;
			largest = number;
		}
		else if(number > secondLargest)
			secondLargest = number;
		
		++counter;
	}
	
	cout << "\nLargest is " << largest << "\nSecond largest is " << secondLargest << endl;
	
	return 0;
}

// Exercise 4.19 Solution: ex04_19.cpp
// Find the two largest numbers.
#include <iostream>
using namespace std; 

int main()
{
   int number = 0; // current number input
   int largest = 0; // largest number found
   int secondLargest = 0; // second-largest number found

   cout << "Enter the first number: "; // prompt for first number
   cin >> largest; // get first number
      
   cout << "Enter next number: "; // prompt for second number
   cin >> number; // get second number
   
   // compare second number with first number
   if ( number > largest )
   {
      secondLargest = largest;
      largest = number;
   } // end if
   else
      secondLargest = number;

   unsigned int counter = 2; // counter for remaining inputs 

   // get rest of the numbers and find the largest and secondLargest
   while ( counter < 10 ) 
   {
      cout << "Enter next number: "; // prompt for next number
      cin >> number; // get next number
         
      // compare current number with largest and secondLargest
      if ( number > largest ) 
      {
         secondLargest = largest;
         largest = number;
      } // end if
      else if ( number > secondLargest )
         secondLargest = number;

      ++counter; // increment counter
   } // end while

   // display largest two numbers
   cout << "\nLargest is " <<  largest 
      << "\nSecond largest is " << secondLargest << endl;
} // end main

//Examination results problem: Validating input.
#include <iostream>
using namespace std;

int main()
{
	// initializing variables in declarations
   unsigned int passes = 0; // number of passes
   unsigned int failures = 0; // number of failures
   unsigned int studentCounter = 1; // student counter
   unsigned int result = 0; // one exam result (1 = pass, 2 = fail)

   // process 10 students using counter-controlled loop
   while ( studentCounter <= 10 )
   {
      // prompt user for input and obtain value from user
      cout << "Enter result (1 = pass, 2 = fail): ";
      cin >> result;

      if ( result == 1 ) // 1 is a valid input
      {
         passes = passes + 1; // increment passes
         studentCounter = studentCounter + 1; // increment studentCounter
      } // end if
      else if ( result == 2 ) // 2 is a valid input
      {
         failures = failures + 1; // increment failures
         studentCounter = studentCounter + 1; // increment studentCount
      } // end else if
      else // invalid input; tell user and prompt again
      {
         cout << "Invalid input" << endl;
      } // end else
   } // end while

   // termination phase; display number of passes and failures
   cout << "Passed " << passes << "\nFailed " << failures << endl;

   // determine whether more than eight students passed
   if ( passes > 8 )
      cout << "Bonus to instructor!" << endl;
} // end main

// Exercise 4.23 Solution: ex04_23.cpp
// Dangling-else problem. 
#include <iostream>
using namespace std;

int main()
{
   // part A, x=9 and y=11
   unsigned int x = 9;
   unsigned int y = 11;
   cout << "Output for part A, x=9 and y=11:" << endl;
   
   if(x < 10)
	   if(y > 10)
		   cout << "*****" << endl;
	   else
		   cout << "#####" << endl;
	   
	cout << "$$$$$" << endl;
	
	//part A, x=11 and y=9
	x = 11;
	y = 9;
	   cout << endl << "Output for part A, x=11 and y=9:" << endl;

   if ( x < 10 )
      if ( y > 10 )
         cout << "*****" << endl; 
      else
         cout << "#####" << endl;

   cout << "$$$$$" << endl;

   // part B, x=9 and y=11
   x = 9;
   y = 11;
   cout << endl << "Output for part B, x=9 and y=11:" << endl;
   
   if ( x < 10 )
   {
      if ( y > 10 )
         cout << "*****" << endl;  
   } // end outer if
   else
   {
      cout << "#####" << endl;
      cout << "$$$$$" << endl;
   } // end else

   // part B, x=11 and y=9
   x = 11;
   y = 9;
   cout << endl << "Output for part B, x=11 and y=9:" << endl;
   
   if ( x < 10 )
   {
      if ( y > 10 )
         cout << "*****" << endl;  
   } // end outer if
   else
   {
      cout << "#####" << endl;
      cout << "$$$$$" << endl;
   } // end else
} // end main

=======================================

// Exercise 4.24 Solution: ex04_24.cpp
// Dangling-else problem.
#include <iostream>
using namespace std;

int main()
{
    unsigned int x = 5; // initialize x to 5
    unsigned int y = 8; // initialize y to 8

    // part a
    if (y == 8)
    {
        if (x == 5)
            cout << "@@@@@" << endl;
        else
            cout << "#####" << endl;
    } // end if

    cout << "$$$$$" << endl;
    cout << "&&&&&" << endl << endl;

    // part b
    if (y == 8)
    {
        if (x == 5)
            cout << "@@@@@" << endl;
        else
        {
            cout << "#####" << endl;
            cout << "$$$$$" << endl;
            cout << "&&&&&" << endl;
        } // end inner else
    } // end outer if

    cout << endl;

    // part c
    if (y == 8)
    {
        if (x == 5)
            cout << "@@@@@" << endl;
        else
        {
            cout << "#####" << endl;
            cout << "$$$$$" << endl;
        } // end inner else
    } // end outer if

    cout << "&&&&&" << endl << endl;

    // part d
    y = 7;

    if (y == 8)
    {
        if (x == 5)
            cout << "@@@@@" << endl;
    } // end if
    else
    {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
        cout << "&&&&&" << endl;
    } // end else
} // end main

// Exercise 4.25 Solution: ex04_25.cpp
// Displaying a square of asterisks.
#include <iostream>
using namespace std;

int main()
{
	unsigned int stars = 0; //number of stars on a side
	unsigned int column = 0; //the current column of the square being printed
	unsigned int row = 1; //the current row of the square being printed
	
	//prompt and read the length of the side from the user
	cout << "Enter length of side: ";
	cin >> stars;
	
	//valid input, if invalid, set to default
	if(stars < 1)
	{
		stars = 1;
		cout << "Invalid Input\nUsing default value 1\n";
	}
	else if(stars > 20)
	{
		stars = 20;
		cout << "Invalid Input\nUsing default value 20";
	}
	
	//repeat for as many rows as the user entered
	while(row <= stars)
	{
		column = 1;
		
		//and for as many columns as rows
		while(column <= stars)
		{
			if(row == 1)
				cout << "*";
			else if(row == stars)
				cout << "*";
			else if(column == 1)
				cout << "*";
			else if(column == stars)
				cout << "*";
			else
				cout << " ";
			
			++column;
		}
		cout << endl;
		++row;
	}
}

#include <cstdio>
using namespace std;

int N;         // using global variables in contests can be a good strategy
char x[110];  // make it a habit to set array size a bit larger than needed

int main() {
  scanf("%d\n", &N);
  while (N--) {                  // we simply loop from N, N-1, N-2, ..., 0
    scanf("0.%[0-9]...\n", &x);   // `&' is optional when x is a char array
                         // note: if you are surprised with the trick above,
                      // please check scanf details in www.cppreference.com
    printf("the digits are 0.%s\n", x);
} } // return 0;

I/O:
----
3
0.1227...
0.517611738...
0.7341231223444344389923899277...

package Factorial;
import java.util.Scanner;
import java.math.BigInteger;

/**
 *
 * @author jubms
 */
public class Factorial {
    
    public static void main(String[] args) {
        BigInteger fac = BigInteger.ONE;
        
        for(int i = 2; i <= 25; i++)
            fac = fac.multiply(BigInteger.valueOf(i)); //it is in the library
        
        System.out.println(fac);
    }
    
}

Output:
------
15511210043330985984000000


