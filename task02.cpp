#include <iostream>
#include <string>

using namespace std;

// task 01
class Person { // Class Person
private:
	string _name;
	string _sex;
	int _age;
	float _weight;
		
public:
	void changeName (string name) {this->_name = name;}	
	void setAge (int age) {this->_age = age;}	
	void setWeight (int weight) {this->_weight = weight;}
	string printName() {return this->_name;}
	
	Person (string name = "Name") {this->_name = name;}	
	~Person () {}
};

class Student : public Person { // Class Student
private:
	string _name;
	int _year;
	static int _quant;
	
public:
	void setYear (int year) {this->_year = year;}
	void incYear () {this->_year++;}
	static int getQuant () {return Student::_quant;}
	
	Student(string name);
	~Student();
}; 

int Student::_quant = 0;
// constr outside init
Student::Student (string name = "Student"):Person(name) {
		this->_year = 2000;
		Student::_quant++;
	}
// destr outside init	
Student::~Student () {
    Student::_quant--;
}

void print_stud (Student *st) { 
	cout << "I am " << st->printName() << "\n\r";
	cout << "There are " << st->getQuant() << " zadrots available\n\r";
}

class Fruit {
	private:
		string _name;
		string _colour;
	public:
		string getName () {
			return this->_name;			
		}
		string getColour () {
			return this->_colour;
		}
		// constr destr
		Fruit (string colour, string name) {
			_colour = colour;
			_name = name;
		}
		Fruit (string colour) {
			_colour = colour;
		}
		Fruit () {
			_colour = "colour";
			_name = "name";
		}
		
		~Fruit () {}		
};

class Apple : public Fruit {
	public:
		Apple (string colour = "red", string name = "apple") : Fruit(colour, name){
		}
		~Apple () {}	
};

class Banana : public Fruit {
	public:
		Banana (string colour = "yellow", string name = "banana") : Fruit(colour, name){
		}
		~Banana () {}	
};

class GrannySmith : public Apple {
	public:
		GrannySmith (string colour = "green", string name = "garanny smith") : Apple(colour, name){
		}
		~GrannySmith () {}	
};

int main (void) {
	// test 01
	Person Ivan; // default "Name" 
	cout << Ivan.printName() << "\n\r";
	Ivan.changeName("Borys");
	cout << Ivan.printName() << "\n\r";
	
	Student Vasyl; // default "Student"
	cout << Vasyl.printName() << "\n\r";
	Vasyl.changeName("Sergey");
	cout << Vasyl.printName() << "\n\r";	
	
	Student *phantom = new Student("Casper");
	cout << "\n\r";
	print_stud(phantom);
	delete phantom;
	cout << "Casper has gone\n\r";
	// dec Students quant
	print_stud(&Vasyl);
	
	Student zadrot_1("Zadrot_1");
	print_stud(&zadrot_1);
	
	Student zadrot_2("Zadrot_2");
	print_stud(&zadrot_2);
	
	Student zadrot_3("Zadrot_3");
	print_stud(&zadrot_3);
	
	cout << "\n\r\n\r";
	
	// test 02
	Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColour() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColour() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColour() << ".\n";
	
	return 0;
}
