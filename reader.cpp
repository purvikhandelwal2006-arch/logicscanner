#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream f("input.txt");
    string s;
    while(getline(f,s)){
         cout<<s<<endl;
    }
    return 0;
}