


#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

using namespace std;

string exec(const char*);

/*int main()
{
    string input;
    bool cont = true;
    while(cont){
        getline(cin,input);
        if(input == "exit")
            cont = false;
        else
            cout << exec(input.c_str()) << endl;
    }
}*/



string exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);

    if (!pipe) 
    throw 
        runtime_error("popen() failed!");

    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }

    return result;
}
