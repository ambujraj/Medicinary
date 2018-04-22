#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class medicine{
    private:
    char name[20]="NA";
    float price=0;
    int stocks=0;
    char man[20]="NA";
    char exp[20]="NA";

    public:
    void add()
    {
        cout<<"Enter name of medicine: ";
        cin>>name;

        while(1){
                cout<<endl<<"Enter price: ";
        cin>>price;
                if(price<0 || price>100000){
            cout<<"Invalid Price"<<endl;
            continue;}
        else {break;}
        }
        while(1){
                cout<<endl<<"Enter number of stocks: ";
        cin>>stocks;
                if(stocks==0){
            cout<<"stocks cannot be zero"<<endl;
            continue;}
        else if(stocks<0){
            cout<<"Stocks cannot be less than zero"<<endl;
            continue;
        }
        else {break;}
        }
        cout<<endl<<"Enter Date of Manufacture(dd-mm-yy): ";
        cin>>man;
        cout<<endl<<"Enter Date of Expiry(dd-mm-yy): ";
        cin>>exp;
    }
    string searchname()
    {
        return name;
    }
    int searchprice()
    {
        return price;
    }
    int searchstocks()
    {
        return stocks;
    }
    string searchexp(){
        return exp;
    }
    string searchman(){
        return man;
    }
    void show()
    {
        cout<<"Medicine Name: "<<name<<"\tPrice: "<<price<<"\tStocks Left: "<<stocks<<endl<<"Date of manufacture: "<<man<<"\tDate of Expiry: "<<exp<<endl;
     }
};
int x=0;
void auth()
{

   string pass ="";
   char ch;
   int count = 1;


   while(1){
    cout <<"Enter password: ";
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "qwerty"){
      cout <<endl<<endl<< "Access Granted!";
      x=123;
      break;
   }else if(pass !="qwerty"){
      cout <<endl<< "Wrong Password!! "<<endl<<"\t"<<"Attempts left: "<<5-count<<endl;
      ++count;


      if(count>5){
          cout<<"Access Denied";
          exit(0);
      }
   }}

}

int main()
{

    medicine m[12];
    int in;
    cout << endl<< endl<< endl<< "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\t\t\t\t\t"<< "WELCOME TO MEDICINE MANAGEMENT SYSTEM - ADMIN PANEL" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl<<endl;
    cout<<"Lets Authenticate First!!"<<endl<<endl;
    auth();

    if (x == 123)
    {
        while(1){
        cout <<endl<<endl<< "Enter [1] to Search for Medicine Name" << endl;
        cout << "Enter [2] to Add Medicine names" << endl;
        cout<<"Enter [3] to show all Medicine Names"<<endl;
        cout << "Enter any other number to Exit" << endl<< endl;
        cout << "Enter Your choice: ";
        cin >> in;
        if (in == 1)
        {
            ifstream fi;
            fi.open("medicinedata.txt", ios::in);
            if (!fi)
            {
                cout <<endl<< "File cannot be opened";
                exit(0);
            }
            
            for(int i=0;i<12;i++){
                fi.read((char*)&m[i], sizeof(m[i]));
            }
            char n[10];
            cout<<"Enter the name to search: ";
            cin >> n;
            int temp = 0;
            for (int i = 0; i < 12; i++)
            {

                string s = m[i].searchname();
                const char *cstr = s.c_str();

                if (stricmp(n, cstr) == 0)
                {
                    cout << "-------------------------------------------------------------------------------------" << endl;

                    cout << "Name of Medicine: " << m[i].searchname() << '\t' << "Price: " << m[i].searchprice() << '\t' << "Stocks left: " << m[i].searchstocks() << endl
                         << "Date of Manufacture: " << m[i].searchman() << '\t' << "Date of Expiry: " << m[i].searchexp() << endl;
                    temp = 321;
                    cout << "-------------------------------------------------------------------------------------" << endl;
                }
            }
            if (temp != 321)
            {
                cout << "Sorry, Medicine Name not found" << endl;
                continue;
            }
            fi.close();
        }
        else if (in == 2)
        {
            ofstream fout;
            /*int ad;
            cout << "Enter the number of Medicine You want to Add: ";
            cin >> ad;*/
            fout.open("medicinedata.txt", ios::out);
            if (!fout)
            {
                cout << endl
                     << "File cannot be opened";
                exit(0);
            }
            cout << endl<< endl<< "Lets add the new Medicines"<<endl;
            for (int i = 0; i < 12; i++)
            {
                m[i].add();

            }
            for(int i=0;i<12;i++)
            {
                fout.write((char*)&m[i], sizeof(m[i]));
            }
            fout.close();

        }
        else if(in==3)
        {
            ifstream fin;
            fin.open("medicinedata.txt", ios::in);
            if (!fin)
            {
                cout << endl<< "File cannot be opened";
                exit(0);
            }
            for(int i=0;i<12;i++){
                fin.read((char*)&m[i], sizeof(m[i]));
            }
            for(int i=0;i<12;i++)
            {
                
                cout << "-------------------------------------------------------------------------------------" << endl;
                m[i].show();
                cout << "-------------------------------------------------------------------------------------" << endl;
            }
        }
        else
        {
            cout << "Have a nice Day !!";
            exit(0);
        }
    }
}
}