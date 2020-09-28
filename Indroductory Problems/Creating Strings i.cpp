#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	vector <string> a;
	int v=0;
	cin>>s;
	sort(s.begin(),s.end());
	do
	{
	    v++;
	    a.push_back(s);
	}while(next_permutation(s.begin(),s.end()));

	cout<<v<<endl;
    for(int i=0;i<v;i++)
    cout<<a[i]<<endl;

	return 0;
}
