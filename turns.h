#ifndef TURNS_H
#define TURNS_H

namespace movement{
    enum{
    moveUp=-1,
    moveDown=1,
    moveLeft=-8,
    moveRight=8,
    diagUL=-9,
    diagDL=-7,
    diagUR=7,
    diagDR=9
    };}


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

