#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
void fill_random_int(vector<int>& v,int cnt){//��������� 
	v.clear();
	for(int i=0;i<cnt;i++)
		v.push_back(rand());
}
vector<int> fill_random_int(int cnt){
	vector<int> v;
	for(int i=0;i<cnt;i++)
		v.push_back(rand());
	return v;
}//��������в���Ҫ�ĸ��� ,������������ 
void test_sort(vector<int>& v){
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++)
		assert(v[i]<=v[i+1]);//�����ʽΪ��ʱ�ޱ仯��Ϊ��ʱǿ����ֹ���򲢸���������ʾ 
}
int main(){
	vector<int>v;
	fill_random_int(v,1000000);
	test_sort(v); 
	return 0;
}
