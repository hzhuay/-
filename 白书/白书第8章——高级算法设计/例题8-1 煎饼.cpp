// UVa120 Stacks of Flapjacks
// Rujia Liu
#include<cstdio>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

const int maxn = 30 + 5;
int n, a[maxn];

// ��תa[0..p]
void flip(int p){
	for(int i = 0; i < p-i; i++)
		swap(a[i], a[p-i]);
	printf("%d ", n-p);
}

int main(){
	string s;
	while(getline(cin, s)) {
		cout << s << "\n";
		stringstream ss(s);
		n = 0;
		while(ss >> a[n]) n++;
		for(int i = n-1; i > 0; i--) {
			int p = max_element(a, a+i+1) - a; // Ԫ��a[0..i]�е����Ԫ��
			if(p == i) continue;
			if(p > 0) flip(p); // flip(0)ûɶ��˼���ǲ���
			flip(i);
		}
		printf("0\n");
	}
	return 0;
}
