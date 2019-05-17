/*	This is BahuMajaNu/NahiDegi. I am back. This is May - 2019. Feeling a bit slow but will get there.
	Lost my old Template starting again.
	'D' key is not working.
*/

#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define ull unsigned long long
#define For(var,start,end) for(var=start;var<end;var++)
#define Rof(var,start,end) for(var=start;var>=end;var--)
using namespace std;
int n,x,y,i,j,k;


int main(){
	ifstream in("in.txt");
	ofstream out("out.txt");
	in >> n;
	string s;
	vector <char> tempString,ansString;
	tempString.reserve(n);
	ansString.reserve(n);
	in >> s;
	int ans=0,sum=0;

	std::vector<int> count;
	count.reserve(n);

	int cur=1;
	For(i,1,n){
		if(s[i]==s[i-1])
			cur++;
		else{
			count.push_back(cur);
			tempString.push_back(s[i-1]);
			cur=1;
		}
	}
	tempString.push_back(s[n-1]);
	count.push_back(cur);

	For(i,0,count.size()){
		if(count[i]>1){
			if(sum%2){
				sum+=2,ans+=(count[i]-2);
				ansString.push_back(tempString[i]);
				ansString.push_back(tempString[i]);
			}
			else{
				sum++,ans+=(count[i]-1);
				ansString.push_back(tempString[i]);
			}
		}
		else{
			sum++;
			ansString.push_back(tempString[i]);
		}
	}
	if(sum%2){
		ans++,ansString.pop_back();
	}

	out << ans << "\n";

	for(auto c:ansString)
		out << c;

	in.close();
	out.close();
	exit(0);
}
