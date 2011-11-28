#ifndef SCANCONTROLLER_H
#define SCANCONTROLLER_H
#include <string>

class scanController
{
    public:
        scanController();
        static scanController* get();

        bool direction_isvalid(int cell,int direction,bool internal=false);
        bool cell_isoccupied(int cell);
        void checks(int i);
        void print_cells(std::string type,std::string key);
    protected:
    private:
    int get_last_valid_space_index();
    void reset_last_valid_space_index();

    static scanController* scan_pointer;
    int last_valid_cell;
};

#endif // SCANCONTROLLER_H
