#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>


int elements_size;
int element_length;
int home_interface_index=0;
char home_interface_key;
char MarketName[20];
int category_index =0;


struct product
{
    char name [50];
    float price;
    int quantity;
};
typedef struct product product;

struct category
{
    char name[50];
    int product_index;
    product * to_product[50];
};
typedef struct category category;

category *cat[50];



void menu(char menu_elements[elements_size][element_length])
{
    home_interface_index=0;
    SetColor(2);
    printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
    SetColor(15);
    while(1)
    {

for (int i =0 ; i<elements_size ; i++)
{

        if(i==home_interface_index)
        {
            gotoxy(5,8+i);
            SetColor(2);
            printf("%s",menu_elements[i]);
            SetColor(15);
        }
        else
        {
            gotoxy(5,8+i);
            printf("%s",menu_elements[i]);
        }
}
  if(elements_size==4)
    {
        printf("\n\n\t\t\t\t\t\t----------------");
        SetColor(4);
        printf("\n\n\t\t\t\t<<Enter backspace at any level for home page>>");
    SetColor(15);
    }

        home_interface_key = getch();
        if(home_interface_key==-32)
        {
            home_interface_key = getch();
            switch (home_interface_key)
            {

            case 80 :
                home_interface_index++;
                if (home_interface_index>=elements_size)
                {
                    home_interface_index=0;
                }
                break;
            case 72 :
                home_interface_index--;
                if(home_interface_index<0)
                {
                    home_interface_index=(elements_size-1);
                }
                break;
            }
        }

     else if(home_interface_key==13)
     {
         system("cls");
         break;
     }

      else if(home_interface_key==127 || home_interface_key==8)
     {
         system("cls");
         break;
     }

    }

}


void add_category()
{
    char enter;
    do
    {
        cat[category_index] = malloc(sizeof(category));
        cat[category_index]->product_index=0;
        system("cls");

            SetColor(2);
        printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
            SetColor(15);

        printf("\n\n\nenter category name : ");
         fflush(stdin);
    gets(cat[category_index]->name);

        category_index++;
        printf("\n\nadd another category? y or n");
        enter = getch();
        system("cls");

    }
    while(enter =='y' || enter =='Y');

}


int display_category()
{

if(category_index==0)
{
    system("cls");
        SetColor(2);
            printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
                SetColor(15);
                    SetColor(4);
    printf("\n\nThere are no categories yet, you have to add first!");
        SetColor(15);
        printf("\n\nPress any key for home page..");
        getch();
        return 0;
}
int i;
home_interface_index=0;
 while(1)
    {

for(i=0;i<category_index;i++)
    {

          if(i==home_interface_index)
        {
            gotoxy(5,i+8);
            SetColor(2);
            printf(cat[i]->name);
            SetColor(15);
        }
        else
        {
            gotoxy(5,i+8);
            printf(cat[i]->name);
        }
    }

        home_interface_key = getch();
        if(home_interface_key==-32)
        {
           home_interface_key = getch();
            switch (home_interface_key)
            {

            case 80 :
                   home_interface_index++;
                if (home_interface_index>(category_index-1))
                {
                    home_interface_index=0;
                }
                break;

            case 72 :
                home_interface_index--;
                if(home_interface_index<0)
                {
                    home_interface_index=(category_index-1);
                }
                break;
            }
        }

          else if(home_interface_key == 13)
        {
            break;
        }

        else if (home_interface_key==127 || home_interface_key==8)
        {
            break;
        }

    }
    system("cls");
    return home_interface_index;
}

void num_validation(int *valid_num)
{
     do
       {
          if(scanf("%d",valid_num)==1 && *valid_num > 0)
          {
              break;
          }

          else
          {
                        SetColor(4);
            printf("\n\n\nPlease, enter product quantity in numbers starting from 1 : ");
                SetColor(15);
                while(getchar()!='\n');
          }

       }   while(1);
}

void add_product()
{
    char enter;

    do
    {
        cat[home_interface_index]->to_product[cat[home_interface_index]->product_index] = malloc(sizeof(product));
        system("cls");

            SetColor(2);
        printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
            SetColor(15);

        printf("\n\n\nenter product name : ");
          fflush(stdin);
    gets(cat[home_interface_index]->to_product[ cat[home_interface_index]->product_index]->name);

        printf("\n\n\nenter product quantity : ");
        num_validation(&(cat[home_interface_index]->to_product[ cat[home_interface_index]->product_index]->quantity));


        printf("\n\n\nenter product price : ");

        do
        {
         if(scanf("%f",&cat[home_interface_index]->to_product[cat[home_interface_index]->product_index]->price)==1
            && cat[home_interface_index]->to_product[cat[home_interface_index]->product_index]->price > 0)
            {
                break;
            }
            else
            {
                SetColor(4);
                printf("\n\n\nPlease, enter product price in numbers starting from 1 : ");
                SetColor(15);
                while(getchar()!='\n');
             }
        }  while(1);


                cat[home_interface_index]->product_index++;
        printf("\n\nadd another product? y or n");
        enter = getch();
        system("cls");

       }
        while(enter =='y' || enter =='Y');

}

int last_selected_product;

int display_product()
{
    if(cat[home_interface_index]->product_index == 0)
    {
        system("cls");

        SetColor(2);
            printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
                SetColor(4);
        printf("\n\nThere are no products yet, you have to add first!");
        SetColor(15);

        printf("\n\nPress any key for home page..");
        getch();
        return 0;
    }

int i , category_num;
category_num = home_interface_index;
home_interface_index=0;
char null[]={"null"};


 while(1)
    {

for(i=0;i<cat[category_num]->product_index;i++)
    {
        if(strcmp(cat[category_num]->to_product[i]->name , null) == 0 && i != cat[category_num]->product_index -1 )
        {
           for(int shift = last_selected_product ;shift<cat[category_num]->product_index-1;shift++)
           {
                 cat[category_num]->to_product[shift] = cat[category_num]->to_product[shift+1];
           }
          cat[category_num]->product_index--;
         }


        if(strcmp(cat[category_num]->to_product[i]->name , null) == 0 && i == cat[category_num]->product_index -1)
        {
           cat[category_num]->product_index--;
            continue;
        }

          if(i==home_interface_index)
        {
            gotoxy(5,i+8);
            SetColor(2);
            printf("Name : %s\t\t\t",cat[category_num]->to_product[i]->name);
            printf("Price : %f $\t\t\t",cat[category_num]->to_product[i]->price);
            printf("Quantity : %d\t\t\t",cat[category_num]->to_product[i]->quantity);
            SetColor(15);
        }

        else
        {
            gotoxy(5,i+8);
            printf("Name : %s\t\t\t",cat[category_num]->to_product[i]->name);
            printf("Price : %f $\t\t\t",cat[category_num]->to_product[i]->price);
            printf("Quantity : %d\t\t\t",cat[category_num]->to_product[i]->quantity);
        }
    }


        home_interface_key = getch();
        if(home_interface_key==-32)
        {
           home_interface_key = getch();
            switch (home_interface_key)
            {

            case 80 :
                   home_interface_index++;
                if (home_interface_index>( (cat[category_num]->product_index)-1))
                {
                    home_interface_index=0;
                }
                break;

            case 72 :
                home_interface_index--;
                if(home_interface_index<0)
                {
                    home_interface_index=( (cat[category_num]->product_index)-1);
                }
                break;
            }
        }

          else if(home_interface_key == 13)
        {
            system("cls");
           return home_interface_index;
            break;
        }

        else if (home_interface_key==127 || home_interface_key==8)
        {
            system("cls");
            break;
        }

    }
}


void move_product()
{
        product copy;
        system("cls");

        SetColor(2);
        printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
            SetColor(15);

            printf("\n\n\nFrom which category you want to move your product?");
            int last_selected_category = display_category();


            if(category_index==0)
            {
                return 0;
            }


             if(home_interface_key==127 || home_interface_key==8)
            {
               return 0;
            }

                SetColor(2);
             printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
                 SetColor(15);

            printf("\n\n\nwhich product you want to move?");
            last_selected_product =  display_product();

            if(cat[last_selected_category]->product_index==0)
            {
                system("cls");
                return 0;
            }
             if(home_interface_key==127 || home_interface_key==8)
            {
               return 0;
            }

            copy = *(cat[last_selected_category]->to_product[last_selected_product]);

            strcpy( (cat[last_selected_category]->to_product[last_selected_product]->name) , "null" );


            system("cls");
                SetColor(2);
            printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
                SetColor(15);
            printf("\n\n\nSelect category to move your product for");
            display_category();

             if(home_interface_key==127 || home_interface_key==8)
            {
               return 0;
            }
            cat[home_interface_index]->to_product[cat[home_interface_index]->product_index] = malloc(sizeof(product));
            memcpy( cat[home_interface_index]->to_product[cat[home_interface_index]->product_index]->name , copy.name , sizeof(copy.name));
             cat[home_interface_index]->to_product[cat[home_interface_index]->product_index]->price = copy.price;
             cat[home_interface_index]->to_product[cat[home_interface_index]->product_index]->quantity = copy.quantity;
             cat[home_interface_index]->product_index++;



}
float sell_product(int selected_cat, int selected_product, int search,float *total_price)
{
     int sold_quantity;
    float price;

    SetColor(2);
    printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
    SetColor(15);

     printf("\n\n\n\n\nenter quantity you want to sell : ");

     num_validation(&sold_quantity);



                if (search==1)
               {

                    while(sold_quantity>cat[selected_cat]->to_product[selected_product]->quantity)
               {
                   SetColor(4);
                   printf("Sorry we only have quantity %d of %s , Please minimize your ordered quantity",cat[selected_cat]->to_product[selected_product]->quantity,cat[selected_cat]->to_product[selected_product]->name);
                   SetColor(15);
                    printf("\n\n\t New ordered quantity : ");
                    num_validation(&sold_quantity);
                    }

              cat[selected_cat]->to_product[selected_product]->quantity-=sold_quantity;
              price =  cat[selected_cat]->to_product[selected_product]->price*sold_quantity;

              SetColor(2);
               printf("you sold %d of %s and price is : %f $",sold_quantity,cat[selected_cat]->to_product[selected_product]->name,price);
               SetColor(15);
              }


               else
               {

               while(sold_quantity>cat[selected_cat]->to_product[last_selected_product]->quantity)
               {
                   SetColor(4);
                   printf("Sorry we only have quantity %d of %s , Please minimize your ordered quantity",cat[selected_cat]->to_product[last_selected_product]->quantity,cat[selected_cat]->to_product[last_selected_product]->name);
                  SetColor(15);

                  printf("\n\n\t New ordered quantity : ");
                  num_validation(&sold_quantity);
                }


               cat[selected_cat]->to_product[last_selected_product]->quantity-=sold_quantity;
               price =  cat[selected_cat]->to_product[last_selected_product]->price*sold_quantity;

               SetColor(2);
               printf("you sold %d of %s and price is : %f $",sold_quantity,cat[selected_cat]->to_product[last_selected_product]->name,price);
                SetColor(15);

                printf("\n\nPress enter for selling another product");
                getch();
                system("cls");
               }

*total_price+= price;
return *total_price;
}

COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}




int main()
{
    char user_name[20], password [20];
    int search_detector = 0;
    float total_price = 0;

        SetColor(2);
    printf("\n\n\t\t\t\t\t\tLOGIN PAGE\n");
        SetColor(15);

    printf("\n\tUser name : ");
     fflush(stdin);
    gets(user_name);

    printf("\n\tPassword : ");
    int password_index=0;

    password[password_index] = getch();

    while( (int) password[password_index] != 13)
    {
        if((int)password[password_index]==127 || (int)password[password_index]==8 )
        {
            password_index--;
            password[password_index] = getch();
        }
        else
        {
            printf("*");
            password_index++;
            password[password_index] = getch();
        }
    }


    system("cls");
        SetColor(2);
    printf("\n\n\t\t\t\t\t\tENTER YOUR MARKET NAME : \n\n\t\t\t\t\t\t");
        SetColor(15);
    fflush(stdin);
    gets(MarketName);




    system("cls");
    char home_interface[4][22] = {">> MANAGING PRODUCTS",">> SELLING PRODUCTS",">> SETTINGS",">> EXIT"};
    char managing_products_interface [3][20] = {">> Add category",">> Add product",">> Move product"};
    char selling_process_interface [3][30] = {">> SELECT FROM CATEGORY",">> SEARCH BY PRODUCT NAME",">> TOTAL PRICE"};

    int last_selected_cat;




while(1)
{

   elements_size = 4;
    element_length =22;
menu(home_interface);

if(home_interface_key==127 || home_interface_key==8)
{
    continue;
}


    switch(home_interface_index)
         {
     case 0 :

          elements_size = 3;
    element_length =20;
menu(managing_products_interface);

if(home_interface_key==127 || home_interface_key==8)
{
    continue;
}


    switch(home_interface_index)
    {
        case 0:
           add_category();
           break;


        case 1:
            system("cls");
            SetColor(2);
            printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
            SetColor(15);
            printf("\n\n\nIn which category you want to add your product?");
           display_category();

            if(category_index==0)
            {
                system("cls");
                continue;
            }

           if(home_interface_key==127 || home_interface_key==8)
            {
               continue;
            }

            add_product();

        break;

        case 2:
          move_product();
          if(category_index==0)
          {   system("cls");
              continue;
          }

            break;
         }

         break;

         case 1:

             elements_size = 3;
             element_length =30;
           menu(selling_process_interface);

             if(home_interface_key==127 || home_interface_key==8)
               {
                continue;
               }

               switch(home_interface_index)
               {

               case 0:

                   do {
                  SetColor(2);
                printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
                    SetColor(15);

                printf("\nEnter category you want to sell from : ");
                last_selected_cat = display_category();

                 if(category_index==0)
                {
                  system("cls");
                  break;;
                }

                 if(home_interface_key==127 || home_interface_key==8)
               {
                continue;
               }

                printf("\n\n\n\n\n\nEnter product you want to sell : ");
               last_selected_product = display_product();

               if(cat[last_selected_cat]->product_index==0)
               {
                   system("cls");
                   break;
               }

                 if(home_interface_key==127 || home_interface_key==8)
               {
                continue;
               }

               total_price = sell_product(last_selected_cat,last_selected_product,search_detector,&total_price);

               } while(home_interface_key==13);


                 if(category_index==0)
             {
                system("cls");
                continue;
             }

             if(cat[last_selected_cat]->product_index==0)
               {
                   system("cls");
                   continue;
               }

               break;


               case 1:

                       SetColor(2);
                printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
                    SetColor(15);

                printf("\n\n\nEnter product name : ");
                char product_search[20];
                fflush(stdin);
                gets(product_search);

                    for(int category_search_index=0 ; category_search_index<category_index; category_search_index++)
                 {
                    for(int product_search_index=0 ; product_search_index<cat[category_search_index]->product_index;product_search_index++)
                    {
                        if(strcmp(cat[category_search_index]->to_product[product_search_index]->name , product_search)==0)
                        {
                            printf("\n\nPress enter for selling the product : \n\n");

                            SetColor(2);
                             printf("Name : %s\t\t\t",cat[category_search_index]->to_product[product_search_index]->name);
                             printf("Price : %f $\t\t\t",cat[category_search_index]->to_product[product_search_index]->price);
                             printf("Quantity : %d\t\t\t",cat[category_search_index]->to_product[product_search_index]->quantity);
                             search_detector =1;
                            SetColor(15);

                            home_interface_key = getch();

                            if(home_interface_key==127 || home_interface_key==8)
                            {
                                break;
                            }

                            else if(home_interface_key==13)
                            {
                                system("cls");
                               total_price = sell_product(category_search_index,product_search_index,search_detector,&total_price);
                            }
                        }

                    }
                }

                if(search_detector==0)
                {
                    SetColor(4);
                    printf("\n\nThere is no product called %s on our market",product_search);
                    SetColor(15);
                }

                search_detector=0;
                printf("\n\nPress any key for home page...");
                getch();
                system("cls");
                break;


               case 2:
                printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);

                SetColor(2);
                printf("\n\n\nTotal price for the previous bill is : %f $",total_price);
                SetColor(15);

                total_price=0;
                printf("\n\nPress any key for home page...");
                getch();
                 system("cls");
                continue;

                break;
                }

       break;

               case 2:
                   system("cls");

                       SetColor(2);
                printf("\n\n\n\t\t\t\t\t\t%s SYSTEM",MarketName);
                printf("\n\nUser name : ");
                SetColor(15);

                printf("%s",user_name);

                SetColor(2);
                printf("\n\nPassword : ");
                SetColor(15);

                for(int r=0; r<= password_index ; r++)
                {
                  printf("%c",password[r]);
                }

                getch();
                system("cls");
                break;

               case 3:

                   SetColor(9);
                  printf("\n\n\n\t\t\t\t--------- Good Bye ---------\n\n");
                  SetColor(15);
                   return 0;
                break;

         }

         }
    return 0;
}
