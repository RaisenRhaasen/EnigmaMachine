#include "position.h"

Position::Position(char a[])
{
                        for(int i = 0; i < 3; i++) {
                                if(a[i] <= 'Z' && a[i] >= 'A') {
                                        a[i] = a[i] + 32;
                                }
                        }
                        
                        position1 = a[0] - 'a';
                        position2 = a[1] - 'a';
                        position3 = a[2] - 'a';
}

void Position::Step()
{
    position3 = (position3 + 1)%26;
    
    if(position3 == 23 && position2 == 4) {
                 position1 = (position1 + 1)%26;
                 position2 = (position2 + 1)%26;
    }
    
    if(position3 == 22) {
                 position2 = (position2 + 1)%26;
    }
}

int Position::Pos1()
{
    return position1;
}

int Position::Pos2()
{
    return position2;
}

int Position::Pos3()
{
    return position3;
}
