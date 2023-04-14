#include <iostream>
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
// finds index of matching closing parenthesis
int findmatchingparenthesis(string expression, int start){
    int count = 0;
    for (int i = start; i < expression.length(); i++) {
        if (expression[i] == '(')
            count++;
        else if (expression[i] == ')')
            count--;
        if (count == 0)
            return i;
    }
    return -1;// not found
}
// simplifies subexpressions with negations
string simplify(string subexpression){
    string newsubexp;
    for(int i=0; i<subexpression.size(); i++){
        if(subexpression[i] == '~' && subexpression[i+1] == '('){
            int start = i+1;
            int end = findmatchingparenthesis(subexpression, i+1);
            cout<<"start: "<<start<<endl;
            cout<<"end: "<<end<<endl;
            for(int j=start; j<end; j++){
                // apply De Morgan's laws
                // change operator between subexpressions
            }
        }
    }
    return "";
}
int main(){
    // ~(AvB) == (~A^~B)
    // ~(A ^ (B v C))
    // returns (~A v (~B ^ ~C))
    string expression="";
    cout<<"enter expression: ";
    // getline(cin,expression);
    expression = "~(A ^ B)";
    expression = removespaces(expression);
    cout<<expression<<endl;
    cout<<simplify(expression);
    return 0;
}
