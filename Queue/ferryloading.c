#include <stdio.h>
int len, n, i, L, R, l, r, t, ans, mark;
int left[10000], right[10000], p;
char pos[5];

void input()
{
	scanf("%d%d",&len,&n);
	p = 0;ans = 0;L = l = r = R = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d%s",&t,pos);
		if(pos[0]=='l')
			left[L++] = t;
		else
			right[R++] = t;
	}
	while(l<L||r<R)
	{
		mark = 0;
		if(p==0)
		{
			if(L)
			{
				t = len*100;
				while(l<L&&left[l]<=t)
					t -= left[l++];
				ans ++;
			}
			else
			{
				mark = 1;
				ans++,p=!p;
			}
		}
		else
		{
			if(R)
			{
				t = len*100;
				while(r<R&&right[r]<=t)
					t -= right[r++];
				ans++;
			}
			else
			{
				mark = 1;
				ans++,p=!p;
			}
		}
		if(!mark)
			p=!p;
	}
	printf("%d\n",ans);
}

int main()
{
	
		input();
	return 0;
}