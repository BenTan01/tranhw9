/*
control_GPIO.cpp take 3 arguments
first argument is the name of the gpio
second argument is the value that you want to set to the first gpio name argument
thrid argument is the name of the gpio that you want to know it state
e.g. ./control_GPIO 60 hi 46
*/

#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

#define GPIO_PATH "/sys/class/gpio/"

void writeFile(string filename, string value){
    fstream writeFile;
    string path(GPIO_PATH);
    writeFile.open((GPIO_PATH + filename).c_str(), fstream::out);
    if (value == "hi"){
        writeFile << "1";
    }
    else if (value == "low"){
        writeFile << "0";
    }
    writeFile.close();
}

void read(string filename){
   fstream readFile;
   string path(GPIO_PATH);
   readFile.open((GPIO_PATH + filename).c_str(), fstream::in);
   string line;
   while (getline(readFile, line)){
       cout << "The value of the input is: " << line << endl;
   }
   readFile.close();
}


int main(int argc, char*argv[]){

    if (argc != 4){
        cout << "Usage is: control_GPIO gpio_number state gpio_number" << endl;
        cout << "gpio number: GPIO number to control" << endl;
        cout << "state: hi or low" << endl;
        return 4;

    }

    ostringstream cmd1;
    cmd1 << "gpio" << argv[1] << "/value";
    string gpioInput = string(cmd1.str());

    string setValue(argv[2]);
    writeFile(gpioInput, setValue);

    ostringstream cmd3;
    cmd3 << "gpio" << argv[3] << "/value";
    string gpioOutput = string(cmd3.str());
    read(gpioOutput);


}



