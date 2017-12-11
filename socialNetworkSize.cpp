#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstdlib>

//Function declaration
void count_people_in_social_network(std::ifstream&);
//count_people_in_social_network - counts the number of people in a social network
int main(){
    std::ifstream infile;
    infile.open("SocialNetwork.txt");
    count_people_in_social_network(infile);
    std::cin.get();
    return 0;
}
//Function definition
void count_people_in_social_network(std::ifstream& inFile){
   if(inFile.fail()){
        std::cerr<<"File cannot open"<<std::endl;
        exit(1);
    }
    std::set<std::string> socialNetwork;
    std::string left_name, right_name;
    while(!inFile.eof()){
        getline(inFile,left_name,',');
        getline(inFile,right_name,'\n');
        socialNetwork.insert(left_name);
        socialNetwork.insert(right_name);
    }
    std::cout<<"The total number of people in the social network is : "<<socialNetwork.size()<<std::endl;
}
