#pragma once
using namespace std;
#include <string>
#include <map>

struct IP{
    int ip;
    int cont;
    IP();
    IP(int ip, int cont);


};

IP::IP(){

}

IP::IP(int ip, int cont){
    this->ip=ip;
}

