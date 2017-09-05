#include <iostream>
#include "rotor.h"
#include "rotor.cpp"
#include "position.h"
#include "position.cpp"

int ReflectPlug(int, int*);

using namespace std;

int main()
{
    Rotor rotor3("BDFHJLCPRTXVZNYEIWGAKMUSQO");
    Rotor rotor2("AJDKSIRUXBLHWTMCQGZNPYFVOE");
    Rotor rotor1("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
    char reflect[27] = "AYBRCUDHEQFSGLIPJXKNMOTZVW";
    char plugtemp[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    char a[3];
    cout << "Rotor Positions: " << flush;
    cin >> a;
    Position pos(a);
    
    char temp[128];
    cout << "Code: " << flush;
    cin >> temp;
    
    int count = 0;
    for(count = 0; temp[count] != '\0'; count++);
    
    int code[count];
    for(int i = 0; i < count; i++) {
            code[i] = (temp[i] - 'a')%26;
    }
    
    int reflector[26], plug[26];
    for(int i = 0; i < 26; i++) {
            reflector[i] = reflect[i] - 'A';
            plug[i] = plugtemp[i] - 'A';
    }
    
    for(int i = 0; i < count; i++) {
            pos.Step();
            int k = code[i];
            char ans = 'a';
            k = ReflectPlug(k, plug);
            k = rotor3.Substitute(k, pos.Pos3());
            k = rotor2.Substitute(k, pos.Pos2());
            k = rotor1.Substitute(k, pos.Pos1());
            k = ReflectPlug(k, reflector);
            k = rotor1.BackSubstitute(k, pos.Pos1());
            k = rotor2.BackSubstitute(k, pos.Pos2());
            k = rotor3.BackSubstitute(k, pos.Pos3());
            k = ReflectPlug(k, plug);
            ans = k + 'a';
            cout << ans;
    }
    
    cout << endl;
    system("pause");
}

int ReflectPlug(int code, int reflector[])
{
     for(int i = 0; i < 26; i++)
     {
             if((code)%26 == reflector[i])
             {
                     if(i % 2 == 0)
                     {
                          code = reflector[(i+1)%26];
                          return code%26;
                     }
                     else
                     {
                          code = reflector[(i-1)%26];
                          return code%26;
                     }
             }
     }
};
