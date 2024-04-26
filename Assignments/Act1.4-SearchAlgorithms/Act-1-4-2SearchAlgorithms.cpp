//Mauricio Zavala Sánchez
//A00837332
//ITC
// 9/8/2023
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string strings(vector<string> list,int cant, int cont){
    while(cont<cant){
        string nuevoString;
        cout << "Ingresa el string #" << cont + 1 << ": ";
        cin >> nuevoString;
        list.push_back(nuevoString); // Agregar el string al vector
        cont++;
    }
    cout << "Los strings ingresados son:" << endl;
    int x=0;
    for (const string& str : list) {
        for(int i = 0; i < str.size(); i++){
            for (int j=0; j <str.size();j++){
                //cout<<str[i]<<endl;
                //cout<<str[j]<<endl;
                cout<<str[i,j]<<endl;
                if(str[i]==str[j]){
                    x++;
                }
                cout<<x<<endl;
            
            }
        }  
    }
}

int main(){
    int cant;
    int cont;
    vector<string> list;
    cout<<"Ingrese el numero de strings: ";
    cin>>cant;
    strings(list,cant,cont);




   



    return 0;
}



