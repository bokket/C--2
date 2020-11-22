//
// Created by bokket on 2020/11/22.
//

#include <iostream>
#include <string>
#include <Scanner.h>
#include <Parse.h>
using namespace std;

int main()
{
    do {
        cout<<"> ";
        string buf;
        getline(cin,buf);
        cout<<buf<<endl;
        Scanner scanner(buf);
        Parser parser(scanner);
        parser.Parse();
        parser.Calculate();
    }
}