// bar.h
// header file which creates a single bar - containing a name, value, and category

#include <iostream>
#include <string>
#include "myrandom.h"
using namespace std;

// Bar Class
class Bar {
 private:
    string name;
    int value;
    string category;

 public:

    // default constructor:
    Bar() {
        name = "";
        value = 0;
        category = "";
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
        this->name = name;
        this->value = value;
        this->category = category;
    }

    // destructor:
    virtual ~Bar() {
    }

    // getName:
	string getName() {
        return name;
	}

    // getValue:
	int getValue() {
        return value;
	}

    // getCategory:
	string getCategory() {
        return category;
	}
	// operator overloads - comparison operators
	bool operator<(const Bar &other) const {
        if (this->value < other.value) {
            return true;
        }
        return false;
	}

	bool operator<=(const Bar &other) const {
        if (this->value <= other.value) {
            return true;
        }
        return false;
	}

	bool operator>(const Bar &other) const {
        if (this->value > other.value) {
            return true;
        }
        return false;
	}

	bool operator>=(const Bar &other) const {
        if (this->value >= other.value) {
            return true;
        }
        return false;
	}
	
	// equality operator
	bool operator==(const Bar &other) const {
        if (this->value == other.value && this->name == other.name && this->category == other.category) {
            return true;
        }
        return false;
	}
	
	// copy operator
	Bar& operator=(const Bar& other) {
	    if (this == &other) {
	        return *this;
	    }
	    name = other.name;
	    value = other.value;
	    category = other.category;
	    
	    return *this;
	}
};

