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

string logfile::generateEnding()
{
     int num = rand() % 10000 + 1;
     char catted[15];//will never be more then this
  strcat (catted,"all-");
  strcat (catted,(const char *)num);
  strcat (catted,".log");
     ifstream test (catted);
     //if success VV else recurse
return catted;
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
  ofstream myfile;
  if (fileSize("all.log")<maxLength)
  {
    myfile.open ("all.log",ios::app);
    myfile << data;
    myfile.close();
    return 1;//success, written
  }else{
    //myfile.open ("all"+generateEnding()+".log",ios::app);  //rewrite new ending and use that file enstead
    myfile << data;
    myfile.close();
    return 1;//success, written
  }
}

int logfile::write(int data)
{
  ofstream myfile;
  myfile.open ("all.log",ios::app);
  myfile << data;
  myfile.close();
  return 1;//success, written
}



int logfile::write(std::string data,std::string arg)
{
    if (arg=="-v"){cout<<data;}
  ofstream myfile;
  myfile.open ("all.log",ios::app);
  myfile << data;
  myfile.close();
  return 1;//success, written
}

int logfile::write(int data,std::string arg)
{
    if (arg=="-v"){cout<<data;}
  ofstream myfile;
  myfile.open ("all.log",ios::app);
  myfile << data;
  myfile.close();
  return 1;//success, written
}
