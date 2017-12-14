#include "DyeText.h"
#include "textformat.h"
#include <string>
#include <iostream>

namespace text{

    // foreground colors----------------------------------------------
    std::string black(std::string str){
        str = FORM_BEGIN + std::to_string(BLACK) + "m" + str + FORM_END;    
        return str;
    }

    std::string black(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(RED) + "m" + str + FORM_END_MULTILINE;
        else
            str = black(str);
        return str;
    }

    std::string red(std::string str){
        str = FORM_BEGIN + std::to_string(RED) + "m" + str + FORM_END;    
        return str;
    }

    std::string red(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(RED) + "m" + str + FORM_END_MULTILINE;
        else
            str = red(str);
        return str;
    }

    std::string green(std::string str){
        str = FORM_BEGIN + std::to_string(GREEN) + "m" + str + FORM_END;    
        return str;
    }

    std::string green(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(GREEN) + "m" + str + FORM_END_MULTILINE;
        else
            str = green(str);
        return str;
    }

    std::string yellow(std::string str){
        str = FORM_BEGIN + std::to_string(YELLOW) + "m" + str + FORM_END;    
        return str;
    }

    std::string yellow(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(YELLOW) + "m" + str + FORM_END_MULTILINE;
        else
            str = yellow(str);
        return str;
    }

    std::string blue(std::string str){
        str = FORM_BEGIN + std::to_string(BLUE) + "m" + str + FORM_END;    
        return str;
    }

    std::string blue(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(BLUE) + "m" + str + FORM_END_MULTILINE;
        else
            str = blue(str);
        return str;
    }

    std::string magenta(std::string str){
        str = FORM_BEGIN + std::to_string(MAGENTA) + "m" + str + FORM_END;    
        return str;
    }

    std::string magenta(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(MAGENTA) + "m" + str + FORM_END_MULTILINE;
        else
            str = magenta(str);
        return str;
    }

    std::string cyan(std::string str){
        str = FORM_BEGIN + std::to_string(CYAN) + "m" + str + FORM_END;    
        return str;
    }

    std::string cyan(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(CYAN) + "m" + str + FORM_END_MULTILINE;
        else
            str = cyan(str);
        return str;
    }

    std::string white(std::string str){
        str = FORM_BEGIN + std::to_string(WHITE) + "m" + str + FORM_END;    
        return str;
    }

    std::string white(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(WHITE) + "m" + str + FORM_END_MULTILINE;
        else
            str = white(str);
        return str;
    }

    // background colors----------------------------------------------
    std::string black_bg(std::string str){
        str = FORM_BEGIN + std::to_string(BG_BLACK) + "m" + str + FORM_END;    
        return str;
    }

    std::string black_bg(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(BG_RED) + "m" + str + FORM_END_MULTILINE;
        else
            str = black_bg(str);
        return str;
    }

    std::string red_bg(std::string str){
        str = FORM_BEGIN + std::to_string(BG_RED) + "m" + str + FORM_END;    
        return str;
    }

    std::string red_bg(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(BG_RED) + "m" + str + FORM_END_MULTILINE;
        else
            str = red_bg(str);
        return str;
    }

    std::string green_bg(std::string str){
        str = FORM_BEGIN + std::to_string(BG_GREEN) + "m" + str + FORM_END;    
        return str;
    }

    std::string green_bg(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(BG_GREEN) + "m" + str + FORM_END_MULTILINE;
        else
            str = green_bg(str);
        return str;
    }

    std::string yellow_bg(std::string str){
        str = FORM_BEGIN + std::to_string(BG_YELLOW) + "m" + str + FORM_END;    
        return str;
    }

    std::string yellow_bg(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(BG_YELLOW) + "m" + str + FORM_END_MULTILINE;
        else
            str = yellow_bg(str);
        return str;
    }

    std::string blue_bg(std::string str){
        str = FORM_BEGIN + std::to_string(BG_BLUE) + "m" + str + FORM_END;    
        return str;
    }

    std::string blue_bg(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(BG_BLUE) + "m" + str + FORM_END_MULTILINE;
        else
            str = blue_bg(str);
        return str;
    }

    std::string magenta_bg(std::string str){
        str = FORM_BEGIN + std::to_string(BG_MAGENTA) + "m" + str + FORM_END;    
        return str;
    }

    std::string magenta_bg(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(BG_MAGENTA) + "m" + str + FORM_END_MULTILINE;
        else
            str = magenta_bg(str);
        return str;
    }

    std::string cyan_bg(std::string str){
        str = FORM_BEGIN + std::to_string(BG_CYAN) + "m" + str + FORM_END;    
        return str;
    }

    std::string cyan_bg(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(BG_CYAN) + "m" + str + FORM_END_MULTILINE;
        else
            str = cyan_bg(str);
        return str;
    }

    std::string white_bg(std::string str){
        str = FORM_BEGIN + std::to_string(BG_WHITE) + "m" + str + FORM_END;    
        return str;
    }

    std::string white_bg(std::string str, bool multiline){
        if(multiline == true)
            str = FORM_BEGIN + std::to_string(BG_WHITE) + "m" + str + FORM_END_MULTILINE;
        else
            str = white_bg(str);
        return str;
    }


    // formatting-----------------------------------------------------

    std::string underline(std::string str){
        str = FORM_BEGIN + std::to_string(UNDERLINE) + "m" + str + FORM_END;    
        return str;
    }
}

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

int main(void){
    std::string s = "Hello World!";
    for (int i = 0; i < s.length(); i++) {
        std::cout << text::red(s.at(i)) << std::endl;    
    }
}
