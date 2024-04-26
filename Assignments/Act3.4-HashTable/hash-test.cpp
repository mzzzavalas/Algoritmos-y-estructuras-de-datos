#include <iostream>
#include <vector>
using namespace std;

#include "HashStudentId.h"
int main() {

    HashStudentId hash;
    hash.insert("00");
    hash.insert("83");
    hash.insert("73");
    hash.insert("32");
    hash.print();
    // hash.remove("6");
    cout << hash.findStudentId("00") << endl;
    hash.insert("52");
    hash.print();


    return 0;
}
