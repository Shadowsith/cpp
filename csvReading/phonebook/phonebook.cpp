#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>

class Pbook {
    
    private:
        std::fstream m_f;
        std::string m_name;
        std::string m_tel;
        std::string m_addr;

    public:
    void writeIn();
    void printPhoneBook();

};

void Pbook::writeIn(){
    
    std::cout << "Gebe einen Namen ein: ";
    std::getline(std::cin,m_name);

    std::cout << "Gebe eine Telefonnummer ein: ";
    std::getline(std::cin,m_tel);


    std::cout << "Gebe eine Adresse ein: ";
    std::getline(std::cin,m_addr);
    
    m_f.open("Phonebook.csv", std::fstream::in | std::fstream::out | std::fstream::app);

    m_f << m_name << ";" << m_tel << ";" << m_addr << std::endl;

    m_f.close();
}

void Pbook::printPhoneBook(){
    m_f.open("Phonebook.csv");
    std::string line;
    std::vector<std::string> parts;
    if(m_f.good()){
        while(std::getline(m_f,line)){
            boost::split(parts,line,boost::is_any_of(";"));
            std::cout << parts[0] << "\t" << parts[1] << "\t" << parts[2] << std::endl;
            parts.clear();
        }
    }
    
    m_f.close();

}

int main(void){

    Pbook p;
    //p.writeIn();
    //p.writeIn();
    p.printPhoneBook();
}
