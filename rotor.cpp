#include "rotor.h"

Rotor::Rotor(char a[])
{
                  char b[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                  for(int i = 0; i < 26; i++) {
                          change[i] = (a[i] - b[i] + 26)%26;
                          backchange[(change[i] + i)%26] = (26 - change[i])%26;
                  }
}

int Rotor::Substitute(int code, int rotorchange)
{
    code += (change[(code + rotorchange)%26])%26;
    return code%26;
}

int Rotor::BackSubstitute(int code, int rotorchange)
{
    code += backchange[(code + rotorchange)%26];
    return code%26;
}

int Rotor::getChange(int i)
{
    return change[i];
}

int Rotor::getBackChange(int i)
{
     return backchange[i];
}
