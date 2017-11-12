#include <string>
#include <vector>

class String{
    
    private:
        std::string m_str;
        std::vector<std::string> m_parts; // saving parts from last String.split
        std::vector<char> m_cList; // saving vector of chars form last String.

    public:
        //constructors
        String(std::string str);
        String(const char* c);
        String(std::vector<std::string> strvec);
        String(std::vector<char> cvec);
        String(short num);
        String(int num);
        String(long num);
        String(float num);
        String(double num);

        //operators
        operator std::string() const; // save String obj to std::string
        String& operator= (std::string str); // save std::string to String
        String& operator= (const char* c); // save char* to String

        friend bool operator== (const String &S1, const String &S2); // String and String
        friend bool operator== (const std::string str, const String &S); // std::string and String
        friend bool operator== (const String &S, const std::string str); // String and std::string

        friend String operator+ (const String &S1, const String &S2);
        friend String operator+ (std::string str, const String &S);
        friend String operator+ (const String &S, std::string str);

        friend std::ostream& operator<< (std::ostream &out, const String &S);
        friend std::istream& operator>> (std::istream &is, String &S);

        //getters 
        std::string get();
        int size();
        inline int getSize();
        int length();
        inline int getLength();
        char charAt(int pos);
        inline char getCharAt(int pos);
        std::vector<char> charList();
        inline std::vector<char> getCharList();
        std::vector<std::string> getParts(); // to get Parts of a void str.split

        //setters
        void set(std::string str);

        // string formatting
        bool isEmpty();
        bool compare(std::string &str);
        inline bool equals(std::string &str);
        int findFirst(std::string find);
        inline int indexOf(std::string find);
        int findLast(std::string find);
        inline int lastIndexOf(std::string find);
        void split (std::string split);
        std::vector<std::string> splitBack(std::string split);
        void replace(std::string oldstr, std::string newstr);
        void replaceFirst(std::string oldstr, std::string newstr);
        void replaceLast(std::string oldstr, std::string newstr);
        void replaceHead(int headsize, std::string newstr);
        void replaceTail(int tailsize, std::string newstr);
        void erase(std::string erasestr); 
        void eraseFirst(std::string erasestr); 
        void eraseLast(std::string erasestr); 
        void eraseHead(int headsize); 
        void eraseTail(int tailsize); 
        void toUpper();
        void toLower();
        void trim();
        void trimLeft();
        void trimRight();
        void normPathUnix();
        void normPathWindows();

        //cast to numbers
        short toShort();
        int toInt();
        long toLong();
        float toFloat();
        double toDouble();
};
