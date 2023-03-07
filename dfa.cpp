#include <iostream>
#include <cstring>

using namespace std;

int limbaj[3][3] = {{2, 0, 0}, {0, 3, 0}, {0, 0, 1}};


int main()
{
    char cuvant[50], chr;
    int i, n, x, y;
    cin>>cuvant;
    n = strlen(cuvant);
    x=1;
    for(i=0;i<n;i++)
    {
       chr = cuvant[i];
       y = chr - 97;
       x = limbaj[y][x-1];
       if(x==0)
       {
           cout<<"Imposibil";
           break;
       }
    }
    if(x==1)
        cout<<"Valid";
    else
        cout<<"Incomplet";
    return 0;
}
