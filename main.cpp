#include <iostream>
#include "ternary.h"
#include <limits>
#include <cstdlib>
#include <cstring>

using namespace std;

int main( int argc, char *argv[] )
{
    int trytelength=11;
    short byte=0;
    short tryte[trytelength];
    bool once=false;
    bool verbose=false;
    bool cset=false;

    if ( argc > 1 ) {
     for (int i = 1; i < argc; i++) {
      if ( strcmp(argv[i], "-v") == 0 ) {
       verbose=true;
      }
      else {
       once=true;
       cset=true;
       byte=atoi(argv[i]);
      }
     }
    }

    do{
      if (!cset) {
      cout << "Eingabe:     ";
      cin >> byte;
      }
      if(cin.fail()) {
       if(cin.eof()) {
        cout << endl;
        return 0;
       }
       cout << "Eingabe ungültig" << endl;
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
      }else{
       if (verbose) cout << "Dezimal:     " << byte << endl;
       var_to_tryte(byte, tryte);
       if (verbose) {
       cout << "Ternär Bal.: ";
       for(char i=0;i<11;i++)
       {
        cout << tryte[i] << " ";
       }
       cout << endl;
       cout << "Ternär Bal.: ";
       }
       bool lzero = true;
       for(char i=0;i<11;i++)
       {
        if(tryte[i]==-1)
        {
         cout << "-";
         lzero = false;
        }
        if(tryte[i]==1)
        {
         cout << "+";
         lzero = false;
        }
        if(tryte[i]==0 && (!lzero || i == trytelength - 1))
        {
         cout << "0";
        }
       }
       cout << endl;
       byte++;
      }
    if (once) return 0;
    }while(1);
    return 0;
}
