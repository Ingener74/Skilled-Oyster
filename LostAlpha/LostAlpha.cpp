#include <iostream>
#include "LostAlpha.h"

using namespace std;

LostAlpha::LostAlpha() {
    cout << __PRETTY_FUNCTION__ << endl;
}

LostAlpha::~LostAlpha() {
    cout << __PRETTY_FUNCTION__ << endl;
}

LostAlpha* core = nullptr;

int startPlugin() {
    if (core) {
        delete core;
        core = nullptr;
    }
    core = new LostAlpha;
    return 0;
}

int stopPlugin() {
    if (core) {
        delete core;
        core = nullptr;
    }
    return 0;
}
