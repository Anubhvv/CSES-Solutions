#include <stdio.h>
using namespace std;
int main()
{int t,x,y;
scanf("%d",&t);
while(t--)
{scanf("%d%d",&x,&y);
if(!((x+y)%3)&&(y<<1)-x>=0&&(x<<1)-y>=0)printf("YES\n");
else printf("NO\n");}
return 0;}
