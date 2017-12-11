#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("SocialNetwork.txt");
    if(inFile.fail())
    {
        cerr<<"File cannot open"<<endl;
        exit(1);
    }
    vector<string> socialNetwork;
    set<string> check, nextCheck;
    set<string>::iterator it;
    string firstName, secondName;
    while(!inFile.eof())
    {
        getline(inFile,firstName,',');
        getline(inFile,secondName,'\n');
        socialNetwork.push_back(firstName);
        socialNetwork.push_back(secondName);
    }
    firstName = "STACEY_STRIMPLE";
    secondName= "RICH_OMLI";
    check.insert(firstName);
    it = check.begin();
    int noOfLinks=1;
    bool found=false, notLinked=false;
    if (secondName.compare(firstName)==0)
    {
        cout<<"A and B are the same person "<<endl;
    }
    else
    {
        while(found==false)
        {
            if(socialNetwork.empty()!=true)
            {
                while(check.empty() !=true)
                {
                    it = check.begin();
                    firstName=*it;
                    check.erase (it);

                    for (unsigned i=1; i < socialNetwork.size()+1; i++)
                    {

                        if(socialNetwork[i-1].compare(firstName)==0)
                        {
                            if((i-1)%2==0)
                            {
                                if(socialNetwork[i+1-1].compare(secondName)==0)
                                {
                                    found=true;
                                    i=socialNetwork.size()+1;
                                }
                                else
                                {
                                    nextCheck.insert(socialNetwork[i+1-1]);
                                    socialNetwork.erase(socialNetwork.begin()+i+1-1);
                                    socialNetwork.erase(socialNetwork.begin()+i+1-1);
                                    i--;
                                }
                            }
                            else
                            {
                                if(socialNetwork[i-1-1].compare(secondName)==0)
                                {
                                    found=true;
                                    i=socialNetwork.size()+1;
                                }
                                else
                                {
                                    nextCheck.insert(socialNetwork[i-1-1]);
                                    socialNetwork.erase(socialNetwork.begin()+i-1);
                                    socialNetwork.erase(socialNetwork.begin()+i-1);
                                    i--;
                                }
                            }
                        }
                    }

                }
                if(nextCheck.empty()==true)
                {
                    notLinked=true;
                    found=true;
                }
                else
                {
                    check=nextCheck;
                    nextCheck.clear();
                    noOfLinks++;
                }

            }
            else
            {
                notLinked=true;
                found=true;
            }
        }

        if(notLinked)
        {
            cout<<"A and B are not linked "<<endl;
        }
        else
        {
            cout<<"The distance between A and B is : "<<noOfLinks<< " links"<<endl;
        }
    }
    return 0;
}
