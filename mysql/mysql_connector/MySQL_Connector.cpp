#include "MySQL_Connector.h"

MySQL_Connector::MySQL_Connector(){
    std::cout << "\nConnecting to Database" << std::endl;
    std::cout << "Enter MySQL server address:";
    std::cin >> this->server;
    std::cout << "Enter username:";
    std::cin >> this->username;
    std::cout << "Enter password";
    std::cin >> this->password; // must be make saver

    this->driver = sql::mysql::get_mysql_driver_instance();
    this->con = this->driver->connect(this->server,this->username,this->password);

    this->stmt = NULL;
    this->res = NULL;
}

MySQL_Connector::MySQL_Connector(std::string server){
    std::cout << "\nConnecting to Database at: " << server << std::endl;
    this->server = server;
    std::cout << "Enter username:";
    std::cin >> this->username;
    std::cout << "Enter password";
    std::cin >> this->password; // must be make saver

    this->driver = sql::mysql::get_mysql_driver_instance();
    this->con = this->driver->connect(this->server,this->username,this->password);
}

MySQL_Connector::MySQL_Connector(std::string server, std::string username){
    std::cout << "\nConnecting to Database at: " << server << std::endl;
    this->server = server;
    this->username = username;
    std::cout << "Hello " << username << " enter password ";
    std::cin >> this->password; // must be make saver

    this->driver = sql::mysql::get_mysql_driver_instance();
    this->con = this->driver->connect(this->server,this->username,this->password);

    this->stmt = NULL;
    this->res = NULL;
}

void MySQL_Connector::setScheme(std::string scheme){
    this->scheme = scheme;
    this->stmt = this->con->createStatement();
    this->stmt->execute("USE " + this->scheme);
}

void MySQL_Connector::dropCreate(std::string table, std::string values){
    this->stmt->execute("DROP TABLE IF EXISTS " + table);
    this->stmt->execute("CREATE TABLE " + table + "(" + values + ")");
}

void MySQL_Connector::deleteConnetor(){
    if (this->con != NULL)
        delete this->con;
    if (this->stmt != NULL)
        delete this->stmt;
    if (this->res != NULL)
        delete this->res;
}

int main(void){

    MySQL_Connector connect("localhost:3306","shadowsith");
    connect.setScheme("test_scheme");
    connect.dropCreate("new_test","id INT NOT NULL AUTO_INCREMENT, name VARCHAR(40) NOT NULL, PRIMARY KEY (id)");
    connect.deleteConnetor();
}
