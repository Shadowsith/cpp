#ifndef MYSQL_CONNECTOR_H
#define MYSQL_CONNECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <mysql_connection.h>

#include <mysql_driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class MySQL_Connector{
    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        std::string server;
        std::string username;
        std::string password;
        std::string scheme;

    public:
        MySQL_Connector();
        MySQL_Connector(std::string server);
        MySQL_Connector(std::string server, std::string username);
        //~MySQL_Connector();
        void setScheme(std::string scheme);
        void dropCreate(std::string table, std::string values);
        void create(std::string table, std::string values); //only if not exists
        void insert();
        void insert(std::string table, std::string rows, std::string values);
        void insert(std::string table, std::vector<std::string> rows, std::vector<std::string> values);
        void select();
        void select(std::string rows, std::string from, std::string where);
        void deleteConnetor();

};


#endif
