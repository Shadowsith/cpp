#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

class Hcin{
    public:
        static std::string HideInput(){
        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        std::string s;
        getline(std::cin, s);
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return s;

        }


};

int main()
{
/*
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    std::string s;
    getline(std::cin, s);

    //std::cout << s << std::endl;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
*/
    std::string test = Hcin::HideInput(); 
    std::cout << test << std::endl;
}//main 
