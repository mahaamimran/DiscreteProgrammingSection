// Maham Imran 22i-2733
#include <iostream>
using namespace std;
bool isaSet(int index[]);
class Set{
    string color;
    string symbol;
    string shadings;
    int number;
 public:
    // default+parameterisrd constructor
    Set(string c="", string s="", string sh="", int n=0){
        if (c == "red" || c == "green" || c == "purple")
        color = c;
        if (s == "squiggles" || s == "ovals" || s == "diamonds")
        symbol = s;
        if (sh == "solid" || sh == "striped" || sh == "outlined")
        shadings = sh;
        if (n == 1 || n == 2 || n == 3)
        number = n;
    }
    void set_color(string c){
        if (c == "red" || c == "green" || c == "purple")
        color = c;
    }
    void set_symbol(string s){
        if (s == "squiggles" || s == "ovals" || s == "diamonds")
        symbol = s;
    }
    void set_shadings(string sh){
        if (sh == "solid" || sh == "striped" || sh == "outlined")
        shadings = sh;
    }
    void set_number(int n){
        if (n == 1 || n == 2 || n == 3)
        number = n;
    }
    string get_color(){
        return color;
    }
    string get_symbol(){
        return symbol;
    }
    string get_shadings(){
        return shadings;
    }
    int get_number(){
        return number;
    }
    bool isEmpty(){
        if(color == "" && symbol == "" && shadings == "" && number == 0)
            return true;
        else
            return false;
    }
    void print(){
        if (isEmpty())
            cout << "Empty" << endl;
        else
        cout << color << " " << symbol << " " << shadings << " " << number << endl;
    }
    void makeEmpty(){
        color = "";
        symbol = "";
        shadings = "";
        number = 0;
    }
};
Set card[12];
void initiateCards(){
    // create 12 cards with random attributes
    string color[3] = {"red", "green", "purple"};
    string symbol[3] = {"squiggles", "ovals", "diamonds"};
    string shadings[3] = {"solid", "striped", "outlined"};
    int number[3] = {1, 2, 3};
    for(int i=0;i<12;i++){
        card[i].set_color(color[rand()%3]);
        card[i].set_symbol(symbol[rand()%3]);
        card[i].set_shadings(shadings[rand()%3]);
        card[i].set_number(number[rand()%3]);
    }


    // hardcoding a set of cards incase not randomly generated
    card[0].set_color("red");
    card[0].set_symbol("squiggles");
    card[0].set_shadings("solid");
    card[0].set_number(2);

    card[4].set_color("green");
    card[4].set_symbol("diamonds");
    card[4].set_shadings("striped");
    card[4].set_number(2);

    card[10].set_color("purple");
    card[10].set_symbol("ovals");
    card[10].set_shadings("outlined");
    card[10].set_number(2);

     for(int i=0;i<12;i++){
        cout<<"Card "<<i+1<<": ";            
     card[i].print();
    }
    cout<<endl;
}
bool isaSet(int index[]){
    // check if the cards are a set
    // return true if they are a set
    // return false if they are not a set
    int color[3] = {0, 0, 0};
    int symbol[3] = {0, 0, 0};
    int shadings[3] = {0, 0, 0};
    int number[3] = {0, 0, 0};
    for(int i=0;i<3;i++){
        if(card[index[i]].get_color() == "red")
            color[0]++;
        else if(card[index[i]].get_color() == "green")
            color[1]++;
        else if(card[index[i]].get_color() == "purple")
            color[2]++;
        if(card[index[i]].get_symbol() == "squiggles")
            symbol[0]++;
        else if(card[index[i]].get_symbol() == "ovals")
            symbol[1]++;
        else if(card[index[i]].get_symbol() == "diamonds")
            symbol[2]++;
        if(card[index[i]].get_shadings() == "solid")
            shadings[0]++;
        else if(card[index[i]].get_shadings() == "striped")
            shadings[1]++;
        else if(card[index[i]].get_shadings() == "outlined")
            shadings[2]++;
        if(card[index[i]].get_number() == 1)
            number[0]++;
        else if(card[index[i]].get_number() == 2)
            number[1]++;
        else if(card[index[i]].get_number() == 3)
            number[2]++;
    }

    /*
    // testing
    cout<<endl;
    cout << "color red = " << color[0] << endl;
    cout << "squiggles = " << symbol[0] << endl;
    cout << "solid = " << shadings[0] << endl;
    cout << "number = " << number[0] << endl;
    cout<<endl;
    cout << "color green = " << color[1] << endl;
    cout << "ovals = " << symbol[1] << endl;
    cout << "striped = " << shadings[1] << endl;
    cout << "number = " << number[1] << endl;
    cout<<endl;
    cout << "color purple = " << color[2] << endl;
    cout << "diamonds = " << symbol[2] << endl;
    cout << "outlined = " << shadings[2] << endl;
    cout << "number = " << number[2] << endl;
    cout<<endl;
    */

    bool validColor=false;
    bool validSymbol=false;
    bool validShadings=false;
    bool validNumber=false;

    // cout << "Checkpoint 1 " << endl;
    // either all the same or all different
    if((color[0]==1 && color[1]==1 && color[2]==1) || (color[0]==3 && color[1]==0 && color[2]==0) || (color[0]==0 && color[1]==3 && color[2]==0) || (color[0]==0 && color[1]==0 && color[2]==3))
        validColor=true;
    if((symbol[0]==1 && symbol[1]==1 && symbol[2]==1) || (symbol[0]==3 && symbol[1]==0 && symbol[2]==0) || (symbol[0]==0 && symbol[1]==3 && symbol[2]==0) || (symbol[0]==0 && symbol[1]==0 && symbol[2]==3))
        validSymbol=true;
    if((shadings[0]==1 && shadings[1]==1 && shadings[2]==1) || (shadings[0]==3 && shadings[1]==0 && shadings[2]==0)|| (shadings[0]==0 && shadings[1]==3 && shadings[2]==0) || (shadings[0]==0 && shadings[1]==0 && shadings[2]==3))
        validShadings=true;
    if((number[0]==1 && number[1]==1 && number[2]==1) || (number[0]==3 && number[1]==0 && number[2]==0) || (number[0]==0 && number[1]==3 && number[2]==0) || (number[0]==0 && number[1]==0 && number[2]==3))
        validNumber=true;

    if(validColor==true && validSymbol==true && validShadings==true && validNumber==true)return true;
    return false;

}
void startGame(){
    // user will be asked to enter the index of any 3 cards
    cout<<"enter the index of any 3 cards: "<<endl;
    int index[3];
    for(int i=0;i<3;i++){
        cin>>index[i];
        // to account for the index that starts at 0
        index[i]--; 
    }
    if(isaSet(index)==true){
        cout<<"This is a set!"<<endl;
        card[index[0]].makeEmpty();
        card[index[1]].makeEmpty();
        card[index[2]].makeEmpty();
    }
    else cout<<"This is not a set!"<<endl;
    
}
int main(){
    // 1, 5, 11 is a set
    srand(int(time(NULL)));
    initiateCards();
    startGame();
    return 0;
}
