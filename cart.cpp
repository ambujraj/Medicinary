#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
class medicine
{
  public:
  char name[20] ="NA";
  float price = 0;
  int stocks = 0;
  char man[20] = "NA";
  char exp[20] = "NA";
  static int id;

  void show(int x){


          if(x>=0 && x<=2){
                if(x==1){
                    cout<<"For Fever(Recommended):"<<endl;
                }
                else{
              cout<<"For Fever:"<<endl;
          }}
          else if(x>2 && x<=5){
                if(x==4){
                    cout<<"For Typhoid(Recommended):"<<endl;
                }
                else{
              cout<<"For Typhoid:"<<endl;
          }}
          else if(x>5 && x<=8){
                if(x==6){
                    cout<<"For Jaundice(Recommended):"<<endl;
                }
                else{
              cout<<"For Jaundice:"<<endl;
          }}
          else if(x>9 && x<=11){
                if(x==10){
              cout<<"For Cough(Recommended):"<<endl;}
          else{
            cout<<"For Cough:"<<endl;
          }
          }
          cout << "Medicine Name: " << name << "\tPrice: " << price << "\tStocks Left: " << stocks << endl<< "Date of Manufacture: " << man << "\tDate of Expiry: " << exp << '\t\t';

  }



};
int medicine::id=1;
class cart{
   public:
     char n[20]="NA";
     float p=0;
     int s=0;
     char m[20]="NA";
     char e[20]="NA";



      /* string searchn()
       {
           return n;
       }
       int searchp()
       {
           return p;
       }
       int searchs()
       {
           return s;
       }
       string searche()
       {
           return e;
       }
       string searchm()
       {
           return m;
       }*/
};
int main()
{
    medicine m[12];
    cart car;
    int in;
    int idd;

    cout << endl<< endl<< endl<< "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\t\t\t\t\t"<< "WELCOME TO MEDICINE MANAGEMENT SYSTEM" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" ;

while(1){
    cout << endl<< endl<< "Enter [1] to Search for Medicine" << endl;

    cout << "Enter [2] to show all Medicine Names" << endl;
    cout << "Enter [3] to view cart" << endl;

    cout << "Enter any other number to Exit" << endl<< endl;
    cout << "Enter Your choice: ";
    cin >> in;

    if(in == 1){
        ifstream fin;
        fin.open("medicinedata.txt", ios::in);
        if (!fin)
        {
            cout << endl
                 << "File cannot be opened";
            exit(0);
        }

        for(int i=0;i<12;i++){
            fin.read((char*)&m[i], sizeof(m[i]));
        }
        char n[10];
        cout << "Enter the Disease: ";
        cin >> n;
        int temp = 0;
        int mnp=1;
        int mnp1 = 4;
        int mnp2 = 7;
         int mnp3 = 10;
        for (int i = 0; i < 3; i++)
        {

            string s1 = n;
            string s2 = "fever";
            string s3 = "Fever";
            string s4 = "FEVER";

            if (s1.compare(s2) == 0 || s1.compare(s3)==0 || s1.compare(s4)==0)
            {
                cout << "-------------------------------------------------------------------------------------" << endl;
                cout << "Name of Medicine: " << m[i].name << '\t' << "Price: " << m[i].price << '\t' << endl<< "Date of Manufacture: " << m[i].man << '\t' << "Date of Expiry: " << m[i].exp <<"\tId = "<<mnp<<endl;
                mnp++;
                temp = 321;
                cout << "-------------------------------------------------------------------------------------" << endl;
            }
            s2 = "typhoid";
            s3 = "Typhoid";
            s4 = "TYPHOID";
            if (s1.compare(s2) == 0 || s1.compare(s3) == 0 || s1.compare(s4) == 0)
            {
                cout << "-------------------------------------------------------------------------------------" << endl;
                cout << "Name of Medicine: " << m[i].name << '\t' << "Price: " << m[i].price << '\t' << endl<< "Date of Manufacture: " << m[i].man << '\t' << "Date of Expiry: " << m[i].exp << m[i].exp <<"\tId = "<<mnp1<< endl;
                mnp1++;
                temp = 321;
                cout << "-------------------------------------------------------------------------------------" << endl;
            }

            s2 = "jaundice";
            s3 = "Jaundice";
            s4 = "JAUNDICE";
            if (s1.compare(s2) == 0 || s1.compare(s3) == 0 || s1.compare(s4) == 0)
            {
                cout << "-------------------------------------------------------------------------------------" << endl;
                cout << "Name of Medicine: " << m[i].name << '\t' << "Price: " << m[i].price << '\t' << endl
                     << "Date of Manufacture: " << m[i].man << '\t' << "Date of Expiry: " << m[i].exp << m[i].exp <<"\tId = "<<mnp2<< endl;
                mnp2++;
                temp = 321;
                cout << "-------------------------------------------------------------------------------------" << endl;
            }

            s2 = "cough";
            s3 = "Cough";
            s4 = "COUGH";

            if (s1.compare(s2) == 0 || s1.compare(s3) == 0 || s1.compare(s4) == 0)
            {
                cout << "-------------------------------------------------------------------------------------" << endl;
                cout << "Name of Medicine: " << m[i].name << '\t' << "Price: " << m[i].price << '\t' << endl
                     << "Date of Manufacture: " << m[i].man << '\t' << "Date of Expiry: " << m[i].exp << m[i].exp <<"\tId = "<<mnp3<< endl;
                temp = 321;
                mnp3++;

                cout << "-------------------------------------------------------------------------------------" << endl;
            }

        }

        if (temp != 321)
        {
            cout << "Sorry, No medicine found" << endl;
            exit(0);
        }
        else {
            ofstream fout;
            fout.open("cart.txt", ios::out);
            if (!fout)
            {
                cout << endl<< "File cannot be opened";
                exit(0);
            }
            while(1){
            cout<<"Enter the id of the Medicine you want to buy: ";
            cin>>idd;
            if(idd>0 && idd<=12){break;}
            else{
                cout<<"Invalid Id"<<endl;continue;
            }
            }
            int amo;
            while(1){
                    cout<<"Enter the quantity: ";
                cin>>amo;
            if(amo<0){cout<<"Quantity cannot be negative"<<endl;continue;}
            else{
                break;
            }
            }
            //c.n = m[idd-1].name;
            strcpy(car.n, m[idd-1].name);
            car.p = m[idd-1].price;
            car.s = amo;
            m[idd-1].stocks -= amo;
            strcpy(car.m, m[idd-1].man);
            strcpy(car.e, m[idd-1].exp);
            cout<<"                      Added to cart"<<endl;
            fout.write((char*)&car, sizeof(car));
            fout.close();
        }
        fin.close();
    }
    else if(in==2){
        ifstream fii;
        fii.open("medicinedata.txt", ios::in);
        if (!fii)
        {
            cout << endl
                 << "File cannot be opened";
            exit(0);
        }
        for (int i = 0; i < 12; i++)
        {
            fii.read((char *)&m[i], sizeof(m[i]));
        }
        for(int i=0;i<12;i++){
                cout << "-------------------------------------------------------------------------------------" << endl;
            m[i].show(i);
            cout<<"\t\tId = "<<m[i].id<<endl;
            m[i].id++;
        cout << "-------------------------------------------------------------------------------------" << endl<<endl;
        }

        ofstream foutt;
        foutt.open("cart.txt", ios::out);
        if (!foutt)
        {
            cout << endl
                 << "File cannot be opened";
            exit(0);
        }
        while (1)
        {
            cout << "Enter the id of the Medicine you want to buy: ";
            cin>>idd;
            if(idd>0 && idd<=12){break;}
            else{
                cout<<"Invalid Id"<<endl;continue;
            }
            }
            int amo;

            while(1){
                    cout<<"Enter the quantity: ";
                cin>>amo;
            if(amo<0){cout<<"Quantity cannot be negative"<<endl;continue;}
            else{
                break;
            }
            }


            //c.n = m[idd-1].name;
            strcpy(car.n, m[idd-1].name);
            car.p = m[idd-1].price;
            car.s = amo;
            m[idd-1].stocks -= amo;
            strcpy(car.m, m[idd-1].man);
            strcpy(car.e, m[idd-1].exp);
            cout<<"                   Added to cart"<<endl;
            foutt.write((char *)&car, sizeof(car));
            foutt.close();
        fii.close();
    }
    else if(in==3){
        ifstream fint;
        fint.open("cart.txt", ios::in);
        if(!fint){
            cout << endl
                 << "File cannot be opened";
            exit(0);
        }
        fint.read((char *)&car, sizeof(car));
        cout << "------------------------Cart---------------------------------------------------------" << endl;
        cout << "Name of Medicine: " << car.n << '\t' << "Price: " << car.p<< '\t' << "Quantity: " << car.s << endl;

        cout << "----------------------Total: Rs."<<car.p*car.s<<"----------------------------------------------------" << endl;
    fint.close();
    }
    else{
        cout<<"Have a nice Day !!";
        exit(0);
    }

}}
