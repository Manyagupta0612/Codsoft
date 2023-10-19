#include<iostream>
using namespace std;

char box[3][3]={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int row;
int col;
bool tie=false;
char token='X';
string n1="";
string n2="";
void first()
{
    cout<<"   |     |   \n";
    cout<<" "<<box[0][0]<< " |  " <<box[0][1] << "  |   " <<box[0][2]<<"\n";
    cout<<"___|_____|___\n";
    cout<<"   |     |   \n";
    cout<<" "<<box[1][0]<< " |  " <<box[1][1] << "  |   " <<box[1][2] <<"\n";
    cout<<"___|_____|___\n";
    cout<<"   |     |   \n";
    cout<<" "<<box[2][0]<< " |  " <<box[2][1] << "  |   " <<box[2][2] <<"\n";
    cout<<"   |     |   \n";
}

void second()
{
    int digit;
    if(token=='X')
    {
        cout<<n1<<" Enter: ";
        cin>>digit;
    }
    if(token=='0')
    {
        cout<<n2<<" Enter: ";
        cin>>digit;
    }

    if(digit==1)
    {
        row=0;
        col=0;
    }
    if(digit==2)
    {
        row=0;
        col=1;
    }
    if(digit==3)
    {
        row=0;
        col=2;
    }
    if(digit==4)
    {
        row=1;
        col=0;
    }
    if(digit==5)
    {
        row=1;
        col=1;
    }
    if(digit==6)
    {
        row=1;
        col=2;
    }
    if(digit==7)
    {
        row=2;
        col=0;
    }
    if(digit==8)
    {
        row=2;
        col=1;
    }
    if(digit==9)
    {
        row=2;
        col=2;
    }
    else if(digit<1 || digit>9)
    {
        cout<<"Invalid!!!"<<endl;
    }

    if(token=='X' && box[row][col] !='0' && box[row][col]!='X')
    {
        box[row][col]='X';
        token='0';
    }
    else if(token=='0' && box[row][col] !='0' && box[row][col]!='X')
    {
        box[row][col]='0';
        token='X';
    }
    else
    {
        cout<<"There is no empty space!"<<endl;
        second();
    }
    first();
}

bool third()
{
    for(int i=0;i<3;i++)
    {
        if((box[i][0]==box[i][1] && box[i][1]==box[i][2]) || (box[0][i]==box[1][i] && box[1][i]==box[2][i]))
        {
            return true;
        }
        if((box[0][0]==box[1][1] && box[1][1]==box[2][2]) || (box[0][2]==box[1][1] && box[1][1]==box[2][0]))
        {
            return true;
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(box[i][j]!='X' && box[i][j]!='0')
            {
                return false;
            }
        }
    }
    tie=true;
    return false;
}

int main()
{
    cout<<"First Player : \n";
    getline(cin,n1);
    cout<<"Second Player : \n";
    getline(cin,n2);
    cout<<n1<<" will play first \n";
    cout<<n2<<" will play second \n";

    while(!third())
    {
        first();
        second();
    }
    if(token=='X' && tie==false)
    {
        cout<<n2<<" Wins!!"<<endl;
    }
    else if(token=='0' && tie==false)
    {
        cout<<n1<<" Wins!!"<<endl;
    }
    else
    {
        cout<<"It's a draw!"<<endl;
    }
}
