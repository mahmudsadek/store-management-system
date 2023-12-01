#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "category.c"

COORD coord= {0,0};                  // this is global variable

//center of axis is set to the top left corner of the screen
void gotoxy(int x,int y) {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void SetColor(int ForgC) {
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void ProdactMenu(ListOfProdacts *p) {

}

void BuyMenu() {
}
void CategoryMenu(ListOfCategory *c) {
   char cateMenu[2][20] = {
      "1- Add Category",
      "2- Show Category"
   };
   int X_Axies = 10;
   int Y_Axies = 0;
   int flag = 1;
   do {
      system("cls");
      SetColor(15);
      gotoxy(X_Axies,9);
      printf("===========================");
      for (int i = 0; i < 2; i++) {
      if(Y_Axies == i) {
         SetColor(3);
         gotoxy(X_Axies,i+10);
         printf("\t%s\n",cateMenu[i]);
      }
      else {
         SetColor(15);
         gotoxy(X_Axies,i+10);
         printf("\t%s\n", cateMenu[i]);
      }
      SetColor(15);
      gotoxy(X_Axies,12);
      printf("===========================");
      }
      char ch;
      ch = getch();
      switch (ch)
      {
      case -32:
         ch = getch();
         switch(ch) {
         case 80:
            Y_Axies++;
            if(Y_Axies > 2) {
               Y_Axies = 0;
            }
            break;
         case 72:
            Y_Axies--;
            if(Y_Axies < 0) {
               Y_Axies = 2;
            }
            break;
         }
         break;
      case 13:
         switch (Y_Axies)
         {
         case 0:
            system("cls");
            push_back(c, addCategory());
            break;
         case 1:
            system("cls");
            ShowCategorys(c);
            break;
         default:
            break;
         }
         break;
      default:
         break;
   case 27:
      flag = 0;
      }
   }while(flag);
   
}

void MainMenu(ListOfCategory *c, ListOfProdacts *p) {
   char menu[3][20] = {
      "1- Category",
      "2- Prodact",
      "3- Buy Now !"
   };
   int X_Axies = 10;
   int Y_Axies = 0;

   while(1) {
      system("cls");
      SetColor(15);
      gotoxy(X_Axies,9);
      printf("===========================\n");
      for (int i = 0; i < 3; i++) {
         if(Y_Axies == i) {
            SetColor(20);
            gotoxy(X_Axies,i+10);
            printf("\t%s\n", menu[i]);
         }
         else {
            SetColor(15);
            gotoxy(X_Axies,i+10);
            printf("\t%s\n", menu[i]);
         }
      }
      SetColor(15);
      gotoxy(X_Axies,13);
      printf("===========================");

      char ch;
      ch = getch();
      switch (ch)
      {
      case -32:
         ch = getch();
         switch(ch) {
         case 80:
            Y_Axies++;
            if(Y_Axies > 2) {
               Y_Axies = 0;
            }
            break;
         case 72:
            Y_Axies--;
            if(Y_Axies < 0) {
               Y_Axies = 2;
            }
            break;
         }
         break;
      case 13:
         switch (Y_Axies)
         {
         case 0:
            system("cls");
            CategoryMenu(c);
            break;
         case 1:
            system("cls");
            ProdactMenu(p);
            break;
         case 2:
            system("cls");
            BuyMenu();
            break;
         default:
            break;
         }
         break;
      default:
         break;
      }
   }


}

int main () {
   ListOfCategory category;
   makeListOfCategory(&category, 5);
   ListOfProdacts prodact;
   makeListOfProdacts(&prodact,5);

   MainMenu(&category, &prodact);

}