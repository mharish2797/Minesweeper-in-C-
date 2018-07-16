/*
 * Minesweeper.cpp
 *
 *  Created on: 12-May-2016
 *      Author: Harish Mohan
 */
 
 #include<bits/stdc++.h>
using namespace std;
int a[9][9],i,j,b[9][9],cot=0,x[12];
class mines
{
public:
    mines()
    {
    srand(time(0));
    for(i=0;i<12;i++)
    {
        x[i]=rand()%80+1;
        //cout<<x[i]<<'\t';
    }
    cout<<'\n';
        int k=1;
     for(i=0;i<9;i++)
     {
         for(j=0;j<9;j++)
          {a[i][j]=k++;
          b[i][j]=a[i][j];
          }
        }
     for(k=0;k<12;k++)
     {
         for(i=0;i<9;i++)
     {
         for(j=0;j<9;j++)
          {
              if(x[k]==a[i][j])
               {
                a[i][j]=-17;
                cot++;
               }
          }
     }
    }
    }
void disp()
{
        for(i=0;i<9;i++)
     {
         for(j=0;j<9;j++)
          {
             cout<<b[i][j]<<'\t';}
             cout<<'\n';
     }

}
int check(int v)
{
    int y;
    for(y=0;y<12;y++)
    {
        if(x[y]==v)
            return -1;
    }

}
void span(int v)
{
    srand(time(0));
    int g=rand()%4+3,w=0,p=1;
    for(i=0;i<9;i++)
    {
        p=1;
        for(j=0;j<9;j++)
        {
            if(b[i][j]==v)
               {   b[i][j]=0;
               p=0;
                   break;
                   }
        }
        if(p==0) break;
    }
   // cout<<"i,j,w,g"<<i<<j<<w<<g;
   while(w<g)
   {
       if(w<g)
       {if(i-1>=0&&a[i-1][j]!=-17&&b[i-1][j]!=0)
         b[i-1][j]=0;
         w++;
       }
       if(w<g)
       {if(j-1>=0&&a[i][j-1]!=-17&&b[i][j-1]!=0)
         b[i][j-1]=0;
         w++;
       }
       if(w<g)
       {if(i+1<=8&&a[i+1][j]!=-17&&b[i+1][j]!=0)
         b[i+1][j]=0;
         w++;
       }
       if(w<g)
       {if(j+1<=8&&a[i][j+1]!=-17&&b[i][j+1]!=0)
         b[i][j+1]=0;
         w++;
       }
       i++;
       j--;
       w++;
   }
}
int cou()
{
    int cl=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(b[i][j]==0) cl++;
        }
    }
    return cl;
}
};
int main()
{
    int v,l=0,b=0;
    mines m;
    cout<<"\nWelcome to MINESWEEPER~\n\nThis is the mine-field\nThere are "<<cot<<"mines placed randomly all over it.\nDetect the places where no mine is plotted :)\n";
    do{
            m.disp();
            S:
        cout<<"\nEnter your guess !! ";
            cin>>v;
            if(v<1||v>81)
                {cout<<"Invalid Choice. "; goto S;}
        l=m.check(v);
        if(l==-1)
        {
            cout<<"\n#mine_detected\nYou lost. Try again.";
            break;
        }
        m.span(v);
        b=m.cou();
    cout<<"\nNumber of non mine zones remaining :"<<81-cot-b<<'\n';
    }while(cot+b!=81);
    if(cot+b==81)
        cout<<"\nCongratulations you've WON!";
    cout<<"\nGAME OVER !!";
    return 0;
}



