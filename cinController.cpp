#include "cinController.h"
#include "scanController.h"
#include "pathController.h"
#include <iostream>

cinController* cinController::cin_pointer=NULL;

cinController::cinController()
{
    //ctor
}

 cinController* cinController::get()
{
    if(cin_pointer==NULL)
    cin_pointer=new cinController();

    return cin_pointer;
}

void cinController::cinHandler()
{
    std::cout<<"\n=======================\n= cinHandler() ACTIVE =\n=======================\n";
    std::string command;
    std::cout<<">>";
    std::cin>>command;
    process(command);
    std::cout<<"\n=========================\n= cinHandler() INACTIVE =\n=========================\n";

}

void cinController::process(std::string cmd)
{
    int temp;
    if (cmd=="scanController::get()->checks"){
            std::cout<<"int:";
            std::cin>>temp;
            scanController::get()->checks(temp);
    }else if (cmd=="pathController::get()->pathHandler"){
            pathController::get()->pathHandler();
    }
}

