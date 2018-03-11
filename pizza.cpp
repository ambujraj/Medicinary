#include<iostream>
#include<string.h>
using namespace std;
void DisplayOrder(class PizzaTypes pizzaCart[100],class PizzaCost costOnSize[12],char itemNames[12][100],int sidesCost[4]);
class PizzaTypes{
public:
 int smallQuantity,mediumQuantity,largeQuantity,others,freshPan,cheeseBurst,wheatThinCrust;
};
class PizzaCost{
public:
 int smallCost,mediumCost,largeCost,freshPanCost,cheeseBurstCost,wheatThinCrustCost;
};
main()
{
 int i=0,c=1,j=0,mainChoice,cost[24]={99,195,395,155,295,445,155,295,445,195,365,545,155,295,445,225,425,635,235,455,685,235,455,685},totalCost=0,a[10];
 char name[20];
 char itemNames[12][100]={
  "Margherita(Veg)",
  "Spicy Triple Tango(Veg)",
  "Double Cheese Margherita(Veg)",
  "Farm House(Veg)",
  "Cheese and Barbeque Chicken(Non Veg)",
  "Chicken Fiesta(Non Veg)",
  "Chicken Mexican(Non Veg)",
  "Chicken Golden Delight(Non Veg)",
  "Zingy Parcel Veg",
  "Zingy Parcel Non Veg",
  "Taco Mexicana Veg",
  "Taco Mexicana Non Veg"
 };
 int sidesCost[4]={29,35,119,129};
// int zingyParcelVeg=29,zingyParcelNonVeg=35,tacoMexicanaVeg=119,tacoMexicanaNonVeg=129;
 PizzaTypes pizzaCart[100];
 PizzaCost costOnSize[12];
 for(i=0;i<12;i++)
 {
  pizzaCart[i].smallQuantity=0;
  pizzaCart[i].mediumQuantity=0;
  pizzaCart[i].largeQuantity=0;
  pizzaCart[i].freshPan=0;
  pizzaCart[i].wheatThinCrust=0;
  pizzaCart[i].cheeseBurst=0;
  pizzaCart[i].others=0;

 }
 i=0;
 while(i<24)
 {
  costOnSize[j].smallCost=cost[i++];
  costOnSize[j].mediumCost=cost[i++];
  costOnSize[j].largeCost=cost[i++];
  costOnSize[j].freshPanCost=30;
  costOnSize[j].cheeseBurstCost=95;
  costOnSize[j].wheatThinCrustCost=40;
  j++;
 }
 do{
  if(c==1){
   cout<<"Enter\n1 - Veg Pizzas\n2 - Chicken Pizzas\n3 - Sides\n4 - Exit\n";
      cin>>mainChoice;
   switch(mainChoice)
   {
    case 1:
    {
     int subChoice;
     cout<<"Enter\n1 - Margherita\n2 - Spicy Triple Tango\n3 - Double Cheese Margherita\n4 - Farm House\n5 - Exit\n";
     cin>>subChoice;
     if(subChoice!=5){
      int sizeChoice;
              cout<<"Enter\n1 - Small\n2 - Medium\n3 - Large\n";
              cin>>sizeChoice;
      if(sizeChoice==1)
       pizzaCart[subChoice-1].smallQuantity++;
      if(sizeChoice==2)
                   pizzaCart[subChoice-1].mediumQuantity++;
         if(sizeChoice==3)
       pizzaCart[subChoice-1].largeQuantity++;
      cout<<"Need Special Crusts\n1 - Fresh Pan\n2 - Cheese Burst\n3 - Wheat thin Crust\n4 - No Need\n";
      int extraCrust;
      cin>>extraCrust;
      if(extraCrust==1)
      pizzaCart[subChoice-1].freshPan++;
      else if(extraCrust==2)
      pizzaCart[subChoice-1].cheeseBurst++;
      else if(extraCrust==3)
      pizzaCart[subChoice-1].wheatThinCrust++;

      if(subChoice!=5)
      cout<<"Pizza Added to Cart Successfully\n";
     }


break;
     }
    case 2:
    {
     int subChoice;
     cout<<"Enter\n1 - Cheese and Barbeque Chicken\n2 - Chicken Fiesta\n3 - Chicken Mexican\n4 - Chicken Golden Delight\n5 - Exit\n";
     cin>>subChoice;
     if(subChoice!=5){
      int sizeChoice;
         cout<<"Enter\n1 - Small\n2 - Medium\n3 - Large\n";
              cin>>sizeChoice;
      if(sizeChoice==1)
       pizzaCart[subChoice+4-1].smallQuantity++;
      if(sizeChoice==2)
                   pizzaCart[subChoice+4-1].mediumQuantity++;
         if(sizeChoice==3)
       pizzaCart[subChoice+4-1].largeQuantity++;
      cout<<"Need Special Crusts\n1 - Fresh Pan\n2 - Cheese Burst\n3 - Wheat thin Crust\n4 - No Need\n";
      int extraCrust;
      cin>>extraCrust;
      if(extraCrust==1)
      pizzaCart[subChoice+4-1].freshPan++;
      else if(extraCrust==2)
      pizzaCart[subChoice+4-1].cheeseBurst++;
      else if(extraCrust==3)
      pizzaCart[subChoice+4-1].wheatThinCrust++;
      if(subChoice!=5)
      cout<<"Pizza Added to Cart Successfully\n";
     }

     break;
    }
    case 3:
    {
     int subChoice;
     cout<<"Enter\n1 - Zingy Parcel Veg\n2 - Zingy Parcel Non Veg\n3 - Taco Mexican Veg\n4 - Taco Mexican Non Veg\n5 - Exit\n";
     cin>>subChoice;
     if(subChoice<5 && subChoice>0)
         pizzaCart[subChoice+8-1].others++;
        if(subChoice!=5)
      cout<<"Added to Cart Successfully\n";
     break;
     }
     default:
     {
      cout<<"Invalid Choice\n";
      break;
     }
     }
  }
  if(c==2)
  {
   int id,quantityPizza,quantityCrust,quantity,wrongIdFlag=1;
   cout<<"Enter Id to change Quantity\n";
   cin>>id;
   if(id>=0 && id<=11)
   {
    if(id>=0&&id<=7)
    {
     if(pizzaCart[i].smallQuantity>0||pizzaCart[i].mediumQuantity>0||pizzaCart[i].largeQuantity||pizzaCart[i].others>0||pizzaCart[i].freshPan>0||pizzaCart[i].cheeseBurst||pizzaCart[i].wheatThinCrust>0){
      cout<<"Enter\n1 - To Change Small Pizza Quantity\n2 -Change Quantity for Medium Pizza\n3 -Change Quantity for Large Pizza\n4 -Change Quantity for Crust\n5 - Exit\n";
      cin>>quantityPizza;
      cout<<"Enter quantity to change and to delete Enter 0\n";
      cin>>quantity;
      if(quantity>=0){
          if(quantityPizza==1)
          pizzaCart[id].smallQuantity=quantity;
          if(quantityPizza==2)
          pizzaCart[id].mediumQuantity=quantity;
          if(quantityPizza==3)
          pizzaCart[id].largeQuantity=quantity;
          if(quantityPizza==4)
          {
           cout<<"Enter\n1 - To Change Fresh Pan\n2 - Cheese Burst\n3 - Wheat Thin Crust\n4 - Exit\n";
           cin>>quantityCrust;
           if(quantityCrust==1)
           pizzaCart[id].freshPan=quantity;
           if(quantityCrust==2)
           pizzaCart[id].cheeseBurst=quantity;
           if(quantityCrust==3)
           pizzaCart[id].wheatThinCrust=quantity;
          }
      }
else{
       cout<<"Enter Quantity greater than or equal to zero\n";
      }
     }
     else{
      cout<<"Id Not Found\n";
      wrongIdFlag=0;
     }
    }
    else{
     cout<<"Enter\n1 - To Change Quantity of Zingy Parcel(Veg)\n2 - To Change Quantity of Zingy Parcel(Non Veg)\n3 - To Change Quantity of Taco Mexicana(Veg)\n4 - To Change Quantity of Taco Mexicana(Non Veg)\n5 - To Change Quantity of  - Exit\n";
     cin>>quantityPizza;
     if(quantityPizza>=1 && quantityPizza<=4)
     {
         cout<<"Enter quantity\n";
      cin>>quantity;
      pizzaCart[id].others=quantity;
     }

    }
    if(wrongIdFlag==1)
    {
                   cout<<"Quantity Changed Successfully\nRearranged Order is\n";
                   DisplayOrder(pizzaCart,costOnSize,itemNames,sidesCost);
    }

   }
   else{
    cout<<"Please Enter Valid Id\n";
   }
  }
  if(c==4)
  {
   int id;
   cout<<"Enter Id to delete from Cart\n";
   cin>>id;
   pizzaCart[id].smallQuantity=0;
   pizzaCart[id].mediumQuantity=0;
   pizzaCart[id].largeQuantity=0;
   pizzaCart[id].others=0;
   pizzaCart[id].freshPan=0;
   pizzaCart[id].cheeseBurst=0;
   pizzaCart[id].wheatThinCrust=0;
    cout<<"Item Deleted Successfully\nRearranged Order is\n";
     DisplayOrder(pizzaCart,costOnSize,itemNames,sidesCost);
  }
  if(c==3)
  {
   DisplayOrder(pizzaCart,costOnSize,itemNames,sidesCost);
  }

      cout<<"Enter\n1 - Add Item\n2 - Change Quantity\n3 - View Cart\n4 - Delete from Cart\nElse any number to Calculate Cost\n";
      cin>>c;
 }while(c==1 || c==2 || c==3 || c==4);
 cout<<"Final Order \n";
DisplayOrder(pizzaCart,costOnSize,itemNames,sidesCost);
cout<<"Thanks for Shopping with us\n";
}

void DisplayOrder(struct PizzaTypes pizzaCart[100],struct PizzaCost costOnSize[12],char itemNames[12][100],int sidesCost[4])
{
 int totalCost=0,i;
 cout<<"---------------------List in Cart-------------------------\n";
 for(i=0;i<11;i++)
 {
  if(pizzaCart[i].smallQuantity>0||pizzaCart[i].mediumQuantity>0||pizzaCart[i].largeQuantity||pizzaCart[i].others>0||pizzaCart[i].freshPan>0||pizzaCart[i].cheeseBurst||pizzaCart[i].wheatThinCrust>0)
  {
   if(i>=0&&i<=7){
   cout<<i<<endl;
      cout<<"Item Name : "<<itemNames[i]<<endl;
   if(pizzaCart[i].smallQuantity>0)
   cout<<"Small Size Quantity: "<<pizzaCart[i].smallQuantity<<endl<<costOnSize[i].smallCost*pizzaCart[i].smallQuantity<<endl;
   if(pizzaCart[i].mediumQuantity>0)
   cout<<"Medium Size Quantity: "<<pizzaCart[i].mediumQuantity<<endl<<costOnSize[i].mediumCost*pizzaCart[i].mediumQuantity<<endl;
   if(pizzaCart[i].largeQuantity>0)
   cout<<"Large Size Quantity: "<<pizzaCart[i].largeQuantity<<endl<<costOnSize[i].largeCost*pizzaCart[i].largeQuantity<<endl;
   if(pizzaCart[i].freshPan>0)
   cout<<"Fresh Pan Quantity: "<<pizzaCart[i].freshPan<<endl<<costOnSize[i].freshPanCost*pizzaCart[i].freshPan<<endl;
   if(pizzaCart[i].wheatThinCrust>0)
   cout<<"Wheat Thin Crust Quantity: "<<pizzaCart[i].wheatThinCrust<<endl<<costOnSize[i].wheatThinCrustCost*pizzaCart[i].wheatThinCrust<<endl;
   if(pizzaCart[i].cheeseBurst>0)
   cout<<"Cheese Burst Quantity: "<<pizzaCart[i].cheeseBurst<<endl<<costOnSize[i].cheeseBurstCost*pizzaCart[i].cheeseBurst<<endl;
   totalCost+=pizzaCart[i].smallQuantity*costOnSize[i].smallCost;
   totalCost+=pizzaCart[i].mediumQuantity*costOnSize[i].mediumCost;
   totalCost+=pizzaCart[i].largeQuantity*costOnSize[i].largeCost;
   totalCost+=pizzaCart[i].freshPan*costOnSize[i].freshPanCost;
   totalCost+=pizzaCart[i].cheeseBurst*costOnSize[i].cheeseBurstCost;
   totalCost+=pizzaCart[i].wheatThinCrust*costOnSize[i].wheatThinCrustCost;
  }
  else{
   cout<<"Id : "<<i<<endl;
   cout<<"Item Name : "<<itemNames[i]<<endl;
   cout<<"Quantity : "<<pizzaCart[i].others<<endl;
   cout<<"Cost : "<<pizzaCart[i].others*sidesCost[i-8]<<endl;
   totalCost+=(pizzaCart[i].others)*sidesCost[i-8];
  }
 }
  }
   cout<<"-------------------Total Cost-----------------------\n"<<totalCost<<endl;
}

