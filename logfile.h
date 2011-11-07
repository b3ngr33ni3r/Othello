#ifndef LOGFILE_H
#define LOGFILE_H
#include <string>
#include <fstream>

class logfile
{
    public:
        logfile();
        int write(std::string data);
        int write(int data);
        int write(std::string data,std::string arg);
        int write(int data,std::string arg);
        int fileSize(char * fname);
        std::string addTime();
        int getTime_sec();
        int getTime_min();
        int getTime_hr();
        char * generateEnding();
        bool checkfor(std::string me);
    protected:
    private:
    int maxLength;
    char * currentfile;
};

#endif // LOGFILE_H
