#include <iostream>
#include <cmath>
#include <stdint.h>

using namespace std;

// task 1
class Power {
private:
	float _base;
	float _pow;
public:
	Power(){ //default set
		_base = 5.0;
		_pow = 2.0;	
	}
	Power(float base, float pow){ //constr
		_base = base;
		_pow = pow;
	}
	double calculate(){
		return pow(_base, _pow);
	}
	int set(float base, float pow){
		_base = base;
		_pow = pow;
	}
	~Power () {}				
};

// task 2
class RGBA {
private:
	uint8_t m_red;
	uint8_t	m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
public:
	RGBA () {
		m_red = 0;
		m_green = 0;
		m_blue = 0;
		m_alpha = 255;
	}
	RGBA (uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
		m_red = red;
		m_green = green;
		m_blue = blue;
		m_alpha = alpha;
	}
	void print () {
		cout << (int)m_red << " " << (int)m_green << " " << (int)m_blue << " " << (int)m_alpha << "\n\r";
	}
	~RGBA () {}	
};

// task 3
class Stack {
private:
	static const int len = 10;
	int data[len];
	int index;
public:
	Stack () {
		index = 0;
	}
	void reset () {
		index = len;
		while (index) {
			data[index - 1] = 0;
			index--;
		}
	}
	bool push (int d) {
		if (index == len) {
			return false;
		} else {
			index++;
			data[index - 1] = d;
			return true;
		}		
	}
	int pop (void) {
		if (!index) {
			cout << "There's no data stored in the stack\n\r";
			return 0;			
		} else {
			return data[index--];
		}
	}
	void print (void) {
		int i = 0;
		for (i = 0; i < index; i++) {
			cout << data[i] << ' ';
		}
		cout << "\n\r";
	}
	~Stack () {}		
};

int main (void){
	// test 1	
	Power pow_def;
	cout << pow_def.calculate() << "\n\r";
	Power pow_1(3, 8);
	cout << pow_1.calculate() << "\n\r";
	pow_1.set(5, 8);
	cout << pow_1.calculate() << "\n\r";
	// test 2
	RGBA pixel1;
	RGBA pixel2(20, 62, 22, 9);
	pixel1.print();
	pixel2.print();
	// test 3
	Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();

	return 0;
}
