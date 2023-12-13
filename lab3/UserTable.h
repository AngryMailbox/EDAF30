#ifndef USERTABLE_H
#define USERTABLE_H

#include <iostream>

#include "User.h"

class UserTable
{
public:
    UserTable();
    UserTable(const std::string &);
    ~UserTable()
    {
        delete[] users;
    }
    // UserTable(const UserTable &) = delete; // This makes UserTable non-copyable

    void addUser(const User &);
    User find(int) const;
    User find(std::string) const;

    int getNbrUsers() const
    {
        return nbrUsers;
    }

    void print(std::ostream &) const;

    static const User user_not_found;

private:
    int capacity{1000};
    void ensureCapacity(int);
    int nbrUsers{0};
    int pos{0};
    User *users;

    friend int testFindNbr(const UserTable ut);
};
#endif
