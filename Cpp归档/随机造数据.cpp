#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	freopen("test.in","w",stdout);//freopen�ͷ���main���� 
	int n,x,y;
	srand(time(NULL));//ʹ�ô���ôһ�� 
	n=rand()%10+1;
	x=rand()%n+1;//+1�������棡���������� 
	y=rand()%n+1;
	printf("1 %d\n%d %d",n,x,y);//һ��Ҫ���������ﻻ�˸��ط���� 
	return 0;
}

