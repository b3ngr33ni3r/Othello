#include "vectorcontroller.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

vectorController* vectorController::pointer_to_vectorController=NULL;

vectorController::vectorController()
{
    //ctor
}

void vectorController::newNode()
{
    node temp;
    cells.push_back(temp);
    return;
}

 vectorController* vectorController::get()
{
    if(pointer_to_vectorController==NULL)
    pointer_to_vectorController=new vectorController();

    return pointer_to_vectorController;
}
