#include <iostream>

#include <Poco/SharedLibrary.h>

using namespace std;

int main() {
    try {
        Poco::SharedLibrary lib("./LostAlpha/libLostAlpha.so");

        auto startPlugin = reinterpret_cast<int(*)()>(lib.getSymbol("startPlugin"));
        auto stopPlugin = reinterpret_cast<int(*)()>(lib.getSymbol("stopPlugin"));

        startPlugin();
        stopPlugin();

        return 0;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}
