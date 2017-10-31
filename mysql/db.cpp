#include <iostream>
#include <string>
#include <mysql_connection.h>

#include <mysql_driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

//for hiding console password input
#include <termios.h>
#include <stdio.h>

// not in use yet
class User {
    private:
        int id;
        std::string firstname;
        std::string lastname;
};

int main(void){

    sql::mysql::MySQL_Driver *driver; // need to get mysql driver
    sql::Connection *con; // handels SQL Connection
    sql::Statement *stmt; // handels SQL Statements (UPDATE...) 
    sql::ResultSet *res;  // handels result of SELECT statements 

    std::string username;
    std::string password;
    
    driver = sql::mysql::get_mysql_driver_instance();


    //User Connection
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    con = driver->connect("localhost:3306",username,password);


    stmt = con->createStatement();
    /*
    stmt->execute("USE test_scheme");
    //stmt->execute("DROP TABLE IF EXISTS test");
    //stmt->execute("CREATE TABLE test(id INT, label CHAR(1))");
    //stmt->execute("INSERT INTO test(id, label) VALUES (1, 'a')");
    res = stmt->executeQuery("SELECT id, firstname, lastname FROM user WHERE id = 4"); 
    while (res->next()){

        std::cout << "Id = " << res->getInt(1) << std::endl;
        std::cout << "Firstname = " << res->getString("firstname") << std::endl;
        std::cout << "Lastname = " << res->getString("lastname") << std::endl;
    }
    */


    // delete all before program end
    // prevent memory overflow on microcontroler
    //delete res;
    delete stmt;
    delete con;
    return 0;
}
