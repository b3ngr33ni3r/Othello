#include "vectorcontroller.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

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
