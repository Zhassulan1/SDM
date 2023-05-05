#include <iostream>
#include <cstring>
#include "qsd_modes.hpp"
using namespace std;


int to_int(string arg) {
    int res;
    try {
        res = stoi(arg);
    }catch (invalid_argument) {
        Usage();
        exit(0);
    }
    return res;
}


int main(int argc, char *argv[]) {
    int mode, delay;
    if(argc == 1) {
        cout << "Select shut down mode:" << endl << endl;
        cout << "0) Hybernation     ";
        cout << "1) Shut Down       ";
        cout << "2) Reboot          ";
        cout << "3) Cancel Shut Down" << endl;
        cout << endl << "Select:";
        cin >> mode;

        if (cin.fail() || cin.get() != '\n') {
            Usage();
            return 0;
        }

        cout << "Enter delay (sec):";
        cin  >> delay;
        if (cin.fail() || cin.get() != '\n') {
            Usage();
            return 0;
        }
        select(mode, delay);

    }else if (argc == 2) {
        mode = to_int(argv[1]);
        select(mode);
    }else if (argc == 3) {
        mode  = to_int(argv[1]);
        delay = to_int(argv[2]);
        select(mode, delay);
    }else {
        Usage();
    }
    return 0;
}
