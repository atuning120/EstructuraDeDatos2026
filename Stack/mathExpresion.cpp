#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string expresion){

    stack<char> bracket;
    for (char c: expresion){
        if(c=='('){
            bracket.push(c);
        }else if (c==')'){
            if (bracket.empty()){
                return false;
            }
            bracket.pop();
        }
    }

    if(bracket.empty()){
        return true;
    }
    return false;
}

int main() {

    string expresion= "(a + b) * (c + d)";
    //string expresion= "((a + b) * (c + d)";
    //string expresion= "(a + b))";

    if (isValid(expresion)){
        cout << "Es valido"<< endl;
    } else {
        cout << "No es valido"<< endl;
    }



}