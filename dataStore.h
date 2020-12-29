//json.hpp library is used to work with json objects in cpp  https://github.com/nlohmann/json/releases/tag/v3.9.1
#include "json.hpp"
#include <bits/stdc++.h>
#include <fstream>
// for convenience
using json = nlohmann::json;
using namespace std;


//All the data will be saved to the file "pretty.json"
//A temporary file is used "temp.json" to to do the necessary calc. where necessary
//pretty.json will be created automatically when first time the Create() function is called
void Create(string key,json value,int time_to_live=0)
{
    //Checking if key out of constraints or not
    if(key.size()>32)
    {
        cout<<"Key is too big to store"<<endl;
        return;
    }

    //Checking if value is JSON obj or not
    if(!value.is_object())
    {
        cout<<"Not valid value (Enter JSON object only)"<<endl;
        return ;
    }

    //For calc. the size of JSON obj
    //
    ofstream temp_file("temp.json");
    temp_file << setw(4) << value;
    temp_file.close();


    //Checking if json obj is out of constriants or not
    if(sizeof(temp_file)>1024*16)
    {
        cout<<"Value is too big to store"<<endl;
        return;
    }
    //


    //Opening file to read data from it

    //

    ifstream i;

    i.open("pretty.json");


    // if file not found(not created)

    //
    if(!i)
    {
        json j;

        j[key]=value;

        j[key].push_back({"time_created",time(0)});
        j[key].push_back({"time_to_live",time_to_live});


        //Writing the Key-Value in file
        ofstream o("pretty.json");
        o << std::setw(4) << j;
        o.close();

        cout<<"Entry Created Successfully"<<endl;

        return ;

    }

    //

    //If file was created earlier

    json j;
    i >> j;
    i.close();


    //Checking if key already exists or not
    if(j.find(key)!=j.end())
    {
        cout<<"Key already exsits"<<endl;
        return ;
    }

    j[key]=value;


    //appending time of creation of the key
    j[key].push_back({"time_created",time(0)});
    //appending time to live of the key
    j[key].push_back({"time_to_live",time_to_live});


    //Calc if file limit exceeds 1GB or not
    //
    ofstream temp_file1("temp.json");
    temp_file1 << std::setw(4) << j;
    temp_file1.close();


    if(sizeof(temp_file1)>1024*1024*1024)
    {
        cout<<"Memory limit exceeded"<<endl;
        return;
    }
    //

    //Writting the data into the file
    ofstream o("pretty.json");
    o << std::setw(4) << j;
    o.close();

    cout<<"Entry Created Successfully"<<endl;


    return ;

}


void Read(string key)
{
    ifstream i;

    i.open("pretty.json");

    //If file doesn't exists
    if(!i)
    {
        cout<<"Key doesn't exist"<<endl;
        return;
    }


    json j;
    i >> j;
    i.close();

    //If key does't exists
    if(j.find(key)==j.end())
    {
        cout<<"Key doesn't exist"<<endl;
        return;
    }


    //Calc. the time spent of the key from creation till now
    int time_spent=time(0)-(long int)j[key]["time_created"];


    if(j[key]["time_to_live"]==0 || (j[key]["time_to_live"]>=time_spent))
        cout<<j[key]<<endl;
    
    else
        cout<<"Key expires cannot access now"<<endl;

    return;

}


void Delete(string key)
{
    ifstream i;

    i.open("pretty.json");

    //If file doesn't exists
    if(!i)
    {
        cout<<"Key doesn't exist"<<endl;
        return ;
    }

    json j;
    i >> j;
    i.close();

    //If key does't exists
    if(j.find(key)==j.end())
    {
        cout<<"Key doesn't exsits"<<endl;
        return ;
    }


    //Calc. the time spent of the key from creation till now
    int time_spent=time(0)-(long int)j[key]["time_created"];


    if(j[key]["time_to_live"]==0 || (j[key]["time_to_live"]>=time_spent))
        {
            //Deleting key from the file
            j.erase(key);
            ofstream o("pretty.json");
            o << std::setw(4) << j;
            o.close();   
            cout<<"Key deleted successfully"<<endl;
            return;
        }
    
    else
        cout<<"Key expires cannot access now"<<endl;

    return;
   
}
//End of Code
