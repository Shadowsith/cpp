#ifndef DYETEXT_H
#define DYETEXT_H


#include <string>


class DyeText{
    private:
        const std::string FORM_BEGIN = "\033[";
        const std::string FORM_END = "\033[";

        enum COLOR {  
            BLACK = 0,
            RED,
            GREEN,
            YELLOW,
            BLUE,
            MAGENTA,
            CYAN,
            WHITE,
        }; 

        enum FORMAT {
            RESET = 0,
            BOLD,
            UNDERLINE,
            INVERSE,
            BOLD_OFF,
            UNDERLINE_OFF,
            INVERSE_OFF,
        };

        const std::string fgColor[8] {
            "30m",
            "31m",
            "32m",
            "33m",
            "34m",
            "35m",
            "36m",
            "37m"
        };

        const std::string bgColor[8] {
            "40m",
            "41m",
            "42m",
            "43m",
            "44m",
            "45m",
            "46m",
            "47m",
        };

        const std::string format[7] {
            "0m",
            "1m",
            "4m",
            "7m",
            "21m",
            "24m",
            "27m",
        };


    public:
        std::string black(std::string str);
        std::string red(std::string str);
        std::string green(std::string str);
        std::string yellow(std::string str);
        std::string blue(std::string str);
        std::string magenta(std::string str);
        std::string cyan(std::string str);
        std::string white(std::string str);

        std::string blackBG(std::string str);
        std::string redBG(std::string str);
        std::string greenBG(std::string str);
        std::string yellowBG(std::string str);
        std::string blueBG(std::string str);
        std::string magentaBG(std::string str);
        std::string cyanBG(std::string str);
        std::string whiteBG(std::string str);

        std::string bold(std::string str);
        std::string underline(std::string str);
        std::string inverse(std::string str);

        void dyePrint(std::string str);
};

#endif
