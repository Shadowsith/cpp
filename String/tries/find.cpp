#include <iostream>

int stringFind(std::string find, std::string& source){
    if(find.length() <= 1){
        for(int i = 0; i < source.length(); i++){
            if(find.at(0) == source.at(i)){
                return i;
            }
        }
    }
    else{
        int j = 0;
        for(int i = 0; i < source.length(); i++){
            if(find.at(0) == source.at(i) && 
            (source.length()-i) >= find.length()){
                for(int i = 0; i < find.length(); i++){
                    if(find.at(i) == source.at(i)){
                        j++;
                    }
                    else break;
                    if(j == find.length())
                        break;
                }
                if(j == find.length())
                    std::cout << "df" << std::endl;
                    return i;
            }
        }
    }
    return 0;
}

int lengthComp(std::string find, std::string& source){
    int j = 0;
    for(int i = 0; i < find.length(); i++){
        if(find.at(i) == source.at(i)){
            j++;
        }
        if(j == find.length())
            break;
    }
    if(j == find.length())
        return 1;
    return 0;

}

int main(void){
    std::string str = "ddblab";
    std::string a = "a";
    int i = stringFind("bla",str);
    std::cout << i << std::endl;
}
