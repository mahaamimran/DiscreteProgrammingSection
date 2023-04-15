// Maham Imran 22i-2733
#include <iostream>
#include <string>
using namespace std;
// removes any spaces in expression
string removespaces(string expression){
    string newexp;
    for(int i=0; i<expression.length(); i++){
        if(expression[i] != ' '){
            newexp += expression[i];
        }
    }
    return newexp;
}
// evaluating expression
bool evaluateExpression(string expression){
    bool boolexp = 0;
    int i = 0;
    while (i < expression.length()){
        if (expression[i] == 'F'){
            boolexp = 0;
            i++;
        }
        else if (expression[i] == 'T'){
            boolexp = 1;
            i++;
        }
        else if (expression[i] == '^'){
            i++;
            if (expression[i] == 'T'){
                boolexp = boolexp ^ 1;
                i++;
            }
            else if (expression[i] == 'F'){
                boolexp = boolexp ^ 0;
                i++;
            }
        }
        else if (expression[i] == '&'){
            i++;
            if (expression[i] == 'T'){
                boolexp = boolexp && 1;
                i++;
            }
            else if (expression[i] == 'F'){
                boolexp = boolexp && 0;
                i++;
            }
        }
        else if (expression[i] == '|'){
            i++;
            if (expression[i] == 'T'){
                boolexp = boolexp || 1;
                i++;
            }
            else if (expression[i] == 'F'){
                boolexp = boolexp || 0;
                i++;
            }
        }
    }
    return boolexp;
}
int main(){
    // works w/ any expression
    string expression = "F & T | T & F"; 
    // removing any spaces in expression
    expression = removespaces(expression);
    // evaluating expression
    bool boolexp = evaluateExpression(expression);
    // printing expression and result w/ turnary operator
    cout<<expression<<"="<<(boolexp?"T":"F")<<endl;
    return 0;
}
