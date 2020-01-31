#include <stdio.h>
#include <stdlib.h>
/*Coded by Mike Laman*/
/***************************
    Analyzed and Modified by 
        Hazhir Ahmadzadeh
****************************/
int a[900];
int b;
int c;
int d=1;
int e=1;
int f;
int g;
int h;
int O;
int main(k,l) char* *l;
{
    g=atoi(* ++l);
    for(k=0;k*k<g;b=k++>>1);
    for(h=0;h*h<=g;++h);
    --h;
    c=((h+=g>h*(h+1))-1)>>1;
    while(d<=g){
        ++O;
        for(f=0;f<O&&d<=g;++f) a[b<<5|c]=d++,b+=e;
        for(f=0;f<O&&d<=g;++f) a[b<<5|c]=d++,c+=e;e= -e;
    }
    for(c=0;c<h;++c)
    {
        for(b=0;b<k;++b)
        {
            if(b<k/2)a[b<<5|c]^=a[(k-(b+1))<<5|c]^=	a[b<<5|c]^=a[(k-(b+1))<<5|c];
            printf(a[b<<5|c]?"%-4d"	:"    "	,a[b<<5|c]);
        }
    putchar('\n');
    }
    return 0;
}