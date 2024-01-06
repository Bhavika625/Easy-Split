# include <iostream>
# include <vector>
using namespace std;

vector <string> Names;

using namespace std;

class QuickSort
{
    public:
    void doQuickSort(vector<int> &ary,int lb,int ub)
    {
        if(lb>=ub)
            return;
            
            int mid=getPvtPos(ary,lb,ub);
            doQuickSort(ary,lb,mid-1);
            doQuickSort(ary,mid+1,ub);
           
    }
    int getPvtPos(vector<int> &ary,int lb,int ub)
    {
        int i=lb,j=ub;
        int pvt=ary[lb];
        
        while(i<j)
        {
            while(ary[i]<=pvt)
                {
                    i++;
                }
            while(ary[j]>pvt)
                {
                    j--;
                }
                if(i<j)
                {
                    swap(ary[i],ary[j]);
                }
        }
        swap(ary[j],ary[lb]);
        return j;
   }
    
};

class Split
{
    int row;
    vector<int> money;
    QuickSort quick;
    public:
        Split(int n)
        {
            row = n; 
        }

        void Input(vector <vector <int> > &Matrix)
        {
            int i = 0, amount;;
            string name;
            char ch;

            do
            {
                cout<<"Does "<<Names[i]<<" has to pay someone? "<<endl;
                cout<<"(Enter y/Y for Yes AND n/N for No)"<<endl;
                cin>>ch;

                if(ch == 'y' || ch == 'Y')
                {
                    cout<<"To whom does "<<Names[i]<<" have to pay? ";
                    cin>>name;

                    int j = Search(name);
                    
                    if(j != -1)
                    {
                        cout<<"How much does "<<Names[i]<<" have to pay? ";
                        cin>>amount;
                        Matrix[i][j] += amount;
                    }
                }
                else    
                    i++;
            }
            while(i < row);
        }

        int Search(string name)
        {
            for(int i=0; i<Names.size(); i++)
            {
                if(Names[i] == name)
                    return i;
            }
            cout<<"There is no such name."<<endl;
            return -1;
        }
        
        void Credit_Debit(vector <vector <int> > &Matrix)
        {
            for(int i=0; i<Matrix[0].size(); i++)
            {
                int credit =0, debit = 0;
                for(int j=0; j<Matrix[i].size(); j++)
                {
                    credit += Matrix[j][i];
                    debit += Matrix[i][j];
                }
                money.push_back(credit-debit);
            }
            quick.doQuickSort(money, 0, money.size()-1);
        }
        
        void Payment() 
        { 
            int i=0, j = money.size()-1;

            while(i < j)
            {
                cout<<"\t\t";
                if(abs(money[i]) >= abs(money[j]))
                {
                    cout<<Names[i]<<" will give "<<abs(money[j])<<" Rs. to "<<Names[j]<<". "<<endl;
                    money[i] += money[j];
                    money[j] = 0;
                    j--;
                }

                else if(abs(money[j]) > abs(money[i]))
                {
                    cout<<Names[i]<<" will give "<<abs(money[i])<<" Rs. to "<<Names[j]<<". "<<endl;
                    money[j] += money[i];
                    money[i] = 0;
                    i++;
                }
            }
        }
};

int main()
{
    int n;
    string name;

    cout<<"How many people are there to split money: "<<endl;
    cin>>n;

    vector <vector <int> >array(n, vector<int>(n,0));

    for(int i=0; i<n; i++)
    {
        cout<<"Enter name of the "<<(i+1)<<" person: ";
        cin>>name;
        Names.push_back(name);
    }

    Split split_obj(n);
    split_obj.Input(array);
    split_obj.Credit_Debit(array);
    cout<<"\n\n";
    split_obj.Payment();

    cout <<"\n\nEXECUTION IS OVER." << endl;
    cin.ignore();

    system("pause");

}