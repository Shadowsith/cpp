#include <iostream>

class String
{

public:
	String(void);//default sets string to NULL
	String(const char* input);//Takes in a string and creates an object
	String(const String & S);//Copy constructor
	~String(void);//Destructor deletes the nstring at the end
    
    
	int length();//displays length of string excluding null
	char& at(int loc);// returns a chracter at specified loc-1
	bool empty();// if string is empty returns true else it returns false
    void swap(String& from);// swaps the contents of two strings
	int find (const String& S, int index =0);
	String substr(int index, int length);// returns an object which is the substring of the object that calls it

friend std::ostream& operator << (std::ostream & OS,const String &S);// out stream displays the string
friend std::istream& operator >> (std::istream & IS,String &S);//instream takes in a string and creates and object
String& operator = (const String& S);//if A and B are object B is "neil", the A =B therefore A is "neil"
friend  bool operator ==(const String& S1, const String & S2);// checks if both strings are equal
friend String operator + (const String& S1, const String & S2);//still buggy

private:
	char* nstring;
	short nlength;
};



