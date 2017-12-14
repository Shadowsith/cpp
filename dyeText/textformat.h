#ifndef TEXTFOMAT_H
#define TEXTFOMAT_H

#include <string>

namespace text{

    const std::string FORM_BEGIN = "\033[";
    const std::string FORM_END = "\033[0m";
    const std::string FORM_END_MULTILINE = "\033[";

    enum FG_COLOR {  
        BLACK = 30,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,
    };

    enum BG_COLOR { 
        BG_BLACK = 40,
        BG_RED,
        BG_GREEN,
        BG_YELLOW,
        BG_BLUE,
        BG_MAGENTA,
        BG_CYAN,
        BG_WHITE,

    };

    enum FORMAT {
        RESET = 0,
        BOLD,
        UNDERLINE = 4,
        INVERSE = 7,
        BOLD_OFF = 21,
        UNDERLINE_OFF = 24,
        INVERSE_OFF = 27,
    };

    //fg colors
    std::string black(std::string str);
    std::string black(std::string str, bool multiline);
    std::string red(std::string str);
    std::string red(std::string str, bool multiline);
    std::string green(std::string str);
    std::string green(std::string str, bool multiline);
    std::string yellow(std::string str);
    std::string yellow(std::string str, bool multiline);
    std::string blue(std::string str);
    std::string blue(std::string str, bool multiline);
    std::string magenta(std::string str);
    std::string magenta(std::string str, bool multiline);
    std::string cyan(std::string str);
    std::string cyan(std::string str, bool multiline);
    std::string white(std::string str);
    std::string white(std::string str, bool multiline);

    //bg colors
    std::string black_bg(std::string str);
    std::string black_bg(std::string str, bool multiline);
    std::string red_bg(std::string str);
    std::string red_bg(std::string str, bool multiline);
    std::string green_bg(std::string str);
    std::string green_bg(std::string str, bool multiline);
    std::string yellow_bg(std::string str);
    std::string yellow_bg(std::string str, bool multiline);
    std::string blue_bg(std::string str);
    std::string blue_bg(std::string str, bool multiline);
    std::string magenta_bg(std::string str);
    std::string magenta_bg(std::string str, bool multiline);
    std::string cyan_bg(std::string str);
    std::string cyan_bg(std::string str, bool multiline);
    std::string white_bg(std::string str);
    std::string white_bg(std::string str, bool multiline);


    std::string underline(std::string str);

}

#endif
