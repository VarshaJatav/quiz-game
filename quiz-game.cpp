#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctime>
using namespace std;

class quiz{
    char ques[400];
    char options[4][100];
    char c;
    int count;
public:
    void read_data()
    {
        cout<<"\nEnter the question no: ";
        cin>>count;
        cout<<"\nEnter the question : ";
        fflush(stdin);
        cin.getline(ques,400);
        fflush(stdin);
        cout<<"\nEnter the options: ";
        for (int i = 0; i < 4; i++)
        {
            cin.getline(options[i],100);
            fflush(stdin);
        }
        cout<<"\nEnter the answer: ";
        cin>>c;
    }
    void display()
    {
        cout<<endl<<endl<<count<<".  "<<ques<<endl;
        for (int i = 0; i < 4; i++)
        {
            cout<<(char)(i+65)<<")  "<<options[i]<<"\n";
        }
        cout<<"\nAns : "<<c;
    }
    void ask_ques(int num)
    {
        cout<<endl<<endl<<num<<".  "<<ques<<endl;
        for (int i = 0; i < 4; i++)
        {
            cout<<(char)(i+65)<<")  "<<options[i]<<"\n";
        }
        cout<<endl;
    }
    char get_ans()
    {
        return c;
    }
    int get_count()
    {
        return count;
    }
};
void write_to_file(void)
{
    quiz s;
    ofstream fout;
    fout.open("quiz.dat", ios::app);
    s.read_data();
    fout.write((char *)&s, sizeof(quiz));
    fout.close();
    return;
}

void read_from_file()
{
    quiz s;
    ifstream fin;
    fin.open("quiz.dat");
    while (fin.read((char *)&s, sizeof(quiz)))
        s.display();
    fin.close();
    return;
}
int how_many_ques()
{
    int num=0;
    quiz s;
    ifstream fin;
    fin.open("quiz.dat");
    while (fin.read((char *)&s, sizeof(quiz)))
    {
        num++;
    }
    fin.close();
    return num;
}
int generate_rand()
{
    srand(time(0));
    int n=how_many_ques();
    return (rand()%n + 1);
}

int play_quiz(int random_num,int ques_no)
{
    
    quiz s;
    char ch;
    ifstream fin;
    fin.open("quiz.dat");
    while (fin.read((char *)&s, sizeof(quiz)))
    {
        if(s.get_count()==random_num)
        {
            s.ask_ques(ques_no);
            cin>>ch;
            if(ch==s.get_ans())
            {
                cout<<"\n\nYour answer is correct.  :)  \n\n";
                return 1;
            }
            else{
                cout<<"\n\nWrong answer.\n\n\t\tYOU LOOSE\n";
                cout<<"\n\nThe Correct answer is :   "<<s.get_ans()<<"\n\n";
                cout<<"\n\n\t\t:) BETTER LUCK NEXT TIME\n\n";
                
                
            }
        }
    }
    return 0;
}

int main()
{
    system("cls");
    int temp,j,a[10],x,res=0;
    cout<<"\n\n\t\t============ QUIZ ==========\n\n\n";
    cout<<"\n\n\nHow many questions you want out of "<<how_many_ques()<<" :  ";
    cin>>x;
    cout<<"\n\n\n\n";
    getch();
    for(int i=0;i<x;i++)
    {
        system("cls");
        
        temp=generate_rand();
        for(j=0;j<=i-1;j++)
        {
            if(temp==a[j])
            {
                break;
            }
        }
        if(i==j)
        {
            a[i]=temp;
            res+=play_quiz(temp,i+1);
            getch();
            
        }
        else{
            i--;
        }
        // cout<<"\n\nPress any key to continue......\n\n";

    }
    cout<<"\n\n\n================    Your Score :  "<<res<<" / "<<x<<"    ====================\n\n\n\n";
    getch();
    return 0;
}

//main function to add more questions: 
/*
int main()
{
    system("cls");
    int choice;
    do{
        cout<<"\n\n\nEnter 1 to add a question: \n";
        cout<<"\nEnter 2 to read all question : \n";
        cout<<"\nenter 3 to exit : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            write_to_file();
            break;
        
        case 2:
            read_from_file();
            break;

        case 3:
             exit(0);
             break;

        default:
            break;
        }
    }while (choice!=3);
    return 0;
}

*/

/*
int main()
{
    system("cls");
    char x;
    string name;
    cout<<"\n\n......Welcome to QUIZ.......\n";
    cout<<"\n\nEnter your name:   ";
    cin>>name;
    system("cls");
    cout<<"\n\n\n\n\n\t\tLETS START\n\n\n\n";
    system("cls");
    cout<<"Enter the Correct option ( A / B / C / D):  \n";
    cout<<"\n\nWhat is the name of the gold winner of India in Olympics?\nA) P.V Sindhu\t\tB)  Neeraj Chopra\nC) Mirabai Chanu\t\tD)  Bajrang Punia\n";
    cin>>x;
    if(x=='B')
    {
        cout<<"\n=========Your answer is correct============\n ";
    }
    else{
        cout<<"===========you lose==========";
        exit(0);
    }
    cout<<"\n\n************  YOU WON 500 Rs  ************\n";
    cout<<"\nPress any key to continue: \n";
   x=getch();
    system("cls");
   
    cout<<"\n\nWhat is the name of the owner of AMAZON  ?\nA) Bill Gates\t\tB)  Elon Musk\nC)  Jeff Bejos\t\tD)  Mukesh Ambani\n";
    cin>>x;
    if(x=='C')
    {
        cout<<"\n=========Your answer is correct============\n ";
    }
    else{
        cout<<"===========you lose==========";
        exit(0);
    }
    cout<<"\n\n************  YOU WON 1000 Rs  ************\n";
    cout<<"\nPress any key to continue: \n";
   x=getch();
system("cls");

    cout<<"\n\nWhat is the Chemical formula of salt ?\nA) H2O\t\tB)  NaSO4\nC) HCl\t\tD)  NaCl\n";
    cin>>x;
    if(x=='D')
    {
        cout<<"\n=========Your answer is correct============\n ";
    }
    else{
        cout<<"===========you lose==========";
        exit(0);
    }
    cout<<"\n\n************  YOU WON 2000 Rs  ************\n";
    cout<<"\nPress any key to continue: \n";
   x=getch();
    system("cls");

    cout<<"\n\nWhich of the following is not a programming language ?\nA) C++\t\tB)  CPU\nC) Ruby\t\tD)  Javascript\n";
    cin>>x;
    if(x=='B')
    {
        cout<<"\n=========Your answer is correct============\n ";
    }
    else{
        cout<<"===========you lose==========";
        exit(0);
    }
    cout<<"\n\n************  YOU WON 3500 Rs  ************\n";
    cout<<"\nPress any key to continue: \n";
   x=getch();
    system("cls");

    cout<<"\n\nhow many times moon's gravity is equal to earth ?\nA) 1/6\t\tB)  6\nC) 1/16\t\tD)  1/4\n";
    cin>>x;
    if(x=='A')
    {
        cout<<"\n=========Your answer is correct============\n ";
    }
    else{
        cout<<"===========you lose==========";
        exit(0);
    }
    cout<<"\n\n************  YOU WON 5000 Rs  ************\n";
    cout<<"\nPress any key to continue: \n";
   x=getch();
    system("cls");

    cout<<"\n\n+++++++++++ Congratulations "<<name<<" Won the Game +++++++++++";
    return 0;
}*/