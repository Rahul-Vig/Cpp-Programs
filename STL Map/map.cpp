#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){

	map<string, int> d;
	vector<string> in{"hello","one","hello","bye","glerp","one","hello"};

	// count the number of times each string appears in vector in

	for(auto i:in) // this is a "range for"
		if(d.find(i)==d.end())
			d[i]=1;
		else
			d[i]++;

	// find the max element of the map
	int max=0;
	string val;

       for (auto i:d){
        	cout<<i.first<<" found "<<i.second<<" times. "<<endl;
        	if(i.second>max){
        		val=i.first;
        		max=i.second;
        	}
        }
        cout<<"The  string most found is: "<<val<<". It was found "<<max<<" times."<<endl;


 }			
