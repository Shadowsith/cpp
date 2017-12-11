#include "DyeText.h"
#include <string>
#include <iostream>

// foreground colors------------------------------------------------------

std::string DyeText::black(std::string str){
    str = FORM_BEGIN + fgColor[BLACK] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::red(std::string str){
    str =  FORM_BEGIN + fgColor[RED] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::green(std::string str){
    str =  FORM_BEGIN + fgColor[GREEN] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::yellow(std::string str){
    str =  FORM_BEGIN + fgColor[YELLOW] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::blue(std::string str){
    str =  FORM_BEGIN + fgColor[BLUE] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::magenta(std::string str){
    str =  FORM_BEGIN + fgColor[MAGENTA] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::cyan(std::string str){
    str =  FORM_BEGIN + fgColor[CYAN] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::white(std::string str){
    str =  FORM_BEGIN + fgColor[WHITE] + str + FORM_END + format[RESET];
    return str;
}


// background colors------------------------------------------------------

std::string DyeText::blackBG(std::string str){
    str = FORM_BEGIN + bgColor[BLACK] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::redBG(std::string str){
    str = FORM_BEGIN + bgColor[RED] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::greenBG(std::string str){
    str = FORM_BEGIN + bgColor[GREEN] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::yellowBG(std::string str){
    str = FORM_BEGIN + bgColor[YELLOW] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::blueBG(std::string str){
    str = FORM_BEGIN + bgColor[BLUE] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::magentaBG(std::string str){
    str = FORM_BEGIN + bgColor[MAGENTA] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::cyanBG(std::string str){
    str = FORM_BEGIN + bgColor[CYAN] + str + FORM_END + format[RESET];
    return str;
}

std::string DyeText::whiteBG(std::string str){
    str = FORM_BEGIN + bgColor[WHITE] + str + FORM_END + format[RESET];
    return str;
}

// formatting--------------------------------------------------------------

std::string DyeText::bold(std::string str){
    str = FORM_BEGIN + format[BOLD] + str + FORM_END;
    return str;
}

std::string DyeText::underline(std::string str){
    str = FORM_BEGIN + format[UNDERLINE] + str + FORM_END;
    return str;
}

std::string DyeText::inverse(std::string str){
    str = FORM_BEGIN + format[INVERSE] + str + FORM_END;
    return str;
}

void DyeText::dyePrint(std::string str){
    std::cout << str << std::endl;
}

