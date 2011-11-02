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
        std::string generateEnding();
    protected:
    private:
    int maxLength;
};

#endif // LOGFILE_H
