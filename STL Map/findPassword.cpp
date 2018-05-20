#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){

	vector<string> in{"011", "0111", "01110", "111", "0111", "10111"};
	//vector<string> in{"10","0111","100","111","1","00111"};

	int num_frags=in.size();
	int num_bits=0;
	for(string i:in)
		num_bits+=i.length();

	int num_files=num_frags/2;
	int file_size=num_bits/num_files;

	map<string, int> d;
	for(string i:in)
		for(string j:in){
			string s=i+j;
			if (s.size()==file_size)
				if(d.find(s)==d.end())
					d[s]=1;
				else
					d[s]++;
	     }

	// find the max element of the map
	int max=0;
	string val;
	for (auto i:d){  // i is a pair
    	cout<<i.first<<" appears: "<<i.second<<" times."<<endl;
    	if(i.second>max){
    		val=i.first;
    		max=i.second;
    	}
    }
    cout<<"The secret string is: "<<val<<endl;

}
