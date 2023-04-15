#include <iostream>
#include <cstdlib>
using namespace std;
bool isaSet(int index[]);
class Set{
    string color;
    string symbol;
    string shadings;
    int number;
 public:
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
    // if no set exicts, create 12 more cards
   
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
    card[0].set_color()="red";
    card[0].set_symbol()="squiggles";
    card[0].set_shadings()="solid";
    card[0].set_number()=1;

    card[1].set_color()="red";
    card[1].set_symbol()="ovals";
    card[1].set_shadings()="striped";
    card[1].set_number()=2;

    card[2].set_color()="red";
    card[2].set_symbol()="diamonds";
    card[2].set_shadings()="outlined";
    card[2].set_number()=3;

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
    for(int i=0;i<3;i++){
        if(color[i] == 3 || (color[0] == 1 && color[1] == 1 && color[2] == 1)){ // either all same color or diff
            if(symbol[i] == 3 || (symbol[0] == 1 && symbol[1] == 1 && symbol[2] == 1)){ // either all same symbol or diff
                if(shadings[i] == 3 || (shadings[0] == 1 && shadings[1] == 1 && shadings[2] == 1)){ // either all same shadings or diff
                    if(number[i] == 3 || (number[0] == 1 && number[1] == 1 && number[2] == 1)){ // either all same number or diff
                        return true;
                        cout<<"set lalalala";
                    }
                }
            }

        }  
        else cout<<"not a set awww";
    }
    return false;

}
void startGame(){
    // user will be asked to enter the index of any 3 cards
    // if the cards are a set, they will be removed from the deck
    // if the cards are not a set, the user will be asked to enter the index of another 3 cards
    // the game ends when there are no more sets
    cout<<"enter the index of any 3 cards: "<<endl;
    int index[3];
    for(int i=0;i<3;i++){
        cin>>index[i];
    }
    if(isaSet(index)){
        cout<<"This is a set!"<<endl;
        card[index[0]].makeEmpty();
        card[index[1]].makeEmpty();
        card[index[2]].makeEmpty();
    }
    else cout<<"This is not a set!"<<endl;
    
}
int main(){
    //srand(int(time(NULL)));
    initiateCards();
    startGame();
    return 0;
}
