#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
string extractblock(ifstream &f,string &line){
    string block=line+"\n";
    int openbraces=0;
    for(char c:line){
        if(c=='{') openbraces++;
        if(c=='}')openbraces--;
    }
    string temp;
    while(openbraces>0 && getline(f,temp)){
        block+=temp+"\n";
        for(char c :temp){
            if(c=='{') openbraces++;
            if(c=='}')openbraces--;
        }
    }
    return block;
}
int main(){
    ifstream f("input.txt");
    string s;
    vector<string> logicblock;
    int ifcount=0;
    int forcount=0;
    int whilecount=0;
    while (getline(f,s)){
        if(s.find("if")!=string::npos){
            int pos=s.find("if");
            int j = pos + 2;
         while(s[j] == ' ' || s[j] == '\t') j++;
         if(s[j] == '('){
            string block = extractblock(f, s);
              logicblock.push_back(block);
               ifcount++;
             }

        }
        if(s.find("for")!=string::npos){
            int pov=s.find("for");
            int j = pov + 3;
         while(s[j] == ' ' || s[j] == '\t') j++;
         if(s[j] == '('){
                string block = extractblock(f, s);
                logicblock.push_back(block);
               forcount++;
             }
        }
        if(s.find("while")!=string::npos){
            int poc=s.find("while");
            int j = poc + 5;
         while(s[j] == ' ' || s[j] == '\t') j++;
         if(s[j] == '('){
             string block = extractblock(f, s);
                logicblock.push_back(block);
               whilecount++;
             }
        }
    }
    for(int i=0;i<logicblock.size();i++){
        cout<<logicblock[i]<<endl;
    }
    return 0;
}