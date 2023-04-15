// Maham Imran 22i-2733
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
            subexpression[start-1] = ' ';
            subexpression[end] = subexpression[end-1];
            subexpression[end-1] = '~';
            subexpression[start] = '~';
            if(subexpression[start+2] == 'v')
                subexpression[start+2] = '^';
            else if(subexpression[start+2] == '^')
                subexpression[start+2] = 'v';
            cout<<subexpression<<endl;
        }
    }
    return "";
}
int main(){
    cout<<endl;
    string expression = "~(A v B)";
    expression = removespaces(expression);
    cout<<"expression 1 before: "<<expression<<endl;
    cout<<"expression 1 after: "<<simplify(expression);
    cout<<endl;

    expression = "~(A ^ B)";
    expression = removespaces(expression);
    cout<<"expression 2 before: "<<expression<<endl;
    cout<<"expression 2 after: "<<simplify(expression);
    cout<<endl;

    expression = "~(A v B) ^ C";
    expression = removespaces(expression);
    cout<<"expression 3 before: "<<expression<<endl;
    cout<<"expression 3 after: "<<simplify(expression);
    cout<<endl;

    expression = "~(A ^ B) v C";
    expression = removespaces(expression);
    cout<<"expression 4 before: "<<expression<<endl;
    cout<<"expression 4 after: "<<simplify(expression);
    cout<<endl;

    expression = "~(C v D)";
    expression = removespaces(expression);
    cout<<"expression 5 before: "<<expression<<endl;
    cout<<"expression 5 after: "<<simplify(expression);
    cout<<endl;

    expression = "~(C ^ D)";
    expression = removespaces(expression);
    cout<<"expression 6 before: "<<expression<<endl;
    cout<<"expression 6 after: "<<simplify(expression);
    cout<<endl;

    return 0;
}
