#include<sstream>
stringstream s("aa bb cc");
vector<string>splitted;
string str;
while(s>>str){
splitted.push_back(str);
}
