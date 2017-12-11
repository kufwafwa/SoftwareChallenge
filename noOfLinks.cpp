#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>

#define FIRST_NAME "STACEY_STRIMPLE"
#define SECOND_NAME "RICH_OMLI"

//Function declaration
void count_no_of_links(std::ifstream&, std::string, std::string);
//count_no_of_links - counts the shortest number of links between 2 friends in a social network

int main()
{
    std::ifstream infile;
    std::string firstname, secondname;
#ifdef FIRST_NAME
    firstname = FIRST_NAME;
#else
    std::cout<<"Please enter the first name : ";
    std::cin>>firstname;
#endif // NAME_A
#ifdef SECOND_NAME
    secondname = SECOND_NAME;
#else
    std::cout<<"Please enter the second name : ";
    std::cin>>secondname;
#endif
    count_no_of_links(infile,firstname,secondname);
    std::cin.get();
    return 0;
}

//Function definition
void count_no_of_links(std::ifstream& inFile, std::string first_name, std::string second_name)
{
    inFile.open("SocialNetwork.txt");
    if(inFile.fail())
    {
        std::cerr<<"File cannot open"<<std::endl;
        exit(1);
    }

    if (second_name.compare(first_name)==0)
    {
        std::cout<<first_name<<" and "<<second_name<<" are the same person "<<std::endl;
    }
    else
    {
        std::vector<std::string> socialNetwork;
        std::string left_name,right_name;
        while(!inFile.eof())
        {
            getline(inFile,left_name,',');
            getline(inFile,right_name,'\n');
            socialNetwork.push_back(left_name);
            socialNetwork.push_back(right_name);
        }
        std::set<std::string> current_level_links, next_level_links;
        std::set<std::string>::iterator name_to_check;
        std::string name;
        unsigned int no_of_links=0;

        current_level_links.insert(first_name);
        name_to_check = current_level_links.begin();
        bool found=false, no_link=false;
        while(found==false)
        {
            if(socialNetwork.size()==0)
            {
                std::cout<<"The social network is empty"<<std::endl;
                no_link=true;
                break;
            }
            else
            {
                while(current_level_links.size()!=0)
                {
                    name_to_check = current_level_links.begin();
                    name=*name_to_check;
                    current_level_links.erase (name_to_check);
                    for (unsigned i=1; i < socialNetwork.size()+1; i++)
                    {
                        if(socialNetwork[i-1].compare(name)==0)
                        {
                            if(i%2==0)
                            {
                                if(socialNetwork[i-2].compare(second_name)==0)
                                {
                                    found=true;
                                    break;
                                }
                                else
                                {
                                    next_level_links.insert(socialNetwork[i-2]);
                                    socialNetwork.erase(socialNetwork.begin()+i-1);
                                    socialNetwork.erase(socialNetwork.begin()+i-1);
                                    i--;
                                }
                            }
                            else
                            {
                                if(socialNetwork[i].compare(second_name)==0)
                                {
                                    found=true;
                                    break;
                                }
                                else
                                {
                                    next_level_links.insert(socialNetwork[i]);
                                    socialNetwork.erase(socialNetwork.begin()+i-1);
                                    socialNetwork.erase(socialNetwork.begin()+i-1);
                                    i--;
                                }
                            }
                        }
                    }
                }
            }
            if(next_level_links.size()!=0 )
            {
                current_level_links=next_level_links;
                next_level_links.clear();
                no_of_links++;
            }
            else
            {
                if (found!=true)
                {
                    no_of_links=0;
                }
                else
                {
                    no_of_links++;
                }
                socialNetwork.clear();
                break;
            }
        }
        std::cout<<"The distance between "<< first_name<<" and "<<second_name<<" is : "<<no_of_links<< " link(s)"<<std::endl;
    }
}
