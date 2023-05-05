#include <iostream>
#include <windows.h>
using namespace std;


void Usage() {
    cout << "\n\nUsage:\n  sm [mode] [delay in seconds]\n\n";
    cout << "0 - Hybernation\n";
    cout << "1 - Shut Down\n";
    cout << "2 - Reboot\n";
    cout << "3 - Cancel Shut Down\n\n";
    cout << "For example:\n  sm 0 15  hybernation in 15 seconds\n";
}


void hybernate(int delay) {
    if (delay == 0){
        system("shutdown -h");
    }else if (delay > 100) {
        cout << endl;
        cout << "Hybernation after " << delay << " seconds";

        Sleep(delay * 1000);
        system("shutdown -h");
    }else {
        for(int i = delay; i > 0; i--) {
            Sleep(950);
            cout << "Hybernate in " << i << " seconds..." << endl;
        }
        cout << "Hybernate ...";
        Sleep(200);
        system("shutdown -h");
    }
}




void shutdown(int delay) {
    if (delay == 0) {
        system("shutdown -s -t 00");
        system("exit");
    }else if (delay > 100) {
        cout << endl;
        cout << "Shutting Down after " << delay << " seconds...";

        system(("shutdown -s -t " + to_string(delay)).c_str());
        system("exit");
    }else {
        system(("shutdown -s -t " + to_string(delay)).c_str());
        cout << endl;

        for (int i = delay; i > 0; i--) {
            Sleep(950);
            cout << "Shutting Down in " << i << " seconds" << endl;
        }
        Sleep(200);
        cout << "Shutting Down ...";
        system("exit");
    }
}


void reboot(int delay) {
    if (delay == 0) {
        system("shutdown -r -t 00");
        system("exit");
    }else if (delay > 1000) {
        cout << endl;
        cout << "Rebooting after " << delay << " seconds...";

        system(("shutdown -r -t " + to_string(delay)).c_str());
        system("exit");
    }else {
        system(("shutdown -r -t " + to_string(delay)).c_str());
        cout << endl;

        for (int i = delay; i > 0; i--) {
            Sleep(900); cout << "Rebooting in " << i << " seconds" << endl;
        }

        Sleep(200); cout << "Rebooting ...";
        system("exit");
    }
}


void cancel() {
    system("shutdown -a");
}


void select(int mode, int delay=0) {
    switch (mode) {
        case (0):
            hybernate(delay);
            break;
        case (1):
            shutdown(delay);
            break;
        case (2):
            reboot(delay);
            break;
        case (3):
            cancel();
            break;
        default:
            Usage();
    }
}
