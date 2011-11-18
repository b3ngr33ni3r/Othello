#ifndef SCANCONTROLLER_H
#define SCANCONTROLLER_H


class scanController
{
    public:
        scanController();
        static scanController* get();

        bool direction_isvalid(int cell,int direction,bool internal=false);
        bool cell_isoccupied(int cell);
    protected:
    private:
    static scanController* scan_pointer;
};

#endif // SCANCONTROLLER_H
