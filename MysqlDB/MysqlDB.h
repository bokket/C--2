//
// Created by bokket on 2020/11/25.
//

#ifndef C_2_MYSQLDB_H
#define C_2_MYSQLDB_H



class MysqlDB
{
    MysqlDB();
    ~MysqlDB();
    void Open(const char* host,
              const char* user,
              const char* passwd,
              const char* db,
              unsigned int port);
    void Close();

    unsigned long long ExecSQL(const char* sql);
    MysqlRecordset QuerySQL(const char* sql);

    unsigned long long GetInsertID() const;
    void StartTransaction();
    void Commit();
    void Rollback();

private:
    MYSQL* mysql_;
};


#endif //C_2_MYSQLDB_H
