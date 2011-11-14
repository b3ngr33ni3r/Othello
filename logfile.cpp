#include "logfile.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <cstring>



/*
*   im not, NOT going to comment this file, because it does very little, in a lot of differnet ways
*   basically, it logs things to all.log
*   theres conversion functions, and write things.
*/






using namespace std;

logfile::logfile()
{
    //ctor
     srand ( time(NULL) );
    maxLength=1800000;
    currentfile="all.log";
}


bool logfile::checkfor(std::string me)
{
    ifstream f;
    string line;

    f.open("all.log");

    if (f.is_open())
    {
        while ( !f.eof() )
        {
            getline (f,line);


            if (line.find(me)!=string::npos)
            {
                return true;
            }

        }
        f.close();
    }

    return false;
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
  ofstream test;
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




/*
 *  The getTime functions below provide easy access to an int value of the EST time of the system.
 *  _sec,_min,_hr are the choices.
 *
 */
int logfile::getTime_sec()
{

    time_t rawtime;
    struct tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );
    int hr= (ptm->tm_hour-5)%24;
    int min= ptm->tm_min;
    int sec= ptm->tm_sec;
    return sec;
}

int logfile::getTime_hr()
{

    time_t rawtime;
    struct tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );
    int hr= (ptm->tm_hour-5)%24;
    int min= ptm->tm_min;
    int sec= ptm->tm_sec;
    return hr;
}

int logfile::getTime_min()
{

    time_t rawtime;
    struct tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );
    int hr= (ptm->tm_hour-5)%24;
    int min= ptm->tm_min;
    int sec= ptm->tm_sec;
    return min;
}

int logfile::write(std::string data)
{

  ofstream myfile;
  //if (fileSize(currentfile)>maxLength)
 //       currentfile=generateEnding();   //this is a problem

    myfile.open (currentfile,ios::app);
    myfile << data;
    myfile.close();
    return 1;//success, written

}

int logfile::write(int data)
{
  ofstream myfile;
//   if (fileSize(currentfile)>maxLength)
 //       currentfile=generateEnding();
  myfile.open (currentfile,ios::app);
  myfile << data;
  myfile.close();
  return 1;//success, written
}



int logfile::write(std::string data,std::string arg)
{
    if (arg=="-v"){cout<<data;}
  ofstream myfile;
 //  if (fileSize(currentfile)>maxLength)
 //       currentfile=generateEnding();
  myfile.open (currentfile,ios::app);
  myfile << data;
  myfile.close();
  return 1;//success, written
}

int logfile::write(int data,std::string arg)
{
    if (arg=="-v"){cout<<data;}
  ofstream myfile;
 //  if (fileSize(currentfile)>maxLength)
 //       currentfile=generateEnding();
  myfile.open (currentfile,ios::app);
  myfile << data;
  myfile.close();
  return 1;//success, written
}
