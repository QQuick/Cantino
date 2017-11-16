#include <cantino.h>

using namespace cantino;

char aString [32];
char aChar;
unsigned char aUChar;
int anInt;
unsigned int aUInt;
long aLong;
unsigned long aULong;
float aFloat;

int main () {
    cout << "cstr char uchar int uint long ulong float" << endl;
    cin >> aString >> aChar >> aUChar >> anInt >> aUInt >> aLong >> aULong >> aFloat;
    cout << 111 << ' ' << aString << ' ' << aChar << ' ' << aUChar << ' ' << anInt << ' ' << aUInt << ' ' << aLong << ' ' << aULong << ' ' << aFloat << ' ' << endl;
    cout << 222 << ' ' << aString << ' ' << aChar << ' ' << aUChar << ' ' << anInt << ' ' << aUInt << ' ' << aLong << ' ' << aULong << ' ' << aFloat << ' ' << endl;
    return 0;
}
