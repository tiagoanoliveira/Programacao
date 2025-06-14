#include <iostream>
using namespace std;
void split(const string& s, vector<string>& v) {

}


int main () {
    { string s = "";
        vector<string> v;
        split(s, v);
        print(v); }
    { string s = "    ";
        vector<string> v;
        split(s, v);
        print(v); }
    { string s = "  a b  c ";
        vector<string> v;
        split(s, v);
        print(v); }
    { string s = "C++ LEIC FCUP FEUP";
        vector<string> v;
        split(s, v);
        print(v); }
    { string s = "       C++        ";
        vector<string> v;
        split(s, v);
        print(v); }
    return 0;
}