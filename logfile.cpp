#include "logfile.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

logfile::logfile()
{
    //ctor
     srand ( time(NULL) );
    maxLength=1800000;
    currentfile="all.log";
}


int logfile::fileSize(char * fname)
{
    /*
ifstream file (fname);
int size = (int) file.tellg();
file.close();
return size;
    */

FILE * pFile;
  long size;

  pFile = fopen (fname,"rb");
  if (pFile==NULL) perror ("Error opening file");
  else
  {
    fseek (pFile, 0, SEEK_END);
    size=ftell (pFile);
    fclose (pFile);
    return (int) size;
  }
}

char * logfile::generateEnding()
{
     int num = rand() % 10000 + 1;
     char catted[15];      //will never be more then this
     catted[0]='\0';
     char Buffer[8];
     itoa (num,Buffer,10);
     //cout<<(char)num;    //causes weird beeping==BAD
  strcat (catted,"all-");
  strcat (catted,Buffer);
  strcat (catted,".log");
     //cout<<catted;
  ifstream test;
  test.open(catted);
     if (test.is_open())
        {
        test.close();
        return catted;
        }
    else
        generateEnding();

}

string logfile::addTime()
{
     time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  return asctime (timeinfo);

}

int logfile::write(std::string data)
{
    cout<<"writing";
  ofstream myfile;
  if (fileSize(currentfile)>maxLength)
        currentfile=generateEnding();   //this is a problem

    myfile.open (currentfile,ios::app);
    myfile << data;
    myfile.close();
    return 1;//success, written

}

int logfile::write(int data)
{
  ofstream myfile;
   if (fileSize(currentfile)>maxLength)
        currentfile=generateEnding();
  myfile.open (currentfile,ios::app);
  myfile << data;
  myfile.close();
  return 1;//success, written
}



int logfile::write(std::string data,std::string arg)
{
    if (arg=="-v"){cout<<data;}
  ofstream myfile;
   if (fileSize(currentfile)>maxLength)
        currentfile=generateEnding();
  myfile.open (currentfile,ios::app);
  myfile << data;
  myfile.close();
  return 1;//success, written
}

int logfile::write(int data,std::string arg)
{
    if (arg=="-v"){cout<<data;}
  ofstream myfile;
   if (fileSize(currentfile)>maxLength)
        currentfile=generateEnding();
  myfile.open (currentfile,ios::app);
  myfile << data;
  myfile.close();
  return 1;//success, written
}
