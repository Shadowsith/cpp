#include <string>
#include <vector>

class String{

    public:


        // static ones
        static bool equals(std::string &str1, std::string &str2);
        int findFirst(std::string &str, std::string fin);
        static std::vector<std::string> split (std::string &str, std::string split);
        static std::string toUpper(std::string &str);
        static std::string toLower(std::string &str);
        static std::string trim(std::string &str);
        static std::string trimLeft(std::string &str);
        static std::string trimRight(std::string &str);

        //casts
        static short toShort(std::string &str);
        static int toInt(std::string &str);
        static long toLong(std::string &str);
        static float toFloat(std::string &str);
        static double toDouble(std::string &str);

};
