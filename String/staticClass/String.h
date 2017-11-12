#include <string>
#include <vector>

class String{

    public:

        // string formatting
        static bool equals(std::string &str1, std::string &str2);
        static int indexOf(std::string &str, std::string fin);
        static int lastIndexOf(std::string &str, std::string fin);
        static std::vector<std::string> split (std::string &str, std::string split);
        static std::string replace(std::string &str, std::string oldstr, std::string newstr);
        static std::string replaceFirst(std::string &str, std::string oldstr, std::string newstr);
        static std::string replaceLast(std::string &str, std::string oldstr, std::string newstr);
        static std::string replaceHead(std::string &str, int headsize, std::string newstr);
        static std::string replaceTail(std::string &str, int tailsize, std::string newstr);
        static std::string erase(std::string &str, std::string erasestr); 
        static std::string eraseFirst(std::string &str, std::string erasestr); 
        static std::string eraseLast(std::string &str, std::string erasestr); 
        static std::string eraseHead(std::string &str, int headsize); 
        static std::string eraseTail(std::string &str, int tailsize); 
        static std::vector<char> toCharArr(std::string &str);
        static std::string toUpper(std::string &str);
        static std::string toLower(std::string &str);
        static std::string trim(std::string &str);
        static std::string trimLeft(std::string &str);
        static std::string trimRight(std::string &str);
        static std::string normPathUnix(std::string &str);
        static std::string normPathWindows(std::string &str);

        //casts to numbers without references
        static short toShort(std::string &str);
        static int toInt(std::string &str);
        static long toLong(std::string &str);
        static float toFloat(std::string &str);
        static double toDouble(std::string &str);

        //cast to string without references
        static std::string fromShort(short &num);
        static std::string fromInt(int &num);
        static std::string fromLong(long &num);
        static std::string fromFloat(float &num);
        static std::string fromDouble(double &num);
};
