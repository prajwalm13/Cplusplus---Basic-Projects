#include<iostream>
using namespace std;


int main(){
string question[] = {{"1.Which is the year c++ introduced?: "},
                    {"2.What is the name of c++ creater?:"},
                    {"3.Which is C++ predecossor?:"},
                    {"4.Is the earth flat?:"},};

string options[][4]={
    {"A.1985","B.1873","C.1986","D.1987"},
    {"A.ryan gosling","B.bjarne strostrup","C.christopher","D.stan lee"},
    {"A.C--","B.C+","C.C","D.java"},
    {"A.Sometimes","B.yes","C.Maybe","D.No"},


};
char AnswerKey[]={'A','B','C','D'};

int size = sizeof(question)/sizeof(question[0]);
char guess;
int score;

for(int i=0;i<size;i++){
    cout<<"**********************"<<'\n';
    cout<<question[i]<<'\n';
    cout<<"**********************"<<'\n';

    for(int j=0;j<sizeof(options[i])/sizeof(options[i][0]);j++){
        cout<<options[i][j]<<'\n';

    }
    cin>>guess;
    guess = toupper(guess);

    if(guess == AnswerKey[i]){
        cout<<"Correct\n";
        score++;
    }else{
        cout<<"Wrong\n";
        cout<<"Corret Answer is "<<AnswerKey[i]<<'\n';
    }


}
cout<<"+++++++++++++++++++++++++++++++"<<'\n';
cout<<"             Result            "<<'\n';
cout<<"+++++++++++++++++++++++++++++++"<<'\n';


cout<<"Your Correct Guesses:"<<score<<endl;
cout<<"Total questions :"<<size<<endl;

cout<<"Score :"<<(score/double(size))*100 <<"%"<<endl;



return 0;
}
