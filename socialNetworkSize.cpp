#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstdlib>

using namespace std;
int main(){
    ifstream inFile;
    inFile.open("SocialNetwork.txt");
    if(inFile.fail()){
        cerr<<"File cannot open"<<endl;
        exit(1);
    }
    set<string> socialNetwork;
    string firstName, secondName;
    while(!inFile.eof()){
        getline(inFile,firstName,',');
        getline(inFile,secondName,'\n');
        socialNetwork.insert(firstName);
        socialNetwork.insert(secondName);
    }
    cout<<"The total number of people in the social network is : "<<socialNetwork.size();
    return 0;
}

