#ifndef PATHCONTROLLER_H
#define PATHCONTROLLER_H


class pathController
{
    public:
        pathController();
        static pathController* get();
        void pathHandler();
    protected:
    private:
        static pathController* path_pointer;
        void path(int i,int direction);
};

#endif // PATHCONTROLLER_H
