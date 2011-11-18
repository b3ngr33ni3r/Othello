#ifndef TURNS_H
#define TURNS_H


class turns
{
    public:
        turns();
        static turns* get();
        int turn;
    protected:
    private:
    static turns* turns_pointer;
};

#endif // TURNS_H
