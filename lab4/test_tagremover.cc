#include "TagRemover.h"
#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void TEST1()
{
    fstream file;
    fstream resfile;
    TagRemover tr(file);

    string i = tr.translate("<html>hej</html>");
    assert(i == "<html>hej</html>");

    string j = tr.removeTags("<html>hej</html>");
    assert(j == "hej");

    cout << "TEST 1 OK" << endl;
}

void TEST2()
{
    fstream file;
    fstream resfile;
    TagRemover tr(file);

    string k = tr.translate("&amp;hej&nbsp;&lt;&gt;");
    assert(k == "&hej <>");

    cout << "TEST 2 OK" << endl;
}

int main()
{
    TEST1();
    TEST2();
}