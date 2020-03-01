#include<stdio.h>
int main(){
	short n;
	if(scanf("%hd",&n)!=1)	printf("n is error\n");
	short ans=0;
	while(n--){
		short tmp;
		if(scanf("%hd",&tmp)!=1)	printf("number error\n");
		ans+=tmp;
	}
	printf("%hd\n",ans);
}