#include <string>
#include <vector>

class String{
    
    private:
        std::string m_str;
        std::vector<std::string> m_parts; // saving parts from last String.split
        std::vector<char> m_cList; // saving vector of chars form last String.

    public:
        //constructors
        String();

        String(const std::string str);
        
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
        String& operator= (String s);
        String& operator= (std::string str); // save std::string to String
        String& operator= (const char* c); // save char* to String

        bool operator== (const String &S); // String and String
        bool operator== (const std::string str); // std::string and String

        String& operator+= (const String &S);
        String& operator+= (const std::string str);
        String& operator+= (const char* c);
        String& operator+= (const char c); 

        char& operator[] (int pos);

        friend std::ostream& operator<< (std::ostream &out, const String &S);
        friend std::istream& operator>> (std::istream &is, const String &S);

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
        
        //TODO
        bool isNull();
        bool isNullOrEmpty();
        bool isNullOrWhiteSpace();
        bool isTab();
        bool isTabOrWhiteSpace();
        //---

        bool compare(std::string &str);
        inline bool equals(std::string &str);

        template<typename T1, typename T2>
        inline T1& concat(T1& a, T2& b);

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
        void fillLeft(int length, char fill);
        inline void padLeft(int length, char fill);
        void fillRight(int length, char fill);
        inline void padRight(int length, char fill);
        void normPathUnix();
        void normPathWindows();

        //cast to numbers
        short toShort();
        int toInt();
        long toLong();
        float toFloat();
        double toDouble();
};

inline String operator+ (String lhs, const String& rhs); 
inline String operator+ (String lhs, const std::string& rhs);
inline String operator+ (String lhs, const char* rhs);
inline String operator+ (String lhs, const char rhs);
