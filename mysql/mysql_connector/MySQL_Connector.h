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
#include <cppconn/resultset_metadata.h>

class MySQL_Connector{
    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        sql::ResultSetMetaData *res_meta;
        std::string server;
        std::string username;
        std::string password;
        std::string schema;

    public:
        MySQL_Connector();
        MySQL_Connector(std::string server);
        MySQL_Connector(std::string server, std::string username);
        MySQL_Connector(std::string server, std::string username, std::string password);
        //virtual ~MySQL_Connector();
        void createSchema(std::string schema);
        void dropSchema(std::string schema);
        inline void createDatabase(std::string database); //alias of createSchema
        inline void dropDatabase(std::string database); //alias of dropSchema
        void setSchema(std::string schema); 
        void dropTable(std::string table);
        void dropRecreateTable(std::string table, std::string columns);
        void createTable(std::string querry);
        void createTable(std::string table, std::string columns); //only if not exists
        void insert(std::string querry);
        void insert(std::string table, std::string columns, std::string values);
        void insert(std::string table, std::vector<std::string> rows, std::vector<std::string> values);
        void update(std::string querry);
        void update(std::string table, std::string set_, std::string where);
        void select(std::string querry);
        void select(std::string columns, std::string from);
        void select(std::string columns, std::string from, std::string where);
        std::vector<std::string> resSelect(std::string querry);
        std::vector<std::string> resSelect(std::string columns, std::string from);
        std::vector<std::string> resSelect(std::string columns, std::string from, std::string where);
        void deleteConnetor();
        std::vector<std::string> selector;
};


#endif
