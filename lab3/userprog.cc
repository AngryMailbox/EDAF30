#include <iostream>
#include "User.h"
#include "UserTable.h"
using namespace std;

int main()
{
    UserTable userTable = UserTable("C:\\Users\\mans\\Documents\\projekt\\labs-edaf30\\lab3\\users.txt");

    cout << userTable.find(21330) << endl;
    cout << userTable.find(21331) << endl;
    cout << userTable.find("Jens Holmgren") << endl;
    testFindNbr(userTable);
    return 0;
}