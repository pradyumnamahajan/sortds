#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

#define MAX 15

void swap(int* a, int* b);
void maxheap(int arr[], int no, int timee);
void heapsort(int arr[], int no, int timee);
void object(int x,int y,int no);
void objecth(int x,int y,int no);
int selectlocx(int i);
int selectlocy(int i);
void swapheap(int arr[], int i, int j);
void drawheap(int arr[], int no);
void lines(int no);
void moveon(int arr[],int i, int j);
void display(int arr[],int n);
void accept(int arr[],int n);
void drawarray(int low, int high);
void drawswap(int arr[],int p,int q);
void selectionsort(int arr[],int n);
void insertion(int el[],int n);
void bubble(int el[],int n);
void flow(int el[],int,int);
void mixing(int el[],int,int);
void rect(int x,int y,int no);
void printarray(int arr[],int n);
int partition (int arr[], int low, int high, int n);
void quickSort(int arr[], int low, int high, int n);
int initmouse();
void showmouseptr();
void hidemouseptr();
void getmousepos(int*,int*,int*);

union REGS i, o;


void main(){
   int el[MAX],n,i,j,c,root,temp,timee,x,ct,status,button,mousex,mousey,px,py;
   int gd = DETECT, gm;
   char p[100],cont,s[100];
   clrscr();
   initgraph(&gd, &gm, "c:\\turboc3\\bgi");
   sprintf(s,"%s","Visualising");
   setcolor(RED);
   settextstyle(3,0,8);
   outtextxy(130,30,s);
   sprintf(s,"%s","Different");
   settextstyle(3,0,8);
   outtextxy(160,120,s);
   sprintf(s,"%s","Sorting");
   settextstyle(3,0,8);
   outtextxy(180,220,s);
   sprintf(s,"%s","Techniques");
   settextstyle(3,0,8);
   outtextxy(120,320,s);
   setcolor(DARKGRAY);
   sprintf(p,"%s","Press any key to continue.");
   settextstyle(2,0,5);
   outtextxy(200,460,p);
   getch();
   cleardevice();

   status = initmouse();
   if(status == 0){
     printf("Mouse support not available.\n");

   }else{
 a:   showmouseptr();

     getmousepos(&button,&mousex,&mousey);



     setbkcolor(LIGHTGRAY);
     setcolor(GREEN);
     sprintf(p,"%s","DETAILS");
     settextstyle(2,0,8);
     outtextxy(540,5,p);
     outtextxy(541,5,p);
     outtextxy(542,5,p);
     rectangle(534,1,639,40);
     setcolor(RED);
     sprintf(p,"%s","SELECT A SORT:");
     settextstyle(2,0,11);
     outtextxy(110,50,p);
     outtextxy(111,50,p);
     outtextxy(111,51,p);
     outtextxy(112,52,p);
     setcolor(BLUE);
     rectangle(100,100,540,150);
     sprintf(p,"%s","BUBBLE SORT");
     settextstyle(2,0,8);
     outtextxy(110,110,p);
     outtextxy(111,111,p);
     rectangle(100,175,540,225);
     sprintf(p,"%s","INSERTION SORT");
     settextstyle(2,0,8);
     outtextxy(110,185,p);
     outtextxy(111,186,p);
     rectangle(100,250,540,300);
     sprintf(p,"%s","SELECTION SORT");
     settextstyle(2,0,8);
     outtextxy(110,260,p);
     outtextxy(111,261,p);
     rectangle(100,325,540,375);
     sprintf(p,"%s","QUICK SORT");
     settextstyle(2,0,8);
     outtextxy(110,335,p);
     outtextxy(111,336,p);
     rectangle(100,400,540,450);
     sprintf(p,"%s","HEAP SORT");
     settextstyle(2,0,8);
     outtextxy(110,410,p);
     outtextxy(111,411,p);
     setcolor(DARKGRAY);
     sprintf(p,"%s","Enter Esc to Exit the program.");
     settextstyle(2,0,5);
     outtextxy(230,460,p);

     while(!kbhit()){
     getmousepos(&button,&mousex,&mousey);

     px= mousex;
     py= mousey;

     if( button == 1 )
     {
        button = -1;
        cleardevice();
        goto b;
     }
     }

 b:  while(button==-1){
     if(px>100&&px<540&&py>100&&py<150){
       cleardevice();
       closegraph();
       printf("Bubble sort\n");
       printf("\n");

       printf("Enter the No of Elements : " );
       scanf("%d",&n);
       accept(el,n);
       initgraph(&gd, &gm, "c:\\turboc3\\bgi");
       for(i=0;i<n;i++){
         object(100+i*50,150,el[i]);

       }
       bubble(el,n);
       setcolor(GREEN);
       for(i=0;i<n;i++){
         object(100+i*50,150,el[i]);
       }

       setcolor(CYAN);
       sprintf(p,"%s","Bubble sort complete.");
       settextstyle(2,0,7);
       outtextxy(220,300,p);

       setcolor(DARKGRAY);
       sprintf(p,"%s","Press any key to continue.");
       settextstyle(2,0,5);
       outtextxy(230,460,p);
       getch();
       cleardevice();

       goto a;
     }
     else if(px>100&&px<540&&py>170&&py<225){
       cleardevice();
       closegraph();
       printf("Insertion sort\n");
       printf("\n");

       printf("Enter the No of Elements : " );
       scanf("%d",&n);
       accept(el,n);
       initgraph(&gd, &gm, "c:\\turboc3\\bgi");
       setcolor(WHITE);
       for(i=0;i<n;i++){
         object(100+i*50,150,el[i]);

       }
       insertion(el,n);
       setcolor(GREEN);
       for(i=0;i<n;i++){
         object(100+i*50,150,el[i]);

       }

       setcolor(CYAN);
       sprintf(p,"%s","Insertion sort complete.");
       settextstyle(2,0,7);
       outtextxy(220,300,p);

       setcolor(DARKGRAY);
       sprintf(p,"%s","Press any key to continue.");
       settextstyle(2,0,5);
       outtextxy(230,460,p);

       getch();
       cleardevice();
       goto a;

     }
     else if(px>100&&px<540&&py>250&&py<300){
       cleardevice();
       closegraph();
       printf("Selection sort\n");
       printf("\n");

       printf("Enter the No of Elements : " );
       scanf("%d",&n);
       accept(el,n);
       initgraph(&gd, &gm, "c:\\turboc3\\bgi");
       display(el,n);
       getch();
       cleardevice();
       display(el,n);
       selectionsort(el,n);

       setcolor(CYAN);
       sprintf(p,"%s","Selection sort complete.");
       settextstyle(2,0,7);
       outtextxy(220,300,p);

       setcolor(DARKGRAY);
       sprintf(p,"%s","Press any key to continue.");
       settextstyle(2,0,5);
       outtextxy(230,460,p);

       getch();
       cleardevice();
       goto a;

     }
     else if(px>100&&px<540&&py>325&&py<375){
       cleardevice();
       closegraph();
       printf("Quicksort\n");
       printf("\n");

       printf("Enter the No of Elements : " );
       scanf("%d",&n);
       accept(el,n);
       initgraph(&gd, &gm, "c:\\turboc3\\bgi");

       sprintf(p,"%s","Legend");
       settextstyle(2,0,10);
       outtextxy(50,50,p);
       setcolor(RED);
       rectangle(50,150,100,200);
       sprintf(p,"%s","Pivot");
       settextstyle(2,0,7);
       outtextxy(120,155,p);
       setcolor(BLUE);
       rectangle(50,250,100,300);
       sprintf(p,"%s","Element being compared with the Pivot");
       settextstyle(2,0,7);
       outtextxy(120,255,p);
       setcolor(YELLOW);
       rectangle(50,350,100,400);
       sprintf(p,"%s","Array being sorted.");
       settextstyle(2,0,7);
       outtextxy(120,355,p);

       getch();
       cleardevice();
       setcolor(WHITE);
       sprintf(p,"%s","Initial order - ");
       settextstyle(2,0,10);
       outtextxy(50,50,p);
       printarray(el,n);
       getch();
       cleardevice();



       quickSort(el, 0, n-1, n);

       setcolor(CYAN);
       sprintf(p,"%s","Quick sort complete.");
       settextstyle(2,0,7);
       outtextxy(220,300,p);

       setcolor(DARKGRAY);
       sprintf(p,"%s","Press any key to continue.");
       settextstyle(2,0,5);
       outtextxy(230,460,p);

       getch();
       cleardevice();
       goto a;
     }
     else if(px>100&&px<540&&py>400&&py<450){
       cleardevice();
       closegraph();
       printf("Heap sort\n");

       printf("\n");
       printf("Enter the No of Elements : " );
       scanf("%d",&n);
       accept(el,n);
       printf("\nEnter 0 for step by step swap or 1 otherwise: ");
       scanf("%d",&timee);
       initgraph(&gd,&gm,"c:\\turboc3\\bgi");
       lines(n-1);
       drawheap(el, n-1);

       maxheap(el, n, timee);

       lines(n-1);
       drawheap(el, n-1);
       if(timee == 0){
         getch();
       } else{
         delay(1000);
       }
       heapsort(el, n, timee);

       setcolor(CYAN);
       sprintf(p,"%s","Heap sort complete.");
       settextstyle(2,0,7);
       outtextxy(220,400,p);

       setcolor(DARKGRAY);
       sprintf(p,"%s","Press any key to continue.");
       settextstyle(2,0,5);
       outtextxy(230,460,p);
       getch();
       cleardevice();

       goto a;
      }
      else if(px>534&&px<639&&py>1&&py<40){
       cleardevice();
       setbkcolor(LIGHTGRAY);
       setcolor(GREEN);
       sprintf(p,"%s","MEMBERS:");
       settextstyle(2,0,10);
       outtextxy(50,50,p);

       setcolor(BLUE);
       sprintf(p,"%s","Pradyumna Mahajan");
       settextstyle(2,0,8);
       outtextxy(50,100,p);
       sprintf(p,"%s","17102B0019");
       settextstyle(2,0,8);
       outtextxy(350,100,p);

       sprintf(p,"%s","Ashutosh Pandey");
       settextstyle(2,0,8);
       outtextxy(50,150,p);
       sprintf(p,"%s","17102B0006");
       settextstyle(2,0,8);
       outtextxy(350,150,p);

       setcolor(DARKGRAY);
       sprintf(p,"%s","Enter Spacebar to go back.");
       settextstyle(2,0,5);
       outtextxy(200,460,p);

      if(getch()==32){
        cleardevice();
        goto a;
      }

     }else{
       goto a;
     }
   }
   }

 if(getch()==27){
   return;
 }else{
   goto a;
 }
}

void accept(int arr[],int n){
  int i;
  for(i=0;i<n;i++)
  {
    printf("Element %d:",i+1);
    scanf("%d",&arr[i]);
  }
}

void printarray(int arr[], int n){
	int i;
	int ipx = 50, ipy = 200;
	for(i=0;i<n;i++)
	{
		rect(ipx+(i*50),ipy,arr[i]);

	}
}

void drawarray(int low, int high){
	int ipx = 50, ipy = 200;
	setcolor(YELLOW);
	rectangle(ipx+(low*50),ipy,ipx+((high+1)*50),ipy+50);
	rectangle(ipx+(low*50)-1,ipy-1,ipx+((high+1)*50)+1,ipy+50+1);
	rectangle(ipx+(low*50)-2,ipy-2,ipx+((high+1)*50)+2,ipy+50+2);
	rectangle(ipx+(low*50)-3,ipy-3,ipx+((high+1)*50)+3,ipy+50+3);
	rectangle(ipx+(low*50)-3,ipy-4,ipx+((high+1)*50)+3,ipy+50+4);


}

void drawswap(int arr[], int p, int q){
	int i,j,k, ipx = 50, ipy = 200,x,y;
	x = arr[p];
	y = arr[q];

	setcolor(BLACK);
	rect(ipx+p*50,ipy+i,x);
	rect(ipx+q*50,ipy+i,y);

	for(i=0; i<100; i++)
	{
	       setcolor(WHITE);
	       rect(ipx+p*50,ipy+i,x);
	       rect(ipx+q*50,ipy+i,y);

	       delay(2);

	       setcolor(BLACK);
	       rect(ipx+p*50,ipy+i,x);
	       rect(ipx+q*50,ipy+i,y);
	}

	setcolor(WHITE);
	rect(ipx+p*50,ipy+i,x);
	rect(ipx+q*50,ipy+i,y);

	delay(30);

	setcolor(BLACK);
	rect(ipx+p*50,ipy+i,x);
	rect(ipx+q*50,ipy+i,y);

	for(j=0; j<(q-p)*50; j++){
			setcolor(WHITE);
			rect(ipx+p*50+j,ipy+i,x);
			rect(ipx+q*50-j,ipy+i,y);

			delay(2);

			setcolor(BLACK);
			rect(ipx+p*50+j,ipy+i,x);
			rect(ipx+q*50-j,ipy+i,y);
	}

	setcolor(WHITE);
	rect(ipx+p*50+j,ipy+i,x);
	rect(ipx+q*50-j,ipy+i,y);

	delay(30);

	setcolor(BLACK);
	rect(ipx+p*50+j,ipy+i,x);
	rect(ipx+q*50-j,ipy+i,y);

	for(k=0;k<100;k++)
	{
	    setcolor(WHITE);
	    rect(ipx+p*50+j,ipy+i-k,x);
	    rect(ipx+q*50-j,ipy+i-k,y);

	    delay(2);

	    setcolor(BLACK);
	    rect(ipx+p*50+j,ipy+i-k,x);
	    rect(ipx+q*50-j,ipy+i-k,y);
	}

	setcolor(WHITE);
	rect(ipx+p*50+j,ipy+i-k,x);
	rect(ipx+q*50-j,ipy+i-k,y);

	getch();
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high, int n){
  	int j;
		int ipx = 50, ipy = 200;
    int pivot = arr[high];
    int i = (low - 1);
   for (j = low; j <= high- 1; j++)
    {

	if (arr[j] <= pivot)
	{
	    i++;

	    if(i!=j)
	    {
	       drawswap(arr,i,j);
	     //setcolor(GREEN);
	     //rectangle(ipx+(i*50)+1,ipy+1,ipx+((j+1)*50)-1,ipy+50-1);
	     //rectangle(ipx+(i*50)+2,ipy+2,ipx+((j+1)*50)-2,ipy+50-2);

	    }
	    else
	    {
	      setcolor(GREEN);
	      rectangle(ipx+(i*50)+1,ipy+1,ipx+((j+1)*50)-1,ipy+50-1);
	      rectangle(ipx+(i*50)+2,ipy+2,ipx+((j+1)*50)-2,ipy+50-2);
	    }

	    swap(&arr[i], &arr[j]);

	  drawarray(low, high);
	  setcolor(WHITE);
	  printarray(arr,n);
	  setcolor(BLUE);
	  rectangle(ipx+(j*50),ipy,ipx+((j+1)*50),ipy+50);

	}
	cleardevice();
	drawarray(low, high);
	setcolor(WHITE);
	printarray(arr,n);
	setcolor(BLUE);
	rectangle(ipx+(j*50),ipy,ipx+((j+1)*50),ipy+50);
	rectangle(ipx+(j*50)+1,ipy+1,ipx+((j+1)*50)-1,ipy+50-1);

	setcolor(RED);										//sets colour of pivot
	rectangle(ipx+(high*50),ipy,ipx+(high+1)*50,ipy+50);
	rectangle(ipx+(high*50)+1,ipy+1,ipx+(high+1)*50-1,ipy+50-1);

	getch();
    }
    drawswap(arr, i+1, high);
    swap(&arr[i + 1], &arr[high]);
    cleardevice();
    printarray(arr,n);
    cleardevice();
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int n){
    if (low < high)
    {
	     int pi = partition(arr, low, high, n);
	     quickSort(arr, low, pi - 1, n);
	     quickSort(arr, pi + 1, high, n);
	     setcolor(GREEN);
	     printarray(arr, n);
    }
}

void bubble(int el[],int n){
  int i,j,temp,exchange,last;
  last=n;
  for(i=1;i<n;i++)
  {
    exchange=0;
    last--;

    for(j=0;j<last;j++)
    {
       if(el[j]>el[j+1])
      {
	       flow(el,j,j+1);
	       temp=el[j];
	       el[j]=el[j+1];
	       el[j+1]=temp;
	       exchange++;
      }
    }
  gotoxy(300,300);

  printf("Total no of exchanges in pass %d are %d\n",i,exchange);
  if(!exchange)
    break;
  }
}

void insertion(int el[],int n){
   int i,j,exchange,key;
   for(j=1;j<n;j++)
   {
      exchange=0;
      key=el[j];
      i=j-1;
      while(i>=0 && el[i]>key)
      {
	      flow(el,i,i+1);
        delay(500);
	      el[i+1]=el[i];
	      i=i-1;
	      el[i+1]=key;
	      exchange++;
      }
      gotoxy(300,300);
      printf("Total no of exchanges in pass %d are %d\n",j,exchange);


   }
}

void object(int x,int y,int no){
  char s[8];
  sprintf(s,"%d",no);
  circle(x,y,20);
  settextstyle(2,0,6);
  outtextxy(x-2,y-10,s);
}

void flow(int el[],int f,int s){
  int i;
  for(i=0;i<50;i++)
  {
   setcolor(WHITE);
   object(100+f*50,150+i*4,el[f]);
   delay(15);
   setcolor(0);
   object(100+f*50,150+i*4,el[f]);
  }
  setcolor(WHITE);
  object(100+f*50,150+i*4,el[f]);
  for(i=0;i<50;i++)
  {
    setcolor(WHITE);
    object(100+s*50,150+i*4,el[s]);
    delay(10);
    setcolor(0);
    object(100+s*50,150+i*4,el[s]);
  }

  object(100+s*50,150+i*4,el[s]);
  mixing(el,f,s);
  for(i=50;i>0;i--)
  {
    setcolor(WHITE);
    object(100+f*50,150+i*4,el[s]);
    delay(10);
    setcolor(0);
    object(100+f*50,150+i*4,el[s]);
  }
  setcolor(30);
  object(100+f*50,150+i*4,el[s]);
  for(i=50;i>0;i--)
  {
    setcolor(WHITE);
    object(100+s*50,150+i*4,el[f]);
    delay(15);
    setcolor(0);
    object(100+s*50,150+i*4,el[f]);
  }
  setcolor(30);
  object(100+s*50,150+i*4,el[f]);
}

void mixing(int el[],int f,int s){
  int i;
  for(i=0;i<(s-f)*50;i++)
  {
    setcolor(YELLOW);
    object(100+f*50+i,350,el[f]);
    object(100+s*50-i,350,el[s]);
    delay(20);
    setcolor(0);
    object(100+f*50+i,350,el[f]);
    object(100+s*50-i,350,el[s]);
  }
  setcolor(WHITE);
  object(100+f*50+i,350,el[f]);
  object(100+s*50-i,350,el[s]);
}

void objecth(int x,int y,int no){
  char s[8];

  sprintf(s,"%d",no);
  circle(x,y,15);
  settextstyle(2,0,6);
  outtextxy(x-8,y-10,s);
}

void maxheap(int arr[], int no, int timee){
  int root, i, c;
  char p[100];
  for (i = 1; i < no; i++)
  {
      c = i;
      do
      {
          root = (c - 1) / 2;
          setcolor(BLUE);
          moveon(arr, root, c);
          if(timee == 0){
            getch();
          }else{
            delay(500);
          }
          if (arr[root] < arr[c])
          {
              setcolor(GREEN);
              moveon(arr, root, c);
              if(timee == 0){
                getch();
              }else{
                delay(500);
              }
              swapheap(arr, root, c);
              if(timee == 0){
                getch();
              }else{
                delay(500);
              }
              swap(&arr[root], &arr[c]);
              setcolor(WHITE);
              moveon(arr, root, c);

          }else{
            setcolor(RED);
            moveon(arr, root, c);
            if(timee == 0){
              getch();
            }else{
              delay(500);
            }
            setcolor(WHITE);
            moveon(arr, root, c);
          }
          c = root;

          moveon(arr, root, c);
      } while (c != 0);
  }
  lines(no-1);
  setcolor(MAGENTA);
  drawheap(arr, no-1);
  setcolor(CYAN);
  sprintf(p,"%s","Max Heap complete.");
  settextstyle(2,0,7);
  outtextxy(230,440,p);


  if(timee == 0){
    getch();
    cleardevice();
  }else{
    delay(3000);
    cleardevice();
  }

}

void heapsort(int arr[], int no, int timee){
  int c, j, root, temp;
  char p[100];
  for (j = no - 1; j >= 0; j--)
  {   setcolor(CYAN);
      moveon(arr,0,j);
      if(timee == 0){
        getch();
      }else{
        delay(500);
      }
      swapheap(arr, 0, j);
      swap(&arr[0], &arr[j]);
      if(timee == 0){
        getch();
      }else{
        delay(500);
      }
      setcolor(WHITE);
      moveon(arr,0,j);

      root = 0;
      do{
          c = 2 * root + 1;

          if ((arr[c] < arr[c + 1]) && c < j-1){
              temp = c;
              c++;
              setcolor(BLUE);
              moveon(arr, temp, c);
              if(timee == 0){
                getch();
              }else{
                delay(500);
              }
              setcolor(WHITE);
              moveon(arr, temp, c);
          }

          if(c<j){
            setcolor(BLUE);
            moveon(arr,root,c);
            if(timee == 0){
              getch();
            }else{
              delay(500);
            }

          }

          if (arr[root]<arr[c] && c<j)
          {   setcolor(GREEN);
              moveon(arr,root,c);
              if(timee == 0){
                getch();
              }else{
                delay(500);
              }
              swapheap(arr, root, c);
              if(timee == 0){
                getch();
              }else{
                delay(500);
              }
              setcolor(WHITE);
              swap(&arr[root], &arr[c]);

              moveon(arr, root, c);

          }else{
            if(c<j){
              setcolor(RED);
              moveon(arr,root,c);
              if(timee == 0){
                getch();
              }else{
                delay(500);
              }
              setcolor(WHITE);
              moveon(arr,root,c);
            }
          }
          root = c;




      } while (c < j);

      sprintf(p,"%s","Pass complete.");
      settextstyle(2,0,7);
      outtextxy(230,440,p);
      delay(1000);
      setcolor(BLACK);
      sprintf(p,"%s","Pass complete.");
      settextstyle(2,0,7);
      outtextxy(230,440,p);
  }
  setcolor(GREEN);
  drawheap(arr,no-1);
  delay(1000);

}

void drawheap(int arr[], int no){
  int rootx = 320, rooty = 100, index;
  char p[100];
  index = no;

  switch(no){

    case 14:objecth(rootx+rootx/2+rootx/4+rootx/8, rooty+175, arr[index]);
            index--;
    case 13:objecth(rootx+rootx/2+rootx/4-rootx/8, rooty+175, arr[index]);
            index--;
    case 12:objecth(rootx+rootx/2-rootx/4+rootx/8, rooty+175, arr[index]);
            index--;
    case 11:objecth(rootx+rootx/2-rootx/4-rootx/8, rooty+175, arr[index]);
            index--;
    case 10:objecth(rootx/2+rootx/4+rootx/8, rooty+175, arr[index]);
            index--;
    case 9: objecth(rootx/2+rootx/4-rootx/8, rooty+175, arr[index]);
            index--;
    case 8: objecth(rootx/2-rootx/4+rootx/8, rooty+175, arr[index]);
            index--;
    case 7: objecth(rootx/2-rootx/4-rootx/8, rooty+175, arr[index]);
            index--;
    case 6: objecth(rootx+rootx/2+rootx/4, rooty+100, arr[index]);
            index--;
    case 5: objecth(rootx+(rootx/2)-rootx/4, rooty+100, arr[index]);
            index--;
    case 4: objecth(rootx/2 + rootx/4, rooty+100, arr[index]);
            index--;
    case 3: objecth(rootx/4, rooty+100, arr[index]);
            index--;
    case 2: objecth(rootx+(rootx/2), rooty + 50, arr[index]);
            index--;
    case 1: objecth(rootx/2, rooty + 50, arr[index]);
            index--;
    case 0: objecth(rootx, rooty, arr[index]);
            break;

  }
  setcolor(BLUE);
  circle(20,20,10);
  sprintf(p,"%s","Elements being compared");
  settextstyle(2,0,5);
  outtextxy(40,10,p);

  setcolor(GREEN);
  circle(270,20,10);
  sprintf(p,"%s","Child is greater than Parent Node");
  settextstyle(2,0,5);
  outtextxy(290,10,p);

  setcolor(RED);
  circle(270,50,10);
  sprintf(p,"%s","Child is not greater than Parent Node");
  settextstyle(2,0,5);
  outtextxy(290,40,p);

  setcolor(CYAN);
  circle(20,50,10);
  sprintf(p,"%s","Swapping max element with");
  settextstyle(2,0,5);
  outtextxy(40,40,p);
  sprintf(p,"%s","rightmost leaf Node");
  settextstyle(2,0,5);
  outtextxy(40,55,p);

}

void lines(int no){
  int rootx = 320, rooty = 100;

  switch(no){

    case 14:  setfillstyle(EMPTY_FILL, RED);
              setcolor(WHITE);
              line(rootx+rootx/2+rootx/4+rootx/8, rooty+175, rootx+rootx/2+rootx/4, rooty+100);
              setcolor(BLACK);
              fillellipse(rootx+rootx/2+rootx/4+rootx/8, rooty+175, 15, 15);
              fillellipse(rootx+rootx/2+rootx/4, rooty+100, 15, 15);

    case 13:  setfillstyle(EMPTY_FILL, RED);
              setcolor(WHITE);
              line(rootx+rootx/2+rootx/4-rootx/8, rooty+175, rootx+rootx/2+rootx/4, rooty+100);
              setcolor(BLACK);
              fillellipse(rootx+rootx/2+rootx/4-rootx/8, rooty+175, 15, 15);
              fillellipse(rootx+rootx/2+rootx/4, rooty+100, 15, 15);

    case 12:  setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx+rootx/2-rootx/4+rootx/8, rooty+175, rootx+(rootx/2)-rootx/4, rooty+100);
              setcolor(BLACK);
              fillellipse(rootx+rootx/2-rootx/4+rootx/8, rooty+175, 15, 15);
              fillellipse(rootx+(rootx/2)-rootx/4, rooty+100, 15, 15);

    case 11:  setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx+rootx/2-rootx/4-rootx/8, rooty+175, rootx+(rootx/2)-rootx/4, rooty+100);
              setcolor(BLACK);
              fillellipse(rootx+rootx/2-rootx/4-rootx/8, rooty+175, 15, 15);
              fillellipse(rootx+(rootx/2)-rootx/4, rooty+100, 15, 15);

    case 10:  setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx/2+rootx/4+rootx/8, rooty+175, rootx/2 + rootx/4, rooty+100);
              setcolor(BLACK);
              fillellipse(rootx/2+rootx/4+rootx/8, rooty+175, 15, 15);
              fillellipse(rootx/2 + rootx/4, rooty+100, 15, 15);

    case 9:   setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx/2+rootx/4-rootx/8, rooty+175, rootx/2 + rootx/4, rooty+100);
              setcolor(BLACK);
              fillellipse(rootx/2+rootx/4-rootx/8, rooty+175, 15, 15);
              fillellipse(rootx/2 + rootx/4, rooty+100, 15, 15);

    case 8:   setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx/2-rootx/4+rootx/8, rooty+175,rootx/4, rooty+100);
              setcolor(BLACK);
              fillellipse(rootx/2-rootx/4+rootx/8, rooty+175, 15, 15);
              fillellipse(rootx/4, rooty+100, 15, 15);

    case 7:   setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx/2-rootx/4-rootx/8, rooty+175,rootx/4, rooty+100);
              setcolor(BLACK);
              fillellipse(rootx/2-rootx/4-rootx/8, rooty+175, 15, 15);
              fillellipse(rootx/4, rooty+100, 15, 15);

    case 6:   setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx+rootx/2+rootx/4, rooty+100,rootx+(rootx/2), rooty + 50);
              setcolor(BLACK);
              fillellipse(rootx+rootx/2+rootx/4, rooty+100, 15, 15);
              fillellipse(rootx+(rootx/2), rooty + 50, 15, 15);

    case 5:   setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx+(rootx/2)-rootx/4, rooty+100,rootx+(rootx/2), rooty + 50);
              setcolor(BLACK);
              fillellipse(rootx+(rootx/2)-rootx/4, rooty+100, 15, 15);
              fillellipse(rootx+(rootx/2), rooty + 50, 15, 15);

    case 4:   setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx/2 + rootx/4, rooty+100,rootx/2, rooty + 50);
              setcolor(BLACK);
              fillellipse(rootx/2 + rootx/4, rooty+100, 15, 15);
              fillellipse(rootx/2, rooty + 50, 15, 15);

    case 3:   setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx/4, rooty+100,rootx/2, rooty + 50);
              setcolor(BLACK);
              fillellipse(rootx/4, rooty+100, 15, 15);
              fillellipse(rootx/2, rooty + 50, 15, 15);

    case 2:   setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx+(rootx/2), rooty + 50,rootx, rooty);
              setcolor(BLACK);
              fillellipse(rootx+(rootx/2), rooty + 50, 15, 15);
              fillellipse(rootx, rooty, 15, 15);

    case 1:   setcolor(WHITE);
              setfillstyle(EMPTY_FILL, RED);
              line(rootx/2, rooty + 50,rootx, rooty);
              setcolor(BLACK);
              fillellipse(rootx/2, rooty + 50, 15, 15);
              fillellipse(rootx, rooty, 15, 15);
              setcolor(WHITE);
              break;

  }
}

void swapheap(int arr[], int i, int j){
  int ix,iy,jx,jy,k;

  ix = selectlocx(i);
  iy = selectlocy(i);

  jx = selectlocx(j);
  jy = selectlocy(j);

  setcolor(YELLOW);
  objecth(ix,iy,arr[i]);
  objecth(jx,jy,arr[j]);
  //getch();

  for(k = 15; k>=0; k--){
    setcolor(WHITE);
    circle(ix,iy,k);
    circle(jx,jy,k);

    delay(10);

    setcolor(BLACK);
    circle(ix,iy,k);
    circle(jx,jy,k);

  }

  setfillstyle(EMPTY_FILL, RED);
  fillellipse(ix, iy, 15, 15);
  fillellipse(jx, jy, 15, 15);

  for(k=0; k<=15; k++){
    setcolor(WHITE);
    circle(ix,iy,k);
    circle(jx,jy,k);

    delay(10);

    setcolor(BLACK);
    circle(ix,iy,k);
    circle(jx,jy,k);
  }
  setfillstyle(EMPTY_FILL, RED);
  fillellipse(ix, iy, 15, 15);
  fillellipse(jx, jy, 15, 15);

  setcolor(YELLOW);
  objecth(ix,iy,arr[j]);
  objecth(jx,jy,arr[i]);


}

int selectlocx(int i){
  int rootx = 320;
  switch(i){
    case 0:   return rootx;
    case 1:   return rootx/2;
    case 2:   return rootx+(rootx/2);
    case 3:   return rootx/4;
    case 4:   return rootx/2 + rootx/4;
    case 5:   return rootx+rootx/2-rootx/4;
    case 6:   return rootx+rootx/2+rootx/4;
    case 7:   return rootx/2-rootx/4-rootx/8;
    case 8:   return rootx/2-rootx/4+rootx/8;
    case 9:   return rootx/2+rootx/4-rootx/8;
    case 10:  return rootx/2+rootx/4+rootx/8;
    case 11:  return rootx+rootx/2-rootx/4-rootx/8;
    case 12:  return rootx+rootx/2-rootx/4+rootx/8;
    case 13:  return rootx+rootx/2+rootx/4-rootx/8;
    case 14:  return rootx+rootx/2+rootx/4+rootx/8;
    default:  return 999;
  }
}

int selectlocy(int i){
  int rooty = 100;
  switch(i){
    case 0:   return rooty;
    case 1:
    case 2:   return rooty + 50;
    case 3:
    case 4:
    case 5:
    case 6:   return rooty + 100;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:  return rooty + 175;
    default:  return 999;


  }
}

void moveon(int arr[],int i, int j){
  int ix,iy,jx,jy,k;

  ix = selectlocx(i);
  iy = selectlocy(i);

  jx = selectlocx(j);
  jy = selectlocy(j);


  objecth(ix,iy,arr[i]);
  objecth(jx,jy,arr[j]);

}

void rect(int x,int y,int no){
  char s[8];
  sprintf(s,"%d",no);
  rectangle(x,y,x+50,y+50);
  settextstyle(2,0,6);
  outtextxy(x+10,y+10,s);
}

void display(int arr[],int n){
  int i,ipx=50,ipy=200;
  for(i=0;i<n;i++)
  {
    rect(ipx+(i*50),ipy,arr[i]);
  }
}

void selectionsort(int arr[],int n){
  int i,j,min_index;
  for(i=0;i<n-1;i++)
  {
    display(arr,n);
    min_index=i;
    for(j=i+1;j<n;j++)
    {
      if(arr[j]<arr[min_index])
         min_index=j;
    }
    drawarray(i,n-1);
    drawswap(arr,i,min_index);
    swap(&arr[min_index],&arr[i]);
    getch();
    cleardevice();
  }
  cleardevice();
  setcolor(GREEN);
  display(arr,n);
}

void showmouseptr(){
   i.x.ax = 1;
   int86(0X33, &i, &o);
}

void getmousepos(int *button, int *x, int *y){
   i.x.ax = 3;
   int86(0X33, &i, &o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}

int initmouse(){
   i.x.ax = 0;
   int86(0X33, &i, &o);
   return ( o.x.ax );
}
