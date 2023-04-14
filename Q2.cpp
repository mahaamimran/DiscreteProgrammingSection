#include <iostream>
#include <string>
using namespace std;
bool evaluateExpression(string expression){
    bool result = false;
    int i = 0;
    while (i < expression.length()){
        if (expression[i] == 'T'){
            result = true;
            i++;
        }
        else if (expression[i] == 'F'){
            result = false;
            i++;
        }
        else if (expression[i] == '|'){
            i++;
            if (expression[i] == 'T'){
                result = result || true;
                i++;
            }
            else if (expression[i] == 'F'){
                result = result || false;
                i++;
            }
        }
        else if (expression[i] == '^'){
            i++;
            if (expression[i] == 'T'){
                result = result ^ true;
                i++;
            }
            else if (expression[i] == 'F'){
                result = result ^ false;
                i++;
            }
        }
        else if (expression[i] == '&'){
            i++;
            if (expression[i] == 'T'){
                result = result && true;
                i++;
            }
            else if (expression[i] == 'F'){
                result = result && false;
                i++;
            }
        }
    }
    return result;
}
int main(){
    string expression = "F&T|F";
    bool result = evaluateExpression(expression);
    cout<<expression<<" = "<<(result ? "T":"F")<<endl;
    return 0;
}
